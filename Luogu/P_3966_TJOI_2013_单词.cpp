#include <cstdio>
#include <queue>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int M = 1e6 + 5;
struct AC_automaton {
    int tot[M], tr[M][26], cnt, fail[M], sid[M], deg[M], n;
    AC_automaton() {cnt = n = 0;}
    int init() {
        ++cnt;
        memset(tr[cnt], 0, sizeof(tr[cnt]));
        fail[cnt] = sid[cnt] = deg[cnt] = tot[cnt] = 0;
        return cnt;
    }
    void insert(string &s, int id) {
        int cur = 0; ++n;
        for(int i = 0; i < s.size(); i++) {
            if(!tr[cur][s[i] - 'a']) tr[cur][s[i] - 'a'] = init();
            cur = tr[cur][s[i] - 'a'];
            ++tot[cur];
        }
        sid[cur] = id;
    }
    queue<int> q;
    void build() {
        memset(fail, 0, sizeof(fail));
        for(int i = 0; i < 26; i++) if(tr[0][i]) q.push(tr[0][i]);
        while(!q.empty()) {
            int x = q.front(); q.pop();
            for(int i = 0; i < 26; i++) {
                if(tr[x][i]) ++deg[fail[tr[x][i]] = tr[fail[x]][i]], q.push(tr[x][i]);
                else tr[x][i] = tr[fail[x]][i];
            }
        }
    }
    vector<int> search(string &s) {
        vector<int> ans(n+5);
        int cur = 0, res = 0;
        for(int i = 0; i < s.size(); i++) {
            cur = tr[cur][s[i] - 'a'];
        }
        for(int i = 0; i <= cnt; i++) if(!deg[i]) q.push(i);
        while(!q.empty()) {
            int x = q.front(); q.pop();
            ans[sid[x]] = tot[x]; tot[fail[x]] += tot[x];
            if(!--deg[fail[x]]) q.push(fail[x]);
        }
        return ans;
    }
    vector<int> calc() {
        vector<int> ans(n+5);
        for(int i = 0; i <= cnt; i++) {
            if(!deg[i]) q.push(i);
        }
        while(!q.empty()) {
            int x = q.front(); q.pop(); 
            ans[sid[x]] = tot[x]; tot[fail[x]] += tot[x];
            if(!--deg[fail[x]]) q.push(fail[x]);
        }
        return ans;
    }

} ac;
int id[M]; string b[M], a[M];
int main() {
    int n; cin >> n; string s;
    for(int i = 1; i <= n; i++) {
        cin >> a[i]; b[i] = a[i];
    }
    sort(b+1, b+n+1);
    int n1 = unique(b+1, b+n+1) - b - 1;
    for(int i = 1; i <= n; i++)
        id[i] = lower_bound(b+1, b+n1+1, a[i]) - b;
    for(int i = 1; i <= n; i++)
        ac.insert(a[i], id[i]);
    ac.build();
    vector<int> ans = ac.calc();
    for(int i = 1; i <= n; i++) printf("%d\n", ans[id[i]]);
}