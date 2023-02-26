#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int M = 2e5 + 5;
queue<int> q; 
struct edge {
  int to, nxt;
}e[M];
int head[M], cnt1, n, m, u, v, deg[M];
void link(int u, int v){
  e[++cnt1].to = v; e[cnt1].nxt = head[u];
  head[u] = cnt1; deg[v]++;
}
int num[M];
bool t[M];
void tuopu() {
  int cnt = 0;
  for(int i = 1; i <= n; i++) if(deg[i] == 0) q.push(i);
  if(q.size() > 1) return printf("No\n"), void();
  num[q.front()] = 1;
  while(!q.empty()){
    int u = q.front(); q.pop(); ++cnt;
    for(int i = head[u]; i; i = e[i].nxt){
      int v = e[i].to; deg[v]--; num[v] = max(num[v], num[u] + 1);
      if(deg[v] == 0) q.push(v);
    }
  }
  for (int i = 1; i <= n; i++) t[num[i]] = 1;
  bool f = 1;
  for (int i = 1; i <= n; i++) if(!t[i]) f = 0;
  if(!f) return printf("No\n"), void();
  else {
    printf("Yes\n");
    for(int i = 1; i <= n; i++) printf("%d ", num[i]);
  }
}
int main(){
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= m; i++){
    scanf("%d %d", &u, &v);
    link(u, v);
  }
  tuopu();
}