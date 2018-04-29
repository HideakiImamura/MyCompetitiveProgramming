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
    let mut a = [0u32; 101];
    for _i in 0..n {
        let d = read::<usize>();
        if a[d] == 0 {
            a[d] = 1;
        }
    }
    println!("{}", a.to_vec().iter().sum::<u32>());
}