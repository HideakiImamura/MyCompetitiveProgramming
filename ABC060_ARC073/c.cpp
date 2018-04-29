//
// Created by 今村秀明 on 2017/05/03.
//
#include <stdio.h>

int main(int argc, char **argv){
    int n, T, t[200000], ans=0;
    scanf("%d %d", &n, &T);
    for(int i=0; i<n; i++){
        scanf("%d", &t[i]);
    }
    ans += T;
    for(int i=1; i<n; i++){
        if(t[i]-t[i-1]>T){
            ans += T;
        }else{
            ans += t[i]-t[i-1];
        }
    }
    printf("%d\n", ans);
    return 0;
}
