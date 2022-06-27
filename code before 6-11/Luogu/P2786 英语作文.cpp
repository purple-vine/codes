#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int m,n,p;
long long sum;
struct word{
	string w;
	int v;
}a[100000];
bool ch(char c){
	return (c>='a'&&c<='z')||(c>='A'&&c<='Z');
}
bool di(char c){
	return (c>='0'&&c<='9');
}
int e(string q){
	int l=1,r=n,ans=-1,mid=0;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid].w==q) return mid;
		else if(a[mid].w<q) l=mid+1;
		else r=mid-1;
	}
	return -1;
}
bool cmp(word a,word b){
	return a.w<b.w;
}
int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++){
		cin >> a[i].w >> a[i].v;
	}
	sort(a+1,a+n+1,cmp);
	cout << "fl" << endl;
	char c;
	string t;
	while(scanf("%c",c)!=EOF){
		if(!di(c) && !ch(c)){
			if(e(t)!=-1){
				sum+=(a[e(t)].v%p);
				sum%=p;
			}
			t="";
		}
		else t=t+c;
	}
	cout << "fl" << endl;
	cout << sum;
	return 0;
}
