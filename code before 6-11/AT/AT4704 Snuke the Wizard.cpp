#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std; 
const int M = 200005, N = 50;
int cnt[N], n, q, ans, minn[N], maxx[N];
char t[M], d[M], a[M];
int getpl(int k){
	for(int i = 1; i <= q; i++){
		if(a[k] == t[i]) k += (d[i] == 'L' ? -1 : 1);
	}
	return k;
}
int main(){
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++)
		scanf(" %c", &a[i]);
	for(int i = 1; i <= q; i++)
		scanf(" %c %c", &t[i], &d[i]);
	int l = 1, r = n, ansl = 0, ansr = n+1;
	while(l <= r){
		int mid = l + r >> 1;
		if(getpl(mid) == 0) ansl = mid, l = mid + 1;
		else r = mid - 1;
	}
	l = 1; r = n;
	while(l <= r){
		int mid = l + r >> 1;
		if(getpl(mid) == n+1) ansr = mid, r = mid-1;
		else l = mid+1; 
	}
	printf("%d %d\n",ansl, ansr);
	printf("%d\n", ansr - ansl - 1);
}
