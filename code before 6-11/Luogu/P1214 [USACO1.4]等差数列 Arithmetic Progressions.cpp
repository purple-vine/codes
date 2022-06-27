#include <cstdio>
#include <iostream>
using namespace std;
const int M = 255;
bool f[200005]; int n, m, maxx = -1, minn = 1e9;
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i <= m; i++){
		for(int j = i; j <= m; j++){
			int k = i * i + j * j;
			f[k] = 1; maxx = max(maxx, k); minn = min(minn, k);
		}
	}
	int lim = (maxx - minn) / (n-1) + 1; bool ff = 0;
	for(int i = 1; i <= lim; i++){ //b 
		for(int j = minn, ll = maxx - (n-1)*i; j <= ll; j++){ //a 
			bool flag = 1; int l = j + (n-1) * i;
			for(int k = j; k <= l; k += i)
				if(!f[k]) {flag = 0; break;}
			if(flag) printf("%d %d\n", j, i), ff = 1;
		}
	}
	if(!ff) puts("NONE");
	return 0;
}
