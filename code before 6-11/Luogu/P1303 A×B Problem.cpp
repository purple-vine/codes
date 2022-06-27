#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int m = 2005;
int a[m],b[m],alen,blen,ans[2*m],anslen;
string s1,s2;
int main(){
    cin >> s1 >> s2;
    if(s1=="0" || s2=="0") {
    	cout << 0;
    	return 0;
	}
    alen = s1.length();
    blen = s2.length();
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
	for(int i=anslen-1;i>=0;i--) cout << ans[i];
	return 0;
}
