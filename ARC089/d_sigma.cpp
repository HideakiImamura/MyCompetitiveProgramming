//
// Created by 今村秀明 on 2018/02/22.
//

#include <iostream>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
int s[3010][3010];
int a[2][1010][1010];
void print(int n, int m){
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			printf("%d ", s[i][j]);
		}
		printf("\n");
	}
	printf("--------------------\n");
}
int main(){
	int N,K;
	cin>>N>>K;
	rep(i,N){
		int x,y;
		char c;
		cin>>x>>y>>c;
		if(c=='W') y += K;
		x %= 2*K;
		y %= 2*K;
		s[x][y]++;
		s[x+K][y+K]++;
		s[x][y+K]--;
		s[x+K][y]--;
	}
	print(3 * K, 3 * K);
	rep(i,3*K) rep(j,3*K) s[i][j+1] += s[i][j];
	print(3 * K, 3 * K);
	rep(i,3*K) rep(j,3*K) s[i+1][j] += s[i][j];
	print(3 * K, 3 * K);
	int ans = 0;
	rep(i,K*3) rep(j,K*3){
		int p = (i/K+j/K)%2;
		a[p][i%K][j%K] += s[i][j];
	}
	rep(p,2) rep(i,K) rep(j,K) chmax(ans,a[p][i][j]);
	cout<<ans<<endl;
}

