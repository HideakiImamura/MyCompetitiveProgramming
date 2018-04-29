//
// Created by 今村秀明 on 2018/02/11.
//

#include <iostream>
#include <string>

int main(){
    std::string s;
    std::cin >> s;

    int n = s.length();
    int ans = n;
    for(int k = 0; k < n - 1; ++k){
        if(s[k] != s[k+1]){
            ans = std::min(ans, std::max(k + 1, n - k - 1));
        }
    }

    printf("%d\n", ans);

    return 0;
}
