#pragma once

// this header def_heli1.h should not be included in any code except *heli1.cpp

#include "def_heli.h"

#include "FHE.h"
#include "EncryptedArray.h"

///using NativePrivKey = FHESecKey * ;
///using NativeEvalKey = FHEPubKey * ;

struct NativeProperties
{
    FHEcontext * pcontext;
};


namespace e3heli
{

using sk = FHESecKey ;
inline  sk * tosk(HeliNativePrivKey a) { return static_cast<sk *>(a); }

using ek = FHEPubKey ;
inline  ek * toek(HeliNativeEvalKey a) { return static_cast<ek *>(a); }
inline  const ek * toek(cHeliNativeEvalKey a) { return static_cast<const ek *>(a); }

const bool PRN = false;

} // e3heli

struct HeliCtxt
{
    Ctxt b;
    HeliCtxt(const FHEPubKey * ek): b(*ek) {}
};

void init_properties_heli(NativeProperties ** ppprop, std::string & name);
