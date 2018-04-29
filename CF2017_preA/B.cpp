//
// Created by 今村秀明 on 2017/09/27.
//

#include <stdio.h>

int main() {
    int a, b, N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for (a=0; a<=M; ++a) {
        for (b = 0; b <= N; ++b) {
            if (a * N + b * M - 2 * a * b == K) {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}