//
// Created by 今村秀明 on 2017/05/03.
//
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    char a[11], b[11], c[11];
    scanf("%s %s %s", a, b, c);
    if (a[strlen(a)-1]==b[0] && b[strlen(b)-1]==c[0]){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}
