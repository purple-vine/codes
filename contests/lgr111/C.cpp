//time : 2022-06-19
//problem url : https://www.luogu.com.cn/problem/T192369?contestId=50000
//status : not submitted
#include <cstdio>
#include <vector>
#include <map>
#define mp make_pair
using namespace std;
const int M = 1005;
vector<pair<int, int> > sl[100000005], sr[100000005];
map<int, int> s;
int n, k, p, a[M*M], T, phik, suml[M], sumr[M];
int qpow(int a, int b, int p){
	long long ans = 1ll;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % p; a = 1ll * a * a % p;}
	return ans;
}
int phi(int n){
	int ans = n;
	for(int i = 2; i * i <= n; i++) if(n % i == 0) {
		ans = ans / i * (i-1); while(n % i == 0) n /= i;
	}
	if(n > 1) ans = ans / n * (n-1);
	return ans; 
}
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &k, &p); k--; phik = phi(k); int l = k * phik;
        printf("l=%d\n", l);
        if(k == 1) {printf("1 %d\n", p); continue;}
        bool f = 1; a[0] = suml[0] = 1; sl[1].push_back(mp(0, 0));
        for(int i = 1; i < l; i++){
            a[i] = qpow(i, i, k);  suml[i] = suml[i-1] + a[i];
            if(s[suml[i]] != 0 && a[s[suml[i]]] + p == a[i]) {printf("%d %d\n", s[suml[i]], i); f = 0; break;}
        }
        printf("\n");
        if(!f) continue; int tot = suml[l-1];
        for(int i = l-1; i >= 0; i--){
            sumr[i] = sumr[i+1] + a[i]; sr[sumr[i]%tot].push_back(mp(sumr[i]/tot, i));
            sl[suml[i]%tot].push_back(mp(suml[i]/tot, i));
        }
        int val = p % suml[l-1], c = p / suml[l-1];
        for(int i = 0; i <= val; i++){
            for(auto u : sl[i]){
                for(auto v : sr[val-i]){
                    if(u.first + v.first <= c){
                        printf("%d %d\n", u.second, v.second + l + l*(c-u.first-v.first));
                        f = 0; break;
                    }
                }
            }
        }
        if(f) printf("-1 -1\n");
    }
}