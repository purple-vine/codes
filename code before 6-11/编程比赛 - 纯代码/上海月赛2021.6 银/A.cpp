#include <cstdio>
#include <iostream>
using namespace std;
int n,a[10005],s1[10005],s2[10005],ans;//s1:shang s2:xia
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s1[i]=s2[i]=1;
		for(int j=1;j<=i;j++){
			if(a[j]<a[i]){
				if(s1[j]+1>s2[i])
					s2[i]=s1[j]+1;
			}
			else if(a[j]>a[i]){
				if(s2[j]+1>s1[i])
					s1[i]=s2[j]+1;
			}
		}
//		printf("%d %d\n",s1[i],s2[i]);
		ans=max(ans,s1[i]);ans=max(ans,s2[i]);
	}
	printf("%d",ans);
	return 0;
}
