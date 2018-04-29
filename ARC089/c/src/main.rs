use std::io;

fn read_
fn main() {
    let mut n = String::new();
    io::stdin().read_line(&mut n).expect("Failed to read line!");
    let n: u32 = n.trim().parse().expect("N is not a number!");

    println!("{}", n);
}
