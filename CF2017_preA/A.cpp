//
// Created by 今村秀明 on 2017/09/27.
//
#include <stdio.h>

int main(int argv, char **argc) {
    char s[11];
    scanf("%s", s);
    if (s[0]=='Y' && s[1]=='A' && s[2]=='K' && s[3]=='I') {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}