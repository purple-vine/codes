#include <bits/stdc++.h>
#include <random>
#define int long long
using namespace std;

int read() {
	int s = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
		f = (ch == '-' ? -1 : 1), ch = getchar();
	while (ch >= '0' && ch <= '9')
		s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
	return s * f;
}

default_random_engine rnd(time(0));
namespace Rand {
	int tr() { return rnd();}
	int gr(int k) { return tr() % (k + 1);}
	int gr(int l, int r) { return l + gr(r - l);}
}

using namespace Rand;

#define Pair pair<int, int>
#define mkp make_pair

int n;
int c[100005][2];
Pair p[100005][2];

signed main() {
	freopen("16.in", "w", stdout);
	srand(time(NULL));
	int n = gr(50000, 100000);
	printf("%lld\n", n);
	for (int i = 1; i < n; i++)
		c[i][0] = i, c[i][1] = i + 1;
	for (int i = 1; i <= n; i++)
		p[i][0] = mkp(i - 1, 1), p[i][1] = mkp(i, 0);
	int tim = gr(1000, 2000);
	while (tim--) {
		int mov = gr(1000, 2000), sp = gr(1, n);
		Pair yl1 = p[sp][0], yl2 = p[sp][1];
		while (mov--) {
			int k = gr(0, 1) ? 1 : -1, l1, l2, no1, no2;
			if (sp + k > n || sp + k < 1)
				k = -k;
			int pos = sp + k;
			l1 = p[pos][0].first, no1 = p[pos][0].second, l2 = p[pos][1].first, no2 = p[pos][1].second;
			c[l1][no1] = sp, c[l2][no2] = sp;
			p[sp][0] = mkp(l1, no1), p[sp][1] = mkp(l2, no2);
			sp = pos;
		}
		p[sp][0] = yl1, p[sp][1] = yl2;
		c[yl1.first][yl1.second] = sp, c[yl2.first][yl2.second] = sp;
	}
	for (int i = 1; i < n; i++){
		if(rnd() % 2 == 0)
			printf("%lld %lld\n", c[i][0], c[i][1]);
		else
			printf("%lld %lld\n", c[i][1], c[i][0]);
	}
	return 0;
}
