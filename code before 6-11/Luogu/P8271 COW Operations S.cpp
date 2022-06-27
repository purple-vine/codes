#include <cstdio>
#include <cstring>
#define calc(l, r, op) (s[r][op] - s[l-1][op])
using namespace std;
const int M = 200005;
char a[M]; int q, l, r, s[M][3], n;
int get(char c){
	switch(c){
		case 'C' : return 0;
		case 'O' : return 1;
		case 'W' : return 2;
	}
}
int main(){
	scanf("%s", a+1);
	n = strlen(a+1);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 3; j++){
			s[i][j] = s[i-1][j] + (get(a[i]) == j);
		}
	}
	scanf("%d", &q);
	while(q--){
		scanf("%d %d", &l, &r);
		if((calc(l, r, 2) + calc(l, r, 0)) % 2 == 1 && (calc(l, r, 0) + calc(l, r, 1)) % 2 == 1)
			putchar('Y');
		else
			putchar('N');
	}
}
