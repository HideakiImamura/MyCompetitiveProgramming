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

fn relu(x: i32) -> i32 {
    if x > 0 {
        x
    } else {
        0
    }
}

fn main() {
    let v = read_vec::<i32>();
    let a = v[0];
    let b = v[1];
    let c = v[2];
    let x = v[3];
    let y = v[4];

    let ans1 = c * 2 * x + relu(y - x) * b;
    let ans2 = c * 2 * y + relu(x - y) * a;
    let ans3 = a * x + b * y;
    let ans = std::cmp::min(std::cmp::min(ans1, ans2), ans3);
    println!("{}", ans);
}