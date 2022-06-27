#include <iostream>
#include <stdio.h>
using namespace std;
char t[4]={'N','E','S','W'};
void deal(){
	char a[105];
	int b[105];
	b[0]=0;
	scanf("%s",a);
	int len=1;
	int sum;
	//int start=a[0];
	while(a[len]=='N'||a[len]=='S'||a[len]=='E'||a[len]=='W'){
		/*for(int i=0;i<4;i++){
			if(t[i]==a[len]){
				a[len]=i;
				//if(a[len]<0) a[len]+=4;
			}
		}*/
		char n=a[len-1];
		char m=a[len];
		if(n==m){
			b[len]=b[len-1];
			sum+=b[len];
		} 
		else if((n=='N'&&m=='E')||(n=='S'&&m=='W')||(n=='E'&&m=='S')||(n=='W'&&m=='N')){
			b[len]=1;
			sum+=1;
		}
		else{
			b[len]=-1;
			sum-=1;
		}
		//cout << b[len] << " ";
		len++;
	}
	//cout << endl;
	if(sum>0) cout << "CW\n";
	else cout << "CCW\n";
}//'N','E','S','W'
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) deal();
	return 0;
}
