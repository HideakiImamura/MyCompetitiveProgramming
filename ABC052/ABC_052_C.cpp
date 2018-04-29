//
// Created by 今村秀明 on 2017/01/20.
//

#include <stdio.h>
#include <set>
#include <math.h>

using namespace std;

int is_prime(int n){
    int ans = 1;
    if(n==2)return 1;
    for(int i = 2; i <= ceil(sqrt(n)); i++){
        if(n % i == 0){
            ans=0;
            break;
        }
    }
    return ans;
}

int main(){
    set<int> facts;
    int a,b,N,num;
    unsigned long long ans;

    scanf("%d", &N);

    for(int i=2;i<=N;i++){
        for(int j=2;j<=i;j++) {
            if (is_prime(j) && i % j == 0) {
                facts.insert(j);
            }
        }
    }

    ans = 1;
    for(int i : facts){
        num = 1;
        for(int n = 1;n <= N; n++){
            a = n;
            while(1){
                b = a % i;
                a = a / i;
                if(a==0 || b!=0){
                    break;
                }else{
                    num++;
                }
            }
        }
        ans = ans * num % 1000000007;
    }

    printf("%lld\n", ans);

    return 0;
}