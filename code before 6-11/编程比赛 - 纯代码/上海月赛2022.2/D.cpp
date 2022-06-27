#include <cstdio>
using namespace std;
const int M = 50005;
int n, m, x, y, ans[M]; char op;
struct node{
	int to, nxt;
}e[M];
int head[M], cnt1;
int main(){
	scanf("%d %d", &n, &m);
	while(m--){
		scanf(" %c", &op);
		if(op == '!'){
			scanf("%d", &x);
			for(int i = head[x]; i; i = e[i].nxt)
				ans[e[i].to]++; 
		} else if(op == '+') {
			scanf("%d %d", &x, &y);
			e[++cnt1].to = y; e[cnt1].nxt = head[x];
			head[x] = cnt1;
		} else {
			scanf("%d %d", &x, &y);
			if(e[head[x]].to == y) {
				head[x] = e[head[x]].nxt; continue;
			}
			for(int j = head[x], i = e[j].nxt; i; i = e[x].nxt, j = e[j].nxt){
				if(e[i].to == y){
					e[j].nxt = e[i].nxt; break;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
}
