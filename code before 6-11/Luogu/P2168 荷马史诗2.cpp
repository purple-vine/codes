#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN=100000;
struct node{
    long long w;
    int pa,ch[10];
    int next;
}a[2*MAXN];
bool cmp(node a,node b){
    return a.w<b.w;
}
long long n,num,k;
int r=1;
void maketree(long long n,int k){
    num=n;
    for(long long i=1;i<=n;i++) cin>>a[i].w;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<n;i++) a[i].next=i+1;
    bool flag=(n%(k-1)==1||k==2);
    for(r=1;;r++){
    	num++;
    	int t=1,cnt=0;
    	if(n%(k-1)==1||k==2||flag){
	        while(cnt<k&&t>0){
	            if(a[t].pa==0&&a[t].w>0){
	            	a[num].ch[++cnt]=t;
	        		a[t].pa=num;
	        		a[num].w+=a[t].w;
				}
				t=a[t].next;
	        }
	    }
	    else{
	    	//cout << "tt" << endl;
	    	int s;
	    	if(n%(k-1)==0) s=k-1;
	    	else s=n%(k-1);
	    	while(cnt<s&&t>0){
	            if(a[t].pa==0&&a[t].w>0){
	            	a[num].ch[++cnt]=t;
	        		a[t].pa=num;
	        		a[num].w+=a[t].w;
				}
				t=a[t].next;
	        }
	        flag=true;
		}
        //cout << i << endl;
        int j=1;
        for(;j<n+r;j=a[j].next){
        	if((a[j].w<=a[num].w&&a[a[j].next].w>=a[num].w)||a[j].next==0){
        		a[num].next=a[j].next;
        		a[j].next=num;
			}
		}
		/*for(int i=1;i<=2*n-1;i++){
	        printf("%d %lld %d %d\n",i,a[i].w,a[i].pa,a[i].next);
	        for(int j=1;j<=k;j++) printf("%d ",a[i].ch[j]);
	        cout << endl;
	    }
	    cout << endl;*/
	    if(t==0){
	    	//cout << "fl";
	    	break;
		}
    }
}
long long dp(int b){
    long long i=0,t=b;
    while(a[t].pa!=0){
        t=a[t].pa;
        i++;
    }
    return i;
}
long long sum;
int main() {
    long long maxn=0;
    cin >> n>>k;
    maketree(n,k);
    /*for(int i=1;i<=n+r;i++){
	    printf("%d %lld %d %d\n",i,a[i].w,a[i].pa,a[i].next);
	    for(int j=1;j<=k;j++) printf("%d ",a[i].ch[j]);
	    cout << endl;
    }*/
    for(int i=1;i<=n;i++){
        long long dpi=dp(i);
        //printf("%d %d\n",i,dpi);
        sum+=dpi*a[i].w;
        maxn=max(dpi,maxn);
    }
    printf("%lld\n%lld",sum,maxn);
    return 0;
}
