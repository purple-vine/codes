#include <cstdio>
#include <time.h>
#include <algorithm>
#define int long long
#define mod 1000000007
using namespace std;
const int M = 6055;
struct poi {
	int x, y;
} p[M];
int dp[M][M], l[M][M], r[M][M], n, ans;
bool cmp(poi a, poi b) {return a.y > b.y;}
signed main(){
	freopen("1.in", "r", stdin);
	double time = clock();
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) scanf("%lld %lld", &p[i].x, &p[i].y);
	sort(p + 1, p + n + 1, cmp);
	for(int i = 2; i <= n; i++){
		for(int j = 1; j < i; j++){
			dp[i][j] = 1;
			for(int k = 1; k < j; k++){
				if((p[i].x > p[j].x && p[i].x < p[k].x) || (p[i].x < p[j].x && p[i].x > p[k].x))
					dp[i][j] = (dp[i][j] + dp[j][k]) % mod;
			}
			ans = (ans + dp[i][j]) % mod;
		}
	}
	printf("%lld\n", ans + n);
	double time2 = clock();
	printf("%lf\n", (time2 - time) / 1000);
}
