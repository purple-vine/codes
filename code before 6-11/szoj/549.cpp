#include <cstdio>
#define ull unsigned long long
using namespace std;
const int M = 200005, N = 200005, s = (1 << 16) - 1;
ull a[M], t; int head[N][4], nxt[N][4], n, c[M], ans;
inline ull read(){
	ull x = 0; char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return x;
}
int calc(ull t){
	int ans = 0;
	for(; t; t >>= 1) ans += (t & 1);
	return ans;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		t = a[i] = read(); ans = 0;
		for(int j = 0; j < 4; j++){
			int m = t & s; t >>= 16;
			for(int k = head[m][j]; k; k = nxt[k][j]){
				if(c[k] != i && calc(a[i] ^ a[k]) == 3) ans++, c[k] = i;
			} nxt[i][j] = head[m][j]; head[m][j] = i;
		} printf("%d\n", ans);
	}
}
