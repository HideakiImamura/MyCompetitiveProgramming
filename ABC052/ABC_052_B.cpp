//
// Created by 今村秀明 on 2017/01/20.
//

#include <stdio.h>

int main(){
    int n;
    char s[100];
    int m;
    int x = 0;
    int i;

    scanf("%d", &n);
    scanf("%s", s);
    m = x;
    for(i=0;i<n;i++){
        if(s[i]=='I'){
            x++;
        }else{
            x--;
        }
        if(m < x){
            m = x;
        }
    }
    printf("%d", m);
    return 0;
}
