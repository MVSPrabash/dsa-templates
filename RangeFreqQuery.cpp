#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

namespace rgs = std::ranges;

struct RangeFreqQuery {
    std::map<int, std::vector<int>> mp;

    explicit
    RangeFreqQuery(const std::vector<int>& arr) {
        for (int i = 0; i < static_cast<int>(arr.size()); i++) {
            mp[arr[i]].push_back(i);
        }
    }
        
    int query(int left, int right, int value) const {
        if (left > right) return 0;

        auto it = mp.find(value);
        
        if (it == mp.end()) return 0;
  
        const auto& indices = it->second;

        return static_cast<int>(
            rgs::upper_bound(indices, right) -
            rgs::lower_bound(indices, left)
        );
    }

};

// NOTE: using `int` instead of `std::size_t`
//       because almost all problem have array size n <= 10^5

// NOTE: future plans for using `std::unordered_map`
//       with `splitmix64` hashing algorithm for max perf

// NOTE: no future plans so far for dynamic arrays
//       but I'll build one if I need one.

