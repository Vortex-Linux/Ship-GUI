use gtk4::prelude::*;
use super::gtk_env::GtkEnv;
use gtk4::{Application, ApplicationWindow};

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

fn build_window(gtk_env: &GtkEnv, app: &Application)-> ApplicationWindow {
    ApplicationWindow::builder()
        .application(app)
        .title(&gtk_env.title)
        .default_width(gtk_env.default_width)
        .default_height(gtk_env.default_height)
        .build()
}