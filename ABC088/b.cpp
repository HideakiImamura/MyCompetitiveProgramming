//
// Created by 今村秀明 on 2018/02/18.
//

#include <stdio.h>
#include <algorithm>
#include <functional>

int solve(int n, int *a) {
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            ans += a[i];
        } else {
            ans -= a[i];
        }
    }
    return ans;
}

int main() {
    int n, a[100];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    std::sort(std::begin(a), std::begin(a) + n, std::greater<int>());

    printf("%d\n", solve(n, a));

    return 0;
}
