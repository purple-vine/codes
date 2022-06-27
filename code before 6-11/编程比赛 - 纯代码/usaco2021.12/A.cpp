#include <cstdio>
#include <iostream>
using namespace std;
int n, g1, g2, h1, h2; long long ans; char c[500005];
char get(){
	char cc = getchar();
	while(cc != 'G' && cc != 'H') cc = getchar();
	return cc;
} 
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		c[i] = get();
		if(c[i] == 'H') ans += max(min(g1, i - 1) - g2, 0);
		else if(c[i] == 'G') ans += max(min(h1, i - 1) - h2, 0);
		if(c[i] == 'H'){
			h2 = h1; h1 = i;
		} else {
			g2 = g1; g1 = i;
		}
//		 printf("%d %d %d %d %d\n", g1, g2, h1, h2, ans);
	} printf("%lld\n", ans);
} 

