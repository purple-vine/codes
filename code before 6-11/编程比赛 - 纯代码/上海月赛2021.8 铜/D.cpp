#include <cstdio>
#include <stack>
#define wrong {printf("Invalid");return 0;}
using namespace std;
const int M=100005;
bool in[M];stack<int>st;
int n,t,l=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		if(in[t]){
			if(t!=st.top()) wrong
			else {st.pop();in[t]=0;}
		}
		else{
			for(l++;l<t;l++) {st.push(l);in[l]=1;}
		}
	}
	printf("Valid");return 0;
}
