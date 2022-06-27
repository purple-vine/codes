#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 100005, N = 10005;
int n, pos[M], L[N], R[N], a[M], t, op, l, r, c, siz; vector<int> s[N];
void pre(int n){
	int t = sqrt(n); siz = ceil(1.0 * n / t);
	for(int i = 1; i <= siz; i++){
		L[i] = t * (i - 1) + 1; R[i] = min(t * i, n);
		for(int j = L[i]; j <= R[i]; j++)
			pos[j] = i;
	}
}
bool check(int t){
	for(int i = t; i <= siz; i++){
		if(s[i].size > R[i] - L[i] + 1) s[i + 1].push_front()
	}
}
void modify(int l, int t){
	int p = pos[l]; s[p].push_back(t);
	for(int i = s[p].size() - 1; i > l - L[p]; i--) swap(s[p][i], s[p][i - 1]);
	check(p);
}
int query(int t){
	return s[pos[t]][t - L[pos[t]]];
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	pre(2 * n);
	for(int k = 1; k <= n; k++){
		scanf("%d %d %d %d", &op, &l, &r, &c);
		if(op == 0){
			modify(l, c);
		} else {
			printf("%d\n", query(r));
		}
	}
}
