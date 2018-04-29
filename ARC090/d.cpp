//
// Created by 今村秀明 on 2018/02/14.
//

#include <stdio.h>
#include <vector>

const int MAX_N = 100000;
int x[MAX_N];
bool ok[MAX_N];
std::vector<std::pair<int, int> > G[MAX_N];


bool dfs(int s, int now) {
    x[s] = now;
    ok[s] = true;
    for (auto e: G[s]) {
        int to = e.first;
        int cost = e.second;
        if (!ok[to]){
            if (!dfs(to, now + cost)) {
                return false;
            }
        } else if (x[to] - now != cost){
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        int L, R, D;
        scanf("%d %d %d", &L, &R, &D);
        L--;
        R--;
        G[L].push_back(std::make_pair(R, D));
        G[R].push_back(std::make_pair(L, -D));
    }
    for (int i = 0; i < N; ++i) {
        ok[i] = false;
    }

    for (int i = 0; i < N; ++i) {
        if (!ok[i]) {
            if (!dfs(i, 0)) {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;
}
