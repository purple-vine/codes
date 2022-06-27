#include <cstdio>
using namespace std;
int t, n, k, p1, p2; bool f;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n); p1 = p2 = 0; k = 1; f = 1;
		for(int i = 1; i <= n; i++){
			scanf("%d", &p1);
			if(i == 1){
				k += p1; p2 = p1; continue;
			}
			if(p1 && !p2) k++;
			else if(p1 && p2) k += 5;
			else if(!p1 && !p2) f = 0;
			p2 = p1;
		} printf("%d\n", f ? k : -1);
	}
}
