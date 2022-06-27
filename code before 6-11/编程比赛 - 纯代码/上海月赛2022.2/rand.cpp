#include <bits/stdc++.h>
#include <random>
using namespace std;
mt19937 rnd(time(0));
int rand(int l, int r){
	return rnd() % (r - l + 1) + l;
}
int main(){
	int n = 5; printf("%d\n", n);
	for(int i = 1; i <= n; i++) printf("%d ", rand(1, 15));
}
