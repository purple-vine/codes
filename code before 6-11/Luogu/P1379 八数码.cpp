#include <cstdio>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
const int M = 3;
int t[M][M] = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};
int dx[4] = {0, 1, -1, 0}, dy[4] = {-1, 0, 0, 1};
struct dat{
	int a[3][3], px, py, t;
	bool operator < (const dat &t) const{
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				if(a[i][j] != t.a[i][j]) return a[i][j] < t.a[i][j];
		return 0;
	}
//	int p(){
//		int ans = 0;
//		for(int i = 0; i < 3; i++)
//			for(int j = 0; j < 3; j++)
//				ans += 
//	}
}s;
bool check(dat a){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(a.a[i][j] != t[i][j]) return 0;
		}
	} return 1;
}
queue<dat> q; map<dat, bool> k;
int bfs(){
	q.push(s);
	while(!q.empty()){
		dat a = q.front(); q.pop();
		if(k[a] == 1) continue; k[a] = 1;
		if(check(a)) return a.t;
		for(int i = 0; i < 4; i++){
			dat t = a;
			int xx = a.px + dx[i], yy = a.py + dy[i];
			if(xx < 0 || xx >= 3 || yy < 0 || yy >= 3) continue;
			swap(t.a[t.px][t.py], t.a[xx][yy]); t.t++;
			t.px = xx; t.py = yy;
			q.push(t);
		}
	}
}
int main(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			scanf("%1d", &s.a[i][j]);
			if(s.a[i][j] == 0) s.px = i, s.py = j;
		}
	}
	printf("%d\n", bfs());
}
