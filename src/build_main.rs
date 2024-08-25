use gtk4::prelude::*;
use gtk4::{Application, ApplicationWindow, Builder, Label, Notebook};

pub fn build_app() -> Application {
    let gtk_env = super::gtk_env::GtkEnv::init();

    let app = Application::builder()
        .application_id(&gtk_env.application_id)
        .build();

    app.connect_activate(move |app| {
        let window = build_window(app);
        window.present();
    });

    app
}

fn build_window(app: &Application) -> ApplicationWindow {
    let builder = Builder::from_file("src/ui/interface.ui");

    let window: ApplicationWindow = builder.object("main_window").expect("Failed to get main_window");
    window.set_application(Some(app));

    let notebook: Notebook = builder.object("notebook").expect("Failed to get notebook");
    let page1: gtk4::Widget = builder.object("page1").expect("Failed to get page1");
    let page2: gtk4::Widget = builder.object("page2").expect("Failed to get page2");

    let label1 = Label::new(Some("Containers"));
    let label2 = Label::new(Some("Virtual Machines"));

    notebook.set_tab_label(&page1, Some(&label1));
    notebook.set_tab_label(&page2, Some(&label2));

    window
}

