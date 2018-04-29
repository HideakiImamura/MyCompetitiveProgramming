//
// Created by 今村秀明 on 2018/02/10.
//

#include <stdio.h>
#include <cmath>

long long int f(long long int b, long long int n){
    if (n < b) {
        return n;
    } else {
        return f(b, n / b) + n % b;
    }
}

int main(){
    long long int n, s;
    scanf("%lld", &n);
    scanf("%lld", &s);

    if (n == s) {
        printf("%lld\n", n + 1);
        return 0;
    } else if (s > n) {
        printf("-1\n");
        return 0;
    }

    for(long long int b = 2; b <= std::sqrt(n); ++b){
        if (f(b, n) == s){
            printf("%lld\n", b);
            return 0;
        }
    }

    long long int b = 0;
    for(long long int p = std::sqrt(n); 1 <= p; --p){
        b = 1 + (n - s) / p;
        if (b >= 2 && b > p && p*p!=n) {
            if (f(b, n) == s) {
                printf("%lld\n", b);
                return 0;
            }
        }
    }

    printf("-1\n");

    return 0;
}
