#include <cstdio>
#include <iostream>
#include <cstring>
#define inf (1000000000)
using namespace std;
const int M = 100005, N = 55;
int n, k, m, a[M]; long long stu; // 目标状态
struct node{
    //cnt: 有几个本质不同的前缀  mm: 中间的最值
    int l, r, llen[N], mm, lcnt, rcnt, rlen[N]; long long lstu[N], rstu[N]; 
    int getans(){
        if(lcnt < k) return -1;
        return min(mm, min(llen[k], rlen[k]));
    }
    void print(){
    	printf("in debug of l=%d r=%d\n", l, r);
    	printf("suffix: ");
    	for(int i = 1; i <= lcnt; i++) printf("%d-%lld ", llen[i], lstu[i]);
        printf("\n");
        printf("prefix: ");
        for(int i = 1; i <= rcnt; i++) printf("%d-%lld ", rlen[i], rstu[i]);
        printf("\n");
        printf("mm = %d\n", mm);
	}
    node(int pl, int val){
        l = r = pl; lcnt = rcnt = 1; mm = inf;
        llen[1] = rlen[1] = 1; lstu[1] = rstu[1] = (1ll << val);
    }
    node() {
        memset(llen, 0, sizeof(llen)); memset(rlen, 0, sizeof(rlen));
        memset(lstu, 0, sizeof(lstu)); memset(rstu, 0, sizeof(rstu));
    }
} s[M << 2];
node merge(const node &l, const node &r){
    int l1 = l.l, r1 = r.r, mid = l.r;
    if(r.r - r.l + 1 <= 0) return l;
    if(l.r - l.l + 1 <= 0) return r;
    node ans; ans.l = l1, ans.r = r1; ans.lcnt = l.lcnt; ans.rcnt = r.rcnt; ans.mm = inf;
    for(int i = 1; i <= l.lcnt; i++) ans.llen[i] = l.llen[i], ans.lstu[i] = l.lstu[i];
    for(int i = 1; i <= r.rcnt; i++) ans.rlen[i] = r.rlen[i], ans.rstu[i] = r.rstu[i];
    if(ans.lcnt < k)
        for(int i = 1; i <= r.lcnt && ans.lcnt < k; i++)
            if(ans.lstu[ans.lcnt] != (ans.lstu[l.lcnt] | r.lstu[i])){
                ++ans.lcnt;
                ans.lstu[ans.lcnt] = ans.lstu[l.lcnt] | r.lstu[i];
                ans.llen[ans.lcnt] = mid - l1 + 1 + r.llen[i];
            }
    if(ans.rcnt < k)
        for(int i = 1; i <= l.rcnt && ans.rcnt < k; i++)
            if(ans.rstu[ans.rcnt] != (ans.rstu[r.rcnt] | l.rstu[i])){
                ++ans.rcnt;
                ans.rstu[ans.rcnt] = ans.rstu[r.rcnt] | l.rstu[i];
                ans.rlen[ans.rcnt] = r1 - mid + l.rlen[i];
            }
    ans.mm = min(l.mm, r.mm);
    // printf("l = %d r = %d  l=%lld r=%lld mm=%lld\n", l1, r1, l.rstu[l.lcnt], r.rstu[r.rcnt], ans.mm);
    // if((l.rstu[l.lcnt] | r.lstu[r.rcnt]) != stu) return ans;
    for(int i = 0, j = r.rcnt; j; --j){
        while(i <= l.lcnt && stu != (l.rstu[i] | r.lstu[j])) ++i;
        if(i <= l.lcnt) ans.mm = min(ans.mm, l.rlen[i] + r.llen[j]);
        if((l.rlen[l.lcnt+1] | r.lstu[j]) == stu) exit(-1);
    } 
    return ans;
}
void build(int o, int l, int r){
    if(l == r) {s[o] = node(l, a[l]); return;}
    int mid = l + r >> 1;
    build(o<<1, l, mid); build(o<<1|1, mid+1, r);
    s[o] = merge(s[o<<1], s[o<<1|1]);
}
void modify(int o, int l, int r, int x, int v){
    if(l == r && l == x) {s[o] = node(l, v); return;}
    int mid = l + r >> 1; 
    x <= mid ? modify(o<<1, l, mid, x, v) : modify(o<<1|1, mid+1, r, x, v);
    s[o] = merge(s[o<<1], s[o<<1|1]);
}
node query(int o, int l, int r, int x, int y){
    if(x <= l && r <= y) return s[o];
    int mid = l + r >> 1; node ans; ans.r = 0, ans.l = 1;
    if(x <= mid) ans = merge(ans, s[o<<1]);
    if(y > mid) ans = merge(ans, s[o<<1|1]);
    return ans; 
}
int main(){
    scanf("%d %d %d", &n, &k, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), --a[i];
    stu = (1ll << k) - 1;
    build(1, 1, n);
    while(m--){
        int op, p, v;
        scanf("%d", &op);
        if(op == 1){
            scanf("%d %d", &p, &v);
            modify(1, 1, n, p, --v);
        } else {
            printf("%d\n", s[1].getans());
        }
        // s[1].print(); s[2].print(); s[3].print(); s[4].print(); s[5].print();
    }
}