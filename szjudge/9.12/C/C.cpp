#include <cstdio>
#include <vector>
#include <map>
using namespace std;
const int M = 100005;
struct tp{
    int sufmax, prfmax, val, mx;
};
vector<tp> s[M];