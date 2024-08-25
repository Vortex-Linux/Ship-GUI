use gtk4 as gtk;
use gtk::prelude::*;
use gtk::{glib};

mod build_main;
mod gtk_env;

use build_main::build_app;

fn main() -> glib::ExitCode {
    let app = build_app();
    app.run()
}

