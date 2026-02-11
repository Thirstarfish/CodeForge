#include <bits/stdc++.h>
using namespace std;

// 函数：计算字符串的最长回文子串长度（Manacher算法）
int manacher(const string& str) {
    // 如果输入字符串为空，直接返回0
    if (str.empty()) return 0;
    
    // 构建预处理字符串，插入特殊字符避免奇偶长度问题
    string s = "$#";
    for (char c : str) {
        s += c;
        s += '#';
    }
    s += '&';
    
    int n = s.length();
    vector<int> p(n, 0);  // p[i]表示以i为中心的最长回文半径
    
    int center = 0;  // 当前回文串的中心
    int right = 0;   // 当前回文串的右边界
    int maxLen = 0;  // 最长回文半径
    
    for (int i = 1; i < n - 1; i++) {
        // 利用对称性初始化p[i]
        if (i < right) {
            p[i] = min(p[2 * center - i], right - i);
        } else {
            p[i] = 1;
        }
        
        // 中心扩展
        while (s[i + p[i]] == s[i - p[i]]) {
            p[i]++;
        }
        
        // 更新当前最右回文边界
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
        
        // 更新最大回文半径
        maxLen = max(maxLen, p[i]);
    }
    
    // 原始字符串中的最长回文子串长度 = 处理字符串中的最大半径 - 1
    return maxLen - 1;
}

int main() {
    string a;
    cin >> a;
    cout << manacher(a) << endl;
    return 0;
}