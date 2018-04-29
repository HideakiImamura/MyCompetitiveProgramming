//
// Created by 今村秀明 on 2018/04/14.
//
#include <stdio.h>

int main() {
    int n, m, x, a, l = 0, r = 0;
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &a);
        if (a < x) {
            l += 1;
        } else {
            r += 1;
        }
    }

    if (l < r) {
        printf("%d\n", l);
    } else {
        printf("%d\n", r);
    }
    return 0;
}
