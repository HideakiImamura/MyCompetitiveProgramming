//
// Created by 今村秀明 on 2016/09/06.
//

int H,W;
char a[100][100];
int dp[100][100][100][100];

int main()
{
    int x,y;
    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            scanf("%c", &a[i][j]);
            if(a[i][j]=='E'){
                x=i;
                y=j;
            }
        }
    }

    dp[0][0][0][0]=0;
    for (int l = 0; l < x; ++l) {
        for (int u = 0; u < y; ++u) {
            for (int r = 0; r < W-x; ++r) {
                for (int d = 0; d < H-y; ++d) {

                }
            }
        }
    }
}