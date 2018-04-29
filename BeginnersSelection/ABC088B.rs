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
    let _n = read::<u32>();
    let mut a = read_vec::<u32>();
    let mut ans = 0;

    a.sort_by(|a, b| b.cmp(a));

    for i in 0..a.len() {
        if i % 2 == 0 {
            ans += a[i];
        } else {
            ans -= a[i];
        }
    }

    println!("{}", ans);
}