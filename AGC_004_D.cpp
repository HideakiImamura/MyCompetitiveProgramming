//
// Created by 今村秀明 on 2016/09/05.
//
#include <stdio.h>
#include <vector>

using namespace std;

int N;
int K;
int a[100000];
vector<int> g[100000];
int ans = 0;

int dfs(int v) {
    int size = g[v].size();
    int steps = 0;
    for (int j = 0; j < size; j++) {
        int u = g[v][j];
        int h = dfs(u);
        steps = max(steps, h + 1);
    }
    if (steps == K - 1 && a[v] != 0) {
        a[v] = 0;
        steps = -1;
        ans++;
    }
    return steps;
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", a + i);
        a[i]--;
    }

    if (a[0] != 0) {
        a[0] = 0;
        ans++;
    }

    for (int i = 1; i < N; i++) {
        g[a[i]].push_back(i);
    }
    dfs(0);
    printf("%d\n", ans);

    return 0;
}