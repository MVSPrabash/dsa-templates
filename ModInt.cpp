#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

template<u32 P>
class ModInt {
public:
    constexpr ModInt() : x{0} {}
    template<std::unsigned_integral T>
    constexpr ModInt(T v) : x(v % mod()) {}
    template<std::signed_integral T>
    constexpr ModInt(T v) {
        i64 xx = v % static_cast<i64>(mod());
        if (xx < 0) xx += mod();
        x = xx;
    }

    static constexpr u32 mod() { return P; }

    constexpr u32 val() const { return x; }

    friend constexpr bool operator==(const ModInt&, const ModInt&) = default;

    friend constexpr ModInt& operator+=(ModInt& lhs, const ModInt& rhs) {
        lhs.x += rhs.x;
        lhs.x %= mod();
        return lhs;
    }
private:
    u32 x;
};

using Z = ModInt<13>;

// Tests
int main() {
    Z a = 1, b = 2;

    std::cout << std::boolalpha << (a == b) << std::endl;
}