#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
	freopen("1.in", "w", stdout);
	srand(time(0));
	int n = 100;
	printf("%d\n", n);
	for(int i = 1; i <= n; i++){
		printf("%d %d\n", rand() % 2000000000 - 1e9, rand() % 2000000000 - 1e9);
	}
}
