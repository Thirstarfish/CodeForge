    freopen("P6577_5.in", "r", stdin); // 从 data.in 读取输入
    freopen("out.out", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "执行时间: " << duration.count()/1000 << "ms" << endl;