//
// Created by 今村秀明 on 2017/01/20.
//

#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    unsigned long long n,a,b,ans,tmp;
    vector<unsigned long long> x;

    scanf("%lld %lld %lld", &n, &a, &b);
    for(int i = 0; i < n; i++){
        scanf("%lld", &tmp);
        x.push_back(tmp);
    }

    ans = 0;
    for(int i = 0; i < x.size() - 1; i++){
        ans += min((x[i + 1] - x[i]) * a, b);
    }
    printf("%lld\n", ans);

    return 0;
}
