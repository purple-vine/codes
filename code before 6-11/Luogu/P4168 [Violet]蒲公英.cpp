//《算进》第一个思路 
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int M = 40005, N = 105;
int a[M], b[M], n, n1, m, cnt[N][N][M], t, bl[M];
int L[N], lim, R[N], x, siz, pl[N][N], anss[N][N];
void pre(){
	for(int i = 1; i <= t; i++){
		L[i] = R[i-1] + 1, R[i] = min(n, siz * i);
//		printf("%d %d\n", L[i], R[i]);
		for(int j = L[i]; j <= R[i]; j++)
			bl[j] = i;
	}
	for(int l = 1; l <= t; l++){
		for(int r = l; r <= t; r++){
			for(int k = L[l]; k <= R[r]; k++){
				cnt[l][r][a[k]]++;
				if(cnt[l][r][a[k]] > anss[l][r])
					anss[l][r] = cnt[l][r][a[k]], pl[l][r] = a[k];
				else if(cnt[l][r][a[k]] == anss[l][r])
					pl[l][r] = min(pl[l][r], a[k]);
			}
		}
	}
}
int col[M];
int calc(int l, int r){
	int p = bl[l], q = bl[r], maxx = -1, ans = 0;
	if(p == q){
		for(int i = l; i <= r; i++){
			col[a[i]]++;
			if(col[a[i]] > maxx)
				maxx = col[a[i]], ans = a[i];
			else if(col[a[i]] == maxx)
				ans = min(ans, a[i]);
		}
		for(int i = l; i <= r; i++)
			col[a[i]]--;
		return ans;
	}
	p++; q--; maxx = anss[p][q]; ans = pl[p][q];
	for(int i = l; i <= R[p-1]; i++){
		cnt[p][q][a[i]]++;
		if(cnt[p][q][a[i]] > maxx)
			maxx = cnt[p][q][a[i]], ans = a[i];
		else if(cnt[p][q][a[i]] == maxx)
			ans = min(ans, a[i]);
	}
	for(int i = L[q+1]; i <= r; i++){
		cnt[p][q][a[i]]++;
		if(cnt[p][q][a[i]] > maxx)
			maxx = cnt[p][q][a[i]], ans = a[i];
		else if(cnt[p][q][a[i]] == maxx)
			ans = min(ans, a[i]);
	}
	for(int i = l; i <= R[p-1]; i++)
		cnt[p][q][a[i]]--;
	for(int i = L[q+1]; i <= r; i++)
		cnt[p][q][a[i]]--;
	return ans; 
}
int main(){
//	freopen("P4168_1.in", "r", stdin);
	scanf("%d %d", &n, &m);
	t = pow(n, 1.0/3); siz = ceil(1.0 * n / t);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[i] = a[i];
	sort(b+1, b+n+1); n1 = unique(b+1, b+n+1) - b - 1;
	for(int i = 1; i <= n; i++)
		a[i] = lower_bound(b+1, b+n1+1, a[i]) - b;
	pre();
	while(m--){
		int l, r;
		scanf("%d %d", &l, &r);
		l = (l+x-1) % n + 1; r = (r+x-1) % n + 1;
		if(l > r) swap(l, r);
		x = b[calc(l, r)];
		printf("%d\n", x);
	}
}
