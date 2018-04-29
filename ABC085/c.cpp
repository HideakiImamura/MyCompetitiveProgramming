//
// Created by 今村秀明 on 2018/01/07.
//

#include <stdio.h>
#include <cmath>

int main(){
    int n, k, y, i, j, a = -1, b = -1, c = -1;
    scanf("%d %d", &n, &y);

    k = y / 1000;

    for(i = 0; i <= std::ceil((k - n) / 9); ++i){
        j = (k - n) - (9 * i);
        if((j % 4 == 0) && (j >= 0) && (n - i - (j / 4) >= 0)){
            a = i;
            b = j / 4;
            c = n - a - b;
            break;
        }
    }

    printf("%d %d %d\n", a, b, c);

    return 0;
}
