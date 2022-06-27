#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN=100000;
struct node{
    long long w;
    long long pa,lch,rch;
    int next;
}a[2*MAXN];
bool cmp(node b,node c){
	return b.w<c.w;
}
long long n,num,k;
void maketree(long long n){
    num=n;
    for(long long i=1;i<=n;i++) cin>>a[i].w;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<n;i++) a[i].next=i+1;
    for(int i=1;i<=n-1;i++){
        long long minn1=100000000000,mp1,minn2=100000000000,mp2;
        for(long long i=1;i<=2*n-1;i++){
            if(a[i].w>0&&a[i].pa==0&&a[i].w<minn1) minn1=a[i].w,mp1=i;
        }
        for(long long i=1;i<=2*n-1;i++){
            if(a[i].w>0&&a[i].pa==0&&a[i].w<minn2&&i!=mp1) minn2=a[i].w,mp2=i;
        }
        a[++num].lch=mp1;
        a[num].rch=mp2;
        a[mp1].pa=num;
        a[mp2].pa=num;
        a[num].w=a[mp1].w+a[mp2].w;
    }
    for(int i=1;i<=2*n-1;i++){
        printf("%lld %lld %lld %lld\n",a[i].w,a[i].pa,a[i].lch,a[i].rch);
    }
    printf("fl\n");
}
long long dp(int b){
    long long i=0,t=b;
    while(t!=2*n-1){
        t=a[t].pa;
        i++;
    }
    return i;
}
long long sum;
int main()
{
    long long maxn=0;
    cin >> n>>k;
    maketree(n);
    for(int i=1;i<=n;i++){
        long long dpi=dp(i);
        //cout << dpi << endl;
        sum+=dpi*a[i].w;
        if(dpi>maxn) maxn=dpi;
    }
    printf("%lld\n%lld",sum,maxn);
    return 0;
} 
