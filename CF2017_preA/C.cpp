//
// Created by 今村秀明 on 2017/09/27.
//

#include <stdio.h>
#include <queue>
#include <utility>

//void printq(std::queue<char> q) {
//    while(!q.empty()) {
//        printf("%c", q.front());
//        q.pop();
//    }
//    printf("\n");
//}

std::pair<bool, std::queue<char> > ok(std::queue<char> q, int N, int n) {
    // qにnつ組がN組作れるかどうか調べる。

    int n_counter = 0, N_counter = 0, iter_counter = 0;
    char a, b;
    std::pair<bool, std::queue<char> > ret;
    if (N == 0) {
        ret = std::make_pair(true, q);
        return ret;
    }
    while (!q.empty()) {
        if (n_counter == 0) {
            a = q.front();
            q.pop();
            n_counter += 1;
            iter_counter = q.size() + 1;
        } else if (1 <= n_counter && n_counter <= n - 1){
            b = q.front();
            q.pop();
            iter_counter -= 1;
            if (a == b) {
                n_counter += 1;
            } else {
                if (iter_counter == 0) {
                    n_counter = 0;
                }
                q.push(b);
            }
        } else if (n_counter == n) {
            n_counter = 0;
            N_counter += 1;
            printf("%d\n", N_counter);
            if (N_counter == N) {
                ret = std::make_pair(true, q);
                return ret;
            }
        }
    }
    if (n_counter == n) {
        N_counter += 1;
    }
    if (N_counter == N) {
        ret = std::make_pair(true, q);
    } else {
        ret = std::make_pair(false, q);
    }
    return ret;
}

int main() {
    std::queue<char> q1;
    int i, j, H, W;
    char tmp[101];
    bool flag;
    std::pair<bool, std::queue<char> > ret;

    scanf("%d %d", &H, &W);
    for (i = 0; i < H; ++i) {
        scanf("%s", tmp);
        for (j = 0; j < W; ++j) {
            q1.push(tmp[j]);
        }
    }
    if (H % 2 == 0 && W % 2 == 0) {
        flag = ok(q1, H * W / 4, 4).first;
    } else if (H % 2 == 0 && W % 2 == 1) {
        ret = ok(q1, H * (W - 1) / 4, 4);
        flag = ret.first && (ok(ret.second, H / 2, 2).first);
    } else if (H % 2 == 1 && W % 2 == 0) {
        ret = ok(q1, (H - 1) * W / 4, 4);
        flag = ret.first && (ok(ret.second, W / 2, 2).first);
    } else {
        ret = ok(q1, (H - 1) * (W - 1) / 4, 4);
        flag = ret.first && (ok(ret.second, (H + W - 2) / 2, 2).first);
    }

    if (flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}