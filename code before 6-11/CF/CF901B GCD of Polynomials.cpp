#include <cstdio>
using namespace std;
const int M = 155;
int s[M][M], n;
int main(){
	scanf("%d", &n);
	s[0][0] = 1;
	s[1][1] = 1;
	for(int i = 1; i <= n; i++){
		s[i+1][0] = s[i-1][0];
		for(int j = 1; j <= i+1; j++){
			s[i+1][j] = s[i][j-1] + s[i-1][j];
		}
		bool f = 1;
		for(int j = 0; j <= i+1; j++){
			if(s[i+1][j] < -1 || s[i+1][j] > 1) {f = 0; break;}
		}
		if(f) continue;
		printf("%d,", i);
		s[i+1][0] = -s[i-1][0];
		for(int j = 1; j <= i+1; j++){
			s[i+1][j] = s[i][j-1] - s[i-1][j];
		}
	}
	printf("%d\n", n);
	for(int i = 0; i <= n; i++)
		printf("%d ", s[n][i]);
	printf("\n%d\n", n-1);
	for(int i = 0; i < n; i++)
		printf("%d ", s[n-1][i]);
}
