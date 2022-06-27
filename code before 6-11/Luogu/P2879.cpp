#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;
const int M = 10005;
set<pair<int, int>> m;
int s[M];
int main(){
	int n, i, h, r;
	scanf("%d %d %d %d", &n, &i, &h, &r);
	while(r--){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a > b) swap(a, b);
		if(m.find(make_pair(a, b)) != m.end()) continue;
		m.insert(make_pair(a, b));
		s[a+1]--; s[b]++;
	}
	for(int i = 1; i <= n; i++)
		s[i] += s[i-1];
	for(int i = 1; i <= n; i++){
		printf("%d\n", h + s[i]);
	}
}
