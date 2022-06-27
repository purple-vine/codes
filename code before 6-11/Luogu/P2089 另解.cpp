#include <iostream>
#include <stdio.h>
using namespace std;
int n,sum,t[10000][11];
int main(){
	cin >> n;
	if(n<10||n>30){
		cout << 0;
		return 0;
	}
	for(int a=1;a<=3;a++){
		for(int b=1;b<=3;b++){
			for(int c=1;c<=3;c++){
				for(int d=1;d<=3;d++){
					for(int e=1;e<=3;e++){
						for(int f=1;f<=3;f++){
							for(int g=1;g<=3;g++){
								for(int h=1;h<=3;h++){//8
									for(int i=1;i<=3;i++){
										for(int j=1;j<=3;j++){
											if(a+b+c+d+e+f+g+h+i+j==n){
												sum++;
												t[sum][1]=a;t[sum][2]=b;t[sum][3]=c;t[sum][4]=d;t[sum][5]=e;
												t[sum][6]=f;t[sum][7]=g;t[sum][8]=h;t[sum][9]=i;t[sum][10]=j;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << sum << endl;
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=10;j++) printf("%d ",t[i][j]);
		printf("\n");
	}
	return 0;
}
