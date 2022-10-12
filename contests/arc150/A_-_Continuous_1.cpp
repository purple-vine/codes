#include <cstdio>
using namespace std;
const int M = 300005;
char c[M]; int n, k, cnt[M], cnt2[M];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %s", &n, &k, c+1);
        for(int i = 1; i <= n; i++){
            cnt[i] = cnt[i-1] + (c[i] != '0');
            cnt2[i] = cnt2[i-1] + (c[i] == '1');
            // printf("%d %d  ", cnt[i], cnt2[i]);
        }
        int num = cnt2[n], cnt1 = 0;
        for(int i = k; i <= n; i++){
            if(cnt[i] - cnt[i-k] == k && cnt2[i] - cnt2[i-k] == num)
                ++cnt1;
        }
        printf("%s\n", cnt1 == 1 ? "Yes" : "No");
    }
}