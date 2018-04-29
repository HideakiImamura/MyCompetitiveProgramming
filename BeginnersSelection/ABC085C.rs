fn read<T: std::str::FromStr>() -> T {
    let mut n = String::new();
    std::io::stdin().read_line(&mut n).ok();
    n.trim().parse().ok().unwrap()
}

fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().split_whitespace()
        .map(|e| e.parse().ok().unwrap()).collect()
}

fn main() {
    let v = read_vec::<i32>();
    let n = v[0];
    let y = v[1] / 1000;
    for a in 0..n+1 {
        let b4 = y - n - 9 * a;
        let c4 = - y + 5 * n + 5 * a;
        if b4 % 4 == 0 && c4 % 4 == 0 && 0 <= b4 && 0 <= c4 {
            println!("{} {} {}", a, b4 / 4, c4 / 4);
            std::process::exit(0);
        }
    }
    println!("-1 -1 -1");
}