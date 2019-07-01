#pragma once

// this header def_tfhe1.h should not be included in any code except *tfhe1.cpp

#include "def_tfhe.h"

#include "tfhe.h"
#include "tfhe_io.h"

//struct LweSample { ... };

namespace e3tfhe
{

using sk = TFheGateBootstrappingSecretKeySet;
inline  sk * tosk(e3::TfheNativePrivKey a) { return static_cast<sk *>(a); }

using ek = TFheGateBootstrappingCloudKeySet;
inline  ek * toek(e3::TfheNativeEvalKey a) { return static_cast<ek *>(a); }
inline  const ek * toek(e3::cTfheNativeEvalKey a) { return static_cast<const ek *>(a); }

} // e3tfhe

