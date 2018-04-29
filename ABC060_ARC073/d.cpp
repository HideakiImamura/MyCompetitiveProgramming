//
// Created by 今村秀明 on 2017/05/03.
//
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <numeric>
#include <vector>

int main(int argc, char **argv){
    unsigned long long int n, W, w0, w, v, ans, tmp;
    std::vector<int> ws[4];
    scanf("%lld %lld", &n, &W);
    scanf("%lld %lld", &w0, &v);
    ws[0].push_back(v);
    for(int i = 1; i<n; i++){
        scanf("%lld %lld", &w, &v);
        ws[w-w0].push_back(v);
    }
    for(int i = 0; i<4; i++){
        std::sort(ws[i].begin(), ws[i].end());
    }
    ans = 0;
    for(int a = 0; a <= ws[0].size(); a++){
        for(int b = 0; b <= ws[1].size(); b++){
            for(int c = 0; c <= ws[2].size(); c++){
                for(int d = 0; d <= ws[3].size(); d++){
                    if(w0*(a+b+c+d)+b+2*c+3*d <= W){
                        tmp = std::accumulate(ws[0].begin()+ws[0].size()-a, ws[0].end(), 0);
                        tmp += std::accumulate(ws[1].begin()+ws[1].size()-b, ws[1].end(), 0);
                        tmp += std::accumulate(ws[2].begin()+ws[2].size()-c, ws[2].end(), 0);
                        tmp += std::accumulate(ws[3].begin()+ws[3].size()-d, ws[3].end(), 0);
                        if(tmp>ans) ans = tmp;
                    }
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
