#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define vec vector
#define fir first
#define sec second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mxe max_element
#define mne min_element
#define ppc __builtin_popcount
#define ctz __builtin_ctzll
#define clz __builtin_clzll // 二进制前导零的个数
#define pcs(n) cout << fixed << setprecision(n)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
typedef unsigned long long ull;
typedef __int128_t lll;
const int mod = 998244353;
const int N = 200005;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int bs = 433;
const int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

void Thirstarfish()
{
    int n;
    cin >> n;
    vec<int> a(n + 1), val;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        val.pb(a[i]);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());

    int m = val.size();
    vec<int> tree(m + 1);

    auto update = [&](int b, int v)
    {
        for (int i = b; i <= m; i = i + (i & -i))
            tree[i] += v;
    };

    auto query = [&](int b)
    {
        int ans = 0;
        for (int i = b; i; i = i - (i & -i))
            ans += tree[i];
        return ans;
    };

    auto idx = [&](int x)
    {
        return lower_bound(val.begin(), val.end(), x) - val.begin() + 1;
    };

    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        int temp = idx(a[i]);
        update(temp, 1);
        ans += query(temp - 1);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _; // 如果是单测记得注释掉这一行
    while (_--)
        Thirstarfish();
    return 0;
}

/*
 things to check
 1.  int overflow or long long memory need
 2.  recursion/array/binary search/dp/loop bounds
 3.  precision
 4.  special cases(n=1,bounds)
 5.  delete debug statements
 6.  initialize(especially multi-tests)
 7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
 8.  keep it simple and stupid
 9.  do not delete, use // instead
 10. operator priority
 11. is there anything extra to output?
 12. ...


something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not ?????? or few affect?

騒がしい日々に笑えない君に
思い付く限り眩しい明日を
  */
