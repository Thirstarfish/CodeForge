# 🔥 CodeForge
<div align="center">

![8411c4fc6c464d9b6182683d58252c91](https://github.com/user-attachments/assets/11ecb8ad-7c8a-42a9-8251-3baea2df781f)

**算法竞赛模板库 | Algorithm Template Library for CP**

[中文](README.md) | [English](README.en.md)

<p align="center">
  <img alt="License" src="https://img.shields.io/badge/license-MIT-blue.svg">
  <img alt="Language" src="https://img.shields.io/badge/language-C++-orange.svg">
  <img alt="Version" src="https://img.shields.io/badge/version-1.0.0-green.svg">
  <img alt="Build Status" src="https://img.shields.io/badge/build-passing-brightgreen.svg">
  <img alt="Downloads" src="https://img.shields.io/badge/downloads-1--50-blue.svg">
  <img alt="Issues" src="https://img.shields.io/badge/issues-0-red.svg">
</p>

</div>


## Folder Layout
```
CodeForge/
├─ graph/           # graph algorithms
├─ data-struct/     # data structures
├─ math/            # number theory & poly
├─ string/          # string algorithms
├─ dp/              # dynamic programming
└─ misc/            # utilities (fast IO, stress, debug macros)
```
Every `.cpp` is self-contained—just drop it into your project.

## Build in One Line
```bash
g++ -std=c++23 -O2 -Wall -Wextra -o main filename.cpp && ./a.out
```
**Notes**  
- The header file might be required (in the misc directory)
- C++23 or higher might be required  
- Templates using `__int128` need judge support; fallback to `long long` if not available

## Update Cadence
- New templates land after each contest  
- Typos are fixed on the fly so "copy → paste → pass samples" always holds

## Contributing
Issues & PRs are welcome:  
1. Fork → 2. branch → 3. test samples → 4. PR  
Please keep every template single-file and dependency-free.

## License
All code is released under the [MIT](LICENSE) license. **No attribution required**; commercial use is fine.
