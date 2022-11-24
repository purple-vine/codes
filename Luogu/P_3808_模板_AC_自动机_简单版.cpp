#include <cstdio>
#include <queue>
using namespace std;
const int M = 1e6 + 5;
int tot[M], tr[M][26], cnt, fail[M], sid[M], deg[M];
void insert(char *s, int id) {
    int cur = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if(!tr[cur][s[i] - 'a']) tr[cur][s[i] - 'a'] = ++cnt;
        cur = tr[cur][s[i] - 'a'];
    }
    ++tot[cur]; sid[cur] = id;
}
queue<int> q;
void build() {
    for(int i = 0; i < 26; i++) if(tr[0][i]) q.push(tr[0][i]);
    while(!q.empty()) {
        int x = q.front(); q.pop(); 
        for(int i = 0; i < 26; i++) {
            if(tr[x][i]) fail[tr[x][i]] = tr[fail[x]][i], q.push(tr[x][i]);
            else tr[x][i] = tr[fail[x]][i];
        }
    }
}
int sum[M];
int query(char *s) {
    int cur = 0, res = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        cur = tr[cur][s[i] - 'a'];
        ++sum[cur];
    }
    return res;
}
int ans[M];
void calcans() {
    
}
char s[M];
int main() {
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%s", s); insert(s, i);
    }
    build();
    scanf("%s", s); printf("%d\n", query(s));
}