#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int M=200005;
int a[15]={0},t[200005]={0},l=0,ans1=0,ans2=0,b[15][200005]={0},ll[15]={0},dp[M][15]={0},n;
int judge(int s,int t){
	int ls=ll[s],lt=ll[t],ans=0;
	for(int i=1,j=1;j<lt;j++){
		i=upper_bound(&b[s][i],&b[s][ls+1],b[t][j])-b[s];
		if(b[s][i]<b[t][j+1]&&i!=ls+1) ans++; 
	}
	return ans;
}
char c[200005];
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%s",c);
        for(;c[l]!='\0';l++){
            t[l]=c[l]-'0';a[t[l]]++;b[t[l]][++ll[t[l]]]=l;
        }
        for(int i=0;i<=9;i++) {ans1=max(ans1,a[i]);b[i][++ll[i]]=b[i][1]+l;}
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                int t=judge(i,j);
                //printf("%d %d %d\n",i,j,t);
                ans2=max(ans2,t);
            }
        }
        //printf("%d %d\n",ans2*2,getans()/2*2);
        ans2=l-2*ans2;ans1=l-ans1;
        printf("%d\n",min(ans1,ans2));
        memset(a,0,sizeof(a));l=ans1=ans2=0;memset(dp,0,sizeof(dp));memset(ll,0,sizeof(ll));
    }
}//13744782
