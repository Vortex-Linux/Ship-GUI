use gdk4::Display;
use gtk4::prelude::*;
use gtk4::{Application, ApplicationWindow, Builder, Label, Notebook, CssProvider, GestureClick, Menu, MenuItem};
use gio::File;
use std::path::PathBuf;

mod ship_commands; 

pub fn build_app() -> Application {
    let gtk_env = super::gtk_env::GtkEnv::init();
    let app = Application::builder()
        .application_id(&gtk_env.application_id)
        .build();
    app.connect_startup(|_| load_css());
    app.connect_activate(move |app| {
        let window = build_window(app);
        window.present();
    });
    app
}

fn get_base_folder() -> PathBuf {
    return PathBuf::from(env!("CARGO_MANIFEST_DIR"));
} 

fn load_css() {
    let provider = CssProvider::new();

    let css_file_path = get_base_folder().join("src/ui/style.css");
    let file = File::for_path(css_file_path);

    provider.load_from_file(&file); 
    gtk4::style_context_add_provider_for_display(
        &Display::default().expect("Could not connect to a display."),
        &provider,
        gtk4::STYLE_PROVIDER_PRIORITY_APPLICATION,
    );
}
fn load_object_with_css<T: IsA<gtk4::glib::Object> + IsA<gtk4::Widget>>(object_builder: &Builder, object_id: &str) -> T {
    let object: T = object_builder.object(object_id).expect(&format!("failed to get {}", object_id));
    object.add_css_class(object_id);
    object 
}


fn set_label_expand_and_align(label: &Label) {
    label.set_hexpand(true);
    label.set_vexpand(true);
    label.set_halign(gtk4::Align::Fill);
    label.set_valign(gtk4::Align::Center);
}

fn create_page_with_label(page_id: &str, label_text: &str, base_folder: &PathBuf) -> (gtk4::Box, Label) {
    let page_builder = Builder::from_file(base_folder.join(format!("src/ui/{}.ui", page_id)).to_str().unwrap());
    let page: gtk4::Box = load_object_with_css(&page_builder, page_id);
    let label = Label::new(Some(label_text));
    set_label_expand_and_align(&label);

    label.add_css_class(&format!("{}-heading", page_id));

    (page, label)
}

fn load_buttons_to_page(base_folder: &PathBuf, page: &gtk4::Box, button_id: &str, error_message: &str) {
    let button_builder = Builder::from_file(base_folder.join(format!("src/ui/{}.ui", button_id)).to_str().unwrap());
    let button: gtk4::Button = button_builder.object(button_id).expect(&format!("Failed to get {}", error_message));
    page.append(&button);
}

fn add_vm_buttons_to_page(base_folder: &PathBuf, page: &gtk4::Box) {
    let vm_list = ship_commands::get_vm_list();

    for vm in vm_list {
        load_buttons_to_page(base_folder, page, &vm, "VM button");

        let button: Button = page.last_child().unwrap().downcast().unwrap();

        let click_gesture = GestureClick::new();
        click_gesture.set_button(3);
        button.add_controller(&click_gesture);

        click_gesture.connect_pressed(move |_gesture, _n_press, x, y| {
            let menu = Menu::new();
            let start_item = MenuItem::with_label("Start VM");
            let stop_item = MenuItem::with_label("Stop VM");
            let delete_item = MenuItem::with_label("Delete VM");

            menu.append(&start_item);
            menu.append(&stop_item);
            menu.append(&delete_item);

            menu.show_all();
            menu.popup_at_pointer(None);
        });
    }
}

fn add_container_buttons_to_page(base_folder: &PathBuf, page: &gtk4::Box) {
    let container_list = ship_commands::get_container_list();

    for container in container_list {
        load_buttons_to_page(base_folder, page, &container, "Container button");

        let button: Button = page.last_child().unwrap().downcast().unwrap();

        let click_gesture = GestureClick::new();
        click_gesture.set_button(3);
        button.add_controller(&click_gesture);

        click_gesture.connect_pressed(move |_gesture, _n_press, x, y| {
            let menu = Menu::new();
            let start_item = MenuItem::with_label("Start Container");
            let stop_item = MenuItem::with_label("Stop Container");
            let delete_item = MenuItem::with_label("Delete Container");

            menu.append(&start_item);
            menu.append(&stop_item);
            menu.append(&delete_item);

            menu.show_all();
            menu.popup_at_pointer(None);
        });
    }
} 

fn build_window(app: &Application) -> ApplicationWindow {
    let base_folder = get_base_folder();

    let main_window_builder = Builder::from_file(base_folder.join("src/ui/main_window.ui").to_str().unwrap());
    let window: ApplicationWindow = load_object_with_css(&main_window_builder, "main_window");
    window.set_application(Some(app));

    let _main_box: gtk4::Box = load_object_with_css(&main_window_builder, "main_box");
    let notebook: Notebook = load_object_with_css(&main_window_builder, "notebook");

    let (page1, label1) = create_page_with_label("page1", "Containers", &base_folder);
    let (page2, label2) = create_page_with_label("page2", "Virtual Machines", &base_folder);

    notebook.append_page(&page1, Some(&label1));
    notebook.append_page(&page2, Some(&label2));

    add_container_buttons_to_page(&base_folder, &page1); 
    add_vm_buttons_to_page(&base_folder, &page2); 

    load_buttons_to_page(&base_folder, &page1, "create_container_button", "Create Container button");
    load_buttons_to_page(&base_folder, &page2, "create_vm_button", "Create VM button");

    window
}

