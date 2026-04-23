const int down = 0.997;

auto start = clock();

static random_device rd;
static mt19937 g(rd());
uniform_real_distribution<double> dist01(0.0, 1.0);  // [0,1)
uniform_real_distribution<double> dist11(-1.0, 1.0); // [-1,1)

auto TIME = [&]() -> double
{ return (double)(clock() - start) / CLOCKS_PER_SEC; };

auto cal = [&](double x, double y) -> double
{
    // 代价函数
};

x /= n, y /= n, w = cal(x, y);
double bx = x, by = y, bw = w;

auto anneal = [&]() -> void
{
    double t = 3000;
    while (t > 1e-9)
    {
        double ex = x + dist11(g) * t * 1e4;
        double ey = y + dist11(g) * t * 1e4;
        double ew = cal(ex, ey);
        double de = ew - w; // 注意代价越大越好还是越小越好

        if (de < 0)
        {
            x = ex;
            y = ey;
            w = ew;
        }
        else if (exp(-de / t) > dist01(g))
        {
            x = ex;
            y = ey;
            w = ew;
        }
        if (w < bw)
        {
            bw = w;
            bx = x;
            by = y;
        }
        t *= down;
    }
};
