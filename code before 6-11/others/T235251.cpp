#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 500005;
namespace subtask1{
	#define lowbit(x) (x & -x)
    int s[M], n, st[M];
    void upd(int x, int t){
    	for(; x <= n; x += lowbit(x)) s[x] += t;
	} 
	int query(int x){
		int ans = 0;
		for(; x >= 1; x -= lowbit(x)) ans += s[x];
		return ans;
	}
	template <class T>
	int work(T *l, T *r){
		n = r - l;
	    int ans = 0;
		for(int i = 0; i < n; i++){
			ans += i - query(l[i]);
			upd(l[i], 1);
		}
		return ans;
	}
}
namespace subtask2{
	int f[M];
	int work(int *l, int *r){
		int n = r - l, len = 0;
		for(int i = 0; i < n; i++){
			if(l[i] > f[len]) f[++len] = -l[i];
			else f[lower_bound(f+1, f+len+1, -l[i]) - f + 1] = l[i];
		}
		return n - len;
	}
	int dp[M];
	int work2(int *l, int *r){
		int n = r - l, len = 0;
		for(int i = 0; i < n; i++){
			dp[i] = 1;
			for(int j = 0; j < i; j++){
				if(l[j] < l[i]) dp[i] = max(dp[i], dp[j] + 1);
			} 
			len = max(len, dp[i]);
		}
		return n - len;
	}
}
int n, a[M];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	printf("%d %d\n", subtask1::work(a+1, a+n+1), subtask2::work2(a+1, a+n+1));
}
