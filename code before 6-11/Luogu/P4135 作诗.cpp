#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int M = 100005, N = 70;
int a[M], b[M], n, n1, m, cnt[N][N][M], t, bl[M];
int L[N], lim, R[N], x, siz, anss[N][N], c;
void pre(){
	for(int i = 1; i <= t; i++){
		L[i] = R[i-1] + 1, R[i] = min(n, siz * i);
//		printf("%d %d\n", L[i], R[i]);
		for(int j = L[i]; j <= R[i]; j++)
			bl[j] = i;
	}
	for(int l = 1; l <= t; l++){
		for(int r = l; r <= t; r++){
			int *p = cnt[l][r];
			for(int k = L[l]; k <= R[r]; k++){
				if(p[a[k]]) anss[l][r] += ((p[a[k]] & 1) << 1) - 1;
				++p[a[k]];
			}
		}
	}
}
int col[M];
int calc(int l, int r){
	int p = bl[l], q = bl[r], ans = 0;
	if(p == q){
		for(int i = l; i <= r; i++){
			if(col[a[i]]) ans += ((col[a[i]] & 1) << 1) - 1;
			++col[a[i]];
//			printf("%d ", ans);
		}
		for(int i = l; i <= r; i++)
			--col[a[i]];
		return ans;
	}
	p++; q--; ans = anss[p][q]; int *pp = cnt[p][q]; //printf("%d %d\n", p, q);
	for(int i = l; i <= R[p-1]; i++){
		if(pp[a[i]]) ans += ((pp[a[i]] & 1) << 1) - 1;
		++pp[a[i]];
	}
	for(int i = L[q+1]; i <= r; i++){
		if(pp[a[i]]) ans += ((pp[a[i]] & 1) << 1) - 1;
		++pp[a[i]];
	}
	for(int i = l; i <= R[p-1]; i++)
		--pp[a[i]];
	for(int i = L[q+1]; i <= r; i++)
		--pp[a[i]];
	return ans; 
}
int main(){
// 	freopen("P4135_1.in", "r", stdin);
// 	freopen("1.out", "w", stdout);
	scanf("%d %d %d", &n, &c, &m);
	t = 65; siz = ceil(1.0 * n / t);
//	printf("%d %d\n", t, siz);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[i] = a[i];
	sort(b+1, b+n+1); n1 = unique(b+1, b+n+1) - b;
	for(int i = 1; i <= n; i++)
		a[i] = lower_bound(b+1, b+n1+1, a[i]) - b;
	pre();
	while(m--){
		int l, r;
		scanf("%d %d", &l, &r);
		l = (l+x) % n + 1; r = (r+x) % n + 1;
		if(l > r) swap(l, r);
		x = calc(l, r);
		printf("%d\n", x);
	}
}
