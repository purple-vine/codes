#include <cstdio>
#include <algorithm>
#include <cmath>
#define e 1e-4
using namespace std;
const int M = 105;
double a[M][M], b[M]; int n; bool f;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {for(int j = 1; j <= n; j++) scanf("%lf", &a[i][j]); scanf("%lf",&b[i]);}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++) if(fabs(a[j][i]) > fabs(a[i][i])) {swap(a[i], a[j]); swap(b[i], b[j]);}
		if(fabs(a[i][i]) < e) {f = 1; continue;}
		for(int j = 1; j <= n; j++){
			if(i == j) continue; double r = a[j][i] / a[i][i];
			for(int k = 1; k <= n; k++) a[j][k] -= a[i][k] * r;
			b[j] -= r * b[i];
		}
	}
	if(f){
		bool f1 = 0;
		for(int i = 1; i <= n; i++){
			bool ff = 0;
			for(int j = 1; j <= n; j++) if(fabs(a[i][j]) > e) {ff = 1; break;}
			if(ff) continue;
			if(fabs(b[i]) > e) f1 = 1;
		}
		printf("%d", f1 == 1 ? -1 : 0);
		return 0;
	}
	for(int i = 1; i <= n; i++) printf("x%d=%.2lf\n", i, fabs(b[i] / a[i][i]) < e ? 0.00 : b[i] / a[i][i]);
}
