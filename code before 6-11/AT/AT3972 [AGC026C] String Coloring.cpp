#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#define int128 __int128
using namespace std;
const int M = 20;
char s[M << 1]; int n, a[M << 1]; map<pair<int128, int128>, int> t;
int128 s1, s2; long long ans;
void print(int128 a){
	int s1[M], n; memset(s1, 0, sizeof(s1));
	for(; a > 0; a /= 27) s1[++n] = a % 27;
	for(int i = n; i >= 1; i--) printf("%d ", s1[i]);
	putchar('\n');
}
void print(int128 a, int128 b){
	print(a); print(b);
}
void dfs1(int k){
	if(k == n+1) {t[make_pair(s1, s2)]++; return;}
	s2 = s2 * 27 + a[k]; dfs1(k+1);
	s2 /= 27; s1 = s1 * 27 + a[k]; dfs1(k+1);
	s1 /= 27; return;
}
void dfs2(int k){
	if(k == n) {ans += 1ll * t[make_pair(s2, s1)]; return;}
	s2 = s2 * 27 + a[k]; dfs2(k-1);
	s2 /= 27; s1 = s1 * 27 + a[k]; dfs2(k-1);
	s1 /= 27; return;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= 2*n; i++)
		scanf(" %c", &s[i]), a[i] = s[i] - 'a' + 1;
	dfs1(1); dfs2(2*n);
	printf("%lld\n", ans);
}
