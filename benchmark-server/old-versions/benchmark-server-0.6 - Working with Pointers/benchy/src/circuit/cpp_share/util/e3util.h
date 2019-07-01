#pragma once

#include <string>
#include <vector>

namespace e3util
{
using ull = unsigned long long;
using sll = signed long long;
using usi = unsigned short int;

ull hex2ull(std::string);
std::string ull2hex(ull);

bool isHex(const std::string & hex);

std::string bin2hex(const std::vector<bool> & bin);
std::vector<bool> hex2bin(const std::string & hex, size_t bitsize = 0);

std::string bin2sbn(const std::vector<bool> & bin);
std::vector<bool> sbn2bin(const std::string & sbn, size_t bitsize = 0);

unsigned hex2dec(char hex);
char hex2dec(char hex, bool * carry);
char dec2hex(unsigned dec);
std::string hex2dec(const std::string & hex, size_t bitsize = 0, bool sign = false);
std::string dec2hex(const std::string & dec, size_t bitsize);
bool isNegative(const std::string & hex, size_t bitsize);
std::string twosComplement(const std::string & hex, size_t bitsize);
std::string increment(const std::string & hex, size_t bitsize);
char negation(char hex);
std::string negation(const std::string & hex, size_t bitsize);
std::string add(const std::string & dec, unsigned value);
std::string multiply(const std::string & dec, unsigned value);
std::string removeLeadingZeros(const std::string & s);
char addHex(char hex1, char hex2, bool * carry = nullptr);
std::string divide(const std::string & dec, unsigned div);
unsigned mod(const std::string & dec, unsigned div);
char maskHex(char c, size_t bitsize);
std::string zeroExtension(const std::string & hex, size_t bitsize);

constexpr inline bool bitAt(ull m, ull n)
{
    return 0 != (m & (1ull << n));
}

constexpr inline ull mask(ull n)
{
    if ( n >= 8 * sizeof(1ull) ) return -1;
    return (1ull << n) - 1;
}

constexpr inline sll signExtend(sll m, ull n)
{
    if (!bitAt(m, n - 1)) return m;
    return m | ~mask(n);
}

} // e3util

// using this macro during active development phase
#define FIX throw std::string("\nFIX ")+(__FILE__)+":"+std::to_string(__LINE__);

// === testing compiler versions
// test MS VERSION
#ifdef _MSC_VER
#if _MSC_VER < 1910
#error MS compiler version must be not less than 19.10
#endif
#endif
// test GCC version
#ifdef __GNUC__
#define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#if GCC_VERSION < 50400
#error GCC compiler version must be not less than 5.4.0
#endif
#endif
// === END testing compiler versions
