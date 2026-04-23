static random_device rd;
static mt19937 g(rd());

shuffle(a.begin() + 1, a.end(), g); // 随机打乱数组

uniform_real_distribution<double> dist01(0.0, 1.0); // [0,1)
uniform_real_distribution<double> dist11(-1.0, 1.0); // [-1,1)