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
    let n = read::<u32>();
    let t = 0;
    let x = 0;
    let y = 0;
    let mut ans = true;
    for i in 0..n {
        let v = read_vec::<u32>();
        let t = v[0] - t;
        let x = v[1] - x;
        let y = v[2] - y;
        if x + y > t || (x + y) % 2 != t % 2 {
            ans = false;
        }
    }
    if ans {
        println!("Yes");
    } else {
        println!("No");
    }
}