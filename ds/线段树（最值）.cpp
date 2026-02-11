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
int tmax[N << 2], tmin[N << 2], lz[N << 2];

void pushup(int o)
{
    tmax[o] = max(tmax[o << 1], tmax[o << 1 | 1]);
    tmin[o] = min(tmin[o << 1], tmin[o << 1 | 1]);
}

void update(int s, int e, int o, int x)
{
    tmax[o] += x;
    tmin[o] += x;
    lz[o] += x;
}

void pushdown(int s, int e, int o)
{
    if (!lz[o])
        return;
    int mid = (s + e) >> 1, ls = o << 1, rs = o << 1 | 1;
    update(s, mid, ls, lz[o]);
    update(mid + 1, e, rs, lz[o]);
    lz[o] = 0;
}

void buildtree(int s = 1, int e = n, int o = 1)
{
    if (s == e)
    {
        tmax[o] = a[s];
        tmin[o] = a[s];
        return;
    }
    int mid = (s + e) >> 1;
    buildtree(s, mid, o << 1);
    buildtree(mid + 1, e, o << 1 | 1);
    pushup(o);
}

void add(int l, int r, int x, int s = 1, int e = n, int o = 1)
{
    if (l <= s && e <= r)
    {
        update(s, e, o, x);
        return;
    }
    pushdown(s, e, o);
    int mid = s + e >> 1;
    if (mid >= l)
        add(l, r, x, s, mid, o << 1);
    if (mid + 1 <= r)
        add(l, r, x, mid + 1, e, o << 1 | 1);
    pushup(o);
}

pii query(int l, int r, int s = 1, int e = n, int o = 1)
{
    if (l <= s && e <= r)
        return {tmax[o], tmin[o]};
    pushdown(s, e, o);
    int mid = (s + e) >> 1;
    pii res = {-inf, inf};
    if (mid >= l)
    {
        pii temp = query(l, r, s, mid, o << 1);
        res.fir = max(res.fir, temp.fir);
        res.sec = min(res.sec, temp.sec);
    }
    if (mid + 1 <= r)
    {
        pii temp = query(l, r, mid + 1, e, o << 1 | 1);
        res.fir = max(res.fir, temp.fir);
        res.sec = min(res.sec, temp.sec);
    }
    return res;
}

void Thirstarfish()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    buildtree();
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            add(l, r, x);
        }
        else if (op == 2)
        {
            int l, r;
            cin >> l >> r;
            pii ans = query(l, r);
            cout << ans.fir << ' ' << ans.sec << endl;
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
