use gdk4::Display;
use gtk4::prelude::*;
use gtk4::{Application, ApplicationWindow, Builder, Label, Notebook, CssProvider};
use gio::File;

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

fn load_css() {
    let provider = CssProvider::new();
    let file = File::for_path("src/ui/style.css");

    provider.load_from_file(&file); 

    gtk4::style_context_add_provider_for_display(
        &Display::default().expect("Could not connect to a display."),
        &provider,
        gtk4::STYLE_PROVIDER_PRIORITY_APPLICATION,
    );
}

fn build_window(app: &Application) -> ApplicationWindow {
    let builder = Builder::from_file("src/ui/interface.ui");

    let window: ApplicationWindow = builder.object("main_window").expect("Failed to get main_window");
    window.set_application(Some(app));

    let main_box: gtk4::Box = builder.object("main_box").expect("failed to get main_box");
    let notebook: Notebook = builder.object("notebook").expect("Failed to get notebook");
    let page1: gtk4::Widget = builder.object("page1").expect("Failed to get page1");
    let page2: gtk4::Widget = builder.object("page2").expect("Failed to get page2");

    let label1 = Label::new(Some("Containers"));
    let label2 = Label::new(Some("Virtual Machines"));

    main_box.add_css_class("main_box");
    notebook.add_css_class("notebook");
    page1.add_css_class("page1");
    page2.add_css_class("page2");
    label1.add_css_class("label1");
    label2.add_css_class("label2");
    
    notebook.set_tab_label(&page1, Some(&label1));
    notebook.set_tab_label(&page2, Some(&label2));

    label1.set_hexpand(true);
    label1.set_vexpand(true);
    label1.set_halign(gtk4::Align::Fill);
    label1.set_valign(gtk4::Align::Center);

    label2.set_hexpand(true);
    label2.set_vexpand(true);
    label2.set_halign(gtk4::Align::Fill);
    label2.set_valign(gtk4::Align::Center);

    window
}

