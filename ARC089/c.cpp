//
// Created by 今村秀明 on 2018/02/21.
//

#include <stdio.h>
#include <cmath>

int const max_N = 1e5;

int main() {
    int N, x[max_N + 1], y[max_N + 1], t[max_N + 1];
    x[0] = 0;
    y[0] = 0;
    t[0] = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d %d %d", &t[i], &x[i], &y[i]);
    }

    for (int i = 1; i <= N; ++i) {
        int tmp = std::fabs(x[i] - x[i - 1]) + std::fabs(y[i] - y[i - 1]);
        if (tmp > t[i] - t[i - 1] || tmp % 2 != (t[i] - t[i - 1]) % 2) {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");

    return 0;
}
