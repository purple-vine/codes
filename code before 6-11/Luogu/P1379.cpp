#include <cstdio>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

struct matrix{
	int a[3][3];
	bool operator < (const matrix &t) const{
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				if(a[i][j] != t.a[i][j]) return a[i][j] < t.a[i][j];
		return 0;
	}
} k;
int e[3][3] = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};
int h(matrix t){
	int ans = 0;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			if(t.a[i][j] && t.a[i][j] != e[i][j]) ans++;
	return ans;
}
struct dat{
	matrix a; int t;
	bool operator < (dat temp) const {return t + h(a) > temp.t + h(temp.a);}
};

int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
priority_queue<dat> q; set<matrix> s;
int bfs(){
	q.push({k, 0});
	while(!q.empty()){
		dat t = q.top(); q.pop();
		if(s.find(t.a) != s.end()) continue; s.insert(t.a);
		matrix a = t.a; int tt = t.t, x = 0, y = 0;
		bool f = 1;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(a.a[i][j] == 0) x = i, y = j;
				if(a.a[i][j] != e[i][j]) f = 0;
			}
		}
		if(f) return t.t;
		for(int i = 0; i < 4; i++){
			int xx = x + dx[i], yy = y + dy[i];
			if(xx < 0 || xx > 2 || yy < 0 || yy > 2) continue;
			std::swap(a.a[x][y], a.a[xx][yy]);
			q.push({a, tt + 1});
			std::swap(a.a[x][y], a.a[xx][yy]);
		}
	}
}

int main(){
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			scanf("%1d", &k.a[i][j]);
	printf("%d\n", bfs());
}
