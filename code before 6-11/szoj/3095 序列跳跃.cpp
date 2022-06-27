#include <cstdio>
#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
const int M = 2005;
bitset<3600005>t[M];
int n, a, b, d[M], s, m, op[M];
char c[4][4] = {{'L', 'D', 'U', 'R'}, 
				{'U', 'L', 'R', 'D'},
				{'D', 'R', 'L', 'U'},
				{'R', 'U', 'D', 'L'}};
int main(){
	scanf("%d %d %d", &n, &a, &b); a += b; b = a - 2 * b;
	for(int i = 1; i <= n; i++) scanf("%d", &d[i]), s += d[i];
	if(abs(s % 2) != abs(a % 2) || abs(s % 2) != abs(b % 2)) {printf("No"); return 0;}
	a = (a + s) / 2; b = (b + s) / 2;
	if(a < 0) a = abs(a), m += 2;
	if(b < 0) b = abs(b), m += 1;
	t[0][0] = 1;
	for(int i = 1; i <= n; i++) t[i] = t[i - 1] | (t[i - 1] << d[i]);
	if(!t[n][a] || !t[n][b]) {printf("No"); return 0;}
	printf("Yes\n");
	for(int i = n; i >= 1; i--){
		if(a >= d[i] && t[i - 1][a - d[i]]) op[i] += 2, a -= d[i];
		if(b >= d[i] && t[i - 1][b - d[i]]) op[i] += 1, b -= d[i];
	}
	for(int i = 1; i <= n; i++) putchar(c[m][op[i]]);
}
