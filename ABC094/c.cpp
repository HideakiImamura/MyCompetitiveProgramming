//
// Created by 今村秀明 on 2018/04/14.
//
#include <stdio.h>
#include <vector>
#include <algorithm>

long long solve(int n, int i, std::vector<long long> x) {
    x[i] = 10e9 + 1;
    //for(int j = 0; j < n; ++j) { printf("(%lld, %d) ", x[j].first, x[j].second); }
    std::sort(x.begin(), x.end());
    return x[n / 2 - 1];
}

int main() {
    int n;
    std::vector <long long> x;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        long long data;
        scanf("%lld", &data);
        x.push_back(data);
    }
    for(int i = 0; i < n; ++i) {
        printf("%lld\n", solve(n, i, x));
    }

    return 0;
}
