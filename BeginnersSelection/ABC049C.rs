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

fn solve(s: &[u8]) -> bool {
    match s.len() {
        0 => true,
        1 ... 4 => false,
        5 => {
            if &s[0..5] == b"dream" {
                solve(&s[5..])
            } else if &s[0..5] == b"erase" {
                solve(&s[5..])
            } else {
                false
            }
        }
        6 => {
            if &s[0..5] == b"dream" {
                solve(&s[5..])
            } else if &s[0..6] == b"eraser" {
                solve(&s[6..])
            } else if &s[0..5] == b"erase" {
                solve(&s[5..])
            } else {
                false
            }
        }
        _ => {
            if &s[0..7] == b"dreamer" {
                if solve(&s[7..]) {
                    true
                } else {
                    solve(&s[5..])
                }
            } else if &s[0..5] == b"dream" {
                solve(&s[5..])
            } else if &s[0..6] == b"eraser" {
                solve(&s[6..])
            } else if &s[0..5] == b"erase" {
                solve(&s[5..])
            } else {
                false
            }
        }
    }
}

fn main() {
    let s = read::<String>();
    let s = s.as_bytes();
    if solve(s) {
        println!("YES");
    } else {
        println!("NO");
    }
}