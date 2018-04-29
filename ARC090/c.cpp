//
// Created by 今村秀明 on 2018/02/14.
//

#include <stdio.h>
#include <numeric>
#include <algorithm>
#include <iterator>

int main(){
    int N, A1[100], A2[100];
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A1[i]);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A2[i]);
    }

    int x[100], ans;
    for (int n = 0; n < N; ++n) {
        x[n] = std::accumulate(std::begin(A1), std::begin(A1) + n + 1, 0) + std::accumulate(std::begin(A2) + n, std::begin(A2) + N, 0);
    }
    ans = *std::max_element(std::begin(x), std::begin(x) + N);

    printf("%d\n", ans);

    return 0;
}
