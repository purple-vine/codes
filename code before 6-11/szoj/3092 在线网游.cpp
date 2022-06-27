#include <cstdio>
#include <algorithm>
using namespace std;
const int M=500005;
struct tp{
	int t, f;
}st[M];
bool cmp(tp a, tp b) {return a.t < b.t;}
int n, s[M], t[M], n1, ans[M];
int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &s[i], &t[i]); t[i] += s[i];
		st[i * 2 - 1] = {s[i], 1}; st[i * 2] = {t[i], -1};
	}
	sort(st + 1, st + 2 * n + 1, cmp);
	for(int i = 1, cnt = 0; i < 2 * n; i++){
		cnt += st[i].f;
		ans[cnt] += st[i + 1].t - st[i].t;
	}
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
}
