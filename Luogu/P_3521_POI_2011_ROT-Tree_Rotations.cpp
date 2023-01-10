#include <cstdio>
#include <set>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define LL long long
using namespace std;
using namespace __gnu_pbds;
const int M = 5e5 + 5;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s[M];
int cnt;
LL ans;
int build() {
    int x; scanf("%d", &x);
    int rt = ++cnt;
    if(x != 0) return s[rt].insert(x), rt;
    else {
        int l = build(), r = build();
        if(s[l].size() < s[r].size()) swap(l, r);
        LL tmp = 0, tot = 1ll * s[l].size() * s[r].size();
        for(auto u : s[r]) {
            if(s[l].lower_bound(u) == s[l].end()) tmp += s[l].size();
            else tmp += 1ll * s[l].order_of_key(*s[l].lower_bound(u));
        }
        for(auto u : s[r]) s[l].insert(u);
        ans += min(tmp, tot - tmp);
        return l;
    }
}
int main() {
    int n; scanf("%d", &n); build();
    printf("%lld\n", ans);
}