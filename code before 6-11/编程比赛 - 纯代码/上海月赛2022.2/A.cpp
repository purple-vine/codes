#include <cstdio>
#include <queue>
//#define ONLINE_JUDGE
#define int long long
#ifndef ONLINE_JUDGE
#define debug(k) for(int i = 1; i <= n; i++) printf("%lld ", k[i]);\
printf("\n")
#else
#define debug(k) 
#endif
using namespace std; 
const int M = 500005;
//左往右 第一个>= 第一个<= 右往左 第一个> 第一个<
int p1[M], p2[M], p3[M], p4[M], a[M], n;
int q1[M], r1, q2[M], r2;
void pre(){
	for(int i = 1; i <= n; i++){
		while(r1 >= 1 && a[q1[r1]] < a[i])
			p1[q1[r1]] = i, r1--;
		q1[++r1] = i;
		while(r2 >= 1 && a[q2[r2]] > a[i])
			p2[q2[r2]] = i, r2--;
		q2[++r2] = i;
	}
	for(int i = 1; i <= r1; i++)
		p1[q1[i]] = n + 1;
	for(int i = 1; i <= r2; i++)
		p2[q2[i]] = n + 1;
	r1 = r2 = 0;
	for(int i = n; i >= 1; i--){
		while(r1 >= 1 && a[q1[r1]] <= a[i])
			p3[q1[r1]] = i, r1--;
		q1[++r1] = i;
		while(r2 >= 1 && a[q2[r2]] >= a[i])
			p4[q2[r2]] = i, r2--;
		q2[++r2] = i;
	}
	for(int i = 1; i <= r1; i++)
		p3[q1[i]] = 0;
	for(int i = 1; i <= r2; i++)
		p4[q2[i]] = 0;
}
long long ans;
signed main(){
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	pre();
	for(int i = 1; i <= n; i++){
		int k1 = (p1[i] - p3[i] - 1), k2 = (p2[i] - p4[i] - 1);
		ans += (p1[i]-i) * (i-p3[i]) * a[i] - (p2[i]-i) * (i-p4[i]) * a[i];
//		printf("%lld : + %lld - %lld\n", a[i], (p1[i]-i) * (i-p3[i]), (p2[i]-i) * (i-p4[i]));
	}
	debug(p1); debug(p2); debug(p3); debug(p4);
	printf("%lld\n", ans);
}
/*
5
9 2 12 2 1 
*/
