use std::process::Command;

fn get_vm_list() -> Vec<String> {
    let output = Command::new("sh")
        .arg("-c")
        .arg("ship --vm list | awk '{print $2}' | tail -n +3 | sed '/^$/d'")
        .output()
        .expect("Failed to list VMs");
    
    let output_str = String::from_utf8_lossy(&output.stdout);
    
    output_str.lines().map(String::from).collect()
}

fn get_ctr_list() -> Vec<String> {
    let output = Command::new("sh")
        .arg("-c")
        .arg("ship --ctr list | awk '{print $3}' | tail -n +2 | sed '/^$/d'")
        .output()
        .expect("Failed to list containers");
    
    let output_str = String::from_utf8_lossy(&output.stdout);

    output_str.lines().map(String::from).collect()
}

