//
// Created by 今村秀明 on 2018/02/18.
//

#include <stdio.h>
#include <queue>

typedef std::pair<int, int> P;

const int INF = 1e5;
int H, W;
char s[50][51];

int d[50][50];
int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

int bfs() {
    std::queue<P> que;

    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            d[i][j] = INF;
        }
    }

    que.push(P(0, 0));
    d[0][0] = 0;

    while (que.size()) {
        P p = que.front();
        que.pop();
        if (p.first == H - 1 && p.second == W - 1) {
            break;
        }

        for(int k = 0; k < 4; k++) {
            int ni = p.first + di[k], nj = p.second + dj[k];
            if (0 <= ni && ni < H && 0 <= nj && nj < W && s[ni][nj] != '#' && d[ni][nj] == INF) {
                que.push(P(ni, nj));
                d[ni][nj] = d[p.first][p.second] + 1;
            }
        }
    }

    return d[H-1][W-1];
}
int main() {
    scanf("%d %d", &H, &W);
    for(int i = 0; i < H; ++i) {
        scanf("%s", s[i]);
    }

    int n0 = -1;
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W ; ++j) {
            if (s[i][j] == '.') {
                n0 += 1;
            }
        }
    }

    int nmin = bfs();


    if (nmin == INF) {
        nmin = n0 + 1;
    }

    printf("%d\n", n0 - nmin);

    return 0;
}
