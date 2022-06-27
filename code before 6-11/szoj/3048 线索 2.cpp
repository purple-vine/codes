#include <cstdio>
#include <queue>
#define int long long
using namespace std;
priority_queue<int>p, q;
const int M = 100005;
int n, w[M], ans, cnt1, cnt2; bool f[M]; char cc[M];
signed main(){
	scanf("%lld", &n); getchar();
	for(int i = 1; i <= n; i++) cc[i] = getchar();
	for(int i = 1; i <= n; i++){
		scanf("%lld", &w[i]);
		if(cc[i] == '(') p.push(w[i]), cnt1++;
		else{
			cnt2++; q.push(-w[i]);
			if(cnt2) ans -= q.top(), q.pop(), cnt2--;
			else p.pop(), cnt1--;
		}
	}
	while(p.size()) ans += p.top(), p.pop();
	printf("%lld\n", ans);
}
