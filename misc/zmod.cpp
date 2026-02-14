using i64 = long long;

template <class T>
constexpr T fpow(T n, i64 k)
{
    T r = 1;
    for (; k; k >>= 1, n *= n)
        if (k & 1)
            r *= n;
    return r;
}

template <int MOD>
struct Zmod
{
    int x;

    constexpr Zmod(int x = 0) : x(norm(x % MOD)) {}

    static constexpr int norm(int x)
    {
        if (x < 0) x += MOD;
        if (x >= MOD) x -= MOD;
        return x;
    }

    constexpr int val() const { return x; }

    constexpr Zmod operator-() const
    {
        return Zmod(MOD - x);
    }

    constexpr Zmod inv() const
    {
        assert(x != 0);
        return fpow(*this, MOD - 2);
    }

    /* IO */
    friend std::istream &operator>>(std::istream &in, Zmod &a)
    {
        int v;
        in >> v;
        a = Zmod(v);
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const Zmod &a)
    {
        return out << a.val();
    }

    /* 自增自减 */
    constexpr Zmod &operator++() { return x = norm(x + 1), *this; }
    constexpr Zmod &operator--() { return x = norm(x - 1), *this; }

    /* 复合赋值 */
    constexpr Zmod &operator+=(const Zmod &o)
    {
        x = norm(x + o.x);
        return *this;
    }

    constexpr Zmod &operator-=(const Zmod &o)
    {
        x = norm(x - o.x);
        return *this;
    }

    constexpr Zmod &operator*=(const Zmod &o)
    {
        x = (i64)x * o.x % MOD;
        return *this;
    }

    constexpr Zmod &operator/=(const Zmod &o)
    {
        return *this *= o.inv();
    }

    /* 二元运算 */
    friend constexpr Zmod operator+(Zmod a, const Zmod &b) { return a += b; }
    friend constexpr Zmod operator-(Zmod a, const Zmod &b) { return a -= b; }
    friend constexpr Zmod operator*(Zmod a, const Zmod &b) { return a *= b; }
    friend constexpr Zmod operator/(Zmod a, const Zmod &b) { return a /= b; }

    /* 比较 */
    friend constexpr bool operator==(const Zmod &a, const Zmod &b) { return a.x == b.x; }
    friend constexpr bool operator!=(const Zmod &a, const Zmod &b) { return a.x != b.x; }
    friend constexpr bool operator<(const Zmod &a, const Zmod &b) { return a.x < b.x; }
    friend constexpr bool operator>(const Zmod &a, const Zmod &b) { return a.x > b.x; }
};

constexpr int MOD[] = {998244353, 1000000007};
using Z = Zmod<MOD[0]>;

/* 示例：2^n */
Z power(int n)
{
    return fpow(Z(2), n);
}
