//
// Created by 今村秀明 on 2016/09/07.
//

#include <stdio.h>
#include <cmath>
#include <math.h>

unsigned long long int n, s, b;

unsigned long long int f(unsigned long long int b, unsigned long long int n) {
    unsigned long long int ans = 0;
    while (n) {
        ans += n % b;
        n /= b;
    }
    return ans;
}

unsigned long long int solve() {
    unsigned long long int sqn = floor(sqrt(n));
    unsigned long long int p = 1;
    b = 2;

    if (s > n) return -1;
    if (s == n) return n + 1;

    while (b <= sqn) {
        if (f(b, n) == s) return b;
        b++;
    }
    b = (n - s) / p + 1;
    while (p <= sqn) {
        if (f(b, n) == s) return b;
        p++;
        b = (n - s) / p + 1;
    }
    return -1;
}

int main() {
    scanf("%lld %lld", &n, &s);

    printf("%lld\n", solve());

    return 0;
}