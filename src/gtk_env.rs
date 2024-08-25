use dotenv::dotenv;
use std::env;
use serde::Deserialize;

#[derive(Debug, Deserialize, Clone, Default)]
pub struct GtkEnv {
    pub application_id: String,
}

impl GtkEnv {
    pub fn init() -> Self {
        dotenv().expect("Failed to read .env file");

        let application_id = env::var("APPLICATION_ID").expect("APPLICATION_ID must be set");

        Self {
            application_id,
        }
    }
}


