#include <cstdio>
#include <iostream>
using namespace std; 
int a[5], b[5], min1 = 1e9, min2 = 1e9;
int main(){
	for(int i = 1; i <= 4; i++){
		scanf("%d", &a[i]);
		min1 = min(min1, a[i]);
	}
	for(int i = 1; i <= 3; i++){
		scanf("%d", &b[i]);
		min2 = min(min2, b[i]);
	}
	printf("%d", min1 + min2);
}
