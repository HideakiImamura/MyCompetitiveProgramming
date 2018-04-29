//
// Created by 今村秀明 on 2018/01/07.
//

#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

int rec(int *d, int left, int right){
    int l = right - left + 1;
    if (l == 1) {
        return 1;
    } else {
        if (d[left] == d[left + 1]) {
            return rec(d, left + 1, right);
        } else {
            return 1 + rec(d, left + 1, right);
        }
    }
}

int main(){
    int n, i, N;
    int d[100];
    scanf("%d", &n);
    for(i = 0; i < n; ++i){
        scanf("%d", &d[i]);
    }

    std::sort(d, d + n, std::greater<int>());

    N = rec(d, 0, n - 1);
    printf("%d", N);

    return 0;
}
