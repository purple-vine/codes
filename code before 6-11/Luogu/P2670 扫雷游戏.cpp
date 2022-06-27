#include <iostream>
using namespace std;
bool a[105][105];
int n,m;
int de[8][2]={{-1,1},{-1,0},{-1,-1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char t;
			cin >> t;
			if(t=='*') a[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==1) cout << '*';
			else{
				int cnt=0;
				for(int k=0;k<8;k++){
					cnt+=a[i+de[k][0]][j+de[k][1]];
				}
				cout << cnt;
			}
		}
		cout << endl;
	}
	return 0;
}
