use dotenv::dotenv;
use std::env;
use serde::Deserialize;

#[derive(Debug, Deserialize, Clone, Default)]
pub struct GtkEnv {
    pub application_id: String,
    pub title: String,
    pub default_width: i32,
    pub default_height: i32,
}

impl GtkEnv {
    pub fn init() -> Self {
        dotenv().expect("Failed to read .env file");

        let application_id = env::var("APPLICATION_ID").expect("APPLICATION_ID must be set");
        let title = env::var("TITLE").expect("TITLE must be set");
        let default_width: i32 = env::var("DEFAULT_WIDTH").expect("DEFAULT_WIDTH must be set").parse().unwrap();
        let default_height: i32 = env::var("DEFAULT_HEIGHT").expect("DEFAULT_HEIGHT must be set").parse().unwrap();

        Self {
            application_id,
            title,
            default_width,
            default_height,
        }
    }
}


