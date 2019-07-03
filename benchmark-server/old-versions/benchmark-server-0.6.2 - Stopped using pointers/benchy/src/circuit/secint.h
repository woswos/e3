// E3 Framework, NYUAD, 2018-2019, ver 0.1.7
// cgt build id: 1561891902
// LibsTFHMC 0 0 0 0 0 0
// Config: ../tests/user/def/cgt.cfg
// Classes: Native Native2 Cplain Ctfhe Pil

// === BEGIN atop.h

#include <string>
#include <vector>
#include <cstdio>
#include <iostream>

#include "e3util.h"
#include "evalkeys.h"

template <class T, class N = T> void initEvalKey(std::string name, T *& pek, T *& gpek);

template <class T> T multiply_by_ull(unsigned long long u, const T & x);

// CarryAdd is a switch which changes operation add.
// Normal operation add add all the bits of the arguments.
// When CarryAdd is on, add operation adds all bits except msb
// placing carryon in msb of the result.
// eg: a[5:0] and b[5:0] are two 6-bit numbers, c[5:0] is result
// CarryAdd operation adds a[4:0]+b[4:0]=c[4:0]
// and sets c[5] to carry of 5-bit addition.
// In CarryAdd case 33+17=18 because b100001+b010001=b010010
// but normally add 33+17=50 because b100001+b010001=b110010
struct CarryAdd
{
    CarryAdd();
    ~CarryAdd();
    static bool use;
    bool old;
};

// === END atop.h
// === BEGIN native.h Name=Native
class NativeBool;

template<int SZ> class NativeUint
{
        template <int Z> friend class NativeUint;
        template <int Z> friend class NativeInt;
        friend class NativeBool;

    protected:
        e3util::ull x;
        static NativeEvalKey * pek;

    public:
        static const char * name() { return "Native"; }
        static const char * scheme() { return "native"; }
        static const int size() { return SZ; };

        // Constructors
        NativeUint();
        NativeUint(const std::string &);
        NativeUint(const char * c) : NativeUint(std::string(c)) {}

        // Casting
        template <int Z> explicit operator NativeUint<Z> () const;
        explicit operator NativeBool () const;
        //operator bool() const; // forbid in template // need to remove because of ambiguity on Int*Enc

        // Operators
        NativeUint<SZ> & operator+=(const NativeUint<SZ> & a);
        NativeUint<SZ> & operator-=(const NativeUint<SZ> & a);
        NativeUint<SZ> & operator*=(const NativeUint<SZ> & a);
        NativeUint<SZ> & operator/=(const NativeUint<SZ> & a);
        NativeUint<SZ> & operator%=(const NativeUint<SZ> & a);
        NativeUint<SZ> & operator&=(const NativeUint<SZ> & a);
        NativeUint<SZ> & operator|=(const NativeUint<SZ> & a);
        NativeUint<SZ> & operator^=(const NativeUint<SZ> & a);
        NativeUint<SZ> & operator<<=(const NativeUint<SZ> & a);
        NativeUint<SZ> & operator>>=(const NativeUint<SZ> & a);
        NativeUint<SZ> & operator++();
        NativeUint<SZ> & operator--();
        NativeUint<SZ> operator++(int);
        NativeUint<SZ> operator--(int);

        NativeUint<SZ> operator+(const NativeUint<SZ> & a) const;
        NativeUint<SZ> operator-(const NativeUint<SZ> & a) const;
        NativeUint<SZ> operator*(const NativeUint<SZ> & a) const;
        NativeUint<SZ> operator/(const NativeUint<SZ> & a) const;
        NativeUint<SZ> operator%(const NativeUint<SZ> & a) const;
        NativeUint<SZ> operator&(const NativeUint<SZ> & a) const;
        NativeUint<SZ> operator|(const NativeUint<SZ> & a) const;
        NativeUint<SZ> operator^(const NativeUint<SZ> & a) const;
        NativeUint<SZ> operator<<(const NativeUint<SZ> & a) const;
        NativeUint<SZ> operator>>(const NativeUint<SZ> & a) const;
        NativeUint<SZ> operator*(const NativeBool & a) const;
        NativeUint<SZ> operator~() const;
        NativeBool operator!() const;
        NativeBool operator==(const NativeUint<SZ> & a) const;
        NativeBool operator!=(const NativeUint<SZ> & a) const;
        NativeBool operator<(const NativeUint<SZ> & a) const;
        NativeBool operator<=(const NativeUint<SZ> & a) const;
        NativeBool operator>(const NativeUint<SZ> & a) const;
        NativeBool operator>=(const NativeUint<SZ> & a) const;
        NativeBool operator&&(const NativeUint<SZ> & a) const;
        NativeBool operator||(const NativeUint<SZ> & a) const;

        NativeUint<SZ> mux(const NativeUint<SZ> & a, const NativeUint<SZ> & b) const;

        NativeUint<SZ> operator*(unsigned long long u) const;
        friend NativeUint<SZ> operator*(unsigned long long u, const NativeUint<SZ> & a) { return a * u; }

        // Functions
        std::string str() const;
};

template<int SZ> class NativeInt : public NativeUint<SZ>
{
        using base = NativeUint<SZ>;
        signed long long sll() const { return base::x; }

    protected:
        using NativeUint<SZ>::pek;
        using NativeUint<SZ>::x;

    public:
        // Constructors
        NativeInt() {}
        NativeInt(const std::string & s): NativeUint<SZ>(s) {}
        NativeInt(const char * c): NativeUint<SZ>(c) {}
        NativeInt(const NativeUint<SZ> & y): NativeUint<SZ>(y) {}
        explicit NativeInt(const NativeBool & y): NativeUint<SZ>(y) {}

        // Casting
        template <int Z> explicit operator NativeInt<Z> () const;

        // Operators
        NativeInt<SZ> & operator/=(const NativeInt<SZ> & a);
        NativeInt<SZ> & operator%=(const NativeInt<SZ> & a);
        NativeInt<SZ> & operator>>=(const NativeInt<SZ> & a);
        NativeInt<SZ> operator/(const NativeInt<SZ> & a) const;
        NativeInt<SZ> operator%(const NativeInt<SZ> & a) const;
        NativeInt<SZ> operator>>(const NativeInt<SZ> & a) const;
        NativeBool operator<(const NativeInt<SZ> & a) const;
        NativeBool operator<=(const NativeInt<SZ> & a) const;
        NativeBool operator>(const NativeInt<SZ> & a) const;
        NativeBool operator>=(const NativeInt<SZ> & a) const;

        // Functions
};

class NativeBool : public NativeUint<1>
{
    public:
        // Constructors
        NativeBool() = default;
        template <int SZ> NativeBool(const NativeUint<SZ> &);
        NativeBool(const std::string & s): NativeUint<1>(s) {}
        NativeBool(const char * c) : NativeBool(std::string(c)) {}

        // Operators
        NativeBool & operator+=(const NativeBool & a);
        NativeBool & operator-=(const NativeBool & a);
        NativeBool & operator*=(const NativeBool & a);
        NativeBool & operator/=(const NativeBool & a);
        NativeBool & operator%=(const NativeBool & a);
        NativeBool operator+(const NativeBool & a) const;
        NativeBool operator-(const NativeBool & a) const;
        NativeBool operator*(const NativeBool & a) const;
        NativeBool operator/(const NativeBool & a) const;
        NativeBool operator%(const NativeBool & a) const;
        template <int SZ> NativeUint<SZ> operator*(const NativeUint<SZ> & x) const;

        template <int SZ>
        NativeUint<SZ> mux(const NativeUint<SZ> & x, const NativeUint<SZ> & y) const;
};

template <int SZ> std::ostream & operator<<(std::ostream & os, const NativeUint<SZ> & x);
template <int SZ> std::ostream & operator<<(std::ostream & os, const NativeInt<SZ> & x);

extern NativeEvalKey * g_pek_Native;

#define _1_EN "Native[0000000000000801]"
#define _13_EN "Native[000000000000080d]"
#define _3_EN "Native[0000000000000803]"
#define _4_EN "Native[0000000000000804]"
#define _7_EN "Native[0000000000000807]"
#define _1_ENn "Native[fffffffffffff7ff]"
#define _3_ENn "Native[fffffffffffff7fd]"


// === END native.h Name=Native
// === BEGIN native.h Name=Native2
class Native2Bool;

template<int SZ> class Native2Uint
{
        template <int Z> friend class Native2Uint;
        template <int Z> friend class Native2Int;
        friend class Native2Bool;

    protected:
        e3util::ull x;
        static NativeEvalKey * pek;

    public:
        static const char * name() { return "Native2"; }
        static const char * scheme() { return "native"; }
        static const int size() { return SZ; };

        // Constructors
        Native2Uint();
        Native2Uint(const std::string &);
        Native2Uint(const char * c) : Native2Uint(std::string(c)) {}

        // Casting
        template <int Z> explicit operator Native2Uint<Z> () const;
        explicit operator Native2Bool () const;
        //operator bool() const; // forbid in template // need to remove because of ambiguity on Int*Enc

        // Operators
        Native2Uint<SZ> & operator+=(const Native2Uint<SZ> & a);
        Native2Uint<SZ> & operator-=(const Native2Uint<SZ> & a);
        Native2Uint<SZ> & operator*=(const Native2Uint<SZ> & a);
        Native2Uint<SZ> & operator/=(const Native2Uint<SZ> & a);
        Native2Uint<SZ> & operator%=(const Native2Uint<SZ> & a);
        Native2Uint<SZ> & operator&=(const Native2Uint<SZ> & a);
        Native2Uint<SZ> & operator|=(const Native2Uint<SZ> & a);
        Native2Uint<SZ> & operator^=(const Native2Uint<SZ> & a);
        Native2Uint<SZ> & operator<<=(const Native2Uint<SZ> & a);
        Native2Uint<SZ> & operator>>=(const Native2Uint<SZ> & a);
        Native2Uint<SZ> & operator++();
        Native2Uint<SZ> & operator--();
        Native2Uint<SZ> operator++(int);
        Native2Uint<SZ> operator--(int);

        Native2Uint<SZ> operator+(const Native2Uint<SZ> & a) const;
        Native2Uint<SZ> operator-(const Native2Uint<SZ> & a) const;
        Native2Uint<SZ> operator*(const Native2Uint<SZ> & a) const;
        Native2Uint<SZ> operator/(const Native2Uint<SZ> & a) const;
        Native2Uint<SZ> operator%(const Native2Uint<SZ> & a) const;
        Native2Uint<SZ> operator&(const Native2Uint<SZ> & a) const;
        Native2Uint<SZ> operator|(const Native2Uint<SZ> & a) const;
        Native2Uint<SZ> operator^(const Native2Uint<SZ> & a) const;
        Native2Uint<SZ> operator<<(const Native2Uint<SZ> & a) const;
        Native2Uint<SZ> operator>>(const Native2Uint<SZ> & a) const;
        Native2Uint<SZ> operator*(const Native2Bool & a) const;
        Native2Uint<SZ> operator~() const;
        Native2Bool operator!() const;
        Native2Bool operator==(const Native2Uint<SZ> & a) const;
        Native2Bool operator!=(const Native2Uint<SZ> & a) const;
        Native2Bool operator<(const Native2Uint<SZ> & a) const;
        Native2Bool operator<=(const Native2Uint<SZ> & a) const;
        Native2Bool operator>(const Native2Uint<SZ> & a) const;
        Native2Bool operator>=(const Native2Uint<SZ> & a) const;
        Native2Bool operator&&(const Native2Uint<SZ> & a) const;
        Native2Bool operator||(const Native2Uint<SZ> & a) const;

        Native2Uint<SZ> mux(const Native2Uint<SZ> & a, const Native2Uint<SZ> & b) const;

        Native2Uint<SZ> operator*(unsigned long long u) const;
        friend Native2Uint<SZ> operator*(unsigned long long u, const Native2Uint<SZ> & a) { return a * u; }

        // Functions
        std::string str() const;
};

template<int SZ> class Native2Int : public Native2Uint<SZ>
{
        using base = Native2Uint<SZ>;
        signed long long sll() const { return base::x; }

    protected:
        using Native2Uint<SZ>::pek;
        using Native2Uint<SZ>::x;

    public:
        // Constructors
        Native2Int() {}
        Native2Int(const std::string & s): Native2Uint<SZ>(s) {}
        Native2Int(const char * c): Native2Uint<SZ>(c) {}
        Native2Int(const Native2Uint<SZ> & y): Native2Uint<SZ>(y) {}
        explicit Native2Int(const Native2Bool & y): Native2Uint<SZ>(y) {}

        // Casting
        template <int Z> explicit operator Native2Int<Z> () const;

        // Operators
        Native2Int<SZ> & operator/=(const Native2Int<SZ> & a);
        Native2Int<SZ> & operator%=(const Native2Int<SZ> & a);
        Native2Int<SZ> & operator>>=(const Native2Int<SZ> & a);
        Native2Int<SZ> operator/(const Native2Int<SZ> & a) const;
        Native2Int<SZ> operator%(const Native2Int<SZ> & a) const;
        Native2Int<SZ> operator>>(const Native2Int<SZ> & a) const;
        Native2Bool operator<(const Native2Int<SZ> & a) const;
        Native2Bool operator<=(const Native2Int<SZ> & a) const;
        Native2Bool operator>(const Native2Int<SZ> & a) const;
        Native2Bool operator>=(const Native2Int<SZ> & a) const;

        // Functions
};

class Native2Bool : public Native2Uint<1>
{
    public:
        // Constructors
        Native2Bool() = default;
        template <int SZ> Native2Bool(const Native2Uint<SZ> &);
        Native2Bool(const std::string & s): Native2Uint<1>(s) {}
        Native2Bool(const char * c) : Native2Bool(std::string(c)) {}

        // Operators
        Native2Bool & operator+=(const Native2Bool & a);
        Native2Bool & operator-=(const Native2Bool & a);
        Native2Bool & operator*=(const Native2Bool & a);
        Native2Bool & operator/=(const Native2Bool & a);
        Native2Bool & operator%=(const Native2Bool & a);
        Native2Bool operator+(const Native2Bool & a) const;
        Native2Bool operator-(const Native2Bool & a) const;
        Native2Bool operator*(const Native2Bool & a) const;
        Native2Bool operator/(const Native2Bool & a) const;
        Native2Bool operator%(const Native2Bool & a) const;
        template <int SZ> Native2Uint<SZ> operator*(const Native2Uint<SZ> & x) const;

        template <int SZ>
        Native2Uint<SZ> mux(const Native2Uint<SZ> & x, const Native2Uint<SZ> & y) const;
};

template <int SZ> std::ostream & operator<<(std::ostream & os, const Native2Uint<SZ> & x);
template <int SZ> std::ostream & operator<<(std::ostream & os, const Native2Int<SZ> & x);

extern NativeEvalKey * g_pek_Native2;

#define _10_E2 "Native2[000000000000080a]"
#define _5_E2 "Native2[0000000000000805]"


// === END native.h Name=Native2
// === BEGIN circuit.base.h Name=Cplain

class CplainBit;

class CplainBaseBit
{
    protected:
        ///struct PekInitializer { PekInitializer( void(*f)() ) { f(); } } pekInitializer;
        static CircuitEvalKey * pek;
        static void init_pek();
        static const char * name() { return "Cplain"; }

        CplainBaseBit() { init_pek(); }

    public:
        static const CplainBit * zero, * unit;
};

// === END circuit.base.h Name=Cplain
// === BEGIN circuit.plain.h Name=Cplain

class CplainBit : public CplainBaseBit
{
    protected:
        e3util::usi x;

    public:
        CplainBit(e3util::usi ax = 0) : x(ax) {}
        CplainBit(const std::string & s);

        // access to SecureInt classes
        static CircuitEvalKey_plain * k() { return static_cast<CircuitEvalKey_plain *>(pek); }

        std::string str() const { return std::to_string(x); }

        static CplainBit gate_buf(const CplainBit & a);
        static CplainBit gate_not(const CplainBit & a);
        static CplainBit gate_and(const CplainBit & a, const CplainBit & b);
        static CplainBit gate_or(const CplainBit & a, const CplainBit & b);
        static CplainBit gate_nand(const CplainBit & a, const CplainBit & b);
        static CplainBit gate_nor(const CplainBit & a, const CplainBit & b);
        static CplainBit gate_xnor(const CplainBit & a, const CplainBit & b);
        static CplainBit gate_xor(const CplainBit & a, const CplainBit & b);
        static CplainBit gate_mux(const CplainBit & a, const CplainBit & b, const CplainBit & c);
};

// === END circuit.plain.h Name=Cplain
// === BEGIN circuit.h Name=Cplain
class CplainBool;

template<int SZ> class CplainUint
{
        template <int Z> friend class CplainUint;
        template <int Z> friend class CplainInt;
        friend class CplainBool;

    protected:
        using Bit = CplainBit;

        std::vector<Bit> bits;

        // ATTENTION 'y' must be different to 'a' and 'b'! No checks are done

        // <1> <N>
        static void d_lognot (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_redand (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_rednand(std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_rednor (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_redor  (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_redxnor(std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_redxor (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;

        // <1> <N> <N>
        static void d_eq    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_ge    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_gesig (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_gt    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_gtsig (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_ineq  (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_le    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_lesig (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_logand(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_logor (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_lt    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_ltsig (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;

        // <N> <1> <N>
        static void d_boolmul(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;

        // <N> <1> <N> <N>
        static void d_boolmux(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b, const std::vector<Bit> & c) noexcept;

        // <N> <N>
        static void d_bitnot   (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_dec      (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_uminus   (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_inc      (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;

        // <N> <N> 1
        static void d_bitsum   (std::vector<Bit> & y, const std::vector<Bit> & a, const Bit & zero) noexcept;

        // <N> <N> <N>
        static void d_add   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_bitand(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_bitor (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_bitxor(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_carryadd(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_div   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_divsig(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_mod   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_modsig(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_mul   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_sll   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_slr   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_srasig(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_sub   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        // static void d_xnor(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;

        // <N> <N> <N> <N>
        static void d_intmux(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b, const std::vector<Bit> & c) noexcept;

        void load(const std::string & s);

    public:
        static const char * name() { return "Cplain"; }
        static const int size() { return SZ; };
        static const char * scheme() { return "plain"; }

        // Constructors
        CplainUint() { bits.resize(SZ); }
        CplainUint(const std::string & s): CplainUint() { load(s); }
        CplainUint(const char * c) : CplainUint(std::string(c)) {}

        // Casting
        template <int Z> explicit operator CplainUint<Z> () const;
        explicit operator CplainBool () const;

        // Operators
        CplainUint<SZ> & operator+=(const CplainUint<SZ> & a);
        CplainUint<SZ> & operator-=(const CplainUint<SZ> & a);
        CplainUint<SZ> & operator*=(const CplainUint<SZ> & a);
        CplainUint<SZ> & operator/=(const CplainUint<SZ> & a);
        CplainUint<SZ> & operator%=(const CplainUint<SZ> & a);
        CplainUint<SZ> & operator&=(const CplainUint<SZ> & a);
        CplainUint<SZ> & operator|=(const CplainUint<SZ> & a);
        CplainUint<SZ> & operator^=(const CplainUint<SZ> & a);
        CplainUint<SZ> & operator<<=(const CplainUint<SZ> & a);
        CplainUint<SZ> & operator>>=(const CplainUint<SZ> & a);
        CplainUint<SZ> & operator++();
        CplainUint<SZ> & operator--();
        CplainUint<SZ> operator++(int);
        CplainUint<SZ> operator--(int);

        CplainUint<SZ> operator+(const CplainUint<SZ> & a) const;
        CplainUint<SZ> operator-(const CplainUint<SZ> & a) const;
        CplainUint<SZ> operator*(const CplainUint<SZ> & a) const;
        CplainUint<SZ> operator/(const CplainUint<SZ> & a) const;
        CplainUint<SZ> operator%(const CplainUint<SZ> & a) const;
        CplainUint<SZ> operator&(const CplainUint<SZ> & a) const;
        CplainUint<SZ> operator|(const CplainUint<SZ> & a) const;
        CplainUint<SZ> operator^(const CplainUint<SZ> & a) const;
        CplainUint<SZ> operator<<(const CplainUint<SZ> & a) const;
        CplainUint<SZ> operator>>(const CplainUint<SZ> & a) const;
        CplainUint<SZ> operator*(const CplainBool & a) const;
        CplainUint<SZ> operator~() const;
        CplainBool operator!() const;
        CplainBool operator==(const CplainUint<SZ> & a) const;
        CplainBool operator!=(const CplainUint<SZ> & a) const;
        CplainBool operator<(const CplainUint<SZ> & a) const;
        CplainBool operator<=(const CplainUint<SZ> & a) const;
        CplainBool operator>(const CplainUint<SZ> & a) const;
        CplainBool operator>=(const CplainUint<SZ> & a) const;
        CplainBool operator&&(const CplainUint<SZ> & a) const;
        CplainBool operator||(const CplainUint<SZ> & a) const;
        Bit operator[](int i) const { return bits[i]; }
        Bit & operator[](int i) { return bits[i]; }
        CplainUint<SZ> bitsum() const;

        CplainUint<SZ> mux(const CplainUint<SZ> & a, const CplainUint<SZ> & b) const;

        CplainUint<SZ> operator*(unsigned long long u) const;
        CplainUint<SZ> operator<<(unsigned long long u) const;
        CplainUint<SZ> operator>>(unsigned long long u) const;
        friend CplainUint<SZ> operator*(unsigned long long u, const CplainUint<SZ> & a) { return a * u; }

        // Functions
        std::string str() const;

    private:
        // Gates
        static Bit gate_buf(const Bit & a) { return Bit::gate_buf(a); }
        static Bit gate_not(const Bit & a) { return Bit::gate_not(a); }
        static Bit gate_and(const Bit & a, const Bit & b) { return Bit::gate_and(a, b); }
        static Bit gate_or(const Bit & a, const Bit & b) { return Bit::gate_or(a, b); }
        static Bit gate_nand(const Bit & a, const Bit & b) { return Bit::gate_nand(a, b); }
        static Bit gate_nor(const Bit & a, const Bit & b) { return Bit::gate_nor(a, b); }
        static Bit gate_xnor(const Bit & a, const Bit & b) { return Bit::gate_xnor(a, b); }
        static Bit gate_xor(const Bit & a, const Bit & b) { return Bit::gate_xor(a, b); }
        static Bit gate_mux(const Bit & a, const Bit & b, const Bit & c)
        { return Bit::gate_mux(c, b, a); } // the operators are switched because the netlist is FTS, while our MUX is STF
};

template<int SZ> class CplainInt : public CplainUint<SZ>
{
        using base = CplainUint<SZ>;
        signed long long sll() const { return base::x; }

    protected:
        using CplainUint<SZ>::bits;
        using CplainUint<SZ>::d_divsig;
        using CplainUint<SZ>::d_modsig;
        using CplainUint<SZ>::d_srasig;
        using CplainUint<SZ>::d_gesig;
        using CplainUint<SZ>::d_gtsig;
        using CplainUint<SZ>::d_lesig;
        using CplainUint<SZ>::d_ltsig;

    public:
        // Constructors
        CplainInt() {}
        CplainInt(const std::string & s): CplainUint<SZ>(s) {}
        CplainInt(const char * c): CplainUint<SZ>(c) {}

        CplainInt(const CplainUint<SZ> & y): CplainUint<SZ>(y) {}
        explicit CplainInt(const CplainBool & y): CplainUint<SZ>(y) {}

        // Casting
        template <int Z> explicit operator CplainInt<Z> () const;

        // Operators
        CplainInt<SZ> & operator/=(const CplainInt<SZ> & a);
        CplainInt<SZ> & operator%=(const CplainInt<SZ> & a);
        CplainInt<SZ> & operator>>=(const CplainInt<SZ> & a);
        CplainInt<SZ> operator/(const CplainInt<SZ> & a) const;
        CplainInt<SZ> operator%(const CplainInt<SZ> & a) const;
        CplainInt<SZ> operator>>(const CplainInt<SZ> & a) const;
        CplainBool operator<(const CplainInt<SZ> & a) const;
        CplainBool operator<=(const CplainInt<SZ> & a) const;
        CplainBool operator>(const CplainInt<SZ> & a) const;
        CplainBool operator>=(const CplainInt<SZ> & a) const;

        // Functions
};

class CplainBool : public CplainUint<1>
{
    public:
        // Constructors
        CplainBool() = default;
        template <int SZ> explicit CplainBool(const CplainUint<SZ> &);
        CplainBool(const std::string & s): CplainUint<1>(s) {}
        CplainBool(const char * c) : CplainBool(std::string(c)) {}

        // Operators
        CplainBool & operator+=(const CplainBool & a);
        CplainBool & operator-=(const CplainBool & a);
        CplainBool & operator*=(const CplainBool & a);
        CplainBool & operator/=(const CplainBool & a);
        CplainBool & operator%=(const CplainBool & a);
        CplainBool operator+(const CplainBool & a) const;
        CplainBool operator-(const CplainBool & a) const;
        CplainBool operator*(const CplainBool & a) const;
        CplainBool operator/(const CplainBool & a) const;
        CplainBool operator%(const CplainBool & a) const;
        template <int SZ> CplainUint<SZ> operator*(const CplainUint<SZ> & x) const;

        template <int SZ>
        CplainUint<SZ> mux(const CplainUint<SZ> & x, const CplainUint<SZ> & y) const;
};

template <int SZ> std::ostream &
operator<<(std::ostream & os, const CplainUint<SZ> & x) { return os << x.str(); }
template <int SZ> std::ostream &
operator<<(std::ostream & os, const CplainInt<SZ> & x) { return os << x.str(); }

extern CircuitEvalKey * g_pek_Cplain;

#define _100_Ecp "Cplain[800,800,801,800,800,801,801,800]"
#define _101_Ecp "Cplain[801,800,801,800,800,801,801,800]"
#define _129_Ecp "Cplain[801,800,800,800,800,800,800,801]"
#define _12_Ecpn "Cplain[800,800,801,800,801,801,801,801]"


// === END circuit.h Name=Cplain
// === BEGIN circuit.base.h Name=Ctfhe

class CtfheBit;

class CtfheBaseBit
{
    protected:
        ///struct PekInitializer { PekInitializer( void(*f)() ) { f(); } } pekInitializer;
        static CircuitEvalKey * pek;
        static void init_pek();
        static const char * name() { return "Ctfhe"; }

        CtfheBaseBit() { init_pek(); }

    public:
        static const CtfheBit * zero, * unit;
};

// === END circuit.base.h Name=Ctfhe
// === BEGIN circuit.tfhe.h Name=Ctfhe

#include "def_tfhe.h"

class CtfheBit : public CtfheBaseBit
{
    protected:

        e3::TfheNativeBt nb;

        // this function may not needed since LweSample is always
        // initialized (see default Ctor of TfheNativeBt)
        static const LweSample * op(const std::shared_ptr<LweSample> & p)
        {
            if ( !p.get() ) throw "Operation on uninitialized bit in Ctfhe";
            return p.get();
        }

    public:
        CtfheBit() : CtfheBaseBit(), nb(k()->native()) {}
        CtfheBit(e3::TfheNativeBt ax) : CtfheBaseBit(), nb(ax, k()->native()) {}
        CtfheBit(const CtfheBit & b): CtfheBaseBit(), nb(b.nb, k()->native()) {}

        CtfheBit(const std::string & s): CtfheBaseBit(), nb(s, k()->native()) {}
        ///CtfheBit(const std::string & s): pekInitializer(init_pek), nb(s, k()->native()) {}
        CtfheBit(const char * s): CtfheBit(std::string(s)) {}
        std::string str() const { return nb.str(k()->native()); }

        static e3::CircuitEvalKey_tfhe * k() { return static_cast<e3::CircuitEvalKey_tfhe *>(pek); }

        static CtfheBit gate_buf(const CtfheBit & a);
        static CtfheBit gate_not(const CtfheBit & a);
        static CtfheBit gate_and(const CtfheBit & a, const CtfheBit & b);
        static CtfheBit gate_or(const CtfheBit & a, const CtfheBit & b);
        static CtfheBit gate_nand(const CtfheBit & a, const CtfheBit & b);
        static CtfheBit gate_nor(const CtfheBit & a, const CtfheBit & b);
        static CtfheBit gate_xnor(const CtfheBit & a, const CtfheBit & b);
        static CtfheBit gate_xor(const CtfheBit & a, const CtfheBit & b);
        static CtfheBit gate_mux(const CtfheBit & a, const CtfheBit & b, const CtfheBit & c);
};

// === END circuit.tfhe.h Name=Ctfhe
// === BEGIN circuit.h Name=Ctfhe
class CtfheBool;

template<int SZ> class CtfheUint
{
        template <int Z> friend class CtfheUint;
        template <int Z> friend class CtfheInt;
        friend class CtfheBool;

    protected:
        using Bit = CtfheBit;

        std::vector<Bit> bits;

        // ATTENTION 'y' must be different to 'a' and 'b'! No checks are done

        // <1> <N>
        static void d_lognot (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_redand (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_rednand(std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_rednor (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_redor  (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_redxnor(std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_redxor (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;

        // <1> <N> <N>
        static void d_eq    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_ge    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_gesig (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_gt    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_gtsig (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_ineq  (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_le    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_lesig (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_logand(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_logor (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_lt    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_ltsig (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;

        // <N> <1> <N>
        static void d_boolmul(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;

        // <N> <1> <N> <N>
        static void d_boolmux(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b, const std::vector<Bit> & c) noexcept;

        // <N> <N>
        static void d_bitnot   (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_dec      (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_uminus   (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_inc      (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;

        // <N> <N> 1
        static void d_bitsum   (std::vector<Bit> & y, const std::vector<Bit> & a, const Bit & zero) noexcept;

        // <N> <N> <N>
        static void d_add   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_bitand(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_bitor (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_bitxor(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_carryadd(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_div   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_divsig(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_mod   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_modsig(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_mul   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_sll   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_slr   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_srasig(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_sub   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        // static void d_xnor(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;

        // <N> <N> <N> <N>
        static void d_intmux(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b, const std::vector<Bit> & c) noexcept;

        void load(const std::string & s);

    public:
        static const char * name() { return "Ctfhe"; }
        static const int size() { return SZ; };
        static const char * scheme() { return "tfhe"; }

        // Constructors
        CtfheUint() { bits.resize(SZ); }
        CtfheUint(const std::string & s): CtfheUint() { load(s); }
        CtfheUint(const char * c) : CtfheUint(std::string(c)) {}

        // Casting
        template <int Z> explicit operator CtfheUint<Z> () const;
        explicit operator CtfheBool () const;

        // Operators
        CtfheUint<SZ> & operator+=(const CtfheUint<SZ> & a);
        CtfheUint<SZ> & operator-=(const CtfheUint<SZ> & a);
        CtfheUint<SZ> & operator*=(const CtfheUint<SZ> & a);
        CtfheUint<SZ> & operator/=(const CtfheUint<SZ> & a);
        CtfheUint<SZ> & operator%=(const CtfheUint<SZ> & a);
        CtfheUint<SZ> & operator&=(const CtfheUint<SZ> & a);
        CtfheUint<SZ> & operator|=(const CtfheUint<SZ> & a);
        CtfheUint<SZ> & operator^=(const CtfheUint<SZ> & a);
        CtfheUint<SZ> & operator<<=(const CtfheUint<SZ> & a);
        CtfheUint<SZ> & operator>>=(const CtfheUint<SZ> & a);
        CtfheUint<SZ> & operator++();
        CtfheUint<SZ> & operator--();
        CtfheUint<SZ> operator++(int);
        CtfheUint<SZ> operator--(int);

        CtfheUint<SZ> operator+(const CtfheUint<SZ> & a) const;
        CtfheUint<SZ> operator-(const CtfheUint<SZ> & a) const;
        CtfheUint<SZ> operator*(const CtfheUint<SZ> & a) const;
        CtfheUint<SZ> operator/(const CtfheUint<SZ> & a) const;
        CtfheUint<SZ> operator%(const CtfheUint<SZ> & a) const;
        CtfheUint<SZ> operator&(const CtfheUint<SZ> & a) const;
        CtfheUint<SZ> operator|(const CtfheUint<SZ> & a) const;
        CtfheUint<SZ> operator^(const CtfheUint<SZ> & a) const;
        CtfheUint<SZ> operator<<(const CtfheUint<SZ> & a) const;
        CtfheUint<SZ> operator>>(const CtfheUint<SZ> & a) const;
        CtfheUint<SZ> operator*(const CtfheBool & a) const;
        CtfheUint<SZ> operator~() const;
        CtfheBool operator!() const;
        CtfheBool operator==(const CtfheUint<SZ> & a) const;
        CtfheBool operator!=(const CtfheUint<SZ> & a) const;
        CtfheBool operator<(const CtfheUint<SZ> & a) const;
        CtfheBool operator<=(const CtfheUint<SZ> & a) const;
        CtfheBool operator>(const CtfheUint<SZ> & a) const;
        CtfheBool operator>=(const CtfheUint<SZ> & a) const;
        CtfheBool operator&&(const CtfheUint<SZ> & a) const;
        CtfheBool operator||(const CtfheUint<SZ> & a) const;
        Bit operator[](int i) const { return bits[i]; }
        Bit & operator[](int i) { return bits[i]; }
        CtfheUint<SZ> bitsum() const;

        CtfheUint<SZ> mux(const CtfheUint<SZ> & a, const CtfheUint<SZ> & b) const;

        CtfheUint<SZ> operator*(unsigned long long u) const;
        CtfheUint<SZ> operator<<(unsigned long long u) const;
        CtfheUint<SZ> operator>>(unsigned long long u) const;
        friend CtfheUint<SZ> operator*(unsigned long long u, const CtfheUint<SZ> & a) { return a * u; }

        // Functions
        std::string str() const;

    private:
        // Gates
        static Bit gate_buf(const Bit & a) { return Bit::gate_buf(a); }
        static Bit gate_not(const Bit & a) { return Bit::gate_not(a); }
        static Bit gate_and(const Bit & a, const Bit & b) { return Bit::gate_and(a, b); }
        static Bit gate_or(const Bit & a, const Bit & b) { return Bit::gate_or(a, b); }
        static Bit gate_nand(const Bit & a, const Bit & b) { return Bit::gate_nand(a, b); }
        static Bit gate_nor(const Bit & a, const Bit & b) { return Bit::gate_nor(a, b); }
        static Bit gate_xnor(const Bit & a, const Bit & b) { return Bit::gate_xnor(a, b); }
        static Bit gate_xor(const Bit & a, const Bit & b) { return Bit::gate_xor(a, b); }
        static Bit gate_mux(const Bit & a, const Bit & b, const Bit & c)
        { return Bit::gate_mux(c, b, a); } // the operators are switched because the netlist is FTS, while our MUX is STF
};

template<int SZ> class CtfheInt : public CtfheUint<SZ>
{
        using base = CtfheUint<SZ>;
        signed long long sll() const { return base::x; }

    protected:
        using CtfheUint<SZ>::bits;
        using CtfheUint<SZ>::d_divsig;
        using CtfheUint<SZ>::d_modsig;
        using CtfheUint<SZ>::d_srasig;
        using CtfheUint<SZ>::d_gesig;
        using CtfheUint<SZ>::d_gtsig;
        using CtfheUint<SZ>::d_lesig;
        using CtfheUint<SZ>::d_ltsig;

    public:
        // Constructors
        CtfheInt() {}
        CtfheInt(const std::string & s): CtfheUint<SZ>(s) {}
        CtfheInt(const char * c): CtfheUint<SZ>(c) {}

        CtfheInt(const CtfheUint<SZ> & y): CtfheUint<SZ>(y) {}
        explicit CtfheInt(const CtfheBool & y): CtfheUint<SZ>(y) {}

        // Casting
        template <int Z> explicit operator CtfheInt<Z> () const;

        // Operators
        CtfheInt<SZ> & operator/=(const CtfheInt<SZ> & a);
        CtfheInt<SZ> & operator%=(const CtfheInt<SZ> & a);
        CtfheInt<SZ> & operator>>=(const CtfheInt<SZ> & a);
        CtfheInt<SZ> operator/(const CtfheInt<SZ> & a) const;
        CtfheInt<SZ> operator%(const CtfheInt<SZ> & a) const;
        CtfheInt<SZ> operator>>(const CtfheInt<SZ> & a) const;
        CtfheBool operator<(const CtfheInt<SZ> & a) const;
        CtfheBool operator<=(const CtfheInt<SZ> & a) const;
        CtfheBool operator>(const CtfheInt<SZ> & a) const;
        CtfheBool operator>=(const CtfheInt<SZ> & a) const;

        // Functions
};

class CtfheBool : public CtfheUint<1>
{
    public:
        // Constructors
        CtfheBool() = default;
        template <int SZ> explicit CtfheBool(const CtfheUint<SZ> &);
        CtfheBool(const std::string & s): CtfheUint<1>(s) {}
        CtfheBool(const char * c) : CtfheBool(std::string(c)) {}

        // Operators
        CtfheBool & operator+=(const CtfheBool & a);
        CtfheBool & operator-=(const CtfheBool & a);
        CtfheBool & operator*=(const CtfheBool & a);
        CtfheBool & operator/=(const CtfheBool & a);
        CtfheBool & operator%=(const CtfheBool & a);
        CtfheBool operator+(const CtfheBool & a) const;
        CtfheBool operator-(const CtfheBool & a) const;
        CtfheBool operator*(const CtfheBool & a) const;
        CtfheBool operator/(const CtfheBool & a) const;
        CtfheBool operator%(const CtfheBool & a) const;
        template <int SZ> CtfheUint<SZ> operator*(const CtfheUint<SZ> & x) const;

        template <int SZ>
        CtfheUint<SZ> mux(const CtfheUint<SZ> & x, const CtfheUint<SZ> & y) const;
};

template <int SZ> std::ostream &
operator<<(std::ostream & os, const CtfheUint<SZ> & x) { return os << x.str(); }
template <int SZ> std::ostream &
operator<<(std::ostream & os, const CtfheInt<SZ> & x) { return os << x.str(); }

extern CircuitEvalKey * g_pek_Ctfhe;

#define _14_EtN "Ctfhe[0,1,1,1,0,0,0,0]"
#define _7_EtN "Ctfhe[1,1,1,0,0,0,0,0]"
#define _3_EtNn "Ctfhe[1,0,1,1,1,1,1,1]"
#define _4_EtNn "Ctfhe[0,0,1,1,1,1,1,1]"


// === END circuit.h Name=Ctfhe
// === BEGIN circuit.base.h Name=Pil

class PilBit;

class PilBaseBit
{
    protected:
        ///struct PekInitializer { PekInitializer( void(*f)() ) { f(); } } pekInitializer;
        static CircuitEvalKey * pek;
        static void init_pek();
        static const char * name() { return "Pil"; }

        PilBaseBit() { init_pek(); }

    public:
        static const PilBit * zero, * unit;
};

// === END circuit.base.h Name=Pil
// === BEGIN circuit.pilc.h Name=Pil

class PilBit : public PilBaseBit
{
    protected:
        e3::PilQuad x;

    public:

        PilBit() : PilBaseBit() {}
        PilBit(const PilBit & b) = default;

        PilBit(const char * s): PilBit(std::string(s)) {}
        PilBit(const std::string & s): PilBaseBit(), x(s) {}
        e3::PilQuad native() const { return x; }

        static e3::CircuitEvalKey_pilc * k()
        { return static_cast<e3::CircuitEvalKey_pilc *>(pek); }
        static e3::PilBaseEvalKey * kb() { return &k()->bek; }

        std::string str() const { return x.str(); }

        static PilBit gate_buf(const PilBit & a);
        static PilBit gate_not(const PilBit & a);
        static PilBit gate_and(const PilBit & a, const PilBit & b);
        static PilBit gate_or(const PilBit & a, const PilBit & b);
        static PilBit gate_nand(const PilBit & a, const PilBit & b);
        static PilBit gate_nor(const PilBit & a, const PilBit & b);
        static PilBit gate_xnor(const PilBit & a, const PilBit & b);
        static PilBit gate_xor(const PilBit & a, const PilBit & b);
        static PilBit gate_mux(const PilBit & a, const PilBit & b, const PilBit & c);
};

// === END circuit.pilc.h Name=Pil
// === BEGIN circuit.h Name=Pil
class PilBool;

template<int SZ> class PilUint
{
        template <int Z> friend class PilUint;
        template <int Z> friend class PilInt;
        friend class PilBool;

    protected:
        using Bit = PilBit;

        std::vector<Bit> bits;

        // ATTENTION 'y' must be different to 'a' and 'b'! No checks are done

        // <1> <N>
        static void d_lognot (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_redand (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_rednand(std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_rednor (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_redor  (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_redxnor(std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_redxor (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;

        // <1> <N> <N>
        static void d_eq    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_ge    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_gesig (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_gt    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_gtsig (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_ineq  (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_le    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_lesig (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_logand(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_logor (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_lt    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_ltsig (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;

        // <N> <1> <N>
        static void d_boolmul(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;

        // <N> <1> <N> <N>
        static void d_boolmux(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b, const std::vector<Bit> & c) noexcept;

        // <N> <N>
        static void d_bitnot   (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_dec      (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_uminus   (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_inc      (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;

        // <N> <N> 1
        static void d_bitsum   (std::vector<Bit> & y, const std::vector<Bit> & a, const Bit & zero) noexcept;

        // <N> <N> <N>
        static void d_add   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_bitand(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_bitor (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_bitxor(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_carryadd(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_div   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_divsig(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_mod   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_modsig(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_mul   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_sll   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_slr   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_srasig(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_sub   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        // static void d_xnor(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;

        // <N> <N> <N> <N>
        static void d_intmux(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b, const std::vector<Bit> & c) noexcept;

        void load(const std::string & s);

    public:
        static const char * name() { return "Pil"; }
        static const int size() { return SZ; };
        static const char * scheme() { return "pilc"; }

        // Constructors
        PilUint() { bits.resize(SZ); }
        PilUint(const std::string & s): PilUint() { load(s); }
        PilUint(const char * c) : PilUint(std::string(c)) {}

        // Casting
        template <int Z> explicit operator PilUint<Z> () const;
        explicit operator PilBool () const;

        // Operators
        PilUint<SZ> & operator+=(const PilUint<SZ> & a);
        PilUint<SZ> & operator-=(const PilUint<SZ> & a);
        PilUint<SZ> & operator*=(const PilUint<SZ> & a);
        PilUint<SZ> & operator/=(const PilUint<SZ> & a);
        PilUint<SZ> & operator%=(const PilUint<SZ> & a);
        PilUint<SZ> & operator&=(const PilUint<SZ> & a);
        PilUint<SZ> & operator|=(const PilUint<SZ> & a);
        PilUint<SZ> & operator^=(const PilUint<SZ> & a);
        PilUint<SZ> & operator<<=(const PilUint<SZ> & a);
        PilUint<SZ> & operator>>=(const PilUint<SZ> & a);
        PilUint<SZ> & operator++();
        PilUint<SZ> & operator--();
        PilUint<SZ> operator++(int);
        PilUint<SZ> operator--(int);

        PilUint<SZ> operator+(const PilUint<SZ> & a) const;
        PilUint<SZ> operator-(const PilUint<SZ> & a) const;
        PilUint<SZ> operator*(const PilUint<SZ> & a) const;
        PilUint<SZ> operator/(const PilUint<SZ> & a) const;
        PilUint<SZ> operator%(const PilUint<SZ> & a) const;
        PilUint<SZ> operator&(const PilUint<SZ> & a) const;
        PilUint<SZ> operator|(const PilUint<SZ> & a) const;
        PilUint<SZ> operator^(const PilUint<SZ> & a) const;
        PilUint<SZ> operator<<(const PilUint<SZ> & a) const;
        PilUint<SZ> operator>>(const PilUint<SZ> & a) const;
        PilUint<SZ> operator*(const PilBool & a) const;
        PilUint<SZ> operator~() const;
        PilBool operator!() const;
        PilBool operator==(const PilUint<SZ> & a) const;
        PilBool operator!=(const PilUint<SZ> & a) const;
        PilBool operator<(const PilUint<SZ> & a) const;
        PilBool operator<=(const PilUint<SZ> & a) const;
        PilBool operator>(const PilUint<SZ> & a) const;
        PilBool operator>=(const PilUint<SZ> & a) const;
        PilBool operator&&(const PilUint<SZ> & a) const;
        PilBool operator||(const PilUint<SZ> & a) const;
        Bit operator[](int i) const { return bits[i]; }
        Bit & operator[](int i) { return bits[i]; }
        PilUint<SZ> bitsum() const;

        PilUint<SZ> mux(const PilUint<SZ> & a, const PilUint<SZ> & b) const;

        PilUint<SZ> operator*(unsigned long long u) const;
        PilUint<SZ> operator<<(unsigned long long u) const;
        PilUint<SZ> operator>>(unsigned long long u) const;
        friend PilUint<SZ> operator*(unsigned long long u, const PilUint<SZ> & a) { return a * u; }

        // Functions
        std::string str() const;

    private:
        // Gates
        static Bit gate_buf(const Bit & a) { return Bit::gate_buf(a); }
        static Bit gate_not(const Bit & a) { return Bit::gate_not(a); }
        static Bit gate_and(const Bit & a, const Bit & b) { return Bit::gate_and(a, b); }
        static Bit gate_or(const Bit & a, const Bit & b) { return Bit::gate_or(a, b); }
        static Bit gate_nand(const Bit & a, const Bit & b) { return Bit::gate_nand(a, b); }
        static Bit gate_nor(const Bit & a, const Bit & b) { return Bit::gate_nor(a, b); }
        static Bit gate_xnor(const Bit & a, const Bit & b) { return Bit::gate_xnor(a, b); }
        static Bit gate_xor(const Bit & a, const Bit & b) { return Bit::gate_xor(a, b); }
        static Bit gate_mux(const Bit & a, const Bit & b, const Bit & c)
        { return Bit::gate_mux(c, b, a); } // the operators are switched because the netlist is FTS, while our MUX is STF
};

template<int SZ> class PilInt : public PilUint<SZ>
{
        using base = PilUint<SZ>;
        signed long long sll() const { return base::x; }

    protected:
        using PilUint<SZ>::bits;
        using PilUint<SZ>::d_divsig;
        using PilUint<SZ>::d_modsig;
        using PilUint<SZ>::d_srasig;
        using PilUint<SZ>::d_gesig;
        using PilUint<SZ>::d_gtsig;
        using PilUint<SZ>::d_lesig;
        using PilUint<SZ>::d_ltsig;

    public:
        // Constructors
        PilInt() {}
        PilInt(const std::string & s): PilUint<SZ>(s) {}
        PilInt(const char * c): PilUint<SZ>(c) {}

        PilInt(const PilUint<SZ> & y): PilUint<SZ>(y) {}
        explicit PilInt(const PilBool & y): PilUint<SZ>(y) {}

        // Casting
        template <int Z> explicit operator PilInt<Z> () const;

        // Operators
        PilInt<SZ> & operator/=(const PilInt<SZ> & a);
        PilInt<SZ> & operator%=(const PilInt<SZ> & a);
        PilInt<SZ> & operator>>=(const PilInt<SZ> & a);
        PilInt<SZ> operator/(const PilInt<SZ> & a) const;
        PilInt<SZ> operator%(const PilInt<SZ> & a) const;
        PilInt<SZ> operator>>(const PilInt<SZ> & a) const;
        PilBool operator<(const PilInt<SZ> & a) const;
        PilBool operator<=(const PilInt<SZ> & a) const;
        PilBool operator>(const PilInt<SZ> & a) const;
        PilBool operator>=(const PilInt<SZ> & a) const;

        // Functions
};

class PilBool : public PilUint<1>
{
    public:
        // Constructors
        PilBool() = default;
        template <int SZ> explicit PilBool(const PilUint<SZ> &);
        PilBool(const std::string & s): PilUint<1>(s) {}
        PilBool(const char * c) : PilBool(std::string(c)) {}

        // Operators
        PilBool & operator+=(const PilBool & a);
        PilBool & operator-=(const PilBool & a);
        PilBool & operator*=(const PilBool & a);
        PilBool & operator/=(const PilBool & a);
        PilBool & operator%=(const PilBool & a);
        PilBool operator+(const PilBool & a) const;
        PilBool operator-(const PilBool & a) const;
        PilBool operator*(const PilBool & a) const;
        PilBool operator/(const PilBool & a) const;
        PilBool operator%(const PilBool & a) const;
        template <int SZ> PilUint<SZ> operator*(const PilUint<SZ> & x) const;

        template <int SZ>
        PilUint<SZ> mux(const PilUint<SZ> & x, const PilUint<SZ> & y) const;
};

template <int SZ> std::ostream &
operator<<(std::ostream & os, const PilUint<SZ> & x) { return os << x.str(); }
template <int SZ> std::ostream &
operator<<(std::ostream & os, const PilInt<SZ> & x) { return os << x.str(); }

extern CircuitEvalKey * g_pek_Pil;

#define _1_EP "Pil[392:409:294:30,385:166:335:379,210:328:434:226,174:224:3:47,85:32:99:17,163:433:62:291,224:246:122:265,110:38:239:82]"
#define _100_EP "Pil[435:59:6:302,322:178:222:166,135:395:339:112,222:274:242:417,65:207:395:65,107:334:131:8,298:41:138:115,342:307:101:177]"
#define _101_EP "Pil[434:283:275:242,60:261:435:92,331:363:321:133,20:426:163:115,272:171:78:367,216:286:307:296,194:417:402:126,377:75:126:214]"
#define _1_EPn "Pil[190:428:4:185,247:346:343:153,12:170:161:136,433:0:257:1,25:5:171:54,336:171:72:301,397:66:347:5,241:53:218:251]"
#define _12_EPn "Pil[89:374:97:163,89:289:95:254,225:153:257:34,133:74:283:74,26:258:193:285,127:26:44:246,301:30:55:84,302:173:326:151]"


// === END circuit.h Name=Pil
