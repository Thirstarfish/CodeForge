auto calc = [&](double x) -> double 
{

};

auto ternary = [&](double l, double r) -> double
{
    const double PHI = (sqrt(5.0) - 1.0) / 2.0;
    double m1 = r - PHI * (r - l);
    double m2 = l + PHI * (r - l);
    double f1 = calc(m1);
    double f2 = calc(m2);

    while (r - l > eps)
        if (f1 < f2)
        {
            l = m1;
            m1 = m2;
            f1 = f2;
            m2 = l + PHI * (r - l);
            f2 = calc(m2);
        }
        else
        {
            r = m2;
            m2 = m1;
            f2 = f1;
            m1 = r - PHI * (r - l);
            f1 = calc(m1);
        }
    return (l + r) / 2.0;
};