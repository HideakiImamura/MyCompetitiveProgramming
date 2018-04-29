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
    let v = read_vec::<u32>();
    let n = v[0];
    let a = v[1];
    let b = v[2];
    let mut ans = 0;

    for i in 1..n+1 {
        let mut s = 0;
        let mut i_ = i;
        for _k in 0..5 {
            s += i_ % 10;
            i_ /= 10;
        }
        if a <= s && s <= b {
            ans += i;
        }
    }

    println!("{}", ans);
}