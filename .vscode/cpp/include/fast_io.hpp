#ifndef FAST_IO_HPP
#define FAST_IO_HPP

#include <bits/stdc++.h>

static const auto _ = []() {
    std::ios::sync_with_stdio(false);

    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin.iword(1 << 15);
    std::cout.iword(1 << 15);

    return 0;
}();

#endif