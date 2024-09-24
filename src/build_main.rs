use gdk4::Display;
use gtk4::prelude::*;
use gtk4::{Application, ApplicationWindow, Builder, Label, Notebook, CssProvider};
use gio::File;
use std::path::PathBuf;

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

fn set_label_expand_and_align(label: &Label) {
    label.set_hexpand(true);
    label.set_vexpand(true);
    label.set_halign(gtk4::Align::Fill);
    label.set_valign(gtk4::Align::Center);
}
 
fn build_window(app: &Application) -> ApplicationWindow {

    let base_folder = get_base_folder();
    
    let main_window_builder = Builder::from_file(base_folder.join("src/ui/main_window.ui").to_str().unwrap());
    let page1_builder = Builder::from_file(base_folder.join("src/ui/page1.ui").to_str().unwrap());
    let page2_builder = Builder::from_file(base_folder.join("src/ui/page2.ui").to_str().unwrap());
    let create_container_button_builder = Builder::from_file(base_folder.join("src/ui/create_container_button.ui").to_str().unwrap());
    let create_vm_button_builder = Builder::from_file(base_folder.join("src/ui/create_vm_button.ui").to_str().unwrap());
    
    let window: ApplicationWindow = main_window_builder.object("main_window").expect("Failed to get main_window");
    window.set_application(Some(app));
    
    let main_box: gtk4::Box = main_window_builder.object("main_box").expect("failed to get main_box");
    let notebook: Notebook = main_window_builder.object("notebook").expect("Failed to get notebook");
    
    let page1: gtk4::Box = page1_builder.object("page1").expect("Failed to get page1");
    let page2: gtk4::Box = page2_builder.object("page2").expect("Failed to get page2");

    let label1 = Label::new(Some("Containers"));
    let label2 = Label::new(Some("Virtual Machines"));

    let create_container_button: gtk4::Button = create_container_button_builder.object("create_container_button").expect("Failed to get Create Container button");
    let create_vm_button: gtk4::Button = create_vm_button_builder.object("create_vm_button").expect("Failed to get Create VM button"); 
 
    notebook.append_page(&page1, Some(&label1));
    notebook.append_page(&page2, Some(&label2));

    page1.append(&create_container_button);  
    page2.append(&create_vm_button);

    main_box.add_css_class("main_box");
    notebook.add_css_class("notebook");
    page1.add_css_class("page1");
    page2.add_css_class("page2");
    label1.add_css_class("label1");
    label2.add_css_class("label2");
    label1.add_css_class("create_container_button");
    label2.add_css_class("create_vm_button");

    set_label_expand_and_align(&label1);
    set_label_expand_and_align(&label2);
    
    window
}

