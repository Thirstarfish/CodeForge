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
int tree1[N], treei[N];
int n, q, a;
void update(int b, int val)
{
    for (int i = b; i <= n; i = i + (i & -i))
    {
        tree1[i] += val;
        treei[i] += b * val;
    }
}

int query(int b)
{
    int ans = 0;
    for (int i = b; i; i = i - (i & -i))
        ans += (b + 1) * tree1[i] - treei[i];
    return ans;
}

void Thirstarfish()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        update(i, a);
        update(i+1,-a);
    }
    int op;
    for (int i = 1; i <= q; i++)
    {
        cin >> op;
        if (op == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            update(l, v);
            update(r + 1, -v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(r) - query(l - 1) << endl;
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
