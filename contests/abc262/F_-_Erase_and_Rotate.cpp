#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int M = 200005;
int n, a[M], k, cost[M], b[M], pl;
struct node{
    int mnd, mnp;
    bool operator < (const node &t) const{
        return mnd < t.mnd;
    }
};
node min(node x, node y) {return x < y ? x : y;}
struct sg2{
    node s[M << 2];
    void clear(){
        memset(s, 0, sizeof(s));
    }
    void build(int o, int l, int r){
        if(l == r) {s[o] = {a[l], l}; return;}
        int mid = l + r >> 1;
        build(o<<1, l, mid); build(o<<1|1, mid+1, r);
        s[o] = min(s[o<<1], s[o<<1|1]);
    }
	node query(int o, int l, int r, int x, int y){
		if(x <= l && r <= y) return s[o];
		int mid = l + r >> 1; node ans = {(int)1e9, (int)1e9};
		if(x <= mid) ans = min(ans, query(o<<1, l, mid, x, y));
		if(y > mid) ans = min(ans, query(o<<1|1, mid+1, r, x, y));
		return ans;
	}
}t;
void print(vector<int> t){
    for(auto i : t) printf("%d ", i);
    puts("");
}
vector<int> solve(){
    vector<int> ans; t.clear(); t.build(1, 1, n);
    int l = 1, c = k;
    while(l <= n){
        int tmpp = t.query(1, 1, n, l, max(l+c, n-pl+2+c)).mnp;
        // printf("tmpp = %d c = %d l = %d\n", tmpp, c, l);
        for(int i = l; i < tmpp; i++) c -= cost[i];
        ans.push_back(a[tmpp]); l = tmpp + 1;
    }
    for(int i = l; i <= n; i++) ans.push_back(a[i]);
    for(int i = 1; i <= c; i++) ans.pop_back();
    return ans;
}
int main(){
    scanf("%d %d", &n, &k); pl = 100000000;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]); cost[i] = 1;
    }
    vector<int> ans1 = solve();
    // print(ans1);
    if(k == 0) {print(ans1); return 0;}
    pl = t.query(1, 1, n, n-k+1, n).mnp;
    for(int i = 1; i <= n-pl+1; i++) b[i] = a[i+pl-1], cost[i] = 0;
    for(int i = 1; i < pl; i++) b[i+n-pl+1] = a[i];
    for(int i = 1; i <= n; i++) a[i] = b[i];
    k -= n-pl+1;
    // lim = n-pl+1;
    vector<int> ans2 = solve();
    // print(ans2);
    vector<int> ans = min(ans1, ans2);
    print(ans); return 0;
}