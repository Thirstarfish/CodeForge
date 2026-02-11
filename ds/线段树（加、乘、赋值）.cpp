#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define vec vector
#define fir first
#define sec second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
const int mod = 998244353;
const int N = 200005;
const int inf = 0x3f3f3f3f3f3f3f3f;
int n, q, a[N];
int t[N << 2], lzx[N << 2], lzy[N << 2];

void pushup(int o)
{
    t[o] = t[o << 1] + t[o << 1 | 1];
    t[o] %= mod;
}                                                                

void update(int s, int e, int o, int x, int y)
{
    t[o] = (t[o] * y % mod + (e - s + 1) * x) % mod;
    lzy[o] = lzy[o] * y % mod;
    lzx[o] = (lzx[o] * y % mod + x) % mod;
}

void pushdown(int s, int e, int o)
{
    if (!lzx[o] && !lzy[o])
        return;
    int mid = (s + e) >> 1, ls = o << 1, rs = o << 1 | 1;
    update(s, mid, ls, lzx[o], lzy[o]);
    update(mid + 1, e, rs, lzx[o], lzy[o]);
    lzx[o] = 0, lzy[o] = 1;
}

void buildtree(int s = 1, int e = n, int o = 1)
{
    if (s == e)
    {
        t[o] = a[s];
        return;
    }
    int mid = (s + e) >> 1;
    buildtree(s, mid, o << 1);
    buildtree(mid + 1, e, o << 1 | 1);
    pushup(o);
}

void add(int l, int r, int x, int y, int s = 1, int e = n, int o = 1)
{
    if (l <= s && e <= r)
    {
        update(s, e, o, x, y);
        return;
    }
    pushdown(s, e, o);
    int mid = (s + e >> 1);
    if (mid >= l)
        add(l, r, x, y, s, mid, o << 1);
    if (mid + 1 <= r)
        add(l, r, x, y, mid + 1, e, o << 1 | 1);
    pushup(o);
}

int query(int l, int r, int s = 1, int e = n, int o = 1)
{
    if (l <= s && e <= r)
        return t[o];
    pushdown(s, e, o);
    int mid = (s + e) >> 1;
    int res = 0;
    if (mid >= l)
    {
        res += query(l, r, s, mid, o << 1);
        res %= mod;
    }
    if (mid + 1 <= r)
    {
        res += query(l, r, mid + 1, e, o << 1 | 1);
        res %= mod;
    }
    return res;
}

void Thirstarfish()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n << 2; i++)
        lzy[i] = 1;
    buildtree();
    while (q--)
    {
        int op;
        cin >> op;
        if (op != 4)
        {
            int l, r, x;
            cin >> l >> r >> x;
            if (op == 1)
                add(l, r, x, 1);
            else if (op == 2)
                add(l, r, 0, x);
            else if (op == 3)
                add(l, r, x, 0);
        }
        else if (op == 4)
        {
            int l, r;
            cin >> l >> r;
            cout << query(l, r) << endl;
        }
    }
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

  Il y a seulement de la malchance à n'être pas aimé ; il y a du malheur à ne point aimer.
  */
