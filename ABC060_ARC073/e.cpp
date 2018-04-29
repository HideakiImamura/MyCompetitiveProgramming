//
// Created by 今村秀明 on 2017/05/04.
//

#include <stdio.h>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv){
    int n;
    signed long long int x, y, max_x, min_x, max_y, min_y, tmp, s, t, dx, dy;
    signed long long int tmp_maxx, tmp_minx, tmp_maxy, tmp_miny, tmp_maxx_, tmp_minx_, tmp_maxy_, tmp_miny_;
    scanf("%d", &n);
    scanf("%lld %lld", &max_x, &max_y);
    min_x = max_x;
    min_y = max_y;
    if(n >= 2){
        scanf("%lld %lld", &min_x, &min_y);
        s = abs(max_x - min_x)*abs(max_y - min_y);
        t = abs(max_x - min_y)*abs(max_y - min_x);
        if(t < s){
            tmp = min_x;
            min_x = min_y;
            min_y = tmp;
        }
        if(max_x < min_x){
            tmp = max_x;
            max_x = min_x;
            min_x = tmp;
        }
        if(max_y < min_y){
            tmp = max_y;
            max_y = min_y;
            min_y = tmp;
        }
    }
    for(int i = 2; i < n; i++){
        scanf("%lld %lld", &x, &y);
        if(x < min_x){
            dx = max_x - x;
            tmp_maxx = max_x;
            tmp_minx = x;
        }else if(max_x < x){
            dx = x - min_x;
            tmp_maxx = x;
            tmp_minx = min_x;
        }else{
            dx = max_x - min_x;
            tmp_maxx = max_x;
            tmp_minx = min_x;
        }
        if(y < min_y){
            dy = max_y - y;
            tmp_maxy = max_y;
            tmp_miny = y;
        }else if(max_y < y){
            dy = y - min_y;
            tmp_maxy = y;
            tmp_miny = min_y;
        }else{
            dy = max_y - min_y;
            tmp_maxy = max_y;
            tmp_miny = min_y;
        }
        s = dx * dy;
        if(y < min_x){
            dx = max_x - y;
            tmp_maxx_ = max_x;
            tmp_minx_ = y;
        }else if(max_x < y){
            dx = y - min_x;
            tmp_maxx_ = y;
            tmp_minx_ = min_x;
        }else{
            dx = max_x - min_x;
            tmp_maxx_ = max_x;
            tmp_minx_ = min_x;
        }
        if(x < min_y){
            dy = max_y - x;
            tmp_maxy_ = max_y;
            tmp_miny_ = x;
        }else if(max_y < x){
            dy = x - min_y;
            tmp_maxy_ = x;
            tmp_miny_ = min_y;
        }else{
            dy = max_y - min_y;
            tmp_maxy_ = max_y;
            tmp_miny_ = min_y;
        }
        t = dx * dy;
        if(s < t){
            max_x = tmp_maxx;
            min_x = tmp_minx;
            max_y = tmp_maxy;
            min_y = tmp_miny;
        }else{
            max_x = tmp_maxx_;
            min_x = tmp_minx_;
            max_y = tmp_maxy_;
            min_y = tmp_miny_;
        }
    }
    printf("%lld\n", (max_x - min_x)*(max_y - min_y));
    return 0;
}
