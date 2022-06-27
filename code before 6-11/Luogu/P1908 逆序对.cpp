#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define int long long
using namespace std;
const int M = 500005;
int n, a[M];
struct mergeget{
    int t[M];
    template <class T>
    int merge(T c[], T *as, T *an, T *bs, T *bn){
        int n = an - as, m = bn - bs, ans = 0;
        int i = 0, j = 0, k = 0;
        while(i < n && j < m){
            if(as[i] <= bs[j]) c[k++] = as[i++];
            else c[k++] = bs[j++], ans += n - i;
        }
        while(i < n) c[k++] = as[i++];
        while(j < m) c[k++] = bs[j++];
        return ans;
    }
    template <class T>
    int MergeSort(T *l, T *r)
    {
        int ans = 0;
        if (r - l == 1) return 0;
        T *mid = l + (r - l - 1) / 2;
        ans = MergeSort(l, mid + 1) + MergeSort(mid + 1, r) + merge(t, l, mid + 1, mid + 1, r);
        for(int i = 0; i < r - l; i++)
            l[i] = t[i];
        return ans;
    }
}s;
struct treeget{
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
	    for(int i = 0; i < n; i++) st[i] = l[i];
	    sort(st, st + n); int n1 = unique(st, st + n) - st + 1;
	    int ans = 0;
		for(int i = 0; i < n; i++){
		    int t = lower_bound(st, st + n1, l[i]) - st + 1;
			ans += query(t - 1);
			upd(t, 1);
		}
		return ans;
	}
}t;
signed main()
{
	srand(time(0)); scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    if(rand() % 2 == 0) printf("%lld\n", s.MergeSort(a + 1, a + n + 1));
    else printf("%lld\n", t.work(a + 1, a + n + 1));
    return 0;
}
