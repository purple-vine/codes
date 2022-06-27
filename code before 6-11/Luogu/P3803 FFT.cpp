#include <cstdio>
#include <cmath>
using namespace std;
const int M = 6000005;
namespace zag{
	template <typename T> void swap(T &a, T &b){
		T c = a; a = b; b = c; 
	}
}
namespace math{
	const double Pi = acos(-1);
	struct cp{ //complex
		double x, y;
		cp(double a, double b) : x(a), y(b) {}
		cp() {}
		cp operator + (const cp &t) const
			{return cp(x+t.x, y+t.y);}
		cp operator - (const cp &t) const
			{return cp(x-t.x, y-t.y);}
		cp operator * (const cp &t) const
			{return cp(x*t.x-y*t.y, x*t.y+y*t.x);}
		cp operator / (const cp &t) const {
			double l = t.x*t.x+t.y*t.y;
			return cp((x*t.x+y*t.y)/l, (y*t.x-x*t.y)/l);
		}
	};
	int tr[M];
	using zag::swap;
	void fft(cp *f, int n, bool flag){
		for(int i = 0; i < n; i++) if(i < tr[i])
			swap(f[i], f[tr[i]]);
		for(int l = 2; l <= n; l <<= 1){
			cp tg(cos(2*Pi/l), sin(2*Pi/l));
			if(!flag) tg.y *= -1;
			for(int s = 0; s < n; s += l){
				cp buf(1, 0);
				for(int k = s; k < s + l/2; k++){
					cp tt = buf * f[k+l/2];
					f[k+l/2] = f[k] - tt; f[k] = f[k] + tt;
					buf = buf * tg;
				}
			}
		}
	}
	void fft_main(cp *f, cp *g, int &n, int &m){
		for(m += n, n = 1; n <= m; n <<= 1) ;
		for(int i = 0; i < n; i++)
			tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
		fft(f, n, 1); fft(g, n, 1);
		for(int i = 0; i < n; i++) f[i] = f[i] * g[i];
		fft(f, n, 0);
		for(int i = 0; i <= m; i++) printf("%d ", (int)(f[i].x / n + 0.49));
	}
}
math::cp f[M], g[M]; int n, m;
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i <= n; i++) scanf("%lf", &f[i].x);
	for(int i = 0; i <= m; i++) scanf("%lf", &g[i].x);
	math::fft_main(f, g, n, m);
}
