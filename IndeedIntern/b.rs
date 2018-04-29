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
    let v = read_vec::<u64>();
    let n = v[0];
    let m = v[1];
    let r = v[2];
    let c = v[3];
    let s = read::<String>().chars().collect::<Vec<char>>();

    let mut now = (r, c);
    let mut data: Vec<(u64, u64)> = vec![(r, c)];
    for i in 0..s.len() {
        //println!("      ({} {})", now.0, now.1);
        //for t in &data {
        //    println!("  {:?}", t);
        //}
        match s[i as usize] {
            'U' => {
                if now.0 == 1 { println!("{} {}", now.0, now.1); }
                let mut tmp = 0;
                for j in (1..now.0).rev() {
                    match data.binary_search(&(j, now.1)) {
                        Ok(k) => {
                            now = (j + 1, now.1);
                            data.insert(tmp, now);
                            println!("{} {}", now.0, now.1);
                            break;
                        }
                        Err(k) => {
                            if j == 1 {
                                now = (1, now.1);
                                match data.binary_search(&(j, now.1)) {
                                    Err(kk) => {tmp = kk}
                                    _ => {}
                                }
                                data.insert(tmp, now);
                                println! ("{} {}", now.0, now.1);
                            }
                            tmp = k;
                        }
                    }
                }
            }
            'D' => {
                if now.0 == n { println!("{} {}", now.0, now.1); }
                let mut tmp = 0;
                for j in (now.0 + 1)..n + 1 {
                    match data.binary_search(&(j, now.1)) {
                        Ok(k) => {
                            now = (j - 1, now.1);
                            data.insert(tmp, now);
                            println!("{} {}", now.0, now.1);
                            break;
                        }
                        Err(k) => {
                            if j == n {
                                now = (n, now.1);
                                match data.binary_search(&(j, now.1)) {
                                    Err(kk) => {tmp = kk}
                                    _ => {}
                                }
                                data.insert(tmp, now);
                                println! ("{} {}", now.0, now.1);
                            }
                            tmp = k;
                        }
                    }
                }
            }
            'L' => {
                if now.1 == 1 { println!("{} {}", now.0, now.1); }
                let mut tmp = 0;
                for j in (1..now.1).rev() {
                    match data.binary_search(&(now.0, j)) {
                        Ok(k) => {
                            now = (now.0, j + 1);
                            data.insert(tmp, now);
                            println!("{} {}", now.0, now.1);
                        }
                        Err(k) => {
                            if j == 1 {
                                now = (now.0, 1);
                                match data.binary_search(&(j, now.1)) {
                                    Err(kk) => {tmp = kk}
                                    _ => {}
                                }
                                data.insert(tmp, now);
                                println! ("{} {}", now.0, now.1);
                            }
                            tmp = k;
                        }
                    }
                }
            }
            _ => {
                if now.1 == m { println!("{} {}", now.0, now.1); }
                let mut tmp = 0;
                for j in (now.1 + 1)..m + 1 {
                    match data.binary_search(&(now.0, j)) {
                        Ok(k) => {
                            now = (now.0, j - 1);
                            data.insert(tmp, now);
                            println!("{} {}", now.0, now.1);
                        }
                        Err(k) => {
                            if j == m {
                                now = (now.0, m);
                                match data.binary_search(&(j, now.1)) {
                                    Err(kk) => {tmp = kk}
                                    _ => {}
                                }
                                data.insert(tmp, now);
                                println! ("{} {}", now.0, now.1);
                            }
                            tmp = k;
                        }
                    }
                }
            }
        }
    }
}