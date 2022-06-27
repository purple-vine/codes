#include <iostream>
#include <stdio.h>
#include <cmath>
#define ll long long
using namespace std;
int a[1005][1005],n;
ll t[1005],ans;
int main(){
	//freopen("pacman.in","r",stdin);
	//freopen("pacman.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		t[1]+=a[i][i];
		t[n]+=a[n-i][i];
	}
	for(int i=2;i<n;i++){
		for(int j=1;j<=2*(n-2);j++){
			t[i]+=a[n-abs(j-n)][n-abs(i-n)];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int u=t[i]+t[j];
			maxn=max(maxn,u);
		}
	}
	return 0;
}
