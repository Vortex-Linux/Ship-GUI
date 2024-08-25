use gtk4::prelude::*;
use super::gtk_env::GtkEnv;
use gtk4::{Application, ApplicationWindow, Notebook, Box, Label, Orientation, Align};

pub fn build_app() -> Application {
    let gtk_env = GtkEnv::init();

    let app = Application::builder()
        .application_id(&gtk_env.application_id)
        .build();

    app.connect_activate(move | app | {
        let window = build_window(&gtk_env, app);
        window.present();
    });

    app 
}

fn build_window(gtk_env: &GtkEnv, app: &Application) -> ApplicationWindow {
    let window = ApplicationWindow::builder()
        .application(app)
        .title(&gtk_env.title)
        .default_width(gtk_env.default_width)
        .default_height(gtk_env.default_height)
        .build();

    let notebook = Notebook::new();

    let page1 = Box::new(Orientation::Vertical, 0);
    let label1 = Label::new(Some("This is the first tab"));
    page1.append(&label1);
    notebook.append_page(&page1, Some(&Label::new(Some("Tab 1"))));

    let page2 = Box::new(Orientation::Vertical, 0);
    let label2 = Label::new(Some("This is the second tab"));
    page2.append(&label2);
    notebook.append_page(&page2, Some(&Label::new(Some("Tab 2"))));

    let container = Box::new(Orientation::Vertical, 0);
    container.set_halign(Align::Center);

    container.append(&notebook);
    window.set_child(Some(&container));

    window
}

