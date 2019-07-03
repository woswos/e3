// E3 Framework, NYUAD, 2018-2019, ver 0.1.7
// cgt build id: 1561891902

// === BEGIN atop.inc

template <class T, class N>
void initEvalKey(std::string name, T *& pek, T *& gpek)
{
    if ( !gpek )
    {
        try { gpek = new N(T::User::Bob, name); }
        catch (...)
        {
            std::cerr << "Cannot load evaluation key of "
                      << name << "\n";
            throw;
        }
    }

    pek = gpek;
}

template <class T> T multiply_by_ull(unsigned long long u, const T & x)
{
    if ( u == 0 ) return x - x;
    if ( u == 1 ) return x;

    T y = x + x;
    auto q = u / 2;
    y = multiply_by_ull(q, y);

    if ( u == 2 * q ) return y;
    return y + x;
}

// === END atop.inc
// === BEGIN native.inc Name=Native

// Pointer to the manager
template <int SZ> NativeEvalKey * NativeUint<SZ>::pek = nullptr;

// ----- NativeUint ----- //

// Constructors/Destructors

template <int SZ>
NativeUint<SZ>::NativeUint()
{
    if ( !pek ) initEvalKey(name(), pek, g_pek_Native);
}

template <int SZ>
NativeUint<SZ>::NativeUint(const std::string & s) : NativeUint<SZ>()
{
    string c = pek->decor(s, false, "Native");
    x = e3util::hex2ull(c);
    // hack to have valid plaintext
    // not applicable to other classes
    e3util::ull m = pek->dec(x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
}

// Casting

template <int SZ> template <int Z>
NativeUint<SZ>::operator NativeUint<Z> () const
{
    e3util::ull m = pek->dec(x);
    m &= e3util::mask(Z);
    NativeUint<Z> r;
    r.x = pek->enc(m);
    return r;
}

template <int SZ>
NativeUint<SZ>::operator NativeBool () const
{
    return NativeUint<1> (*this);
}

/*
template <int SZ>
NativeUint<SZ>::operator bool () const
{
    static_assert
    (SZ == (-1), "Implicit conversion of SecureInt to bool is not "
     "allowed; this would leak information about the encrypted data");
    throw 0;
}
*/

// Operators

template <int SZ>
inline NativeUint<SZ> & NativeUint<SZ>::operator+=(const NativeUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m += pek->dec(a.x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline NativeUint<SZ> & NativeUint<SZ>::operator-=(const NativeUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m -= pek->dec(a.x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline NativeUint<SZ> & NativeUint<SZ>::operator*=(const NativeUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m *= pek->dec(a.x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline NativeUint<SZ> & NativeUint<SZ>::operator/=(const NativeUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m /= pek->dec(a.x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline NativeUint<SZ> & NativeUint<SZ>::operator%=(const NativeUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m %= pek->dec(a.x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline NativeUint<SZ> & NativeUint<SZ>::operator&=(const NativeUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m &= pek->dec(a.x);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline NativeUint<SZ> & NativeUint<SZ>::operator^=(const NativeUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m ^= pek->dec(a.x);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline NativeUint<SZ> & NativeUint<SZ>::operator|=(const NativeUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m |= pek->dec(a.x);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline NativeUint<SZ> & NativeUint<SZ>::operator<<=(const NativeUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m <<= pek->dec(a.x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline NativeUint<SZ> & NativeUint<SZ>::operator>>=(const NativeUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m >>= pek->dec(a.x);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline NativeUint<SZ> NativeUint<SZ>::operator++(int)
{
    NativeUint r(*this);
    e3util::ull m = pek->dec(x);
    m++;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return r;
}

template <int SZ>
inline NativeUint<SZ> & NativeUint<SZ>::operator++()
{
    e3util::ull m = pek->dec(x);
    m++;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return (*this);
}

template <int SZ>
inline NativeUint<SZ> NativeUint<SZ>::operator--(int)
{
    NativeUint r(*this);
    e3util::ull m = pek->dec(x);
    m--;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return r;
}

template <int SZ>
inline NativeUint<SZ> & NativeUint<SZ>::operator--()
{
    e3util::ull m = pek->dec(x);
    m--;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return (*this);
}

template <int SZ>
inline NativeUint<SZ> NativeUint<SZ>::operator+(const NativeUint<SZ> & a) const
{
    NativeUint<SZ> r(*this);
    r += a;
    return r;
}

template <int SZ>
inline NativeUint<SZ> NativeUint<SZ>::operator-(const NativeUint<SZ> & a) const
{
    NativeUint<SZ> r(*this);
    r -= a;
    return r;
}

template <int SZ>
inline NativeUint<SZ> NativeUint<SZ>::operator*(const NativeUint<SZ> & a) const
{
    NativeUint<SZ> r(*this);
    r *= a;
    return r;
}

template <int SZ>
inline NativeUint<SZ> NativeUint<SZ>::operator/(const NativeUint<SZ> & a) const
{
    NativeUint<SZ> r(*this);
    r /= a;
    return r;
}

template <int SZ>
inline NativeUint<SZ> NativeUint<SZ>::operator%(const NativeUint<SZ> & a) const
{
    NativeUint<SZ> r(*this);
    r %= a;
    return r;
}

template <int SZ>
inline NativeUint<SZ> NativeUint<SZ>::operator&(const NativeUint<SZ> & a) const
{
    NativeUint<SZ> r(*this);
    r &= a;
    return r;
}

template <int SZ>
inline NativeUint<SZ> NativeUint<SZ>::operator^(const NativeUint<SZ> & a) const
{
    NativeUint<SZ> r(*this);
    r ^= a;
    return r;
}

template <int SZ>
inline NativeUint<SZ> NativeUint<SZ>::operator|(const NativeUint<SZ> & a) const
{
    NativeUint<SZ> r(*this);
    r |= a;
    return r;
}

template <int SZ>
inline NativeUint<SZ> NativeUint<SZ>::operator<<(const NativeUint<SZ> & a) const
{
    NativeUint<SZ> r(*this);
    r <<= a;
    return r;
}

template <int SZ>
inline NativeUint<SZ> NativeUint<SZ>::operator>>(const NativeUint<SZ> & a) const
{
    NativeUint<SZ> r(*this);
    r >>= a;
    return r;
}

template <int SZ>
inline NativeUint<SZ> NativeUint<SZ>::operator*(const NativeBool & a) const
{
    return a * (*this);
}

template <int SZ>
inline NativeUint<SZ> NativeUint<SZ>::operator~() const
{
    e3util::ull m = pek->dec(x);
    m = ~m;
    m &= e3util::mask(SZ);
    NativeUint<SZ> r;
    r.x = pek->enc(m);
    return r;
}

template <int SZ>
inline NativeBool NativeUint<SZ>::operator!() const
{
    e3util::ull m = pek->dec(x);
    m = (e3util::ull) !m;
    NativeUint<SZ> r;
    r.x = pek->enc(m);
    return NativeBool(r);
}

template <int SZ>
inline NativeBool NativeUint<SZ>::operator==(const NativeUint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m == ma;
    NativeUint<SZ> r;
    r.x = pek->enc(m);
    return NativeBool(r);
}

template <int SZ>
inline NativeBool NativeUint<SZ>::operator!=(const NativeUint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m != ma;
    NativeUint<SZ> r;
    r.x = pek->enc(m);
    return NativeBool(r);
}

template <int SZ>
inline NativeBool NativeUint<SZ>::operator<(const NativeUint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m < ma;
    NativeUint<SZ> r;
    r.x = pek->enc(m);
    return NativeBool(r);
}

template <int SZ>
inline NativeBool NativeUint<SZ>::operator<=(const NativeUint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m <= ma;
    NativeUint<SZ> r;
    r.x = pek->enc(m);
    return NativeBool(r);
}

template <int SZ>
inline NativeBool NativeUint<SZ>::operator>(const NativeUint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m > ma;
    NativeUint<SZ> r;
    r.x = pek->enc(m);
    return NativeBool(r);
}

template <int SZ>
inline NativeBool NativeUint<SZ>::operator>=(const NativeUint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m >= ma;
    NativeUint<SZ> r;
    r.x = pek->enc(m);
    return NativeBool(r);
}

template <int SZ>
inline NativeBool NativeUint<SZ>::operator&&(const NativeUint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m && ma;
    NativeUint<SZ> r;
    r.x = pek->enc(m);
    return NativeBool(r);
}

template <int SZ>
inline NativeBool NativeUint<SZ>::operator||(const NativeUint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m || ma;
    NativeUint<SZ> r;
    r.x = pek->enc(m);
    return NativeBool(r);
}

template <int SZ>
inline NativeUint<SZ> NativeUint<SZ>::mux(const NativeUint<SZ> & a, const NativeUint<SZ> & b) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    e3util::ull mb = pek->dec(b.x);
    m = e3util::ull (m ? ma : mb);
    NativeUint<SZ> r;
    r.x = pek->enc(m);
    return r;
}

template <int SZ>
inline std::ostream & operator<<(std::ostream & os, const NativeUint<SZ> & x)
{
    return os << x.str();
}

template <int SZ>
inline NativeUint<SZ> NativeBool::mux(const NativeUint<SZ> & a, const NativeUint<SZ> & b) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    e3util::ull mb = pek->dec(b.x);
    m = m ? ma : mb;
    NativeUint<SZ> r;
    r.x = pek->enc(m);
    return r;
}

template <int SZ>
inline NativeUint<SZ> NativeUint<SZ>::operator*(unsigned long long u) const
{
    return multiply_by_ull < NativeUint<SZ >> (u, *this);
}


// Functions

template <int SZ>
std::string NativeUint<SZ>::str() const
{
    std::string s = e3util::ull2hex(x);
    return pek->decor(s, true, "Native");
}


// ----- NativeInt ----- //

// Casting
template <int SZ> template <int Z>
NativeInt<SZ>::operator NativeInt<Z> () const
{
    e3util::ull m = pek->dec(x);
    m = e3util::signExtend(m, SZ);
    m &= e3util::mask(Z);
    NativeInt<Z> r;
    r.x = pek->enc(m);
    return r;
}

// Operators

template <int SZ>
inline NativeInt<SZ> & NativeInt<SZ>::operator/=(const NativeInt<SZ> & a)
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m /= ma;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline NativeInt<SZ> & NativeInt<SZ>::operator%=(const NativeInt<SZ> & a)
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m %= ma;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline NativeInt<SZ> & NativeInt<SZ>::operator>>=(const NativeInt<SZ> & a)
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m >>= ma;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline NativeInt<SZ> NativeInt<SZ>::operator/(const NativeInt<SZ> & a) const
{
    NativeInt<SZ> r(*this);
    r /= a;
    return r;
}

template <int SZ>
inline NativeInt<SZ> NativeInt<SZ>::operator%(const NativeInt<SZ> & a) const
{
    NativeInt<SZ> r(*this);
    r %= a;
    return r;
}

template <int SZ>
inline NativeInt<SZ> NativeInt<SZ>::operator>>(const NativeInt<SZ> & a) const
{
    NativeInt<SZ> r(*this);
    r >>= a;
    return r;
}

template <int SZ>
inline NativeBool NativeInt<SZ>::operator<(const NativeInt<SZ> & a) const
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m = m < ma;
    m &= e3util::mask(SZ);
    NativeUint<SZ> r;
    r.x = pek->enc(m);
    return NativeBool(r);
}

template <int SZ>
inline NativeBool NativeInt<SZ>::operator<=(const NativeInt<SZ> & a) const
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m = m <= ma;
    m &= e3util::mask(SZ);
    NativeUint<SZ> r;
    r.x = pek->enc(m);
    return NativeBool(r);
}

template <int SZ>
inline NativeBool NativeInt<SZ>::operator>(const NativeInt<SZ> & a) const
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m = m > ma;
    m &= e3util::mask(SZ);
    NativeUint<SZ> r;
    r.x = pek->enc(m);
    return NativeBool(r);
}

template <int SZ>
inline NativeBool NativeInt<SZ>::operator>=(const NativeInt<SZ> & a) const
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m = m >= ma;
    m &= e3util::mask(SZ);
    NativeUint<SZ> r;
    r.x = pek->enc(m);
    return NativeBool(r);
}

template <int SZ>
inline std::ostream & operator<<(std::ostream & os, const NativeInt<SZ> & x)
{
    return os << x.str();
}

// ----- NativeBool ----- //

// Constructors/Destructors

template <int SZ>
inline NativeBool::NativeBool(const NativeUint<SZ> & a)
{
    e3util::ull ma = pek->dec(a.x);
    e3util::ull m = ma ? 1 : 0;
    x = pek->enc(m);
}

// Operators

inline NativeBool & NativeBool::operator+=(const NativeBool & a)
{
    e3util::ull m = pek->dec(x);
    m |= pek->dec(a.x);
    // m &= e3util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline NativeBool & NativeBool::operator-=(const NativeBool & a)
{
    e3util::ull m = pek->dec(x);
    m ^= pek->dec(a.x);
    // m &= e3util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline NativeBool & NativeBool::operator*=(const NativeBool & a)
{
    e3util::ull m = pek->dec(x);
    m &= pek->dec(a.x);
    // m &= e3util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline NativeBool & NativeBool::operator/=(const NativeBool & a)
{
    e3util::ull m = pek->dec(x);
    m &= pek->dec(a.x);
    // m &= e3util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline NativeBool & NativeBool::operator%=(const NativeBool & a)
{
    e3util::ull m = pek->dec(x);
    m ^= m;
    // m &= e3util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline NativeBool NativeBool::operator+(const NativeBool & a) const
{
    NativeBool r(*this);
    r += a;
    return r;
}

inline NativeBool NativeBool::operator-(const NativeBool & a) const
{
    NativeBool r(*this);
    r -= a;
    return r;
}

inline NativeBool NativeBool::operator*(const NativeBool & a) const
{
    NativeBool r(*this);
    r *= a;
    return r;
}

inline NativeBool NativeBool::operator/(const NativeBool & a) const
{
    NativeBool r(*this);
    r /= a;
    return r;
}

inline NativeBool NativeBool::operator%(const NativeBool & a) const
{
    NativeBool r(*this);
    r %= a;
    return r;
}

template <int SZ>
inline NativeUint<SZ> NativeBool::operator*(const NativeUint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    auto mr = m ? ma : 0;
    NativeUint<SZ> r;
    r.x = pek->enc(mr);
    return r;
}

// === END native.inc Name=Native
// === BEGIN native.inc Name=Native2

// Pointer to the manager
template <int SZ> NativeEvalKey * Native2Uint<SZ>::pek = nullptr;

// ----- Native2Uint ----- //

// Constructors/Destructors

template <int SZ>
Native2Uint<SZ>::Native2Uint()
{
    if ( !pek ) initEvalKey(name(), pek, g_pek_Native2);
}

template <int SZ>
Native2Uint<SZ>::Native2Uint(const std::string & s) : Native2Uint<SZ>()
{
    string c = pek->decor(s, false, "Native2");
    x = e3util::hex2ull(c);
    // hack to have valid plaintext
    // not applicable to other classes
    e3util::ull m = pek->dec(x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
}

// Casting

template <int SZ> template <int Z>
Native2Uint<SZ>::operator Native2Uint<Z> () const
{
    e3util::ull m = pek->dec(x);
    m &= e3util::mask(Z);
    Native2Uint<Z> r;
    r.x = pek->enc(m);
    return r;
}

template <int SZ>
Native2Uint<SZ>::operator Native2Bool () const
{
    return Native2Uint<1> (*this);
}

/*
template <int SZ>
Native2Uint<SZ>::operator bool () const
{
    static_assert
    (SZ == (-1), "Implicit conversion of SecureInt to bool is not "
     "allowed; this would leak information about the encrypted data");
    throw 0;
}
*/

// Operators

template <int SZ>
inline Native2Uint<SZ> & Native2Uint<SZ>::operator+=(const Native2Uint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m += pek->dec(a.x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline Native2Uint<SZ> & Native2Uint<SZ>::operator-=(const Native2Uint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m -= pek->dec(a.x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline Native2Uint<SZ> & Native2Uint<SZ>::operator*=(const Native2Uint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m *= pek->dec(a.x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline Native2Uint<SZ> & Native2Uint<SZ>::operator/=(const Native2Uint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m /= pek->dec(a.x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline Native2Uint<SZ> & Native2Uint<SZ>::operator%=(const Native2Uint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m %= pek->dec(a.x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline Native2Uint<SZ> & Native2Uint<SZ>::operator&=(const Native2Uint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m &= pek->dec(a.x);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline Native2Uint<SZ> & Native2Uint<SZ>::operator^=(const Native2Uint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m ^= pek->dec(a.x);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline Native2Uint<SZ> & Native2Uint<SZ>::operator|=(const Native2Uint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m |= pek->dec(a.x);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline Native2Uint<SZ> & Native2Uint<SZ>::operator<<=(const Native2Uint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m <<= pek->dec(a.x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline Native2Uint<SZ> & Native2Uint<SZ>::operator>>=(const Native2Uint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m >>= pek->dec(a.x);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline Native2Uint<SZ> Native2Uint<SZ>::operator++(int)
{
    Native2Uint r(*this);
    e3util::ull m = pek->dec(x);
    m++;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return r;
}

template <int SZ>
inline Native2Uint<SZ> & Native2Uint<SZ>::operator++()
{
    e3util::ull m = pek->dec(x);
    m++;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return (*this);
}

template <int SZ>
inline Native2Uint<SZ> Native2Uint<SZ>::operator--(int)
{
    Native2Uint r(*this);
    e3util::ull m = pek->dec(x);
    m--;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return r;
}

template <int SZ>
inline Native2Uint<SZ> & Native2Uint<SZ>::operator--()
{
    e3util::ull m = pek->dec(x);
    m--;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return (*this);
}

template <int SZ>
inline Native2Uint<SZ> Native2Uint<SZ>::operator+(const Native2Uint<SZ> & a) const
{
    Native2Uint<SZ> r(*this);
    r += a;
    return r;
}

template <int SZ>
inline Native2Uint<SZ> Native2Uint<SZ>::operator-(const Native2Uint<SZ> & a) const
{
    Native2Uint<SZ> r(*this);
    r -= a;
    return r;
}

template <int SZ>
inline Native2Uint<SZ> Native2Uint<SZ>::operator*(const Native2Uint<SZ> & a) const
{
    Native2Uint<SZ> r(*this);
    r *= a;
    return r;
}

template <int SZ>
inline Native2Uint<SZ> Native2Uint<SZ>::operator/(const Native2Uint<SZ> & a) const
{
    Native2Uint<SZ> r(*this);
    r /= a;
    return r;
}

template <int SZ>
inline Native2Uint<SZ> Native2Uint<SZ>::operator%(const Native2Uint<SZ> & a) const
{
    Native2Uint<SZ> r(*this);
    r %= a;
    return r;
}

template <int SZ>
inline Native2Uint<SZ> Native2Uint<SZ>::operator&(const Native2Uint<SZ> & a) const
{
    Native2Uint<SZ> r(*this);
    r &= a;
    return r;
}

template <int SZ>
inline Native2Uint<SZ> Native2Uint<SZ>::operator^(const Native2Uint<SZ> & a) const
{
    Native2Uint<SZ> r(*this);
    r ^= a;
    return r;
}

template <int SZ>
inline Native2Uint<SZ> Native2Uint<SZ>::operator|(const Native2Uint<SZ> & a) const
{
    Native2Uint<SZ> r(*this);
    r |= a;
    return r;
}

template <int SZ>
inline Native2Uint<SZ> Native2Uint<SZ>::operator<<(const Native2Uint<SZ> & a) const
{
    Native2Uint<SZ> r(*this);
    r <<= a;
    return r;
}

template <int SZ>
inline Native2Uint<SZ> Native2Uint<SZ>::operator>>(const Native2Uint<SZ> & a) const
{
    Native2Uint<SZ> r(*this);
    r >>= a;
    return r;
}

template <int SZ>
inline Native2Uint<SZ> Native2Uint<SZ>::operator*(const Native2Bool & a) const
{
    return a * (*this);
}

template <int SZ>
inline Native2Uint<SZ> Native2Uint<SZ>::operator~() const
{
    e3util::ull m = pek->dec(x);
    m = ~m;
    m &= e3util::mask(SZ);
    Native2Uint<SZ> r;
    r.x = pek->enc(m);
    return r;
}

template <int SZ>
inline Native2Bool Native2Uint<SZ>::operator!() const
{
    e3util::ull m = pek->dec(x);
    m = (e3util::ull) !m;
    Native2Uint<SZ> r;
    r.x = pek->enc(m);
    return Native2Bool(r);
}

template <int SZ>
inline Native2Bool Native2Uint<SZ>::operator==(const Native2Uint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m == ma;
    Native2Uint<SZ> r;
    r.x = pek->enc(m);
    return Native2Bool(r);
}

template <int SZ>
inline Native2Bool Native2Uint<SZ>::operator!=(const Native2Uint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m != ma;
    Native2Uint<SZ> r;
    r.x = pek->enc(m);
    return Native2Bool(r);
}

template <int SZ>
inline Native2Bool Native2Uint<SZ>::operator<(const Native2Uint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m < ma;
    Native2Uint<SZ> r;
    r.x = pek->enc(m);
    return Native2Bool(r);
}

template <int SZ>
inline Native2Bool Native2Uint<SZ>::operator<=(const Native2Uint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m <= ma;
    Native2Uint<SZ> r;
    r.x = pek->enc(m);
    return Native2Bool(r);
}

template <int SZ>
inline Native2Bool Native2Uint<SZ>::operator>(const Native2Uint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m > ma;
    Native2Uint<SZ> r;
    r.x = pek->enc(m);
    return Native2Bool(r);
}

template <int SZ>
inline Native2Bool Native2Uint<SZ>::operator>=(const Native2Uint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m >= ma;
    Native2Uint<SZ> r;
    r.x = pek->enc(m);
    return Native2Bool(r);
}

template <int SZ>
inline Native2Bool Native2Uint<SZ>::operator&&(const Native2Uint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m && ma;
    Native2Uint<SZ> r;
    r.x = pek->enc(m);
    return Native2Bool(r);
}

template <int SZ>
inline Native2Bool Native2Uint<SZ>::operator||(const Native2Uint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m || ma;
    Native2Uint<SZ> r;
    r.x = pek->enc(m);
    return Native2Bool(r);
}

template <int SZ>
inline Native2Uint<SZ> Native2Uint<SZ>::mux(const Native2Uint<SZ> & a, const Native2Uint<SZ> & b) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    e3util::ull mb = pek->dec(b.x);
    m = e3util::ull (m ? ma : mb);
    Native2Uint<SZ> r;
    r.x = pek->enc(m);
    return r;
}

template <int SZ>
inline std::ostream & operator<<(std::ostream & os, const Native2Uint<SZ> & x)
{
    return os << x.str();
}

template <int SZ>
inline Native2Uint<SZ> Native2Bool::mux(const Native2Uint<SZ> & a, const Native2Uint<SZ> & b) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    e3util::ull mb = pek->dec(b.x);
    m = m ? ma : mb;
    Native2Uint<SZ> r;
    r.x = pek->enc(m);
    return r;
}

template <int SZ>
inline Native2Uint<SZ> Native2Uint<SZ>::operator*(unsigned long long u) const
{
    return multiply_by_ull < Native2Uint<SZ >> (u, *this);
}


// Functions

template <int SZ>
std::string Native2Uint<SZ>::str() const
{
    std::string s = e3util::ull2hex(x);
    return pek->decor(s, true, "Native2");
}


// ----- Native2Int ----- //

// Casting
template <int SZ> template <int Z>
Native2Int<SZ>::operator Native2Int<Z> () const
{
    e3util::ull m = pek->dec(x);
    m = e3util::signExtend(m, SZ);
    m &= e3util::mask(Z);
    Native2Int<Z> r;
    r.x = pek->enc(m);
    return r;
}

// Operators

template <int SZ>
inline Native2Int<SZ> & Native2Int<SZ>::operator/=(const Native2Int<SZ> & a)
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m /= ma;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline Native2Int<SZ> & Native2Int<SZ>::operator%=(const Native2Int<SZ> & a)
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m %= ma;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline Native2Int<SZ> & Native2Int<SZ>::operator>>=(const Native2Int<SZ> & a)
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m >>= ma;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline Native2Int<SZ> Native2Int<SZ>::operator/(const Native2Int<SZ> & a) const
{
    Native2Int<SZ> r(*this);
    r /= a;
    return r;
}

template <int SZ>
inline Native2Int<SZ> Native2Int<SZ>::operator%(const Native2Int<SZ> & a) const
{
    Native2Int<SZ> r(*this);
    r %= a;
    return r;
}

template <int SZ>
inline Native2Int<SZ> Native2Int<SZ>::operator>>(const Native2Int<SZ> & a) const
{
    Native2Int<SZ> r(*this);
    r >>= a;
    return r;
}

template <int SZ>
inline Native2Bool Native2Int<SZ>::operator<(const Native2Int<SZ> & a) const
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m = m < ma;
    m &= e3util::mask(SZ);
    Native2Uint<SZ> r;
    r.x = pek->enc(m);
    return Native2Bool(r);
}

template <int SZ>
inline Native2Bool Native2Int<SZ>::operator<=(const Native2Int<SZ> & a) const
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m = m <= ma;
    m &= e3util::mask(SZ);
    Native2Uint<SZ> r;
    r.x = pek->enc(m);
    return Native2Bool(r);
}

template <int SZ>
inline Native2Bool Native2Int<SZ>::operator>(const Native2Int<SZ> & a) const
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m = m > ma;
    m &= e3util::mask(SZ);
    Native2Uint<SZ> r;
    r.x = pek->enc(m);
    return Native2Bool(r);
}

template <int SZ>
inline Native2Bool Native2Int<SZ>::operator>=(const Native2Int<SZ> & a) const
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m = m >= ma;
    m &= e3util::mask(SZ);
    Native2Uint<SZ> r;
    r.x = pek->enc(m);
    return Native2Bool(r);
}

template <int SZ>
inline std::ostream & operator<<(std::ostream & os, const Native2Int<SZ> & x)
{
    return os << x.str();
}

// ----- Native2Bool ----- //

// Constructors/Destructors

template <int SZ>
inline Native2Bool::Native2Bool(const Native2Uint<SZ> & a)
{
    e3util::ull ma = pek->dec(a.x);
    e3util::ull m = ma ? 1 : 0;
    x = pek->enc(m);
}

// Operators

inline Native2Bool & Native2Bool::operator+=(const Native2Bool & a)
{
    e3util::ull m = pek->dec(x);
    m |= pek->dec(a.x);
    // m &= e3util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline Native2Bool & Native2Bool::operator-=(const Native2Bool & a)
{
    e3util::ull m = pek->dec(x);
    m ^= pek->dec(a.x);
    // m &= e3util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline Native2Bool & Native2Bool::operator*=(const Native2Bool & a)
{
    e3util::ull m = pek->dec(x);
    m &= pek->dec(a.x);
    // m &= e3util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline Native2Bool & Native2Bool::operator/=(const Native2Bool & a)
{
    e3util::ull m = pek->dec(x);
    m &= pek->dec(a.x);
    // m &= e3util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline Native2Bool & Native2Bool::operator%=(const Native2Bool & a)
{
    e3util::ull m = pek->dec(x);
    m ^= m;
    // m &= e3util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline Native2Bool Native2Bool::operator+(const Native2Bool & a) const
{
    Native2Bool r(*this);
    r += a;
    return r;
}

inline Native2Bool Native2Bool::operator-(const Native2Bool & a) const
{
    Native2Bool r(*this);
    r -= a;
    return r;
}

inline Native2Bool Native2Bool::operator*(const Native2Bool & a) const
{
    Native2Bool r(*this);
    r *= a;
    return r;
}

inline Native2Bool Native2Bool::operator/(const Native2Bool & a) const
{
    Native2Bool r(*this);
    r /= a;
    return r;
}

inline Native2Bool Native2Bool::operator%(const Native2Bool & a) const
{
    Native2Bool r(*this);
    r %= a;
    return r;
}

template <int SZ>
inline Native2Uint<SZ> Native2Bool::operator*(const Native2Uint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    auto mr = m ? ma : 0;
    Native2Uint<SZ> r;
    r.x = pek->enc(mr);
    return r;
}

// === END native.inc Name=Native2
// === BEGIN circuit.inc Name=Cplain

// Casting

template <int SZ> template <int Z>
CplainUint<SZ>::operator CplainUint<Z> () const
{
    CplainUint<Z> r;
    for ( int i = 0; i < Z; i++ )
    {
        if ( i < SZ ) r.bits[i] = bits[i];
        else r.bits[i] = *CplainBit::zero;
    }
    return r;
}

// Operators

template <int SZ>
inline CplainUint<SZ> & CplainUint<SZ>::operator+=(const CplainUint<SZ> & x)
{
    (*this) = (*this) + x;
    return (*this);
}

template <int SZ>
inline CplainUint<SZ> & CplainUint<SZ>::operator-=(const CplainUint<SZ> & x)
{
    (*this) = (*this) - x;
    return (*this);
}

template <int SZ>
inline CplainUint<SZ> & CplainUint<SZ>::operator*=(const CplainUint<SZ> & x)
{
    (*this) = (*this) * x;
    return (*this);
}

template <int SZ>
inline CplainUint<SZ> & CplainUint<SZ>::operator/=(const CplainUint<SZ> & x)
{
    (*this) = (*this) / x;
    return (*this);
}

template <int SZ>
inline CplainUint<SZ> & CplainUint<SZ>::operator%=(const CplainUint<SZ> & x)
{
    (*this) = (*this) % x;
    return (*this);
}

template <int SZ>
inline CplainUint<SZ> & CplainUint<SZ>::operator&=(const CplainUint<SZ> & x)
{
    (*this) = (*this) & x;
    return (*this);
}

template <int SZ>
inline CplainUint<SZ> & CplainUint<SZ>::operator|=(const CplainUint<SZ> & x)
{
    (*this) = (*this) | x;
    return (*this);
}

template <int SZ>
inline CplainUint<SZ> & CplainUint<SZ>::operator^=(const CplainUint<SZ> & x)
{
    (*this) = (*this) ^ x;
    return (*this);
}

template <int SZ>
inline CplainUint<SZ> & CplainUint<SZ>::operator<<=(const CplainUint<SZ> & x)
{
    (*this) = (*this) << x;
    return (*this);
}

template <int SZ>
inline CplainUint<SZ> & CplainUint<SZ>::operator>>=(const CplainUint<SZ> & x)
{
    (*this) = (*this) >> x;
    return (*this);
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::operator++(int)
{
    CplainUint<SZ> r = (*this);
    d_inc(bits, r.bits);
    return r;
}

template <int SZ>
inline CplainUint<SZ> & CplainUint<SZ>::operator++()
{
    CplainUint<SZ> r = (*this);
    d_inc(bits, r.bits);
    return (*this);
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::operator--(int)
{
    CplainUint<SZ> r = (*this);
    d_dec(bits, r.bits);
    return r;
}

template <int SZ>
inline CplainUint<SZ> & CplainUint<SZ>::operator--()
{
    CplainUint<SZ> r = (*this);
    d_dec(bits, r.bits);
    return (*this);
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::bitsum() const
{
    CplainUint<SZ> r;
    d_bitsum(r.bits, bits, *CplainBit::zero);
    return r;
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::operator+(const CplainUint<SZ> & x) const
{
    CplainUint<SZ> r;

    if (CarryAdd::use) d_carryadd(r.bits, bits, x.bits);
    else d_add(r.bits, bits, x.bits);

    return r;
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::operator-(const CplainUint<SZ> & x) const
{
    CplainUint<SZ> r;
    d_sub(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::operator*(const CplainUint<SZ> & x) const
{
    CplainUint<SZ> r;
    d_mul(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::operator/(const CplainUint<SZ> & x) const
{
    CplainUint<SZ> r;
    d_div(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::operator%(const CplainUint<SZ> & x) const
{
    CplainUint<SZ> r;
    d_mod(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::operator&(const CplainUint<SZ> & x) const
{
    CplainUint<SZ> r;
    d_bitand(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::operator|(const CplainUint<SZ> & x) const
{
    CplainUint<SZ> r;
    d_bitor(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::operator^(const CplainUint<SZ> & x) const
{
    CplainUint<SZ> r;
    d_bitxor(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::operator<<(const CplainUint<SZ> & x) const
{
    CplainUint<SZ> r;
    d_sll(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::operator>>(const CplainUint<SZ> & x) const
{
    CplainUint<SZ> r;
    d_slr(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::operator*(const CplainBool & a) const
{
    return a * (*this);
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::operator~() const
{
    CplainUint<SZ> r;
    d_bitnot(r.bits, bits);
    return r;
}

template <int SZ>
inline CplainBool CplainUint<SZ>::operator!() const
{
    CplainBool r;
    d_lognot(r.bits, bits);
    return r;
}

template <int SZ>
inline CplainBool CplainUint<SZ>::operator==(const CplainUint<SZ> & x) const
{
    CplainBool r;
    d_eq(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainBool CplainUint<SZ>::operator!=(const CplainUint<SZ> & x) const
{
    CplainBool r;
    d_ineq(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainBool CplainUint<SZ>::operator<(const CplainUint<SZ> & x) const
{
    CplainBool r;
    d_lt(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainBool CplainUint<SZ>::operator<=(const CplainUint<SZ> & x) const
{
    CplainBool r;
    d_le(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainBool CplainUint<SZ>::operator>(const CplainUint<SZ> & x) const
{
    CplainBool r;
    d_gt(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainBool CplainUint<SZ>::operator>=(const CplainUint<SZ> & x) const
{
    CplainBool r;
    d_ge(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainBool CplainUint<SZ>::operator&&(const CplainUint<SZ> & x) const
{
    CplainBool r;
    d_logand(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainBool CplainUint<SZ>::operator||(const CplainUint<SZ> & x) const
{
    CplainBool r;
    d_logor(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::mux(const CplainUint<SZ> & a, const CplainUint<SZ> & b) const
{
    CplainUint<SZ> r;
    d_intmux(r.bits, bits, a.bits, b.bits);
    return r;
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::operator*(unsigned long long u) const
{
    return multiply_by_ull < CplainUint<SZ >> (u, *this);
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::operator<<(unsigned long long u) const
{
    CplainUint<SZ> r;
    if ( u > SZ )
    {
        for ( auto b : r.bits ) b = *CplainBit::zero;
    }
    else
    {
        for ( unsigned long long i = 0; i + u < SZ; i++ )
            r.bits[i + u] = bits[i];
        for ( unsigned long long i = 0; i < u; i++ )
            r.bits[i] = *CplainBit::zero;
    }
    return r;
}

template <int SZ>
inline CplainUint<SZ> CplainUint<SZ>::operator>>(unsigned long long u) const
{
    CplainUint<SZ> r;
    if ( u > SZ )
        for ( auto b : r.bits ) b = *CplainBit::zero;
    else
    {
        for ( unsigned long long i = 0; i + u < SZ; i++ )
            r.bits[i] = bits[i + u];
        for ( unsigned long long i = 0; i < u; i++ )
            r.bits[SZ - 1 - i] = *CplainBit::zero;
    }
    return r;
}

// Functions

template <int SZ>
void CplainUint<SZ>::load(const std::string & c)
{
    auto s = CplainBit::k()->decor(c, false, "Cplain");
    if ( s.empty() ) throw "Bad decoration in Cplain [" + c + "]";
    auto bs = CplainBit::k()->enc2bits(s);
    if ( bs.empty() ) throw "Bad init in Cplain [" + c + "]";

    for ( int i = 0; i < SZ; i++ )
    {
        if ( i < (int)bs.size() ) bits[i] = CplainBit(bs[i]);
        else bits[i] = *CplainBit::zero;
    }
}

template <int SZ>
std::string CplainUint<SZ>::str() const
{
    std::vector<std::string> bs;
    for ( const auto & x : bits ) bs.push_back(x.str());
    auto s = CplainBit::k()->bits2enc(bs);
    return CplainBit::k()->decor(s, true, "Cplain");
}

// ----- CplainInt ----- //

// Casting

template <int SZ> template <int Z>
CplainInt<SZ>::operator CplainInt<Z> () const
{
    CplainUint<Z> r;
    for ( int i = 0; i < Z; i++ )
    {
        if ( i < SZ ) r.bits[i] = bits[i];
        else r.bits[i] = bits[SZ - 1];
    }
    return r;
}

// Operators

template <int SZ>
inline CplainInt<SZ> & CplainInt<SZ>::operator/=(const CplainInt<SZ> & x)
{
    (*this) = (*this) / x;
    return (*this);
}

template <int SZ>
inline CplainInt<SZ> & CplainInt<SZ>::operator%=(const CplainInt<SZ> & x)
{
    (*this) = (*this) % x;
    return (*this);
}

template <int SZ>
inline CplainInt<SZ> & CplainInt<SZ>::operator>>=(const CplainInt<SZ> & x)
{
    (*this) = (*this) >> x;
    return (*this);
}

template <int SZ>
inline CplainInt<SZ> CplainInt<SZ>::operator/(const CplainInt<SZ> & x) const
{
    CplainInt<SZ> r;
    d_divsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainInt<SZ> CplainInt<SZ>::operator%(const CplainInt<SZ> & x) const
{
    CplainInt<SZ> r;
    d_modsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainInt<SZ> CplainInt<SZ>::operator>>(const CplainInt<SZ> & x) const
{
    CplainInt<SZ> r;
    d_srasig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainBool CplainInt<SZ>::operator<(const CplainInt<SZ> & x) const
{
    CplainBool r;
    d_ltsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainBool CplainInt<SZ>::operator<=(const CplainInt<SZ> & x) const
{
    CplainBool r;
    d_lesig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainBool CplainInt<SZ>::operator>(const CplainInt<SZ> & x) const
{
    CplainBool r;
    d_gtsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CplainBool CplainInt<SZ>::operator>=(const CplainInt<SZ> & x) const
{
    CplainBool r;
    d_gesig(r.bits, bits, x.bits);
    return r;
}

// ----- CplainBool ----- //

// Constructors/Destructors

template <int SZ>
CplainBool::CplainBool(const CplainUint<SZ> & a)
{
    CplainUint<SZ>::d_redor(bits, a.bits);
}

// Operators

inline CplainBool & CplainBool::operator+=(const CplainBool & x)
{
    (*this) = (*this) + x;
    return (*this);
}

inline CplainBool & CplainBool::operator-=(const CplainBool & x)
{
    (*this) = (*this) - x;
    return (*this);
}

inline CplainBool & CplainBool::operator*=(const CplainBool & x)
{
    (*this) = (*this) * x;
    return (*this);
}

inline CplainBool & CplainBool::operator/=(const CplainBool & x)
{
    (*this) = (*this) / x;
    return (*this);
}

inline CplainBool & CplainBool::operator%=(const CplainBool & x)
{
    (*this) = (*this) % x;
    return (*this);
}

inline CplainBool CplainBool::operator+(const CplainBool & x) const
{
    CplainBool r;
    r = CplainBool ( CplainUint<1>(*this) | CplainUint<1>(x) );
    return r;
}

inline CplainBool CplainBool::operator-(const CplainBool & x) const
{
    CplainBool r;
    r = CplainBool ( CplainUint<1>(*this) ^ CplainUint<1>(x) );
///    r = (*this) ^ x;
    return r;
}

inline CplainBool CplainBool::operator*(const CplainBool & x) const
{
    CplainBool r;
    r = CplainBool ( CplainUint<1>(*this) & CplainUint<1>(x) );
///    r = (*this) & x;
    return r;
}

inline CplainBool CplainBool::operator/(const CplainBool & x) const
{
    CplainBool r;
    r = CplainBool ( CplainUint<1>(*this) & CplainUint<1>(x) );
///    r = (*this) & x;
    return r;
}

inline CplainBool CplainBool::operator%(const CplainBool & x) const
{
    CplainBool r;
    r = CplainBool ( CplainUint<1>(*this) ^ CplainUint<1>(x) );
///    r = (*this) ^ (*this);
    return r;
}

template <int SZ>
inline CplainUint<SZ> CplainBool::operator*(const CplainUint<SZ> & a) const
{
    CplainUint<SZ> r;
    CplainUint<SZ>::d_boolmul(r.bits, bits, a.bits);
    return r;
}

template <int SZ>
inline CplainUint<SZ> CplainBool::mux(const CplainUint<SZ> & x, const CplainUint<SZ> & y) const
{
    CplainUint<SZ> r;
    CplainUint<SZ>::d_boolmux(r.bits, bits, x.bits, y.bits);
    return r;
}
// === END circuit.inc Name=Cplain
// === BEGIN circuit.inc Name=Ctfhe

// Casting

template <int SZ> template <int Z>
CtfheUint<SZ>::operator CtfheUint<Z> () const
{
    CtfheUint<Z> r;
    for ( int i = 0; i < Z; i++ )
    {
        if ( i < SZ ) r.bits[i] = bits[i];
        else r.bits[i] = *CtfheBit::zero;
    }
    return r;
}

// Operators

template <int SZ>
inline CtfheUint<SZ> & CtfheUint<SZ>::operator+=(const CtfheUint<SZ> & x)
{
    (*this) = (*this) + x;
    return (*this);
}

template <int SZ>
inline CtfheUint<SZ> & CtfheUint<SZ>::operator-=(const CtfheUint<SZ> & x)
{
    (*this) = (*this) - x;
    return (*this);
}

template <int SZ>
inline CtfheUint<SZ> & CtfheUint<SZ>::operator*=(const CtfheUint<SZ> & x)
{
    (*this) = (*this) * x;
    return (*this);
}

template <int SZ>
inline CtfheUint<SZ> & CtfheUint<SZ>::operator/=(const CtfheUint<SZ> & x)
{
    (*this) = (*this) / x;
    return (*this);
}

template <int SZ>
inline CtfheUint<SZ> & CtfheUint<SZ>::operator%=(const CtfheUint<SZ> & x)
{
    (*this) = (*this) % x;
    return (*this);
}

template <int SZ>
inline CtfheUint<SZ> & CtfheUint<SZ>::operator&=(const CtfheUint<SZ> & x)
{
    (*this) = (*this) & x;
    return (*this);
}

template <int SZ>
inline CtfheUint<SZ> & CtfheUint<SZ>::operator|=(const CtfheUint<SZ> & x)
{
    (*this) = (*this) | x;
    return (*this);
}

template <int SZ>
inline CtfheUint<SZ> & CtfheUint<SZ>::operator^=(const CtfheUint<SZ> & x)
{
    (*this) = (*this) ^ x;
    return (*this);
}

template <int SZ>
inline CtfheUint<SZ> & CtfheUint<SZ>::operator<<=(const CtfheUint<SZ> & x)
{
    (*this) = (*this) << x;
    return (*this);
}

template <int SZ>
inline CtfheUint<SZ> & CtfheUint<SZ>::operator>>=(const CtfheUint<SZ> & x)
{
    (*this) = (*this) >> x;
    return (*this);
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::operator++(int)
{
    CtfheUint<SZ> r = (*this);
    d_inc(bits, r.bits);
    return r;
}

template <int SZ>
inline CtfheUint<SZ> & CtfheUint<SZ>::operator++()
{
    CtfheUint<SZ> r = (*this);
    d_inc(bits, r.bits);
    return (*this);
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::operator--(int)
{
    CtfheUint<SZ> r = (*this);
    d_dec(bits, r.bits);
    return r;
}

template <int SZ>
inline CtfheUint<SZ> & CtfheUint<SZ>::operator--()
{
    CtfheUint<SZ> r = (*this);
    d_dec(bits, r.bits);
    return (*this);
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::bitsum() const
{
    CtfheUint<SZ> r;
    d_bitsum(r.bits, bits, *CtfheBit::zero);
    return r;
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::operator+(const CtfheUint<SZ> & x) const
{
    CtfheUint<SZ> r;

    if (CarryAdd::use) d_carryadd(r.bits, bits, x.bits);
    else d_add(r.bits, bits, x.bits);

    return r;
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::operator-(const CtfheUint<SZ> & x) const
{
    CtfheUint<SZ> r;
    d_sub(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::operator*(const CtfheUint<SZ> & x) const
{
    CtfheUint<SZ> r;
    d_mul(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::operator/(const CtfheUint<SZ> & x) const
{
    CtfheUint<SZ> r;
    d_div(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::operator%(const CtfheUint<SZ> & x) const
{
    CtfheUint<SZ> r;
    d_mod(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::operator&(const CtfheUint<SZ> & x) const
{
    CtfheUint<SZ> r;
    d_bitand(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::operator|(const CtfheUint<SZ> & x) const
{
    CtfheUint<SZ> r;
    d_bitor(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::operator^(const CtfheUint<SZ> & x) const
{
    CtfheUint<SZ> r;
    d_bitxor(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::operator<<(const CtfheUint<SZ> & x) const
{
    CtfheUint<SZ> r;
    d_sll(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::operator>>(const CtfheUint<SZ> & x) const
{
    CtfheUint<SZ> r;
    d_slr(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::operator*(const CtfheBool & a) const
{
    return a * (*this);
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::operator~() const
{
    CtfheUint<SZ> r;
    d_bitnot(r.bits, bits);
    return r;
}

template <int SZ>
inline CtfheBool CtfheUint<SZ>::operator!() const
{
    CtfheBool r;
    d_lognot(r.bits, bits);
    return r;
}

template <int SZ>
inline CtfheBool CtfheUint<SZ>::operator==(const CtfheUint<SZ> & x) const
{
    CtfheBool r;
    d_eq(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheBool CtfheUint<SZ>::operator!=(const CtfheUint<SZ> & x) const
{
    CtfheBool r;
    d_ineq(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheBool CtfheUint<SZ>::operator<(const CtfheUint<SZ> & x) const
{
    CtfheBool r;
    d_lt(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheBool CtfheUint<SZ>::operator<=(const CtfheUint<SZ> & x) const
{
    CtfheBool r;
    d_le(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheBool CtfheUint<SZ>::operator>(const CtfheUint<SZ> & x) const
{
    CtfheBool r;
    d_gt(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheBool CtfheUint<SZ>::operator>=(const CtfheUint<SZ> & x) const
{
    CtfheBool r;
    d_ge(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheBool CtfheUint<SZ>::operator&&(const CtfheUint<SZ> & x) const
{
    CtfheBool r;
    d_logand(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheBool CtfheUint<SZ>::operator||(const CtfheUint<SZ> & x) const
{
    CtfheBool r;
    d_logor(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::mux(const CtfheUint<SZ> & a, const CtfheUint<SZ> & b) const
{
    CtfheUint<SZ> r;
    d_intmux(r.bits, bits, a.bits, b.bits);
    return r;
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::operator*(unsigned long long u) const
{
    return multiply_by_ull < CtfheUint<SZ >> (u, *this);
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::operator<<(unsigned long long u) const
{
    CtfheUint<SZ> r;
    if ( u > SZ )
    {
        for ( auto b : r.bits ) b = *CtfheBit::zero;
    }
    else
    {
        for ( unsigned long long i = 0; i + u < SZ; i++ )
            r.bits[i + u] = bits[i];
        for ( unsigned long long i = 0; i < u; i++ )
            r.bits[i] = *CtfheBit::zero;
    }
    return r;
}

template <int SZ>
inline CtfheUint<SZ> CtfheUint<SZ>::operator>>(unsigned long long u) const
{
    CtfheUint<SZ> r;
    if ( u > SZ )
        for ( auto b : r.bits ) b = *CtfheBit::zero;
    else
    {
        for ( unsigned long long i = 0; i + u < SZ; i++ )
            r.bits[i] = bits[i + u];
        for ( unsigned long long i = 0; i < u; i++ )
            r.bits[SZ - 1 - i] = *CtfheBit::zero;
    }
    return r;
}

// Functions

template <int SZ>
void CtfheUint<SZ>::load(const std::string & c)
{
    auto s = CtfheBit::k()->decor(c, false, "Ctfhe");
    if ( s.empty() ) throw "Bad decoration in Ctfhe [" + c + "]";
    auto bs = CtfheBit::k()->enc2bits(s);
    if ( bs.empty() ) throw "Bad init in Ctfhe [" + c + "]";

    for ( int i = 0; i < SZ; i++ )
    {
        if ( i < (int)bs.size() ) bits[i] = CtfheBit(bs[i]);
        else bits[i] = *CtfheBit::zero;
    }
}

template <int SZ>
std::string CtfheUint<SZ>::str() const
{
    std::vector<std::string> bs;
    for ( const auto & x : bits ) bs.push_back(x.str());
    auto s = CtfheBit::k()->bits2enc(bs);
    return CtfheBit::k()->decor(s, true, "Ctfhe");
}

// ----- CtfheInt ----- //

// Casting

template <int SZ> template <int Z>
CtfheInt<SZ>::operator CtfheInt<Z> () const
{
    CtfheUint<Z> r;
    for ( int i = 0; i < Z; i++ )
    {
        if ( i < SZ ) r.bits[i] = bits[i];
        else r.bits[i] = bits[SZ - 1];
    }
    return r;
}

// Operators

template <int SZ>
inline CtfheInt<SZ> & CtfheInt<SZ>::operator/=(const CtfheInt<SZ> & x)
{
    (*this) = (*this) / x;
    return (*this);
}

template <int SZ>
inline CtfheInt<SZ> & CtfheInt<SZ>::operator%=(const CtfheInt<SZ> & x)
{
    (*this) = (*this) % x;
    return (*this);
}

template <int SZ>
inline CtfheInt<SZ> & CtfheInt<SZ>::operator>>=(const CtfheInt<SZ> & x)
{
    (*this) = (*this) >> x;
    return (*this);
}

template <int SZ>
inline CtfheInt<SZ> CtfheInt<SZ>::operator/(const CtfheInt<SZ> & x) const
{
    CtfheInt<SZ> r;
    d_divsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheInt<SZ> CtfheInt<SZ>::operator%(const CtfheInt<SZ> & x) const
{
    CtfheInt<SZ> r;
    d_modsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheInt<SZ> CtfheInt<SZ>::operator>>(const CtfheInt<SZ> & x) const
{
    CtfheInt<SZ> r;
    d_srasig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheBool CtfheInt<SZ>::operator<(const CtfheInt<SZ> & x) const
{
    CtfheBool r;
    d_ltsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheBool CtfheInt<SZ>::operator<=(const CtfheInt<SZ> & x) const
{
    CtfheBool r;
    d_lesig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheBool CtfheInt<SZ>::operator>(const CtfheInt<SZ> & x) const
{
    CtfheBool r;
    d_gtsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline CtfheBool CtfheInt<SZ>::operator>=(const CtfheInt<SZ> & x) const
{
    CtfheBool r;
    d_gesig(r.bits, bits, x.bits);
    return r;
}

// ----- CtfheBool ----- //

// Constructors/Destructors

template <int SZ>
CtfheBool::CtfheBool(const CtfheUint<SZ> & a)
{
    CtfheUint<SZ>::d_redor(bits, a.bits);
}

// Operators

inline CtfheBool & CtfheBool::operator+=(const CtfheBool & x)
{
    (*this) = (*this) + x;
    return (*this);
}

inline CtfheBool & CtfheBool::operator-=(const CtfheBool & x)
{
    (*this) = (*this) - x;
    return (*this);
}

inline CtfheBool & CtfheBool::operator*=(const CtfheBool & x)
{
    (*this) = (*this) * x;
    return (*this);
}

inline CtfheBool & CtfheBool::operator/=(const CtfheBool & x)
{
    (*this) = (*this) / x;
    return (*this);
}

inline CtfheBool & CtfheBool::operator%=(const CtfheBool & x)
{
    (*this) = (*this) % x;
    return (*this);
}

inline CtfheBool CtfheBool::operator+(const CtfheBool & x) const
{
    CtfheBool r;
    r = CtfheBool ( CtfheUint<1>(*this) | CtfheUint<1>(x) );
    return r;
}

inline CtfheBool CtfheBool::operator-(const CtfheBool & x) const
{
    CtfheBool r;
    r = CtfheBool ( CtfheUint<1>(*this) ^ CtfheUint<1>(x) );
///    r = (*this) ^ x;
    return r;
}

inline CtfheBool CtfheBool::operator*(const CtfheBool & x) const
{
    CtfheBool r;
    r = CtfheBool ( CtfheUint<1>(*this) & CtfheUint<1>(x) );
///    r = (*this) & x;
    return r;
}

inline CtfheBool CtfheBool::operator/(const CtfheBool & x) const
{
    CtfheBool r;
    r = CtfheBool ( CtfheUint<1>(*this) & CtfheUint<1>(x) );
///    r = (*this) & x;
    return r;
}

inline CtfheBool CtfheBool::operator%(const CtfheBool & x) const
{
    CtfheBool r;
    r = CtfheBool ( CtfheUint<1>(*this) ^ CtfheUint<1>(x) );
///    r = (*this) ^ (*this);
    return r;
}

template <int SZ>
inline CtfheUint<SZ> CtfheBool::operator*(const CtfheUint<SZ> & a) const
{
    CtfheUint<SZ> r;
    CtfheUint<SZ>::d_boolmul(r.bits, bits, a.bits);
    return r;
}

template <int SZ>
inline CtfheUint<SZ> CtfheBool::mux(const CtfheUint<SZ> & x, const CtfheUint<SZ> & y) const
{
    CtfheUint<SZ> r;
    CtfheUint<SZ>::d_boolmux(r.bits, bits, x.bits, y.bits);
    return r;
}
// === END circuit.inc Name=Ctfhe
// === BEGIN circuit.inc Name=Pil

// Casting

template <int SZ> template <int Z>
PilUint<SZ>::operator PilUint<Z> () const
{
    PilUint<Z> r;
    for ( int i = 0; i < Z; i++ )
    {
        if ( i < SZ ) r.bits[i] = bits[i];
        else r.bits[i] = *PilBit::zero;
    }
    return r;
}

// Operators

template <int SZ>
inline PilUint<SZ> & PilUint<SZ>::operator+=(const PilUint<SZ> & x)
{
    (*this) = (*this) + x;
    return (*this);
}

template <int SZ>
inline PilUint<SZ> & PilUint<SZ>::operator-=(const PilUint<SZ> & x)
{
    (*this) = (*this) - x;
    return (*this);
}

template <int SZ>
inline PilUint<SZ> & PilUint<SZ>::operator*=(const PilUint<SZ> & x)
{
    (*this) = (*this) * x;
    return (*this);
}

template <int SZ>
inline PilUint<SZ> & PilUint<SZ>::operator/=(const PilUint<SZ> & x)
{
    (*this) = (*this) / x;
    return (*this);
}

template <int SZ>
inline PilUint<SZ> & PilUint<SZ>::operator%=(const PilUint<SZ> & x)
{
    (*this) = (*this) % x;
    return (*this);
}

template <int SZ>
inline PilUint<SZ> & PilUint<SZ>::operator&=(const PilUint<SZ> & x)
{
    (*this) = (*this) & x;
    return (*this);
}

template <int SZ>
inline PilUint<SZ> & PilUint<SZ>::operator|=(const PilUint<SZ> & x)
{
    (*this) = (*this) | x;
    return (*this);
}

template <int SZ>
inline PilUint<SZ> & PilUint<SZ>::operator^=(const PilUint<SZ> & x)
{
    (*this) = (*this) ^ x;
    return (*this);
}

template <int SZ>
inline PilUint<SZ> & PilUint<SZ>::operator<<=(const PilUint<SZ> & x)
{
    (*this) = (*this) << x;
    return (*this);
}

template <int SZ>
inline PilUint<SZ> & PilUint<SZ>::operator>>=(const PilUint<SZ> & x)
{
    (*this) = (*this) >> x;
    return (*this);
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::operator++(int)
{
    PilUint<SZ> r = (*this);
    d_inc(bits, r.bits);
    return r;
}

template <int SZ>
inline PilUint<SZ> & PilUint<SZ>::operator++()
{
    PilUint<SZ> r = (*this);
    d_inc(bits, r.bits);
    return (*this);
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::operator--(int)
{
    PilUint<SZ> r = (*this);
    d_dec(bits, r.bits);
    return r;
}

template <int SZ>
inline PilUint<SZ> & PilUint<SZ>::operator--()
{
    PilUint<SZ> r = (*this);
    d_dec(bits, r.bits);
    return (*this);
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::bitsum() const
{
    PilUint<SZ> r;
    d_bitsum(r.bits, bits, *PilBit::zero);
    return r;
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::operator+(const PilUint<SZ> & x) const
{
    PilUint<SZ> r;

    if (CarryAdd::use) d_carryadd(r.bits, bits, x.bits);
    else d_add(r.bits, bits, x.bits);

    return r;
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::operator-(const PilUint<SZ> & x) const
{
    PilUint<SZ> r;
    d_sub(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::operator*(const PilUint<SZ> & x) const
{
    PilUint<SZ> r;
    d_mul(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::operator/(const PilUint<SZ> & x) const
{
    PilUint<SZ> r;
    d_div(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::operator%(const PilUint<SZ> & x) const
{
    PilUint<SZ> r;
    d_mod(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::operator&(const PilUint<SZ> & x) const
{
    PilUint<SZ> r;
    d_bitand(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::operator|(const PilUint<SZ> & x) const
{
    PilUint<SZ> r;
    d_bitor(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::operator^(const PilUint<SZ> & x) const
{
    PilUint<SZ> r;
    d_bitxor(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::operator<<(const PilUint<SZ> & x) const
{
    PilUint<SZ> r;
    d_sll(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::operator>>(const PilUint<SZ> & x) const
{
    PilUint<SZ> r;
    d_slr(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::operator*(const PilBool & a) const
{
    return a * (*this);
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::operator~() const
{
    PilUint<SZ> r;
    d_bitnot(r.bits, bits);
    return r;
}

template <int SZ>
inline PilBool PilUint<SZ>::operator!() const
{
    PilBool r;
    d_lognot(r.bits, bits);
    return r;
}

template <int SZ>
inline PilBool PilUint<SZ>::operator==(const PilUint<SZ> & x) const
{
    PilBool r;
    d_eq(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilBool PilUint<SZ>::operator!=(const PilUint<SZ> & x) const
{
    PilBool r;
    d_ineq(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilBool PilUint<SZ>::operator<(const PilUint<SZ> & x) const
{
    PilBool r;
    d_lt(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilBool PilUint<SZ>::operator<=(const PilUint<SZ> & x) const
{
    PilBool r;
    d_le(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilBool PilUint<SZ>::operator>(const PilUint<SZ> & x) const
{
    PilBool r;
    d_gt(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilBool PilUint<SZ>::operator>=(const PilUint<SZ> & x) const
{
    PilBool r;
    d_ge(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilBool PilUint<SZ>::operator&&(const PilUint<SZ> & x) const
{
    PilBool r;
    d_logand(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilBool PilUint<SZ>::operator||(const PilUint<SZ> & x) const
{
    PilBool r;
    d_logor(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::mux(const PilUint<SZ> & a, const PilUint<SZ> & b) const
{
    PilUint<SZ> r;
    d_intmux(r.bits, bits, a.bits, b.bits);
    return r;
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::operator*(unsigned long long u) const
{
    return multiply_by_ull < PilUint<SZ >> (u, *this);
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::operator<<(unsigned long long u) const
{
    PilUint<SZ> r;
    if ( u > SZ )
    {
        for ( auto b : r.bits ) b = *PilBit::zero;
    }
    else
    {
        for ( unsigned long long i = 0; i + u < SZ; i++ )
            r.bits[i + u] = bits[i];
        for ( unsigned long long i = 0; i < u; i++ )
            r.bits[i] = *PilBit::zero;
    }
    return r;
}

template <int SZ>
inline PilUint<SZ> PilUint<SZ>::operator>>(unsigned long long u) const
{
    PilUint<SZ> r;
    if ( u > SZ )
        for ( auto b : r.bits ) b = *PilBit::zero;
    else
    {
        for ( unsigned long long i = 0; i + u < SZ; i++ )
            r.bits[i] = bits[i + u];
        for ( unsigned long long i = 0; i < u; i++ )
            r.bits[SZ - 1 - i] = *PilBit::zero;
    }
    return r;
}

// Functions

template <int SZ>
void PilUint<SZ>::load(const std::string & c)
{
    auto s = PilBit::k()->decor(c, false, "Pil");
    if ( s.empty() ) throw "Bad decoration in Pil [" + c + "]";
    auto bs = PilBit::k()->enc2bits(s);
    if ( bs.empty() ) throw "Bad init in Pil [" + c + "]";

    for ( int i = 0; i < SZ; i++ )
    {
        if ( i < (int)bs.size() ) bits[i] = PilBit(bs[i]);
        else bits[i] = *PilBit::zero;
    }
}

template <int SZ>
std::string PilUint<SZ>::str() const
{
    std::vector<std::string> bs;
    for ( const auto & x : bits ) bs.push_back(x.str());
    auto s = PilBit::k()->bits2enc(bs);
    return PilBit::k()->decor(s, true, "Pil");
}

// ----- PilInt ----- //

// Casting

template <int SZ> template <int Z>
PilInt<SZ>::operator PilInt<Z> () const
{
    PilUint<Z> r;
    for ( int i = 0; i < Z; i++ )
    {
        if ( i < SZ ) r.bits[i] = bits[i];
        else r.bits[i] = bits[SZ - 1];
    }
    return r;
}

// Operators

template <int SZ>
inline PilInt<SZ> & PilInt<SZ>::operator/=(const PilInt<SZ> & x)
{
    (*this) = (*this) / x;
    return (*this);
}

template <int SZ>
inline PilInt<SZ> & PilInt<SZ>::operator%=(const PilInt<SZ> & x)
{
    (*this) = (*this) % x;
    return (*this);
}

template <int SZ>
inline PilInt<SZ> & PilInt<SZ>::operator>>=(const PilInt<SZ> & x)
{
    (*this) = (*this) >> x;
    return (*this);
}

template <int SZ>
inline PilInt<SZ> PilInt<SZ>::operator/(const PilInt<SZ> & x) const
{
    PilInt<SZ> r;
    d_divsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilInt<SZ> PilInt<SZ>::operator%(const PilInt<SZ> & x) const
{
    PilInt<SZ> r;
    d_modsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilInt<SZ> PilInt<SZ>::operator>>(const PilInt<SZ> & x) const
{
    PilInt<SZ> r;
    d_srasig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilBool PilInt<SZ>::operator<(const PilInt<SZ> & x) const
{
    PilBool r;
    d_ltsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilBool PilInt<SZ>::operator<=(const PilInt<SZ> & x) const
{
    PilBool r;
    d_lesig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilBool PilInt<SZ>::operator>(const PilInt<SZ> & x) const
{
    PilBool r;
    d_gtsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline PilBool PilInt<SZ>::operator>=(const PilInt<SZ> & x) const
{
    PilBool r;
    d_gesig(r.bits, bits, x.bits);
    return r;
}

// ----- PilBool ----- //

// Constructors/Destructors

template <int SZ>
PilBool::PilBool(const PilUint<SZ> & a)
{
    PilUint<SZ>::d_redor(bits, a.bits);
}

// Operators

inline PilBool & PilBool::operator+=(const PilBool & x)
{
    (*this) = (*this) + x;
    return (*this);
}

inline PilBool & PilBool::operator-=(const PilBool & x)
{
    (*this) = (*this) - x;
    return (*this);
}

inline PilBool & PilBool::operator*=(const PilBool & x)
{
    (*this) = (*this) * x;
    return (*this);
}

inline PilBool & PilBool::operator/=(const PilBool & x)
{
    (*this) = (*this) / x;
    return (*this);
}

inline PilBool & PilBool::operator%=(const PilBool & x)
{
    (*this) = (*this) % x;
    return (*this);
}

inline PilBool PilBool::operator+(const PilBool & x) const
{
    PilBool r;
    r = PilBool ( PilUint<1>(*this) | PilUint<1>(x) );
    return r;
}

inline PilBool PilBool::operator-(const PilBool & x) const
{
    PilBool r;
    r = PilBool ( PilUint<1>(*this) ^ PilUint<1>(x) );
///    r = (*this) ^ x;
    return r;
}

inline PilBool PilBool::operator*(const PilBool & x) const
{
    PilBool r;
    r = PilBool ( PilUint<1>(*this) & PilUint<1>(x) );
///    r = (*this) & x;
    return r;
}

inline PilBool PilBool::operator/(const PilBool & x) const
{
    PilBool r;
    r = PilBool ( PilUint<1>(*this) & PilUint<1>(x) );
///    r = (*this) & x;
    return r;
}

inline PilBool PilBool::operator%(const PilBool & x) const
{
    PilBool r;
    r = PilBool ( PilUint<1>(*this) ^ PilUint<1>(x) );
///    r = (*this) ^ (*this);
    return r;
}

template <int SZ>
inline PilUint<SZ> PilBool::operator*(const PilUint<SZ> & a) const
{
    PilUint<SZ> r;
    PilUint<SZ>::d_boolmul(r.bits, bits, a.bits);
    return r;
}

template <int SZ>
inline PilUint<SZ> PilBool::mux(const PilUint<SZ> & x, const PilUint<SZ> & y) const
{
    PilUint<SZ> r;
    PilUint<SZ>::d_boolmux(r.bits, bits, x.bits, y.bits);
    return r;
}
// === END circuit.inc Name=Pil
