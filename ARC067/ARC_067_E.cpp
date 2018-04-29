//
// Created by 今村秀明 on 2017/01/22.
// わからず
//

#include <stdio.h>

#define MOD 1000000007
unsigned long long dp[1005][1005];

unsigned long long fact(int n){
    if(n < 2){
        return 1;
    }else{
        return fact(n - 1) * n;
    }
}

unsigned long long pow(unsigned long long a, int b){
    if(b < 1){
        return 1;
    }else{
        return pow(a, b - 1) * a;
    }
}

unsigned long long func(int i, int j, int m){
    return (fact(i) / (fact(i - j * m) * pow(fact(j), m) * fact(m))) % MOD;
}

int main(){
    for(int i = 0; i < 1005; i++){
        for(int j = 0; j < 1005; j++){
            dp[i][j] = 0;
        }
    }
    int n,a,b,c,d;
    scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);

    dp[0][0] = 1;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++) {
            if(dp[i][j]!=0) {
                dp[i][j + 1] += dp[i][j];
                if (a <= j && j <= b) {
                    for (int k = c; k <= d; k++) {
                        if (i + j * k <= n) {
                            dp[i + j * k][j + 1] += (dp[i][j] * func(n - i, j, k)) % MOD;
                        }
                    }
                }
            }
        }
    }

    printf("%lld\n", dp[n][n + 1]);

    return 0;
}
