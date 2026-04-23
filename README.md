# 🔥 CodeForge


<div align="center">
 


 ![8411c4fc6c464d9b6182683d58252c91](https://github.com/user-attachments/assets/62e648d1-b64d-4f17-8ca6-fed4d7ff23b3)
 


 </div>

<div align="center">


**算法竞赛模板库 | Algorithm Template Library for CP**

[中文](README.md) | [English](README.en.md)
</div>

<p align="center">
  <img alt="License" src="https://img.shields.io/badge/license-MIT-blue.svg">
  <img alt="Language" src="https://img.shields.io/badge/language-C++-orange.svg">
  <img alt="Version" src="https://img.shields.io/badge/version-1.0.0-green.svg">
  <img alt="Build Status" src="https://img.shields.io/badge/build-passing-brightgreen.svg">
  <img alt="Downloads" src="https://img.shields.io/badge/downloads-1--50-blue.svg">
  <img alt="Issues" src="https://img.shields.io/badge/issues-0-red.svg">
</p>



## 文件组织


```
CodeForge/
├─ graph/           # 图论
├─ data-struct/     # 数据结构
├─ math/            # 数论 & 多项式
├─ string/          # 字符串
├─ dp/              # 动态规划
└─ misc/            # 杂项（快读、对拍、调试宏）
```


每个 `.cpp` 都是独立模板，直接复制即可塞进任意工程。

## 一键编译


```bash
g++ -std=c++23 -O2 -Wall -Wextra -o main filename.cpp && ./a.out
```


**提示**  
- 可能需要header file(在misc目录下)
- 可能需要 C++23 及以上  
- 模板里如果用到 `__int128`，请确保评测机支持，否则自行改 `long long`

## 更新节奏
- 每场比赛后如果写了新板子就丢进来  
- 顺手修 typo，保证「复制即可过样例」

## 贡献方式
Issues & PR 都欢迎：  
1. Fork → 2. 新分支 → 3. 测样例 → 4. PR  
**注意**：请保持单文件独立、无外部依赖。

## 许可证
所有模板均以 [MIT](LICENSE) 协议发布，**复制无需署名**，改完商用也行。
