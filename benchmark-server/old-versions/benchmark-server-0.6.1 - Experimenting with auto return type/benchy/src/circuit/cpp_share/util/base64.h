#pragma once

#include <string>
///#include <vector>
///#include "e3util.h"

namespace e3util
{
namespace base64
{

std::string encode(unsigned char const * data, unsigned int data_length);
std::string decode(std::string const & data);

template <class T, class U>
inline const T * cp2cp(const U * p) { return reinterpret_cast<const T *>( p ); }
inline int st2i(size_t x) { return static_cast<int>( x ); }

inline std::string enc(const std::string & s)
{
    return encode(cp2cp<unsigned char, char>(s.c_str()), st2i(s.size()));
}

inline std::string dec(const std::string & s) { return decode(s); }

} // base64
} // util
