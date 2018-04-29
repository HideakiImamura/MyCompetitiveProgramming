//
// Created by 今村秀明 on 2018/02/23.
//

#include <stdio.h>

const int mod = 1e9 + 7;

int qpow(int a, int x) {
    int ans = 1;
    while (x) {
        if (x & 1) ans = 1ll * ans * a % mod;
        a = 1ll * a * a % mod;
        x >>= 1;
    }
    return ans;
}

int digit(int n) {
    int ans = 0;
    while (n) {
        ans += 1;
        n /= 10;
    }
    return ans;
}

int main() {
    int s;
    scanf("%d", &s);
    int ans = 0;

    for (int d = 8; d <= s; ++d) {
        if (s % d == 0) {
            ans += (qpow(10, d) - qpow(10, d - 1) - s / d + 1) % mod;
            ans %= mod;
        }
    }

    for (int t = 1; t <= s / 8; ++t) {
        if (s % t != 0) {
            ++ans;
            ans += mod;
            ans %= mod;
        }
    }

    long long r = 1;
    int f = 0;
    for (int l = 1; l < 1e7; ++l) {
        while (f < s) {
            f += digit(r);
            r++;
        }
        if (f == s) {
            ++ans;
            ans %= mod;
        }
        f -= digit(l);
    }

    printf("%d\n", ans);

    return 0;
}
