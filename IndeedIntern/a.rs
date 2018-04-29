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
    let mut a: Vec<u32> = Vec::new();
    for i_ in 0..n {
        let ai = read::<u32>();
        a.push(ai);
    }
    let s = read::<String>();
    let s = s.chars().collect::<Vec<char>>();

    let mut min = 0;
    let mut max = 0;
    for i in 0..n {
        match s[i as usize] {
            'W' => {
                max += a[i as usize];
                min += a[i as usize] / 2 + 1;
            }
            'L' => {
                if a[i as usize] % 2 == 0 {
                    max += a[i as usize] / 2 - 1;
                } else {
                    max += a[i as usize] / 2;
                }
            }
            _ => {
                max += a[i as usize] / 2;
                min += a[i as usize] / 2;
            }
        }
    }

    println!("{} {}", min, max);
}