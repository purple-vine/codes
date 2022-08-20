#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 500005;
struct opt{
    char op; int l, r, k, id;
} q[M], ql[M], qr[M];
int n, m, ans[M], a[M], b[M << 1], bl, cnt1; 
struct segtr{
    int s[M << 2];
    void modify(int o, int l, int r, int x, int t){
        if(x == l && l == r) {s[o] += t; return;}
        int mid = l + r >> 1;
        if(x <= mid) modify(o<<1, l, mid, x, t);
        else modify(o<<1|1, mid+1, r, x, t);
        s[o] = s[o<<1] + s[o<<1|1];
    }
    int query(int o, int l, int r, int x, int y){
        if(x <= l && r <= y) return s[o];
        int ans = 0, mid = l + r >> 1;
        if(x <= mid) ans += query(o<<1, l, mid, x, y);
        if(y > mid) ans += query(o<<1|1, mid+1, r, x, y);
        return ans;
    }
} t;
void solve(int l, int r, int sl, int sr){
    if(sl > sr || l > r) return;
    // printf("solve %d %d %d %d\n", l, r, sl, sr);
    if(sl == sr){
        for(int i = l; i <= r; i++) if(q[i].op == 'Q') ans[q[i].id] = sl; return;
    }
    int mid = sl + sr >> 1, cntl = 0, cntr = 0;
    for(int i = l; i <= r; i++){
        // printf("op %c %d %d %d %d\n", q[i].op, q[i].l, q[i].r, q[i].k, q[i].id);
        if(q[i].op == 'C'){
            if(q[i].k <= mid) t.modify(1, 1, n, q[i].l, q[i].r), ql[++cntl] = q[i];
            else qr[++cntr] = q[i];
        } else {
            int cnt = t.query(1, 1, n, q[i].l, q[i].r);
            if(cnt >= q[i].k) ql[++cntl] = q[i];
            else qr[++cntr] = q[i], qr[cntr].k -= cnt;
        }
    }
    for(int i = l; i <= r; i++)
        if(q[i].op == 'C' && q[i].k <= mid) t.modify(1, 1, n, q[i].l, -q[i].r);
    // printf("l: "); for(int i = 1; i <= cntl; i++) printf("%d ", ql[i].id); printf("\n");
    // printf("r: "); for(int i = 1; i <= cntr; i++) printf("%d ", qr[i].id); printf("\n");
    for(int i = 1; i <= cntl; i++) q[l + i - 1] = ql[i];
    for(int i = 1; i <= cntr; i++) q[l + i + cntl - 1] = qr[i];
    solve(l, l + cntl - 1, sl, mid); solve(l + cntl, r, mid + 1, sr);
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]), b[++bl] = a[i];
        ++cnt1; q[cnt1] = {'C', i, 1, a[i], cnt1};
    }
    for(int i = 1; i <= m; i++){
        char op; scanf(" %c", &op);
        if(op == 'Q'){
            int l, r, k; scanf("%d %d %d", &l, &r, &k); q[++cnt1] = {op, l, r, k, cnt1};
            b[++bl] = k;
        } else {
            int p, k; scanf("%d %d", &p, &k);
            ++cnt1; q[cnt1] = {op, p, -1, a[p], cnt1}; 
            ++cnt1; q[cnt1] = {op, p, 1, k, cnt1}; 
            b[++bl] = k; a[p] = k;
        }
    }
    // sort(b+1, b+bl+1); bl = unique(b+1, b+bl+1) - b - 1;
    // for(int i = 1; i <= n; i++) a[i] = lower_bound(b+1, b+bl+1, a[i]) - b;
    // for(int i = 1; i <= cnt1; i++) q[i].k = lower_bound(b+1, b+bl+1, q[i].k) - b;
    solve(1, cnt1, 0, 1e9);
    for(int i = 1; i <= cnt1; i++){
        if(ans[i]) printf("%d\n", ans[i]);
    }
}