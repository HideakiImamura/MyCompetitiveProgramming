//
// Created by 今村秀明 on 2018/02/10.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

int main(){
    int N, A, tmp;
    int x[51];

    scanf("%d %d", &N, &A);
    for(int i = 0; i < N; ++i){
        scanf("%d", &tmp);
        x[i + 1] = tmp;
    }

    int X = std::max(*std::max_element(&x[1], &x[N]), A);
    long long int dp[N + 1][2 * N * X + 1];

    for(int i = 0; i < N; ++i){
        x[i + 1] -= A;
    }

    for(int j = 0; j <= N; ++j){
        for(int t = 0; t <= 2 * N * X; ++t){
            if (j == 0 && t == N * X) {
                dp[j][t] = 1;
            } else if (1 <= j && 0 <= t - x[j] && t - x[j] <= 2 * N * X){
                dp[j][t] = dp[j - 1][t - x[j]] + dp[j - 1][t];
            } else if (1 <= j && (t - x[j] < 0 || 2 * N * X < t - x[j])){
                dp[j][t] = dp[j - 1][t];
            } else {
                dp[j][t] = 0;
            }
        }
    }

    printf("%lld\n", dp[N][N * X] - 1);

    return 0;
}
