#include <cstdio>
#include <iostream>
using namespace std;
const int M = 500005;
int a[M], n;
struct node{
	int ld, lu, rd, ru, mm, l, r; // left/right up/down middle-max
    int getans() {return max(ld, max(lu, max(rd, max(ru, mm))));}
}s[M << 2];
node operator + (const node &ll, const node &rr) {
    if(rr.r - rr.l + 1 <= 0) return ll;
    if(ll.r - ll.l + 1 <= 0) return rr;
    node ans; int l1 = ll.l, mid = ll.r, r1 = rr.r; ans.l = l1; ans.r = r1;

    if(ll.ld == mid - l1 + 1 && a[mid] >= a[mid+1])
        ans.ld = ll.ld + rr.ld;
    else ans.ld = ll.ld;

    if(ll.lu == mid - l1 + 1 && a[mid] <= a[mid+1])
        ans.ru = ll.ru + rr.ru;
    else ans.lu = ll.lu;

    if(rr.rd == r1 - mid && a[mid+1] >= a[mid])
        ans.rd = rr.rd + ll.rd;
    else ans.rd = rr.rd;

    if(rr.ru == r1 - mid && a[mid+1] <= a[mid])
        ans.ru = rr.ru + ll.ru;
    else ans.ru = rr.ru;

    ans.mm = max(ll.mm, rr.mm);
    if(a[mid+1] <= a[mid])
        ans.mm = max(ans.mm, ll.ru + rr.lu);
    if(a[mid+1] >= a[mid])
        ans.mm = max(ans.mm, ll.rd + rr.ld);

    return ans;
}
void build(int o, int l, int r){
	if(l == r) {s[o] = {1, 1, 1, 1, 1, l, r}; return;}
    int mid = l + r >> 1;
    build(o<<1, l, mid); build(o<<1|1, mid+1, r);
    s[o] = s[o<<1] + s[o<<1|1];
}
node query(int o, int l, int r, int x, int y){
    if(x <= l && r <= y) return s[o];
    int mid = l + r >> 1; node ans = {0, 0, 0, 0, 0, 1, 0};
    if(x <= mid) ans = ans + query(o<<1, l, mid, x, y);
    if(y > mid) ans = ans + query(o<<1|1, mid+1, r, x, y);
    return ans;
}
int q, x, y;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    scanf("%d", &q);
    while(q--){
        scanf("%d %d", &x, &y);
        printf("%d\n", query(1, 1, n, x, y).getans());
    }
}