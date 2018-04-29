//
// Created by 今村秀明 on 2018/04/01.
//

#include <iostream>
#include <string>

bool is_tasai(std::string s) {
    bool ans = true;
    char a[26];
    for(int i = 0; i < 26; ++i) {
        a[i] = 0;
    }
    for(int i = 0; i < s.size(); ++i){
        if (a[s[i] - 97] == 1) {
            return false;
        }else{
            a[s[i] - 97] = 1;
        }
    }
    return true;
}

int main() {
    std::string s, ss;
    int length;
    bool b = true;

    std::cin >> s;

    s.push_back('a');
    length = s.size();
    if (is_tasai(s)) {
        std::cout << s << "\n";
        b = false;
    }
    while (b) {
        if (length == 0) {
            printf("-1\n");
            break;
        }
        if (s[length - 1] != 'z') {
            s[length - 1] += 1;
            if (is_tasai(s)) {
                std::cout << s << "\n";
                break;
            }
        } else {
            s.pop_back();
            length = s.size();
        }
    }
    return 0;
}
