#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
string mul_num(string s1,string s2){//高精度乘法 
	const int max_long=10005;
	int a[max_long],b[max_long],ans[max_long];
	long anslen;
	if(s1=="0" || s2=="0") {
    	return "0";
	}
    long alen = s1.length();
    long blen = s2.length();
    for(int i=0;i<alen;i++) a[i]=s1[i]-'0';
    reverse(a,a+alen);
    for(int i=0;i<blen;i++) b[i]=s2[i]-'0';
    reverse(b,b+blen);
	for(int i=0;i<alen;i++){
		for(int j=0;j<blen;j++) ans[i+j]+=a[i]*b[j];
	}
	while(ans[anslen]>0) anslen++;
	for(int i=0;i<=anslen;i++) {ans[i+1]+=ans[i]/10;ans[i]=ans[i]%10;}
	if(ans[anslen+1]>0) anslen++;
	string anss;
	for(int i=anslen-1;i>=0;i--) anss=anss+(char)(ans[i]+'0');
	return anss;
}
string add_num(string s1,string s2){//高精度加法 
	const int m=10005;
	int a[m],b[m],c[m],s[m],anss,slen,alen,blen;
    alen = s1.length();
    blen = s2.length();
    slen = max(alen,blen);
    for(int i=0;i<alen;i++) a[i]=s1[i]-'0';
    reverse(a,a+alen);
    for(int i=0;i<blen;i++) b[i]=s2[i]-'0';
    reverse(b,b+blen);
	for(int i=0;i<=slen;i++){
        s[i]=a[i]+b[i]+c[i];
        if(s[i]>9){s[i]-=10;c[i+1]++;}
    }
    while(s[slen]>0) slen++;
    for(int i=slen-1;i>=0;i--) anss=anss+(char)(s[i]+'0');
}
int main(){
	
}
