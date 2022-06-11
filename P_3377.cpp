//test
#include<iostream>
#include<cstdio>
#define l(x) zps[x].l
#define r(x) zps[x].r
#define d(x) zps[x].d
#define fa(x) zps[x].fa
using namespace std;
int n,m;
struct node
{
    int val,l,r,d,fa; bool del;
}zps[100001];
int find(int x)
{
    if(zps[x].fa==x) return x;
    return zps[x].fa=find(zps[x].fa);
}
int merge(int x,int y)
{
    if(!x||!y) return x|y;
    if(zps[x].val>zps[y].val) swap(x, y);
    zps[x].r=merge(zps[x].r,y);
    if(zps[zps[x].r].d>zps[zps[x].l].d) swap(zps[x].l,zps[x].r);
    zps[x].d=zps[zps[x].r].d+1;
    return x;
}
signed main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&zps[i].val),zps[i].fa=i;
    for(int i=1;i<=m;i++)
    {
        int opt,x,y;
        scanf("%d%d",&opt,&x);
        if(opt==1)
        {
            scanf("%d",&y);
            if(zps[x].del||zps[y].del)
            {
                continue;
            }
            x = find(x); y = find(y);
            if(x == y) continue;
            fa(x) = fa(y) = merge(x,y);
        }else
        {
            if(zps[x].del)
            {
                printf("-1\n");
                continue;
            }
            int nw = find(x);
            printf("%d\n",zps[nw].val);
            zps[nw].del = 1;
            fa(l(nw)) = fa(r(nw)) = zps[nw].fa = merge(zps[nw].l,zps[nw].r);
            zps[nw].r = zps[nw].l = 0;
            zps[nw].d = 0;
        }
    }
    return 0;
}