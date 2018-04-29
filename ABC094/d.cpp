//
// Created by 今村秀明 on 2018/04/14.
//

#include <stdio.h>
#include <algorithm>

int main() {
    int n
    long long a[int(10e5+1)];
    scanf("%d\n", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    std::sort(a, a + n, [](long long x, long long y) {return x > y;});

    long long x, y, tempx, tempy;
    for(int i = 0; i < n; ++i) {
        tempx = a[i];
        tempy = search(tempx / 2, a);
        if
    }
    return 0;
}
