#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

template<class T>
constexpr T power(T a, u64 b, T res = 1) {
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 2;
    }
    return res;
}

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

    constexpr ModInt inv() const {
        return power(*this, mod() - 2);
    }

    constexpr ModInt& operator+=(const ModInt& rhs) {
        x += rhs.val();
        if (x >= mod()) x -= mod();
        return *this;
    }

    constexpr ModInt& operator-=(const ModInt& rhs) {
        int xx = x - rhs.val();
        if (xx < 0) xx += mod();
        x = xx;
        return *this;
    }

    constexpr ModInt& operator*=(const ModInt& rhs) {
        x = u64(x) * rhs.x % mod();
        return *this;
    }

    constexpr ModInt& operator/=(const ModInt& rhs) {
        return *this *= rhs.inv();
    }

    friend constexpr bool operator==(const ModInt& lhs, const ModInt& rhs) {
        return lhs.val() == rhs.val();
    }

    friend constexpr ModInt operator++(const ModInt& z) {
        return ModInt(z.val() + 1);
    }

    friend constexpr ModInt operator--(const ModInt& z) {
        return ModInt(z.val() - 1);
    }

    friend constexpr ModInt operator+(ModInt lhs, const ModInt& rhs) {
        return lhs += rhs;
    }

    friend constexpr ModInt operator-(ModInt lhs, const ModInt& rhs) {
        return lhs -= rhs;
    }

    friend constexpr ModInt operator*(ModInt lhs, const ModInt& rhs) {
        return lhs *= rhs;
    }

    friend constexpr ModInt operator/(ModInt lhs, const ModInt& rhs) {
        return lhs /= rhs;
    }

    constexpr ModInt operator-() const {
        return ModInt((x == 0 ? 0 : mod() - x));
    }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& z) {
        os << z.val();
        return os;
    }

    friend std::istream& operator>>(std::istream& is, ModInt& z) {
        i64 x;
        is >> x;
        z = x;
        return is;
    }
private:
    u32 x;
};

using Z = ModInt<998244353>;

