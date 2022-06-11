#include <iostream>
#include <cstring>
using namespace std;

long long t, n, ans, a[200005], two[200005], cnt[35];

int main()
{
    cin >> t;
    for( long long zxrakioi = 1; zxrakioi <= t; zxrakioi++ )
    {
        ans = 0;
        memset( two, 0, sizeof( two ) );
        memset( cnt, 0, sizeof( cnt ) );
        cin >> n;
        for( long long i = 1; i <= n; i++ )
        {
            cin >> a[i];
            for( long long j = 30; j >= 1; j-- )
            {
                if( a[i] % ( 1 << j ) == 0 )
                {
                    two[i] = j;
                    break;
                }
            }
            cnt[two[i]]++;
        }
        for( long long i = 30; i >= 1; i-- )
        {
            while( cnt[i] > 0 )
            {
                for( long long j = 0; j <= 30; j++ )
                {
                    if( cnt[j] > 0 )
                    {
                        if( i == j && cnt[i] == 1 )
                        {
                            cnt[j]--;
                            ans += j;
                            break;
                        }
                        else
                        {
                            cnt[i]--;
                            cnt[j]--;
                            cnt[0]++;
                            ans += j + 1;
                            break;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}