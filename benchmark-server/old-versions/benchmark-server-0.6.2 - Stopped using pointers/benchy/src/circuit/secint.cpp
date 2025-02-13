// E3 Framework, NYUAD, 2018-2019, ver 0.1.7
// cgt build id: 1561891902

// === BEGIN atop.cpp

#include <iostream>
#include <cstdlib>
#include <exception>
#include <vector>

#include "secint.h"
#include "secint.inc"


void abortion()
{
    // the program aborted for some reason (possibly unhandled exception)
    // it may come from anywhere in the program, not necessarily from E3
    std::cout << "\nAbnormal termination\n";
    std::exit(1);
}

namespace
{
int set_abortion() { std::set_terminate(abortion); return 1; }
}

// outside of namespace to suppress warning of not used variable
int abortion_set_variable = set_abortion();

using std::vector;

bool CarryAdd::use = false;
CarryAdd::CarryAdd(): old(use) { use = true; }
CarryAdd::~CarryAdd() { use = old; }

// === END atop.cpp
// === BEGIN native.cpp Name=Native

NativeEvalKey * g_pek_Native = nullptr;

// === END native.cpp Name=Native
// === BEGIN native.cpp Name=Native2

NativeEvalKey * g_pek_Native2 = nullptr;

// === END native.cpp Name=Native2
template<> void CplainUint<1>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(b[0], a[0]);
}
template<> void CplainUint<1>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
}
template<> void CplainUint<1>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void CplainUint<1>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  auto n3 = gate_not(a[0]);
  y[0] = gate_nand(n4, n3);
}
template<> void CplainUint<1>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  auto _a0 = gate_buf(a[0]);
  y[0] = gate_buf(_a0);
}
template<> void CplainUint<1>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(b[0], a[0]);
}
template<> void CplainUint<1>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
}
template<> void CplainUint<1>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
}
template<> void CplainUint<1>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], a[0]);
}
template<> void CplainUint<1>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void CplainUint<1>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_not(a[0]);
  y[0] = gate_nand(b[0], n1);
}
template<> void CplainUint<1>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto _a0 = gate_buf(a[0]);
  y[0] = gate_buf(_a0);
}
template<> void CplainUint<1>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xnor(b[0], a[0]);
}
template<> void CplainUint<1>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_not(a[0]);
  y[0] = gate_nand(b[0], n3);
}
template<> void CplainUint<1>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_not(b[0]);
  y[0] = gate_nand(a[0], n3);
}
template<> void CplainUint<1>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  y[0] = gate_and(a[0], n4);
}
template<> void CplainUint<1>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(a[0]);
  y[0] = gate_and(b[0], n4);
}
template<> void CplainUint<1>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void CplainUint<1>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(b[0], a[0]);
}
template<> void CplainUint<1>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
}
template<> void CplainUint<1>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_not(b[0]);
  y[0] = gate_nand(a[0], n3);
}
template<> void CplainUint<1>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_not(a[0]);
  y[0] = gate_nand(b[0], n3);
}
template<> void CplainUint<1>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
}
template<> void CplainUint<1>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void CplainUint<1>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  auto n3 = gate_not(a[0]);
  y[0] = gate_nand(n4, n3);
}
template<> void CplainUint<1>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(a[0]);
  y[0] = gate_and(b[0], n4);
}
template<> void CplainUint<1>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  y[0] = gate_and(a[0], n4);
}
template<> void CplainUint<1>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_not(b[0]);
  y[0] = gate_and(a[0], n2);
}
template<> void CplainUint<1>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_not(b[0]);
  y[0] = gate_and(a[0], n2);
}
template<> void CplainUint<1>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
}
template<> void CplainUint<1>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void CplainUint<1>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void CplainUint<1>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void CplainUint<1>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void CplainUint<1>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void CplainUint<1>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void CplainUint<1>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  y[0] = gate_and(a[0], n4);
}
template<> void CplainUint<1>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  y[0] = gate_and(a[0], n4);
}
template<> void CplainUint<1>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void CplainUint<1>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(b[0], a[0]);
}
template<> void CplainUint<1>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void CplainUint<2>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n6 = gate_nand(b[0], a[0]);
  auto _add_x_1_n6 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n6);
  auto n5 = gate_xor(b[1], a[1]);
  y[1] = gate_xnor(n6, n5);
}
template<> void CplainUint<2>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[1] = gate_and(b[1], a[1]);
  y[0] = gate_and(b[0], a[0]);
}
template<> void CplainUint<2>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[1] = gate_not(a[1]);
  y[0] = gate_not(a[0]);
}
template<> void CplainUint<2>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n6 = gate_not(b[1]);
  auto n5 = gate_not(a[1]);
  y[1] = gate_nand(n6, n5);
  auto n8 = gate_not(b[0]);
  auto n7 = gate_not(a[0]);
  y[0] = gate_nand(n8, n7);
}
template<> void CplainUint<2>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  auto N0 = gate_buf(a[0]);
  y[1] = gate_and(a[1], N0);
  auto _add_x_1_n6 = gate_xor(a[1], N0);
  y[0] = gate_buf(_add_x_1_n6);
}
template<> void CplainUint<2>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[1] = gate_xor(b[1], a[1]);
  y[0] = gate_xor(b[0], a[0]);
}
template<> void CplainUint<2>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[1] = gate_and(a[0], b[1]);
  y[0] = gate_and(a[0], b[0]);
}
template<> void CplainUint<2>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
  y[1] = gate_mux(c[1], b[1], a[0]);
}
template<> void CplainUint<2>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[1] = gate_and(b[0], a[0]);
  auto _add_x_1_n6 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n6);
}
template<> void CplainUint<2>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  y[1] = gate_xor(a[1], y[0]);
}
template<> void CplainUint<2>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_not(a[0]);
  auto n5 = gate_nand(b[0], n3);
  auto n6 = gate_not(a[1]);
  auto n7 = gate_nand(b[0], n6);
  auto n4 = gate_nand(b[1], n6);
  y[0] = gate_and(n5, n4);
  auto n8 = gate_not(b[1]);
  y[1] = gate_and(n8, n7);
}
template<> void CplainUint<2>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(a[0]);
  auto n5 = gate_nand(a[1], n4);
  auto n6 = gate_nand(b[1], n5);
  auto n10 = gate_mux(n6, a[0], b[0]);
  auto n8 = gate_not(b[0]);
  auto n7 = gate_not(b[1]);
  auto n1 = gate_and(n8, n7);
  auto n9 = gate_nand(n1, a[1]);
  y[0] = gate_and(n10, n9);
  auto n11 = gate_xor(a[1], a[0]);
  auto n2 = gate_and(b[0], n11);
  y[1] = gate_mux(a[1], n2, b[1]);
}
template<> void CplainUint<2>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_not(a[0]);
  auto n11 = gate_xor(n8, b[0]);
  auto n9 = gate_not(a[1]);
  auto n10 = gate_xor(n9, b[1]);
  y[0] = gate_and(n11, n10);
}
template<> void CplainUint<2>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_not(b[1]);
  auto n13 = gate_nand(n8, a[1]);
  auto n11 = gate_xor(n8, a[1]);
  auto n9 = gate_not(a[0]);
  auto n10 = gate_nand(b[0], n9);
  auto n12 = gate_nand(n11, n10);
  y[0] = gate_nand(n13, n12);
}
template<> void CplainUint<2>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_not(a[1]);
  auto n13 = gate_nand(n8, b[1]);
  auto n11 = gate_xor(n8, b[1]);
  auto n9 = gate_not(a[0]);
  auto n10 = gate_nand(b[0], n9);
  auto n12 = gate_nand(n11, n10);
  y[0] = gate_nand(n13, n12);
}
template<> void CplainUint<2>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_not(a[1]);
  auto n15 = gate_nand(n10, b[1]);
  auto n13 = gate_xor(n10, b[1]);
  auto n11 = gate_not(b[0]);
  auto n12 = gate_nand(a[0], n11);
  auto n14 = gate_nand(n13, n12);
  y[0] = gate_and(n15, n14);
}
template<> void CplainUint<2>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_not(b[1]);
  auto n15 = gate_nand(n10, a[1]);
  auto n13 = gate_xor(n10, a[1]);
  auto n11 = gate_not(b[0]);
  auto n12 = gate_nand(a[0], n11);
  auto n14 = gate_nand(n13, n12);
  y[0] = gate_and(n15, n14);
}
template<> void CplainUint<2>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[1] = gate_xor(a[0], a[1]);
  y[0] = gate_not(a[0]);
}
template<> void CplainUint<2>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n5 = gate_not(a[0]);
  auto n8 = gate_xor(n5, b[0]);
  auto n6 = gate_not(a[1]);
  auto n7 = gate_xor(n6, b[1]);
  auto _ne_x_1_n4 = gate_nand(n8, n7);
  y[0] = gate_buf(_ne_x_1_n4);
}
template<> void CplainUint<2>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n5 = gate_not(a[0]);
  auto n4 = gate_not(a[1]);
  auto n6 = gate_nand(n5, n4);
  y[0] = gate_mux(c[0], b[0], n6);
  y[1] = gate_mux(c[1], b[1], n6);
}
template<> void CplainUint<2>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n7 = gate_not(a[1]);
  auto n12 = gate_nand(n7, b[1]);
  auto n10 = gate_xor(n7, b[1]);
  auto n8 = gate_not(b[0]);
  auto n9 = gate_nand(a[0], n8);
  auto n11 = gate_nand(n10, n9);
  auto _lte_x_1_n5 = gate_nand(n12, n11);
  y[0] = gate_buf(_lte_x_1_n5);
}
template<> void CplainUint<2>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n7 = gate_not(b[1]);
  auto n12 = gate_nand(n7, a[1]);
  auto n10 = gate_xor(n7, a[1]);
  auto n8 = gate_not(b[0]);
  auto n9 = gate_nand(a[0], n8);
  auto n11 = gate_nand(n10, n9);
  auto _lte_x_1_n5 = gate_nand(n12, n11);
  y[0] = gate_buf(_lte_x_1_n5);
}
template<> void CplainUint<2>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_not(b[0]);
  auto n9 = gate_not(b[1]);
  auto n14 = gate_nand(n10, n9);
  auto n12 = gate_not(a[0]);
  auto n11 = gate_not(a[1]);
  auto n13 = gate_nand(n12, n11);
  y[0] = gate_and(n14, n13);
}
template<> void CplainUint<2>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n7 = gate_not(a[0]);
  auto n6 = gate_not(a[1]);
  y[0] = gate_and(n7, n6);
}
template<> void CplainUint<2>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n12 = gate_not(a[1]);
  auto n11 = gate_not(b[1]);
  auto n10 = gate_and(n12, n11);
  auto n14 = gate_not(b[0]);
  auto n13 = gate_not(a[0]);
  auto n9 = gate_and(n14, n13);
  y[0] = gate_nand(n10, n9);
}
template<> void CplainUint<2>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_not(b[1]);
  auto n14 = gate_nand(n9, a[1]);
  auto n12 = gate_xor(n9, a[1]);
  auto n10 = gate_not(a[0]);
  auto n11 = gate_nand(b[0], n10);
  auto n13 = gate_nand(n12, n11);
  y[0] = gate_and(n14, n13);
}
template<> void CplainUint<2>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_not(a[1]);
  auto n14 = gate_nand(n9, b[1]);
  auto n12 = gate_xor(n9, b[1]);
  auto n10 = gate_not(a[0]);
  auto n11 = gate_nand(b[0], n10);
  auto n13 = gate_nand(n12, n11);
  y[0] = gate_and(n14, n13);
}
template<> void CplainUint<2>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_not(a[1]);
  auto n4 = gate_nand(b[1], n3);
  auto n5 = gate_nand(n4, b[0]);
  y[0] = gate_and(a[0], n5);
  auto n6 = gate_not(a[0]);
  auto n7 = gate_nand(b[1], n6);
  auto n8 = gate_mux(b[1], n7, b[0]);
  auto n9 = gate_not(n8);
  y[1] = gate_and(a[1], n9);
}
template<> void CplainUint<2>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  auto n1 = gate_and(n4, a[1]);
  y[0] = gate_and(a[0], n4);
  auto n5 = gate_not(a[0]);
  auto n6 = gate_nand(b[1], n5);
  y[1] = gate_and(n1, n6);
}
template<> void CplainUint<2>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(a[0], b[0]);
  auto n6 = gate_nand(a[1], b[0]);
  auto n5 = gate_nand(b[1], a[0]);
  y[1] = gate_xor(n6, n5);
}
template<> void CplainUint<2>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_and(a[0], a[1]);
}
template<> void CplainUint<2>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_nand(a[0], a[1]);
}
template<> void CplainUint<2>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n7 = gate_not(a[0]);
  auto n6 = gate_not(a[1]);
  y[0] = gate_and(n7, n6);
}
template<> void CplainUint<2>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n4 = gate_not(a[0]);
  auto n3 = gate_not(a[1]);
  y[0] = gate_nand(n4, n3);
}
template<> void CplainUint<2>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_xnor(a[0], a[1]);
}
template<> void CplainUint<2>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_xor(a[0], a[1]);
}
template<> void CplainUint<2>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_not(b[0]);
  auto n12 = gate_mux(a[1], a[0], b[0]);
  auto n10 = gate_and(a[0], n11);
  auto n13 = gate_not(b[1]);
  y[1] = gate_and(n13, n12);
  y[0] = gate_and(n10, n13);
}
template<> void CplainUint<2>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_not(b[0]);
  auto n12 = gate_mux(a[0], a[1], b[0]);
  auto n10 = gate_and(a[1], n11);
  auto n13 = gate_not(b[1]);
  y[1] = gate_and(n10, n13);
  y[0] = gate_and(n13, n12);
}
template<> void CplainUint<2>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[1] = gate_buf(a[1]);
  auto n5 = gate_not(b[0]);
  auto n4 = gate_not(b[1]);
  auto n6 = gate_nand(n5, n4);
  y[0] = gate_mux(a[0], a[1], n6);
}
template<> void CplainUint<2>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n8 = gate_not(b[1]);
  auto n5 = gate_not(a[0]);
  auto n6 = gate_nand(b[0], n5);
  auto n7 = gate_xor(n6, a[1]);
  y[1] = gate_xor(n8, n7);
}
template<> void CplainUint<2>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  y[1] = gate_xor(a[0], a[1]);
}
template<> void CplainUint<3>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_and(b[0], a[0]);
  auto _add_x_1_n9 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n9);
  auto n9 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n8, n9);
  auto n11 = gate_nand(n8, n9);
  auto n10 = gate_nand(b[1], a[1]);
  auto n12 = gate_nand(n11, n10);
  auto n13 = gate_xor(b[2], n12);
  y[2] = gate_xor(a[2], n13);
}
template<> void CplainUint<3>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_and(b[2], a[2]);
  y[0] = gate_and(b[0], a[0]);
  y[1] = gate_and(b[1], a[1]);
}
template<> void CplainUint<3>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[2] = gate_not(a[2]);
  y[1] = gate_not(a[1]);
  y[0] = gate_not(a[0]);
}
template<> void CplainUint<3>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_not(b[2]);
  auto n7 = gate_not(a[2]);
  y[2] = gate_nand(n8, n7);
  auto n10 = gate_not(b[1]);
  auto n9 = gate_not(a[1]);
  y[1] = gate_nand(n10, n9);
  auto n12 = gate_not(b[0]);
  auto n11 = gate_not(a[0]);
  y[0] = gate_nand(n12, n11);
}
template<> void CplainUint<3>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  auto N0 = gate_buf(a[0]);
  y[2] = gate_buf(zero);
  auto n6 = gate_nand(a[1], N0);
  auto n7 = gate_xor(a[1], N0);
  auto n5 = gate_nand(n7, a[2]);
  y[1] = gate_nand(n6, n5);
  auto _add_x_2_n9 = gate_xor(n7, a[2]);
  y[0] = gate_buf(_add_x_2_n9);
}
template<> void CplainUint<3>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_xor(b[2], a[2]);
  y[1] = gate_xor(b[1], a[1]);
  y[0] = gate_xor(b[0], a[0]);
}
template<> void CplainUint<3>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_and(a[0], b[2]);
  y[1] = gate_and(a[0], b[1]);
  y[0] = gate_and(a[0], b[0]);
}
template<> void CplainUint<3>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
  y[1] = gate_mux(c[1], b[1], a[0]);
  y[2] = gate_mux(c[2], b[2], a[0]);
}
template<> void CplainUint<3>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n6 = gate_and(b[0], a[0]);
  auto n7 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n7, n6);
  auto _add_x_1_n9 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n9);
  auto n9 = gate_nand(b[1], a[1]);
  auto n8 = gate_nand(n7, n6);
  auto _add_x_1_n11 = gate_nand(n9, n8);
  y[2] = gate_buf(_add_x_1_n11);
}
template<> void CplainUint<3>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  auto n5 = gate_not(a[1]);
  y[1] = gate_xor(a[0], n5);
  auto n7 = gate_not(a[2]);
  auto n6 = gate_nand(y[0], n5);
  y[2] = gate_xor(n7, n6);
}
template<> void CplainUint<3>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(b[2]);
  auto n1 = gate_and(b[1], n22);
  auto n7 = gate_not(a[1]);
  auto n8 = gate_nand(b[0], n7);
  auto n23 = gate_nand(n22, n8);
  auto n6 = gate_and(a[2], n23);
  auto n10 = gate_not(n23);
  auto n19 = gate_not(a[2]);
  auto n9 = gate_nand(b[1], n19);
  y[1] = gate_and(n10, n9);
  auto n13 = gate_not(b[1]);
  auto n2 = gate_and(n22, n13);
  auto n11 = gate_nand(b[0], n19);
  y[2] = gate_and(n2, n11);
  auto n12 = gate_nand(y[1], b[0]);
  auto n5 = gate_and(a[1], n12);
  auto n18 = gate_nand(n13, n5);
  auto n16 = gate_xor(n13, n5);
  auto n14 = gate_not(a[0]);
  auto n15 = gate_nand(b[0], n14);
  auto n17 = gate_nand(n16, n15);
  auto n21 = gate_nand(n18, n17);
  auto n20 = gate_nand(b[2], n19);
  auto n25 = gate_nand(n21, n20);
  auto n24 = gate_nand(n1, n6);
  y[0] = gate_nand(n25, n24);
}
template<> void CplainUint<3>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n40 = gate_xor(a[2], b[2]);
  auto n9 = gate_not(a[1]);
  auto n18 = gate_not(a[0]);
  auto n4 = gate_and(n9, n18);
  auto n6 = gate_nand(a[2], n4);
  auto n35 = gate_not(n6);
  auto n27 = gate_not(b[2]);
  auto n7 = gate_xor(b[1], n27);
  auto n34 = gate_nand(n7, b[0]);
  auto n3 = gate_and(n35, n34);
  auto n17 = gate_not(n7);
  auto n14 = gate_nand(n17, n6);
  auto n12 = gate_nand(n7, n3);
  auto n8 = gate_nand(a[0], a[2]);
  auto n15 = gate_xor(n9, n8);
  auto n10 = gate_mux(n27, n15, b[0]);
  auto n11 = gate_not(n10);
  auto n13 = gate_nand(n12, n11);
  auto n25 = gate_nand(n14, n13);
  auto n24 = gate_nand(n3, n25);
  auto n16 = gate_nand(n15, n25);
  auto n22 = gate_nand(n17, n16);
  auto n20 = gate_xor(n17, n16);
  auto n19 = gate_mux(b[2], n18, b[0]);
  auto n21 = gate_nand(n20, n19);
  auto n23 = gate_nand(n22, n21);
  auto n5 = gate_and(n24, n23);
  auto n30 = gate_nand(n40, n5);
  auto n31 = gate_xor(n25, n40);
  y[1] = gate_xor(n30, n31);
  auto n26 = gate_not(b[0]);
  auto n2 = gate_and(n27, n26);
  auto n28 = gate_not(b[1]);
  auto n1 = gate_and(n2, n28);
  auto n29 = gate_nand(n1, n40);
  y[0] = gate_xor(n5, n29);
  auto n33 = gate_not(n30);
  auto n32 = gate_not(n31);
  auto n38 = gate_nand(n33, n32);
  auto n36 = gate_not(n34);
  auto n37 = gate_nand(n36, n35);
  auto n39 = gate_xor(n38, n37);
  y[2] = gate_xor(n40, n39);
}
template<> void CplainUint<3>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_xnor(b[2], a[2]);
  auto n14 = gate_xnor(a[0], b[0]);
  auto n13 = gate_and(n11, n14);
  auto n15 = gate_xnor(a[1], b[1]);
  y[0] = gate_and(n13, n15);
}
template<> void CplainUint<3>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n13 = gate_not(b[2]);
  auto n23 = gate_nand(n13, a[2]);
  auto n21 = gate_xor(n13, a[2]);
  auto n14 = gate_not(b[1]);
  auto n19 = gate_nand(n14, a[1]);
  auto n17 = gate_xor(n14, a[1]);
  auto n15 = gate_not(a[0]);
  auto n16 = gate_nand(b[0], n15);
  auto n18 = gate_nand(n17, n16);
  auto n20 = gate_nand(n19, n18);
  auto n22 = gate_nand(n21, n20);
  y[0] = gate_nand(n23, n22);
}
template<> void CplainUint<3>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n12 = gate_not(b[1]);
  auto n17 = gate_nand(n12, a[1]);
  auto n15 = gate_xor(n12, a[1]);
  auto n13 = gate_not(a[0]);
  auto n14 = gate_nand(b[0], n13);
  auto n16 = gate_nand(n15, n14);
  auto n18 = gate_nand(n17, n16);
  auto n22 = gate_nand(n18, b[2]);
  auto n20 = gate_xor(n18, b[2]);
  auto n19 = gate_not(a[2]);
  auto n21 = gate_nand(n20, n19);
  auto _gte_x_1_n22 = gate_nand(n22, n21);
  y[0] = gate_buf(_gte_x_1_n22);
}
template<> void CplainUint<3>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_not(a[1]);
  auto n20 = gate_nand(n15, b[1]);
  auto n18 = gate_xor(n15, b[1]);
  auto n16 = gate_not(b[0]);
  auto n17 = gate_nand(a[0], n16);
  auto n19 = gate_nand(n18, n17);
  auto n21 = gate_nand(n20, n19);
  auto n25 = gate_nand(n21, b[2]);
  auto n23 = gate_xor(n21, b[2]);
  auto n22 = gate_not(a[2]);
  auto n24 = gate_nand(n23, n22);
  y[0] = gate_and(n25, n24);
}
template<> void CplainUint<3>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_not(b[2]);
  auto n26 = gate_nand(n16, a[2]);
  auto n24 = gate_xor(n16, a[2]);
  auto n17 = gate_not(a[1]);
  auto n22 = gate_nand(n17, b[1]);
  auto n20 = gate_xor(n17, b[1]);
  auto n18 = gate_not(b[0]);
  auto n19 = gate_nand(a[0], n18);
  auto n21 = gate_nand(n20, n19);
  auto n23 = gate_nand(n22, n21);
  auto n25 = gate_nand(n24, n23);
  y[0] = gate_and(n26, n25);
}
template<> void CplainUint<3>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[1] = gate_xor(a[0], a[1]);
  auto n5 = gate_not(a[2]);
  auto n4 = gate_nand(a[0], a[1]);
  y[2] = gate_xor(n5, n4);
  y[0] = gate_not(a[0]);
}
template<> void CplainUint<3>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_xnor(b[2], a[2]);
  auto n11 = gate_xnor(a[0], b[0]);
  auto n10 = gate_and(n9, n11);
  auto n12 = gate_xnor(a[1], b[1]);
  auto _ne_x_1_n7 = gate_nand(n10, n12);
  y[0] = gate_buf(_ne_x_1_n7);
}
template<> void CplainUint<3>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n9 = gate_not(a[0]);
  auto n8 = gate_not(a[1]);
  auto n7 = gate_and(n9, n8);
  auto n10 = gate_not(a[2]);
  auto n11 = gate_nand(n7, n10);
  y[2] = gate_mux(c[2], b[2], n11);
  y[0] = gate_mux(c[0], b[0], n11);
  y[1] = gate_mux(c[1], b[1], n11);
}
template<> void CplainUint<3>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_not(a[1]);
  auto n21 = gate_nand(n16, b[1]);
  auto n19 = gate_xor(n16, b[1]);
  auto n17 = gate_not(b[0]);
  auto n18 = gate_nand(a[0], n17);
  auto n20 = gate_nand(n19, n18);
  auto n22 = gate_nand(n21, n20);
  auto n26 = gate_nand(n22, b[2]);
  auto n24 = gate_xor(n22, b[2]);
  auto n23 = gate_not(a[2]);
  auto n25 = gate_nand(n24, n23);
  auto _lte_x_1_n8 = gate_nand(n26, n25);
  y[0] = gate_buf(_lte_x_1_n8);
}
template<> void CplainUint<3>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(a[1]);
  auto n22 = gate_nand(n17, b[1]);
  auto n20 = gate_xor(n17, b[1]);
  auto n18 = gate_not(b[0]);
  auto n19 = gate_nand(a[0], n18);
  auto n21 = gate_nand(n20, n19);
  auto n23 = gate_nand(n22, n21);
  auto n27 = gate_nand(n23, a[2]);
  auto n25 = gate_xor(n23, a[2]);
  auto n24 = gate_not(b[2]);
  auto n26 = gate_nand(n25, n24);
  y[0] = gate_nand(n27, n26);
}
template<> void CplainUint<3>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n18 = gate_not(a[0]);
  auto n17 = gate_not(a[1]);
  auto n15 = gate_and(n18, n17);
  auto n19 = gate_not(a[2]);
  auto n24 = gate_nand(n15, n19);
  auto n21 = gate_not(b[1]);
  auto n20 = gate_not(b[2]);
  auto n14 = gate_and(n21, n20);
  auto n22 = gate_not(b[0]);
  auto n23 = gate_nand(n14, n22);
  y[0] = gate_and(n24, n23);
}
template<> void CplainUint<3>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n11 = gate_not(a[0]);
  auto n12 = gate_not(a[2]);
  auto n10 = gate_not(a[1]);
  auto n8 = gate_and(n11, n10);
  y[0] = gate_and(n8, n12);
}
template<> void CplainUint<3>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_not(b[0]);
  auto n19 = gate_not(a[1]);
  auto n17 = gate_and(n20, n19);
  auto n22 = gate_not(a[2]);
  auto n21 = gate_not(b[2]);
  auto n18 = gate_and(n22, n21);
  auto n15 = gate_and(n17, n18);
  auto n23 = gate_not(b[1]);
  auto n16 = gate_and(n15, n23);
  auto n24 = gate_not(a[0]);
  y[0] = gate_nand(n16, n24);
}
template<> void CplainUint<3>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_not(b[1]);
  auto n19 = gate_nand(n14, a[1]);
  auto n17 = gate_xor(n14, a[1]);
  auto n15 = gate_not(a[0]);
  auto n16 = gate_nand(b[0], n15);
  auto n18 = gate_nand(n17, n16);
  auto n20 = gate_nand(n19, n18);
  auto n24 = gate_nand(n20, a[2]);
  auto n22 = gate_xor(n20, a[2]);
  auto n21 = gate_not(b[2]);
  auto n23 = gate_nand(n22, n21);
  y[0] = gate_and(n24, n23);
}
template<> void CplainUint<3>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_not(b[1]);
  auto n20 = gate_nand(n15, a[1]);
  auto n18 = gate_xor(n15, a[1]);
  auto n16 = gate_not(a[0]);
  auto n17 = gate_nand(b[0], n16);
  auto n19 = gate_nand(n18, n17);
  auto n21 = gate_nand(n20, n19);
  auto n25 = gate_nand(n21, b[2]);
  auto n23 = gate_xor(n21, b[2]);
  auto n22 = gate_not(a[2]);
  auto n24 = gate_nand(n23, n22);
  y[0] = gate_and(n25, n24);
}
template<> void CplainUint<3>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n19 = gate_not(a[0]);
  auto n9 = gate_not(b[2]);
  auto n12 = gate_not(b[1]);
  auto n1 = gate_and(n9, n12);
  auto n5 = gate_nand(b[0], n1);
  auto n4 = gate_and(a[2], n5);
  auto n6 = gate_mux(b[0], a[2], b[1]);
  auto n3 = gate_and(n9, n6);
  auto n7 = gate_not(a[1]);
  auto n8 = gate_nand(b[0], n7);
  auto n11 = gate_nand(n3, n8);
  auto n2 = gate_and(n4, n11);
  auto n28 = gate_nand(n2, n9);
  auto n10 = gate_not(a[2]);
  auto n16 = gate_nand(b[2], n10);
  auto n24 = gate_nand(a[1], n11);
  auto n13 = gate_not(n24);
  auto n15 = gate_nand(n13, n12);
  auto n20 = gate_xor(b[1], n24);
  auto n21 = gate_nand(b[0], n19);
  auto n14 = gate_nand(n20, n21);
  auto n29 = gate_nand(n15, n14);
  auto n17 = gate_nand(n16, n29);
  auto n26 = gate_nand(n28, n17);
  auto n18 = gate_nand(n26, b[0]);
  y[0] = gate_xor(n19, n18);
  auto n22 = gate_not(n20);
  auto n23 = gate_nand(n22, n21);
  auto n25 = gate_mux(n24, n23, n26);
  y[1] = gate_not(n25);
  auto n27 = gate_not(n26);
  auto n32 = gate_nand(n2, n27);
  auto n30 = gate_not(n28);
  auto n31 = gate_nand(n30, n29);
  y[2] = gate_nand(n32, n31);
}
template<> void CplainUint<3>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n5 = gate_xnor(b[2], b[1]);
  auto n6 = gate_nand(a[0], a[2]);
  auto n4 = gate_xnor(a[1], n6);
  auto n7 = gate_nand(n5, b[0]);
  auto n22 = gate_nand(n4, n7);
  auto n8 = gate_not(b[2]);
  auto n11 = gate_mux(n8, a[0], b[0]);
  auto n10 = gate_xor(n22, n5);
  auto n21 = gate_nand(n11, n10);
  auto n9 = gate_not(n22);
  auto n14 = gate_nand(n9, n5);
  auto n12 = gate_not(n10);
  auto n13 = gate_nand(n12, n11);
  auto n31 = gate_nand(n14, n13);
  auto n20 = gate_not(n31);
  auto n15 = gate_not(a[0]);
  auto n3 = gate_and(a[2], n15);
  auto n16 = gate_not(a[1]);
  auto n2 = gate_and(n3, n16);
  auto n17 = gate_not(b[0]);
  auto n18 = gate_mux(n17, b[0], n5);
  auto n19 = gate_not(n18);
  auto n30 = gate_nand(n2, n19);
  auto n23 = gate_nand(n20, n30);
  auto n28 = gate_mux(n22, n21, n23);
  auto n25 = gate_xor(a[2], a[0]);
  auto n24 = gate_nand(b[0], n23);
  auto n27 = gate_xor(n25, n24);
  auto n26 = gate_nand(n27, a[2]);
  y[1] = gate_xor(n28, n26);
  auto n29 = gate_not(n27);
  auto n1 = gate_and(a[2], n29);
  y[0] = gate_xor(a[2], n29);
  auto n35 = gate_nand(n28, n1);
  auto n32 = gate_not(n30);
  auto n33 = gate_nand(n32, n31);
  auto n34 = gate_nand(a[2], n33);
  y[2] = gate_xor(n35, n34);
}
template<> void CplainUint<3>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_and(a[1], b[1]);
  auto n2 = gate_and(b[2], a[0]);
  auto n6 = gate_nand(b[0], a[0]);
  y[0] = gate_not(n6);
  auto n4 = gate_nand(b[1], a[0]);
  auto n3 = gate_nand(a[1], b[0]);
  y[1] = gate_xor(n4, n3);
  auto n5 = gate_nand(a[2], b[0]);
  auto n8 = gate_xor(n2, n5);
  auto n7 = gate_nand(n6, n1);
  y[2] = gate_xor(n8, n7);
}
template<> void CplainUint<3>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n5 = gate_and(a[0], a[1]);
  y[0] = gate_and(a[2], n5);
}
template<> void CplainUint<3>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n4 = gate_and(a[0], a[1]);
  y[0] = gate_nand(a[2], n4);
}
template<> void CplainUint<3>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n11 = gate_not(a[0]);
  auto n12 = gate_not(a[2]);
  auto n10 = gate_not(a[1]);
  auto n8 = gate_and(n11, n10);
  y[0] = gate_and(n8, n12);
}
template<> void CplainUint<3>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n8 = gate_not(a[0]);
  auto n7 = gate_not(a[1]);
  auto n6 = gate_and(n8, n7);
  auto n9 = gate_not(a[2]);
  y[0] = gate_nand(n6, n9);
}
template<> void CplainUint<3>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n5 = gate_xor(a[1], a[2]);
  y[0] = gate_xnor(a[0], n5);
}
template<> void CplainUint<3>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n2 = gate_xor(a[2], a[0]);
  y[0] = gate_xor(a[1], n2);
}
template<> void CplainUint<3>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_not(b[0]);
  auto n25 = gate_and(a[0], n27);
  auto n32 = gate_not(b[2]);
  auto n28 = gate_not(b[1]);
  auto n23 = gate_and(n32, n28);
  y[0] = gate_and(n25, n23);
  auto n29 = gate_mux(a[1], a[0], b[0]);
  y[1] = gate_and(n23, n29);
  auto n30 = gate_mux(a[2], a[1], b[0]);
  auto n31 = gate_mux(n30, n25, b[1]);
  y[2] = gate_and(n32, n31);
}
template<> void CplainUint<3>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n24 = gate_not(b[2]);
  auto n25 = gate_mux(a[1], a[2], b[0]);
  auto n21 = gate_mux(a[0], a[1], b[0]);
  auto n20 = gate_not(b[0]);
  auto n19 = gate_and(a[2], n20);
  auto n22 = gate_mux(n21, n19, b[1]);
  y[0] = gate_and(n24, n22);
  auto n23 = gate_not(b[1]);
  auto n15 = gate_and(n24, n23);
  y[2] = gate_and(n19, n15);
  y[1] = gate_and(n15, n25);
}
template<> void CplainUint<3>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_buf(a[2]);
  auto n10 = gate_mux(a[0], a[1], b[0]);
  auto n9 = gate_not(b[1]);
  auto n8 = gate_not(b[2]);
  auto n11 = gate_nand(n9, n8);
  y[0] = gate_mux(n10, a[2], n11);
  auto n13 = gate_not(n11);
  auto n12 = gate_not(b[0]);
  auto n14 = gate_nand(n13, n12);
  y[1] = gate_mux(a[1], a[2], n14);
}
template<> void CplainUint<3>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n17 = gate_xor(b[2], a[2]);
  auto n12 = gate_not(b[1]);
  auto n14 = gate_xor(a[1], n12);
  auto n11 = gate_not(a[0]);
  auto n13 = gate_nand(b[0], n11);
  y[1] = gate_xor(n14, n13);
  auto n16 = gate_nand(a[1], n12);
  auto n15 = gate_nand(n14, n13);
  auto n18 = gate_nand(n16, n15);
  y[2] = gate_xnor(n18, n17);
}
template<> void CplainUint<3>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  y[1] = gate_xor(a[1], a[0]);
  auto n5 = gate_not(a[1]);
  auto n4 = gate_not(a[0]);
  auto n6 = gate_nand(n5, n4);
  y[2] = gate_xor(a[2], n6);
}
template<> void CplainUint<4>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n12 = gate_and(b[0], a[0]);
  auto _add_x_1_n12 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n12);
  auto n13 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n12, n13);
  auto n17 = gate_xor(b[2], a[2]);
  auto n15 = gate_nand(b[1], a[1]);
  auto n14 = gate_nand(n12, n13);
  auto n16 = gate_nand(n15, n14);
  y[2] = gate_xor(n17, n16);
  auto n19 = gate_nand(n17, n16);
  auto n18 = gate_nand(b[2], a[2]);
  auto n20 = gate_nand(n19, n18);
  auto n21 = gate_xor(b[3], n20);
  y[3] = gate_xor(a[3], n21);
}
template<> void CplainUint<4>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_and(b[3], a[3]);
  y[0] = gate_and(b[0], a[0]);
  y[1] = gate_and(b[1], a[1]);
  y[2] = gate_and(b[2], a[2]);
}
template<> void CplainUint<4>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[3] = gate_not(a[3]);
  y[2] = gate_not(a[2]);
  y[1] = gate_not(a[1]);
  y[0] = gate_not(a[0]);
}
template<> void CplainUint<4>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_not(b[3]);
  auto n9 = gate_not(a[3]);
  y[3] = gate_nand(n10, n9);
  auto n12 = gate_not(b[2]);
  auto n11 = gate_not(a[2]);
  y[2] = gate_nand(n12, n11);
  auto n14 = gate_not(b[1]);
  auto n13 = gate_not(a[1]);
  y[1] = gate_nand(n14, n13);
  auto n16 = gate_not(b[0]);
  auto n15 = gate_not(a[0]);
  y[0] = gate_nand(n16, n15);
}
template<> void CplainUint<4>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  y[3] = gate_buf(zero);
  auto N0 = gate_buf(a[0]);
  auto n15 = gate_nand(a[1], a[2]);
  auto n13 = gate_not(n15);
  auto n17 = gate_nand(N0, a[3]);
  auto n12 = gate_not(n17);
  y[2] = gate_and(n13, n12);
  auto n19 = gate_xor(a[1], a[2]);
  auto n18 = gate_xor(N0, a[3]);
  auto n14 = gate_nand(n19, n18);
  auto n16 = gate_nand(n17, n14);
  y[1] = gate_mux(n17, n16, n15);
  y[0] = gate_xor(n19, n18);
}
template<> void CplainUint<4>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_xor(b[3], a[3]);
  y[2] = gate_xor(b[2], a[2]);
  y[1] = gate_xor(b[1], a[1]);
  y[0] = gate_xor(b[0], a[0]);
}
template<> void CplainUint<4>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_and(a[0], b[3]);
  y[2] = gate_and(a[0], b[2]);
  y[1] = gate_and(a[0], b[1]);
  y[0] = gate_and(a[0], b[0]);
}
template<> void CplainUint<4>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
  y[1] = gate_mux(c[1], b[1], a[0]);
  y[2] = gate_mux(c[2], b[2], a[0]);
  y[3] = gate_mux(c[3], b[3], a[0]);
}
template<> void CplainUint<4>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_and(b[0], a[0]);
  auto n11 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n11, n10);
  auto n15 = gate_xor(b[2], a[2]);
  auto n13 = gate_nand(b[1], a[1]);
  auto n12 = gate_nand(n11, n10);
  auto n14 = gate_nand(n13, n12);
  y[2] = gate_xor(n15, n14);
  auto _add_x_1_n12 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n12);
  auto n17 = gate_nand(b[2], a[2]);
  auto n16 = gate_nand(n15, n14);
  auto _add_x_1_n14 = gate_nand(n17, n16);
  y[3] = gate_buf(_add_x_1_n14);
}
template<> void CplainUint<4>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n9 = gate_not(a[1]);
  y[1] = gate_xor(a[0], n9);
  y[0] = gate_not(a[0]);
  auto n7 = gate_and(y[0], n9);
  y[2] = gate_xor(a[2], n7);
  auto n10 = gate_not(a[2]);
  auto n8 = gate_and(n7, n10);
  y[3] = gate_xor(n8, a[3]);
}
template<> void CplainUint<4>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n31 = gate_not(b[1]);
  auto n47 = gate_not(b[3]);
  auto n40 = gate_not(b[2]);
  auto n2 = gate_and(n47, n40);
  auto n1 = gate_and(n31, n2);
  auto n22 = gate_not(a[3]);
  auto n7 = gate_nand(b[0], n22);
  auto n17 = gate_nand(n1, n7);
  auto n5 = gate_and(a[3], n17);
  y[3] = gate_not(n17);
  auto n8 = gate_not(a[2]);
  auto n9 = gate_nand(b[0], n8);
  auto n3 = gate_and(n9, n2);
  auto n10 = gate_nand(b[1], n22);
  auto n18 = gate_nand(n3, n10);
  auto n4 = gate_and(n5, n18);
  y[2] = gate_not(n18);
  auto n16 = gate_nand(n22, b[2]);
  auto n11 = gate_nand(y[2], b[0]);
  auto n27 = gate_nand(a[2], n11);
  auto n12 = gate_not(n27);
  auto n14 = gate_nand(n12, n31);
  auto n23 = gate_xor(b[1], n27);
  auto n30 = gate_not(a[1]);
  auto n24 = gate_nand(b[0], n30);
  auto n13 = gate_nand(n23, n24);
  auto n15 = gate_nand(n14, n13);
  auto n20 = gate_nand(n16, n15);
  auto n19 = gate_nand(n40, n4);
  auto n21 = gate_nand(n20, n19);
  auto n46 = gate_nand(n47, n21);
  auto n6 = gate_and(n4, n46);
  y[1] = gate_not(n46);
  auto n45 = gate_nand(n22, b[3]);
  auto n25 = gate_not(n23);
  auto n26 = gate_nand(n25, n24);
  auto n28 = gate_mux(n27, n26, y[1]);
  auto n39 = gate_not(n28);
  auto n29 = gate_nand(y[1], b[0]);
  auto n32 = gate_xor(n30, n29);
  auto n37 = gate_nand(n32, n31);
  auto n35 = gate_xor(n32, n31);
  auto n33 = gate_not(a[0]);
  auto n34 = gate_nand(b[0], n33);
  auto n36 = gate_nand(n35, n34);
  auto n38 = gate_nand(n37, n36);
  auto n43 = gate_nand(n39, n38);
  auto n41 = gate_xor(n39, n38);
  auto n42 = gate_nand(n41, n40);
  auto n44 = gate_nand(n43, n42);
  auto n49 = gate_nand(n45, n44);
  auto n48 = gate_nand(n47, n6);
  y[0] = gate_nand(n49, n48);
}
template<> void CplainUint<4>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n61 = gate_not(b[3]);
  auto n56 = gate_xor(a[3], n61);
  auto n46 = gate_xor(b[2], b[3]);
  auto n43 = gate_not(n46);
  auto n20 = gate_not(a[1]);
  auto n8 = gate_not(a[0]);
  auto n11 = gate_nand(n20, n8);
  auto n9 = gate_not(n11);
  auto n13 = gate_not(a[2]);
  auto n6 = gate_and(a[3], n13);
  auto n21 = gate_nand(n9, n6);
  auto n10 = gate_not(n21);
  auto n38 = gate_xor(b[1], b[3]);
  auto n36 = gate_not(n38);
  auto n1 = gate_and(n43, n36);
  auto n4 = gate_and(n1, b[0]);
  auto n67 = gate_nand(n10, n4);
  auto n3 = gate_and(n10, n67);
  auto n17 = gate_nand(n3, n36);
  auto n12 = gate_nand(a[3], n11);
  auto n22 = gate_xor(n13, n12);
  auto n60 = gate_not(b[0]);
  auto n2 = gate_and(n61, n60);
  auto n15 = gate_mux(n22, n61, n60);
  auto n14 = gate_nand(n38, n21);
  auto n16 = gate_nand(n15, n14);
  auto n18 = gate_nand(n17, n16);
  auto n29 = gate_nand(n43, n18);
  auto n5 = gate_and(n22, n29);
  auto n66 = gate_xor(n56, n29);
  auto n68 = gate_not(n56);
  auto n19 = gate_nand(a[3], a[0]);
  auto n34 = gate_xor(n20, n19);
  auto n28 = gate_nand(n21, n46);
  auto n23 = gate_mux(n34, n61, n60);
  auto n26 = gate_nand(n23, n5);
  auto n24 = gate_xor(n23, n5);
  auto n25 = gate_nand(n24, n36);
  auto n27 = gate_nand(n26, n25);
  auto n32 = gate_nand(n28, n27);
  auto n48 = gate_nand(n3, n29);
  auto n30 = gate_not(n48);
  auto n31 = gate_nand(n43, n30);
  auto n50 = gate_nand(n32, n31);
  auto n33 = gate_nand(b[0], n50);
  auto n37 = gate_nand(n34, n33);
  auto n35 = gate_not(n37);
  auto n42 = gate_nand(n36, n35);
  auto n40 = gate_xor(n38, n37);
  auto n39 = gate_mux(a[0], n61, n60);
  auto n41 = gate_nand(n40, n39);
  auto n44 = gate_nand(n42, n41);
  auto n53 = gate_nand(n44, n43);
  auto n45 = gate_not(n44);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n47, n5);
  auto n51 = gate_nand(n49, n48);
  auto n55 = gate_not(n50);
  auto n52 = gate_nand(n51, n55);
  auto n59 = gate_nand(n53, n52);
  auto n54 = gate_not(n59);
  auto n65 = gate_nand(n68, n54);
  auto n58 = gate_not(n65);
  auto n57 = gate_xor(n56, n55);
  auto n7 = gate_and(n58, n57);
  y[2] = gate_xor(n66, n7);
  y[1] = gate_xor(n58, n57);
  auto n64 = gate_xor(n59, n68);
  auto n62 = gate_nand(n2, n1);
  auto n63 = gate_nand(n68, n62);
  y[0] = gate_mux(n65, n64, n63);
  auto n70 = gate_nand(n66, n7);
  auto n69 = gate_xor(n68, n67);
  y[3] = gate_xor(n70, n69);
}
template<> void CplainUint<4>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_xnor(a[1], b[1]);
  auto n18 = gate_not(b[2]);
  auto n23 = gate_xor(n18, a[2]);
  auto n19 = gate_not(a[3]);
  auto n22 = gate_xor(n19, b[3]);
  auto n20 = gate_not(a[0]);
  auto n21 = gate_xor(n20, b[0]);
  auto n15 = gate_and(n22, n21);
  auto n14 = gate_and(n15, n16);
  y[0] = gate_and(n23, n14);
}
template<> void CplainUint<4>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(b[3]);
  auto n32 = gate_nand(n17, a[3]);
  auto n30 = gate_xor(n17, a[3]);
  auto n18 = gate_not(b[1]);
  auto n23 = gate_nand(n18, a[1]);
  auto n21 = gate_xor(n18, a[1]);
  auto n19 = gate_not(a[0]);
  auto n20 = gate_nand(b[0], n19);
  auto n22 = gate_nand(n21, n20);
  auto n24 = gate_nand(n23, n22);
  auto n28 = gate_nand(n24, a[2]);
  auto n26 = gate_xor(n24, a[2]);
  auto n25 = gate_not(b[2]);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n31 = gate_nand(n30, n29);
  auto _gte_x_1_n29 = gate_nand(n32, n31);
  y[0] = gate_buf(_gte_x_1_n29);
}
template<> void CplainUint<4>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(a[3]);
  auto n32 = gate_nand(n17, b[3]);
  auto n30 = gate_xor(n17, b[3]);
  auto n18 = gate_not(b[1]);
  auto n23 = gate_nand(n18, a[1]);
  auto n21 = gate_xor(n18, a[1]);
  auto n19 = gate_not(a[0]);
  auto n20 = gate_nand(b[0], n19);
  auto n22 = gate_nand(n21, n20);
  auto n24 = gate_nand(n23, n22);
  auto n28 = gate_nand(n24, a[2]);
  auto n26 = gate_xor(n24, a[2]);
  auto n25 = gate_not(b[2]);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n31 = gate_nand(n30, n29);
  auto _gte_x_1_n29 = gate_nand(n32, n31);
  y[0] = gate_buf(_gte_x_1_n29);
}
template<> void CplainUint<4>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n23 = gate_not(a[1]);
  auto n28 = gate_nand(n23, b[1]);
  auto n26 = gate_xor(n23, b[1]);
  auto n24 = gate_not(b[0]);
  auto n25 = gate_nand(a[0], n24);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n33 = gate_nand(n29, b[2]);
  auto n31 = gate_xor(n29, b[2]);
  auto n30 = gate_not(a[2]);
  auto n32 = gate_nand(n31, n30);
  auto n22 = gate_and(n33, n32);
  auto n37 = gate_nand(a[3], n22);
  auto n35 = gate_xor(a[3], n22);
  auto n34 = gate_not(b[3]);
  auto n36 = gate_nand(n35, n34);
  auto _gt_x_1_n29 = gate_nand(n37, n36);
  y[0] = gate_buf(_gt_x_1_n29);
}
template<> void CplainUint<4>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n23 = gate_not(a[1]);
  auto n28 = gate_nand(n23, b[1]);
  auto n26 = gate_xor(n23, b[1]);
  auto n24 = gate_not(b[0]);
  auto n25 = gate_nand(a[0], n24);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n33 = gate_nand(n29, b[2]);
  auto n31 = gate_xor(n29, b[2]);
  auto n30 = gate_not(a[2]);
  auto n32 = gate_nand(n31, n30);
  auto n22 = gate_and(n33, n32);
  auto n37 = gate_nand(b[3], n22);
  auto n35 = gate_xor(b[3], n22);
  auto n34 = gate_not(a[3]);
  auto n36 = gate_nand(n35, n34);
  auto _gt_x_1_n29 = gate_nand(n37, n36);
  y[0] = gate_buf(_gt_x_1_n29);
}
template<> void CplainUint<4>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_and(a[0], a[1]);
  y[2] = gate_xor(n6, a[2]);
  auto n5 = gate_and(n6, a[2]);
  y[1] = gate_xor(a[0], a[1]);
  y[0] = gate_not(a[0]);
  y[3] = gate_xor(n5, a[3]);
}
template<> void CplainUint<4>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_xnor(a[1], b[1]);
  auto n17 = gate_not(b[2]);
  auto n22 = gate_xor(n17, a[2]);
  auto n18 = gate_not(a[3]);
  auto n21 = gate_xor(n18, b[3]);
  auto n19 = gate_not(a[0]);
  auto n20 = gate_xor(n19, b[0]);
  auto n15 = gate_and(n21, n20);
  auto n14 = gate_and(n15, n16);
  y[0] = gate_nand(n22, n14);
}
template<> void CplainUint<4>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n13 = gate_not(a[1]);
  auto n12 = gate_not(a[3]);
  auto n11 = gate_and(n13, n12);
  auto n15 = gate_not(a[2]);
  auto n14 = gate_not(a[0]);
  auto n10 = gate_and(n15, n14);
  auto n16 = gate_nand(n11, n10);
  y[3] = gate_mux(c[3], b[3], n16);
  y[0] = gate_mux(c[0], b[0], n16);
  y[1] = gate_mux(c[1], b[1], n16);
  y[2] = gate_mux(c[2], b[2], n16);
}
template<> void CplainUint<4>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(a[3]);
  auto n37 = gate_nand(n22, b[3]);
  auto n35 = gate_xor(n22, b[3]);
  auto n23 = gate_not(a[1]);
  auto n28 = gate_nand(n23, b[1]);
  auto n26 = gate_xor(n23, b[1]);
  auto n24 = gate_not(b[0]);
  auto n25 = gate_nand(a[0], n24);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n33 = gate_nand(n29, b[2]);
  auto n31 = gate_xor(n29, b[2]);
  auto n30 = gate_not(a[2]);
  auto n32 = gate_nand(n31, n30);
  auto n34 = gate_nand(n33, n32);
  auto n36 = gate_nand(n35, n34);
  y[0] = gate_nand(n37, n36);
}
template<> void CplainUint<4>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(b[3]);
  auto n37 = gate_nand(n22, a[3]);
  auto n35 = gate_xor(n22, a[3]);
  auto n23 = gate_not(a[1]);
  auto n28 = gate_nand(n23, b[1]);
  auto n26 = gate_xor(n23, b[1]);
  auto n24 = gate_not(b[0]);
  auto n25 = gate_nand(a[0], n24);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n33 = gate_nand(n29, b[2]);
  auto n31 = gate_xor(n29, b[2]);
  auto n30 = gate_not(a[2]);
  auto n32 = gate_nand(n31, n30);
  auto n34 = gate_nand(n33, n32);
  auto n36 = gate_nand(n35, n34);
  y[0] = gate_nand(n37, n36);
}
template<> void CplainUint<4>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n26 = gate_not(a[1]);
  auto n25 = gate_not(a[3]);
  auto n24 = gate_and(n26, n25);
  auto n28 = gate_not(a[2]);
  auto n27 = gate_not(a[0]);
  auto n23 = gate_and(n28, n27);
  auto n34 = gate_nand(n24, n23);
  auto n30 = gate_not(b[1]);
  auto n29 = gate_not(b[3]);
  auto n22 = gate_and(n30, n29);
  auto n32 = gate_not(b[2]);
  auto n31 = gate_not(b[0]);
  auto n21 = gate_and(n32, n31);
  auto n33 = gate_nand(n22, n21);
  y[0] = gate_and(n34, n33);
}
template<> void CplainUint<4>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n15 = gate_not(a[1]);
  auto n16 = gate_not(a[0]);
  auto n14 = gate_not(a[3]);
  auto n13 = gate_and(n15, n14);
  auto n17 = gate_not(a[2]);
  auto n12 = gate_and(n17, n16);
  y[0] = gate_and(n13, n12);
}
template<> void CplainUint<4>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n28 = gate_not(a[1]);
  auto n27 = gate_not(a[3]);
  auto n26 = gate_and(n28, n27);
  auto n30 = gate_not(a[2]);
  auto n29 = gate_not(a[0]);
  auto n25 = gate_and(n30, n29);
  auto n22 = gate_and(n26, n25);
  auto n32 = gate_not(b[1]);
  auto n31 = gate_not(b[3]);
  auto n24 = gate_and(n32, n31);
  auto n34 = gate_not(b[2]);
  auto n33 = gate_not(b[0]);
  auto n23 = gate_and(n34, n33);
  auto n21 = gate_and(n24, n23);
  y[0] = gate_nand(n22, n21);
}
template<> void CplainUint<4>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_not(b[3]);
  auto n35 = gate_nand(n20, a[3]);
  auto n33 = gate_xor(n20, a[3]);
  auto n21 = gate_not(b[1]);
  auto n26 = gate_nand(n21, a[1]);
  auto n24 = gate_xor(n21, a[1]);
  auto n22 = gate_not(a[0]);
  auto n23 = gate_nand(b[0], n22);
  auto n25 = gate_nand(n24, n23);
  auto n27 = gate_nand(n26, n25);
  auto n31 = gate_nand(n27, a[2]);
  auto n29 = gate_xor(n27, a[2]);
  auto n28 = gate_not(b[2]);
  auto n30 = gate_nand(n29, n28);
  auto n32 = gate_nand(n31, n30);
  auto n34 = gate_nand(n33, n32);
  y[0] = gate_and(n35, n34);
}
template<> void CplainUint<4>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_not(a[3]);
  auto n35 = gate_nand(n20, b[3]);
  auto n33 = gate_xor(n20, b[3]);
  auto n21 = gate_not(b[1]);
  auto n26 = gate_nand(n21, a[1]);
  auto n24 = gate_xor(n21, a[1]);
  auto n22 = gate_not(a[0]);
  auto n23 = gate_nand(b[0], n22);
  auto n25 = gate_nand(n24, n23);
  auto n27 = gate_nand(n26, n25);
  auto n31 = gate_nand(n27, a[2]);
  auto n29 = gate_xor(n27, a[2]);
  auto n28 = gate_not(b[2]);
  auto n30 = gate_nand(n29, n28);
  auto n32 = gate_nand(n31, n30);
  auto n34 = gate_nand(n33, n32);
  y[0] = gate_and(n35, n34);
}
template<> void CplainUint<4>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n44 = gate_not(b[3]);
  auto n29 = gate_not(b[2]);
  auto n3 = gate_and(n44, n29);
  auto n33 = gate_not(b[1]);
  auto n2 = gate_and(n3, n33);
  auto n8 = gate_nand(b[0], n2);
  auto n6 = gate_and(a[3], n8);
  auto n9 = gate_mux(a[3], b[0], n33);
  auto n5 = gate_and(n3, n9);
  auto n10 = gate_not(a[2]);
  auto n11 = gate_nand(b[0], n10);
  auto n12 = gate_nand(n5, n11);
  auto n38 = gate_nand(n6, n12);
  auto n21 = gate_not(n38);
  auto n28 = gate_nand(a[2], n12);
  auto n13 = gate_not(n28);
  auto n16 = gate_nand(n13, n33);
  auto n19 = gate_xor(n33, n28);
  auto n14 = gate_not(n19);
  auto n32 = gate_not(a[1]);
  auto n20 = gate_nand(b[0], n32);
  auto n15 = gate_nand(n14, n20);
  auto n22 = gate_nand(n16, n15);
  auto n17 = gate_xor(n29, n22);
  auto n18 = gate_nand(n44, n17);
  auto n1 = gate_and(n21, n18);
  auto n27 = gate_nand(n20, n19);
  auto n25 = gate_nand(n22, n21);
  auto n23 = gate_xor(n22, n21);
  auto n24 = gate_nand(n23, n29);
  auto n26 = gate_nand(n25, n24);
  auto n4 = gate_and(n44, n26);
  auto n30 = gate_mux(n28, n27, n4);
  auto n48 = gate_not(n30);
  auto n37 = gate_nand(n29, n48);
  auto n43 = gate_xor(b[2], n30);
  auto n31 = gate_nand(n4, b[0]);
  auto n52 = gate_xor(n32, n31);
  auto n35 = gate_nand(n33, n52);
  auto n50 = gate_xor(n33, n52);
  auto n55 = gate_not(a[0]);
  auto n49 = gate_nand(b[0], n55);
  auto n34 = gate_nand(n50, n49);
  auto n42 = gate_nand(n35, n34);
  auto n36 = gate_nand(n43, n42);
  auto n40 = gate_nand(n37, n36);
  auto n39 = gate_nand(b[3], n38);
  auto n46 = gate_nand(n40, n39);
  auto n41 = gate_mux(n46, n40, n44);
  y[3] = gate_and(n1, n41);
  auto n47 = gate_xor(n43, n42);
  auto n45 = gate_nand(n44, n1);
  auto n53 = gate_nand(n46, n45);
  y[2] = gate_mux(n48, n47, n53);
  auto n51 = gate_xor(n50, n49);
  y[1] = gate_mux(n52, n51, n53);
  auto n54 = gate_nand(n53, b[0]);
  y[0] = gate_xor(n55, n54);
}
template<> void CplainUint<4>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n69 = gate_not(a[3]);
  auto n12 = gate_not(a[2]);
  auto n9 = gate_not(a[1]);
  auto n56 = gate_not(a[0]);
  auto n13 = gate_nand(n9, n56);
  auto n10 = gate_nand(a[3], n13);
  auto n20 = gate_xor(n12, n10);
  auto n47 = gate_xor(b[2], b[3]);
  auto n46 = gate_not(n47);
  auto n37 = gate_not(b[3]);
  auto n60 = gate_xor(n37, b[1]);
  auto n5 = gate_and(b[0], n60);
  auto n11 = gate_nand(n5, n46);
  auto n3 = gate_and(n12, n11);
  auto n14 = gate_not(n13);
  auto n8 = gate_and(n14, a[3]);
  auto n2 = gate_and(n3, n8);
  auto n15 = gate_xor(n60, n2);
  auto n1 = gate_and(n46, n15);
  auto n36 = gate_not(b[0]);
  auto n16 = gate_not(n20);
  auto n17 = gate_nand(b[0], n16);
  auto n23 = gate_nand(n1, n17);
  auto n4 = gate_and(n2, n23);
  auto n18 = gate_not(n23);
  auto n19 = gate_nand(n18, b[0]);
  auto n32 = gate_nand(n20, n19);
  auto n21 = gate_nand(a[3], a[0]);
  auto n35 = gate_xor(a[1], n21);
  auto n22 = gate_mux(n35, b[3], n36);
  auto n26 = gate_not(n22);
  auto n25 = gate_xor(n32, n60);
  auto n31 = gate_nand(n26, n25);
  auto n43 = gate_nand(n4, n46);
  auto n24 = gate_not(n32);
  auto n29 = gate_nand(n24, n60);
  auto n27 = gate_not(n25);
  auto n28 = gate_nand(n27, n26);
  auto n42 = gate_nand(n29, n28);
  auto n30 = gate_nand(n46, n42);
  auto n33 = gate_nand(n43, n30);
  auto n54 = gate_mux(n32, n31, n33);
  auto n34 = gate_nand(b[0], n33);
  auto n64 = gate_xor(n35, n34);
  auto n40 = gate_nand(n64, n60);
  auto n38 = gate_xor(n64, n60);
  auto n59 = gate_mux(a[0], n37, n36);
  auto n39 = gate_nand(n38, n59);
  auto n48 = gate_nand(n40, n39);
  auto n41 = gate_xor(n54, n46);
  auto n53 = gate_nand(n48, n41);
  auto n44 = gate_nand(n47, n2);
  auto n71 = gate_mux(n44, n43, n42);
  auto n45 = gate_not(n54);
  auto n51 = gate_nand(n46, n45);
  auto n49 = gate_xor(n47, n54);
  auto n50 = gate_nand(n49, n48);
  auto n73 = gate_nand(n51, n50);
  auto n52 = gate_not(n73);
  auto n62 = gate_nand(n71, n52);
  auto n55 = gate_mux(n54, n53, n62);
  auto n70 = gate_xor(n69, n55);
  auto n58 = gate_xor(a[3], n56);
  auto n57 = gate_nand(b[0], n62);
  auto n65 = gate_xor(n58, n57);
  auto n6 = gate_and(a[3], n65);
  auto n61 = gate_xor(n60, n59);
  auto n63 = gate_nand(n62, n61);
  auto n67 = gate_xor(n64, n63);
  auto n7 = gate_and(n6, n67);
  y[2] = gate_xor(n70, n7);
  auto n68 = gate_not(n65);
  auto n66 = gate_nand(a[3], n68);
  y[1] = gate_xor(n67, n66);
  y[0] = gate_xor(n69, n68);
  auto n76 = gate_nand(n70, n7);
  auto n72 = gate_not(n71);
  auto n74 = gate_nand(n73, n72);
  auto n75 = gate_nand(a[3], n74);
  y[3] = gate_xor(n76, n75);
}
template<> void CplainUint<4>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_and(a[2], b[0]);
  y[0] = gate_and(a[0], b[0]);
  auto n4 = gate_and(a[1], b[2]);
  auto n5 = gate_and(a[1], b[0]);
  auto n17 = gate_nand(a[0], b[1]);
  auto n8 = gate_not(n17);
  auto n2 = gate_and(n8, n5);
  y[1] = gate_xor(n8, n5);
  auto n7 = gate_nand(a[1], b[1]);
  auto n6 = gate_nand(b[2], a[0]);
  auto n10 = gate_xor(n7, n6);
  auto n9 = gate_xor(n10, n1);
  y[2] = gate_xor(n9, n2);
  auto n14 = gate_nand(a[0], b[3]);
  auto n12 = gate_nand(n9, n2);
  auto n11 = gate_nand(n10, n1);
  auto n13 = gate_nand(n12, n11);
  auto n21 = gate_xor(n14, n13);
  auto n16 = gate_nand(a[3], b[0]);
  auto n15 = gate_nand(a[2], b[1]);
  auto n19 = gate_xor(n16, n15);
  auto n18 = gate_nand(n17, n4);
  auto n20 = gate_xor(n19, n18);
  y[3] = gate_xor(n21, n20);
}
template<> void CplainUint<4>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_and(a[1], a[3]);
  auto n8 = gate_and(a[2], a[0]);
  y[0] = gate_and(n6, n8);
}
template<> void CplainUint<4>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_and(a[1], a[3]);
  auto n7 = gate_and(a[2], a[0]);
  y[0] = gate_nand(n6, n7);
}
template<> void CplainUint<4>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n15 = gate_not(a[1]);
  auto n16 = gate_not(a[0]);
  auto n14 = gate_not(a[3]);
  auto n13 = gate_and(n15, n14);
  auto n17 = gate_not(a[2]);
  auto n12 = gate_and(n17, n16);
  y[0] = gate_and(n13, n12);
}
template<> void CplainUint<4>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n12 = gate_not(a[1]);
  auto n11 = gate_not(a[3]);
  auto n10 = gate_and(n12, n11);
  auto n14 = gate_not(a[2]);
  auto n13 = gate_not(a[0]);
  auto n9 = gate_and(n14, n13);
  y[0] = gate_nand(n10, n9);
}
template<> void CplainUint<4>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n5 = gate_not(a[0]);
  auto n7 = gate_xor(n5, a[1]);
  auto n6 = gate_xor(a[2], a[3]);
  y[0] = gate_xor(n7, n6);
}
template<> void CplainUint<4>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n4 = gate_xor(a[0], a[1]);
  auto n3 = gate_xor(a[3], a[2]);
  y[0] = gate_xor(n4, n3);
}
template<> void CplainUint<4>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n42 = gate_not(b[2]);
  auto n41 = gate_not(b[3]);
  auto n37 = gate_and(n42, n41);
  auto n40 = gate_and(n37, b[1]);
  auto n44 = gate_not(b[1]);
  auto n36 = gate_and(n37, n44);
  auto n46 = gate_not(b[0]);
  auto n35 = gate_and(n36, n46);
  y[0] = gate_and(a[0], n35);
  auto n43 = gate_mux(a[0], a[1], n46);
  y[1] = gate_and(n36, n43);
  auto n47 = gate_nand(a[1], n36);
  auto n45 = gate_mux(a[0], a[2], n44);
  auto n49 = gate_nand(n37, n45);
  auto n48 = gate_mux(n47, n49, n46);
  y[2] = gate_not(n48);
  auto n50 = gate_nand(n40, a[1]);
  auto n52 = gate_mux(n50, n49, b[0]);
  auto n51 = gate_nand(a[3], n35);
  y[3] = gate_nand(n52, n51);
}
template<> void CplainUint<4>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n29 = gate_not(b[3]);
  auto n28 = gate_not(b[2]);
  auto n23 = gate_and(n29, n28);
  auto n34 = gate_not(b[1]);
  auto n25 = gate_and(n23, n34);
  auto n26 = gate_and(a[3], n25);
  auto n30 = gate_mux(a[3], a[1], n34);
  auto n35 = gate_nand(n23, n30);
  auto n31 = gate_mux(a[2], a[0], n34);
  auto n32 = gate_nand(n31, n23);
  auto n39 = gate_not(b[0]);
  auto n38 = gate_mux(a[3], a[2], n39);
  y[3] = gate_and(n26, n39);
  y[2] = gate_and(n25, n38);
  auto n33 = gate_mux(n35, n32, n39);
  y[0] = gate_not(n33);
  auto n36 = gate_nand(n25, a[2]);
  auto n37 = gate_mux(n36, n35, n39);
  y[1] = gate_not(n37);
}
template<> void CplainUint<4>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_buf(a[3]);
  auto n20 = gate_and(b[1], a[2]);
  auto n37 = gate_not(b[0]);
  auto n23 = gate_nand(n20, n37);
  auto n27 = gate_not(a[3]);
  auto n22 = gate_not(b[2]);
  auto n21 = gate_not(b[3]);
  auto n24 = gate_nand(n22, n21);
  auto n32 = gate_mux(n23, n27, n24);
  auto n26 = gate_not(n24);
  auto n25 = gate_not(b[1]);
  auto n34 = gate_nand(n26, n25);
  auto n38 = gate_not(n34);
  auto n30 = gate_nand(a[0], n38);
  auto n28 = gate_nand(a[1], n26);
  auto n29 = gate_mux(n28, n27, b[1]);
  auto n31 = gate_mux(n30, n29, b[0]);
  y[0] = gate_nand(n32, n31);
  auto n33 = gate_mux(a[1], a[2], b[0]);
  auto n36 = gate_nand(n38, n33);
  auto n35 = gate_nand(a[3], n34);
  y[1] = gate_nand(n36, n35);
  auto n39 = gate_nand(n38, n37);
  y[2] = gate_mux(a[2], a[3], n39);
}
template<> void CplainUint<4>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n27 = gate_xor(b[3], a[3]);
  auto n17 = gate_not(b[1]);
  auto n19 = gate_xor(a[1], n17);
  auto n16 = gate_not(a[0]);
  auto n18 = gate_nand(b[0], n16);
  y[1] = gate_xor(n19, n18);
  auto n22 = gate_not(b[2]);
  auto n24 = gate_xor(a[2], n22);
  auto n21 = gate_nand(a[1], n17);
  auto n20 = gate_nand(n19, n18);
  auto n23 = gate_nand(n21, n20);
  y[2] = gate_xor(n24, n23);
  auto n26 = gate_nand(a[2], n22);
  auto n25 = gate_nand(n24, n23);
  auto n28 = gate_nand(n26, n25);
  y[3] = gate_xnor(n28, n27);
}
template<> void CplainUint<4>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  y[1] = gate_xor(a[1], a[0]);
  auto n8 = gate_not(a[1]);
  auto n7 = gate_not(a[0]);
  auto n9 = gate_nand(n8, n7);
  y[2] = gate_xor(a[2], n9);
  auto n11 = gate_not(n9);
  auto n10 = gate_not(a[2]);
  auto n12 = gate_nand(n11, n10);
  y[3] = gate_xor(a[3], n12);
}
template<> void CplainUint<8>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_and(a[0], b[0]);
  y[0] = gate_xor(a[0], b[0]);
  auto n3 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n3, n2);
  auto n7 = gate_xor(b[2], a[2]);
  auto n5 = gate_nand(b[1], a[1]);
  auto n4 = gate_nand(n3, n2);
  auto n6 = gate_nand(n5, n4);
  y[2] = gate_xor(n7, n6);
  auto n11 = gate_xor(b[3], a[3]);
  auto n9 = gate_nand(b[2], a[2]);
  auto n8 = gate_nand(n7, n6);
  auto n10 = gate_nand(n9, n8);
  y[3] = gate_xor(n11, n10);
  auto n15 = gate_xor(b[4], a[4]);
  auto n13 = gate_nand(b[3], a[3]);
  auto n12 = gate_nand(n11, n10);
  auto n14 = gate_nand(n13, n12);
  y[4] = gate_xor(n15, n14);
  auto n19 = gate_xor(b[5], a[5]);
  auto n17 = gate_nand(b[4], a[4]);
  auto n16 = gate_nand(n15, n14);
  auto n18 = gate_nand(n17, n16);
  y[5] = gate_xor(n19, n18);
  auto n23 = gate_xor(b[6], a[6]);
  auto n21 = gate_nand(b[5], a[5]);
  auto n20 = gate_nand(n19, n18);
  auto n22 = gate_nand(n21, n20);
  y[6] = gate_xor(n23, n22);
  auto n25 = gate_nand(n23, n22);
  auto n24 = gate_nand(b[6], a[6]);
  auto n26 = gate_nand(n25, n24);
  auto n27 = gate_xor(b[7], n26);
  y[7] = gate_xor(a[7], n27);
}
template<> void CplainUint<8>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[7] = gate_and(b[7], a[7]);
  y[0] = gate_and(b[0], a[0]);
  y[1] = gate_and(b[1], a[1]);
  y[2] = gate_and(b[2], a[2]);
  y[3] = gate_and(b[3], a[3]);
  y[4] = gate_and(b[4], a[4]);
  y[5] = gate_and(b[5], a[5]);
  y[6] = gate_and(b[6], a[6]);
}
template<> void CplainUint<8>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[7] = gate_not(a[7]);
  y[6] = gate_not(a[6]);
  y[5] = gate_not(a[5]);
  y[4] = gate_not(a[4]);
  y[3] = gate_not(a[3]);
  y[2] = gate_not(a[2]);
  y[1] = gate_not(a[1]);
  y[0] = gate_not(a[0]);
}
template<> void CplainUint<8>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n18 = gate_not(b[7]);
  auto n17 = gate_not(a[7]);
  y[7] = gate_nand(n18, n17);
  auto n20 = gate_not(b[6]);
  auto n19 = gate_not(a[6]);
  y[6] = gate_nand(n20, n19);
  auto n22 = gate_not(b[5]);
  auto n21 = gate_not(a[5]);
  y[5] = gate_nand(n22, n21);
  auto n24 = gate_not(b[4]);
  auto n23 = gate_not(a[4]);
  y[4] = gate_nand(n24, n23);
  auto n26 = gate_not(b[3]);
  auto n25 = gate_not(a[3]);
  y[3] = gate_nand(n26, n25);
  auto n28 = gate_not(b[2]);
  auto n27 = gate_not(a[2]);
  y[2] = gate_nand(n28, n27);
  auto n30 = gate_not(b[1]);
  auto n29 = gate_not(a[1]);
  y[1] = gate_nand(n30, n29);
  auto n32 = gate_not(b[0]);
  auto n31 = gate_not(a[0]);
  y[0] = gate_nand(n32, n31);
}
template<> void CplainUint<8>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  y[4] = gate_buf(zero);
  y[5] = gate_buf(zero);
  y[6] = gate_buf(zero);
  y[7] = gate_buf(zero);
  auto N0 = gate_buf(a[0]);
  auto n4 = gate_xor(N0, a[1]);
  auto n11 = gate_xor(n4, a[2]);
  auto n10 = gate_xor(a[6], a[7]);
  auto n15 = gate_xor(n11, n10);
  auto n7 = gate_xor(a[4], a[3]);
  auto n14 = gate_xor(n7, a[5]);
  auto n3 = gate_and(n15, n14);
  y[0] = gate_xor(n15, n14);
  auto n6 = gate_nand(N0, a[1]);
  auto n5 = gate_nand(n4, a[2]);
  auto n18 = gate_nand(n6, n5);
  auto n9 = gate_nand(a[4], a[3]);
  auto n8 = gate_nand(n7, a[5]);
  auto n17 = gate_nand(n9, n8);
  auto n20 = gate_xor(n18, n17);
  auto n13 = gate_nand(a[6], a[7]);
  auto n12 = gate_nand(n11, n10);
  auto n19 = gate_nand(n13, n12);
  auto n16 = gate_xor(n20, n19);
  auto n1 = gate_and(n16, n3);
  y[1] = gate_xor(n16, n3);
  auto n22 = gate_nand(n18, n17);
  auto n21 = gate_nand(n20, n19);
  auto n23 = gate_nand(n22, n21);
  y[3] = gate_and(n1, n23);
  y[2] = gate_xor(n1, n23);
}
template<> void CplainUint<8>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[7] = gate_xor(b[7], a[7]);
  y[6] = gate_xor(b[6], a[6]);
  y[5] = gate_xor(b[5], a[5]);
  y[4] = gate_xor(b[4], a[4]);
  y[3] = gate_xor(b[3], a[3]);
  y[2] = gate_xor(b[2], a[2]);
  y[1] = gate_xor(b[1], a[1]);
  y[0] = gate_xor(b[0], a[0]);
}
template<> void CplainUint<8>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[7] = gate_and(a[0], b[7]);
  y[6] = gate_and(a[0], b[6]);
  y[5] = gate_and(a[0], b[5]);
  y[4] = gate_and(a[0], b[4]);
  y[3] = gate_and(a[0], b[3]);
  y[2] = gate_and(a[0], b[2]);
  y[1] = gate_and(a[0], b[1]);
  y[0] = gate_and(a[0], b[0]);
}
template<> void CplainUint<8>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
  y[1] = gate_mux(c[1], b[1], a[0]);
  y[2] = gate_mux(c[2], b[2], a[0]);
  y[3] = gate_mux(c[3], b[3], a[0]);
  y[4] = gate_mux(c[4], b[4], a[0]);
  y[5] = gate_mux(c[5], b[5], a[0]);
  y[6] = gate_mux(c[6], b[6], a[0]);
  y[7] = gate_mux(c[7], b[7], a[0]);
}
template<> void CplainUint<8>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_and(a[0], b[0]);
  y[0] = gate_xor(a[0], b[0]);
  auto n3 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n3, n2);
  auto n7 = gate_xor(b[2], a[2]);
  auto n5 = gate_nand(b[1], a[1]);
  auto n4 = gate_nand(n3, n2);
  auto n6 = gate_nand(n5, n4);
  y[2] = gate_xor(n7, n6);
  auto n11 = gate_xor(b[3], a[3]);
  auto n9 = gate_nand(b[2], a[2]);
  auto n8 = gate_nand(n7, n6);
  auto n10 = gate_nand(n9, n8);
  y[3] = gate_xor(n11, n10);
  auto n15 = gate_xor(b[4], a[4]);
  auto n13 = gate_nand(b[3], a[3]);
  auto n12 = gate_nand(n11, n10);
  auto n14 = gate_nand(n13, n12);
  y[4] = gate_xor(n15, n14);
  auto n19 = gate_xor(b[5], a[5]);
  auto n17 = gate_nand(b[4], a[4]);
  auto n16 = gate_nand(n15, n14);
  auto n18 = gate_nand(n17, n16);
  y[5] = gate_xor(n19, n18);
  auto n23 = gate_xor(b[6], a[6]);
  auto n21 = gate_nand(b[5], a[5]);
  auto n20 = gate_nand(n19, n18);
  auto n22 = gate_nand(n21, n20);
  y[6] = gate_xor(n23, n22);
  auto n25 = gate_nand(b[6], a[6]);
  auto n24 = gate_nand(n23, n22);
  y[7] = gate_nand(n25, n24);
}
template<> void CplainUint<8>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  y[1] = gate_xor(a[1], y[0]);
  auto n7 = gate_not(a[1]);
  auto n2 = gate_and(n7, y[0]);
  y[2] = gate_xor(a[2], n2);
  auto n8 = gate_not(a[2]);
  auto n3 = gate_and(n2, n8);
  y[3] = gate_xor(a[3], n3);
  auto n9 = gate_not(a[3]);
  auto n4 = gate_and(n3, n9);
  y[4] = gate_xor(a[4], n4);
  auto n10 = gate_not(a[4]);
  auto n5 = gate_and(n4, n10);
  y[5] = gate_xor(a[5], n5);
  auto n11 = gate_not(a[5]);
  auto n6 = gate_and(n5, n11);
  y[6] = gate_xor(a[6], n6);
  auto n14 = gate_not(a[7]);
  auto n12 = gate_not(a[6]);
  auto n13 = gate_nand(n6, n12);
  y[7] = gate_xor(n14, n13);
}
template<> void CplainUint<8>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_not(a[6]);
  auto n12 = gate_nand(b[0], n11);
  auto n135 = gate_not(b[7]);
  auto n193 = gate_not(b[6]);
  auto n4 = gate_and(n135, n193);
  auto n142 = gate_not(b[5]);
  auto n3 = gate_and(n4, n142);
  auto n178 = gate_not(b[4]);
  auto n7 = gate_and(n3, n178);
  auto n148 = gate_not(b[3]);
  auto n2 = gate_and(n7, n148);
  auto n164 = gate_not(b[2]);
  auto n6 = gate_and(n2, n164);
  auto n5 = gate_and(n12, n6);
  auto n19 = gate_not(a[7]);
  auto n13 = gate_nand(b[1], n19);
  auto n21 = gate_nand(n5, n13);
  y[6] = gate_not(n21);
  auto n14 = gate_nand(y[6], b[0]);
  auto n32 = gate_nand(a[6], n14);
  auto n15 = gate_not(n32);
  auto n151 = gate_not(b[1]);
  auto n1 = gate_and(n151, n6);
  auto n17 = gate_nand(n15, n151);
  auto n28 = gate_xor(b[1], n32);
  auto n34 = gate_not(a[5]);
  auto n29 = gate_nand(b[0], n34);
  auto n16 = gate_nand(n28, n29);
  auto n18 = gate_nand(n17, n16);
  auto n24 = gate_nand(n18, n164);
  auto n22 = gate_xor(n18, n164);
  auto n20 = gate_nand(b[0], n19);
  auto n201 = gate_nand(n1, n20);
  y[7] = gate_not(n201);
  auto n8 = gate_and(n21, n201);
  auto n40 = gate_nand(a[7], n8);
  auto n27 = gate_not(n40);
  auto n23 = gate_nand(n22, n27);
  auto n25 = gate_nand(n24, n23);
  auto n26 = gate_nand(n2, n25);
  y[5] = gate_not(n26);
  auto n64 = gate_nand(n27, n26);
  auto n47 = gate_not(n64);
  auto n44 = gate_nand(n47, n148);
  auto n30 = gate_not(n28);
  auto n31 = gate_nand(n30, n29);
  auto n37 = gate_mux(n32, n31, y[5]);
  auto n49 = gate_xor(b[2], n37);
  auto n33 = gate_nand(y[5], b[0]);
  auto n55 = gate_xor(n34, n33);
  auto n36 = gate_nand(n151, n55);
  auto n53 = gate_xor(n151, n55);
  auto n57 = gate_not(a[4]);
  auto n52 = gate_nand(b[0], n57);
  auto n35 = gate_nand(n53, n52);
  auto n48 = gate_nand(n36, n35);
  auto n39 = gate_nand(n49, n48);
  auto n51 = gate_not(n37);
  auto n38 = gate_nand(n164, n51);
  auto n42 = gate_nand(n39, n38);
  auto n41 = gate_nand(b[3], n40);
  auto n43 = gate_nand(n42, n41);
  auto n45 = gate_nand(n44, n43);
  auto n46 = gate_nand(n7, n45);
  y[4] = gate_not(n46);
  auto n94 = gate_nand(n47, n46);
  auto n70 = gate_not(n94);
  auto n68 = gate_nand(n70, n178);
  auto n50 = gate_xor(n49, n48);
  auto n73 = gate_mux(n51, n50, y[4]);
  auto n71 = gate_xor(n148, n73);
  auto n54 = gate_xor(n53, n52);
  auto n78 = gate_mux(n55, n54, y[4]);
  auto n61 = gate_nand(n78, n164);
  auto n75 = gate_xor(n164, n78);
  auto n56 = gate_nand(y[4], b[0]);
  auto n83 = gate_xor(n57, n56);
  auto n59 = gate_nand(n151, n83);
  auto n81 = gate_xor(n151, n83);
  auto n85 = gate_not(a[3]);
  auto n80 = gate_nand(b[0], n85);
  auto n58 = gate_nand(n81, n80);
  auto n76 = gate_nand(n59, n58);
  auto n60 = gate_nand(n75, n76);
  auto n72 = gate_nand(n61, n60);
  auto n63 = gate_nand(n71, n72);
  auto n62 = gate_nand(n73, n148);
  auto n66 = gate_nand(n63, n62);
  auto n65 = gate_nand(b[4], n64);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n77 = gate_nand(n3, n69);
  y[3] = gate_not(n77);
  auto n136 = gate_nand(n70, n77);
  auto n131 = gate_not(n136);
  auto n98 = gate_nand(n131, n142);
  auto n74 = gate_xor(n72, n71);
  auto n102 = gate_mux(n74, n73, n77);
  auto n100 = gate_xor(n102, n178);
  auto n79 = gate_xor(n76, n75);
  auto n106 = gate_mux(n79, n78, n77);
  auto n91 = gate_nand(n106, n148);
  auto n104 = gate_xor(n106, n148);
  auto n82 = gate_xor(n81, n80);
  auto n110 = gate_mux(n83, n82, y[3]);
  auto n89 = gate_nand(n110, n164);
  auto n108 = gate_xor(n164, n110);
  auto n84 = gate_nand(y[3], b[0]);
  auto n115 = gate_xor(n85, n84);
  auto n87 = gate_nand(n151, n115);
  auto n113 = gate_xor(n151, n115);
  auto n117 = gate_not(a[2]);
  auto n112 = gate_nand(b[0], n117);
  auto n86 = gate_nand(n113, n112);
  auto n109 = gate_nand(n87, n86);
  auto n88 = gate_nand(n108, n109);
  auto n105 = gate_nand(n89, n88);
  auto n90 = gate_nand(n104, n105);
  auto n101 = gate_nand(n91, n90);
  auto n93 = gate_nand(n100, n101);
  auto n92 = gate_nand(n102, n178);
  auto n96 = gate_nand(n93, n92);
  auto n95 = gate_nand(b[5], n94);
  auto n97 = gate_nand(n96, n95);
  auto n99 = gate_nand(n98, n97);
  auto n130 = gate_nand(n4, n99);
  auto n9 = gate_and(n131, n130);
  y[2] = gate_not(n130);
  auto n103 = gate_xor(n101, n100);
  auto n189 = gate_mux(n103, n102, n130);
  auto n186 = gate_xor(n189, n142);
  auto n107 = gate_xor(n105, n104);
  auto n139 = gate_mux(n107, n106, n130);
  auto n125 = gate_nand(n139, n178);
  auto n137 = gate_xor(n139, n178);
  auto n111 = gate_xor(n109, n108);
  auto n174 = gate_mux(n111, n110, n130);
  auto n123 = gate_nand(n174, n148);
  auto n172 = gate_xor(n174, n148);
  auto n114 = gate_xor(n113, n112);
  auto n145 = gate_mux(n115, n114, y[2]);
  auto n121 = gate_nand(n145, n164);
  auto n143 = gate_xor(n164, n145);
  auto n116 = gate_nand(y[2], b[0]);
  auto n161 = gate_xor(n117, n116);
  auto n119 = gate_nand(n151, n161);
  auto n159 = gate_xor(n151, n161);
  auto n150 = gate_not(a[1]);
  auto n158 = gate_nand(b[0], n150);
  auto n118 = gate_nand(n159, n158);
  auto n144 = gate_nand(n119, n118);
  auto n120 = gate_nand(n143, n144);
  auto n173 = gate_nand(n121, n120);
  auto n122 = gate_nand(n172, n173);
  auto n138 = gate_nand(n123, n122);
  auto n124 = gate_nand(n137, n138);
  auto n187 = gate_nand(n125, n124);
  auto n127 = gate_nand(n186, n187);
  auto n126 = gate_nand(n189, n142);
  auto n129 = gate_nand(n127, n126);
  auto n128 = gate_nand(b[6], n136);
  auto n133 = gate_nand(n129, n128);
  auto n132 = gate_nand(n9, n193);
  auto n134 = gate_nand(n133, n132);
  auto n188 = gate_nand(n135, n134);
  auto n10 = gate_and(n9, n188);
  y[1] = gate_not(n188);
  auto n200 = gate_nand(n10, n135);
  auto n198 = gate_nand(b[7], n136);
  auto n140 = gate_xor(n138, n137);
  auto n141 = gate_mux(n140, n139, n188);
  auto n185 = gate_nand(n142, n141);
  auto n183 = gate_xor(n142, n141);
  auto n146 = gate_xor(n144, n143);
  auto n147 = gate_mux(n146, n145, n188);
  auto n171 = gate_nand(n148, n147);
  auto n169 = gate_xor(n148, n147);
  auto n149 = gate_nand(y[1], b[0]);
  auto n152 = gate_xor(n150, n149);
  auto n157 = gate_nand(n152, n151);
  auto n155 = gate_xor(n152, n151);
  auto n153 = gate_not(a[0]);
  auto n154 = gate_nand(b[0], n153);
  auto n156 = gate_nand(n155, n154);
  auto n163 = gate_nand(n157, n156);
  auto n160 = gate_xor(n159, n158);
  auto n162 = gate_mux(n161, n160, y[1]);
  auto n167 = gate_nand(n163, n162);
  auto n165 = gate_xor(n163, n162);
  auto n166 = gate_nand(n165, n164);
  auto n168 = gate_nand(n167, n166);
  auto n170 = gate_nand(n169, n168);
  auto n177 = gate_nand(n171, n170);
  auto n175 = gate_xor(n173, n172);
  auto n176 = gate_mux(n175, n174, n188);
  auto n181 = gate_nand(n177, n176);
  auto n179 = gate_xor(n177, n176);
  auto n180 = gate_nand(n179, n178);
  auto n182 = gate_nand(n181, n180);
  auto n184 = gate_nand(n183, n182);
  auto n192 = gate_nand(n185, n184);
  auto n190 = gate_xor(n187, n186);
  auto n191 = gate_mux(n190, n189, n188);
  auto n196 = gate_nand(n192, n191);
  auto n194 = gate_xor(n192, n191);
  auto n195 = gate_nand(n194, n193);
  auto n197 = gate_nand(n196, n195);
  auto n199 = gate_nand(n198, n197);
  y[0] = gate_nand(n200, n199);
}
template<> void CplainUint<8>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n264 = gate_not(b[7]);
  auto n251 = gate_xor(a[7], n264);
  auto n266 = gate_not(n251);
  auto n160 = gate_not(a[1]);
  auto n194 = gate_not(a[0]);
  auto n119 = gate_nand(n160, n194);
  auto n20 = gate_not(n119);
  auto n19 = gate_not(a[2]);
  auto n86 = gate_nand(n20, n19);
  auto n22 = gate_not(n86);
  auto n21 = gate_not(a[3]);
  auto n59 = gate_nand(n22, n21);
  auto n24 = gate_not(n59);
  auto n23 = gate_not(a[4]);
  auto n39 = gate_nand(n24, n23);
  auto n26 = gate_not(n39);
  auto n25 = gate_not(a[5]);
  auto n29 = gate_nand(n26, n25);
  auto n27 = gate_not(n29);
  auto n31 = gate_not(a[6]);
  auto n7 = gate_and(n27, n31);
  auto n46 = gate_nand(a[7], n7);
  auto n252 = gate_not(n46);
  auto n8 = gate_and(n252, b[0]);
  auto n237 = gate_xor(b[6], b[7]);
  auto n179 = gate_not(n237);
  auto n186 = gate_xor(b[5], b[7]);
  auto n142 = gate_not(n186);
  auto n5 = gate_and(n179, n142);
  auto n218 = gate_xor(b[4], b[7]);
  auto n183 = gate_not(n218);
  auto n4 = gate_and(n5, n183);
  auto n192 = gate_xor(b[3], b[7]);
  auto n221 = gate_not(n192);
  auto n3 = gate_and(n4, n221);
  auto n203 = gate_xor(b[2], b[7]);
  auto n189 = gate_not(n203);
  auto n2 = gate_and(n3, n189);
  auto n196 = gate_xor(b[1], b[7]);
  auto n206 = gate_not(n196);
  auto n9 = gate_and(n2, n206);
  auto n28 = gate_nand(n9, b[0]);
  auto n10 = gate_and(n252, n28);
  auto n35 = gate_nand(n10, n206);
  auto n30 = gate_nand(a[7], n29);
  auto n37 = gate_xor(n31, n30);
  auto n263 = gate_not(b[0]);
  auto n6 = gate_and(n264, n263);
  auto n33 = gate_mux(n37, n264, n263);
  auto n32 = gate_nand(n196, n46);
  auto n34 = gate_nand(n33, n32);
  auto n36 = gate_nand(n35, n34);
  auto n250 = gate_nand(n2, n36);
  auto n53 = gate_nand(n10, n250);
  auto n52 = gate_not(n53);
  auto n50 = gate_nand(n52, n189);
  auto n38 = gate_nand(n37, n250);
  auto n54 = gate_not(n38);
  auto n45 = gate_nand(n206, n54);
  auto n43 = gate_xor(n196, n38);
  auto n40 = gate_nand(a[7], n39);
  auto n58 = gate_xor(a[5], n40);
  auto n41 = gate_mux(n58, b[7], n263);
  auto n42 = gate_not(n41);
  auto n44 = gate_nand(n43, n42);
  auto n48 = gate_nand(n45, n44);
  auto n47 = gate_nand(n203, n46);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  auto n56 = gate_nand(n3, n51);
  auto n75 = gate_nand(n52, n56);
  auto n74 = gate_not(n75);
  auto n70 = gate_nand(n53, n192);
  auto n55 = gate_nand(n54, n56);
  auto n76 = gate_not(n55);
  auto n68 = gate_nand(n189, n76);
  auto n66 = gate_xor(n203, n55);
  auto n249 = gate_not(n56);
  auto n57 = gate_nand(n249, b[0]);
  auto n82 = gate_xor(n58, n57);
  auto n64 = gate_nand(n82, n206);
  auto n62 = gate_xor(n82, n206);
  auto n60 = gate_nand(a[7], n59);
  auto n85 = gate_xor(a[4], n60);
  auto n61 = gate_mux(n85, b[7], n263);
  auto n79 = gate_not(n61);
  auto n63 = gate_nand(n62, n79);
  auto n65 = gate_nand(n64, n63);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n72 = gate_nand(n70, n69);
  auto n71 = gate_nand(n221, n74);
  auto n73 = gate_nand(n72, n71);
  auto n78 = gate_nand(n4, n73);
  auto n140 = gate_nand(n74, n78);
  auto n104 = gate_not(n140);
  auto n100 = gate_nand(n75, n218);
  auto n77 = gate_nand(n76, n78);
  auto n105 = gate_not(n77);
  auto n98 = gate_nand(n221, n105);
  auto n96 = gate_xor(n192, n77);
  auto n248 = gate_not(n78);
  auto n80 = gate_xor(n206, n79);
  auto n81 = gate_nand(n248, n80);
  auto n111 = gate_xor(n82, n81);
  auto n83 = gate_not(n111);
  auto n94 = gate_nand(n83, n189);
  auto n92 = gate_xor(n189, n83);
  auto n84 = gate_nand(n248, b[0]);
  auto n115 = gate_xor(n85, n84);
  auto n91 = gate_nand(n115, n206);
  auto n89 = gate_xor(n115, n206);
  auto n87 = gate_nand(a[7], n86);
  auto n118 = gate_xor(a[3], n87);
  auto n88 = gate_mux(n118, b[7], n263);
  auto n112 = gate_not(n88);
  auto n90 = gate_nand(n89, n112);
  auto n108 = gate_nand(n91, n90);
  auto n93 = gate_nand(n92, n108);
  auto n95 = gate_nand(n94, n93);
  auto n97 = gate_nand(n96, n95);
  auto n99 = gate_nand(n98, n97);
  auto n102 = gate_nand(n100, n99);
  auto n101 = gate_nand(n183, n104);
  auto n103 = gate_nand(n102, n101);
  auto n107 = gate_nand(n5, n103);
  auto n14 = gate_and(n104, n107);
  auto n136 = gate_nand(n140, n186);
  auto n106 = gate_nand(n105, n107);
  auto n141 = gate_not(n106);
  auto n134 = gate_nand(n183, n141);
  auto n132 = gate_xor(n218, n106);
  auto n247 = gate_not(n107);
  auto n109 = gate_xor(n189, n108);
  auto n110 = gate_nand(n247, n109);
  auto n148 = gate_xor(n111, n110);
  auto n130 = gate_nand(n148, n221);
  auto n128 = gate_xor(n148, n221);
  auto n113 = gate_xor(n206, n112);
  auto n114 = gate_nand(n247, n113);
  auto n152 = gate_xor(n115, n114);
  auto n116 = gate_not(n152);
  auto n127 = gate_nand(n116, n189);
  auto n125 = gate_xor(n203, n152);
  auto n117 = gate_nand(n247, b[0]);
  auto n156 = gate_xor(n118, n117);
  auto n124 = gate_nand(n156, n206);
  auto n122 = gate_xor(n156, n206);
  auto n120 = gate_nand(a[7], n119);
  auto n158 = gate_xor(a[2], n120);
  auto n121 = gate_mux(n158, b[7], n263);
  auto n153 = gate_not(n121);
  auto n123 = gate_nand(n122, n153);
  auto n149 = gate_nand(n124, n123);
  auto n126 = gate_nand(n125, n149);
  auto n145 = gate_nand(n127, n126);
  auto n129 = gate_nand(n128, n145);
  auto n131 = gate_nand(n130, n129);
  auto n133 = gate_nand(n132, n131);
  auto n135 = gate_nand(n134, n133);
  auto n138 = gate_nand(n136, n135);
  auto n137 = gate_nand(n142, n14);
  auto n139 = gate_nand(n138, n137);
  auto n144 = gate_nand(n179, n139);
  auto n17 = gate_and(n14, n144);
  auto n178 = gate_nand(n140, n237);
  auto n143 = gate_nand(n141, n144);
  auto n234 = gate_not(n143);
  auto n176 = gate_nand(n142, n234);
  auto n174 = gate_xor(n186, n143);
  auto n246 = gate_not(n144);
  auto n146 = gate_xor(n221, n145);
  auto n147 = gate_nand(n246, n146);
  auto n16 = gate_xnor(n148, n147);
  auto n172 = gate_nand(n16, n183);
  auto n170 = gate_xor(n183, n16);
  auto n150 = gate_xor(n189, n149);
  auto n151 = gate_nand(n246, n150);
  auto n225 = gate_xor(n152, n151);
  auto n169 = gate_nand(n225, n221);
  auto n167 = gate_xor(n221, n225);
  auto n154 = gate_xor(n206, n153);
  auto n155 = gate_nand(n246, n154);
  auto n15 = gate_xnor(n156, n155);
  auto n166 = gate_nand(n15, n189);
  auto n164 = gate_xor(n189, n15);
  auto n157 = gate_nand(b[0], n246);
  auto n209 = gate_xor(n158, n157);
  auto n163 = gate_nand(n209, n206);
  auto n161 = gate_xor(n206, n209);
  auto n159 = gate_nand(a[0], a[7]);
  auto n198 = gate_xor(n160, n159);
  auto n205 = gate_mux(n198, n264, n263);
  auto n162 = gate_nand(n161, n205);
  auto n188 = gate_nand(n163, n162);
  auto n165 = gate_nand(n164, n188);
  auto n220 = gate_nand(n166, n165);
  auto n168 = gate_nand(n167, n220);
  auto n182 = gate_nand(n169, n168);
  auto n171 = gate_nand(n170, n182);
  auto n173 = gate_nand(n172, n171);
  auto n175 = gate_nand(n174, n173);
  auto n177 = gate_nand(n176, n175);
  auto n181 = gate_nand(n178, n177);
  auto n180 = gate_nand(n179, n17);
  auto n223 = gate_nand(n181, n180);
  auto n245 = gate_not(n223);
  auto n242 = gate_nand(n17, n245);
  auto n184 = gate_xor(n183, n182);
  auto n185 = gate_nand(n223, n184);
  auto n187 = gate_xor(n16, n185);
  auto n233 = gate_nand(n187, n186);
  auto n231 = gate_xor(n187, n186);
  auto n190 = gate_xor(n189, n188);
  auto n191 = gate_nand(n223, n190);
  auto n193 = gate_xor(n15, n191);
  auto n217 = gate_nand(n193, n192);
  auto n215 = gate_xor(n193, n192);
  auto n195 = gate_mux(n194, b[7], n263);
  auto n202 = gate_nand(n196, n195);
  auto n200 = gate_xor(n196, n195);
  auto n197 = gate_nand(b[0], n223);
  auto n199 = gate_xor(n198, n197);
  auto n201 = gate_nand(n200, n199);
  auto n204 = gate_nand(n202, n201);
  auto n213 = gate_nand(n204, n203);
  auto n211 = gate_xor(n204, n203);
  auto n207 = gate_xor(n206, n205);
  auto n208 = gate_nand(n223, n207);
  auto n210 = gate_xor(n209, n208);
  auto n212 = gate_nand(n211, n210);
  auto n214 = gate_nand(n213, n212);
  auto n216 = gate_nand(n215, n214);
  auto n219 = gate_nand(n217, n216);
  auto n229 = gate_nand(n219, n218);
  auto n227 = gate_xor(n219, n218);
  auto n222 = gate_xor(n221, n220);
  auto n224 = gate_nand(n223, n222);
  auto n226 = gate_xor(n225, n224);
  auto n228 = gate_nand(n227, n226);
  auto n230 = gate_nand(n229, n228);
  auto n232 = gate_nand(n231, n230);
  auto n236 = gate_nand(n233, n232);
  auto n235 = gate_nand(n234, n245);
  auto n240 = gate_nand(n236, n235);
  auto n238 = gate_xor(n236, n235);
  auto n239 = gate_nand(n238, n237);
  auto n241 = gate_nand(n240, n239);
  auto n262 = gate_nand(n242, n241);
  auto n243 = gate_not(n262);
  auto n269 = gate_nand(n266, n243);
  auto n244 = gate_not(n269);
  auto n261 = gate_xor(n251, n245);
  auto n18 = gate_and(n244, n261);
  auto n260 = gate_xor(n266, n246);
  auto n11 = gate_and(n18, n260);
  auto n259 = gate_xor(n266, n247);
  auto n13 = gate_and(n11, n259);
  auto n258 = gate_xor(n266, n248);
  auto n1 = gate_and(n13, n258);
  auto n257 = gate_xor(n266, n249);
  auto n12 = gate_and(n1, n257);
  auto n256 = gate_xor(n251, n250);
  auto n255 = gate_nand(n12, n256);
  auto n253 = gate_nand(n8, n9);
  auto n254 = gate_xor(n266, n253);
  y[7] = gate_xor(n255, n254);
  y[6] = gate_xor(n12, n256);
  y[5] = gate_xor(n1, n257);
  y[4] = gate_xor(n13, n258);
  y[3] = gate_xor(n11, n259);
  y[2] = gate_xor(n18, n260);
  y[1] = gate_xor(n244, n261);
  auto n268 = gate_xor(n262, n266);
  auto n265 = gate_nand(n6, n9);
  auto n267 = gate_nand(n266, n265);
  y[0] = gate_mux(n269, n268, n267);
}
template<> void CplainUint<8>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n31 = gate_xnor(b[7], a[7]);
  auto n38 = gate_xnor(a[1], b[1]);
  auto n40 = gate_xnor(b[4], a[4]);
  auto n41 = gate_xnor(b[5], a[5]);
  auto n42 = gate_xnor(b[6], a[6]);
  auto n43 = gate_not(b[2]);
  auto n48 = gate_xor(n43, a[2]);
  auto n44 = gate_not(a[3]);
  auto n47 = gate_xor(n44, b[3]);
  auto n45 = gate_not(a[0]);
  auto n46 = gate_xor(n45, b[0]);
  auto n33 = gate_and(n47, n46);
  auto n32 = gate_and(n33, n38);
  auto n39 = gate_and(n48, n32);
  auto n35 = gate_and(n39, n41);
  auto n34 = gate_and(n35, n40);
  auto n36 = gate_and(n34, n42);
  y[0] = gate_and(n36, n31);
}
template<> void CplainUint<8>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n39 = gate_not(b[7]);
  auto n74 = gate_nand(n39, a[7]);
  auto n72 = gate_xor(n39, a[7]);
  auto n40 = gate_not(b[5]);
  auto n65 = gate_nand(n40, a[5]);
  auto n63 = gate_xor(n40, a[5]);
  auto n41 = gate_not(b[3]);
  auto n56 = gate_nand(n41, a[3]);
  auto n54 = gate_xor(n41, a[3]);
  auto n42 = gate_not(b[2]);
  auto n52 = gate_nand(n42, a[2]);
  auto n50 = gate_xor(n42, a[2]);
  auto n43 = gate_not(b[1]);
  auto n48 = gate_nand(n43, a[1]);
  auto n46 = gate_xor(n43, a[1]);
  auto n44 = gate_not(a[0]);
  auto n45 = gate_nand(b[0], n44);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n55 = gate_nand(n54, n53);
  auto n57 = gate_nand(n56, n55);
  auto n61 = gate_nand(n57, a[4]);
  auto n59 = gate_xor(n57, a[4]);
  auto n58 = gate_not(b[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n64 = gate_nand(n63, n62);
  auto n66 = gate_nand(n65, n64);
  auto n70 = gate_nand(n66, a[6]);
  auto n68 = gate_xor(n66, a[6]);
  auto n67 = gate_not(b[6]);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n73 = gate_nand(n72, n71);
  y[0] = gate_nand(n74, n73);
}
template<> void CplainUint<8>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n39 = gate_not(a[7]);
  auto n74 = gate_nand(n39, b[7]);
  auto n72 = gate_xor(n39, b[7]);
  auto n40 = gate_not(b[5]);
  auto n65 = gate_nand(n40, a[5]);
  auto n63 = gate_xor(n40, a[5]);
  auto n41 = gate_not(b[3]);
  auto n56 = gate_nand(n41, a[3]);
  auto n54 = gate_xor(n41, a[3]);
  auto n42 = gate_not(b[2]);
  auto n52 = gate_nand(n42, a[2]);
  auto n50 = gate_xor(n42, a[2]);
  auto n43 = gate_not(b[1]);
  auto n48 = gate_nand(n43, a[1]);
  auto n46 = gate_xor(n43, a[1]);
  auto n44 = gate_not(a[0]);
  auto n45 = gate_nand(b[0], n44);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n55 = gate_nand(n54, n53);
  auto n57 = gate_nand(n56, n55);
  auto n61 = gate_nand(n57, a[4]);
  auto n59 = gate_xor(n57, a[4]);
  auto n58 = gate_not(b[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n64 = gate_nand(n63, n62);
  auto n66 = gate_nand(n65, n64);
  auto n70 = gate_nand(n66, a[6]);
  auto n68 = gate_xor(n66, a[6]);
  auto n67 = gate_not(b[6]);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n73 = gate_nand(n72, n71);
  y[0] = gate_nand(n74, n73);
}
template<> void CplainUint<8>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n41 = gate_not(b[6]);
  auto n70 = gate_nand(n41, a[6]);
  auto n68 = gate_xor(n41, a[6]);
  auto n42 = gate_not(a[1]);
  auto n47 = gate_nand(n42, b[1]);
  auto n45 = gate_xor(n42, b[1]);
  auto n43 = gate_not(b[0]);
  auto n44 = gate_nand(a[0], n43);
  auto n46 = gate_nand(n45, n44);
  auto n48 = gate_nand(n47, n46);
  auto n52 = gate_nand(n48, b[2]);
  auto n50 = gate_xor(n48, b[2]);
  auto n49 = gate_not(a[2]);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n57 = gate_nand(n53, b[3]);
  auto n55 = gate_xor(n53, b[3]);
  auto n54 = gate_not(a[3]);
  auto n56 = gate_nand(n55, n54);
  auto n40 = gate_and(n57, n56);
  auto n61 = gate_nand(n40, a[4]);
  auto n59 = gate_xor(n40, a[4]);
  auto n58 = gate_not(b[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n66 = gate_nand(n62, a[5]);
  auto n64 = gate_xor(n62, a[5]);
  auto n63 = gate_not(b[5]);
  auto n65 = gate_nand(n64, n63);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n75 = gate_nand(n71, a[7]);
  auto n73 = gate_xor(n71, a[7]);
  auto n72 = gate_not(b[7]);
  auto n74 = gate_nand(n73, n72);
  y[0] = gate_nand(n75, n74);
}
template<> void CplainUint<8>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n41 = gate_not(b[6]);
  auto n70 = gate_nand(n41, a[6]);
  auto n68 = gate_xor(n41, a[6]);
  auto n42 = gate_not(a[1]);
  auto n47 = gate_nand(n42, b[1]);
  auto n45 = gate_xor(n42, b[1]);
  auto n43 = gate_not(b[0]);
  auto n44 = gate_nand(a[0], n43);
  auto n46 = gate_nand(n45, n44);
  auto n48 = gate_nand(n47, n46);
  auto n52 = gate_nand(n48, b[2]);
  auto n50 = gate_xor(n48, b[2]);
  auto n49 = gate_not(a[2]);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n57 = gate_nand(n53, b[3]);
  auto n55 = gate_xor(n53, b[3]);
  auto n54 = gate_not(a[3]);
  auto n56 = gate_nand(n55, n54);
  auto n40 = gate_and(n57, n56);
  auto n61 = gate_nand(n40, a[4]);
  auto n59 = gate_xor(n40, a[4]);
  auto n58 = gate_not(b[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n66 = gate_nand(n62, a[5]);
  auto n64 = gate_xor(n62, a[5]);
  auto n63 = gate_not(b[5]);
  auto n65 = gate_nand(n64, n63);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n75 = gate_nand(n71, b[7]);
  auto n73 = gate_xor(n71, b[7]);
  auto n72 = gate_not(a[7]);
  auto n74 = gate_nand(n73, n72);
  y[0] = gate_nand(n75, n74);
}
template<> void CplainUint<8>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n2 = gate_and(a[0], a[1]);
  auto n3 = gate_and(n2, a[2]);
  auto n4 = gate_and(n3, a[3]);
  auto n5 = gate_and(n4, a[4]);
  auto n6 = gate_and(n5, a[5]);
  y[0] = gate_not(a[0]);
  y[1] = gate_xor(a[0], a[1]);
  y[2] = gate_xor(n2, a[2]);
  y[3] = gate_xor(n3, a[3]);
  y[4] = gate_xor(n4, a[4]);
  y[5] = gate_xor(n5, a[5]);
  y[6] = gate_xor(n6, a[6]);
  auto n8 = gate_not(a[7]);
  auto n7 = gate_nand(n6, a[6]);
  y[7] = gate_xor(n8, n7);
}
template<> void CplainUint<8>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n29 = gate_xnor(b[7], a[7]);
  auto n35 = gate_xnor(a[1], b[1]);
  auto n37 = gate_xnor(b[4], a[4]);
  auto n38 = gate_xnor(b[5], a[5]);
  auto n39 = gate_xnor(b[6], a[6]);
  auto n40 = gate_not(b[2]);
  auto n45 = gate_xor(n40, a[2]);
  auto n41 = gate_not(a[3]);
  auto n44 = gate_xor(n41, b[3]);
  auto n42 = gate_not(a[0]);
  auto n43 = gate_xor(n42, b[0]);
  auto n31 = gate_and(n44, n43);
  auto n30 = gate_and(n31, n35);
  auto n36 = gate_and(n45, n30);
  auto n33 = gate_and(n36, n38);
  auto n32 = gate_and(n33, n37);
  auto n34 = gate_and(n32, n39);
  y[0] = gate_nand(n34, n29);
}
template<> void CplainUint<8>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n29 = gate_not(a[1]);
  auto n28 = gate_not(a[3]);
  auto n25 = gate_and(n29, n28);
  auto n31 = gate_not(a[2]);
  auto n30 = gate_not(a[0]);
  auto n24 = gate_and(n31, n30);
  auto n22 = gate_and(n25, n24);
  auto n33 = gate_not(a[5]);
  auto n32 = gate_not(a[7]);
  auto n27 = gate_and(n33, n32);
  auto n35 = gate_not(a[6]);
  auto n34 = gate_not(a[4]);
  auto n26 = gate_and(n35, n34);
  auto n23 = gate_and(n27, n26);
  auto n36 = gate_nand(n22, n23);
  y[7] = gate_mux(c[7], b[7], n36);
  y[0] = gate_mux(c[0], b[0], n36);
  y[1] = gate_mux(c[1], b[1], n36);
  y[2] = gate_mux(c[2], b[2], n36);
  y[3] = gate_mux(c[3], b[3], n36);
  y[4] = gate_mux(c[4], b[4], n36);
  y[5] = gate_mux(c[5], b[5], n36);
  y[6] = gate_mux(c[6], b[6], n36);
}
template<> void CplainUint<8>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n39 = gate_not(a[7]);
  auto n74 = gate_nand(n39, b[7]);
  auto n72 = gate_xor(n39, b[7]);
  auto n40 = gate_not(a[5]);
  auto n65 = gate_nand(n40, b[5]);
  auto n63 = gate_xor(n40, b[5]);
  auto n41 = gate_not(a[3]);
  auto n56 = gate_nand(n41, b[3]);
  auto n54 = gate_xor(n41, b[3]);
  auto n42 = gate_not(a[2]);
  auto n52 = gate_nand(n42, b[2]);
  auto n50 = gate_xor(n42, b[2]);
  auto n43 = gate_not(a[1]);
  auto n48 = gate_nand(n43, b[1]);
  auto n46 = gate_xor(n43, b[1]);
  auto n44 = gate_not(b[0]);
  auto n45 = gate_nand(a[0], n44);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n55 = gate_nand(n54, n53);
  auto n57 = gate_nand(n56, n55);
  auto n61 = gate_nand(n57, b[4]);
  auto n59 = gate_xor(n57, b[4]);
  auto n58 = gate_not(a[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n64 = gate_nand(n63, n62);
  auto n66 = gate_nand(n65, n64);
  auto n70 = gate_nand(n66, b[6]);
  auto n68 = gate_xor(n66, b[6]);
  auto n67 = gate_not(a[6]);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n73 = gate_nand(n72, n71);
  y[0] = gate_nand(n74, n73);
}
template<> void CplainUint<8>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n39 = gate_not(b[7]);
  auto n74 = gate_nand(n39, a[7]);
  auto n72 = gate_xor(n39, a[7]);
  auto n40 = gate_not(a[5]);
  auto n65 = gate_nand(n40, b[5]);
  auto n63 = gate_xor(n40, b[5]);
  auto n41 = gate_not(a[3]);
  auto n56 = gate_nand(n41, b[3]);
  auto n54 = gate_xor(n41, b[3]);
  auto n42 = gate_not(a[2]);
  auto n52 = gate_nand(n42, b[2]);
  auto n50 = gate_xor(n42, b[2]);
  auto n43 = gate_not(a[1]);
  auto n48 = gate_nand(n43, b[1]);
  auto n46 = gate_xor(n43, b[1]);
  auto n44 = gate_not(b[0]);
  auto n45 = gate_nand(a[0], n44);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n55 = gate_nand(n54, n53);
  auto n57 = gate_nand(n56, n55);
  auto n61 = gate_nand(n57, b[4]);
  auto n59 = gate_xor(n57, b[4]);
  auto n58 = gate_not(a[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n64 = gate_nand(n63, n62);
  auto n66 = gate_nand(n65, n64);
  auto n70 = gate_nand(n66, b[6]);
  auto n68 = gate_xor(n66, b[6]);
  auto n67 = gate_not(a[6]);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n73 = gate_nand(n72, n71);
  y[0] = gate_nand(n74, n73);
}
template<> void CplainUint<8>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n58 = gate_not(b[1]);
  auto n57 = gate_not(b[3]);
  auto n50 = gate_and(n58, n57);
  auto n60 = gate_not(b[2]);
  auto n59 = gate_not(b[0]);
  auto n49 = gate_and(n60, n59);
  auto n45 = gate_and(n50, n49);
  auto n62 = gate_not(b[5]);
  auto n61 = gate_not(b[7]);
  auto n52 = gate_and(n62, n61);
  auto n64 = gate_not(b[6]);
  auto n63 = gate_not(b[4]);
  auto n51 = gate_and(n64, n63);
  auto n46 = gate_and(n52, n51);
  auto n74 = gate_nand(n45, n46);
  auto n66 = gate_not(a[1]);
  auto n65 = gate_not(a[3]);
  auto n54 = gate_and(n66, n65);
  auto n68 = gate_not(a[2]);
  auto n67 = gate_not(a[0]);
  auto n53 = gate_and(n68, n67);
  auto n47 = gate_and(n54, n53);
  auto n70 = gate_not(a[5]);
  auto n69 = gate_not(a[7]);
  auto n56 = gate_and(n70, n69);
  auto n72 = gate_not(a[6]);
  auto n71 = gate_not(a[4]);
  auto n55 = gate_and(n72, n71);
  auto n48 = gate_and(n56, n55);
  auto n73 = gate_nand(n47, n48);
  y[0] = gate_and(n74, n73);
}
template<> void CplainUint<8>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n31 = gate_not(a[0]);
  auto n36 = gate_not(a[4]);
  auto n30 = gate_not(a[1]);
  auto n26 = gate_and(n31, n30);
  auto n33 = gate_not(a[3]);
  auto n32 = gate_not(a[6]);
  auto n28 = gate_and(n33, n32);
  auto n35 = gate_not(a[2]);
  auto n34 = gate_not(a[5]);
  auto n27 = gate_and(n35, n34);
  auto n24 = gate_and(n28, n27);
  auto n37 = gate_not(a[7]);
  auto n29 = gate_and(n37, n36);
  auto n25 = gate_and(n24, n29);
  y[0] = gate_and(n26, n25);
}
template<> void CplainUint<8>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n60 = gate_not(a[5]);
  auto n59 = gate_not(a[7]);
  auto n58 = gate_and(n60, n59);
  auto n62 = gate_not(a[6]);
  auto n61 = gate_not(a[4]);
  auto n57 = gate_and(n62, n61);
  auto n50 = gate_and(n58, n57);
  auto n64 = gate_not(b[5]);
  auto n63 = gate_not(b[7]);
  auto n54 = gate_and(n64, n63);
  auto n66 = gate_not(b[6]);
  auto n65 = gate_not(b[4]);
  auto n53 = gate_and(n66, n65);
  auto n48 = gate_and(n54, n53);
  auto n46 = gate_and(n50, n48);
  auto n68 = gate_not(b[1]);
  auto n67 = gate_not(b[3]);
  auto n52 = gate_and(n68, n67);
  auto n70 = gate_not(b[2]);
  auto n69 = gate_not(b[0]);
  auto n51 = gate_and(n70, n69);
  auto n47 = gate_and(n52, n51);
  auto n72 = gate_not(a[1]);
  auto n71 = gate_not(a[3]);
  auto n56 = gate_and(n72, n71);
  auto n74 = gate_not(a[2]);
  auto n73 = gate_not(a[0]);
  auto n55 = gate_and(n74, n73);
  auto n49 = gate_and(n56, n55);
  auto n45 = gate_and(n47, n49);
  y[0] = gate_nand(n46, n45);
}
template<> void CplainUint<8>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n41 = gate_not(a[6]);
  auto n70 = gate_nand(n41, b[6]);
  auto n68 = gate_xor(n41, b[6]);
  auto n42 = gate_not(b[1]);
  auto n47 = gate_nand(n42, a[1]);
  auto n45 = gate_xor(n42, a[1]);
  auto n43 = gate_not(a[0]);
  auto n44 = gate_nand(b[0], n43);
  auto n46 = gate_nand(n45, n44);
  auto n48 = gate_nand(n47, n46);
  auto n52 = gate_nand(n48, a[2]);
  auto n50 = gate_xor(n48, a[2]);
  auto n49 = gate_not(b[2]);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n57 = gate_nand(n53, a[3]);
  auto n55 = gate_xor(n53, a[3]);
  auto n54 = gate_not(b[3]);
  auto n56 = gate_nand(n55, n54);
  auto n40 = gate_and(n57, n56);
  auto n61 = gate_nand(n40, b[4]);
  auto n59 = gate_xor(n40, b[4]);
  auto n58 = gate_not(a[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n66 = gate_nand(n62, b[5]);
  auto n64 = gate_xor(n62, b[5]);
  auto n63 = gate_not(a[5]);
  auto n65 = gate_nand(n64, n63);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n75 = gate_nand(n71, b[7]);
  auto n73 = gate_xor(n71, b[7]);
  auto n72 = gate_not(a[7]);
  auto n74 = gate_nand(n73, n72);
  y[0] = gate_nand(n75, n74);
}
template<> void CplainUint<8>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n41 = gate_not(a[6]);
  auto n70 = gate_nand(n41, b[6]);
  auto n68 = gate_xor(n41, b[6]);
  auto n42 = gate_not(b[1]);
  auto n47 = gate_nand(n42, a[1]);
  auto n45 = gate_xor(n42, a[1]);
  auto n43 = gate_not(a[0]);
  auto n44 = gate_nand(b[0], n43);
  auto n46 = gate_nand(n45, n44);
  auto n48 = gate_nand(n47, n46);
  auto n52 = gate_nand(n48, a[2]);
  auto n50 = gate_xor(n48, a[2]);
  auto n49 = gate_not(b[2]);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n57 = gate_nand(n53, a[3]);
  auto n55 = gate_xor(n53, a[3]);
  auto n54 = gate_not(b[3]);
  auto n56 = gate_nand(n55, n54);
  auto n40 = gate_and(n57, n56);
  auto n61 = gate_nand(n40, b[4]);
  auto n59 = gate_xor(n40, b[4]);
  auto n58 = gate_not(a[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n66 = gate_nand(n62, b[5]);
  auto n64 = gate_xor(n62, b[5]);
  auto n63 = gate_not(a[5]);
  auto n65 = gate_nand(n64, n63);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n75 = gate_nand(n71, a[7]);
  auto n73 = gate_xor(n71, a[7]);
  auto n72 = gate_not(b[7]);
  auto n74 = gate_nand(n73, n72);
  y[0] = gate_nand(n75, n74);
}
template<> void CplainUint<8>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n163 = gate_not(b[7]);
  auto n168 = gate_not(b[6]);
  auto n8 = gate_and(n163, n168);
  auto n173 = gate_not(b[5]);
  auto n5 = gate_and(n8, n173);
  auto n178 = gate_not(b[4]);
  auto n4 = gate_and(n5, n178);
  auto n183 = gate_not(b[3]);
  auto n3 = gate_and(n4, n183);
  auto n188 = gate_not(b[2]);
  auto n2 = gate_and(n3, n188);
  auto n191 = gate_not(b[1]);
  auto n6 = gate_and(n2, n191);
  auto n21 = gate_nand(b[0], n6);
  auto n17 = gate_and(a[7], n21);
  auto n22 = gate_mux(a[7], b[0], n191);
  auto n16 = gate_and(n2, n22);
  auto n23 = gate_not(a[6]);
  auto n24 = gate_nand(b[0], n23);
  auto n25 = gate_nand(n16, n24);
  auto n1 = gate_and(n17, n25);
  auto n39 = gate_nand(a[6], n25);
  auto n26 = gate_not(n39);
  auto n29 = gate_nand(n26, n191);
  auto n31 = gate_xor(n191, n39);
  auto n27 = gate_not(n31);
  auto n42 = gate_not(a[5]);
  auto n32 = gate_nand(b[0], n42);
  auto n28 = gate_nand(n27, n32);
  auto n33 = gate_nand(n29, n28);
  auto n34 = gate_xor(n33, n188);
  auto n30 = gate_nand(n3, n34);
  auto n7 = gate_and(n1, n30);
  auto n38 = gate_nand(n32, n31);
  auto n36 = gate_nand(n33, n188);
  auto n35 = gate_nand(n34, n1);
  auto n37 = gate_nand(n36, n35);
  auto n9 = gate_and(n3, n37);
  auto n40 = gate_mux(n39, n38, n9);
  auto n59 = gate_not(n40);
  auto n48 = gate_nand(n188, n59);
  auto n46 = gate_xor(b[2], n40);
  auto n41 = gate_nand(n9, b[0]);
  auto n64 = gate_xor(n42, n41);
  auto n45 = gate_nand(n191, n64);
  auto n43 = gate_xor(n191, n64);
  auto n67 = gate_not(a[4]);
  auto n61 = gate_nand(b[0], n67);
  auto n44 = gate_nand(n43, n61);
  auto n56 = gate_nand(n45, n44);
  auto n47 = gate_nand(n46, n56);
  auto n51 = gate_nand(n48, n47);
  auto n49 = gate_xor(n183, n51);
  auto n50 = gate_nand(n4, n49);
  auto n20 = gate_and(n7, n50);
  auto n52 = gate_xor(n183, n7);
  auto n54 = gate_nand(n52, n51);
  auto n53 = gate_nand(n7, n183);
  auto n55 = gate_nand(n54, n53);
  auto n19 = gate_and(n4, n55);
  auto n57 = gate_xor(n56, n188);
  auto n58 = gate_nand(n19, n57);
  auto n87 = gate_xor(n59, n58);
  auto n60 = gate_not(n87);
  auto n76 = gate_nand(n60, n183);
  auto n74 = gate_xor(b[3], n87);
  auto n62 = gate_xor(n61, n191);
  auto n63 = gate_nand(n19, n62);
  auto n91 = gate_xor(n64, n63);
  auto n65 = gate_not(n91);
  auto n73 = gate_nand(n65, n188);
  auto n71 = gate_xor(b[2], n91);
  auto n66 = gate_nand(n19, b[0]);
  auto n95 = gate_xor(n67, n66);
  auto n70 = gate_nand(n191, n95);
  auto n68 = gate_xor(n191, n95);
  auto n98 = gate_not(a[3]);
  auto n92 = gate_nand(b[0], n98);
  auto n69 = gate_nand(n68, n92);
  auto n88 = gate_nand(n70, n69);
  auto n72 = gate_nand(n71, n88);
  auto n84 = gate_nand(n73, n72);
  auto n75 = gate_nand(n74, n84);
  auto n79 = gate_nand(n76, n75);
  auto n77 = gate_xor(n178, n79);
  auto n78 = gate_nand(n5, n77);
  auto n10 = gate_and(n20, n78);
  auto n80 = gate_xor(n178, n20);
  auto n82 = gate_nand(n80, n79);
  auto n81 = gate_nand(n20, n178);
  auto n83 = gate_nand(n82, n81);
  auto n18 = gate_and(n5, n83);
  auto n85 = gate_xor(n183, n84);
  auto n86 = gate_nand(n18, n85);
  auto n121 = gate_xor(n87, n86);
  auto n110 = gate_nand(n121, n178);
  auto n108 = gate_xor(n178, n121);
  auto n89 = gate_xor(n188, n88);
  auto n90 = gate_nand(n18, n89);
  auto n126 = gate_xor(n91, n90);
  auto n107 = gate_nand(n126, n183);
  auto n105 = gate_xor(n183, n126);
  auto n93 = gate_xor(n92, n191);
  auto n94 = gate_nand(n18, n93);
  auto n131 = gate_xor(n95, n94);
  auto n96 = gate_not(n131);
  auto n104 = gate_nand(n96, n188);
  auto n102 = gate_xor(b[2], n131);
  auto n97 = gate_nand(n18, b[0]);
  auto n135 = gate_xor(n98, n97);
  auto n101 = gate_nand(n191, n135);
  auto n99 = gate_xor(n191, n135);
  auto n138 = gate_not(a[2]);
  auto n132 = gate_nand(b[0], n138);
  auto n100 = gate_nand(n99, n132);
  auto n128 = gate_nand(n101, n100);
  auto n103 = gate_nand(n102, n128);
  auto n123 = gate_nand(n104, n103);
  auto n106 = gate_nand(n105, n123);
  auto n118 = gate_nand(n107, n106);
  auto n109 = gate_nand(n108, n118);
  auto n113 = gate_nand(n110, n109);
  auto n111 = gate_xor(n173, n113);
  auto n112 = gate_nand(n8, n111);
  auto n156 = gate_nand(n10, n112);
  auto n159 = gate_not(n156);
  auto n114 = gate_xor(n173, n10);
  auto n116 = gate_nand(n114, n113);
  auto n115 = gate_nand(n10, n173);
  auto n117 = gate_nand(n116, n115);
  auto n15 = gate_and(n8, n117);
  auto n119 = gate_xor(n178, n118);
  auto n120 = gate_nand(n15, n119);
  auto n167 = gate_xor(n121, n120);
  auto n122 = gate_not(n167);
  auto n153 = gate_nand(n122, n173);
  auto n151 = gate_xor(b[5], n167);
  auto n124 = gate_xor(n183, n123);
  auto n125 = gate_nand(n15, n124);
  auto n172 = gate_xor(n126, n125);
  auto n127 = gate_not(n172);
  auto n150 = gate_nand(n127, n178);
  auto n148 = gate_xor(b[4], n172);
  auto n129 = gate_xor(n188, n128);
  auto n130 = gate_nand(n15, n129);
  auto n177 = gate_xor(n131, n130);
  auto n147 = gate_nand(n177, n183);
  auto n145 = gate_xor(n183, n177);
  auto n133 = gate_xor(n132, n191);
  auto n134 = gate_nand(n15, n133);
  auto n182 = gate_xor(n135, n134);
  auto n136 = gate_not(n182);
  auto n144 = gate_nand(n136, n188);
  auto n142 = gate_xor(b[2], n182);
  auto n137 = gate_nand(n15, b[0]);
  auto n187 = gate_xor(n138, n137);
  auto n141 = gate_nand(n191, n187);
  auto n139 = gate_xor(n191, n187);
  auto n190 = gate_not(a[1]);
  auto n184 = gate_nand(b[0], n190);
  auto n140 = gate_nand(n139, n184);
  auto n179 = gate_nand(n141, n140);
  auto n143 = gate_nand(n142, n179);
  auto n174 = gate_nand(n144, n143);
  auto n146 = gate_nand(n145, n174);
  auto n169 = gate_nand(n147, n146);
  auto n149 = gate_nand(n148, n169);
  auto n164 = gate_nand(n150, n149);
  auto n152 = gate_nand(n151, n164);
  auto n157 = gate_nand(n153, n152);
  auto n154 = gate_xor(n168, n157);
  auto n155 = gate_nand(n154, n163);
  auto n13 = gate_and(n159, n155);
  auto n207 = gate_nand(n13, n163);
  auto n204 = gate_nand(b[7], n156);
  auto n158 = gate_xor(n168, n159);
  auto n161 = gate_nand(n158, n157);
  auto n160 = gate_nand(n159, n168);
  auto n162 = gate_nand(n161, n160);
  auto n12 = gate_and(n163, n162);
  auto n165 = gate_xor(n173, n164);
  auto n166 = gate_nand(n12, n165);
  auto n215 = gate_xor(n167, n166);
  auto n203 = gate_nand(n215, n168);
  auto n212 = gate_xor(n168, n215);
  auto n170 = gate_xor(n178, n169);
  auto n171 = gate_nand(n12, n170);
  auto n219 = gate_xor(n172, n171);
  auto n201 = gate_nand(n219, n173);
  auto n216 = gate_xor(n173, n219);
  auto n175 = gate_xor(n183, n174);
  auto n176 = gate_nand(n12, n175);
  auto n14 = gate_xnor(n177, n176);
  auto n199 = gate_nand(n14, n178);
  auto n220 = gate_xor(n178, n14);
  auto n180 = gate_xor(n188, n179);
  auto n181 = gate_nand(n12, n180);
  auto n226 = gate_xor(n182, n181);
  auto n197 = gate_nand(n226, n183);
  auto n223 = gate_xor(n183, n226);
  auto n185 = gate_xor(n184, n191);
  auto n186 = gate_nand(n12, n185);
  auto n11 = gate_xnor(n187, n186);
  auto n195 = gate_nand(n11, n188);
  auto n227 = gate_xor(n188, n11);
  auto n189 = gate_nand(n12, b[0]);
  auto n233 = gate_xor(n190, n189);
  auto n193 = gate_nand(n191, n233);
  auto n231 = gate_xor(n191, n233);
  auto n236 = gate_not(a[0]);
  auto n230 = gate_nand(b[0], n236);
  auto n192 = gate_nand(n231, n230);
  auto n228 = gate_nand(n193, n192);
  auto n194 = gate_nand(n227, n228);
  auto n224 = gate_nand(n195, n194);
  auto n196 = gate_nand(n223, n224);
  auto n221 = gate_nand(n197, n196);
  auto n198 = gate_nand(n220, n221);
  auto n217 = gate_nand(n199, n198);
  auto n200 = gate_nand(n216, n217);
  auto n213 = gate_nand(n201, n200);
  auto n202 = gate_nand(n212, n213);
  auto n208 = gate_nand(n203, n202);
  auto n205 = gate_nand(n204, n208);
  auto n234 = gate_nand(n207, n205);
  auto n206 = gate_not(n234);
  auto n211 = gate_nand(n13, n206);
  auto n209 = gate_not(n207);
  auto n210 = gate_nand(n209, n208);
  y[7] = gate_nand(n211, n210);
  auto n214 = gate_xor(n213, n212);
  y[6] = gate_mux(n215, n214, n234);
  auto n218 = gate_xor(n217, n216);
  y[5] = gate_mux(n219, n218, n234);
  auto n222 = gate_xor(n221, n220);
  y[4] = gate_mux(n14, n222, n234);
  auto n225 = gate_xor(n224, n223);
  y[3] = gate_mux(n226, n225, n234);
  auto n229 = gate_xor(n228, n227);
  y[2] = gate_mux(n11, n229, n234);
  auto n232 = gate_xor(n231, n230);
  y[1] = gate_mux(n233, n232, n234);
  auto n235 = gate_nand(n234, b[0]);
  y[0] = gate_xor(n236, n235);
}
template<> void CplainUint<8>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n25 = gate_not(a[1]);
  auto n255 = gate_not(a[0]);
  auto n27 = gate_nand(n25, n255);
  auto n26 = gate_nand(a[7], n27);
  auto n151 = gate_xor(a[2], n26);
  auto n201 = gate_not(b[7]);
  auto n259 = gate_xnor(n201, b[1]);
  auto n3 = gate_not(n259);
  auto n210 = gate_xor(b[6], n201);
  auto n275 = gate_xor(b[5], n201);
  auto n24 = gate_and(n275, n210);
  auto n216 = gate_not(n275);
  auto n29 = gate_not(n27);
  auto n28 = gate_not(a[2]);
  auto n89 = gate_nand(n29, n28);
  auto n31 = gate_not(n89);
  auto n30 = gate_not(a[3]);
  auto n67 = gate_nand(n31, n30);
  auto n33 = gate_not(n67);
  auto n32 = gate_not(a[4]);
  auto n35 = gate_nand(n33, n32);
  auto n34 = gate_nand(a[7], n35);
  auto n61 = gate_xor(a[5], n34);
  auto n269 = gate_xor(b[4], n201);
  auto n1 = gate_not(n269);
  auto n2 = gate_not(n1);
  auto n16 = gate_and(n24, n2);
  auto n228 = gate_xor(b[7], b[3]);
  auto n263 = gate_not(n228);
  auto n14 = gate_and(n16, n263);
  auto n231 = gate_xor(b[7], b[2]);
  auto n229 = gate_not(n231);
  auto n13 = gate_and(n14, n229);
  auto n15 = gate_and(n13, n3);
  auto n37 = gate_not(n35);
  auto n36 = gate_not(a[5]);
  auto n41 = gate_nand(n37, n36);
  auto n38 = gate_nand(a[7], n41);
  auto n43 = gate_xor(a[6], n38);
  auto n48 = gate_not(n43);
  auto n40 = gate_not(a[6]);
  auto n39 = gate_nand(b[0], n15);
  auto n18 = gate_and(n40, n39);
  auto n42 = gate_not(n41);
  auto n4 = gate_and(n42, a[7]);
  auto n17 = gate_and(n18, n4);
  auto n45 = gate_xor(n17, n3);
  auto n44 = gate_nand(n43, b[0]);
  auto n5 = gate_and(n13, n44);
  auto n55 = gate_nand(n45, n5);
  auto n23 = gate_and(n17, n55);
  auto n46 = gate_not(n55);
  auto n47 = gate_nand(n46, b[0]);
  auto n65 = gate_nand(n48, n47);
  auto n49 = gate_not(n65);
  auto n53 = gate_nand(n49, n3);
  auto n62 = gate_xor(n3, n65);
  auto n51 = gate_not(n62);
  auto n50 = gate_mux(b[7], n61, b[0]);
  auto n63 = gate_not(n50);
  auto n52 = gate_nand(n51, n63);
  auto n54 = gate_nand(n53, n52);
  auto n57 = gate_nand(n229, n54);
  auto n76 = gate_xor(n229, n54);
  auto n56 = gate_nand(n76, n23);
  auto n58 = gate_nand(n57, n56);
  auto n64 = gate_nand(n14, n58);
  auto n59 = gate_not(n64);
  auto n60 = gate_nand(n59, b[0]);
  auto n84 = gate_xor(n61, n60);
  auto n66 = gate_nand(n63, n62);
  auto n102 = gate_mux(n66, n65, n64);
  auto n98 = gate_not(n102);
  auto n75 = gate_nand(n229, n98);
  auto n73 = gate_xor(n229, n98);
  auto n72 = gate_nand(n84, n3);
  auto n70 = gate_xor(n84, n3);
  auto n68 = gate_nand(a[7], n67);
  auto n88 = gate_xor(a[4], n68);
  auto n69 = gate_mux(b[7], n88, b[0]);
  auto n81 = gate_not(n69);
  auto n71 = gate_nand(n70, n81);
  auto n100 = gate_nand(n72, n71);
  auto n74 = gate_nand(n73, n100);
  auto n110 = gate_nand(n75, n74);
  auto n79 = gate_nand(n110, n263);
  auto n77 = gate_nand(n14, n76);
  auto n12 = gate_and(n23, n77);
  auto n78 = gate_nand(n12, n263);
  auto n80 = gate_nand(n79, n78);
  auto n101 = gate_nand(n80, n16);
  auto n86 = gate_not(n101);
  auto n82 = gate_xor(n3, n81);
  auto n83 = gate_nand(n86, n82);
  auto n122 = gate_xor(n84, n83);
  auto n85 = gate_not(n122);
  auto n97 = gate_nand(n85, n229);
  auto n95 = gate_xor(n229, n85);
  auto n87 = gate_nand(n86, b[0]);
  auto n126 = gate_xor(n88, n87);
  auto n94 = gate_nand(n126, n3);
  auto n92 = gate_xor(n126, n3);
  auto n90 = gate_nand(a[7], n89);
  auto n130 = gate_xor(a[3], n90);
  auto n91 = gate_mux(b[7], n130, b[0]);
  auto n123 = gate_not(n91);
  auto n93 = gate_nand(n92, n123);
  auto n119 = gate_nand(n94, n93);
  auto n96 = gate_nand(n95, n119);
  auto n106 = gate_nand(n97, n96);
  auto n99 = gate_xor(n231, n98);
  auto n103 = gate_nand(n100, n99);
  auto n116 = gate_mux(n103, n102, n101);
  auto n105 = gate_not(n116);
  auto n104 = gate_xor(n228, n105);
  auto n117 = gate_nand(n106, n104);
  auto n109 = gate_nand(n105, n263);
  auto n107 = gate_xor(n105, n263);
  auto n108 = gate_nand(n107, n106);
  auto n144 = gate_nand(n109, n108);
  auto n114 = gate_nand(n269, n144);
  auto n111 = gate_xor(n263, n110);
  auto n112 = gate_nand(n16, n111);
  auto n7 = gate_and(n12, n112);
  auto n113 = gate_nand(n7, n2);
  auto n115 = gate_nand(n114, n113);
  auto n118 = gate_nand(n24, n115);
  auto n159 = gate_mux(n117, n116, n118);
  auto n155 = gate_not(n159);
  auto n143 = gate_nand(n155, n2);
  auto n141 = gate_xor(n155, n2);
  auto n128 = gate_not(n118);
  auto n120 = gate_xor(n229, n119);
  auto n121 = gate_nand(n128, n120);
  auto n161 = gate_xor(n122, n121);
  auto n140 = gate_nand(n161, n263);
  auto n138 = gate_xor(n263, n161);
  auto n124 = gate_xor(n3, n123);
  auto n125 = gate_nand(n128, n124);
  auto n169 = gate_xor(n126, n125);
  auto n127 = gate_not(n169);
  auto n137 = gate_nand(n127, n229);
  auto n135 = gate_xor(n229, n127);
  auto n129 = gate_nand(n128, b[0]);
  auto n170 = gate_xor(n130, n129);
  auto n134 = gate_nand(n170, n3);
  auto n132 = gate_xor(n170, n3);
  auto n131 = gate_mux(b[7], n151, b[0]);
  auto n171 = gate_not(n131);
  auto n133 = gate_nand(n132, n171);
  auto n166 = gate_nand(n134, n133);
  auto n136 = gate_nand(n135, n166);
  auto n162 = gate_nand(n137, n136);
  auto n139 = gate_nand(n138, n162);
  auto n157 = gate_nand(n140, n139);
  auto n142 = gate_nand(n141, n157);
  auto n152 = gate_nand(n143, n142);
  auto n148 = gate_nand(n275, n152);
  auto n145 = gate_xor(n2, n144);
  auto n146 = gate_nand(n24, n145);
  auto n20 = gate_and(n7, n146);
  auto n147 = gate_nand(n20, n275);
  auto n149 = gate_nand(n148, n147);
  auto n158 = gate_nand(n210, n149);
  auto n173 = gate_not(n158);
  auto n150 = gate_nand(n173, b[0]);
  auto n198 = gate_xor(n151, n150);
  auto n153 = gate_xor(n275, n152);
  auto n154 = gate_nand(n153, n210);
  auto n6 = gate_and(n20, n154);
  auto n194 = gate_nand(n6, n210);
  auto n156 = gate_xor(n1, n155);
  auto n160 = gate_nand(n157, n156);
  auto n209 = gate_mux(n160, n159, n158);
  auto n205 = gate_not(n209);
  auto n192 = gate_nand(n205, n275);
  auto n190 = gate_xor(n205, n275);
  auto n165 = gate_not(n161);
  auto n163 = gate_xor(n263, n162);
  auto n164 = gate_nand(n173, n163);
  auto n214 = gate_xor(n165, n164);
  auto n189 = gate_nand(n214, n2);
  auto n187 = gate_xor(n2, n214);
  auto n167 = gate_xor(n229, n166);
  auto n168 = gate_nand(n173, n167);
  auto n220 = gate_xor(n169, n168);
  auto n186 = gate_nand(n220, n263);
  auto n184 = gate_xor(n263, n220);
  auto n175 = gate_not(n170);
  auto n172 = gate_xor(n3, n171);
  auto n174 = gate_nand(n173, n172);
  auto n226 = gate_xor(n175, n174);
  auto n183 = gate_nand(n226, n229);
  auto n181 = gate_xor(n229, n226);
  auto n180 = gate_nand(n198, n3);
  auto n178 = gate_xor(n198, n3);
  auto n176 = gate_nand(a[7], a[0]);
  auto n200 = gate_xor(a[1], n176);
  auto n177 = gate_mux(b[7], n200, b[0]);
  auto n195 = gate_not(n177);
  auto n179 = gate_nand(n178, n195);
  auto n222 = gate_nand(n180, n179);
  auto n182 = gate_nand(n181, n222);
  auto n217 = gate_nand(n183, n182);
  auto n185 = gate_nand(n184, n217);
  auto n211 = gate_nand(n186, n185);
  auto n188 = gate_nand(n187, n211);
  auto n207 = gate_nand(n189, n188);
  auto n191 = gate_nand(n190, n207);
  auto n248 = gate_nand(n192, n191);
  auto n281 = gate_not(n210);
  auto n193 = gate_nand(n248, n210);
  auto n223 = gate_nand(n194, n193);
  auto n196 = gate_xor(n3, n195);
  auto n197 = gate_nand(n223, n196);
  auto n253 = gate_xor(n198, n197);
  auto n199 = gate_nand(b[0], n223);
  auto n262 = gate_xor(n200, n199);
  auto n204 = gate_nand(n262, n3);
  auto n202 = gate_xor(n262, n3);
  auto n258 = gate_mux(n201, a[0], b[0]);
  auto n203 = gate_nand(n202, n258);
  auto n232 = gate_nand(n204, n203);
  auto n251 = gate_xor(n232, n229);
  auto n206 = gate_xor(n205, n216);
  auto n208 = gate_nand(n207, n206);
  auto n287 = gate_mux(n209, n208, n223);
  auto n282 = gate_not(n287);
  auto n247 = gate_nand(n282, n210);
  auto n245 = gate_xor(n282, n210);
  auto n212 = gate_xor(n211, n2);
  auto n213 = gate_nand(n212, n223);
  auto n279 = gate_xor(n214, n213);
  auto n215 = gate_not(n279);
  auto n244 = gate_nand(n215, n275);
  auto n242 = gate_xor(n216, n279);
  auto n218 = gate_xor(n217, n263);
  auto n219 = gate_nand(n218, n223);
  auto n273 = gate_xor(n220, n219);
  auto n221 = gate_not(n273);
  auto n241 = gate_nand(n221, n2);
  auto n239 = gate_xor(n1, n273);
  auto n224 = gate_xor(n222, n229);
  auto n225 = gate_nand(n224, n223);
  auto n267 = gate_xor(n226, n225);
  auto n227 = gate_not(n267);
  auto n238 = gate_nand(n227, n263);
  auto n236 = gate_xor(n228, n267);
  auto n230 = gate_not(n253);
  auto n235 = gate_nand(n230, n229);
  auto n233 = gate_xor(n231, n253);
  auto n234 = gate_nand(n233, n232);
  auto n264 = gate_nand(n235, n234);
  auto n237 = gate_nand(n236, n264);
  auto n270 = gate_nand(n238, n237);
  auto n240 = gate_nand(n239, n270);
  auto n276 = gate_nand(n241, n240);
  auto n243 = gate_nand(n242, n276);
  auto n284 = gate_nand(n244, n243);
  auto n246 = gate_nand(n245, n284);
  auto n290 = gate_nand(n247, n246);
  auto n250 = gate_not(n290);
  auto n249 = gate_mux(n281, n210, n248);
  auto n289 = gate_nand(n6, n249);
  auto n285 = gate_nand(n250, n289);
  auto n252 = gate_nand(n251, n285);
  auto n254 = gate_xor(n253, n252);
  auto n298 = gate_xor(a[7], n254);
  auto n257 = gate_xor(a[7], n255);
  auto n256 = gate_nand(b[0], n285);
  auto n302 = gate_xor(n257, n256);
  y[0] = gate_xor(a[7], n302);
  auto n10 = gate_and(a[7], n302);
  auto n260 = gate_xor(n3, n258);
  auto n261 = gate_nand(n285, n260);
  auto n301 = gate_xor(n262, n261);
  auto n22 = gate_and(n10, n301);
  auto n11 = gate_and(n298, n22);
  auto n265 = gate_xor(n264, n263);
  auto n266 = gate_nand(n265, n285);
  auto n268 = gate_xor(n267, n266);
  auto n297 = gate_xor(a[7], n268);
  auto n19 = gate_and(n11, n297);
  auto n271 = gate_xor(n270, n2);
  auto n272 = gate_nand(n271, n285);
  auto n274 = gate_xor(n273, n272);
  auto n296 = gate_xor(a[7], n274);
  auto n9 = gate_and(n19, n296);
  auto n277 = gate_xor(n276, n275);
  auto n278 = gate_nand(n277, n285);
  auto n280 = gate_xor(n279, n278);
  auto n295 = gate_xor(a[7], n280);
  auto n21 = gate_and(n9, n295);
  auto n283 = gate_xor(n282, n281);
  auto n286 = gate_nand(n284, n283);
  auto n288 = gate_mux(n287, n286, n285);
  auto n8 = gate_xnor(a[7], n288);
  auto n294 = gate_nand(n21, n8);
  auto n291 = gate_not(n289);
  auto n292 = gate_nand(n291, n290);
  auto n293 = gate_nand(a[7], n292);
  y[7] = gate_xor(n294, n293);
  y[6] = gate_xor(n21, n8);
  y[5] = gate_xor(n9, n295);
  y[4] = gate_xor(n19, n296);
  y[3] = gate_xor(n11, n297);
  y[2] = gate_xor(n298, n22);
  auto n299 = gate_not(n302);
  auto n300 = gate_nand(a[7], n299);
  y[1] = gate_xor(n301, n300);
}
template<> void CplainUint<8>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_and(b[0], a[6]);
  auto n3 = gate_and(b[1], a[4]);
  auto n4 = gate_and(b[0], a[4]);
  auto n5 = gate_and(a[2], b[1]);
  auto n7 = gate_and(b[1], a[1]);
  auto n8 = gate_and(b[0], a[1]);
  auto n9 = gate_and(b[1], a[0]);
  y[0] = gate_and(b[0], a[0]);
  y[1] = gate_xor(n8, n9);
  auto n17 = gate_nand(n8, n9);
  auto n11 = gate_not(n17);
  auto n12 = gate_nand(a[0], b[2]);
  auto n16 = gate_xor(n7, n12);
  auto n15 = gate_nand(a[2], b[0]);
  auto n18 = gate_xor(n16, n15);
  y[2] = gate_xor(n11, n18);
  auto n24 = gate_nand(a[1], b[2]);
  auto n25 = gate_nand(b[3], a[0]);
  auto n14 = gate_xor(n24, n25);
  auto n13 = gate_not(n12);
  auto n29 = gate_nand(n7, n13);
  auto n33 = gate_xor(n14, n29);
  auto n21 = gate_not(n33);
  auto n20 = gate_nand(n16, n15);
  auto n19 = gate_nand(n18, n17);
  auto n32 = gate_nand(n20, n19);
  auto n22 = gate_nand(a[3], b[0]);
  auto n31 = gate_xor(n5, n22);
  auto n34 = gate_xor(n32, n31);
  y[3] = gate_xor(n21, n34);
  auto n23 = gate_not(n22);
  auto n47 = gate_nand(n5, n23);
  auto n27 = gate_not(n24);
  auto n26 = gate_not(n25);
  auto n28 = gate_nand(n27, n26);
  auto n48 = gate_nand(n29, n28);
  auto n55 = gate_nand(a[3], b[1]);
  auto n49 = gate_xor(n4, n55);
  auto n30 = gate_xor(n48, n49);
  auto n40 = gate_xor(n47, n30);
  auto n38 = gate_not(n40);
  auto n36 = gate_nand(n32, n31);
  auto n35 = gate_nand(n34, n33);
  auto n39 = gate_nand(n36, n35);
  auto n41 = gate_not(n39);
  auto n59 = gate_nand(b[3], a[1]);
  auto n58 = gate_nand(b[4], a[0]);
  auto n61 = gate_xor(n59, n58);
  auto n60 = gate_nand(a[2], b[2]);
  auto n43 = gate_xor(n61, n60);
  auto n37 = gate_xor(n41, n43);
  y[4] = gate_xor(n38, n37);
  auto n45 = gate_nand(n39, n38);
  auto n42 = gate_nand(n41, n40);
  auto n44 = gate_nand(n43, n42);
  auto n93 = gate_nand(n45, n44);
  auto n46 = gate_not(n49);
  auto n54 = gate_nand(n46, n48);
  auto n52 = gate_not(n47);
  auto n50 = gate_not(n48);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n2 = gate_and(n54, n53);
  auto n95 = gate_xor(n93, n2);
  auto n73 = gate_nand(b[0], a[5]);
  auto n80 = gate_xor(n73, n3);
  auto n56 = gate_not(n55);
  auto n79 = gate_nand(n4, n56);
  auto n78 = gate_nand(a[3], b[2]);
  auto n81 = gate_xor(n79, n78);
  auto n70 = gate_xor(n80, n81);
  auto n85 = gate_nand(b[5], a[0]);
  auto n89 = gate_nand(b[3], a[2]);
  auto n84 = gate_nand(b[4], a[1]);
  auto n57 = gate_xor(n89, n84);
  auto n65 = gate_xor(n85, n57);
  auto n63 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n66 = gate_nand(n63, n62);
  auto n64 = gate_xor(n65, n66);
  auto n94 = gate_xor(n70, n64);
  y[5] = gate_xnor(n95, n94);
  auto n72 = gate_nand(n65, n66);
  auto n68 = gate_not(n65);
  auto n67 = gate_not(n66);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n130 = gate_nand(n72, n71);
  auto n74 = gate_not(n73);
  auto n155 = gate_nand(n74, n3);
  auto n154 = gate_nand(b[3], a[3]);
  auto n156 = gate_nand(a[2], b[4]);
  auto n75 = gate_xor(n154, n156);
  auto n132 = gate_xor(n155, n75);
  auto n118 = gate_nand(a[4], b[2]);
  auto n117 = gate_nand(a[1], b[5]);
  auto n119 = gate_nand(a[0], b[6]);
  auto n76 = gate_xor(n117, n119);
  auto n131 = gate_xor(n118, n76);
  auto n77 = gate_xor(n132, n131);
  auto n104 = gate_xor(n130, n77);
  auto n83 = gate_nand(n79, n78);
  auto n82 = gate_nand(n81, n80);
  auto n143 = gate_nand(n83, n82);
  auto n91 = gate_nand(n84, n85);
  auto n87 = gate_not(n84);
  auto n86 = gate_not(n85);
  auto n88 = gate_nand(n87, n86);
  auto n90 = gate_nand(n89, n88);
  auto n146 = gate_nand(n91, n90);
  auto n92 = gate_nand(b[1], a[5]);
  auto n145 = gate_xor(n1, n92);
  auto n144 = gate_xor(n146, n145);
  auto n100 = gate_xor(n143, n144);
  auto n97 = gate_nand(n2, n93);
  auto n96 = gate_nand(n95, n94);
  auto n99 = gate_nand(n97, n96);
  auto n102 = gate_not(n99);
  auto n98 = gate_xor(n100, n102);
  y[6] = gate_xor(n104, n98);
  auto n106 = gate_nand(n100, n99);
  auto n101 = gate_not(n100);
  auto n103 = gate_nand(n102, n101);
  auto n105 = gate_nand(n104, n103);
  auto n125 = gate_nand(n106, n105);
  auto n108 = gate_nand(a[6], b[1]);
  auto n107 = gate_nand(a[7], b[0]);
  auto n113 = gate_xor(n108, n107);
  auto n110 = gate_not(b[2]);
  auto n109 = gate_nand(b[1], n1);
  auto n111 = gate_xor(n110, n109);
  auto n112 = gate_nand(a[5], n111);
  auto n123 = gate_xor(n113, n112);
  auto n115 = gate_not(n119);
  auto n114 = gate_not(n118);
  auto n116 = gate_nand(n115, n114);
  auto n121 = gate_nand(n117, n116);
  auto n120 = gate_nand(n119, n118);
  auto n122 = gate_nand(n121, n120);
  auto n124 = gate_xor(n123, n122);
  auto n127 = gate_xor(n125, n124);
  auto n126 = gate_nand(b[6], a[1]);
  auto n138 = gate_xor(n127, n126);
  auto n129 = gate_not(n132);
  auto n128 = gate_not(n131);
  auto n136 = gate_nand(n129, n128);
  auto n134 = gate_not(n130);
  auto n133 = gate_nand(n132, n131);
  auto n135 = gate_nand(n134, n133);
  auto n137 = gate_nand(n136, n135);
  auto n164 = gate_xor(n138, n137);
  auto n140 = gate_nand(b[5], a[2]);
  auto n139 = gate_nand(b[4], a[3]);
  auto n162 = gate_xor(n140, n139);
  auto n142 = gate_nand(b[7], a[0]);
  auto n141 = gate_nand(a[4], b[3]);
  auto n150 = gate_xor(n142, n141);
  auto n148 = gate_nand(n144, n143);
  auto n147 = gate_nand(n146, n145);
  auto n149 = gate_nand(n148, n147);
  auto n160 = gate_xor(n150, n149);
  auto n152 = gate_not(n156);
  auto n151 = gate_not(n155);
  auto n153 = gate_nand(n152, n151);
  auto n158 = gate_nand(n154, n153);
  auto n157 = gate_nand(n156, n155);
  auto n159 = gate_nand(n158, n157);
  auto n161 = gate_xor(n160, n159);
  auto n163 = gate_xor(n162, n161);
  y[7] = gate_xor(n164, n163);
}
template<> void CplainUint<8>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n14 = gate_and(a[5], a[7]);
  auto n18 = gate_and(a[2], a[0]);
  auto n19 = gate_and(a[1], a[3]);
  auto n16 = gate_and(n19, n18);
  auto n20 = gate_and(a[6], a[4]);
  auto n17 = gate_and(n14, n20);
  y[0] = gate_and(n16, n17);
}
template<> void CplainUint<8>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n14 = gate_and(a[5], a[7]);
  auto n17 = gate_and(a[2], a[0]);
  auto n18 = gate_and(a[1], a[3]);
  auto n15 = gate_and(n18, n17);
  auto n19 = gate_and(a[6], a[4]);
  auto n16 = gate_and(n14, n19);
  y[0] = gate_nand(n15, n16);
}
template<> void CplainUint<8>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n31 = gate_not(a[0]);
  auto n36 = gate_not(a[4]);
  auto n30 = gate_not(a[1]);
  auto n26 = gate_and(n31, n30);
  auto n33 = gate_not(a[3]);
  auto n32 = gate_not(a[6]);
  auto n28 = gate_and(n33, n32);
  auto n35 = gate_not(a[2]);
  auto n34 = gate_not(a[5]);
  auto n27 = gate_and(n35, n34);
  auto n24 = gate_and(n28, n27);
  auto n37 = gate_not(a[7]);
  auto n29 = gate_and(n37, n36);
  auto n25 = gate_and(n24, n29);
  y[0] = gate_and(n26, n25);
}
template<> void CplainUint<8>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n28 = gate_not(a[1]);
  auto n27 = gate_not(a[3]);
  auto n24 = gate_and(n28, n27);
  auto n30 = gate_not(a[2]);
  auto n29 = gate_not(a[0]);
  auto n23 = gate_and(n30, n29);
  auto n21 = gate_and(n24, n23);
  auto n32 = gate_not(a[5]);
  auto n31 = gate_not(a[7]);
  auto n26 = gate_and(n32, n31);
  auto n34 = gate_not(a[6]);
  auto n33 = gate_not(a[4]);
  auto n25 = gate_and(n34, n33);
  auto n22 = gate_and(n26, n25);
  y[0] = gate_nand(n21, n22);
}
template<> void CplainUint<8>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n11 = gate_xor(a[0], a[1]);
  auto n14 = gate_xor(a[7], a[6]);
  auto n10 = gate_xor(a[2], a[3]);
  auto n13 = gate_xor(n11, n10);
  auto n12 = gate_xor(a[4], a[5]);
  auto n15 = gate_xor(n13, n12);
  y[0] = gate_xnor(n15, n14);
}
template<> void CplainUint<8>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n8 = gate_xor(a[0], a[1]);
  auto n7 = gate_xor(a[2], a[3]);
  auto n12 = gate_xor(n8, n7);
  auto n10 = gate_xor(a[4], a[5]);
  auto n9 = gate_xor(a[7], a[6]);
  auto n11 = gate_xor(n10, n9);
  y[0] = gate_xor(n12, n11);
}
template<> void CplainUint<8>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n66 = gate_not(b[3]);
  auto n65 = gate_not(b[4]);
  auto n58 = gate_and(n66, n65);
  auto n68 = gate_not(b[5]);
  auto n67 = gate_not(b[6]);
  auto n53 = gate_and(n68, n67);
  auto n50 = gate_and(n58, n53);
  auto n69 = gate_not(b[7]);
  auto n54 = gate_and(n50, n69);
  auto n64 = gate_and(b[2], n54);
  auto n88 = gate_not(b[2]);
  auto n52 = gate_and(n54, n88);
  auto n70 = gate_mux(a[7], a[5], b[1]);
  auto n73 = gate_nand(n52, n70);
  auto n71 = gate_mux(a[6], a[4], b[1]);
  auto n72 = gate_nand(n52, n71);
  auto n76 = gate_mux(n73, n72, b[0]);
  auto n74 = gate_mux(a[3], a[2], b[0]);
  auto n106 = gate_mux(a[1], a[0], b[0]);
  auto n103 = gate_mux(n74, n106, b[1]);
  y[3] = gate_and(n52, n103);
  auto n75 = gate_nand(n64, n103);
  y[7] = gate_nand(n76, n75);
  auto n77 = gate_mux(a[6], a[5], b[0]);
  auto n99 = gate_mux(a[4], a[3], b[0]);
  auto n78 = gate_mux(n77, n99, b[1]);
  auto n81 = gate_nand(n52, n78);
  auto n98 = gate_mux(a[2], a[1], b[0]);
  auto n79 = gate_not(b[0]);
  auto n59 = gate_and(a[0], n79);
  auto n104 = gate_mux(n98, n59, b[1]);
  y[2] = gate_and(n52, n104);
  auto n80 = gate_nand(n104, n64);
  y[6] = gate_nand(n81, n80);
  auto n105 = gate_not(b[1]);
  auto n51 = gate_and(n52, n105);
  auto n55 = gate_and(n59, n105);
  y[0] = gate_and(n51, n59);
  y[1] = gate_and(n51, n106);
  auto n82 = gate_not(a[5]);
  auto n83 = gate_nand(n105, n82);
  auto n86 = gate_mux(a[1], n83, n88);
  auto n84 = gate_not(a[3]);
  auto n85 = gate_nand(b[1], n84);
  auto n94 = gate_nand(n86, n85);
  auto n87 = gate_not(a[4]);
  auto n89 = gate_nand(n87, n105);
  auto n92 = gate_mux(a[0], n89, n88);
  auto n90 = gate_not(a[2]);
  auto n91 = gate_nand(b[1], n90);
  auto n93 = gate_nand(n92, n91);
  auto n95 = gate_mux(n94, n93, b[0]);
  auto n96 = gate_not(n95);
  auto n56 = gate_and(n54, n96);
  auto n97 = gate_nand(b[2], b[1]);
  y[5] = gate_and(n56, n97);
  auto n100 = gate_mux(n99, n98, b[1]);
  auto n102 = gate_nand(n52, n100);
  auto n101 = gate_nand(n64, n55);
  y[4] = gate_nand(n102, n101);
}
template<> void CplainUint<8>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n66 = gate_not(b[3]);
  auto n65 = gate_not(b[4]);
  auto n52 = gate_and(n66, n65);
  auto n68 = gate_not(b[5]);
  auto n67 = gate_not(b[6]);
  auto n53 = gate_and(n68, n67);
  auto n50 = gate_and(n52, n53);
  auto n69 = gate_not(b[7]);
  auto n54 = gate_and(n50, n69);
  auto n61 = gate_and(b[2], n54);
  auto n85 = gate_not(b[2]);
  auto n51 = gate_and(n54, n85);
  auto n84 = gate_not(b[1]);
  auto n58 = gate_and(n51, n84);
  auto n70 = gate_not(b[0]);
  auto n64 = gate_and(a[7], n70);
  auto n55 = gate_and(n64, n84);
  y[7] = gate_and(n58, n64);
  auto n71 = gate_mux(a[6], a[7], b[0]);
  y[6] = gate_and(n58, n71);
  auto n73 = gate_mux(a[5], a[6], b[0]);
  auto n98 = gate_mux(n73, n64, b[1]);
  y[5] = gate_and(n51, n98);
  auto n72 = gate_mux(a[4], a[5], b[0]);
  auto n104 = gate_mux(n72, n71, b[1]);
  y[4] = gate_and(n51, n104);
  auto n74 = gate_mux(a[3], a[4], b[0]);
  auto n75 = gate_mux(n74, n73, b[1]);
  auto n77 = gate_nand(n51, n75);
  auto n76 = gate_nand(n61, n55);
  y[3] = gate_nand(n77, n76);
  auto n78 = gate_not(a[2]);
  auto n79 = gate_nand(n84, n78);
  auto n82 = gate_mux(a[6], n79, n85);
  auto n80 = gate_not(a[4]);
  auto n81 = gate_nand(b[1], n80);
  auto n91 = gate_nand(n82, n81);
  auto n83 = gate_not(a[3]);
  auto n86 = gate_nand(n84, n83);
  auto n89 = gate_mux(a[7], n86, n85);
  auto n87 = gate_not(a[5]);
  auto n88 = gate_nand(b[1], n87);
  auto n90 = gate_nand(n89, n88);
  auto n92 = gate_mux(n91, n90, b[0]);
  auto n93 = gate_not(n92);
  auto n59 = gate_and(n54, n93);
  auto n94 = gate_nand(b[1], b[2]);
  y[2] = gate_and(n59, n94);
  auto n95 = gate_mux(a[1], a[3], b[1]);
  auto n102 = gate_nand(n51, n95);
  auto n96 = gate_mux(a[2], a[4], b[1]);
  auto n97 = gate_nand(n51, n96);
  auto n100 = gate_mux(n102, n97, b[0]);
  auto n99 = gate_nand(n98, n61);
  y[1] = gate_nand(n100, n99);
  auto n101 = gate_mux(a[0], a[2], b[1]);
  auto n103 = gate_nand(n51, n101);
  auto n106 = gate_mux(n103, n102, b[0]);
  auto n105 = gate_nand(n104, n61);
  y[0] = gate_nand(n106, n105);
}
template<> void CplainUint<8>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[7] = gate_buf(a[7]);
  auto n40 = gate_not(b[1]);
  auto n67 = gate_not(b[0]);
  auto n41 = gate_nand(n40, n67);
  auto n60 = gate_mux(a[6], y[7], n41);
  auto n43 = gate_not(b[3]);
  auto n42 = gate_not(b[4]);
  auto n33 = gate_and(n43, n42);
  auto n45 = gate_not(b[5]);
  auto n44 = gate_not(b[6]);
  auto n34 = gate_and(n45, n44);
  auto n35 = gate_and(n33, n34);
  auto n46 = gate_not(b[7]);
  auto n55 = gate_nand(n35, n46);
  auto n59 = gate_not(n55);
  auto n36 = gate_and(b[2], n59);
  auto n47 = gate_not(b[2]);
  auto n52 = gate_nand(n59, n47);
  auto n71 = gate_not(n52);
  y[6] = gate_mux(y[7], n60, n71);
  auto n48 = gate_mux(a[5], a[6], b[0]);
  auto n65 = gate_mux(n48, y[7], b[1]);
  y[5] = gate_mux(y[7], n65, n71);
  auto n50 = gate_mux(a[4], a[6], b[1]);
  auto n49 = gate_mux(a[5], y[7], b[1]);
  auto n74 = gate_mux(n50, n49, b[0]);
  y[4] = gate_mux(y[7], n74, n71);
  auto n56 = gate_mux(a[3], a[5], b[1]);
  auto n51 = gate_mux(n56, n50, b[0]);
  auto n54 = gate_nand(n71, n51);
  auto n53 = gate_nand(y[7], n52);
  y[3] = gate_nand(n54, n53);
  auto n73 = gate_nand(y[7], n55);
  auto n62 = gate_mux(a[2], a[4], b[1]);
  auto n57 = gate_mux(n62, n56, b[0]);
  auto n58 = gate_nand(n71, n57);
  auto n39 = gate_and(n73, n58);
  auto n61 = gate_nand(n36, n60);
  y[2] = gate_nand(n39, n61);
  auto n69 = gate_mux(a[1], a[3], b[1]);
  auto n63 = gate_mux(n69, n62, b[0]);
  auto n64 = gate_nand(n71, n63);
  auto n38 = gate_and(n73, n64);
  auto n66 = gate_nand(n36, n65);
  y[1] = gate_nand(n38, n66);
  auto n68 = gate_mux(a[0], a[2], b[1]);
  auto n70 = gate_mux(n69, n68, n67);
  auto n72 = gate_nand(n71, n70);
  auto n37 = gate_and(n73, n72);
  auto n75 = gate_nand(n36, n74);
  y[0] = gate_nand(n37, n75);
}
template<> void CplainUint<8>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n34 = gate_xor(b[7], a[7]);
  auto n4 = gate_not(b[1]);
  auto n6 = gate_xor(a[1], n4);
  auto n3 = gate_not(a[0]);
  auto n5 = gate_nand(b[0], n3);
  y[1] = gate_xor(n6, n5);
  auto n9 = gate_not(b[2]);
  auto n11 = gate_xor(a[2], n9);
  auto n8 = gate_nand(a[1], n4);
  auto n7 = gate_nand(n6, n5);
  auto n10 = gate_nand(n8, n7);
  y[2] = gate_xor(n11, n10);
  auto n14 = gate_not(b[3]);
  auto n16 = gate_xor(a[3], n14);
  auto n13 = gate_nand(a[2], n9);
  auto n12 = gate_nand(n11, n10);
  auto n15 = gate_nand(n13, n12);
  y[3] = gate_xor(n16, n15);
  auto n19 = gate_not(b[4]);
  auto n21 = gate_xor(a[4], n19);
  auto n18 = gate_nand(a[3], n14);
  auto n17 = gate_nand(n16, n15);
  auto n20 = gate_nand(n18, n17);
  y[4] = gate_xor(n21, n20);
  auto n24 = gate_not(b[5]);
  auto n26 = gate_xor(a[5], n24);
  auto n23 = gate_nand(a[4], n19);
  auto n22 = gate_nand(n21, n20);
  auto n25 = gate_nand(n23, n22);
  y[5] = gate_xor(n26, n25);
  auto n29 = gate_not(b[6]);
  auto n31 = gate_xor(a[6], n29);
  auto n28 = gate_nand(a[5], n24);
  auto n27 = gate_nand(n26, n25);
  auto n30 = gate_nand(n28, n27);
  y[6] = gate_xor(n31, n30);
  auto n33 = gate_nand(a[6], n29);
  auto n32 = gate_nand(n31, n30);
  auto n35 = gate_nand(n33, n32);
  y[7] = gate_xnor(n35, n34);
}
template<> void CplainUint<8>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  auto n25 = gate_not(y[0]);
  auto n24 = gate_not(a[1]);
  auto n19 = gate_and(n25, n24);
  auto n31 = gate_not(a[2]);
  auto n20 = gate_and(n19, n31);
  auto n30 = gate_not(a[3]);
  auto n21 = gate_and(n20, n30);
  auto n29 = gate_not(a[4]);
  auto n22 = gate_and(n21, n29);
  auto n28 = gate_not(a[5]);
  auto n23 = gate_and(n22, n28);
  auto n27 = gate_not(a[6]);
  auto n26 = gate_nand(n23, n27);
  y[7] = gate_xor(a[7], n26);
  y[6] = gate_xor(n23, n27);
  y[5] = gate_xor(n22, n28);
  y[4] = gate_xor(n21, n29);
  y[3] = gate_xor(n20, n30);
  y[2] = gate_xor(n19, n31);
  y[1] = gate_xor(y[0], a[1]);
}
// === BEGIN circuit.cpp Name=Cplain

CircuitEvalKey * g_pek_Cplain = nullptr;
CircuitEvalKey * CplainBaseBit::pek = nullptr;
const CplainBit * CplainBaseBit::zero = nullptr;
const CplainBit * CplainBaseBit::unit = nullptr;

void CplainBaseBit::init_pek()
{
    using namespace e3;
    if ( pek ) return;

    initEvalKey
    < CircuitEvalKey, CircuitEvalKey_plain >
    (name(), pek, g_pek_Cplain);

    if ( !zero ) zero = new CplainBit("800");
    if ( !unit ) unit = new CplainBit("801");
}

// === END circuit.cpp Name=Cplain
// === BEGIN circuit.plain.cpp Name=Cplain

CplainBit::CplainBit(const std::string & s) : CplainBit()
{
    try { x = std::stoi(s); }
    catch (...)
    {
        // print, this exception may not be handled
        std::string e = "Bad init in CplainBit [%s]";
        std::printf((e + "\n").c_str(), s.c_str());
        throw e.substr(0, e.find('%')) + s + "]";
    }
}

CplainBit CplainBit::gate_buf(const CplainBit & a)
{
    return a;
}

CplainBit CplainBit::gate_not(const CplainBit & a)
{
    auto ek = k();
    auto y = ek->dec(a.x);

    y = !y;

    return ek->enc(y);
}
CplainBit CplainBit::gate_and(const CplainBit & a, const CplainBit & b)
{
    auto ek = k();
    auto ma = ek->dec(a.x);
    auto mb = ek->dec(b.x);
    ma &= mb;
    return ek->enc(ma);
}

CplainBit CplainBit::gate_or(const CplainBit & a, const CplainBit & b)
{
    auto ek = k();
    auto ma = ek->dec(a.x);
    auto mb = ek->dec(b.x);

    ma |= mb;

    return ek->enc(ma);
}

CplainBit CplainBit::gate_nand(const CplainBit & a, const CplainBit & b)
{
    auto ek = k();
    auto ma = ek->dec(a.x);
    auto mb = ek->dec(b.x);

    ma = !(ma & mb);

    return ek->enc(ma);
}

CplainBit CplainBit::gate_nor(const CplainBit & a, const CplainBit & b)
{
    auto ek = k();
    auto ma = ek->dec(a.x);
    auto mb = ek->dec(b.x);

    ma = !(ma | mb);

    return ek->enc(ma);
}

CplainBit CplainBit::gate_xnor(const CplainBit & a, const CplainBit & b)
{
    auto ek = k();
    auto ma = ek->dec(a.x);
    auto mb = ek->dec(b.x);

    ma = !(ma ^ mb);

    return ek->enc(ma);
}

CplainBit CplainBit::gate_xor(const CplainBit & a, const CplainBit & b)
{
    auto ek = k();
    auto ma = ek->dec(a.x);
    auto mb = ek->dec(b.x);

    ma ^= mb;

    return ek->enc(ma);
}

// a ? b : c
CplainBit CplainBit::gate_mux(const CplainBit & a, const CplainBit & b, const CplainBit & c)
{
    auto ek = k();
    auto ma = ek->dec(a.x);
    auto mb = ek->dec(b.x);
    auto mc = ek->dec(c.x);

    ma = ma ? mb : mc;

    return ek->enc(ma);
}

// === END circuit.plain.cpp Name=Cplain
template<> void CtfheUint<1>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(b[0], a[0]);
}
template<> void CtfheUint<1>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
}
template<> void CtfheUint<1>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void CtfheUint<1>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  auto n3 = gate_not(a[0]);
  y[0] = gate_nand(n4, n3);
}
template<> void CtfheUint<1>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  auto _a0 = gate_buf(a[0]);
  y[0] = gate_buf(_a0);
}
template<> void CtfheUint<1>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(b[0], a[0]);
}
template<> void CtfheUint<1>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
}
template<> void CtfheUint<1>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
}
template<> void CtfheUint<1>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], a[0]);
}
template<> void CtfheUint<1>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void CtfheUint<1>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_not(a[0]);
  y[0] = gate_nand(b[0], n1);
}
template<> void CtfheUint<1>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto _a0 = gate_buf(a[0]);
  y[0] = gate_buf(_a0);
}
template<> void CtfheUint<1>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xnor(b[0], a[0]);
}
template<> void CtfheUint<1>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_not(a[0]);
  y[0] = gate_nand(b[0], n3);
}
template<> void CtfheUint<1>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_not(b[0]);
  y[0] = gate_nand(a[0], n3);
}
template<> void CtfheUint<1>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  y[0] = gate_and(a[0], n4);
}
template<> void CtfheUint<1>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(a[0]);
  y[0] = gate_and(b[0], n4);
}
template<> void CtfheUint<1>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void CtfheUint<1>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(b[0], a[0]);
}
template<> void CtfheUint<1>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
}
template<> void CtfheUint<1>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_not(b[0]);
  y[0] = gate_nand(a[0], n3);
}
template<> void CtfheUint<1>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_not(a[0]);
  y[0] = gate_nand(b[0], n3);
}
template<> void CtfheUint<1>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
}
template<> void CtfheUint<1>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void CtfheUint<1>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  auto n3 = gate_not(a[0]);
  y[0] = gate_nand(n4, n3);
}
template<> void CtfheUint<1>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(a[0]);
  y[0] = gate_and(b[0], n4);
}
template<> void CtfheUint<1>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  y[0] = gate_and(a[0], n4);
}
template<> void CtfheUint<1>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_not(b[0]);
  y[0] = gate_and(a[0], n2);
}
template<> void CtfheUint<1>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_not(b[0]);
  y[0] = gate_and(a[0], n2);
}
template<> void CtfheUint<1>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
}
template<> void CtfheUint<1>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void CtfheUint<1>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void CtfheUint<1>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void CtfheUint<1>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void CtfheUint<1>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void CtfheUint<1>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void CtfheUint<1>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  y[0] = gate_and(a[0], n4);
}
template<> void CtfheUint<1>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  y[0] = gate_and(a[0], n4);
}
template<> void CtfheUint<1>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void CtfheUint<1>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(b[0], a[0]);
}
template<> void CtfheUint<1>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void CtfheUint<2>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n6 = gate_nand(b[0], a[0]);
  auto _add_x_1_n6 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n6);
  auto n5 = gate_xor(b[1], a[1]);
  y[1] = gate_xnor(n6, n5);
}
template<> void CtfheUint<2>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[1] = gate_and(b[1], a[1]);
  y[0] = gate_and(b[0], a[0]);
}
template<> void CtfheUint<2>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[1] = gate_not(a[1]);
  y[0] = gate_not(a[0]);
}
template<> void CtfheUint<2>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n6 = gate_not(b[1]);
  auto n5 = gate_not(a[1]);
  y[1] = gate_nand(n6, n5);
  auto n8 = gate_not(b[0]);
  auto n7 = gate_not(a[0]);
  y[0] = gate_nand(n8, n7);
}
template<> void CtfheUint<2>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  auto N0 = gate_buf(a[0]);
  y[1] = gate_and(a[1], N0);
  auto _add_x_1_n6 = gate_xor(a[1], N0);
  y[0] = gate_buf(_add_x_1_n6);
}
template<> void CtfheUint<2>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[1] = gate_xor(b[1], a[1]);
  y[0] = gate_xor(b[0], a[0]);
}
template<> void CtfheUint<2>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[1] = gate_and(a[0], b[1]);
  y[0] = gate_and(a[0], b[0]);
}
template<> void CtfheUint<2>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
  y[1] = gate_mux(c[1], b[1], a[0]);
}
template<> void CtfheUint<2>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[1] = gate_and(b[0], a[0]);
  auto _add_x_1_n6 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n6);
}
template<> void CtfheUint<2>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  y[1] = gate_xor(a[1], y[0]);
}
template<> void CtfheUint<2>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_not(a[0]);
  auto n5 = gate_nand(b[0], n3);
  auto n6 = gate_not(a[1]);
  auto n7 = gate_nand(b[0], n6);
  auto n4 = gate_nand(b[1], n6);
  y[0] = gate_and(n5, n4);
  auto n8 = gate_not(b[1]);
  y[1] = gate_and(n8, n7);
}
template<> void CtfheUint<2>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(a[0]);
  auto n5 = gate_nand(a[1], n4);
  auto n6 = gate_nand(b[1], n5);
  auto n10 = gate_mux(n6, a[0], b[0]);
  auto n8 = gate_not(b[0]);
  auto n7 = gate_not(b[1]);
  auto n1 = gate_and(n8, n7);
  auto n9 = gate_nand(n1, a[1]);
  y[0] = gate_and(n10, n9);
  auto n11 = gate_xor(a[1], a[0]);
  auto n2 = gate_and(b[0], n11);
  y[1] = gate_mux(a[1], n2, b[1]);
}
template<> void CtfheUint<2>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_not(a[0]);
  auto n11 = gate_xor(n8, b[0]);
  auto n9 = gate_not(a[1]);
  auto n10 = gate_xor(n9, b[1]);
  y[0] = gate_and(n11, n10);
}
template<> void CtfheUint<2>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_not(b[1]);
  auto n13 = gate_nand(n8, a[1]);
  auto n11 = gate_xor(n8, a[1]);
  auto n9 = gate_not(a[0]);
  auto n10 = gate_nand(b[0], n9);
  auto n12 = gate_nand(n11, n10);
  y[0] = gate_nand(n13, n12);
}
template<> void CtfheUint<2>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_not(a[1]);
  auto n13 = gate_nand(n8, b[1]);
  auto n11 = gate_xor(n8, b[1]);
  auto n9 = gate_not(a[0]);
  auto n10 = gate_nand(b[0], n9);
  auto n12 = gate_nand(n11, n10);
  y[0] = gate_nand(n13, n12);
}
template<> void CtfheUint<2>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_not(a[1]);
  auto n15 = gate_nand(n10, b[1]);
  auto n13 = gate_xor(n10, b[1]);
  auto n11 = gate_not(b[0]);
  auto n12 = gate_nand(a[0], n11);
  auto n14 = gate_nand(n13, n12);
  y[0] = gate_and(n15, n14);
}
template<> void CtfheUint<2>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_not(b[1]);
  auto n15 = gate_nand(n10, a[1]);
  auto n13 = gate_xor(n10, a[1]);
  auto n11 = gate_not(b[0]);
  auto n12 = gate_nand(a[0], n11);
  auto n14 = gate_nand(n13, n12);
  y[0] = gate_and(n15, n14);
}
template<> void CtfheUint<2>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[1] = gate_xor(a[0], a[1]);
  y[0] = gate_not(a[0]);
}
template<> void CtfheUint<2>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n5 = gate_not(a[0]);
  auto n8 = gate_xor(n5, b[0]);
  auto n6 = gate_not(a[1]);
  auto n7 = gate_xor(n6, b[1]);
  auto _ne_x_1_n4 = gate_nand(n8, n7);
  y[0] = gate_buf(_ne_x_1_n4);
}
template<> void CtfheUint<2>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n5 = gate_not(a[0]);
  auto n4 = gate_not(a[1]);
  auto n6 = gate_nand(n5, n4);
  y[0] = gate_mux(c[0], b[0], n6);
  y[1] = gate_mux(c[1], b[1], n6);
}
template<> void CtfheUint<2>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n7 = gate_not(a[1]);
  auto n12 = gate_nand(n7, b[1]);
  auto n10 = gate_xor(n7, b[1]);
  auto n8 = gate_not(b[0]);
  auto n9 = gate_nand(a[0], n8);
  auto n11 = gate_nand(n10, n9);
  auto _lte_x_1_n5 = gate_nand(n12, n11);
  y[0] = gate_buf(_lte_x_1_n5);
}
template<> void CtfheUint<2>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n7 = gate_not(b[1]);
  auto n12 = gate_nand(n7, a[1]);
  auto n10 = gate_xor(n7, a[1]);
  auto n8 = gate_not(b[0]);
  auto n9 = gate_nand(a[0], n8);
  auto n11 = gate_nand(n10, n9);
  auto _lte_x_1_n5 = gate_nand(n12, n11);
  y[0] = gate_buf(_lte_x_1_n5);
}
template<> void CtfheUint<2>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_not(b[0]);
  auto n9 = gate_not(b[1]);
  auto n14 = gate_nand(n10, n9);
  auto n12 = gate_not(a[0]);
  auto n11 = gate_not(a[1]);
  auto n13 = gate_nand(n12, n11);
  y[0] = gate_and(n14, n13);
}
template<> void CtfheUint<2>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n7 = gate_not(a[0]);
  auto n6 = gate_not(a[1]);
  y[0] = gate_and(n7, n6);
}
template<> void CtfheUint<2>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n12 = gate_not(a[1]);
  auto n11 = gate_not(b[1]);
  auto n10 = gate_and(n12, n11);
  auto n14 = gate_not(b[0]);
  auto n13 = gate_not(a[0]);
  auto n9 = gate_and(n14, n13);
  y[0] = gate_nand(n10, n9);
}
template<> void CtfheUint<2>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_not(b[1]);
  auto n14 = gate_nand(n9, a[1]);
  auto n12 = gate_xor(n9, a[1]);
  auto n10 = gate_not(a[0]);
  auto n11 = gate_nand(b[0], n10);
  auto n13 = gate_nand(n12, n11);
  y[0] = gate_and(n14, n13);
}
template<> void CtfheUint<2>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_not(a[1]);
  auto n14 = gate_nand(n9, b[1]);
  auto n12 = gate_xor(n9, b[1]);
  auto n10 = gate_not(a[0]);
  auto n11 = gate_nand(b[0], n10);
  auto n13 = gate_nand(n12, n11);
  y[0] = gate_and(n14, n13);
}
template<> void CtfheUint<2>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_not(a[1]);
  auto n4 = gate_nand(b[1], n3);
  auto n5 = gate_nand(n4, b[0]);
  y[0] = gate_and(a[0], n5);
  auto n6 = gate_not(a[0]);
  auto n7 = gate_nand(b[1], n6);
  auto n8 = gate_mux(b[1], n7, b[0]);
  auto n9 = gate_not(n8);
  y[1] = gate_and(a[1], n9);
}
template<> void CtfheUint<2>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  auto n1 = gate_and(n4, a[1]);
  y[0] = gate_and(a[0], n4);
  auto n5 = gate_not(a[0]);
  auto n6 = gate_nand(b[1], n5);
  y[1] = gate_and(n1, n6);
}
template<> void CtfheUint<2>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(a[0], b[0]);
  auto n6 = gate_nand(a[1], b[0]);
  auto n5 = gate_nand(b[1], a[0]);
  y[1] = gate_xor(n6, n5);
}
template<> void CtfheUint<2>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_and(a[0], a[1]);
}
template<> void CtfheUint<2>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_nand(a[0], a[1]);
}
template<> void CtfheUint<2>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n7 = gate_not(a[0]);
  auto n6 = gate_not(a[1]);
  y[0] = gate_and(n7, n6);
}
template<> void CtfheUint<2>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n4 = gate_not(a[0]);
  auto n3 = gate_not(a[1]);
  y[0] = gate_nand(n4, n3);
}
template<> void CtfheUint<2>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_xnor(a[0], a[1]);
}
template<> void CtfheUint<2>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_xor(a[0], a[1]);
}
template<> void CtfheUint<2>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_not(b[0]);
  auto n12 = gate_mux(a[1], a[0], b[0]);
  auto n10 = gate_and(a[0], n11);
  auto n13 = gate_not(b[1]);
  y[1] = gate_and(n13, n12);
  y[0] = gate_and(n10, n13);
}
template<> void CtfheUint<2>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_not(b[0]);
  auto n12 = gate_mux(a[0], a[1], b[0]);
  auto n10 = gate_and(a[1], n11);
  auto n13 = gate_not(b[1]);
  y[1] = gate_and(n10, n13);
  y[0] = gate_and(n13, n12);
}
template<> void CtfheUint<2>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[1] = gate_buf(a[1]);
  auto n5 = gate_not(b[0]);
  auto n4 = gate_not(b[1]);
  auto n6 = gate_nand(n5, n4);
  y[0] = gate_mux(a[0], a[1], n6);
}
template<> void CtfheUint<2>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n8 = gate_not(b[1]);
  auto n5 = gate_not(a[0]);
  auto n6 = gate_nand(b[0], n5);
  auto n7 = gate_xor(n6, a[1]);
  y[1] = gate_xor(n8, n7);
}
template<> void CtfheUint<2>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  y[1] = gate_xor(a[0], a[1]);
}
template<> void CtfheUint<3>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_and(b[0], a[0]);
  auto _add_x_1_n9 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n9);
  auto n9 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n8, n9);
  auto n11 = gate_nand(n8, n9);
  auto n10 = gate_nand(b[1], a[1]);
  auto n12 = gate_nand(n11, n10);
  auto n13 = gate_xor(b[2], n12);
  y[2] = gate_xor(a[2], n13);
}
template<> void CtfheUint<3>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_and(b[2], a[2]);
  y[0] = gate_and(b[0], a[0]);
  y[1] = gate_and(b[1], a[1]);
}
template<> void CtfheUint<3>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[2] = gate_not(a[2]);
  y[1] = gate_not(a[1]);
  y[0] = gate_not(a[0]);
}
template<> void CtfheUint<3>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_not(b[2]);
  auto n7 = gate_not(a[2]);
  y[2] = gate_nand(n8, n7);
  auto n10 = gate_not(b[1]);
  auto n9 = gate_not(a[1]);
  y[1] = gate_nand(n10, n9);
  auto n12 = gate_not(b[0]);
  auto n11 = gate_not(a[0]);
  y[0] = gate_nand(n12, n11);
}
template<> void CtfheUint<3>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  auto N0 = gate_buf(a[0]);
  y[2] = gate_buf(zero);
  auto n6 = gate_nand(a[1], N0);
  auto n7 = gate_xor(a[1], N0);
  auto n5 = gate_nand(n7, a[2]);
  y[1] = gate_nand(n6, n5);
  auto _add_x_2_n9 = gate_xor(n7, a[2]);
  y[0] = gate_buf(_add_x_2_n9);
}
template<> void CtfheUint<3>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_xor(b[2], a[2]);
  y[1] = gate_xor(b[1], a[1]);
  y[0] = gate_xor(b[0], a[0]);
}
template<> void CtfheUint<3>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_and(a[0], b[2]);
  y[1] = gate_and(a[0], b[1]);
  y[0] = gate_and(a[0], b[0]);
}
template<> void CtfheUint<3>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
  y[1] = gate_mux(c[1], b[1], a[0]);
  y[2] = gate_mux(c[2], b[2], a[0]);
}
template<> void CtfheUint<3>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n6 = gate_and(b[0], a[0]);
  auto n7 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n7, n6);
  auto _add_x_1_n9 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n9);
  auto n9 = gate_nand(b[1], a[1]);
  auto n8 = gate_nand(n7, n6);
  auto _add_x_1_n11 = gate_nand(n9, n8);
  y[2] = gate_buf(_add_x_1_n11);
}
template<> void CtfheUint<3>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  auto n5 = gate_not(a[1]);
  y[1] = gate_xor(a[0], n5);
  auto n7 = gate_not(a[2]);
  auto n6 = gate_nand(y[0], n5);
  y[2] = gate_xor(n7, n6);
}
template<> void CtfheUint<3>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(b[2]);
  auto n1 = gate_and(b[1], n22);
  auto n7 = gate_not(a[1]);
  auto n8 = gate_nand(b[0], n7);
  auto n23 = gate_nand(n22, n8);
  auto n6 = gate_and(a[2], n23);
  auto n10 = gate_not(n23);
  auto n19 = gate_not(a[2]);
  auto n9 = gate_nand(b[1], n19);
  y[1] = gate_and(n10, n9);
  auto n13 = gate_not(b[1]);
  auto n2 = gate_and(n22, n13);
  auto n11 = gate_nand(b[0], n19);
  y[2] = gate_and(n2, n11);
  auto n12 = gate_nand(y[1], b[0]);
  auto n5 = gate_and(a[1], n12);
  auto n18 = gate_nand(n13, n5);
  auto n16 = gate_xor(n13, n5);
  auto n14 = gate_not(a[0]);
  auto n15 = gate_nand(b[0], n14);
  auto n17 = gate_nand(n16, n15);
  auto n21 = gate_nand(n18, n17);
  auto n20 = gate_nand(b[2], n19);
  auto n25 = gate_nand(n21, n20);
  auto n24 = gate_nand(n1, n6);
  y[0] = gate_nand(n25, n24);
}
template<> void CtfheUint<3>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n40 = gate_xor(a[2], b[2]);
  auto n9 = gate_not(a[1]);
  auto n18 = gate_not(a[0]);
  auto n4 = gate_and(n9, n18);
  auto n6 = gate_nand(a[2], n4);
  auto n35 = gate_not(n6);
  auto n27 = gate_not(b[2]);
  auto n7 = gate_xor(b[1], n27);
  auto n34 = gate_nand(n7, b[0]);
  auto n3 = gate_and(n35, n34);
  auto n17 = gate_not(n7);
  auto n14 = gate_nand(n17, n6);
  auto n12 = gate_nand(n7, n3);
  auto n8 = gate_nand(a[0], a[2]);
  auto n15 = gate_xor(n9, n8);
  auto n10 = gate_mux(n27, n15, b[0]);
  auto n11 = gate_not(n10);
  auto n13 = gate_nand(n12, n11);
  auto n25 = gate_nand(n14, n13);
  auto n24 = gate_nand(n3, n25);
  auto n16 = gate_nand(n15, n25);
  auto n22 = gate_nand(n17, n16);
  auto n20 = gate_xor(n17, n16);
  auto n19 = gate_mux(b[2], n18, b[0]);
  auto n21 = gate_nand(n20, n19);
  auto n23 = gate_nand(n22, n21);
  auto n5 = gate_and(n24, n23);
  auto n30 = gate_nand(n40, n5);
  auto n31 = gate_xor(n25, n40);
  y[1] = gate_xor(n30, n31);
  auto n26 = gate_not(b[0]);
  auto n2 = gate_and(n27, n26);
  auto n28 = gate_not(b[1]);
  auto n1 = gate_and(n2, n28);
  auto n29 = gate_nand(n1, n40);
  y[0] = gate_xor(n5, n29);
  auto n33 = gate_not(n30);
  auto n32 = gate_not(n31);
  auto n38 = gate_nand(n33, n32);
  auto n36 = gate_not(n34);
  auto n37 = gate_nand(n36, n35);
  auto n39 = gate_xor(n38, n37);
  y[2] = gate_xor(n40, n39);
}
template<> void CtfheUint<3>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_xnor(b[2], a[2]);
  auto n14 = gate_xnor(a[0], b[0]);
  auto n13 = gate_and(n11, n14);
  auto n15 = gate_xnor(a[1], b[1]);
  y[0] = gate_and(n13, n15);
}
template<> void CtfheUint<3>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n13 = gate_not(b[2]);
  auto n23 = gate_nand(n13, a[2]);
  auto n21 = gate_xor(n13, a[2]);
  auto n14 = gate_not(b[1]);
  auto n19 = gate_nand(n14, a[1]);
  auto n17 = gate_xor(n14, a[1]);
  auto n15 = gate_not(a[0]);
  auto n16 = gate_nand(b[0], n15);
  auto n18 = gate_nand(n17, n16);
  auto n20 = gate_nand(n19, n18);
  auto n22 = gate_nand(n21, n20);
  y[0] = gate_nand(n23, n22);
}
template<> void CtfheUint<3>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n12 = gate_not(b[1]);
  auto n17 = gate_nand(n12, a[1]);
  auto n15 = gate_xor(n12, a[1]);
  auto n13 = gate_not(a[0]);
  auto n14 = gate_nand(b[0], n13);
  auto n16 = gate_nand(n15, n14);
  auto n18 = gate_nand(n17, n16);
  auto n22 = gate_nand(n18, b[2]);
  auto n20 = gate_xor(n18, b[2]);
  auto n19 = gate_not(a[2]);
  auto n21 = gate_nand(n20, n19);
  auto _gte_x_1_n22 = gate_nand(n22, n21);
  y[0] = gate_buf(_gte_x_1_n22);
}
template<> void CtfheUint<3>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_not(a[1]);
  auto n20 = gate_nand(n15, b[1]);
  auto n18 = gate_xor(n15, b[1]);
  auto n16 = gate_not(b[0]);
  auto n17 = gate_nand(a[0], n16);
  auto n19 = gate_nand(n18, n17);
  auto n21 = gate_nand(n20, n19);
  auto n25 = gate_nand(n21, b[2]);
  auto n23 = gate_xor(n21, b[2]);
  auto n22 = gate_not(a[2]);
  auto n24 = gate_nand(n23, n22);
  y[0] = gate_and(n25, n24);
}
template<> void CtfheUint<3>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_not(b[2]);
  auto n26 = gate_nand(n16, a[2]);
  auto n24 = gate_xor(n16, a[2]);
  auto n17 = gate_not(a[1]);
  auto n22 = gate_nand(n17, b[1]);
  auto n20 = gate_xor(n17, b[1]);
  auto n18 = gate_not(b[0]);
  auto n19 = gate_nand(a[0], n18);
  auto n21 = gate_nand(n20, n19);
  auto n23 = gate_nand(n22, n21);
  auto n25 = gate_nand(n24, n23);
  y[0] = gate_and(n26, n25);
}
template<> void CtfheUint<3>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[1] = gate_xor(a[0], a[1]);
  auto n5 = gate_not(a[2]);
  auto n4 = gate_nand(a[0], a[1]);
  y[2] = gate_xor(n5, n4);
  y[0] = gate_not(a[0]);
}
template<> void CtfheUint<3>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_xnor(b[2], a[2]);
  auto n11 = gate_xnor(a[0], b[0]);
  auto n10 = gate_and(n9, n11);
  auto n12 = gate_xnor(a[1], b[1]);
  auto _ne_x_1_n7 = gate_nand(n10, n12);
  y[0] = gate_buf(_ne_x_1_n7);
}
template<> void CtfheUint<3>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n9 = gate_not(a[0]);
  auto n8 = gate_not(a[1]);
  auto n7 = gate_and(n9, n8);
  auto n10 = gate_not(a[2]);
  auto n11 = gate_nand(n7, n10);
  y[2] = gate_mux(c[2], b[2], n11);
  y[0] = gate_mux(c[0], b[0], n11);
  y[1] = gate_mux(c[1], b[1], n11);
}
template<> void CtfheUint<3>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_not(a[1]);
  auto n21 = gate_nand(n16, b[1]);
  auto n19 = gate_xor(n16, b[1]);
  auto n17 = gate_not(b[0]);
  auto n18 = gate_nand(a[0], n17);
  auto n20 = gate_nand(n19, n18);
  auto n22 = gate_nand(n21, n20);
  auto n26 = gate_nand(n22, b[2]);
  auto n24 = gate_xor(n22, b[2]);
  auto n23 = gate_not(a[2]);
  auto n25 = gate_nand(n24, n23);
  auto _lte_x_1_n8 = gate_nand(n26, n25);
  y[0] = gate_buf(_lte_x_1_n8);
}
template<> void CtfheUint<3>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(a[1]);
  auto n22 = gate_nand(n17, b[1]);
  auto n20 = gate_xor(n17, b[1]);
  auto n18 = gate_not(b[0]);
  auto n19 = gate_nand(a[0], n18);
  auto n21 = gate_nand(n20, n19);
  auto n23 = gate_nand(n22, n21);
  auto n27 = gate_nand(n23, a[2]);
  auto n25 = gate_xor(n23, a[2]);
  auto n24 = gate_not(b[2]);
  auto n26 = gate_nand(n25, n24);
  y[0] = gate_nand(n27, n26);
}
template<> void CtfheUint<3>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n18 = gate_not(a[0]);
  auto n17 = gate_not(a[1]);
  auto n15 = gate_and(n18, n17);
  auto n19 = gate_not(a[2]);
  auto n24 = gate_nand(n15, n19);
  auto n21 = gate_not(b[1]);
  auto n20 = gate_not(b[2]);
  auto n14 = gate_and(n21, n20);
  auto n22 = gate_not(b[0]);
  auto n23 = gate_nand(n14, n22);
  y[0] = gate_and(n24, n23);
}
template<> void CtfheUint<3>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n11 = gate_not(a[0]);
  auto n12 = gate_not(a[2]);
  auto n10 = gate_not(a[1]);
  auto n8 = gate_and(n11, n10);
  y[0] = gate_and(n8, n12);
}
template<> void CtfheUint<3>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_not(b[0]);
  auto n19 = gate_not(a[1]);
  auto n17 = gate_and(n20, n19);
  auto n22 = gate_not(a[2]);
  auto n21 = gate_not(b[2]);
  auto n18 = gate_and(n22, n21);
  auto n15 = gate_and(n17, n18);
  auto n23 = gate_not(b[1]);
  auto n16 = gate_and(n15, n23);
  auto n24 = gate_not(a[0]);
  y[0] = gate_nand(n16, n24);
}
template<> void CtfheUint<3>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_not(b[1]);
  auto n19 = gate_nand(n14, a[1]);
  auto n17 = gate_xor(n14, a[1]);
  auto n15 = gate_not(a[0]);
  auto n16 = gate_nand(b[0], n15);
  auto n18 = gate_nand(n17, n16);
  auto n20 = gate_nand(n19, n18);
  auto n24 = gate_nand(n20, a[2]);
  auto n22 = gate_xor(n20, a[2]);
  auto n21 = gate_not(b[2]);
  auto n23 = gate_nand(n22, n21);
  y[0] = gate_and(n24, n23);
}
template<> void CtfheUint<3>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_not(b[1]);
  auto n20 = gate_nand(n15, a[1]);
  auto n18 = gate_xor(n15, a[1]);
  auto n16 = gate_not(a[0]);
  auto n17 = gate_nand(b[0], n16);
  auto n19 = gate_nand(n18, n17);
  auto n21 = gate_nand(n20, n19);
  auto n25 = gate_nand(n21, b[2]);
  auto n23 = gate_xor(n21, b[2]);
  auto n22 = gate_not(a[2]);
  auto n24 = gate_nand(n23, n22);
  y[0] = gate_and(n25, n24);
}
template<> void CtfheUint<3>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n19 = gate_not(a[0]);
  auto n9 = gate_not(b[2]);
  auto n12 = gate_not(b[1]);
  auto n1 = gate_and(n9, n12);
  auto n5 = gate_nand(b[0], n1);
  auto n4 = gate_and(a[2], n5);
  auto n6 = gate_mux(b[0], a[2], b[1]);
  auto n3 = gate_and(n9, n6);
  auto n7 = gate_not(a[1]);
  auto n8 = gate_nand(b[0], n7);
  auto n11 = gate_nand(n3, n8);
  auto n2 = gate_and(n4, n11);
  auto n28 = gate_nand(n2, n9);
  auto n10 = gate_not(a[2]);
  auto n16 = gate_nand(b[2], n10);
  auto n24 = gate_nand(a[1], n11);
  auto n13 = gate_not(n24);
  auto n15 = gate_nand(n13, n12);
  auto n20 = gate_xor(b[1], n24);
  auto n21 = gate_nand(b[0], n19);
  auto n14 = gate_nand(n20, n21);
  auto n29 = gate_nand(n15, n14);
  auto n17 = gate_nand(n16, n29);
  auto n26 = gate_nand(n28, n17);
  auto n18 = gate_nand(n26, b[0]);
  y[0] = gate_xor(n19, n18);
  auto n22 = gate_not(n20);
  auto n23 = gate_nand(n22, n21);
  auto n25 = gate_mux(n24, n23, n26);
  y[1] = gate_not(n25);
  auto n27 = gate_not(n26);
  auto n32 = gate_nand(n2, n27);
  auto n30 = gate_not(n28);
  auto n31 = gate_nand(n30, n29);
  y[2] = gate_nand(n32, n31);
}
template<> void CtfheUint<3>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n5 = gate_xnor(b[2], b[1]);
  auto n6 = gate_nand(a[0], a[2]);
  auto n4 = gate_xnor(a[1], n6);
  auto n7 = gate_nand(n5, b[0]);
  auto n22 = gate_nand(n4, n7);
  auto n8 = gate_not(b[2]);
  auto n11 = gate_mux(n8, a[0], b[0]);
  auto n10 = gate_xor(n22, n5);
  auto n21 = gate_nand(n11, n10);
  auto n9 = gate_not(n22);
  auto n14 = gate_nand(n9, n5);
  auto n12 = gate_not(n10);
  auto n13 = gate_nand(n12, n11);
  auto n31 = gate_nand(n14, n13);
  auto n20 = gate_not(n31);
  auto n15 = gate_not(a[0]);
  auto n3 = gate_and(a[2], n15);
  auto n16 = gate_not(a[1]);
  auto n2 = gate_and(n3, n16);
  auto n17 = gate_not(b[0]);
  auto n18 = gate_mux(n17, b[0], n5);
  auto n19 = gate_not(n18);
  auto n30 = gate_nand(n2, n19);
  auto n23 = gate_nand(n20, n30);
  auto n28 = gate_mux(n22, n21, n23);
  auto n25 = gate_xor(a[2], a[0]);
  auto n24 = gate_nand(b[0], n23);
  auto n27 = gate_xor(n25, n24);
  auto n26 = gate_nand(n27, a[2]);
  y[1] = gate_xor(n28, n26);
  auto n29 = gate_not(n27);
  auto n1 = gate_and(a[2], n29);
  y[0] = gate_xor(a[2], n29);
  auto n35 = gate_nand(n28, n1);
  auto n32 = gate_not(n30);
  auto n33 = gate_nand(n32, n31);
  auto n34 = gate_nand(a[2], n33);
  y[2] = gate_xor(n35, n34);
}
template<> void CtfheUint<3>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_and(a[1], b[1]);
  auto n2 = gate_and(b[2], a[0]);
  auto n6 = gate_nand(b[0], a[0]);
  y[0] = gate_not(n6);
  auto n4 = gate_nand(b[1], a[0]);
  auto n3 = gate_nand(a[1], b[0]);
  y[1] = gate_xor(n4, n3);
  auto n5 = gate_nand(a[2], b[0]);
  auto n8 = gate_xor(n2, n5);
  auto n7 = gate_nand(n6, n1);
  y[2] = gate_xor(n8, n7);
}
template<> void CtfheUint<3>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n5 = gate_and(a[0], a[1]);
  y[0] = gate_and(a[2], n5);
}
template<> void CtfheUint<3>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n4 = gate_and(a[0], a[1]);
  y[0] = gate_nand(a[2], n4);
}
template<> void CtfheUint<3>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n11 = gate_not(a[0]);
  auto n12 = gate_not(a[2]);
  auto n10 = gate_not(a[1]);
  auto n8 = gate_and(n11, n10);
  y[0] = gate_and(n8, n12);
}
template<> void CtfheUint<3>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n8 = gate_not(a[0]);
  auto n7 = gate_not(a[1]);
  auto n6 = gate_and(n8, n7);
  auto n9 = gate_not(a[2]);
  y[0] = gate_nand(n6, n9);
}
template<> void CtfheUint<3>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n5 = gate_xor(a[1], a[2]);
  y[0] = gate_xnor(a[0], n5);
}
template<> void CtfheUint<3>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n2 = gate_xor(a[2], a[0]);
  y[0] = gate_xor(a[1], n2);
}
template<> void CtfheUint<3>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_not(b[0]);
  auto n25 = gate_and(a[0], n27);
  auto n32 = gate_not(b[2]);
  auto n28 = gate_not(b[1]);
  auto n23 = gate_and(n32, n28);
  y[0] = gate_and(n25, n23);
  auto n29 = gate_mux(a[1], a[0], b[0]);
  y[1] = gate_and(n23, n29);
  auto n30 = gate_mux(a[2], a[1], b[0]);
  auto n31 = gate_mux(n30, n25, b[1]);
  y[2] = gate_and(n32, n31);
}
template<> void CtfheUint<3>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n24 = gate_not(b[2]);
  auto n25 = gate_mux(a[1], a[2], b[0]);
  auto n21 = gate_mux(a[0], a[1], b[0]);
  auto n20 = gate_not(b[0]);
  auto n19 = gate_and(a[2], n20);
  auto n22 = gate_mux(n21, n19, b[1]);
  y[0] = gate_and(n24, n22);
  auto n23 = gate_not(b[1]);
  auto n15 = gate_and(n24, n23);
  y[2] = gate_and(n19, n15);
  y[1] = gate_and(n15, n25);
}
template<> void CtfheUint<3>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_buf(a[2]);
  auto n10 = gate_mux(a[0], a[1], b[0]);
  auto n9 = gate_not(b[1]);
  auto n8 = gate_not(b[2]);
  auto n11 = gate_nand(n9, n8);
  y[0] = gate_mux(n10, a[2], n11);
  auto n13 = gate_not(n11);
  auto n12 = gate_not(b[0]);
  auto n14 = gate_nand(n13, n12);
  y[1] = gate_mux(a[1], a[2], n14);
}
template<> void CtfheUint<3>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n17 = gate_xor(b[2], a[2]);
  auto n12 = gate_not(b[1]);
  auto n14 = gate_xor(a[1], n12);
  auto n11 = gate_not(a[0]);
  auto n13 = gate_nand(b[0], n11);
  y[1] = gate_xor(n14, n13);
  auto n16 = gate_nand(a[1], n12);
  auto n15 = gate_nand(n14, n13);
  auto n18 = gate_nand(n16, n15);
  y[2] = gate_xnor(n18, n17);
}
template<> void CtfheUint<3>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  y[1] = gate_xor(a[1], a[0]);
  auto n5 = gate_not(a[1]);
  auto n4 = gate_not(a[0]);
  auto n6 = gate_nand(n5, n4);
  y[2] = gate_xor(a[2], n6);
}
template<> void CtfheUint<4>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n12 = gate_and(b[0], a[0]);
  auto _add_x_1_n12 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n12);
  auto n13 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n12, n13);
  auto n17 = gate_xor(b[2], a[2]);
  auto n15 = gate_nand(b[1], a[1]);
  auto n14 = gate_nand(n12, n13);
  auto n16 = gate_nand(n15, n14);
  y[2] = gate_xor(n17, n16);
  auto n19 = gate_nand(n17, n16);
  auto n18 = gate_nand(b[2], a[2]);
  auto n20 = gate_nand(n19, n18);
  auto n21 = gate_xor(b[3], n20);
  y[3] = gate_xor(a[3], n21);
}
template<> void CtfheUint<4>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_and(b[3], a[3]);
  y[0] = gate_and(b[0], a[0]);
  y[1] = gate_and(b[1], a[1]);
  y[2] = gate_and(b[2], a[2]);
}
template<> void CtfheUint<4>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[3] = gate_not(a[3]);
  y[2] = gate_not(a[2]);
  y[1] = gate_not(a[1]);
  y[0] = gate_not(a[0]);
}
template<> void CtfheUint<4>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_not(b[3]);
  auto n9 = gate_not(a[3]);
  y[3] = gate_nand(n10, n9);
  auto n12 = gate_not(b[2]);
  auto n11 = gate_not(a[2]);
  y[2] = gate_nand(n12, n11);
  auto n14 = gate_not(b[1]);
  auto n13 = gate_not(a[1]);
  y[1] = gate_nand(n14, n13);
  auto n16 = gate_not(b[0]);
  auto n15 = gate_not(a[0]);
  y[0] = gate_nand(n16, n15);
}
template<> void CtfheUint<4>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  y[3] = gate_buf(zero);
  auto N0 = gate_buf(a[0]);
  auto n15 = gate_nand(a[1], a[2]);
  auto n13 = gate_not(n15);
  auto n17 = gate_nand(N0, a[3]);
  auto n12 = gate_not(n17);
  y[2] = gate_and(n13, n12);
  auto n19 = gate_xor(a[1], a[2]);
  auto n18 = gate_xor(N0, a[3]);
  auto n14 = gate_nand(n19, n18);
  auto n16 = gate_nand(n17, n14);
  y[1] = gate_mux(n17, n16, n15);
  y[0] = gate_xor(n19, n18);
}
template<> void CtfheUint<4>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_xor(b[3], a[3]);
  y[2] = gate_xor(b[2], a[2]);
  y[1] = gate_xor(b[1], a[1]);
  y[0] = gate_xor(b[0], a[0]);
}
template<> void CtfheUint<4>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_and(a[0], b[3]);
  y[2] = gate_and(a[0], b[2]);
  y[1] = gate_and(a[0], b[1]);
  y[0] = gate_and(a[0], b[0]);
}
template<> void CtfheUint<4>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
  y[1] = gate_mux(c[1], b[1], a[0]);
  y[2] = gate_mux(c[2], b[2], a[0]);
  y[3] = gate_mux(c[3], b[3], a[0]);
}
template<> void CtfheUint<4>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_and(b[0], a[0]);
  auto n11 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n11, n10);
  auto n15 = gate_xor(b[2], a[2]);
  auto n13 = gate_nand(b[1], a[1]);
  auto n12 = gate_nand(n11, n10);
  auto n14 = gate_nand(n13, n12);
  y[2] = gate_xor(n15, n14);
  auto _add_x_1_n12 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n12);
  auto n17 = gate_nand(b[2], a[2]);
  auto n16 = gate_nand(n15, n14);
  auto _add_x_1_n14 = gate_nand(n17, n16);
  y[3] = gate_buf(_add_x_1_n14);
}
template<> void CtfheUint<4>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n9 = gate_not(a[1]);
  y[1] = gate_xor(a[0], n9);
  y[0] = gate_not(a[0]);
  auto n7 = gate_and(y[0], n9);
  y[2] = gate_xor(a[2], n7);
  auto n10 = gate_not(a[2]);
  auto n8 = gate_and(n7, n10);
  y[3] = gate_xor(n8, a[3]);
}
template<> void CtfheUint<4>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n31 = gate_not(b[1]);
  auto n47 = gate_not(b[3]);
  auto n40 = gate_not(b[2]);
  auto n2 = gate_and(n47, n40);
  auto n1 = gate_and(n31, n2);
  auto n22 = gate_not(a[3]);
  auto n7 = gate_nand(b[0], n22);
  auto n17 = gate_nand(n1, n7);
  auto n5 = gate_and(a[3], n17);
  y[3] = gate_not(n17);
  auto n8 = gate_not(a[2]);
  auto n9 = gate_nand(b[0], n8);
  auto n3 = gate_and(n9, n2);
  auto n10 = gate_nand(b[1], n22);
  auto n18 = gate_nand(n3, n10);
  auto n4 = gate_and(n5, n18);
  y[2] = gate_not(n18);
  auto n16 = gate_nand(n22, b[2]);
  auto n11 = gate_nand(y[2], b[0]);
  auto n27 = gate_nand(a[2], n11);
  auto n12 = gate_not(n27);
  auto n14 = gate_nand(n12, n31);
  auto n23 = gate_xor(b[1], n27);
  auto n30 = gate_not(a[1]);
  auto n24 = gate_nand(b[0], n30);
  auto n13 = gate_nand(n23, n24);
  auto n15 = gate_nand(n14, n13);
  auto n20 = gate_nand(n16, n15);
  auto n19 = gate_nand(n40, n4);
  auto n21 = gate_nand(n20, n19);
  auto n46 = gate_nand(n47, n21);
  auto n6 = gate_and(n4, n46);
  y[1] = gate_not(n46);
  auto n45 = gate_nand(n22, b[3]);
  auto n25 = gate_not(n23);
  auto n26 = gate_nand(n25, n24);
  auto n28 = gate_mux(n27, n26, y[1]);
  auto n39 = gate_not(n28);
  auto n29 = gate_nand(y[1], b[0]);
  auto n32 = gate_xor(n30, n29);
  auto n37 = gate_nand(n32, n31);
  auto n35 = gate_xor(n32, n31);
  auto n33 = gate_not(a[0]);
  auto n34 = gate_nand(b[0], n33);
  auto n36 = gate_nand(n35, n34);
  auto n38 = gate_nand(n37, n36);
  auto n43 = gate_nand(n39, n38);
  auto n41 = gate_xor(n39, n38);
  auto n42 = gate_nand(n41, n40);
  auto n44 = gate_nand(n43, n42);
  auto n49 = gate_nand(n45, n44);
  auto n48 = gate_nand(n47, n6);
  y[0] = gate_nand(n49, n48);
}
template<> void CtfheUint<4>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n61 = gate_not(b[3]);
  auto n56 = gate_xor(a[3], n61);
  auto n46 = gate_xor(b[2], b[3]);
  auto n43 = gate_not(n46);
  auto n20 = gate_not(a[1]);
  auto n8 = gate_not(a[0]);
  auto n11 = gate_nand(n20, n8);
  auto n9 = gate_not(n11);
  auto n13 = gate_not(a[2]);
  auto n6 = gate_and(a[3], n13);
  auto n21 = gate_nand(n9, n6);
  auto n10 = gate_not(n21);
  auto n38 = gate_xor(b[1], b[3]);
  auto n36 = gate_not(n38);
  auto n1 = gate_and(n43, n36);
  auto n4 = gate_and(n1, b[0]);
  auto n67 = gate_nand(n10, n4);
  auto n3 = gate_and(n10, n67);
  auto n17 = gate_nand(n3, n36);
  auto n12 = gate_nand(a[3], n11);
  auto n22 = gate_xor(n13, n12);
  auto n60 = gate_not(b[0]);
  auto n2 = gate_and(n61, n60);
  auto n15 = gate_mux(n22, n61, n60);
  auto n14 = gate_nand(n38, n21);
  auto n16 = gate_nand(n15, n14);
  auto n18 = gate_nand(n17, n16);
  auto n29 = gate_nand(n43, n18);
  auto n5 = gate_and(n22, n29);
  auto n66 = gate_xor(n56, n29);
  auto n68 = gate_not(n56);
  auto n19 = gate_nand(a[3], a[0]);
  auto n34 = gate_xor(n20, n19);
  auto n28 = gate_nand(n21, n46);
  auto n23 = gate_mux(n34, n61, n60);
  auto n26 = gate_nand(n23, n5);
  auto n24 = gate_xor(n23, n5);
  auto n25 = gate_nand(n24, n36);
  auto n27 = gate_nand(n26, n25);
  auto n32 = gate_nand(n28, n27);
  auto n48 = gate_nand(n3, n29);
  auto n30 = gate_not(n48);
  auto n31 = gate_nand(n43, n30);
  auto n50 = gate_nand(n32, n31);
  auto n33 = gate_nand(b[0], n50);
  auto n37 = gate_nand(n34, n33);
  auto n35 = gate_not(n37);
  auto n42 = gate_nand(n36, n35);
  auto n40 = gate_xor(n38, n37);
  auto n39 = gate_mux(a[0], n61, n60);
  auto n41 = gate_nand(n40, n39);
  auto n44 = gate_nand(n42, n41);
  auto n53 = gate_nand(n44, n43);
  auto n45 = gate_not(n44);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n47, n5);
  auto n51 = gate_nand(n49, n48);
  auto n55 = gate_not(n50);
  auto n52 = gate_nand(n51, n55);
  auto n59 = gate_nand(n53, n52);
  auto n54 = gate_not(n59);
  auto n65 = gate_nand(n68, n54);
  auto n58 = gate_not(n65);
  auto n57 = gate_xor(n56, n55);
  auto n7 = gate_and(n58, n57);
  y[2] = gate_xor(n66, n7);
  y[1] = gate_xor(n58, n57);
  auto n64 = gate_xor(n59, n68);
  auto n62 = gate_nand(n2, n1);
  auto n63 = gate_nand(n68, n62);
  y[0] = gate_mux(n65, n64, n63);
  auto n70 = gate_nand(n66, n7);
  auto n69 = gate_xor(n68, n67);
  y[3] = gate_xor(n70, n69);
}
template<> void CtfheUint<4>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_xnor(a[1], b[1]);
  auto n18 = gate_not(b[2]);
  auto n23 = gate_xor(n18, a[2]);
  auto n19 = gate_not(a[3]);
  auto n22 = gate_xor(n19, b[3]);
  auto n20 = gate_not(a[0]);
  auto n21 = gate_xor(n20, b[0]);
  auto n15 = gate_and(n22, n21);
  auto n14 = gate_and(n15, n16);
  y[0] = gate_and(n23, n14);
}
template<> void CtfheUint<4>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(b[3]);
  auto n32 = gate_nand(n17, a[3]);
  auto n30 = gate_xor(n17, a[3]);
  auto n18 = gate_not(b[1]);
  auto n23 = gate_nand(n18, a[1]);
  auto n21 = gate_xor(n18, a[1]);
  auto n19 = gate_not(a[0]);
  auto n20 = gate_nand(b[0], n19);
  auto n22 = gate_nand(n21, n20);
  auto n24 = gate_nand(n23, n22);
  auto n28 = gate_nand(n24, a[2]);
  auto n26 = gate_xor(n24, a[2]);
  auto n25 = gate_not(b[2]);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n31 = gate_nand(n30, n29);
  auto _gte_x_1_n29 = gate_nand(n32, n31);
  y[0] = gate_buf(_gte_x_1_n29);
}
template<> void CtfheUint<4>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(a[3]);
  auto n32 = gate_nand(n17, b[3]);
  auto n30 = gate_xor(n17, b[3]);
  auto n18 = gate_not(b[1]);
  auto n23 = gate_nand(n18, a[1]);
  auto n21 = gate_xor(n18, a[1]);
  auto n19 = gate_not(a[0]);
  auto n20 = gate_nand(b[0], n19);
  auto n22 = gate_nand(n21, n20);
  auto n24 = gate_nand(n23, n22);
  auto n28 = gate_nand(n24, a[2]);
  auto n26 = gate_xor(n24, a[2]);
  auto n25 = gate_not(b[2]);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n31 = gate_nand(n30, n29);
  auto _gte_x_1_n29 = gate_nand(n32, n31);
  y[0] = gate_buf(_gte_x_1_n29);
}
template<> void CtfheUint<4>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n23 = gate_not(a[1]);
  auto n28 = gate_nand(n23, b[1]);
  auto n26 = gate_xor(n23, b[1]);
  auto n24 = gate_not(b[0]);
  auto n25 = gate_nand(a[0], n24);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n33 = gate_nand(n29, b[2]);
  auto n31 = gate_xor(n29, b[2]);
  auto n30 = gate_not(a[2]);
  auto n32 = gate_nand(n31, n30);
  auto n22 = gate_and(n33, n32);
  auto n37 = gate_nand(a[3], n22);
  auto n35 = gate_xor(a[3], n22);
  auto n34 = gate_not(b[3]);
  auto n36 = gate_nand(n35, n34);
  auto _gt_x_1_n29 = gate_nand(n37, n36);
  y[0] = gate_buf(_gt_x_1_n29);
}
template<> void CtfheUint<4>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n23 = gate_not(a[1]);
  auto n28 = gate_nand(n23, b[1]);
  auto n26 = gate_xor(n23, b[1]);
  auto n24 = gate_not(b[0]);
  auto n25 = gate_nand(a[0], n24);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n33 = gate_nand(n29, b[2]);
  auto n31 = gate_xor(n29, b[2]);
  auto n30 = gate_not(a[2]);
  auto n32 = gate_nand(n31, n30);
  auto n22 = gate_and(n33, n32);
  auto n37 = gate_nand(b[3], n22);
  auto n35 = gate_xor(b[3], n22);
  auto n34 = gate_not(a[3]);
  auto n36 = gate_nand(n35, n34);
  auto _gt_x_1_n29 = gate_nand(n37, n36);
  y[0] = gate_buf(_gt_x_1_n29);
}
template<> void CtfheUint<4>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_and(a[0], a[1]);
  y[2] = gate_xor(n6, a[2]);
  auto n5 = gate_and(n6, a[2]);
  y[1] = gate_xor(a[0], a[1]);
  y[0] = gate_not(a[0]);
  y[3] = gate_xor(n5, a[3]);
}
template<> void CtfheUint<4>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_xnor(a[1], b[1]);
  auto n17 = gate_not(b[2]);
  auto n22 = gate_xor(n17, a[2]);
  auto n18 = gate_not(a[3]);
  auto n21 = gate_xor(n18, b[3]);
  auto n19 = gate_not(a[0]);
  auto n20 = gate_xor(n19, b[0]);
  auto n15 = gate_and(n21, n20);
  auto n14 = gate_and(n15, n16);
  y[0] = gate_nand(n22, n14);
}
template<> void CtfheUint<4>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n13 = gate_not(a[1]);
  auto n12 = gate_not(a[3]);
  auto n11 = gate_and(n13, n12);
  auto n15 = gate_not(a[2]);
  auto n14 = gate_not(a[0]);
  auto n10 = gate_and(n15, n14);
  auto n16 = gate_nand(n11, n10);
  y[3] = gate_mux(c[3], b[3], n16);
  y[0] = gate_mux(c[0], b[0], n16);
  y[1] = gate_mux(c[1], b[1], n16);
  y[2] = gate_mux(c[2], b[2], n16);
}
template<> void CtfheUint<4>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(a[3]);
  auto n37 = gate_nand(n22, b[3]);
  auto n35 = gate_xor(n22, b[3]);
  auto n23 = gate_not(a[1]);
  auto n28 = gate_nand(n23, b[1]);
  auto n26 = gate_xor(n23, b[1]);
  auto n24 = gate_not(b[0]);
  auto n25 = gate_nand(a[0], n24);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n33 = gate_nand(n29, b[2]);
  auto n31 = gate_xor(n29, b[2]);
  auto n30 = gate_not(a[2]);
  auto n32 = gate_nand(n31, n30);
  auto n34 = gate_nand(n33, n32);
  auto n36 = gate_nand(n35, n34);
  y[0] = gate_nand(n37, n36);
}
template<> void CtfheUint<4>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(b[3]);
  auto n37 = gate_nand(n22, a[3]);
  auto n35 = gate_xor(n22, a[3]);
  auto n23 = gate_not(a[1]);
  auto n28 = gate_nand(n23, b[1]);
  auto n26 = gate_xor(n23, b[1]);
  auto n24 = gate_not(b[0]);
  auto n25 = gate_nand(a[0], n24);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n33 = gate_nand(n29, b[2]);
  auto n31 = gate_xor(n29, b[2]);
  auto n30 = gate_not(a[2]);
  auto n32 = gate_nand(n31, n30);
  auto n34 = gate_nand(n33, n32);
  auto n36 = gate_nand(n35, n34);
  y[0] = gate_nand(n37, n36);
}
template<> void CtfheUint<4>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n26 = gate_not(a[1]);
  auto n25 = gate_not(a[3]);
  auto n24 = gate_and(n26, n25);
  auto n28 = gate_not(a[2]);
  auto n27 = gate_not(a[0]);
  auto n23 = gate_and(n28, n27);
  auto n34 = gate_nand(n24, n23);
  auto n30 = gate_not(b[1]);
  auto n29 = gate_not(b[3]);
  auto n22 = gate_and(n30, n29);
  auto n32 = gate_not(b[2]);
  auto n31 = gate_not(b[0]);
  auto n21 = gate_and(n32, n31);
  auto n33 = gate_nand(n22, n21);
  y[0] = gate_and(n34, n33);
}
template<> void CtfheUint<4>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n15 = gate_not(a[1]);
  auto n16 = gate_not(a[0]);
  auto n14 = gate_not(a[3]);
  auto n13 = gate_and(n15, n14);
  auto n17 = gate_not(a[2]);
  auto n12 = gate_and(n17, n16);
  y[0] = gate_and(n13, n12);
}
template<> void CtfheUint<4>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n28 = gate_not(a[1]);
  auto n27 = gate_not(a[3]);
  auto n26 = gate_and(n28, n27);
  auto n30 = gate_not(a[2]);
  auto n29 = gate_not(a[0]);
  auto n25 = gate_and(n30, n29);
  auto n22 = gate_and(n26, n25);
  auto n32 = gate_not(b[1]);
  auto n31 = gate_not(b[3]);
  auto n24 = gate_and(n32, n31);
  auto n34 = gate_not(b[2]);
  auto n33 = gate_not(b[0]);
  auto n23 = gate_and(n34, n33);
  auto n21 = gate_and(n24, n23);
  y[0] = gate_nand(n22, n21);
}
template<> void CtfheUint<4>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_not(b[3]);
  auto n35 = gate_nand(n20, a[3]);
  auto n33 = gate_xor(n20, a[3]);
  auto n21 = gate_not(b[1]);
  auto n26 = gate_nand(n21, a[1]);
  auto n24 = gate_xor(n21, a[1]);
  auto n22 = gate_not(a[0]);
  auto n23 = gate_nand(b[0], n22);
  auto n25 = gate_nand(n24, n23);
  auto n27 = gate_nand(n26, n25);
  auto n31 = gate_nand(n27, a[2]);
  auto n29 = gate_xor(n27, a[2]);
  auto n28 = gate_not(b[2]);
  auto n30 = gate_nand(n29, n28);
  auto n32 = gate_nand(n31, n30);
  auto n34 = gate_nand(n33, n32);
  y[0] = gate_and(n35, n34);
}
template<> void CtfheUint<4>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_not(a[3]);
  auto n35 = gate_nand(n20, b[3]);
  auto n33 = gate_xor(n20, b[3]);
  auto n21 = gate_not(b[1]);
  auto n26 = gate_nand(n21, a[1]);
  auto n24 = gate_xor(n21, a[1]);
  auto n22 = gate_not(a[0]);
  auto n23 = gate_nand(b[0], n22);
  auto n25 = gate_nand(n24, n23);
  auto n27 = gate_nand(n26, n25);
  auto n31 = gate_nand(n27, a[2]);
  auto n29 = gate_xor(n27, a[2]);
  auto n28 = gate_not(b[2]);
  auto n30 = gate_nand(n29, n28);
  auto n32 = gate_nand(n31, n30);
  auto n34 = gate_nand(n33, n32);
  y[0] = gate_and(n35, n34);
}
template<> void CtfheUint<4>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n44 = gate_not(b[3]);
  auto n29 = gate_not(b[2]);
  auto n3 = gate_and(n44, n29);
  auto n33 = gate_not(b[1]);
  auto n2 = gate_and(n3, n33);
  auto n8 = gate_nand(b[0], n2);
  auto n6 = gate_and(a[3], n8);
  auto n9 = gate_mux(a[3], b[0], n33);
  auto n5 = gate_and(n3, n9);
  auto n10 = gate_not(a[2]);
  auto n11 = gate_nand(b[0], n10);
  auto n12 = gate_nand(n5, n11);
  auto n38 = gate_nand(n6, n12);
  auto n21 = gate_not(n38);
  auto n28 = gate_nand(a[2], n12);
  auto n13 = gate_not(n28);
  auto n16 = gate_nand(n13, n33);
  auto n19 = gate_xor(n33, n28);
  auto n14 = gate_not(n19);
  auto n32 = gate_not(a[1]);
  auto n20 = gate_nand(b[0], n32);
  auto n15 = gate_nand(n14, n20);
  auto n22 = gate_nand(n16, n15);
  auto n17 = gate_xor(n29, n22);
  auto n18 = gate_nand(n44, n17);
  auto n1 = gate_and(n21, n18);
  auto n27 = gate_nand(n20, n19);
  auto n25 = gate_nand(n22, n21);
  auto n23 = gate_xor(n22, n21);
  auto n24 = gate_nand(n23, n29);
  auto n26 = gate_nand(n25, n24);
  auto n4 = gate_and(n44, n26);
  auto n30 = gate_mux(n28, n27, n4);
  auto n48 = gate_not(n30);
  auto n37 = gate_nand(n29, n48);
  auto n43 = gate_xor(b[2], n30);
  auto n31 = gate_nand(n4, b[0]);
  auto n52 = gate_xor(n32, n31);
  auto n35 = gate_nand(n33, n52);
  auto n50 = gate_xor(n33, n52);
  auto n55 = gate_not(a[0]);
  auto n49 = gate_nand(b[0], n55);
  auto n34 = gate_nand(n50, n49);
  auto n42 = gate_nand(n35, n34);
  auto n36 = gate_nand(n43, n42);
  auto n40 = gate_nand(n37, n36);
  auto n39 = gate_nand(b[3], n38);
  auto n46 = gate_nand(n40, n39);
  auto n41 = gate_mux(n46, n40, n44);
  y[3] = gate_and(n1, n41);
  auto n47 = gate_xor(n43, n42);
  auto n45 = gate_nand(n44, n1);
  auto n53 = gate_nand(n46, n45);
  y[2] = gate_mux(n48, n47, n53);
  auto n51 = gate_xor(n50, n49);
  y[1] = gate_mux(n52, n51, n53);
  auto n54 = gate_nand(n53, b[0]);
  y[0] = gate_xor(n55, n54);
}
template<> void CtfheUint<4>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n69 = gate_not(a[3]);
  auto n12 = gate_not(a[2]);
  auto n9 = gate_not(a[1]);
  auto n56 = gate_not(a[0]);
  auto n13 = gate_nand(n9, n56);
  auto n10 = gate_nand(a[3], n13);
  auto n20 = gate_xor(n12, n10);
  auto n47 = gate_xor(b[2], b[3]);
  auto n46 = gate_not(n47);
  auto n37 = gate_not(b[3]);
  auto n60 = gate_xor(n37, b[1]);
  auto n5 = gate_and(b[0], n60);
  auto n11 = gate_nand(n5, n46);
  auto n3 = gate_and(n12, n11);
  auto n14 = gate_not(n13);
  auto n8 = gate_and(n14, a[3]);
  auto n2 = gate_and(n3, n8);
  auto n15 = gate_xor(n60, n2);
  auto n1 = gate_and(n46, n15);
  auto n36 = gate_not(b[0]);
  auto n16 = gate_not(n20);
  auto n17 = gate_nand(b[0], n16);
  auto n23 = gate_nand(n1, n17);
  auto n4 = gate_and(n2, n23);
  auto n18 = gate_not(n23);
  auto n19 = gate_nand(n18, b[0]);
  auto n32 = gate_nand(n20, n19);
  auto n21 = gate_nand(a[3], a[0]);
  auto n35 = gate_xor(a[1], n21);
  auto n22 = gate_mux(n35, b[3], n36);
  auto n26 = gate_not(n22);
  auto n25 = gate_xor(n32, n60);
  auto n31 = gate_nand(n26, n25);
  auto n43 = gate_nand(n4, n46);
  auto n24 = gate_not(n32);
  auto n29 = gate_nand(n24, n60);
  auto n27 = gate_not(n25);
  auto n28 = gate_nand(n27, n26);
  auto n42 = gate_nand(n29, n28);
  auto n30 = gate_nand(n46, n42);
  auto n33 = gate_nand(n43, n30);
  auto n54 = gate_mux(n32, n31, n33);
  auto n34 = gate_nand(b[0], n33);
  auto n64 = gate_xor(n35, n34);
  auto n40 = gate_nand(n64, n60);
  auto n38 = gate_xor(n64, n60);
  auto n59 = gate_mux(a[0], n37, n36);
  auto n39 = gate_nand(n38, n59);
  auto n48 = gate_nand(n40, n39);
  auto n41 = gate_xor(n54, n46);
  auto n53 = gate_nand(n48, n41);
  auto n44 = gate_nand(n47, n2);
  auto n71 = gate_mux(n44, n43, n42);
  auto n45 = gate_not(n54);
  auto n51 = gate_nand(n46, n45);
  auto n49 = gate_xor(n47, n54);
  auto n50 = gate_nand(n49, n48);
  auto n73 = gate_nand(n51, n50);
  auto n52 = gate_not(n73);
  auto n62 = gate_nand(n71, n52);
  auto n55 = gate_mux(n54, n53, n62);
  auto n70 = gate_xor(n69, n55);
  auto n58 = gate_xor(a[3], n56);
  auto n57 = gate_nand(b[0], n62);
  auto n65 = gate_xor(n58, n57);
  auto n6 = gate_and(a[3], n65);
  auto n61 = gate_xor(n60, n59);
  auto n63 = gate_nand(n62, n61);
  auto n67 = gate_xor(n64, n63);
  auto n7 = gate_and(n6, n67);
  y[2] = gate_xor(n70, n7);
  auto n68 = gate_not(n65);
  auto n66 = gate_nand(a[3], n68);
  y[1] = gate_xor(n67, n66);
  y[0] = gate_xor(n69, n68);
  auto n76 = gate_nand(n70, n7);
  auto n72 = gate_not(n71);
  auto n74 = gate_nand(n73, n72);
  auto n75 = gate_nand(a[3], n74);
  y[3] = gate_xor(n76, n75);
}
template<> void CtfheUint<4>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_and(a[2], b[0]);
  y[0] = gate_and(a[0], b[0]);
  auto n4 = gate_and(a[1], b[2]);
  auto n5 = gate_and(a[1], b[0]);
  auto n17 = gate_nand(a[0], b[1]);
  auto n8 = gate_not(n17);
  auto n2 = gate_and(n8, n5);
  y[1] = gate_xor(n8, n5);
  auto n7 = gate_nand(a[1], b[1]);
  auto n6 = gate_nand(b[2], a[0]);
  auto n10 = gate_xor(n7, n6);
  auto n9 = gate_xor(n10, n1);
  y[2] = gate_xor(n9, n2);
  auto n14 = gate_nand(a[0], b[3]);
  auto n12 = gate_nand(n9, n2);
  auto n11 = gate_nand(n10, n1);
  auto n13 = gate_nand(n12, n11);
  auto n21 = gate_xor(n14, n13);
  auto n16 = gate_nand(a[3], b[0]);
  auto n15 = gate_nand(a[2], b[1]);
  auto n19 = gate_xor(n16, n15);
  auto n18 = gate_nand(n17, n4);
  auto n20 = gate_xor(n19, n18);
  y[3] = gate_xor(n21, n20);
}
template<> void CtfheUint<4>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_and(a[1], a[3]);
  auto n8 = gate_and(a[2], a[0]);
  y[0] = gate_and(n6, n8);
}
template<> void CtfheUint<4>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_and(a[1], a[3]);
  auto n7 = gate_and(a[2], a[0]);
  y[0] = gate_nand(n6, n7);
}
template<> void CtfheUint<4>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n15 = gate_not(a[1]);
  auto n16 = gate_not(a[0]);
  auto n14 = gate_not(a[3]);
  auto n13 = gate_and(n15, n14);
  auto n17 = gate_not(a[2]);
  auto n12 = gate_and(n17, n16);
  y[0] = gate_and(n13, n12);
}
template<> void CtfheUint<4>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n12 = gate_not(a[1]);
  auto n11 = gate_not(a[3]);
  auto n10 = gate_and(n12, n11);
  auto n14 = gate_not(a[2]);
  auto n13 = gate_not(a[0]);
  auto n9 = gate_and(n14, n13);
  y[0] = gate_nand(n10, n9);
}
template<> void CtfheUint<4>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n5 = gate_not(a[0]);
  auto n7 = gate_xor(n5, a[1]);
  auto n6 = gate_xor(a[2], a[3]);
  y[0] = gate_xor(n7, n6);
}
template<> void CtfheUint<4>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n4 = gate_xor(a[0], a[1]);
  auto n3 = gate_xor(a[3], a[2]);
  y[0] = gate_xor(n4, n3);
}
template<> void CtfheUint<4>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n42 = gate_not(b[2]);
  auto n41 = gate_not(b[3]);
  auto n37 = gate_and(n42, n41);
  auto n40 = gate_and(n37, b[1]);
  auto n44 = gate_not(b[1]);
  auto n36 = gate_and(n37, n44);
  auto n46 = gate_not(b[0]);
  auto n35 = gate_and(n36, n46);
  y[0] = gate_and(a[0], n35);
  auto n43 = gate_mux(a[0], a[1], n46);
  y[1] = gate_and(n36, n43);
  auto n47 = gate_nand(a[1], n36);
  auto n45 = gate_mux(a[0], a[2], n44);
  auto n49 = gate_nand(n37, n45);
  auto n48 = gate_mux(n47, n49, n46);
  y[2] = gate_not(n48);
  auto n50 = gate_nand(n40, a[1]);
  auto n52 = gate_mux(n50, n49, b[0]);
  auto n51 = gate_nand(a[3], n35);
  y[3] = gate_nand(n52, n51);
}
template<> void CtfheUint<4>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n29 = gate_not(b[3]);
  auto n28 = gate_not(b[2]);
  auto n23 = gate_and(n29, n28);
  auto n34 = gate_not(b[1]);
  auto n25 = gate_and(n23, n34);
  auto n26 = gate_and(a[3], n25);
  auto n30 = gate_mux(a[3], a[1], n34);
  auto n35 = gate_nand(n23, n30);
  auto n31 = gate_mux(a[2], a[0], n34);
  auto n32 = gate_nand(n31, n23);
  auto n39 = gate_not(b[0]);
  auto n38 = gate_mux(a[3], a[2], n39);
  y[3] = gate_and(n26, n39);
  y[2] = gate_and(n25, n38);
  auto n33 = gate_mux(n35, n32, n39);
  y[0] = gate_not(n33);
  auto n36 = gate_nand(n25, a[2]);
  auto n37 = gate_mux(n36, n35, n39);
  y[1] = gate_not(n37);
}
template<> void CtfheUint<4>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_buf(a[3]);
  auto n20 = gate_and(b[1], a[2]);
  auto n37 = gate_not(b[0]);
  auto n23 = gate_nand(n20, n37);
  auto n27 = gate_not(a[3]);
  auto n22 = gate_not(b[2]);
  auto n21 = gate_not(b[3]);
  auto n24 = gate_nand(n22, n21);
  auto n32 = gate_mux(n23, n27, n24);
  auto n26 = gate_not(n24);
  auto n25 = gate_not(b[1]);
  auto n34 = gate_nand(n26, n25);
  auto n38 = gate_not(n34);
  auto n30 = gate_nand(a[0], n38);
  auto n28 = gate_nand(a[1], n26);
  auto n29 = gate_mux(n28, n27, b[1]);
  auto n31 = gate_mux(n30, n29, b[0]);
  y[0] = gate_nand(n32, n31);
  auto n33 = gate_mux(a[1], a[2], b[0]);
  auto n36 = gate_nand(n38, n33);
  auto n35 = gate_nand(a[3], n34);
  y[1] = gate_nand(n36, n35);
  auto n39 = gate_nand(n38, n37);
  y[2] = gate_mux(a[2], a[3], n39);
}
template<> void CtfheUint<4>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n27 = gate_xor(b[3], a[3]);
  auto n17 = gate_not(b[1]);
  auto n19 = gate_xor(a[1], n17);
  auto n16 = gate_not(a[0]);
  auto n18 = gate_nand(b[0], n16);
  y[1] = gate_xor(n19, n18);
  auto n22 = gate_not(b[2]);
  auto n24 = gate_xor(a[2], n22);
  auto n21 = gate_nand(a[1], n17);
  auto n20 = gate_nand(n19, n18);
  auto n23 = gate_nand(n21, n20);
  y[2] = gate_xor(n24, n23);
  auto n26 = gate_nand(a[2], n22);
  auto n25 = gate_nand(n24, n23);
  auto n28 = gate_nand(n26, n25);
  y[3] = gate_xnor(n28, n27);
}
template<> void CtfheUint<4>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  y[1] = gate_xor(a[1], a[0]);
  auto n8 = gate_not(a[1]);
  auto n7 = gate_not(a[0]);
  auto n9 = gate_nand(n8, n7);
  y[2] = gate_xor(a[2], n9);
  auto n11 = gate_not(n9);
  auto n10 = gate_not(a[2]);
  auto n12 = gate_nand(n11, n10);
  y[3] = gate_xor(a[3], n12);
}
template<> void CtfheUint<8>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_and(a[0], b[0]);
  y[0] = gate_xor(a[0], b[0]);
  auto n3 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n3, n2);
  auto n7 = gate_xor(b[2], a[2]);
  auto n5 = gate_nand(b[1], a[1]);
  auto n4 = gate_nand(n3, n2);
  auto n6 = gate_nand(n5, n4);
  y[2] = gate_xor(n7, n6);
  auto n11 = gate_xor(b[3], a[3]);
  auto n9 = gate_nand(b[2], a[2]);
  auto n8 = gate_nand(n7, n6);
  auto n10 = gate_nand(n9, n8);
  y[3] = gate_xor(n11, n10);
  auto n15 = gate_xor(b[4], a[4]);
  auto n13 = gate_nand(b[3], a[3]);
  auto n12 = gate_nand(n11, n10);
  auto n14 = gate_nand(n13, n12);
  y[4] = gate_xor(n15, n14);
  auto n19 = gate_xor(b[5], a[5]);
  auto n17 = gate_nand(b[4], a[4]);
  auto n16 = gate_nand(n15, n14);
  auto n18 = gate_nand(n17, n16);
  y[5] = gate_xor(n19, n18);
  auto n23 = gate_xor(b[6], a[6]);
  auto n21 = gate_nand(b[5], a[5]);
  auto n20 = gate_nand(n19, n18);
  auto n22 = gate_nand(n21, n20);
  y[6] = gate_xor(n23, n22);
  auto n25 = gate_nand(n23, n22);
  auto n24 = gate_nand(b[6], a[6]);
  auto n26 = gate_nand(n25, n24);
  auto n27 = gate_xor(b[7], n26);
  y[7] = gate_xor(a[7], n27);
}
template<> void CtfheUint<8>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[7] = gate_and(b[7], a[7]);
  y[0] = gate_and(b[0], a[0]);
  y[1] = gate_and(b[1], a[1]);
  y[2] = gate_and(b[2], a[2]);
  y[3] = gate_and(b[3], a[3]);
  y[4] = gate_and(b[4], a[4]);
  y[5] = gate_and(b[5], a[5]);
  y[6] = gate_and(b[6], a[6]);
}
template<> void CtfheUint<8>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[7] = gate_not(a[7]);
  y[6] = gate_not(a[6]);
  y[5] = gate_not(a[5]);
  y[4] = gate_not(a[4]);
  y[3] = gate_not(a[3]);
  y[2] = gate_not(a[2]);
  y[1] = gate_not(a[1]);
  y[0] = gate_not(a[0]);
}
template<> void CtfheUint<8>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n18 = gate_not(b[7]);
  auto n17 = gate_not(a[7]);
  y[7] = gate_nand(n18, n17);
  auto n20 = gate_not(b[6]);
  auto n19 = gate_not(a[6]);
  y[6] = gate_nand(n20, n19);
  auto n22 = gate_not(b[5]);
  auto n21 = gate_not(a[5]);
  y[5] = gate_nand(n22, n21);
  auto n24 = gate_not(b[4]);
  auto n23 = gate_not(a[4]);
  y[4] = gate_nand(n24, n23);
  auto n26 = gate_not(b[3]);
  auto n25 = gate_not(a[3]);
  y[3] = gate_nand(n26, n25);
  auto n28 = gate_not(b[2]);
  auto n27 = gate_not(a[2]);
  y[2] = gate_nand(n28, n27);
  auto n30 = gate_not(b[1]);
  auto n29 = gate_not(a[1]);
  y[1] = gate_nand(n30, n29);
  auto n32 = gate_not(b[0]);
  auto n31 = gate_not(a[0]);
  y[0] = gate_nand(n32, n31);
}
template<> void CtfheUint<8>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  y[4] = gate_buf(zero);
  y[5] = gate_buf(zero);
  y[6] = gate_buf(zero);
  y[7] = gate_buf(zero);
  auto N0 = gate_buf(a[0]);
  auto n4 = gate_xor(N0, a[1]);
  auto n11 = gate_xor(n4, a[2]);
  auto n10 = gate_xor(a[6], a[7]);
  auto n15 = gate_xor(n11, n10);
  auto n7 = gate_xor(a[4], a[3]);
  auto n14 = gate_xor(n7, a[5]);
  auto n3 = gate_and(n15, n14);
  y[0] = gate_xor(n15, n14);
  auto n6 = gate_nand(N0, a[1]);
  auto n5 = gate_nand(n4, a[2]);
  auto n18 = gate_nand(n6, n5);
  auto n9 = gate_nand(a[4], a[3]);
  auto n8 = gate_nand(n7, a[5]);
  auto n17 = gate_nand(n9, n8);
  auto n20 = gate_xor(n18, n17);
  auto n13 = gate_nand(a[6], a[7]);
  auto n12 = gate_nand(n11, n10);
  auto n19 = gate_nand(n13, n12);
  auto n16 = gate_xor(n20, n19);
  auto n1 = gate_and(n16, n3);
  y[1] = gate_xor(n16, n3);
  auto n22 = gate_nand(n18, n17);
  auto n21 = gate_nand(n20, n19);
  auto n23 = gate_nand(n22, n21);
  y[3] = gate_and(n1, n23);
  y[2] = gate_xor(n1, n23);
}
template<> void CtfheUint<8>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[7] = gate_xor(b[7], a[7]);
  y[6] = gate_xor(b[6], a[6]);
  y[5] = gate_xor(b[5], a[5]);
  y[4] = gate_xor(b[4], a[4]);
  y[3] = gate_xor(b[3], a[3]);
  y[2] = gate_xor(b[2], a[2]);
  y[1] = gate_xor(b[1], a[1]);
  y[0] = gate_xor(b[0], a[0]);
}
template<> void CtfheUint<8>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[7] = gate_and(a[0], b[7]);
  y[6] = gate_and(a[0], b[6]);
  y[5] = gate_and(a[0], b[5]);
  y[4] = gate_and(a[0], b[4]);
  y[3] = gate_and(a[0], b[3]);
  y[2] = gate_and(a[0], b[2]);
  y[1] = gate_and(a[0], b[1]);
  y[0] = gate_and(a[0], b[0]);
}
template<> void CtfheUint<8>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
  y[1] = gate_mux(c[1], b[1], a[0]);
  y[2] = gate_mux(c[2], b[2], a[0]);
  y[3] = gate_mux(c[3], b[3], a[0]);
  y[4] = gate_mux(c[4], b[4], a[0]);
  y[5] = gate_mux(c[5], b[5], a[0]);
  y[6] = gate_mux(c[6], b[6], a[0]);
  y[7] = gate_mux(c[7], b[7], a[0]);
}
template<> void CtfheUint<8>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_and(a[0], b[0]);
  y[0] = gate_xor(a[0], b[0]);
  auto n3 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n3, n2);
  auto n7 = gate_xor(b[2], a[2]);
  auto n5 = gate_nand(b[1], a[1]);
  auto n4 = gate_nand(n3, n2);
  auto n6 = gate_nand(n5, n4);
  y[2] = gate_xor(n7, n6);
  auto n11 = gate_xor(b[3], a[3]);
  auto n9 = gate_nand(b[2], a[2]);
  auto n8 = gate_nand(n7, n6);
  auto n10 = gate_nand(n9, n8);
  y[3] = gate_xor(n11, n10);
  auto n15 = gate_xor(b[4], a[4]);
  auto n13 = gate_nand(b[3], a[3]);
  auto n12 = gate_nand(n11, n10);
  auto n14 = gate_nand(n13, n12);
  y[4] = gate_xor(n15, n14);
  auto n19 = gate_xor(b[5], a[5]);
  auto n17 = gate_nand(b[4], a[4]);
  auto n16 = gate_nand(n15, n14);
  auto n18 = gate_nand(n17, n16);
  y[5] = gate_xor(n19, n18);
  auto n23 = gate_xor(b[6], a[6]);
  auto n21 = gate_nand(b[5], a[5]);
  auto n20 = gate_nand(n19, n18);
  auto n22 = gate_nand(n21, n20);
  y[6] = gate_xor(n23, n22);
  auto n25 = gate_nand(b[6], a[6]);
  auto n24 = gate_nand(n23, n22);
  y[7] = gate_nand(n25, n24);
}
template<> void CtfheUint<8>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  y[1] = gate_xor(a[1], y[0]);
  auto n7 = gate_not(a[1]);
  auto n2 = gate_and(n7, y[0]);
  y[2] = gate_xor(a[2], n2);
  auto n8 = gate_not(a[2]);
  auto n3 = gate_and(n2, n8);
  y[3] = gate_xor(a[3], n3);
  auto n9 = gate_not(a[3]);
  auto n4 = gate_and(n3, n9);
  y[4] = gate_xor(a[4], n4);
  auto n10 = gate_not(a[4]);
  auto n5 = gate_and(n4, n10);
  y[5] = gate_xor(a[5], n5);
  auto n11 = gate_not(a[5]);
  auto n6 = gate_and(n5, n11);
  y[6] = gate_xor(a[6], n6);
  auto n14 = gate_not(a[7]);
  auto n12 = gate_not(a[6]);
  auto n13 = gate_nand(n6, n12);
  y[7] = gate_xor(n14, n13);
}
template<> void CtfheUint<8>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_not(a[6]);
  auto n12 = gate_nand(b[0], n11);
  auto n135 = gate_not(b[7]);
  auto n193 = gate_not(b[6]);
  auto n4 = gate_and(n135, n193);
  auto n142 = gate_not(b[5]);
  auto n3 = gate_and(n4, n142);
  auto n178 = gate_not(b[4]);
  auto n7 = gate_and(n3, n178);
  auto n148 = gate_not(b[3]);
  auto n2 = gate_and(n7, n148);
  auto n164 = gate_not(b[2]);
  auto n6 = gate_and(n2, n164);
  auto n5 = gate_and(n12, n6);
  auto n19 = gate_not(a[7]);
  auto n13 = gate_nand(b[1], n19);
  auto n21 = gate_nand(n5, n13);
  y[6] = gate_not(n21);
  auto n14 = gate_nand(y[6], b[0]);
  auto n32 = gate_nand(a[6], n14);
  auto n15 = gate_not(n32);
  auto n151 = gate_not(b[1]);
  auto n1 = gate_and(n151, n6);
  auto n17 = gate_nand(n15, n151);
  auto n28 = gate_xor(b[1], n32);
  auto n34 = gate_not(a[5]);
  auto n29 = gate_nand(b[0], n34);
  auto n16 = gate_nand(n28, n29);
  auto n18 = gate_nand(n17, n16);
  auto n24 = gate_nand(n18, n164);
  auto n22 = gate_xor(n18, n164);
  auto n20 = gate_nand(b[0], n19);
  auto n201 = gate_nand(n1, n20);
  y[7] = gate_not(n201);
  auto n8 = gate_and(n21, n201);
  auto n40 = gate_nand(a[7], n8);
  auto n27 = gate_not(n40);
  auto n23 = gate_nand(n22, n27);
  auto n25 = gate_nand(n24, n23);
  auto n26 = gate_nand(n2, n25);
  y[5] = gate_not(n26);
  auto n64 = gate_nand(n27, n26);
  auto n47 = gate_not(n64);
  auto n44 = gate_nand(n47, n148);
  auto n30 = gate_not(n28);
  auto n31 = gate_nand(n30, n29);
  auto n37 = gate_mux(n32, n31, y[5]);
  auto n49 = gate_xor(b[2], n37);
  auto n33 = gate_nand(y[5], b[0]);
  auto n55 = gate_xor(n34, n33);
  auto n36 = gate_nand(n151, n55);
  auto n53 = gate_xor(n151, n55);
  auto n57 = gate_not(a[4]);
  auto n52 = gate_nand(b[0], n57);
  auto n35 = gate_nand(n53, n52);
  auto n48 = gate_nand(n36, n35);
  auto n39 = gate_nand(n49, n48);
  auto n51 = gate_not(n37);
  auto n38 = gate_nand(n164, n51);
  auto n42 = gate_nand(n39, n38);
  auto n41 = gate_nand(b[3], n40);
  auto n43 = gate_nand(n42, n41);
  auto n45 = gate_nand(n44, n43);
  auto n46 = gate_nand(n7, n45);
  y[4] = gate_not(n46);
  auto n94 = gate_nand(n47, n46);
  auto n70 = gate_not(n94);
  auto n68 = gate_nand(n70, n178);
  auto n50 = gate_xor(n49, n48);
  auto n73 = gate_mux(n51, n50, y[4]);
  auto n71 = gate_xor(n148, n73);
  auto n54 = gate_xor(n53, n52);
  auto n78 = gate_mux(n55, n54, y[4]);
  auto n61 = gate_nand(n78, n164);
  auto n75 = gate_xor(n164, n78);
  auto n56 = gate_nand(y[4], b[0]);
  auto n83 = gate_xor(n57, n56);
  auto n59 = gate_nand(n151, n83);
  auto n81 = gate_xor(n151, n83);
  auto n85 = gate_not(a[3]);
  auto n80 = gate_nand(b[0], n85);
  auto n58 = gate_nand(n81, n80);
  auto n76 = gate_nand(n59, n58);
  auto n60 = gate_nand(n75, n76);
  auto n72 = gate_nand(n61, n60);
  auto n63 = gate_nand(n71, n72);
  auto n62 = gate_nand(n73, n148);
  auto n66 = gate_nand(n63, n62);
  auto n65 = gate_nand(b[4], n64);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n77 = gate_nand(n3, n69);
  y[3] = gate_not(n77);
  auto n136 = gate_nand(n70, n77);
  auto n131 = gate_not(n136);
  auto n98 = gate_nand(n131, n142);
  auto n74 = gate_xor(n72, n71);
  auto n102 = gate_mux(n74, n73, n77);
  auto n100 = gate_xor(n102, n178);
  auto n79 = gate_xor(n76, n75);
  auto n106 = gate_mux(n79, n78, n77);
  auto n91 = gate_nand(n106, n148);
  auto n104 = gate_xor(n106, n148);
  auto n82 = gate_xor(n81, n80);
  auto n110 = gate_mux(n83, n82, y[3]);
  auto n89 = gate_nand(n110, n164);
  auto n108 = gate_xor(n164, n110);
  auto n84 = gate_nand(y[3], b[0]);
  auto n115 = gate_xor(n85, n84);
  auto n87 = gate_nand(n151, n115);
  auto n113 = gate_xor(n151, n115);
  auto n117 = gate_not(a[2]);
  auto n112 = gate_nand(b[0], n117);
  auto n86 = gate_nand(n113, n112);
  auto n109 = gate_nand(n87, n86);
  auto n88 = gate_nand(n108, n109);
  auto n105 = gate_nand(n89, n88);
  auto n90 = gate_nand(n104, n105);
  auto n101 = gate_nand(n91, n90);
  auto n93 = gate_nand(n100, n101);
  auto n92 = gate_nand(n102, n178);
  auto n96 = gate_nand(n93, n92);
  auto n95 = gate_nand(b[5], n94);
  auto n97 = gate_nand(n96, n95);
  auto n99 = gate_nand(n98, n97);
  auto n130 = gate_nand(n4, n99);
  auto n9 = gate_and(n131, n130);
  y[2] = gate_not(n130);
  auto n103 = gate_xor(n101, n100);
  auto n189 = gate_mux(n103, n102, n130);
  auto n186 = gate_xor(n189, n142);
  auto n107 = gate_xor(n105, n104);
  auto n139 = gate_mux(n107, n106, n130);
  auto n125 = gate_nand(n139, n178);
  auto n137 = gate_xor(n139, n178);
  auto n111 = gate_xor(n109, n108);
  auto n174 = gate_mux(n111, n110, n130);
  auto n123 = gate_nand(n174, n148);
  auto n172 = gate_xor(n174, n148);
  auto n114 = gate_xor(n113, n112);
  auto n145 = gate_mux(n115, n114, y[2]);
  auto n121 = gate_nand(n145, n164);
  auto n143 = gate_xor(n164, n145);
  auto n116 = gate_nand(y[2], b[0]);
  auto n161 = gate_xor(n117, n116);
  auto n119 = gate_nand(n151, n161);
  auto n159 = gate_xor(n151, n161);
  auto n150 = gate_not(a[1]);
  auto n158 = gate_nand(b[0], n150);
  auto n118 = gate_nand(n159, n158);
  auto n144 = gate_nand(n119, n118);
  auto n120 = gate_nand(n143, n144);
  auto n173 = gate_nand(n121, n120);
  auto n122 = gate_nand(n172, n173);
  auto n138 = gate_nand(n123, n122);
  auto n124 = gate_nand(n137, n138);
  auto n187 = gate_nand(n125, n124);
  auto n127 = gate_nand(n186, n187);
  auto n126 = gate_nand(n189, n142);
  auto n129 = gate_nand(n127, n126);
  auto n128 = gate_nand(b[6], n136);
  auto n133 = gate_nand(n129, n128);
  auto n132 = gate_nand(n9, n193);
  auto n134 = gate_nand(n133, n132);
  auto n188 = gate_nand(n135, n134);
  auto n10 = gate_and(n9, n188);
  y[1] = gate_not(n188);
  auto n200 = gate_nand(n10, n135);
  auto n198 = gate_nand(b[7], n136);
  auto n140 = gate_xor(n138, n137);
  auto n141 = gate_mux(n140, n139, n188);
  auto n185 = gate_nand(n142, n141);
  auto n183 = gate_xor(n142, n141);
  auto n146 = gate_xor(n144, n143);
  auto n147 = gate_mux(n146, n145, n188);
  auto n171 = gate_nand(n148, n147);
  auto n169 = gate_xor(n148, n147);
  auto n149 = gate_nand(y[1], b[0]);
  auto n152 = gate_xor(n150, n149);
  auto n157 = gate_nand(n152, n151);
  auto n155 = gate_xor(n152, n151);
  auto n153 = gate_not(a[0]);
  auto n154 = gate_nand(b[0], n153);
  auto n156 = gate_nand(n155, n154);
  auto n163 = gate_nand(n157, n156);
  auto n160 = gate_xor(n159, n158);
  auto n162 = gate_mux(n161, n160, y[1]);
  auto n167 = gate_nand(n163, n162);
  auto n165 = gate_xor(n163, n162);
  auto n166 = gate_nand(n165, n164);
  auto n168 = gate_nand(n167, n166);
  auto n170 = gate_nand(n169, n168);
  auto n177 = gate_nand(n171, n170);
  auto n175 = gate_xor(n173, n172);
  auto n176 = gate_mux(n175, n174, n188);
  auto n181 = gate_nand(n177, n176);
  auto n179 = gate_xor(n177, n176);
  auto n180 = gate_nand(n179, n178);
  auto n182 = gate_nand(n181, n180);
  auto n184 = gate_nand(n183, n182);
  auto n192 = gate_nand(n185, n184);
  auto n190 = gate_xor(n187, n186);
  auto n191 = gate_mux(n190, n189, n188);
  auto n196 = gate_nand(n192, n191);
  auto n194 = gate_xor(n192, n191);
  auto n195 = gate_nand(n194, n193);
  auto n197 = gate_nand(n196, n195);
  auto n199 = gate_nand(n198, n197);
  y[0] = gate_nand(n200, n199);
}
template<> void CtfheUint<8>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n264 = gate_not(b[7]);
  auto n251 = gate_xor(a[7], n264);
  auto n266 = gate_not(n251);
  auto n160 = gate_not(a[1]);
  auto n194 = gate_not(a[0]);
  auto n119 = gate_nand(n160, n194);
  auto n20 = gate_not(n119);
  auto n19 = gate_not(a[2]);
  auto n86 = gate_nand(n20, n19);
  auto n22 = gate_not(n86);
  auto n21 = gate_not(a[3]);
  auto n59 = gate_nand(n22, n21);
  auto n24 = gate_not(n59);
  auto n23 = gate_not(a[4]);
  auto n39 = gate_nand(n24, n23);
  auto n26 = gate_not(n39);
  auto n25 = gate_not(a[5]);
  auto n29 = gate_nand(n26, n25);
  auto n27 = gate_not(n29);
  auto n31 = gate_not(a[6]);
  auto n7 = gate_and(n27, n31);
  auto n46 = gate_nand(a[7], n7);
  auto n252 = gate_not(n46);
  auto n8 = gate_and(n252, b[0]);
  auto n237 = gate_xor(b[6], b[7]);
  auto n179 = gate_not(n237);
  auto n186 = gate_xor(b[5], b[7]);
  auto n142 = gate_not(n186);
  auto n5 = gate_and(n179, n142);
  auto n218 = gate_xor(b[4], b[7]);
  auto n183 = gate_not(n218);
  auto n4 = gate_and(n5, n183);
  auto n192 = gate_xor(b[3], b[7]);
  auto n221 = gate_not(n192);
  auto n3 = gate_and(n4, n221);
  auto n203 = gate_xor(b[2], b[7]);
  auto n189 = gate_not(n203);
  auto n2 = gate_and(n3, n189);
  auto n196 = gate_xor(b[1], b[7]);
  auto n206 = gate_not(n196);
  auto n9 = gate_and(n2, n206);
  auto n28 = gate_nand(n9, b[0]);
  auto n10 = gate_and(n252, n28);
  auto n35 = gate_nand(n10, n206);
  auto n30 = gate_nand(a[7], n29);
  auto n37 = gate_xor(n31, n30);
  auto n263 = gate_not(b[0]);
  auto n6 = gate_and(n264, n263);
  auto n33 = gate_mux(n37, n264, n263);
  auto n32 = gate_nand(n196, n46);
  auto n34 = gate_nand(n33, n32);
  auto n36 = gate_nand(n35, n34);
  auto n250 = gate_nand(n2, n36);
  auto n53 = gate_nand(n10, n250);
  auto n52 = gate_not(n53);
  auto n50 = gate_nand(n52, n189);
  auto n38 = gate_nand(n37, n250);
  auto n54 = gate_not(n38);
  auto n45 = gate_nand(n206, n54);
  auto n43 = gate_xor(n196, n38);
  auto n40 = gate_nand(a[7], n39);
  auto n58 = gate_xor(a[5], n40);
  auto n41 = gate_mux(n58, b[7], n263);
  auto n42 = gate_not(n41);
  auto n44 = gate_nand(n43, n42);
  auto n48 = gate_nand(n45, n44);
  auto n47 = gate_nand(n203, n46);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  auto n56 = gate_nand(n3, n51);
  auto n75 = gate_nand(n52, n56);
  auto n74 = gate_not(n75);
  auto n70 = gate_nand(n53, n192);
  auto n55 = gate_nand(n54, n56);
  auto n76 = gate_not(n55);
  auto n68 = gate_nand(n189, n76);
  auto n66 = gate_xor(n203, n55);
  auto n249 = gate_not(n56);
  auto n57 = gate_nand(n249, b[0]);
  auto n82 = gate_xor(n58, n57);
  auto n64 = gate_nand(n82, n206);
  auto n62 = gate_xor(n82, n206);
  auto n60 = gate_nand(a[7], n59);
  auto n85 = gate_xor(a[4], n60);
  auto n61 = gate_mux(n85, b[7], n263);
  auto n79 = gate_not(n61);
  auto n63 = gate_nand(n62, n79);
  auto n65 = gate_nand(n64, n63);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n72 = gate_nand(n70, n69);
  auto n71 = gate_nand(n221, n74);
  auto n73 = gate_nand(n72, n71);
  auto n78 = gate_nand(n4, n73);
  auto n140 = gate_nand(n74, n78);
  auto n104 = gate_not(n140);
  auto n100 = gate_nand(n75, n218);
  auto n77 = gate_nand(n76, n78);
  auto n105 = gate_not(n77);
  auto n98 = gate_nand(n221, n105);
  auto n96 = gate_xor(n192, n77);
  auto n248 = gate_not(n78);
  auto n80 = gate_xor(n206, n79);
  auto n81 = gate_nand(n248, n80);
  auto n111 = gate_xor(n82, n81);
  auto n83 = gate_not(n111);
  auto n94 = gate_nand(n83, n189);
  auto n92 = gate_xor(n189, n83);
  auto n84 = gate_nand(n248, b[0]);
  auto n115 = gate_xor(n85, n84);
  auto n91 = gate_nand(n115, n206);
  auto n89 = gate_xor(n115, n206);
  auto n87 = gate_nand(a[7], n86);
  auto n118 = gate_xor(a[3], n87);
  auto n88 = gate_mux(n118, b[7], n263);
  auto n112 = gate_not(n88);
  auto n90 = gate_nand(n89, n112);
  auto n108 = gate_nand(n91, n90);
  auto n93 = gate_nand(n92, n108);
  auto n95 = gate_nand(n94, n93);
  auto n97 = gate_nand(n96, n95);
  auto n99 = gate_nand(n98, n97);
  auto n102 = gate_nand(n100, n99);
  auto n101 = gate_nand(n183, n104);
  auto n103 = gate_nand(n102, n101);
  auto n107 = gate_nand(n5, n103);
  auto n14 = gate_and(n104, n107);
  auto n136 = gate_nand(n140, n186);
  auto n106 = gate_nand(n105, n107);
  auto n141 = gate_not(n106);
  auto n134 = gate_nand(n183, n141);
  auto n132 = gate_xor(n218, n106);
  auto n247 = gate_not(n107);
  auto n109 = gate_xor(n189, n108);
  auto n110 = gate_nand(n247, n109);
  auto n148 = gate_xor(n111, n110);
  auto n130 = gate_nand(n148, n221);
  auto n128 = gate_xor(n148, n221);
  auto n113 = gate_xor(n206, n112);
  auto n114 = gate_nand(n247, n113);
  auto n152 = gate_xor(n115, n114);
  auto n116 = gate_not(n152);
  auto n127 = gate_nand(n116, n189);
  auto n125 = gate_xor(n203, n152);
  auto n117 = gate_nand(n247, b[0]);
  auto n156 = gate_xor(n118, n117);
  auto n124 = gate_nand(n156, n206);
  auto n122 = gate_xor(n156, n206);
  auto n120 = gate_nand(a[7], n119);
  auto n158 = gate_xor(a[2], n120);
  auto n121 = gate_mux(n158, b[7], n263);
  auto n153 = gate_not(n121);
  auto n123 = gate_nand(n122, n153);
  auto n149 = gate_nand(n124, n123);
  auto n126 = gate_nand(n125, n149);
  auto n145 = gate_nand(n127, n126);
  auto n129 = gate_nand(n128, n145);
  auto n131 = gate_nand(n130, n129);
  auto n133 = gate_nand(n132, n131);
  auto n135 = gate_nand(n134, n133);
  auto n138 = gate_nand(n136, n135);
  auto n137 = gate_nand(n142, n14);
  auto n139 = gate_nand(n138, n137);
  auto n144 = gate_nand(n179, n139);
  auto n17 = gate_and(n14, n144);
  auto n178 = gate_nand(n140, n237);
  auto n143 = gate_nand(n141, n144);
  auto n234 = gate_not(n143);
  auto n176 = gate_nand(n142, n234);
  auto n174 = gate_xor(n186, n143);
  auto n246 = gate_not(n144);
  auto n146 = gate_xor(n221, n145);
  auto n147 = gate_nand(n246, n146);
  auto n16 = gate_xnor(n148, n147);
  auto n172 = gate_nand(n16, n183);
  auto n170 = gate_xor(n183, n16);
  auto n150 = gate_xor(n189, n149);
  auto n151 = gate_nand(n246, n150);
  auto n225 = gate_xor(n152, n151);
  auto n169 = gate_nand(n225, n221);
  auto n167 = gate_xor(n221, n225);
  auto n154 = gate_xor(n206, n153);
  auto n155 = gate_nand(n246, n154);
  auto n15 = gate_xnor(n156, n155);
  auto n166 = gate_nand(n15, n189);
  auto n164 = gate_xor(n189, n15);
  auto n157 = gate_nand(b[0], n246);
  auto n209 = gate_xor(n158, n157);
  auto n163 = gate_nand(n209, n206);
  auto n161 = gate_xor(n206, n209);
  auto n159 = gate_nand(a[0], a[7]);
  auto n198 = gate_xor(n160, n159);
  auto n205 = gate_mux(n198, n264, n263);
  auto n162 = gate_nand(n161, n205);
  auto n188 = gate_nand(n163, n162);
  auto n165 = gate_nand(n164, n188);
  auto n220 = gate_nand(n166, n165);
  auto n168 = gate_nand(n167, n220);
  auto n182 = gate_nand(n169, n168);
  auto n171 = gate_nand(n170, n182);
  auto n173 = gate_nand(n172, n171);
  auto n175 = gate_nand(n174, n173);
  auto n177 = gate_nand(n176, n175);
  auto n181 = gate_nand(n178, n177);
  auto n180 = gate_nand(n179, n17);
  auto n223 = gate_nand(n181, n180);
  auto n245 = gate_not(n223);
  auto n242 = gate_nand(n17, n245);
  auto n184 = gate_xor(n183, n182);
  auto n185 = gate_nand(n223, n184);
  auto n187 = gate_xor(n16, n185);
  auto n233 = gate_nand(n187, n186);
  auto n231 = gate_xor(n187, n186);
  auto n190 = gate_xor(n189, n188);
  auto n191 = gate_nand(n223, n190);
  auto n193 = gate_xor(n15, n191);
  auto n217 = gate_nand(n193, n192);
  auto n215 = gate_xor(n193, n192);
  auto n195 = gate_mux(n194, b[7], n263);
  auto n202 = gate_nand(n196, n195);
  auto n200 = gate_xor(n196, n195);
  auto n197 = gate_nand(b[0], n223);
  auto n199 = gate_xor(n198, n197);
  auto n201 = gate_nand(n200, n199);
  auto n204 = gate_nand(n202, n201);
  auto n213 = gate_nand(n204, n203);
  auto n211 = gate_xor(n204, n203);
  auto n207 = gate_xor(n206, n205);
  auto n208 = gate_nand(n223, n207);
  auto n210 = gate_xor(n209, n208);
  auto n212 = gate_nand(n211, n210);
  auto n214 = gate_nand(n213, n212);
  auto n216 = gate_nand(n215, n214);
  auto n219 = gate_nand(n217, n216);
  auto n229 = gate_nand(n219, n218);
  auto n227 = gate_xor(n219, n218);
  auto n222 = gate_xor(n221, n220);
  auto n224 = gate_nand(n223, n222);
  auto n226 = gate_xor(n225, n224);
  auto n228 = gate_nand(n227, n226);
  auto n230 = gate_nand(n229, n228);
  auto n232 = gate_nand(n231, n230);
  auto n236 = gate_nand(n233, n232);
  auto n235 = gate_nand(n234, n245);
  auto n240 = gate_nand(n236, n235);
  auto n238 = gate_xor(n236, n235);
  auto n239 = gate_nand(n238, n237);
  auto n241 = gate_nand(n240, n239);
  auto n262 = gate_nand(n242, n241);
  auto n243 = gate_not(n262);
  auto n269 = gate_nand(n266, n243);
  auto n244 = gate_not(n269);
  auto n261 = gate_xor(n251, n245);
  auto n18 = gate_and(n244, n261);
  auto n260 = gate_xor(n266, n246);
  auto n11 = gate_and(n18, n260);
  auto n259 = gate_xor(n266, n247);
  auto n13 = gate_and(n11, n259);
  auto n258 = gate_xor(n266, n248);
  auto n1 = gate_and(n13, n258);
  auto n257 = gate_xor(n266, n249);
  auto n12 = gate_and(n1, n257);
  auto n256 = gate_xor(n251, n250);
  auto n255 = gate_nand(n12, n256);
  auto n253 = gate_nand(n8, n9);
  auto n254 = gate_xor(n266, n253);
  y[7] = gate_xor(n255, n254);
  y[6] = gate_xor(n12, n256);
  y[5] = gate_xor(n1, n257);
  y[4] = gate_xor(n13, n258);
  y[3] = gate_xor(n11, n259);
  y[2] = gate_xor(n18, n260);
  y[1] = gate_xor(n244, n261);
  auto n268 = gate_xor(n262, n266);
  auto n265 = gate_nand(n6, n9);
  auto n267 = gate_nand(n266, n265);
  y[0] = gate_mux(n269, n268, n267);
}
template<> void CtfheUint<8>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n31 = gate_xnor(b[7], a[7]);
  auto n38 = gate_xnor(a[1], b[1]);
  auto n40 = gate_xnor(b[4], a[4]);
  auto n41 = gate_xnor(b[5], a[5]);
  auto n42 = gate_xnor(b[6], a[6]);
  auto n43 = gate_not(b[2]);
  auto n48 = gate_xor(n43, a[2]);
  auto n44 = gate_not(a[3]);
  auto n47 = gate_xor(n44, b[3]);
  auto n45 = gate_not(a[0]);
  auto n46 = gate_xor(n45, b[0]);
  auto n33 = gate_and(n47, n46);
  auto n32 = gate_and(n33, n38);
  auto n39 = gate_and(n48, n32);
  auto n35 = gate_and(n39, n41);
  auto n34 = gate_and(n35, n40);
  auto n36 = gate_and(n34, n42);
  y[0] = gate_and(n36, n31);
}
template<> void CtfheUint<8>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n39 = gate_not(b[7]);
  auto n74 = gate_nand(n39, a[7]);
  auto n72 = gate_xor(n39, a[7]);
  auto n40 = gate_not(b[5]);
  auto n65 = gate_nand(n40, a[5]);
  auto n63 = gate_xor(n40, a[5]);
  auto n41 = gate_not(b[3]);
  auto n56 = gate_nand(n41, a[3]);
  auto n54 = gate_xor(n41, a[3]);
  auto n42 = gate_not(b[2]);
  auto n52 = gate_nand(n42, a[2]);
  auto n50 = gate_xor(n42, a[2]);
  auto n43 = gate_not(b[1]);
  auto n48 = gate_nand(n43, a[1]);
  auto n46 = gate_xor(n43, a[1]);
  auto n44 = gate_not(a[0]);
  auto n45 = gate_nand(b[0], n44);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n55 = gate_nand(n54, n53);
  auto n57 = gate_nand(n56, n55);
  auto n61 = gate_nand(n57, a[4]);
  auto n59 = gate_xor(n57, a[4]);
  auto n58 = gate_not(b[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n64 = gate_nand(n63, n62);
  auto n66 = gate_nand(n65, n64);
  auto n70 = gate_nand(n66, a[6]);
  auto n68 = gate_xor(n66, a[6]);
  auto n67 = gate_not(b[6]);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n73 = gate_nand(n72, n71);
  y[0] = gate_nand(n74, n73);
}
template<> void CtfheUint<8>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n39 = gate_not(a[7]);
  auto n74 = gate_nand(n39, b[7]);
  auto n72 = gate_xor(n39, b[7]);
  auto n40 = gate_not(b[5]);
  auto n65 = gate_nand(n40, a[5]);
  auto n63 = gate_xor(n40, a[5]);
  auto n41 = gate_not(b[3]);
  auto n56 = gate_nand(n41, a[3]);
  auto n54 = gate_xor(n41, a[3]);
  auto n42 = gate_not(b[2]);
  auto n52 = gate_nand(n42, a[2]);
  auto n50 = gate_xor(n42, a[2]);
  auto n43 = gate_not(b[1]);
  auto n48 = gate_nand(n43, a[1]);
  auto n46 = gate_xor(n43, a[1]);
  auto n44 = gate_not(a[0]);
  auto n45 = gate_nand(b[0], n44);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n55 = gate_nand(n54, n53);
  auto n57 = gate_nand(n56, n55);
  auto n61 = gate_nand(n57, a[4]);
  auto n59 = gate_xor(n57, a[4]);
  auto n58 = gate_not(b[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n64 = gate_nand(n63, n62);
  auto n66 = gate_nand(n65, n64);
  auto n70 = gate_nand(n66, a[6]);
  auto n68 = gate_xor(n66, a[6]);
  auto n67 = gate_not(b[6]);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n73 = gate_nand(n72, n71);
  y[0] = gate_nand(n74, n73);
}
template<> void CtfheUint<8>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n41 = gate_not(b[6]);
  auto n70 = gate_nand(n41, a[6]);
  auto n68 = gate_xor(n41, a[6]);
  auto n42 = gate_not(a[1]);
  auto n47 = gate_nand(n42, b[1]);
  auto n45 = gate_xor(n42, b[1]);
  auto n43 = gate_not(b[0]);
  auto n44 = gate_nand(a[0], n43);
  auto n46 = gate_nand(n45, n44);
  auto n48 = gate_nand(n47, n46);
  auto n52 = gate_nand(n48, b[2]);
  auto n50 = gate_xor(n48, b[2]);
  auto n49 = gate_not(a[2]);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n57 = gate_nand(n53, b[3]);
  auto n55 = gate_xor(n53, b[3]);
  auto n54 = gate_not(a[3]);
  auto n56 = gate_nand(n55, n54);
  auto n40 = gate_and(n57, n56);
  auto n61 = gate_nand(n40, a[4]);
  auto n59 = gate_xor(n40, a[4]);
  auto n58 = gate_not(b[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n66 = gate_nand(n62, a[5]);
  auto n64 = gate_xor(n62, a[5]);
  auto n63 = gate_not(b[5]);
  auto n65 = gate_nand(n64, n63);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n75 = gate_nand(n71, a[7]);
  auto n73 = gate_xor(n71, a[7]);
  auto n72 = gate_not(b[7]);
  auto n74 = gate_nand(n73, n72);
  y[0] = gate_nand(n75, n74);
}
template<> void CtfheUint<8>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n41 = gate_not(b[6]);
  auto n70 = gate_nand(n41, a[6]);
  auto n68 = gate_xor(n41, a[6]);
  auto n42 = gate_not(a[1]);
  auto n47 = gate_nand(n42, b[1]);
  auto n45 = gate_xor(n42, b[1]);
  auto n43 = gate_not(b[0]);
  auto n44 = gate_nand(a[0], n43);
  auto n46 = gate_nand(n45, n44);
  auto n48 = gate_nand(n47, n46);
  auto n52 = gate_nand(n48, b[2]);
  auto n50 = gate_xor(n48, b[2]);
  auto n49 = gate_not(a[2]);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n57 = gate_nand(n53, b[3]);
  auto n55 = gate_xor(n53, b[3]);
  auto n54 = gate_not(a[3]);
  auto n56 = gate_nand(n55, n54);
  auto n40 = gate_and(n57, n56);
  auto n61 = gate_nand(n40, a[4]);
  auto n59 = gate_xor(n40, a[4]);
  auto n58 = gate_not(b[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n66 = gate_nand(n62, a[5]);
  auto n64 = gate_xor(n62, a[5]);
  auto n63 = gate_not(b[5]);
  auto n65 = gate_nand(n64, n63);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n75 = gate_nand(n71, b[7]);
  auto n73 = gate_xor(n71, b[7]);
  auto n72 = gate_not(a[7]);
  auto n74 = gate_nand(n73, n72);
  y[0] = gate_nand(n75, n74);
}
template<> void CtfheUint<8>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n2 = gate_and(a[0], a[1]);
  auto n3 = gate_and(n2, a[2]);
  auto n4 = gate_and(n3, a[3]);
  auto n5 = gate_and(n4, a[4]);
  auto n6 = gate_and(n5, a[5]);
  y[0] = gate_not(a[0]);
  y[1] = gate_xor(a[0], a[1]);
  y[2] = gate_xor(n2, a[2]);
  y[3] = gate_xor(n3, a[3]);
  y[4] = gate_xor(n4, a[4]);
  y[5] = gate_xor(n5, a[5]);
  y[6] = gate_xor(n6, a[6]);
  auto n8 = gate_not(a[7]);
  auto n7 = gate_nand(n6, a[6]);
  y[7] = gate_xor(n8, n7);
}
template<> void CtfheUint<8>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n29 = gate_xnor(b[7], a[7]);
  auto n35 = gate_xnor(a[1], b[1]);
  auto n37 = gate_xnor(b[4], a[4]);
  auto n38 = gate_xnor(b[5], a[5]);
  auto n39 = gate_xnor(b[6], a[6]);
  auto n40 = gate_not(b[2]);
  auto n45 = gate_xor(n40, a[2]);
  auto n41 = gate_not(a[3]);
  auto n44 = gate_xor(n41, b[3]);
  auto n42 = gate_not(a[0]);
  auto n43 = gate_xor(n42, b[0]);
  auto n31 = gate_and(n44, n43);
  auto n30 = gate_and(n31, n35);
  auto n36 = gate_and(n45, n30);
  auto n33 = gate_and(n36, n38);
  auto n32 = gate_and(n33, n37);
  auto n34 = gate_and(n32, n39);
  y[0] = gate_nand(n34, n29);
}
template<> void CtfheUint<8>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n29 = gate_not(a[1]);
  auto n28 = gate_not(a[3]);
  auto n25 = gate_and(n29, n28);
  auto n31 = gate_not(a[2]);
  auto n30 = gate_not(a[0]);
  auto n24 = gate_and(n31, n30);
  auto n22 = gate_and(n25, n24);
  auto n33 = gate_not(a[5]);
  auto n32 = gate_not(a[7]);
  auto n27 = gate_and(n33, n32);
  auto n35 = gate_not(a[6]);
  auto n34 = gate_not(a[4]);
  auto n26 = gate_and(n35, n34);
  auto n23 = gate_and(n27, n26);
  auto n36 = gate_nand(n22, n23);
  y[7] = gate_mux(c[7], b[7], n36);
  y[0] = gate_mux(c[0], b[0], n36);
  y[1] = gate_mux(c[1], b[1], n36);
  y[2] = gate_mux(c[2], b[2], n36);
  y[3] = gate_mux(c[3], b[3], n36);
  y[4] = gate_mux(c[4], b[4], n36);
  y[5] = gate_mux(c[5], b[5], n36);
  y[6] = gate_mux(c[6], b[6], n36);
}
template<> void CtfheUint<8>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n39 = gate_not(a[7]);
  auto n74 = gate_nand(n39, b[7]);
  auto n72 = gate_xor(n39, b[7]);
  auto n40 = gate_not(a[5]);
  auto n65 = gate_nand(n40, b[5]);
  auto n63 = gate_xor(n40, b[5]);
  auto n41 = gate_not(a[3]);
  auto n56 = gate_nand(n41, b[3]);
  auto n54 = gate_xor(n41, b[3]);
  auto n42 = gate_not(a[2]);
  auto n52 = gate_nand(n42, b[2]);
  auto n50 = gate_xor(n42, b[2]);
  auto n43 = gate_not(a[1]);
  auto n48 = gate_nand(n43, b[1]);
  auto n46 = gate_xor(n43, b[1]);
  auto n44 = gate_not(b[0]);
  auto n45 = gate_nand(a[0], n44);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n55 = gate_nand(n54, n53);
  auto n57 = gate_nand(n56, n55);
  auto n61 = gate_nand(n57, b[4]);
  auto n59 = gate_xor(n57, b[4]);
  auto n58 = gate_not(a[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n64 = gate_nand(n63, n62);
  auto n66 = gate_nand(n65, n64);
  auto n70 = gate_nand(n66, b[6]);
  auto n68 = gate_xor(n66, b[6]);
  auto n67 = gate_not(a[6]);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n73 = gate_nand(n72, n71);
  y[0] = gate_nand(n74, n73);
}
template<> void CtfheUint<8>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n39 = gate_not(b[7]);
  auto n74 = gate_nand(n39, a[7]);
  auto n72 = gate_xor(n39, a[7]);
  auto n40 = gate_not(a[5]);
  auto n65 = gate_nand(n40, b[5]);
  auto n63 = gate_xor(n40, b[5]);
  auto n41 = gate_not(a[3]);
  auto n56 = gate_nand(n41, b[3]);
  auto n54 = gate_xor(n41, b[3]);
  auto n42 = gate_not(a[2]);
  auto n52 = gate_nand(n42, b[2]);
  auto n50 = gate_xor(n42, b[2]);
  auto n43 = gate_not(a[1]);
  auto n48 = gate_nand(n43, b[1]);
  auto n46 = gate_xor(n43, b[1]);
  auto n44 = gate_not(b[0]);
  auto n45 = gate_nand(a[0], n44);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n55 = gate_nand(n54, n53);
  auto n57 = gate_nand(n56, n55);
  auto n61 = gate_nand(n57, b[4]);
  auto n59 = gate_xor(n57, b[4]);
  auto n58 = gate_not(a[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n64 = gate_nand(n63, n62);
  auto n66 = gate_nand(n65, n64);
  auto n70 = gate_nand(n66, b[6]);
  auto n68 = gate_xor(n66, b[6]);
  auto n67 = gate_not(a[6]);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n73 = gate_nand(n72, n71);
  y[0] = gate_nand(n74, n73);
}
template<> void CtfheUint<8>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n58 = gate_not(b[1]);
  auto n57 = gate_not(b[3]);
  auto n50 = gate_and(n58, n57);
  auto n60 = gate_not(b[2]);
  auto n59 = gate_not(b[0]);
  auto n49 = gate_and(n60, n59);
  auto n45 = gate_and(n50, n49);
  auto n62 = gate_not(b[5]);
  auto n61 = gate_not(b[7]);
  auto n52 = gate_and(n62, n61);
  auto n64 = gate_not(b[6]);
  auto n63 = gate_not(b[4]);
  auto n51 = gate_and(n64, n63);
  auto n46 = gate_and(n52, n51);
  auto n74 = gate_nand(n45, n46);
  auto n66 = gate_not(a[1]);
  auto n65 = gate_not(a[3]);
  auto n54 = gate_and(n66, n65);
  auto n68 = gate_not(a[2]);
  auto n67 = gate_not(a[0]);
  auto n53 = gate_and(n68, n67);
  auto n47 = gate_and(n54, n53);
  auto n70 = gate_not(a[5]);
  auto n69 = gate_not(a[7]);
  auto n56 = gate_and(n70, n69);
  auto n72 = gate_not(a[6]);
  auto n71 = gate_not(a[4]);
  auto n55 = gate_and(n72, n71);
  auto n48 = gate_and(n56, n55);
  auto n73 = gate_nand(n47, n48);
  y[0] = gate_and(n74, n73);
}
template<> void CtfheUint<8>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n31 = gate_not(a[0]);
  auto n36 = gate_not(a[4]);
  auto n30 = gate_not(a[1]);
  auto n26 = gate_and(n31, n30);
  auto n33 = gate_not(a[3]);
  auto n32 = gate_not(a[6]);
  auto n28 = gate_and(n33, n32);
  auto n35 = gate_not(a[2]);
  auto n34 = gate_not(a[5]);
  auto n27 = gate_and(n35, n34);
  auto n24 = gate_and(n28, n27);
  auto n37 = gate_not(a[7]);
  auto n29 = gate_and(n37, n36);
  auto n25 = gate_and(n24, n29);
  y[0] = gate_and(n26, n25);
}
template<> void CtfheUint<8>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n60 = gate_not(a[5]);
  auto n59 = gate_not(a[7]);
  auto n58 = gate_and(n60, n59);
  auto n62 = gate_not(a[6]);
  auto n61 = gate_not(a[4]);
  auto n57 = gate_and(n62, n61);
  auto n50 = gate_and(n58, n57);
  auto n64 = gate_not(b[5]);
  auto n63 = gate_not(b[7]);
  auto n54 = gate_and(n64, n63);
  auto n66 = gate_not(b[6]);
  auto n65 = gate_not(b[4]);
  auto n53 = gate_and(n66, n65);
  auto n48 = gate_and(n54, n53);
  auto n46 = gate_and(n50, n48);
  auto n68 = gate_not(b[1]);
  auto n67 = gate_not(b[3]);
  auto n52 = gate_and(n68, n67);
  auto n70 = gate_not(b[2]);
  auto n69 = gate_not(b[0]);
  auto n51 = gate_and(n70, n69);
  auto n47 = gate_and(n52, n51);
  auto n72 = gate_not(a[1]);
  auto n71 = gate_not(a[3]);
  auto n56 = gate_and(n72, n71);
  auto n74 = gate_not(a[2]);
  auto n73 = gate_not(a[0]);
  auto n55 = gate_and(n74, n73);
  auto n49 = gate_and(n56, n55);
  auto n45 = gate_and(n47, n49);
  y[0] = gate_nand(n46, n45);
}
template<> void CtfheUint<8>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n41 = gate_not(a[6]);
  auto n70 = gate_nand(n41, b[6]);
  auto n68 = gate_xor(n41, b[6]);
  auto n42 = gate_not(b[1]);
  auto n47 = gate_nand(n42, a[1]);
  auto n45 = gate_xor(n42, a[1]);
  auto n43 = gate_not(a[0]);
  auto n44 = gate_nand(b[0], n43);
  auto n46 = gate_nand(n45, n44);
  auto n48 = gate_nand(n47, n46);
  auto n52 = gate_nand(n48, a[2]);
  auto n50 = gate_xor(n48, a[2]);
  auto n49 = gate_not(b[2]);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n57 = gate_nand(n53, a[3]);
  auto n55 = gate_xor(n53, a[3]);
  auto n54 = gate_not(b[3]);
  auto n56 = gate_nand(n55, n54);
  auto n40 = gate_and(n57, n56);
  auto n61 = gate_nand(n40, b[4]);
  auto n59 = gate_xor(n40, b[4]);
  auto n58 = gate_not(a[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n66 = gate_nand(n62, b[5]);
  auto n64 = gate_xor(n62, b[5]);
  auto n63 = gate_not(a[5]);
  auto n65 = gate_nand(n64, n63);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n75 = gate_nand(n71, b[7]);
  auto n73 = gate_xor(n71, b[7]);
  auto n72 = gate_not(a[7]);
  auto n74 = gate_nand(n73, n72);
  y[0] = gate_nand(n75, n74);
}
template<> void CtfheUint<8>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n41 = gate_not(a[6]);
  auto n70 = gate_nand(n41, b[6]);
  auto n68 = gate_xor(n41, b[6]);
  auto n42 = gate_not(b[1]);
  auto n47 = gate_nand(n42, a[1]);
  auto n45 = gate_xor(n42, a[1]);
  auto n43 = gate_not(a[0]);
  auto n44 = gate_nand(b[0], n43);
  auto n46 = gate_nand(n45, n44);
  auto n48 = gate_nand(n47, n46);
  auto n52 = gate_nand(n48, a[2]);
  auto n50 = gate_xor(n48, a[2]);
  auto n49 = gate_not(b[2]);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n57 = gate_nand(n53, a[3]);
  auto n55 = gate_xor(n53, a[3]);
  auto n54 = gate_not(b[3]);
  auto n56 = gate_nand(n55, n54);
  auto n40 = gate_and(n57, n56);
  auto n61 = gate_nand(n40, b[4]);
  auto n59 = gate_xor(n40, b[4]);
  auto n58 = gate_not(a[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n66 = gate_nand(n62, b[5]);
  auto n64 = gate_xor(n62, b[5]);
  auto n63 = gate_not(a[5]);
  auto n65 = gate_nand(n64, n63);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n75 = gate_nand(n71, a[7]);
  auto n73 = gate_xor(n71, a[7]);
  auto n72 = gate_not(b[7]);
  auto n74 = gate_nand(n73, n72);
  y[0] = gate_nand(n75, n74);
}
template<> void CtfheUint<8>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n163 = gate_not(b[7]);
  auto n168 = gate_not(b[6]);
  auto n8 = gate_and(n163, n168);
  auto n173 = gate_not(b[5]);
  auto n5 = gate_and(n8, n173);
  auto n178 = gate_not(b[4]);
  auto n4 = gate_and(n5, n178);
  auto n183 = gate_not(b[3]);
  auto n3 = gate_and(n4, n183);
  auto n188 = gate_not(b[2]);
  auto n2 = gate_and(n3, n188);
  auto n191 = gate_not(b[1]);
  auto n6 = gate_and(n2, n191);
  auto n21 = gate_nand(b[0], n6);
  auto n17 = gate_and(a[7], n21);
  auto n22 = gate_mux(a[7], b[0], n191);
  auto n16 = gate_and(n2, n22);
  auto n23 = gate_not(a[6]);
  auto n24 = gate_nand(b[0], n23);
  auto n25 = gate_nand(n16, n24);
  auto n1 = gate_and(n17, n25);
  auto n39 = gate_nand(a[6], n25);
  auto n26 = gate_not(n39);
  auto n29 = gate_nand(n26, n191);
  auto n31 = gate_xor(n191, n39);
  auto n27 = gate_not(n31);
  auto n42 = gate_not(a[5]);
  auto n32 = gate_nand(b[0], n42);
  auto n28 = gate_nand(n27, n32);
  auto n33 = gate_nand(n29, n28);
  auto n34 = gate_xor(n33, n188);
  auto n30 = gate_nand(n3, n34);
  auto n7 = gate_and(n1, n30);
  auto n38 = gate_nand(n32, n31);
  auto n36 = gate_nand(n33, n188);
  auto n35 = gate_nand(n34, n1);
  auto n37 = gate_nand(n36, n35);
  auto n9 = gate_and(n3, n37);
  auto n40 = gate_mux(n39, n38, n9);
  auto n59 = gate_not(n40);
  auto n48 = gate_nand(n188, n59);
  auto n46 = gate_xor(b[2], n40);
  auto n41 = gate_nand(n9, b[0]);
  auto n64 = gate_xor(n42, n41);
  auto n45 = gate_nand(n191, n64);
  auto n43 = gate_xor(n191, n64);
  auto n67 = gate_not(a[4]);
  auto n61 = gate_nand(b[0], n67);
  auto n44 = gate_nand(n43, n61);
  auto n56 = gate_nand(n45, n44);
  auto n47 = gate_nand(n46, n56);
  auto n51 = gate_nand(n48, n47);
  auto n49 = gate_xor(n183, n51);
  auto n50 = gate_nand(n4, n49);
  auto n20 = gate_and(n7, n50);
  auto n52 = gate_xor(n183, n7);
  auto n54 = gate_nand(n52, n51);
  auto n53 = gate_nand(n7, n183);
  auto n55 = gate_nand(n54, n53);
  auto n19 = gate_and(n4, n55);
  auto n57 = gate_xor(n56, n188);
  auto n58 = gate_nand(n19, n57);
  auto n87 = gate_xor(n59, n58);
  auto n60 = gate_not(n87);
  auto n76 = gate_nand(n60, n183);
  auto n74 = gate_xor(b[3], n87);
  auto n62 = gate_xor(n61, n191);
  auto n63 = gate_nand(n19, n62);
  auto n91 = gate_xor(n64, n63);
  auto n65 = gate_not(n91);
  auto n73 = gate_nand(n65, n188);
  auto n71 = gate_xor(b[2], n91);
  auto n66 = gate_nand(n19, b[0]);
  auto n95 = gate_xor(n67, n66);
  auto n70 = gate_nand(n191, n95);
  auto n68 = gate_xor(n191, n95);
  auto n98 = gate_not(a[3]);
  auto n92 = gate_nand(b[0], n98);
  auto n69 = gate_nand(n68, n92);
  auto n88 = gate_nand(n70, n69);
  auto n72 = gate_nand(n71, n88);
  auto n84 = gate_nand(n73, n72);
  auto n75 = gate_nand(n74, n84);
  auto n79 = gate_nand(n76, n75);
  auto n77 = gate_xor(n178, n79);
  auto n78 = gate_nand(n5, n77);
  auto n10 = gate_and(n20, n78);
  auto n80 = gate_xor(n178, n20);
  auto n82 = gate_nand(n80, n79);
  auto n81 = gate_nand(n20, n178);
  auto n83 = gate_nand(n82, n81);
  auto n18 = gate_and(n5, n83);
  auto n85 = gate_xor(n183, n84);
  auto n86 = gate_nand(n18, n85);
  auto n121 = gate_xor(n87, n86);
  auto n110 = gate_nand(n121, n178);
  auto n108 = gate_xor(n178, n121);
  auto n89 = gate_xor(n188, n88);
  auto n90 = gate_nand(n18, n89);
  auto n126 = gate_xor(n91, n90);
  auto n107 = gate_nand(n126, n183);
  auto n105 = gate_xor(n183, n126);
  auto n93 = gate_xor(n92, n191);
  auto n94 = gate_nand(n18, n93);
  auto n131 = gate_xor(n95, n94);
  auto n96 = gate_not(n131);
  auto n104 = gate_nand(n96, n188);
  auto n102 = gate_xor(b[2], n131);
  auto n97 = gate_nand(n18, b[0]);
  auto n135 = gate_xor(n98, n97);
  auto n101 = gate_nand(n191, n135);
  auto n99 = gate_xor(n191, n135);
  auto n138 = gate_not(a[2]);
  auto n132 = gate_nand(b[0], n138);
  auto n100 = gate_nand(n99, n132);
  auto n128 = gate_nand(n101, n100);
  auto n103 = gate_nand(n102, n128);
  auto n123 = gate_nand(n104, n103);
  auto n106 = gate_nand(n105, n123);
  auto n118 = gate_nand(n107, n106);
  auto n109 = gate_nand(n108, n118);
  auto n113 = gate_nand(n110, n109);
  auto n111 = gate_xor(n173, n113);
  auto n112 = gate_nand(n8, n111);
  auto n156 = gate_nand(n10, n112);
  auto n159 = gate_not(n156);
  auto n114 = gate_xor(n173, n10);
  auto n116 = gate_nand(n114, n113);
  auto n115 = gate_nand(n10, n173);
  auto n117 = gate_nand(n116, n115);
  auto n15 = gate_and(n8, n117);
  auto n119 = gate_xor(n178, n118);
  auto n120 = gate_nand(n15, n119);
  auto n167 = gate_xor(n121, n120);
  auto n122 = gate_not(n167);
  auto n153 = gate_nand(n122, n173);
  auto n151 = gate_xor(b[5], n167);
  auto n124 = gate_xor(n183, n123);
  auto n125 = gate_nand(n15, n124);
  auto n172 = gate_xor(n126, n125);
  auto n127 = gate_not(n172);
  auto n150 = gate_nand(n127, n178);
  auto n148 = gate_xor(b[4], n172);
  auto n129 = gate_xor(n188, n128);
  auto n130 = gate_nand(n15, n129);
  auto n177 = gate_xor(n131, n130);
  auto n147 = gate_nand(n177, n183);
  auto n145 = gate_xor(n183, n177);
  auto n133 = gate_xor(n132, n191);
  auto n134 = gate_nand(n15, n133);
  auto n182 = gate_xor(n135, n134);
  auto n136 = gate_not(n182);
  auto n144 = gate_nand(n136, n188);
  auto n142 = gate_xor(b[2], n182);
  auto n137 = gate_nand(n15, b[0]);
  auto n187 = gate_xor(n138, n137);
  auto n141 = gate_nand(n191, n187);
  auto n139 = gate_xor(n191, n187);
  auto n190 = gate_not(a[1]);
  auto n184 = gate_nand(b[0], n190);
  auto n140 = gate_nand(n139, n184);
  auto n179 = gate_nand(n141, n140);
  auto n143 = gate_nand(n142, n179);
  auto n174 = gate_nand(n144, n143);
  auto n146 = gate_nand(n145, n174);
  auto n169 = gate_nand(n147, n146);
  auto n149 = gate_nand(n148, n169);
  auto n164 = gate_nand(n150, n149);
  auto n152 = gate_nand(n151, n164);
  auto n157 = gate_nand(n153, n152);
  auto n154 = gate_xor(n168, n157);
  auto n155 = gate_nand(n154, n163);
  auto n13 = gate_and(n159, n155);
  auto n207 = gate_nand(n13, n163);
  auto n204 = gate_nand(b[7], n156);
  auto n158 = gate_xor(n168, n159);
  auto n161 = gate_nand(n158, n157);
  auto n160 = gate_nand(n159, n168);
  auto n162 = gate_nand(n161, n160);
  auto n12 = gate_and(n163, n162);
  auto n165 = gate_xor(n173, n164);
  auto n166 = gate_nand(n12, n165);
  auto n215 = gate_xor(n167, n166);
  auto n203 = gate_nand(n215, n168);
  auto n212 = gate_xor(n168, n215);
  auto n170 = gate_xor(n178, n169);
  auto n171 = gate_nand(n12, n170);
  auto n219 = gate_xor(n172, n171);
  auto n201 = gate_nand(n219, n173);
  auto n216 = gate_xor(n173, n219);
  auto n175 = gate_xor(n183, n174);
  auto n176 = gate_nand(n12, n175);
  auto n14 = gate_xnor(n177, n176);
  auto n199 = gate_nand(n14, n178);
  auto n220 = gate_xor(n178, n14);
  auto n180 = gate_xor(n188, n179);
  auto n181 = gate_nand(n12, n180);
  auto n226 = gate_xor(n182, n181);
  auto n197 = gate_nand(n226, n183);
  auto n223 = gate_xor(n183, n226);
  auto n185 = gate_xor(n184, n191);
  auto n186 = gate_nand(n12, n185);
  auto n11 = gate_xnor(n187, n186);
  auto n195 = gate_nand(n11, n188);
  auto n227 = gate_xor(n188, n11);
  auto n189 = gate_nand(n12, b[0]);
  auto n233 = gate_xor(n190, n189);
  auto n193 = gate_nand(n191, n233);
  auto n231 = gate_xor(n191, n233);
  auto n236 = gate_not(a[0]);
  auto n230 = gate_nand(b[0], n236);
  auto n192 = gate_nand(n231, n230);
  auto n228 = gate_nand(n193, n192);
  auto n194 = gate_nand(n227, n228);
  auto n224 = gate_nand(n195, n194);
  auto n196 = gate_nand(n223, n224);
  auto n221 = gate_nand(n197, n196);
  auto n198 = gate_nand(n220, n221);
  auto n217 = gate_nand(n199, n198);
  auto n200 = gate_nand(n216, n217);
  auto n213 = gate_nand(n201, n200);
  auto n202 = gate_nand(n212, n213);
  auto n208 = gate_nand(n203, n202);
  auto n205 = gate_nand(n204, n208);
  auto n234 = gate_nand(n207, n205);
  auto n206 = gate_not(n234);
  auto n211 = gate_nand(n13, n206);
  auto n209 = gate_not(n207);
  auto n210 = gate_nand(n209, n208);
  y[7] = gate_nand(n211, n210);
  auto n214 = gate_xor(n213, n212);
  y[6] = gate_mux(n215, n214, n234);
  auto n218 = gate_xor(n217, n216);
  y[5] = gate_mux(n219, n218, n234);
  auto n222 = gate_xor(n221, n220);
  y[4] = gate_mux(n14, n222, n234);
  auto n225 = gate_xor(n224, n223);
  y[3] = gate_mux(n226, n225, n234);
  auto n229 = gate_xor(n228, n227);
  y[2] = gate_mux(n11, n229, n234);
  auto n232 = gate_xor(n231, n230);
  y[1] = gate_mux(n233, n232, n234);
  auto n235 = gate_nand(n234, b[0]);
  y[0] = gate_xor(n236, n235);
}
template<> void CtfheUint<8>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n25 = gate_not(a[1]);
  auto n255 = gate_not(a[0]);
  auto n27 = gate_nand(n25, n255);
  auto n26 = gate_nand(a[7], n27);
  auto n151 = gate_xor(a[2], n26);
  auto n201 = gate_not(b[7]);
  auto n259 = gate_xnor(n201, b[1]);
  auto n3 = gate_not(n259);
  auto n210 = gate_xor(b[6], n201);
  auto n275 = gate_xor(b[5], n201);
  auto n24 = gate_and(n275, n210);
  auto n216 = gate_not(n275);
  auto n29 = gate_not(n27);
  auto n28 = gate_not(a[2]);
  auto n89 = gate_nand(n29, n28);
  auto n31 = gate_not(n89);
  auto n30 = gate_not(a[3]);
  auto n67 = gate_nand(n31, n30);
  auto n33 = gate_not(n67);
  auto n32 = gate_not(a[4]);
  auto n35 = gate_nand(n33, n32);
  auto n34 = gate_nand(a[7], n35);
  auto n61 = gate_xor(a[5], n34);
  auto n269 = gate_xor(b[4], n201);
  auto n1 = gate_not(n269);
  auto n2 = gate_not(n1);
  auto n16 = gate_and(n24, n2);
  auto n228 = gate_xor(b[7], b[3]);
  auto n263 = gate_not(n228);
  auto n14 = gate_and(n16, n263);
  auto n231 = gate_xor(b[7], b[2]);
  auto n229 = gate_not(n231);
  auto n13 = gate_and(n14, n229);
  auto n15 = gate_and(n13, n3);
  auto n37 = gate_not(n35);
  auto n36 = gate_not(a[5]);
  auto n41 = gate_nand(n37, n36);
  auto n38 = gate_nand(a[7], n41);
  auto n43 = gate_xor(a[6], n38);
  auto n48 = gate_not(n43);
  auto n40 = gate_not(a[6]);
  auto n39 = gate_nand(b[0], n15);
  auto n18 = gate_and(n40, n39);
  auto n42 = gate_not(n41);
  auto n4 = gate_and(n42, a[7]);
  auto n17 = gate_and(n18, n4);
  auto n45 = gate_xor(n17, n3);
  auto n44 = gate_nand(n43, b[0]);
  auto n5 = gate_and(n13, n44);
  auto n55 = gate_nand(n45, n5);
  auto n23 = gate_and(n17, n55);
  auto n46 = gate_not(n55);
  auto n47 = gate_nand(n46, b[0]);
  auto n65 = gate_nand(n48, n47);
  auto n49 = gate_not(n65);
  auto n53 = gate_nand(n49, n3);
  auto n62 = gate_xor(n3, n65);
  auto n51 = gate_not(n62);
  auto n50 = gate_mux(b[7], n61, b[0]);
  auto n63 = gate_not(n50);
  auto n52 = gate_nand(n51, n63);
  auto n54 = gate_nand(n53, n52);
  auto n57 = gate_nand(n229, n54);
  auto n76 = gate_xor(n229, n54);
  auto n56 = gate_nand(n76, n23);
  auto n58 = gate_nand(n57, n56);
  auto n64 = gate_nand(n14, n58);
  auto n59 = gate_not(n64);
  auto n60 = gate_nand(n59, b[0]);
  auto n84 = gate_xor(n61, n60);
  auto n66 = gate_nand(n63, n62);
  auto n102 = gate_mux(n66, n65, n64);
  auto n98 = gate_not(n102);
  auto n75 = gate_nand(n229, n98);
  auto n73 = gate_xor(n229, n98);
  auto n72 = gate_nand(n84, n3);
  auto n70 = gate_xor(n84, n3);
  auto n68 = gate_nand(a[7], n67);
  auto n88 = gate_xor(a[4], n68);
  auto n69 = gate_mux(b[7], n88, b[0]);
  auto n81 = gate_not(n69);
  auto n71 = gate_nand(n70, n81);
  auto n100 = gate_nand(n72, n71);
  auto n74 = gate_nand(n73, n100);
  auto n110 = gate_nand(n75, n74);
  auto n79 = gate_nand(n110, n263);
  auto n77 = gate_nand(n14, n76);
  auto n12 = gate_and(n23, n77);
  auto n78 = gate_nand(n12, n263);
  auto n80 = gate_nand(n79, n78);
  auto n101 = gate_nand(n80, n16);
  auto n86 = gate_not(n101);
  auto n82 = gate_xor(n3, n81);
  auto n83 = gate_nand(n86, n82);
  auto n122 = gate_xor(n84, n83);
  auto n85 = gate_not(n122);
  auto n97 = gate_nand(n85, n229);
  auto n95 = gate_xor(n229, n85);
  auto n87 = gate_nand(n86, b[0]);
  auto n126 = gate_xor(n88, n87);
  auto n94 = gate_nand(n126, n3);
  auto n92 = gate_xor(n126, n3);
  auto n90 = gate_nand(a[7], n89);
  auto n130 = gate_xor(a[3], n90);
  auto n91 = gate_mux(b[7], n130, b[0]);
  auto n123 = gate_not(n91);
  auto n93 = gate_nand(n92, n123);
  auto n119 = gate_nand(n94, n93);
  auto n96 = gate_nand(n95, n119);
  auto n106 = gate_nand(n97, n96);
  auto n99 = gate_xor(n231, n98);
  auto n103 = gate_nand(n100, n99);
  auto n116 = gate_mux(n103, n102, n101);
  auto n105 = gate_not(n116);
  auto n104 = gate_xor(n228, n105);
  auto n117 = gate_nand(n106, n104);
  auto n109 = gate_nand(n105, n263);
  auto n107 = gate_xor(n105, n263);
  auto n108 = gate_nand(n107, n106);
  auto n144 = gate_nand(n109, n108);
  auto n114 = gate_nand(n269, n144);
  auto n111 = gate_xor(n263, n110);
  auto n112 = gate_nand(n16, n111);
  auto n7 = gate_and(n12, n112);
  auto n113 = gate_nand(n7, n2);
  auto n115 = gate_nand(n114, n113);
  auto n118 = gate_nand(n24, n115);
  auto n159 = gate_mux(n117, n116, n118);
  auto n155 = gate_not(n159);
  auto n143 = gate_nand(n155, n2);
  auto n141 = gate_xor(n155, n2);
  auto n128 = gate_not(n118);
  auto n120 = gate_xor(n229, n119);
  auto n121 = gate_nand(n128, n120);
  auto n161 = gate_xor(n122, n121);
  auto n140 = gate_nand(n161, n263);
  auto n138 = gate_xor(n263, n161);
  auto n124 = gate_xor(n3, n123);
  auto n125 = gate_nand(n128, n124);
  auto n169 = gate_xor(n126, n125);
  auto n127 = gate_not(n169);
  auto n137 = gate_nand(n127, n229);
  auto n135 = gate_xor(n229, n127);
  auto n129 = gate_nand(n128, b[0]);
  auto n170 = gate_xor(n130, n129);
  auto n134 = gate_nand(n170, n3);
  auto n132 = gate_xor(n170, n3);
  auto n131 = gate_mux(b[7], n151, b[0]);
  auto n171 = gate_not(n131);
  auto n133 = gate_nand(n132, n171);
  auto n166 = gate_nand(n134, n133);
  auto n136 = gate_nand(n135, n166);
  auto n162 = gate_nand(n137, n136);
  auto n139 = gate_nand(n138, n162);
  auto n157 = gate_nand(n140, n139);
  auto n142 = gate_nand(n141, n157);
  auto n152 = gate_nand(n143, n142);
  auto n148 = gate_nand(n275, n152);
  auto n145 = gate_xor(n2, n144);
  auto n146 = gate_nand(n24, n145);
  auto n20 = gate_and(n7, n146);
  auto n147 = gate_nand(n20, n275);
  auto n149 = gate_nand(n148, n147);
  auto n158 = gate_nand(n210, n149);
  auto n173 = gate_not(n158);
  auto n150 = gate_nand(n173, b[0]);
  auto n198 = gate_xor(n151, n150);
  auto n153 = gate_xor(n275, n152);
  auto n154 = gate_nand(n153, n210);
  auto n6 = gate_and(n20, n154);
  auto n194 = gate_nand(n6, n210);
  auto n156 = gate_xor(n1, n155);
  auto n160 = gate_nand(n157, n156);
  auto n209 = gate_mux(n160, n159, n158);
  auto n205 = gate_not(n209);
  auto n192 = gate_nand(n205, n275);
  auto n190 = gate_xor(n205, n275);
  auto n165 = gate_not(n161);
  auto n163 = gate_xor(n263, n162);
  auto n164 = gate_nand(n173, n163);
  auto n214 = gate_xor(n165, n164);
  auto n189 = gate_nand(n214, n2);
  auto n187 = gate_xor(n2, n214);
  auto n167 = gate_xor(n229, n166);
  auto n168 = gate_nand(n173, n167);
  auto n220 = gate_xor(n169, n168);
  auto n186 = gate_nand(n220, n263);
  auto n184 = gate_xor(n263, n220);
  auto n175 = gate_not(n170);
  auto n172 = gate_xor(n3, n171);
  auto n174 = gate_nand(n173, n172);
  auto n226 = gate_xor(n175, n174);
  auto n183 = gate_nand(n226, n229);
  auto n181 = gate_xor(n229, n226);
  auto n180 = gate_nand(n198, n3);
  auto n178 = gate_xor(n198, n3);
  auto n176 = gate_nand(a[7], a[0]);
  auto n200 = gate_xor(a[1], n176);
  auto n177 = gate_mux(b[7], n200, b[0]);
  auto n195 = gate_not(n177);
  auto n179 = gate_nand(n178, n195);
  auto n222 = gate_nand(n180, n179);
  auto n182 = gate_nand(n181, n222);
  auto n217 = gate_nand(n183, n182);
  auto n185 = gate_nand(n184, n217);
  auto n211 = gate_nand(n186, n185);
  auto n188 = gate_nand(n187, n211);
  auto n207 = gate_nand(n189, n188);
  auto n191 = gate_nand(n190, n207);
  auto n248 = gate_nand(n192, n191);
  auto n281 = gate_not(n210);
  auto n193 = gate_nand(n248, n210);
  auto n223 = gate_nand(n194, n193);
  auto n196 = gate_xor(n3, n195);
  auto n197 = gate_nand(n223, n196);
  auto n253 = gate_xor(n198, n197);
  auto n199 = gate_nand(b[0], n223);
  auto n262 = gate_xor(n200, n199);
  auto n204 = gate_nand(n262, n3);
  auto n202 = gate_xor(n262, n3);
  auto n258 = gate_mux(n201, a[0], b[0]);
  auto n203 = gate_nand(n202, n258);
  auto n232 = gate_nand(n204, n203);
  auto n251 = gate_xor(n232, n229);
  auto n206 = gate_xor(n205, n216);
  auto n208 = gate_nand(n207, n206);
  auto n287 = gate_mux(n209, n208, n223);
  auto n282 = gate_not(n287);
  auto n247 = gate_nand(n282, n210);
  auto n245 = gate_xor(n282, n210);
  auto n212 = gate_xor(n211, n2);
  auto n213 = gate_nand(n212, n223);
  auto n279 = gate_xor(n214, n213);
  auto n215 = gate_not(n279);
  auto n244 = gate_nand(n215, n275);
  auto n242 = gate_xor(n216, n279);
  auto n218 = gate_xor(n217, n263);
  auto n219 = gate_nand(n218, n223);
  auto n273 = gate_xor(n220, n219);
  auto n221 = gate_not(n273);
  auto n241 = gate_nand(n221, n2);
  auto n239 = gate_xor(n1, n273);
  auto n224 = gate_xor(n222, n229);
  auto n225 = gate_nand(n224, n223);
  auto n267 = gate_xor(n226, n225);
  auto n227 = gate_not(n267);
  auto n238 = gate_nand(n227, n263);
  auto n236 = gate_xor(n228, n267);
  auto n230 = gate_not(n253);
  auto n235 = gate_nand(n230, n229);
  auto n233 = gate_xor(n231, n253);
  auto n234 = gate_nand(n233, n232);
  auto n264 = gate_nand(n235, n234);
  auto n237 = gate_nand(n236, n264);
  auto n270 = gate_nand(n238, n237);
  auto n240 = gate_nand(n239, n270);
  auto n276 = gate_nand(n241, n240);
  auto n243 = gate_nand(n242, n276);
  auto n284 = gate_nand(n244, n243);
  auto n246 = gate_nand(n245, n284);
  auto n290 = gate_nand(n247, n246);
  auto n250 = gate_not(n290);
  auto n249 = gate_mux(n281, n210, n248);
  auto n289 = gate_nand(n6, n249);
  auto n285 = gate_nand(n250, n289);
  auto n252 = gate_nand(n251, n285);
  auto n254 = gate_xor(n253, n252);
  auto n298 = gate_xor(a[7], n254);
  auto n257 = gate_xor(a[7], n255);
  auto n256 = gate_nand(b[0], n285);
  auto n302 = gate_xor(n257, n256);
  y[0] = gate_xor(a[7], n302);
  auto n10 = gate_and(a[7], n302);
  auto n260 = gate_xor(n3, n258);
  auto n261 = gate_nand(n285, n260);
  auto n301 = gate_xor(n262, n261);
  auto n22 = gate_and(n10, n301);
  auto n11 = gate_and(n298, n22);
  auto n265 = gate_xor(n264, n263);
  auto n266 = gate_nand(n265, n285);
  auto n268 = gate_xor(n267, n266);
  auto n297 = gate_xor(a[7], n268);
  auto n19 = gate_and(n11, n297);
  auto n271 = gate_xor(n270, n2);
  auto n272 = gate_nand(n271, n285);
  auto n274 = gate_xor(n273, n272);
  auto n296 = gate_xor(a[7], n274);
  auto n9 = gate_and(n19, n296);
  auto n277 = gate_xor(n276, n275);
  auto n278 = gate_nand(n277, n285);
  auto n280 = gate_xor(n279, n278);
  auto n295 = gate_xor(a[7], n280);
  auto n21 = gate_and(n9, n295);
  auto n283 = gate_xor(n282, n281);
  auto n286 = gate_nand(n284, n283);
  auto n288 = gate_mux(n287, n286, n285);
  auto n8 = gate_xnor(a[7], n288);
  auto n294 = gate_nand(n21, n8);
  auto n291 = gate_not(n289);
  auto n292 = gate_nand(n291, n290);
  auto n293 = gate_nand(a[7], n292);
  y[7] = gate_xor(n294, n293);
  y[6] = gate_xor(n21, n8);
  y[5] = gate_xor(n9, n295);
  y[4] = gate_xor(n19, n296);
  y[3] = gate_xor(n11, n297);
  y[2] = gate_xor(n298, n22);
  auto n299 = gate_not(n302);
  auto n300 = gate_nand(a[7], n299);
  y[1] = gate_xor(n301, n300);
}
template<> void CtfheUint<8>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_and(b[0], a[6]);
  auto n3 = gate_and(b[1], a[4]);
  auto n4 = gate_and(b[0], a[4]);
  auto n5 = gate_and(a[2], b[1]);
  auto n7 = gate_and(b[1], a[1]);
  auto n8 = gate_and(b[0], a[1]);
  auto n9 = gate_and(b[1], a[0]);
  y[0] = gate_and(b[0], a[0]);
  y[1] = gate_xor(n8, n9);
  auto n17 = gate_nand(n8, n9);
  auto n11 = gate_not(n17);
  auto n12 = gate_nand(a[0], b[2]);
  auto n16 = gate_xor(n7, n12);
  auto n15 = gate_nand(a[2], b[0]);
  auto n18 = gate_xor(n16, n15);
  y[2] = gate_xor(n11, n18);
  auto n24 = gate_nand(a[1], b[2]);
  auto n25 = gate_nand(b[3], a[0]);
  auto n14 = gate_xor(n24, n25);
  auto n13 = gate_not(n12);
  auto n29 = gate_nand(n7, n13);
  auto n33 = gate_xor(n14, n29);
  auto n21 = gate_not(n33);
  auto n20 = gate_nand(n16, n15);
  auto n19 = gate_nand(n18, n17);
  auto n32 = gate_nand(n20, n19);
  auto n22 = gate_nand(a[3], b[0]);
  auto n31 = gate_xor(n5, n22);
  auto n34 = gate_xor(n32, n31);
  y[3] = gate_xor(n21, n34);
  auto n23 = gate_not(n22);
  auto n47 = gate_nand(n5, n23);
  auto n27 = gate_not(n24);
  auto n26 = gate_not(n25);
  auto n28 = gate_nand(n27, n26);
  auto n48 = gate_nand(n29, n28);
  auto n55 = gate_nand(a[3], b[1]);
  auto n49 = gate_xor(n4, n55);
  auto n30 = gate_xor(n48, n49);
  auto n40 = gate_xor(n47, n30);
  auto n38 = gate_not(n40);
  auto n36 = gate_nand(n32, n31);
  auto n35 = gate_nand(n34, n33);
  auto n39 = gate_nand(n36, n35);
  auto n41 = gate_not(n39);
  auto n59 = gate_nand(b[3], a[1]);
  auto n58 = gate_nand(b[4], a[0]);
  auto n61 = gate_xor(n59, n58);
  auto n60 = gate_nand(a[2], b[2]);
  auto n43 = gate_xor(n61, n60);
  auto n37 = gate_xor(n41, n43);
  y[4] = gate_xor(n38, n37);
  auto n45 = gate_nand(n39, n38);
  auto n42 = gate_nand(n41, n40);
  auto n44 = gate_nand(n43, n42);
  auto n93 = gate_nand(n45, n44);
  auto n46 = gate_not(n49);
  auto n54 = gate_nand(n46, n48);
  auto n52 = gate_not(n47);
  auto n50 = gate_not(n48);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n2 = gate_and(n54, n53);
  auto n95 = gate_xor(n93, n2);
  auto n73 = gate_nand(b[0], a[5]);
  auto n80 = gate_xor(n73, n3);
  auto n56 = gate_not(n55);
  auto n79 = gate_nand(n4, n56);
  auto n78 = gate_nand(a[3], b[2]);
  auto n81 = gate_xor(n79, n78);
  auto n70 = gate_xor(n80, n81);
  auto n85 = gate_nand(b[5], a[0]);
  auto n89 = gate_nand(b[3], a[2]);
  auto n84 = gate_nand(b[4], a[1]);
  auto n57 = gate_xor(n89, n84);
  auto n65 = gate_xor(n85, n57);
  auto n63 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n66 = gate_nand(n63, n62);
  auto n64 = gate_xor(n65, n66);
  auto n94 = gate_xor(n70, n64);
  y[5] = gate_xnor(n95, n94);
  auto n72 = gate_nand(n65, n66);
  auto n68 = gate_not(n65);
  auto n67 = gate_not(n66);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n130 = gate_nand(n72, n71);
  auto n74 = gate_not(n73);
  auto n155 = gate_nand(n74, n3);
  auto n154 = gate_nand(b[3], a[3]);
  auto n156 = gate_nand(a[2], b[4]);
  auto n75 = gate_xor(n154, n156);
  auto n132 = gate_xor(n155, n75);
  auto n118 = gate_nand(a[4], b[2]);
  auto n117 = gate_nand(a[1], b[5]);
  auto n119 = gate_nand(a[0], b[6]);
  auto n76 = gate_xor(n117, n119);
  auto n131 = gate_xor(n118, n76);
  auto n77 = gate_xor(n132, n131);
  auto n104 = gate_xor(n130, n77);
  auto n83 = gate_nand(n79, n78);
  auto n82 = gate_nand(n81, n80);
  auto n143 = gate_nand(n83, n82);
  auto n91 = gate_nand(n84, n85);
  auto n87 = gate_not(n84);
  auto n86 = gate_not(n85);
  auto n88 = gate_nand(n87, n86);
  auto n90 = gate_nand(n89, n88);
  auto n146 = gate_nand(n91, n90);
  auto n92 = gate_nand(b[1], a[5]);
  auto n145 = gate_xor(n1, n92);
  auto n144 = gate_xor(n146, n145);
  auto n100 = gate_xor(n143, n144);
  auto n97 = gate_nand(n2, n93);
  auto n96 = gate_nand(n95, n94);
  auto n99 = gate_nand(n97, n96);
  auto n102 = gate_not(n99);
  auto n98 = gate_xor(n100, n102);
  y[6] = gate_xor(n104, n98);
  auto n106 = gate_nand(n100, n99);
  auto n101 = gate_not(n100);
  auto n103 = gate_nand(n102, n101);
  auto n105 = gate_nand(n104, n103);
  auto n125 = gate_nand(n106, n105);
  auto n108 = gate_nand(a[6], b[1]);
  auto n107 = gate_nand(a[7], b[0]);
  auto n113 = gate_xor(n108, n107);
  auto n110 = gate_not(b[2]);
  auto n109 = gate_nand(b[1], n1);
  auto n111 = gate_xor(n110, n109);
  auto n112 = gate_nand(a[5], n111);
  auto n123 = gate_xor(n113, n112);
  auto n115 = gate_not(n119);
  auto n114 = gate_not(n118);
  auto n116 = gate_nand(n115, n114);
  auto n121 = gate_nand(n117, n116);
  auto n120 = gate_nand(n119, n118);
  auto n122 = gate_nand(n121, n120);
  auto n124 = gate_xor(n123, n122);
  auto n127 = gate_xor(n125, n124);
  auto n126 = gate_nand(b[6], a[1]);
  auto n138 = gate_xor(n127, n126);
  auto n129 = gate_not(n132);
  auto n128 = gate_not(n131);
  auto n136 = gate_nand(n129, n128);
  auto n134 = gate_not(n130);
  auto n133 = gate_nand(n132, n131);
  auto n135 = gate_nand(n134, n133);
  auto n137 = gate_nand(n136, n135);
  auto n164 = gate_xor(n138, n137);
  auto n140 = gate_nand(b[5], a[2]);
  auto n139 = gate_nand(b[4], a[3]);
  auto n162 = gate_xor(n140, n139);
  auto n142 = gate_nand(b[7], a[0]);
  auto n141 = gate_nand(a[4], b[3]);
  auto n150 = gate_xor(n142, n141);
  auto n148 = gate_nand(n144, n143);
  auto n147 = gate_nand(n146, n145);
  auto n149 = gate_nand(n148, n147);
  auto n160 = gate_xor(n150, n149);
  auto n152 = gate_not(n156);
  auto n151 = gate_not(n155);
  auto n153 = gate_nand(n152, n151);
  auto n158 = gate_nand(n154, n153);
  auto n157 = gate_nand(n156, n155);
  auto n159 = gate_nand(n158, n157);
  auto n161 = gate_xor(n160, n159);
  auto n163 = gate_xor(n162, n161);
  y[7] = gate_xor(n164, n163);
}
template<> void CtfheUint<8>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n14 = gate_and(a[5], a[7]);
  auto n18 = gate_and(a[2], a[0]);
  auto n19 = gate_and(a[1], a[3]);
  auto n16 = gate_and(n19, n18);
  auto n20 = gate_and(a[6], a[4]);
  auto n17 = gate_and(n14, n20);
  y[0] = gate_and(n16, n17);
}
template<> void CtfheUint<8>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n14 = gate_and(a[5], a[7]);
  auto n17 = gate_and(a[2], a[0]);
  auto n18 = gate_and(a[1], a[3]);
  auto n15 = gate_and(n18, n17);
  auto n19 = gate_and(a[6], a[4]);
  auto n16 = gate_and(n14, n19);
  y[0] = gate_nand(n15, n16);
}
template<> void CtfheUint<8>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n31 = gate_not(a[0]);
  auto n36 = gate_not(a[4]);
  auto n30 = gate_not(a[1]);
  auto n26 = gate_and(n31, n30);
  auto n33 = gate_not(a[3]);
  auto n32 = gate_not(a[6]);
  auto n28 = gate_and(n33, n32);
  auto n35 = gate_not(a[2]);
  auto n34 = gate_not(a[5]);
  auto n27 = gate_and(n35, n34);
  auto n24 = gate_and(n28, n27);
  auto n37 = gate_not(a[7]);
  auto n29 = gate_and(n37, n36);
  auto n25 = gate_and(n24, n29);
  y[0] = gate_and(n26, n25);
}
template<> void CtfheUint<8>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n28 = gate_not(a[1]);
  auto n27 = gate_not(a[3]);
  auto n24 = gate_and(n28, n27);
  auto n30 = gate_not(a[2]);
  auto n29 = gate_not(a[0]);
  auto n23 = gate_and(n30, n29);
  auto n21 = gate_and(n24, n23);
  auto n32 = gate_not(a[5]);
  auto n31 = gate_not(a[7]);
  auto n26 = gate_and(n32, n31);
  auto n34 = gate_not(a[6]);
  auto n33 = gate_not(a[4]);
  auto n25 = gate_and(n34, n33);
  auto n22 = gate_and(n26, n25);
  y[0] = gate_nand(n21, n22);
}
template<> void CtfheUint<8>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n11 = gate_xor(a[0], a[1]);
  auto n14 = gate_xor(a[7], a[6]);
  auto n10 = gate_xor(a[2], a[3]);
  auto n13 = gate_xor(n11, n10);
  auto n12 = gate_xor(a[4], a[5]);
  auto n15 = gate_xor(n13, n12);
  y[0] = gate_xnor(n15, n14);
}
template<> void CtfheUint<8>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n8 = gate_xor(a[0], a[1]);
  auto n7 = gate_xor(a[2], a[3]);
  auto n12 = gate_xor(n8, n7);
  auto n10 = gate_xor(a[4], a[5]);
  auto n9 = gate_xor(a[7], a[6]);
  auto n11 = gate_xor(n10, n9);
  y[0] = gate_xor(n12, n11);
}
template<> void CtfheUint<8>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n66 = gate_not(b[3]);
  auto n65 = gate_not(b[4]);
  auto n58 = gate_and(n66, n65);
  auto n68 = gate_not(b[5]);
  auto n67 = gate_not(b[6]);
  auto n53 = gate_and(n68, n67);
  auto n50 = gate_and(n58, n53);
  auto n69 = gate_not(b[7]);
  auto n54 = gate_and(n50, n69);
  auto n64 = gate_and(b[2], n54);
  auto n88 = gate_not(b[2]);
  auto n52 = gate_and(n54, n88);
  auto n70 = gate_mux(a[7], a[5], b[1]);
  auto n73 = gate_nand(n52, n70);
  auto n71 = gate_mux(a[6], a[4], b[1]);
  auto n72 = gate_nand(n52, n71);
  auto n76 = gate_mux(n73, n72, b[0]);
  auto n74 = gate_mux(a[3], a[2], b[0]);
  auto n106 = gate_mux(a[1], a[0], b[0]);
  auto n103 = gate_mux(n74, n106, b[1]);
  y[3] = gate_and(n52, n103);
  auto n75 = gate_nand(n64, n103);
  y[7] = gate_nand(n76, n75);
  auto n77 = gate_mux(a[6], a[5], b[0]);
  auto n99 = gate_mux(a[4], a[3], b[0]);
  auto n78 = gate_mux(n77, n99, b[1]);
  auto n81 = gate_nand(n52, n78);
  auto n98 = gate_mux(a[2], a[1], b[0]);
  auto n79 = gate_not(b[0]);
  auto n59 = gate_and(a[0], n79);
  auto n104 = gate_mux(n98, n59, b[1]);
  y[2] = gate_and(n52, n104);
  auto n80 = gate_nand(n104, n64);
  y[6] = gate_nand(n81, n80);
  auto n105 = gate_not(b[1]);
  auto n51 = gate_and(n52, n105);
  auto n55 = gate_and(n59, n105);
  y[0] = gate_and(n51, n59);
  y[1] = gate_and(n51, n106);
  auto n82 = gate_not(a[5]);
  auto n83 = gate_nand(n105, n82);
  auto n86 = gate_mux(a[1], n83, n88);
  auto n84 = gate_not(a[3]);
  auto n85 = gate_nand(b[1], n84);
  auto n94 = gate_nand(n86, n85);
  auto n87 = gate_not(a[4]);
  auto n89 = gate_nand(n87, n105);
  auto n92 = gate_mux(a[0], n89, n88);
  auto n90 = gate_not(a[2]);
  auto n91 = gate_nand(b[1], n90);
  auto n93 = gate_nand(n92, n91);
  auto n95 = gate_mux(n94, n93, b[0]);
  auto n96 = gate_not(n95);
  auto n56 = gate_and(n54, n96);
  auto n97 = gate_nand(b[2], b[1]);
  y[5] = gate_and(n56, n97);
  auto n100 = gate_mux(n99, n98, b[1]);
  auto n102 = gate_nand(n52, n100);
  auto n101 = gate_nand(n64, n55);
  y[4] = gate_nand(n102, n101);
}
template<> void CtfheUint<8>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n66 = gate_not(b[3]);
  auto n65 = gate_not(b[4]);
  auto n52 = gate_and(n66, n65);
  auto n68 = gate_not(b[5]);
  auto n67 = gate_not(b[6]);
  auto n53 = gate_and(n68, n67);
  auto n50 = gate_and(n52, n53);
  auto n69 = gate_not(b[7]);
  auto n54 = gate_and(n50, n69);
  auto n61 = gate_and(b[2], n54);
  auto n85 = gate_not(b[2]);
  auto n51 = gate_and(n54, n85);
  auto n84 = gate_not(b[1]);
  auto n58 = gate_and(n51, n84);
  auto n70 = gate_not(b[0]);
  auto n64 = gate_and(a[7], n70);
  auto n55 = gate_and(n64, n84);
  y[7] = gate_and(n58, n64);
  auto n71 = gate_mux(a[6], a[7], b[0]);
  y[6] = gate_and(n58, n71);
  auto n73 = gate_mux(a[5], a[6], b[0]);
  auto n98 = gate_mux(n73, n64, b[1]);
  y[5] = gate_and(n51, n98);
  auto n72 = gate_mux(a[4], a[5], b[0]);
  auto n104 = gate_mux(n72, n71, b[1]);
  y[4] = gate_and(n51, n104);
  auto n74 = gate_mux(a[3], a[4], b[0]);
  auto n75 = gate_mux(n74, n73, b[1]);
  auto n77 = gate_nand(n51, n75);
  auto n76 = gate_nand(n61, n55);
  y[3] = gate_nand(n77, n76);
  auto n78 = gate_not(a[2]);
  auto n79 = gate_nand(n84, n78);
  auto n82 = gate_mux(a[6], n79, n85);
  auto n80 = gate_not(a[4]);
  auto n81 = gate_nand(b[1], n80);
  auto n91 = gate_nand(n82, n81);
  auto n83 = gate_not(a[3]);
  auto n86 = gate_nand(n84, n83);
  auto n89 = gate_mux(a[7], n86, n85);
  auto n87 = gate_not(a[5]);
  auto n88 = gate_nand(b[1], n87);
  auto n90 = gate_nand(n89, n88);
  auto n92 = gate_mux(n91, n90, b[0]);
  auto n93 = gate_not(n92);
  auto n59 = gate_and(n54, n93);
  auto n94 = gate_nand(b[1], b[2]);
  y[2] = gate_and(n59, n94);
  auto n95 = gate_mux(a[1], a[3], b[1]);
  auto n102 = gate_nand(n51, n95);
  auto n96 = gate_mux(a[2], a[4], b[1]);
  auto n97 = gate_nand(n51, n96);
  auto n100 = gate_mux(n102, n97, b[0]);
  auto n99 = gate_nand(n98, n61);
  y[1] = gate_nand(n100, n99);
  auto n101 = gate_mux(a[0], a[2], b[1]);
  auto n103 = gate_nand(n51, n101);
  auto n106 = gate_mux(n103, n102, b[0]);
  auto n105 = gate_nand(n104, n61);
  y[0] = gate_nand(n106, n105);
}
template<> void CtfheUint<8>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[7] = gate_buf(a[7]);
  auto n40 = gate_not(b[1]);
  auto n67 = gate_not(b[0]);
  auto n41 = gate_nand(n40, n67);
  auto n60 = gate_mux(a[6], y[7], n41);
  auto n43 = gate_not(b[3]);
  auto n42 = gate_not(b[4]);
  auto n33 = gate_and(n43, n42);
  auto n45 = gate_not(b[5]);
  auto n44 = gate_not(b[6]);
  auto n34 = gate_and(n45, n44);
  auto n35 = gate_and(n33, n34);
  auto n46 = gate_not(b[7]);
  auto n55 = gate_nand(n35, n46);
  auto n59 = gate_not(n55);
  auto n36 = gate_and(b[2], n59);
  auto n47 = gate_not(b[2]);
  auto n52 = gate_nand(n59, n47);
  auto n71 = gate_not(n52);
  y[6] = gate_mux(y[7], n60, n71);
  auto n48 = gate_mux(a[5], a[6], b[0]);
  auto n65 = gate_mux(n48, y[7], b[1]);
  y[5] = gate_mux(y[7], n65, n71);
  auto n50 = gate_mux(a[4], a[6], b[1]);
  auto n49 = gate_mux(a[5], y[7], b[1]);
  auto n74 = gate_mux(n50, n49, b[0]);
  y[4] = gate_mux(y[7], n74, n71);
  auto n56 = gate_mux(a[3], a[5], b[1]);
  auto n51 = gate_mux(n56, n50, b[0]);
  auto n54 = gate_nand(n71, n51);
  auto n53 = gate_nand(y[7], n52);
  y[3] = gate_nand(n54, n53);
  auto n73 = gate_nand(y[7], n55);
  auto n62 = gate_mux(a[2], a[4], b[1]);
  auto n57 = gate_mux(n62, n56, b[0]);
  auto n58 = gate_nand(n71, n57);
  auto n39 = gate_and(n73, n58);
  auto n61 = gate_nand(n36, n60);
  y[2] = gate_nand(n39, n61);
  auto n69 = gate_mux(a[1], a[3], b[1]);
  auto n63 = gate_mux(n69, n62, b[0]);
  auto n64 = gate_nand(n71, n63);
  auto n38 = gate_and(n73, n64);
  auto n66 = gate_nand(n36, n65);
  y[1] = gate_nand(n38, n66);
  auto n68 = gate_mux(a[0], a[2], b[1]);
  auto n70 = gate_mux(n69, n68, n67);
  auto n72 = gate_nand(n71, n70);
  auto n37 = gate_and(n73, n72);
  auto n75 = gate_nand(n36, n74);
  y[0] = gate_nand(n37, n75);
}
template<> void CtfheUint<8>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n34 = gate_xor(b[7], a[7]);
  auto n4 = gate_not(b[1]);
  auto n6 = gate_xor(a[1], n4);
  auto n3 = gate_not(a[0]);
  auto n5 = gate_nand(b[0], n3);
  y[1] = gate_xor(n6, n5);
  auto n9 = gate_not(b[2]);
  auto n11 = gate_xor(a[2], n9);
  auto n8 = gate_nand(a[1], n4);
  auto n7 = gate_nand(n6, n5);
  auto n10 = gate_nand(n8, n7);
  y[2] = gate_xor(n11, n10);
  auto n14 = gate_not(b[3]);
  auto n16 = gate_xor(a[3], n14);
  auto n13 = gate_nand(a[2], n9);
  auto n12 = gate_nand(n11, n10);
  auto n15 = gate_nand(n13, n12);
  y[3] = gate_xor(n16, n15);
  auto n19 = gate_not(b[4]);
  auto n21 = gate_xor(a[4], n19);
  auto n18 = gate_nand(a[3], n14);
  auto n17 = gate_nand(n16, n15);
  auto n20 = gate_nand(n18, n17);
  y[4] = gate_xor(n21, n20);
  auto n24 = gate_not(b[5]);
  auto n26 = gate_xor(a[5], n24);
  auto n23 = gate_nand(a[4], n19);
  auto n22 = gate_nand(n21, n20);
  auto n25 = gate_nand(n23, n22);
  y[5] = gate_xor(n26, n25);
  auto n29 = gate_not(b[6]);
  auto n31 = gate_xor(a[6], n29);
  auto n28 = gate_nand(a[5], n24);
  auto n27 = gate_nand(n26, n25);
  auto n30 = gate_nand(n28, n27);
  y[6] = gate_xor(n31, n30);
  auto n33 = gate_nand(a[6], n29);
  auto n32 = gate_nand(n31, n30);
  auto n35 = gate_nand(n33, n32);
  y[7] = gate_xnor(n35, n34);
}
template<> void CtfheUint<8>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  auto n25 = gate_not(y[0]);
  auto n24 = gate_not(a[1]);
  auto n19 = gate_and(n25, n24);
  auto n31 = gate_not(a[2]);
  auto n20 = gate_and(n19, n31);
  auto n30 = gate_not(a[3]);
  auto n21 = gate_and(n20, n30);
  auto n29 = gate_not(a[4]);
  auto n22 = gate_and(n21, n29);
  auto n28 = gate_not(a[5]);
  auto n23 = gate_and(n22, n28);
  auto n27 = gate_not(a[6]);
  auto n26 = gate_nand(n23, n27);
  y[7] = gate_xor(a[7], n26);
  y[6] = gate_xor(n23, n27);
  y[5] = gate_xor(n22, n28);
  y[4] = gate_xor(n21, n29);
  y[3] = gate_xor(n20, n30);
  y[2] = gate_xor(n19, n31);
  y[1] = gate_xor(y[0], a[1]);
}
// === BEGIN circuit.cpp Name=Ctfhe

CircuitEvalKey * g_pek_Ctfhe = nullptr;
CircuitEvalKey * CtfheBaseBit::pek = nullptr;
const CtfheBit * CtfheBaseBit::zero = nullptr;
const CtfheBit * CtfheBaseBit::unit = nullptr;

void CtfheBaseBit::init_pek()
{
    using namespace e3;
    if ( pek ) return;

    initEvalKey
    < CircuitEvalKey, CircuitEvalKey_tfhe >
    (name(), pek, g_pek_Ctfhe);

    if ( !zero ) zero = new CtfheBit("0");
    if ( !unit ) unit = new CtfheBit("1");
}

// === END circuit.cpp Name=Ctfhe
// === BEGIN circuit.tfhe.cpp Name=Ctfhe

#include "def_tfhe0.h"

CtfheBit CtfheBit::gate_buf(const CtfheBit & a)
{
    return a;
}

CtfheBit CtfheBit::gate_not(const CtfheBit & a)
{
    CtfheBit r;
    auto y = a.nb.p->b;

    y = !y;

    r.nb.p->b = y;
    return r;
}

CtfheBit CtfheBit::gate_and(const CtfheBit & a, const CtfheBit & b)
{
    CtfheBit r;
    auto ma = a.nb.p->b;
    auto mb = b.nb.p->b;

    ma &= mb;

    r.nb.p->b = ma;
    return r;
}

CtfheBit CtfheBit::gate_or(const CtfheBit & a, const CtfheBit & b)
{
    CtfheBit r;
    auto ma = a.nb.p->b;
    auto mb = b.nb.p->b;

    ma |= mb;

    r.nb.p->b = ma;
    return r;
}

CtfheBit CtfheBit::gate_nand(const CtfheBit & a, const CtfheBit & b)
{
    CtfheBit r;
    auto ma = a.nb.p->b;
    auto mb = b.nb.p->b;

    ma = !(ma & mb);

    r.nb.p->b = ma;
    return r;
}

CtfheBit CtfheBit::gate_nor(const CtfheBit & a, const CtfheBit & b)
{
    CtfheBit r;
    auto ma = a.nb.p->b;
    auto mb = b.nb.p->b;

    ma = !(ma | mb);

    r.nb.p->b = ma;
    return r;
}

CtfheBit CtfheBit::gate_xnor(const CtfheBit & a, const CtfheBit & b)
{
    CtfheBit r;
    auto ma = a.nb.p->b;
    auto mb = b.nb.p->b;

    ma = !(ma ^ mb);

    r.nb.p->b = ma;
    return r;
}

CtfheBit CtfheBit::gate_xor(const CtfheBit & a, const CtfheBit & b)
{
    CtfheBit r;
    auto ma = a.nb.p->b;
    auto mb = b.nb.p->b;

    ma ^= mb;

    r.nb.p->b = ma;
    return r;
}

// a ? b : c
CtfheBit CtfheBit::gate_mux(const CtfheBit & a, const CtfheBit & b, const CtfheBit & c)
{
    CtfheBit r;
    auto ma = a.nb.p->b;
    auto mb = b.nb.p->b;
    auto mc = c.nb.p->b;

    ma = ma ? mb : mc;

    r.nb.p->b = ma;
    return r;
}

// === END circuit.tfhe.cpp Name=Ctfhe
template<> void PilUint<1>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(b[0], a[0]);
}
template<> void PilUint<1>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
}
template<> void PilUint<1>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void PilUint<1>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  auto n3 = gate_not(a[0]);
  y[0] = gate_nand(n4, n3);
}
template<> void PilUint<1>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  auto _a0 = gate_buf(a[0]);
  y[0] = gate_buf(_a0);
}
template<> void PilUint<1>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(b[0], a[0]);
}
template<> void PilUint<1>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
}
template<> void PilUint<1>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
}
template<> void PilUint<1>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], a[0]);
}
template<> void PilUint<1>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void PilUint<1>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_not(a[0]);
  y[0] = gate_nand(b[0], n1);
}
template<> void PilUint<1>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto _a0 = gate_buf(a[0]);
  y[0] = gate_buf(_a0);
}
template<> void PilUint<1>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xnor(b[0], a[0]);
}
template<> void PilUint<1>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_not(a[0]);
  y[0] = gate_nand(b[0], n3);
}
template<> void PilUint<1>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_not(b[0]);
  y[0] = gate_nand(a[0], n3);
}
template<> void PilUint<1>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  y[0] = gate_and(a[0], n4);
}
template<> void PilUint<1>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(a[0]);
  y[0] = gate_and(b[0], n4);
}
template<> void PilUint<1>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void PilUint<1>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(b[0], a[0]);
}
template<> void PilUint<1>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
}
template<> void PilUint<1>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_not(b[0]);
  y[0] = gate_nand(a[0], n3);
}
template<> void PilUint<1>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_not(a[0]);
  y[0] = gate_nand(b[0], n3);
}
template<> void PilUint<1>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
}
template<> void PilUint<1>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void PilUint<1>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  auto n3 = gate_not(a[0]);
  y[0] = gate_nand(n4, n3);
}
template<> void PilUint<1>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(a[0]);
  y[0] = gate_and(b[0], n4);
}
template<> void PilUint<1>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  y[0] = gate_and(a[0], n4);
}
template<> void PilUint<1>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_not(b[0]);
  y[0] = gate_and(a[0], n2);
}
template<> void PilUint<1>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_not(b[0]);
  y[0] = gate_and(a[0], n2);
}
template<> void PilUint<1>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
}
template<> void PilUint<1>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void PilUint<1>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void PilUint<1>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void PilUint<1>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void PilUint<1>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void PilUint<1>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void PilUint<1>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  y[0] = gate_and(a[0], n4);
}
template<> void PilUint<1>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[0]);
  y[0] = gate_and(a[0], n4);
}
template<> void PilUint<1>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void PilUint<1>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(b[0], a[0]);
}
template<> void PilUint<1>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void PilUint<8>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_and(a[0], b[0]);
  y[0] = gate_xor(a[0], b[0]);
  auto n3 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n3, n2);
  auto n7 = gate_xor(b[2], a[2]);
  auto n5 = gate_nand(b[1], a[1]);
  auto n4 = gate_nand(n3, n2);
  auto n6 = gate_nand(n5, n4);
  y[2] = gate_xor(n7, n6);
  auto n11 = gate_xor(b[3], a[3]);
  auto n9 = gate_nand(b[2], a[2]);
  auto n8 = gate_nand(n7, n6);
  auto n10 = gate_nand(n9, n8);
  y[3] = gate_xor(n11, n10);
  auto n15 = gate_xor(b[4], a[4]);
  auto n13 = gate_nand(b[3], a[3]);
  auto n12 = gate_nand(n11, n10);
  auto n14 = gate_nand(n13, n12);
  y[4] = gate_xor(n15, n14);
  auto n19 = gate_xor(b[5], a[5]);
  auto n17 = gate_nand(b[4], a[4]);
  auto n16 = gate_nand(n15, n14);
  auto n18 = gate_nand(n17, n16);
  y[5] = gate_xor(n19, n18);
  auto n23 = gate_xor(b[6], a[6]);
  auto n21 = gate_nand(b[5], a[5]);
  auto n20 = gate_nand(n19, n18);
  auto n22 = gate_nand(n21, n20);
  y[6] = gate_xor(n23, n22);
  auto n25 = gate_nand(n23, n22);
  auto n24 = gate_nand(b[6], a[6]);
  auto n26 = gate_nand(n25, n24);
  auto n27 = gate_xor(b[7], n26);
  y[7] = gate_xor(a[7], n27);
}
template<> void PilUint<8>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[7] = gate_and(b[7], a[7]);
  y[0] = gate_and(b[0], a[0]);
  y[1] = gate_and(b[1], a[1]);
  y[2] = gate_and(b[2], a[2]);
  y[3] = gate_and(b[3], a[3]);
  y[4] = gate_and(b[4], a[4]);
  y[5] = gate_and(b[5], a[5]);
  y[6] = gate_and(b[6], a[6]);
}
template<> void PilUint<8>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[7] = gate_not(a[7]);
  y[6] = gate_not(a[6]);
  y[5] = gate_not(a[5]);
  y[4] = gate_not(a[4]);
  y[3] = gate_not(a[3]);
  y[2] = gate_not(a[2]);
  y[1] = gate_not(a[1]);
  y[0] = gate_not(a[0]);
}
template<> void PilUint<8>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n18 = gate_not(b[7]);
  auto n17 = gate_not(a[7]);
  y[7] = gate_nand(n18, n17);
  auto n20 = gate_not(b[6]);
  auto n19 = gate_not(a[6]);
  y[6] = gate_nand(n20, n19);
  auto n22 = gate_not(b[5]);
  auto n21 = gate_not(a[5]);
  y[5] = gate_nand(n22, n21);
  auto n24 = gate_not(b[4]);
  auto n23 = gate_not(a[4]);
  y[4] = gate_nand(n24, n23);
  auto n26 = gate_not(b[3]);
  auto n25 = gate_not(a[3]);
  y[3] = gate_nand(n26, n25);
  auto n28 = gate_not(b[2]);
  auto n27 = gate_not(a[2]);
  y[2] = gate_nand(n28, n27);
  auto n30 = gate_not(b[1]);
  auto n29 = gate_not(a[1]);
  y[1] = gate_nand(n30, n29);
  auto n32 = gate_not(b[0]);
  auto n31 = gate_not(a[0]);
  y[0] = gate_nand(n32, n31);
}
template<> void PilUint<8>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  y[4] = gate_buf(zero);
  y[5] = gate_buf(zero);
  y[6] = gate_buf(zero);
  y[7] = gate_buf(zero);
  auto N0 = gate_buf(a[0]);
  auto n4 = gate_xor(N0, a[1]);
  auto n11 = gate_xor(n4, a[2]);
  auto n10 = gate_xor(a[6], a[7]);
  auto n15 = gate_xor(n11, n10);
  auto n7 = gate_xor(a[4], a[3]);
  auto n14 = gate_xor(n7, a[5]);
  auto n3 = gate_and(n15, n14);
  y[0] = gate_xor(n15, n14);
  auto n6 = gate_nand(N0, a[1]);
  auto n5 = gate_nand(n4, a[2]);
  auto n18 = gate_nand(n6, n5);
  auto n9 = gate_nand(a[4], a[3]);
  auto n8 = gate_nand(n7, a[5]);
  auto n17 = gate_nand(n9, n8);
  auto n20 = gate_xor(n18, n17);
  auto n13 = gate_nand(a[6], a[7]);
  auto n12 = gate_nand(n11, n10);
  auto n19 = gate_nand(n13, n12);
  auto n16 = gate_xor(n20, n19);
  auto n1 = gate_and(n16, n3);
  y[1] = gate_xor(n16, n3);
  auto n22 = gate_nand(n18, n17);
  auto n21 = gate_nand(n20, n19);
  auto n23 = gate_nand(n22, n21);
  y[3] = gate_and(n1, n23);
  y[2] = gate_xor(n1, n23);
}
template<> void PilUint<8>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[7] = gate_xor(b[7], a[7]);
  y[6] = gate_xor(b[6], a[6]);
  y[5] = gate_xor(b[5], a[5]);
  y[4] = gate_xor(b[4], a[4]);
  y[3] = gate_xor(b[3], a[3]);
  y[2] = gate_xor(b[2], a[2]);
  y[1] = gate_xor(b[1], a[1]);
  y[0] = gate_xor(b[0], a[0]);
}
template<> void PilUint<8>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[7] = gate_and(a[0], b[7]);
  y[6] = gate_and(a[0], b[6]);
  y[5] = gate_and(a[0], b[5]);
  y[4] = gate_and(a[0], b[4]);
  y[3] = gate_and(a[0], b[3]);
  y[2] = gate_and(a[0], b[2]);
  y[1] = gate_and(a[0], b[1]);
  y[0] = gate_and(a[0], b[0]);
}
template<> void PilUint<8>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
  y[1] = gate_mux(c[1], b[1], a[0]);
  y[2] = gate_mux(c[2], b[2], a[0]);
  y[3] = gate_mux(c[3], b[3], a[0]);
  y[4] = gate_mux(c[4], b[4], a[0]);
  y[5] = gate_mux(c[5], b[5], a[0]);
  y[6] = gate_mux(c[6], b[6], a[0]);
  y[7] = gate_mux(c[7], b[7], a[0]);
}
template<> void PilUint<8>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_and(a[0], b[0]);
  y[0] = gate_xor(a[0], b[0]);
  auto n3 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n3, n2);
  auto n7 = gate_xor(b[2], a[2]);
  auto n5 = gate_nand(b[1], a[1]);
  auto n4 = gate_nand(n3, n2);
  auto n6 = gate_nand(n5, n4);
  y[2] = gate_xor(n7, n6);
  auto n11 = gate_xor(b[3], a[3]);
  auto n9 = gate_nand(b[2], a[2]);
  auto n8 = gate_nand(n7, n6);
  auto n10 = gate_nand(n9, n8);
  y[3] = gate_xor(n11, n10);
  auto n15 = gate_xor(b[4], a[4]);
  auto n13 = gate_nand(b[3], a[3]);
  auto n12 = gate_nand(n11, n10);
  auto n14 = gate_nand(n13, n12);
  y[4] = gate_xor(n15, n14);
  auto n19 = gate_xor(b[5], a[5]);
  auto n17 = gate_nand(b[4], a[4]);
  auto n16 = gate_nand(n15, n14);
  auto n18 = gate_nand(n17, n16);
  y[5] = gate_xor(n19, n18);
  auto n23 = gate_xor(b[6], a[6]);
  auto n21 = gate_nand(b[5], a[5]);
  auto n20 = gate_nand(n19, n18);
  auto n22 = gate_nand(n21, n20);
  y[6] = gate_xor(n23, n22);
  auto n25 = gate_nand(b[6], a[6]);
  auto n24 = gate_nand(n23, n22);
  y[7] = gate_nand(n25, n24);
}
template<> void PilUint<8>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  y[1] = gate_xor(a[1], y[0]);
  auto n7 = gate_not(a[1]);
  auto n2 = gate_and(n7, y[0]);
  y[2] = gate_xor(a[2], n2);
  auto n8 = gate_not(a[2]);
  auto n3 = gate_and(n2, n8);
  y[3] = gate_xor(a[3], n3);
  auto n9 = gate_not(a[3]);
  auto n4 = gate_and(n3, n9);
  y[4] = gate_xor(a[4], n4);
  auto n10 = gate_not(a[4]);
  auto n5 = gate_and(n4, n10);
  y[5] = gate_xor(a[5], n5);
  auto n11 = gate_not(a[5]);
  auto n6 = gate_and(n5, n11);
  y[6] = gate_xor(a[6], n6);
  auto n14 = gate_not(a[7]);
  auto n12 = gate_not(a[6]);
  auto n13 = gate_nand(n6, n12);
  y[7] = gate_xor(n14, n13);
}
template<> void PilUint<8>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_not(a[6]);
  auto n12 = gate_nand(b[0], n11);
  auto n135 = gate_not(b[7]);
  auto n193 = gate_not(b[6]);
  auto n4 = gate_and(n135, n193);
  auto n142 = gate_not(b[5]);
  auto n3 = gate_and(n4, n142);
  auto n178 = gate_not(b[4]);
  auto n7 = gate_and(n3, n178);
  auto n148 = gate_not(b[3]);
  auto n2 = gate_and(n7, n148);
  auto n164 = gate_not(b[2]);
  auto n6 = gate_and(n2, n164);
  auto n5 = gate_and(n12, n6);
  auto n19 = gate_not(a[7]);
  auto n13 = gate_nand(b[1], n19);
  auto n21 = gate_nand(n5, n13);
  y[6] = gate_not(n21);
  auto n14 = gate_nand(y[6], b[0]);
  auto n32 = gate_nand(a[6], n14);
  auto n15 = gate_not(n32);
  auto n151 = gate_not(b[1]);
  auto n1 = gate_and(n151, n6);
  auto n17 = gate_nand(n15, n151);
  auto n28 = gate_xor(b[1], n32);
  auto n34 = gate_not(a[5]);
  auto n29 = gate_nand(b[0], n34);
  auto n16 = gate_nand(n28, n29);
  auto n18 = gate_nand(n17, n16);
  auto n24 = gate_nand(n18, n164);
  auto n22 = gate_xor(n18, n164);
  auto n20 = gate_nand(b[0], n19);
  auto n201 = gate_nand(n1, n20);
  y[7] = gate_not(n201);
  auto n8 = gate_and(n21, n201);
  auto n40 = gate_nand(a[7], n8);
  auto n27 = gate_not(n40);
  auto n23 = gate_nand(n22, n27);
  auto n25 = gate_nand(n24, n23);
  auto n26 = gate_nand(n2, n25);
  y[5] = gate_not(n26);
  auto n64 = gate_nand(n27, n26);
  auto n47 = gate_not(n64);
  auto n44 = gate_nand(n47, n148);
  auto n30 = gate_not(n28);
  auto n31 = gate_nand(n30, n29);
  auto n37 = gate_mux(n32, n31, y[5]);
  auto n49 = gate_xor(b[2], n37);
  auto n33 = gate_nand(y[5], b[0]);
  auto n55 = gate_xor(n34, n33);
  auto n36 = gate_nand(n151, n55);
  auto n53 = gate_xor(n151, n55);
  auto n57 = gate_not(a[4]);
  auto n52 = gate_nand(b[0], n57);
  auto n35 = gate_nand(n53, n52);
  auto n48 = gate_nand(n36, n35);
  auto n39 = gate_nand(n49, n48);
  auto n51 = gate_not(n37);
  auto n38 = gate_nand(n164, n51);
  auto n42 = gate_nand(n39, n38);
  auto n41 = gate_nand(b[3], n40);
  auto n43 = gate_nand(n42, n41);
  auto n45 = gate_nand(n44, n43);
  auto n46 = gate_nand(n7, n45);
  y[4] = gate_not(n46);
  auto n94 = gate_nand(n47, n46);
  auto n70 = gate_not(n94);
  auto n68 = gate_nand(n70, n178);
  auto n50 = gate_xor(n49, n48);
  auto n73 = gate_mux(n51, n50, y[4]);
  auto n71 = gate_xor(n148, n73);
  auto n54 = gate_xor(n53, n52);
  auto n78 = gate_mux(n55, n54, y[4]);
  auto n61 = gate_nand(n78, n164);
  auto n75 = gate_xor(n164, n78);
  auto n56 = gate_nand(y[4], b[0]);
  auto n83 = gate_xor(n57, n56);
  auto n59 = gate_nand(n151, n83);
  auto n81 = gate_xor(n151, n83);
  auto n85 = gate_not(a[3]);
  auto n80 = gate_nand(b[0], n85);
  auto n58 = gate_nand(n81, n80);
  auto n76 = gate_nand(n59, n58);
  auto n60 = gate_nand(n75, n76);
  auto n72 = gate_nand(n61, n60);
  auto n63 = gate_nand(n71, n72);
  auto n62 = gate_nand(n73, n148);
  auto n66 = gate_nand(n63, n62);
  auto n65 = gate_nand(b[4], n64);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n77 = gate_nand(n3, n69);
  y[3] = gate_not(n77);
  auto n136 = gate_nand(n70, n77);
  auto n131 = gate_not(n136);
  auto n98 = gate_nand(n131, n142);
  auto n74 = gate_xor(n72, n71);
  auto n102 = gate_mux(n74, n73, n77);
  auto n100 = gate_xor(n102, n178);
  auto n79 = gate_xor(n76, n75);
  auto n106 = gate_mux(n79, n78, n77);
  auto n91 = gate_nand(n106, n148);
  auto n104 = gate_xor(n106, n148);
  auto n82 = gate_xor(n81, n80);
  auto n110 = gate_mux(n83, n82, y[3]);
  auto n89 = gate_nand(n110, n164);
  auto n108 = gate_xor(n164, n110);
  auto n84 = gate_nand(y[3], b[0]);
  auto n115 = gate_xor(n85, n84);
  auto n87 = gate_nand(n151, n115);
  auto n113 = gate_xor(n151, n115);
  auto n117 = gate_not(a[2]);
  auto n112 = gate_nand(b[0], n117);
  auto n86 = gate_nand(n113, n112);
  auto n109 = gate_nand(n87, n86);
  auto n88 = gate_nand(n108, n109);
  auto n105 = gate_nand(n89, n88);
  auto n90 = gate_nand(n104, n105);
  auto n101 = gate_nand(n91, n90);
  auto n93 = gate_nand(n100, n101);
  auto n92 = gate_nand(n102, n178);
  auto n96 = gate_nand(n93, n92);
  auto n95 = gate_nand(b[5], n94);
  auto n97 = gate_nand(n96, n95);
  auto n99 = gate_nand(n98, n97);
  auto n130 = gate_nand(n4, n99);
  auto n9 = gate_and(n131, n130);
  y[2] = gate_not(n130);
  auto n103 = gate_xor(n101, n100);
  auto n189 = gate_mux(n103, n102, n130);
  auto n186 = gate_xor(n189, n142);
  auto n107 = gate_xor(n105, n104);
  auto n139 = gate_mux(n107, n106, n130);
  auto n125 = gate_nand(n139, n178);
  auto n137 = gate_xor(n139, n178);
  auto n111 = gate_xor(n109, n108);
  auto n174 = gate_mux(n111, n110, n130);
  auto n123 = gate_nand(n174, n148);
  auto n172 = gate_xor(n174, n148);
  auto n114 = gate_xor(n113, n112);
  auto n145 = gate_mux(n115, n114, y[2]);
  auto n121 = gate_nand(n145, n164);
  auto n143 = gate_xor(n164, n145);
  auto n116 = gate_nand(y[2], b[0]);
  auto n161 = gate_xor(n117, n116);
  auto n119 = gate_nand(n151, n161);
  auto n159 = gate_xor(n151, n161);
  auto n150 = gate_not(a[1]);
  auto n158 = gate_nand(b[0], n150);
  auto n118 = gate_nand(n159, n158);
  auto n144 = gate_nand(n119, n118);
  auto n120 = gate_nand(n143, n144);
  auto n173 = gate_nand(n121, n120);
  auto n122 = gate_nand(n172, n173);
  auto n138 = gate_nand(n123, n122);
  auto n124 = gate_nand(n137, n138);
  auto n187 = gate_nand(n125, n124);
  auto n127 = gate_nand(n186, n187);
  auto n126 = gate_nand(n189, n142);
  auto n129 = gate_nand(n127, n126);
  auto n128 = gate_nand(b[6], n136);
  auto n133 = gate_nand(n129, n128);
  auto n132 = gate_nand(n9, n193);
  auto n134 = gate_nand(n133, n132);
  auto n188 = gate_nand(n135, n134);
  auto n10 = gate_and(n9, n188);
  y[1] = gate_not(n188);
  auto n200 = gate_nand(n10, n135);
  auto n198 = gate_nand(b[7], n136);
  auto n140 = gate_xor(n138, n137);
  auto n141 = gate_mux(n140, n139, n188);
  auto n185 = gate_nand(n142, n141);
  auto n183 = gate_xor(n142, n141);
  auto n146 = gate_xor(n144, n143);
  auto n147 = gate_mux(n146, n145, n188);
  auto n171 = gate_nand(n148, n147);
  auto n169 = gate_xor(n148, n147);
  auto n149 = gate_nand(y[1], b[0]);
  auto n152 = gate_xor(n150, n149);
  auto n157 = gate_nand(n152, n151);
  auto n155 = gate_xor(n152, n151);
  auto n153 = gate_not(a[0]);
  auto n154 = gate_nand(b[0], n153);
  auto n156 = gate_nand(n155, n154);
  auto n163 = gate_nand(n157, n156);
  auto n160 = gate_xor(n159, n158);
  auto n162 = gate_mux(n161, n160, y[1]);
  auto n167 = gate_nand(n163, n162);
  auto n165 = gate_xor(n163, n162);
  auto n166 = gate_nand(n165, n164);
  auto n168 = gate_nand(n167, n166);
  auto n170 = gate_nand(n169, n168);
  auto n177 = gate_nand(n171, n170);
  auto n175 = gate_xor(n173, n172);
  auto n176 = gate_mux(n175, n174, n188);
  auto n181 = gate_nand(n177, n176);
  auto n179 = gate_xor(n177, n176);
  auto n180 = gate_nand(n179, n178);
  auto n182 = gate_nand(n181, n180);
  auto n184 = gate_nand(n183, n182);
  auto n192 = gate_nand(n185, n184);
  auto n190 = gate_xor(n187, n186);
  auto n191 = gate_mux(n190, n189, n188);
  auto n196 = gate_nand(n192, n191);
  auto n194 = gate_xor(n192, n191);
  auto n195 = gate_nand(n194, n193);
  auto n197 = gate_nand(n196, n195);
  auto n199 = gate_nand(n198, n197);
  y[0] = gate_nand(n200, n199);
}
template<> void PilUint<8>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n264 = gate_not(b[7]);
  auto n251 = gate_xor(a[7], n264);
  auto n266 = gate_not(n251);
  auto n160 = gate_not(a[1]);
  auto n194 = gate_not(a[0]);
  auto n119 = gate_nand(n160, n194);
  auto n20 = gate_not(n119);
  auto n19 = gate_not(a[2]);
  auto n86 = gate_nand(n20, n19);
  auto n22 = gate_not(n86);
  auto n21 = gate_not(a[3]);
  auto n59 = gate_nand(n22, n21);
  auto n24 = gate_not(n59);
  auto n23 = gate_not(a[4]);
  auto n39 = gate_nand(n24, n23);
  auto n26 = gate_not(n39);
  auto n25 = gate_not(a[5]);
  auto n29 = gate_nand(n26, n25);
  auto n27 = gate_not(n29);
  auto n31 = gate_not(a[6]);
  auto n7 = gate_and(n27, n31);
  auto n46 = gate_nand(a[7], n7);
  auto n252 = gate_not(n46);
  auto n8 = gate_and(n252, b[0]);
  auto n237 = gate_xor(b[6], b[7]);
  auto n179 = gate_not(n237);
  auto n186 = gate_xor(b[5], b[7]);
  auto n142 = gate_not(n186);
  auto n5 = gate_and(n179, n142);
  auto n218 = gate_xor(b[4], b[7]);
  auto n183 = gate_not(n218);
  auto n4 = gate_and(n5, n183);
  auto n192 = gate_xor(b[3], b[7]);
  auto n221 = gate_not(n192);
  auto n3 = gate_and(n4, n221);
  auto n203 = gate_xor(b[2], b[7]);
  auto n189 = gate_not(n203);
  auto n2 = gate_and(n3, n189);
  auto n196 = gate_xor(b[1], b[7]);
  auto n206 = gate_not(n196);
  auto n9 = gate_and(n2, n206);
  auto n28 = gate_nand(n9, b[0]);
  auto n10 = gate_and(n252, n28);
  auto n35 = gate_nand(n10, n206);
  auto n30 = gate_nand(a[7], n29);
  auto n37 = gate_xor(n31, n30);
  auto n263 = gate_not(b[0]);
  auto n6 = gate_and(n264, n263);
  auto n33 = gate_mux(n37, n264, n263);
  auto n32 = gate_nand(n196, n46);
  auto n34 = gate_nand(n33, n32);
  auto n36 = gate_nand(n35, n34);
  auto n250 = gate_nand(n2, n36);
  auto n53 = gate_nand(n10, n250);
  auto n52 = gate_not(n53);
  auto n50 = gate_nand(n52, n189);
  auto n38 = gate_nand(n37, n250);
  auto n54 = gate_not(n38);
  auto n45 = gate_nand(n206, n54);
  auto n43 = gate_xor(n196, n38);
  auto n40 = gate_nand(a[7], n39);
  auto n58 = gate_xor(a[5], n40);
  auto n41 = gate_mux(n58, b[7], n263);
  auto n42 = gate_not(n41);
  auto n44 = gate_nand(n43, n42);
  auto n48 = gate_nand(n45, n44);
  auto n47 = gate_nand(n203, n46);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  auto n56 = gate_nand(n3, n51);
  auto n75 = gate_nand(n52, n56);
  auto n74 = gate_not(n75);
  auto n70 = gate_nand(n53, n192);
  auto n55 = gate_nand(n54, n56);
  auto n76 = gate_not(n55);
  auto n68 = gate_nand(n189, n76);
  auto n66 = gate_xor(n203, n55);
  auto n249 = gate_not(n56);
  auto n57 = gate_nand(n249, b[0]);
  auto n82 = gate_xor(n58, n57);
  auto n64 = gate_nand(n82, n206);
  auto n62 = gate_xor(n82, n206);
  auto n60 = gate_nand(a[7], n59);
  auto n85 = gate_xor(a[4], n60);
  auto n61 = gate_mux(n85, b[7], n263);
  auto n79 = gate_not(n61);
  auto n63 = gate_nand(n62, n79);
  auto n65 = gate_nand(n64, n63);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n72 = gate_nand(n70, n69);
  auto n71 = gate_nand(n221, n74);
  auto n73 = gate_nand(n72, n71);
  auto n78 = gate_nand(n4, n73);
  auto n140 = gate_nand(n74, n78);
  auto n104 = gate_not(n140);
  auto n100 = gate_nand(n75, n218);
  auto n77 = gate_nand(n76, n78);
  auto n105 = gate_not(n77);
  auto n98 = gate_nand(n221, n105);
  auto n96 = gate_xor(n192, n77);
  auto n248 = gate_not(n78);
  auto n80 = gate_xor(n206, n79);
  auto n81 = gate_nand(n248, n80);
  auto n111 = gate_xor(n82, n81);
  auto n83 = gate_not(n111);
  auto n94 = gate_nand(n83, n189);
  auto n92 = gate_xor(n189, n83);
  auto n84 = gate_nand(n248, b[0]);
  auto n115 = gate_xor(n85, n84);
  auto n91 = gate_nand(n115, n206);
  auto n89 = gate_xor(n115, n206);
  auto n87 = gate_nand(a[7], n86);
  auto n118 = gate_xor(a[3], n87);
  auto n88 = gate_mux(n118, b[7], n263);
  auto n112 = gate_not(n88);
  auto n90 = gate_nand(n89, n112);
  auto n108 = gate_nand(n91, n90);
  auto n93 = gate_nand(n92, n108);
  auto n95 = gate_nand(n94, n93);
  auto n97 = gate_nand(n96, n95);
  auto n99 = gate_nand(n98, n97);
  auto n102 = gate_nand(n100, n99);
  auto n101 = gate_nand(n183, n104);
  auto n103 = gate_nand(n102, n101);
  auto n107 = gate_nand(n5, n103);
  auto n14 = gate_and(n104, n107);
  auto n136 = gate_nand(n140, n186);
  auto n106 = gate_nand(n105, n107);
  auto n141 = gate_not(n106);
  auto n134 = gate_nand(n183, n141);
  auto n132 = gate_xor(n218, n106);
  auto n247 = gate_not(n107);
  auto n109 = gate_xor(n189, n108);
  auto n110 = gate_nand(n247, n109);
  auto n148 = gate_xor(n111, n110);
  auto n130 = gate_nand(n148, n221);
  auto n128 = gate_xor(n148, n221);
  auto n113 = gate_xor(n206, n112);
  auto n114 = gate_nand(n247, n113);
  auto n152 = gate_xor(n115, n114);
  auto n116 = gate_not(n152);
  auto n127 = gate_nand(n116, n189);
  auto n125 = gate_xor(n203, n152);
  auto n117 = gate_nand(n247, b[0]);
  auto n156 = gate_xor(n118, n117);
  auto n124 = gate_nand(n156, n206);
  auto n122 = gate_xor(n156, n206);
  auto n120 = gate_nand(a[7], n119);
  auto n158 = gate_xor(a[2], n120);
  auto n121 = gate_mux(n158, b[7], n263);
  auto n153 = gate_not(n121);
  auto n123 = gate_nand(n122, n153);
  auto n149 = gate_nand(n124, n123);
  auto n126 = gate_nand(n125, n149);
  auto n145 = gate_nand(n127, n126);
  auto n129 = gate_nand(n128, n145);
  auto n131 = gate_nand(n130, n129);
  auto n133 = gate_nand(n132, n131);
  auto n135 = gate_nand(n134, n133);
  auto n138 = gate_nand(n136, n135);
  auto n137 = gate_nand(n142, n14);
  auto n139 = gate_nand(n138, n137);
  auto n144 = gate_nand(n179, n139);
  auto n17 = gate_and(n14, n144);
  auto n178 = gate_nand(n140, n237);
  auto n143 = gate_nand(n141, n144);
  auto n234 = gate_not(n143);
  auto n176 = gate_nand(n142, n234);
  auto n174 = gate_xor(n186, n143);
  auto n246 = gate_not(n144);
  auto n146 = gate_xor(n221, n145);
  auto n147 = gate_nand(n246, n146);
  auto n16 = gate_xnor(n148, n147);
  auto n172 = gate_nand(n16, n183);
  auto n170 = gate_xor(n183, n16);
  auto n150 = gate_xor(n189, n149);
  auto n151 = gate_nand(n246, n150);
  auto n225 = gate_xor(n152, n151);
  auto n169 = gate_nand(n225, n221);
  auto n167 = gate_xor(n221, n225);
  auto n154 = gate_xor(n206, n153);
  auto n155 = gate_nand(n246, n154);
  auto n15 = gate_xnor(n156, n155);
  auto n166 = gate_nand(n15, n189);
  auto n164 = gate_xor(n189, n15);
  auto n157 = gate_nand(b[0], n246);
  auto n209 = gate_xor(n158, n157);
  auto n163 = gate_nand(n209, n206);
  auto n161 = gate_xor(n206, n209);
  auto n159 = gate_nand(a[0], a[7]);
  auto n198 = gate_xor(n160, n159);
  auto n205 = gate_mux(n198, n264, n263);
  auto n162 = gate_nand(n161, n205);
  auto n188 = gate_nand(n163, n162);
  auto n165 = gate_nand(n164, n188);
  auto n220 = gate_nand(n166, n165);
  auto n168 = gate_nand(n167, n220);
  auto n182 = gate_nand(n169, n168);
  auto n171 = gate_nand(n170, n182);
  auto n173 = gate_nand(n172, n171);
  auto n175 = gate_nand(n174, n173);
  auto n177 = gate_nand(n176, n175);
  auto n181 = gate_nand(n178, n177);
  auto n180 = gate_nand(n179, n17);
  auto n223 = gate_nand(n181, n180);
  auto n245 = gate_not(n223);
  auto n242 = gate_nand(n17, n245);
  auto n184 = gate_xor(n183, n182);
  auto n185 = gate_nand(n223, n184);
  auto n187 = gate_xor(n16, n185);
  auto n233 = gate_nand(n187, n186);
  auto n231 = gate_xor(n187, n186);
  auto n190 = gate_xor(n189, n188);
  auto n191 = gate_nand(n223, n190);
  auto n193 = gate_xor(n15, n191);
  auto n217 = gate_nand(n193, n192);
  auto n215 = gate_xor(n193, n192);
  auto n195 = gate_mux(n194, b[7], n263);
  auto n202 = gate_nand(n196, n195);
  auto n200 = gate_xor(n196, n195);
  auto n197 = gate_nand(b[0], n223);
  auto n199 = gate_xor(n198, n197);
  auto n201 = gate_nand(n200, n199);
  auto n204 = gate_nand(n202, n201);
  auto n213 = gate_nand(n204, n203);
  auto n211 = gate_xor(n204, n203);
  auto n207 = gate_xor(n206, n205);
  auto n208 = gate_nand(n223, n207);
  auto n210 = gate_xor(n209, n208);
  auto n212 = gate_nand(n211, n210);
  auto n214 = gate_nand(n213, n212);
  auto n216 = gate_nand(n215, n214);
  auto n219 = gate_nand(n217, n216);
  auto n229 = gate_nand(n219, n218);
  auto n227 = gate_xor(n219, n218);
  auto n222 = gate_xor(n221, n220);
  auto n224 = gate_nand(n223, n222);
  auto n226 = gate_xor(n225, n224);
  auto n228 = gate_nand(n227, n226);
  auto n230 = gate_nand(n229, n228);
  auto n232 = gate_nand(n231, n230);
  auto n236 = gate_nand(n233, n232);
  auto n235 = gate_nand(n234, n245);
  auto n240 = gate_nand(n236, n235);
  auto n238 = gate_xor(n236, n235);
  auto n239 = gate_nand(n238, n237);
  auto n241 = gate_nand(n240, n239);
  auto n262 = gate_nand(n242, n241);
  auto n243 = gate_not(n262);
  auto n269 = gate_nand(n266, n243);
  auto n244 = gate_not(n269);
  auto n261 = gate_xor(n251, n245);
  auto n18 = gate_and(n244, n261);
  auto n260 = gate_xor(n266, n246);
  auto n11 = gate_and(n18, n260);
  auto n259 = gate_xor(n266, n247);
  auto n13 = gate_and(n11, n259);
  auto n258 = gate_xor(n266, n248);
  auto n1 = gate_and(n13, n258);
  auto n257 = gate_xor(n266, n249);
  auto n12 = gate_and(n1, n257);
  auto n256 = gate_xor(n251, n250);
  auto n255 = gate_nand(n12, n256);
  auto n253 = gate_nand(n8, n9);
  auto n254 = gate_xor(n266, n253);
  y[7] = gate_xor(n255, n254);
  y[6] = gate_xor(n12, n256);
  y[5] = gate_xor(n1, n257);
  y[4] = gate_xor(n13, n258);
  y[3] = gate_xor(n11, n259);
  y[2] = gate_xor(n18, n260);
  y[1] = gate_xor(n244, n261);
  auto n268 = gate_xor(n262, n266);
  auto n265 = gate_nand(n6, n9);
  auto n267 = gate_nand(n266, n265);
  y[0] = gate_mux(n269, n268, n267);
}
template<> void PilUint<8>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n31 = gate_xnor(b[7], a[7]);
  auto n38 = gate_xnor(a[1], b[1]);
  auto n40 = gate_xnor(b[4], a[4]);
  auto n41 = gate_xnor(b[5], a[5]);
  auto n42 = gate_xnor(b[6], a[6]);
  auto n43 = gate_not(b[2]);
  auto n48 = gate_xor(n43, a[2]);
  auto n44 = gate_not(a[3]);
  auto n47 = gate_xor(n44, b[3]);
  auto n45 = gate_not(a[0]);
  auto n46 = gate_xor(n45, b[0]);
  auto n33 = gate_and(n47, n46);
  auto n32 = gate_and(n33, n38);
  auto n39 = gate_and(n48, n32);
  auto n35 = gate_and(n39, n41);
  auto n34 = gate_and(n35, n40);
  auto n36 = gate_and(n34, n42);
  y[0] = gate_and(n36, n31);
}
template<> void PilUint<8>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n39 = gate_not(b[7]);
  auto n74 = gate_nand(n39, a[7]);
  auto n72 = gate_xor(n39, a[7]);
  auto n40 = gate_not(b[5]);
  auto n65 = gate_nand(n40, a[5]);
  auto n63 = gate_xor(n40, a[5]);
  auto n41 = gate_not(b[3]);
  auto n56 = gate_nand(n41, a[3]);
  auto n54 = gate_xor(n41, a[3]);
  auto n42 = gate_not(b[2]);
  auto n52 = gate_nand(n42, a[2]);
  auto n50 = gate_xor(n42, a[2]);
  auto n43 = gate_not(b[1]);
  auto n48 = gate_nand(n43, a[1]);
  auto n46 = gate_xor(n43, a[1]);
  auto n44 = gate_not(a[0]);
  auto n45 = gate_nand(b[0], n44);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n55 = gate_nand(n54, n53);
  auto n57 = gate_nand(n56, n55);
  auto n61 = gate_nand(n57, a[4]);
  auto n59 = gate_xor(n57, a[4]);
  auto n58 = gate_not(b[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n64 = gate_nand(n63, n62);
  auto n66 = gate_nand(n65, n64);
  auto n70 = gate_nand(n66, a[6]);
  auto n68 = gate_xor(n66, a[6]);
  auto n67 = gate_not(b[6]);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n73 = gate_nand(n72, n71);
  y[0] = gate_nand(n74, n73);
}
template<> void PilUint<8>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n39 = gate_not(a[7]);
  auto n74 = gate_nand(n39, b[7]);
  auto n72 = gate_xor(n39, b[7]);
  auto n40 = gate_not(b[5]);
  auto n65 = gate_nand(n40, a[5]);
  auto n63 = gate_xor(n40, a[5]);
  auto n41 = gate_not(b[3]);
  auto n56 = gate_nand(n41, a[3]);
  auto n54 = gate_xor(n41, a[3]);
  auto n42 = gate_not(b[2]);
  auto n52 = gate_nand(n42, a[2]);
  auto n50 = gate_xor(n42, a[2]);
  auto n43 = gate_not(b[1]);
  auto n48 = gate_nand(n43, a[1]);
  auto n46 = gate_xor(n43, a[1]);
  auto n44 = gate_not(a[0]);
  auto n45 = gate_nand(b[0], n44);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n55 = gate_nand(n54, n53);
  auto n57 = gate_nand(n56, n55);
  auto n61 = gate_nand(n57, a[4]);
  auto n59 = gate_xor(n57, a[4]);
  auto n58 = gate_not(b[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n64 = gate_nand(n63, n62);
  auto n66 = gate_nand(n65, n64);
  auto n70 = gate_nand(n66, a[6]);
  auto n68 = gate_xor(n66, a[6]);
  auto n67 = gate_not(b[6]);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n73 = gate_nand(n72, n71);
  y[0] = gate_nand(n74, n73);
}
template<> void PilUint<8>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n41 = gate_not(b[6]);
  auto n70 = gate_nand(n41, a[6]);
  auto n68 = gate_xor(n41, a[6]);
  auto n42 = gate_not(a[1]);
  auto n47 = gate_nand(n42, b[1]);
  auto n45 = gate_xor(n42, b[1]);
  auto n43 = gate_not(b[0]);
  auto n44 = gate_nand(a[0], n43);
  auto n46 = gate_nand(n45, n44);
  auto n48 = gate_nand(n47, n46);
  auto n52 = gate_nand(n48, b[2]);
  auto n50 = gate_xor(n48, b[2]);
  auto n49 = gate_not(a[2]);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n57 = gate_nand(n53, b[3]);
  auto n55 = gate_xor(n53, b[3]);
  auto n54 = gate_not(a[3]);
  auto n56 = gate_nand(n55, n54);
  auto n40 = gate_and(n57, n56);
  auto n61 = gate_nand(n40, a[4]);
  auto n59 = gate_xor(n40, a[4]);
  auto n58 = gate_not(b[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n66 = gate_nand(n62, a[5]);
  auto n64 = gate_xor(n62, a[5]);
  auto n63 = gate_not(b[5]);
  auto n65 = gate_nand(n64, n63);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n75 = gate_nand(n71, a[7]);
  auto n73 = gate_xor(n71, a[7]);
  auto n72 = gate_not(b[7]);
  auto n74 = gate_nand(n73, n72);
  y[0] = gate_nand(n75, n74);
}
template<> void PilUint<8>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n41 = gate_not(b[6]);
  auto n70 = gate_nand(n41, a[6]);
  auto n68 = gate_xor(n41, a[6]);
  auto n42 = gate_not(a[1]);
  auto n47 = gate_nand(n42, b[1]);
  auto n45 = gate_xor(n42, b[1]);
  auto n43 = gate_not(b[0]);
  auto n44 = gate_nand(a[0], n43);
  auto n46 = gate_nand(n45, n44);
  auto n48 = gate_nand(n47, n46);
  auto n52 = gate_nand(n48, b[2]);
  auto n50 = gate_xor(n48, b[2]);
  auto n49 = gate_not(a[2]);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n57 = gate_nand(n53, b[3]);
  auto n55 = gate_xor(n53, b[3]);
  auto n54 = gate_not(a[3]);
  auto n56 = gate_nand(n55, n54);
  auto n40 = gate_and(n57, n56);
  auto n61 = gate_nand(n40, a[4]);
  auto n59 = gate_xor(n40, a[4]);
  auto n58 = gate_not(b[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n66 = gate_nand(n62, a[5]);
  auto n64 = gate_xor(n62, a[5]);
  auto n63 = gate_not(b[5]);
  auto n65 = gate_nand(n64, n63);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n75 = gate_nand(n71, b[7]);
  auto n73 = gate_xor(n71, b[7]);
  auto n72 = gate_not(a[7]);
  auto n74 = gate_nand(n73, n72);
  y[0] = gate_nand(n75, n74);
}
template<> void PilUint<8>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n2 = gate_and(a[0], a[1]);
  auto n3 = gate_and(n2, a[2]);
  auto n4 = gate_and(n3, a[3]);
  auto n5 = gate_and(n4, a[4]);
  auto n6 = gate_and(n5, a[5]);
  y[0] = gate_not(a[0]);
  y[1] = gate_xor(a[0], a[1]);
  y[2] = gate_xor(n2, a[2]);
  y[3] = gate_xor(n3, a[3]);
  y[4] = gate_xor(n4, a[4]);
  y[5] = gate_xor(n5, a[5]);
  y[6] = gate_xor(n6, a[6]);
  auto n8 = gate_not(a[7]);
  auto n7 = gate_nand(n6, a[6]);
  y[7] = gate_xor(n8, n7);
}
template<> void PilUint<8>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n29 = gate_xnor(b[7], a[7]);
  auto n35 = gate_xnor(a[1], b[1]);
  auto n37 = gate_xnor(b[4], a[4]);
  auto n38 = gate_xnor(b[5], a[5]);
  auto n39 = gate_xnor(b[6], a[6]);
  auto n40 = gate_not(b[2]);
  auto n45 = gate_xor(n40, a[2]);
  auto n41 = gate_not(a[3]);
  auto n44 = gate_xor(n41, b[3]);
  auto n42 = gate_not(a[0]);
  auto n43 = gate_xor(n42, b[0]);
  auto n31 = gate_and(n44, n43);
  auto n30 = gate_and(n31, n35);
  auto n36 = gate_and(n45, n30);
  auto n33 = gate_and(n36, n38);
  auto n32 = gate_and(n33, n37);
  auto n34 = gate_and(n32, n39);
  y[0] = gate_nand(n34, n29);
}
template<> void PilUint<8>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n29 = gate_not(a[1]);
  auto n28 = gate_not(a[3]);
  auto n25 = gate_and(n29, n28);
  auto n31 = gate_not(a[2]);
  auto n30 = gate_not(a[0]);
  auto n24 = gate_and(n31, n30);
  auto n22 = gate_and(n25, n24);
  auto n33 = gate_not(a[5]);
  auto n32 = gate_not(a[7]);
  auto n27 = gate_and(n33, n32);
  auto n35 = gate_not(a[6]);
  auto n34 = gate_not(a[4]);
  auto n26 = gate_and(n35, n34);
  auto n23 = gate_and(n27, n26);
  auto n36 = gate_nand(n22, n23);
  y[7] = gate_mux(c[7], b[7], n36);
  y[0] = gate_mux(c[0], b[0], n36);
  y[1] = gate_mux(c[1], b[1], n36);
  y[2] = gate_mux(c[2], b[2], n36);
  y[3] = gate_mux(c[3], b[3], n36);
  y[4] = gate_mux(c[4], b[4], n36);
  y[5] = gate_mux(c[5], b[5], n36);
  y[6] = gate_mux(c[6], b[6], n36);
}
template<> void PilUint<8>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n39 = gate_not(a[7]);
  auto n74 = gate_nand(n39, b[7]);
  auto n72 = gate_xor(n39, b[7]);
  auto n40 = gate_not(a[5]);
  auto n65 = gate_nand(n40, b[5]);
  auto n63 = gate_xor(n40, b[5]);
  auto n41 = gate_not(a[3]);
  auto n56 = gate_nand(n41, b[3]);
  auto n54 = gate_xor(n41, b[3]);
  auto n42 = gate_not(a[2]);
  auto n52 = gate_nand(n42, b[2]);
  auto n50 = gate_xor(n42, b[2]);
  auto n43 = gate_not(a[1]);
  auto n48 = gate_nand(n43, b[1]);
  auto n46 = gate_xor(n43, b[1]);
  auto n44 = gate_not(b[0]);
  auto n45 = gate_nand(a[0], n44);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n55 = gate_nand(n54, n53);
  auto n57 = gate_nand(n56, n55);
  auto n61 = gate_nand(n57, b[4]);
  auto n59 = gate_xor(n57, b[4]);
  auto n58 = gate_not(a[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n64 = gate_nand(n63, n62);
  auto n66 = gate_nand(n65, n64);
  auto n70 = gate_nand(n66, b[6]);
  auto n68 = gate_xor(n66, b[6]);
  auto n67 = gate_not(a[6]);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n73 = gate_nand(n72, n71);
  y[0] = gate_nand(n74, n73);
}
template<> void PilUint<8>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n39 = gate_not(b[7]);
  auto n74 = gate_nand(n39, a[7]);
  auto n72 = gate_xor(n39, a[7]);
  auto n40 = gate_not(a[5]);
  auto n65 = gate_nand(n40, b[5]);
  auto n63 = gate_xor(n40, b[5]);
  auto n41 = gate_not(a[3]);
  auto n56 = gate_nand(n41, b[3]);
  auto n54 = gate_xor(n41, b[3]);
  auto n42 = gate_not(a[2]);
  auto n52 = gate_nand(n42, b[2]);
  auto n50 = gate_xor(n42, b[2]);
  auto n43 = gate_not(a[1]);
  auto n48 = gate_nand(n43, b[1]);
  auto n46 = gate_xor(n43, b[1]);
  auto n44 = gate_not(b[0]);
  auto n45 = gate_nand(a[0], n44);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n55 = gate_nand(n54, n53);
  auto n57 = gate_nand(n56, n55);
  auto n61 = gate_nand(n57, b[4]);
  auto n59 = gate_xor(n57, b[4]);
  auto n58 = gate_not(a[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n64 = gate_nand(n63, n62);
  auto n66 = gate_nand(n65, n64);
  auto n70 = gate_nand(n66, b[6]);
  auto n68 = gate_xor(n66, b[6]);
  auto n67 = gate_not(a[6]);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n73 = gate_nand(n72, n71);
  y[0] = gate_nand(n74, n73);
}
template<> void PilUint<8>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n58 = gate_not(b[1]);
  auto n57 = gate_not(b[3]);
  auto n50 = gate_and(n58, n57);
  auto n60 = gate_not(b[2]);
  auto n59 = gate_not(b[0]);
  auto n49 = gate_and(n60, n59);
  auto n45 = gate_and(n50, n49);
  auto n62 = gate_not(b[5]);
  auto n61 = gate_not(b[7]);
  auto n52 = gate_and(n62, n61);
  auto n64 = gate_not(b[6]);
  auto n63 = gate_not(b[4]);
  auto n51 = gate_and(n64, n63);
  auto n46 = gate_and(n52, n51);
  auto n74 = gate_nand(n45, n46);
  auto n66 = gate_not(a[1]);
  auto n65 = gate_not(a[3]);
  auto n54 = gate_and(n66, n65);
  auto n68 = gate_not(a[2]);
  auto n67 = gate_not(a[0]);
  auto n53 = gate_and(n68, n67);
  auto n47 = gate_and(n54, n53);
  auto n70 = gate_not(a[5]);
  auto n69 = gate_not(a[7]);
  auto n56 = gate_and(n70, n69);
  auto n72 = gate_not(a[6]);
  auto n71 = gate_not(a[4]);
  auto n55 = gate_and(n72, n71);
  auto n48 = gate_and(n56, n55);
  auto n73 = gate_nand(n47, n48);
  y[0] = gate_and(n74, n73);
}
template<> void PilUint<8>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n31 = gate_not(a[0]);
  auto n36 = gate_not(a[4]);
  auto n30 = gate_not(a[1]);
  auto n26 = gate_and(n31, n30);
  auto n33 = gate_not(a[3]);
  auto n32 = gate_not(a[6]);
  auto n28 = gate_and(n33, n32);
  auto n35 = gate_not(a[2]);
  auto n34 = gate_not(a[5]);
  auto n27 = gate_and(n35, n34);
  auto n24 = gate_and(n28, n27);
  auto n37 = gate_not(a[7]);
  auto n29 = gate_and(n37, n36);
  auto n25 = gate_and(n24, n29);
  y[0] = gate_and(n26, n25);
}
template<> void PilUint<8>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n60 = gate_not(a[5]);
  auto n59 = gate_not(a[7]);
  auto n58 = gate_and(n60, n59);
  auto n62 = gate_not(a[6]);
  auto n61 = gate_not(a[4]);
  auto n57 = gate_and(n62, n61);
  auto n50 = gate_and(n58, n57);
  auto n64 = gate_not(b[5]);
  auto n63 = gate_not(b[7]);
  auto n54 = gate_and(n64, n63);
  auto n66 = gate_not(b[6]);
  auto n65 = gate_not(b[4]);
  auto n53 = gate_and(n66, n65);
  auto n48 = gate_and(n54, n53);
  auto n46 = gate_and(n50, n48);
  auto n68 = gate_not(b[1]);
  auto n67 = gate_not(b[3]);
  auto n52 = gate_and(n68, n67);
  auto n70 = gate_not(b[2]);
  auto n69 = gate_not(b[0]);
  auto n51 = gate_and(n70, n69);
  auto n47 = gate_and(n52, n51);
  auto n72 = gate_not(a[1]);
  auto n71 = gate_not(a[3]);
  auto n56 = gate_and(n72, n71);
  auto n74 = gate_not(a[2]);
  auto n73 = gate_not(a[0]);
  auto n55 = gate_and(n74, n73);
  auto n49 = gate_and(n56, n55);
  auto n45 = gate_and(n47, n49);
  y[0] = gate_nand(n46, n45);
}
template<> void PilUint<8>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n41 = gate_not(a[6]);
  auto n70 = gate_nand(n41, b[6]);
  auto n68 = gate_xor(n41, b[6]);
  auto n42 = gate_not(b[1]);
  auto n47 = gate_nand(n42, a[1]);
  auto n45 = gate_xor(n42, a[1]);
  auto n43 = gate_not(a[0]);
  auto n44 = gate_nand(b[0], n43);
  auto n46 = gate_nand(n45, n44);
  auto n48 = gate_nand(n47, n46);
  auto n52 = gate_nand(n48, a[2]);
  auto n50 = gate_xor(n48, a[2]);
  auto n49 = gate_not(b[2]);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n57 = gate_nand(n53, a[3]);
  auto n55 = gate_xor(n53, a[3]);
  auto n54 = gate_not(b[3]);
  auto n56 = gate_nand(n55, n54);
  auto n40 = gate_and(n57, n56);
  auto n61 = gate_nand(n40, b[4]);
  auto n59 = gate_xor(n40, b[4]);
  auto n58 = gate_not(a[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n66 = gate_nand(n62, b[5]);
  auto n64 = gate_xor(n62, b[5]);
  auto n63 = gate_not(a[5]);
  auto n65 = gate_nand(n64, n63);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n75 = gate_nand(n71, b[7]);
  auto n73 = gate_xor(n71, b[7]);
  auto n72 = gate_not(a[7]);
  auto n74 = gate_nand(n73, n72);
  y[0] = gate_nand(n75, n74);
}
template<> void PilUint<8>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n41 = gate_not(a[6]);
  auto n70 = gate_nand(n41, b[6]);
  auto n68 = gate_xor(n41, b[6]);
  auto n42 = gate_not(b[1]);
  auto n47 = gate_nand(n42, a[1]);
  auto n45 = gate_xor(n42, a[1]);
  auto n43 = gate_not(a[0]);
  auto n44 = gate_nand(b[0], n43);
  auto n46 = gate_nand(n45, n44);
  auto n48 = gate_nand(n47, n46);
  auto n52 = gate_nand(n48, a[2]);
  auto n50 = gate_xor(n48, a[2]);
  auto n49 = gate_not(b[2]);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n57 = gate_nand(n53, a[3]);
  auto n55 = gate_xor(n53, a[3]);
  auto n54 = gate_not(b[3]);
  auto n56 = gate_nand(n55, n54);
  auto n40 = gate_and(n57, n56);
  auto n61 = gate_nand(n40, b[4]);
  auto n59 = gate_xor(n40, b[4]);
  auto n58 = gate_not(a[4]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n66 = gate_nand(n62, b[5]);
  auto n64 = gate_xor(n62, b[5]);
  auto n63 = gate_not(a[5]);
  auto n65 = gate_nand(n64, n63);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n75 = gate_nand(n71, a[7]);
  auto n73 = gate_xor(n71, a[7]);
  auto n72 = gate_not(b[7]);
  auto n74 = gate_nand(n73, n72);
  y[0] = gate_nand(n75, n74);
}
template<> void PilUint<8>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n163 = gate_not(b[7]);
  auto n168 = gate_not(b[6]);
  auto n8 = gate_and(n163, n168);
  auto n173 = gate_not(b[5]);
  auto n5 = gate_and(n8, n173);
  auto n178 = gate_not(b[4]);
  auto n4 = gate_and(n5, n178);
  auto n183 = gate_not(b[3]);
  auto n3 = gate_and(n4, n183);
  auto n188 = gate_not(b[2]);
  auto n2 = gate_and(n3, n188);
  auto n191 = gate_not(b[1]);
  auto n6 = gate_and(n2, n191);
  auto n21 = gate_nand(b[0], n6);
  auto n17 = gate_and(a[7], n21);
  auto n22 = gate_mux(a[7], b[0], n191);
  auto n16 = gate_and(n2, n22);
  auto n23 = gate_not(a[6]);
  auto n24 = gate_nand(b[0], n23);
  auto n25 = gate_nand(n16, n24);
  auto n1 = gate_and(n17, n25);
  auto n39 = gate_nand(a[6], n25);
  auto n26 = gate_not(n39);
  auto n29 = gate_nand(n26, n191);
  auto n31 = gate_xor(n191, n39);
  auto n27 = gate_not(n31);
  auto n42 = gate_not(a[5]);
  auto n32 = gate_nand(b[0], n42);
  auto n28 = gate_nand(n27, n32);
  auto n33 = gate_nand(n29, n28);
  auto n34 = gate_xor(n33, n188);
  auto n30 = gate_nand(n3, n34);
  auto n7 = gate_and(n1, n30);
  auto n38 = gate_nand(n32, n31);
  auto n36 = gate_nand(n33, n188);
  auto n35 = gate_nand(n34, n1);
  auto n37 = gate_nand(n36, n35);
  auto n9 = gate_and(n3, n37);
  auto n40 = gate_mux(n39, n38, n9);
  auto n59 = gate_not(n40);
  auto n48 = gate_nand(n188, n59);
  auto n46 = gate_xor(b[2], n40);
  auto n41 = gate_nand(n9, b[0]);
  auto n64 = gate_xor(n42, n41);
  auto n45 = gate_nand(n191, n64);
  auto n43 = gate_xor(n191, n64);
  auto n67 = gate_not(a[4]);
  auto n61 = gate_nand(b[0], n67);
  auto n44 = gate_nand(n43, n61);
  auto n56 = gate_nand(n45, n44);
  auto n47 = gate_nand(n46, n56);
  auto n51 = gate_nand(n48, n47);
  auto n49 = gate_xor(n183, n51);
  auto n50 = gate_nand(n4, n49);
  auto n20 = gate_and(n7, n50);
  auto n52 = gate_xor(n183, n7);
  auto n54 = gate_nand(n52, n51);
  auto n53 = gate_nand(n7, n183);
  auto n55 = gate_nand(n54, n53);
  auto n19 = gate_and(n4, n55);
  auto n57 = gate_xor(n56, n188);
  auto n58 = gate_nand(n19, n57);
  auto n87 = gate_xor(n59, n58);
  auto n60 = gate_not(n87);
  auto n76 = gate_nand(n60, n183);
  auto n74 = gate_xor(b[3], n87);
  auto n62 = gate_xor(n61, n191);
  auto n63 = gate_nand(n19, n62);
  auto n91 = gate_xor(n64, n63);
  auto n65 = gate_not(n91);
  auto n73 = gate_nand(n65, n188);
  auto n71 = gate_xor(b[2], n91);
  auto n66 = gate_nand(n19, b[0]);
  auto n95 = gate_xor(n67, n66);
  auto n70 = gate_nand(n191, n95);
  auto n68 = gate_xor(n191, n95);
  auto n98 = gate_not(a[3]);
  auto n92 = gate_nand(b[0], n98);
  auto n69 = gate_nand(n68, n92);
  auto n88 = gate_nand(n70, n69);
  auto n72 = gate_nand(n71, n88);
  auto n84 = gate_nand(n73, n72);
  auto n75 = gate_nand(n74, n84);
  auto n79 = gate_nand(n76, n75);
  auto n77 = gate_xor(n178, n79);
  auto n78 = gate_nand(n5, n77);
  auto n10 = gate_and(n20, n78);
  auto n80 = gate_xor(n178, n20);
  auto n82 = gate_nand(n80, n79);
  auto n81 = gate_nand(n20, n178);
  auto n83 = gate_nand(n82, n81);
  auto n18 = gate_and(n5, n83);
  auto n85 = gate_xor(n183, n84);
  auto n86 = gate_nand(n18, n85);
  auto n121 = gate_xor(n87, n86);
  auto n110 = gate_nand(n121, n178);
  auto n108 = gate_xor(n178, n121);
  auto n89 = gate_xor(n188, n88);
  auto n90 = gate_nand(n18, n89);
  auto n126 = gate_xor(n91, n90);
  auto n107 = gate_nand(n126, n183);
  auto n105 = gate_xor(n183, n126);
  auto n93 = gate_xor(n92, n191);
  auto n94 = gate_nand(n18, n93);
  auto n131 = gate_xor(n95, n94);
  auto n96 = gate_not(n131);
  auto n104 = gate_nand(n96, n188);
  auto n102 = gate_xor(b[2], n131);
  auto n97 = gate_nand(n18, b[0]);
  auto n135 = gate_xor(n98, n97);
  auto n101 = gate_nand(n191, n135);
  auto n99 = gate_xor(n191, n135);
  auto n138 = gate_not(a[2]);
  auto n132 = gate_nand(b[0], n138);
  auto n100 = gate_nand(n99, n132);
  auto n128 = gate_nand(n101, n100);
  auto n103 = gate_nand(n102, n128);
  auto n123 = gate_nand(n104, n103);
  auto n106 = gate_nand(n105, n123);
  auto n118 = gate_nand(n107, n106);
  auto n109 = gate_nand(n108, n118);
  auto n113 = gate_nand(n110, n109);
  auto n111 = gate_xor(n173, n113);
  auto n112 = gate_nand(n8, n111);
  auto n156 = gate_nand(n10, n112);
  auto n159 = gate_not(n156);
  auto n114 = gate_xor(n173, n10);
  auto n116 = gate_nand(n114, n113);
  auto n115 = gate_nand(n10, n173);
  auto n117 = gate_nand(n116, n115);
  auto n15 = gate_and(n8, n117);
  auto n119 = gate_xor(n178, n118);
  auto n120 = gate_nand(n15, n119);
  auto n167 = gate_xor(n121, n120);
  auto n122 = gate_not(n167);
  auto n153 = gate_nand(n122, n173);
  auto n151 = gate_xor(b[5], n167);
  auto n124 = gate_xor(n183, n123);
  auto n125 = gate_nand(n15, n124);
  auto n172 = gate_xor(n126, n125);
  auto n127 = gate_not(n172);
  auto n150 = gate_nand(n127, n178);
  auto n148 = gate_xor(b[4], n172);
  auto n129 = gate_xor(n188, n128);
  auto n130 = gate_nand(n15, n129);
  auto n177 = gate_xor(n131, n130);
  auto n147 = gate_nand(n177, n183);
  auto n145 = gate_xor(n183, n177);
  auto n133 = gate_xor(n132, n191);
  auto n134 = gate_nand(n15, n133);
  auto n182 = gate_xor(n135, n134);
  auto n136 = gate_not(n182);
  auto n144 = gate_nand(n136, n188);
  auto n142 = gate_xor(b[2], n182);
  auto n137 = gate_nand(n15, b[0]);
  auto n187 = gate_xor(n138, n137);
  auto n141 = gate_nand(n191, n187);
  auto n139 = gate_xor(n191, n187);
  auto n190 = gate_not(a[1]);
  auto n184 = gate_nand(b[0], n190);
  auto n140 = gate_nand(n139, n184);
  auto n179 = gate_nand(n141, n140);
  auto n143 = gate_nand(n142, n179);
  auto n174 = gate_nand(n144, n143);
  auto n146 = gate_nand(n145, n174);
  auto n169 = gate_nand(n147, n146);
  auto n149 = gate_nand(n148, n169);
  auto n164 = gate_nand(n150, n149);
  auto n152 = gate_nand(n151, n164);
  auto n157 = gate_nand(n153, n152);
  auto n154 = gate_xor(n168, n157);
  auto n155 = gate_nand(n154, n163);
  auto n13 = gate_and(n159, n155);
  auto n207 = gate_nand(n13, n163);
  auto n204 = gate_nand(b[7], n156);
  auto n158 = gate_xor(n168, n159);
  auto n161 = gate_nand(n158, n157);
  auto n160 = gate_nand(n159, n168);
  auto n162 = gate_nand(n161, n160);
  auto n12 = gate_and(n163, n162);
  auto n165 = gate_xor(n173, n164);
  auto n166 = gate_nand(n12, n165);
  auto n215 = gate_xor(n167, n166);
  auto n203 = gate_nand(n215, n168);
  auto n212 = gate_xor(n168, n215);
  auto n170 = gate_xor(n178, n169);
  auto n171 = gate_nand(n12, n170);
  auto n219 = gate_xor(n172, n171);
  auto n201 = gate_nand(n219, n173);
  auto n216 = gate_xor(n173, n219);
  auto n175 = gate_xor(n183, n174);
  auto n176 = gate_nand(n12, n175);
  auto n14 = gate_xnor(n177, n176);
  auto n199 = gate_nand(n14, n178);
  auto n220 = gate_xor(n178, n14);
  auto n180 = gate_xor(n188, n179);
  auto n181 = gate_nand(n12, n180);
  auto n226 = gate_xor(n182, n181);
  auto n197 = gate_nand(n226, n183);
  auto n223 = gate_xor(n183, n226);
  auto n185 = gate_xor(n184, n191);
  auto n186 = gate_nand(n12, n185);
  auto n11 = gate_xnor(n187, n186);
  auto n195 = gate_nand(n11, n188);
  auto n227 = gate_xor(n188, n11);
  auto n189 = gate_nand(n12, b[0]);
  auto n233 = gate_xor(n190, n189);
  auto n193 = gate_nand(n191, n233);
  auto n231 = gate_xor(n191, n233);
  auto n236 = gate_not(a[0]);
  auto n230 = gate_nand(b[0], n236);
  auto n192 = gate_nand(n231, n230);
  auto n228 = gate_nand(n193, n192);
  auto n194 = gate_nand(n227, n228);
  auto n224 = gate_nand(n195, n194);
  auto n196 = gate_nand(n223, n224);
  auto n221 = gate_nand(n197, n196);
  auto n198 = gate_nand(n220, n221);
  auto n217 = gate_nand(n199, n198);
  auto n200 = gate_nand(n216, n217);
  auto n213 = gate_nand(n201, n200);
  auto n202 = gate_nand(n212, n213);
  auto n208 = gate_nand(n203, n202);
  auto n205 = gate_nand(n204, n208);
  auto n234 = gate_nand(n207, n205);
  auto n206 = gate_not(n234);
  auto n211 = gate_nand(n13, n206);
  auto n209 = gate_not(n207);
  auto n210 = gate_nand(n209, n208);
  y[7] = gate_nand(n211, n210);
  auto n214 = gate_xor(n213, n212);
  y[6] = gate_mux(n215, n214, n234);
  auto n218 = gate_xor(n217, n216);
  y[5] = gate_mux(n219, n218, n234);
  auto n222 = gate_xor(n221, n220);
  y[4] = gate_mux(n14, n222, n234);
  auto n225 = gate_xor(n224, n223);
  y[3] = gate_mux(n226, n225, n234);
  auto n229 = gate_xor(n228, n227);
  y[2] = gate_mux(n11, n229, n234);
  auto n232 = gate_xor(n231, n230);
  y[1] = gate_mux(n233, n232, n234);
  auto n235 = gate_nand(n234, b[0]);
  y[0] = gate_xor(n236, n235);
}
template<> void PilUint<8>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n25 = gate_not(a[1]);
  auto n255 = gate_not(a[0]);
  auto n27 = gate_nand(n25, n255);
  auto n26 = gate_nand(a[7], n27);
  auto n151 = gate_xor(a[2], n26);
  auto n201 = gate_not(b[7]);
  auto n259 = gate_xnor(n201, b[1]);
  auto n3 = gate_not(n259);
  auto n210 = gate_xor(b[6], n201);
  auto n275 = gate_xor(b[5], n201);
  auto n24 = gate_and(n275, n210);
  auto n216 = gate_not(n275);
  auto n29 = gate_not(n27);
  auto n28 = gate_not(a[2]);
  auto n89 = gate_nand(n29, n28);
  auto n31 = gate_not(n89);
  auto n30 = gate_not(a[3]);
  auto n67 = gate_nand(n31, n30);
  auto n33 = gate_not(n67);
  auto n32 = gate_not(a[4]);
  auto n35 = gate_nand(n33, n32);
  auto n34 = gate_nand(a[7], n35);
  auto n61 = gate_xor(a[5], n34);
  auto n269 = gate_xor(b[4], n201);
  auto n1 = gate_not(n269);
  auto n2 = gate_not(n1);
  auto n16 = gate_and(n24, n2);
  auto n228 = gate_xor(b[7], b[3]);
  auto n263 = gate_not(n228);
  auto n14 = gate_and(n16, n263);
  auto n231 = gate_xor(b[7], b[2]);
  auto n229 = gate_not(n231);
  auto n13 = gate_and(n14, n229);
  auto n15 = gate_and(n13, n3);
  auto n37 = gate_not(n35);
  auto n36 = gate_not(a[5]);
  auto n41 = gate_nand(n37, n36);
  auto n38 = gate_nand(a[7], n41);
  auto n43 = gate_xor(a[6], n38);
  auto n48 = gate_not(n43);
  auto n40 = gate_not(a[6]);
  auto n39 = gate_nand(b[0], n15);
  auto n18 = gate_and(n40, n39);
  auto n42 = gate_not(n41);
  auto n4 = gate_and(n42, a[7]);
  auto n17 = gate_and(n18, n4);
  auto n45 = gate_xor(n17, n3);
  auto n44 = gate_nand(n43, b[0]);
  auto n5 = gate_and(n13, n44);
  auto n55 = gate_nand(n45, n5);
  auto n23 = gate_and(n17, n55);
  auto n46 = gate_not(n55);
  auto n47 = gate_nand(n46, b[0]);
  auto n65 = gate_nand(n48, n47);
  auto n49 = gate_not(n65);
  auto n53 = gate_nand(n49, n3);
  auto n62 = gate_xor(n3, n65);
  auto n51 = gate_not(n62);
  auto n50 = gate_mux(b[7], n61, b[0]);
  auto n63 = gate_not(n50);
  auto n52 = gate_nand(n51, n63);
  auto n54 = gate_nand(n53, n52);
  auto n57 = gate_nand(n229, n54);
  auto n76 = gate_xor(n229, n54);
  auto n56 = gate_nand(n76, n23);
  auto n58 = gate_nand(n57, n56);
  auto n64 = gate_nand(n14, n58);
  auto n59 = gate_not(n64);
  auto n60 = gate_nand(n59, b[0]);
  auto n84 = gate_xor(n61, n60);
  auto n66 = gate_nand(n63, n62);
  auto n102 = gate_mux(n66, n65, n64);
  auto n98 = gate_not(n102);
  auto n75 = gate_nand(n229, n98);
  auto n73 = gate_xor(n229, n98);
  auto n72 = gate_nand(n84, n3);
  auto n70 = gate_xor(n84, n3);
  auto n68 = gate_nand(a[7], n67);
  auto n88 = gate_xor(a[4], n68);
  auto n69 = gate_mux(b[7], n88, b[0]);
  auto n81 = gate_not(n69);
  auto n71 = gate_nand(n70, n81);
  auto n100 = gate_nand(n72, n71);
  auto n74 = gate_nand(n73, n100);
  auto n110 = gate_nand(n75, n74);
  auto n79 = gate_nand(n110, n263);
  auto n77 = gate_nand(n14, n76);
  auto n12 = gate_and(n23, n77);
  auto n78 = gate_nand(n12, n263);
  auto n80 = gate_nand(n79, n78);
  auto n101 = gate_nand(n80, n16);
  auto n86 = gate_not(n101);
  auto n82 = gate_xor(n3, n81);
  auto n83 = gate_nand(n86, n82);
  auto n122 = gate_xor(n84, n83);
  auto n85 = gate_not(n122);
  auto n97 = gate_nand(n85, n229);
  auto n95 = gate_xor(n229, n85);
  auto n87 = gate_nand(n86, b[0]);
  auto n126 = gate_xor(n88, n87);
  auto n94 = gate_nand(n126, n3);
  auto n92 = gate_xor(n126, n3);
  auto n90 = gate_nand(a[7], n89);
  auto n130 = gate_xor(a[3], n90);
  auto n91 = gate_mux(b[7], n130, b[0]);
  auto n123 = gate_not(n91);
  auto n93 = gate_nand(n92, n123);
  auto n119 = gate_nand(n94, n93);
  auto n96 = gate_nand(n95, n119);
  auto n106 = gate_nand(n97, n96);
  auto n99 = gate_xor(n231, n98);
  auto n103 = gate_nand(n100, n99);
  auto n116 = gate_mux(n103, n102, n101);
  auto n105 = gate_not(n116);
  auto n104 = gate_xor(n228, n105);
  auto n117 = gate_nand(n106, n104);
  auto n109 = gate_nand(n105, n263);
  auto n107 = gate_xor(n105, n263);
  auto n108 = gate_nand(n107, n106);
  auto n144 = gate_nand(n109, n108);
  auto n114 = gate_nand(n269, n144);
  auto n111 = gate_xor(n263, n110);
  auto n112 = gate_nand(n16, n111);
  auto n7 = gate_and(n12, n112);
  auto n113 = gate_nand(n7, n2);
  auto n115 = gate_nand(n114, n113);
  auto n118 = gate_nand(n24, n115);
  auto n159 = gate_mux(n117, n116, n118);
  auto n155 = gate_not(n159);
  auto n143 = gate_nand(n155, n2);
  auto n141 = gate_xor(n155, n2);
  auto n128 = gate_not(n118);
  auto n120 = gate_xor(n229, n119);
  auto n121 = gate_nand(n128, n120);
  auto n161 = gate_xor(n122, n121);
  auto n140 = gate_nand(n161, n263);
  auto n138 = gate_xor(n263, n161);
  auto n124 = gate_xor(n3, n123);
  auto n125 = gate_nand(n128, n124);
  auto n169 = gate_xor(n126, n125);
  auto n127 = gate_not(n169);
  auto n137 = gate_nand(n127, n229);
  auto n135 = gate_xor(n229, n127);
  auto n129 = gate_nand(n128, b[0]);
  auto n170 = gate_xor(n130, n129);
  auto n134 = gate_nand(n170, n3);
  auto n132 = gate_xor(n170, n3);
  auto n131 = gate_mux(b[7], n151, b[0]);
  auto n171 = gate_not(n131);
  auto n133 = gate_nand(n132, n171);
  auto n166 = gate_nand(n134, n133);
  auto n136 = gate_nand(n135, n166);
  auto n162 = gate_nand(n137, n136);
  auto n139 = gate_nand(n138, n162);
  auto n157 = gate_nand(n140, n139);
  auto n142 = gate_nand(n141, n157);
  auto n152 = gate_nand(n143, n142);
  auto n148 = gate_nand(n275, n152);
  auto n145 = gate_xor(n2, n144);
  auto n146 = gate_nand(n24, n145);
  auto n20 = gate_and(n7, n146);
  auto n147 = gate_nand(n20, n275);
  auto n149 = gate_nand(n148, n147);
  auto n158 = gate_nand(n210, n149);
  auto n173 = gate_not(n158);
  auto n150 = gate_nand(n173, b[0]);
  auto n198 = gate_xor(n151, n150);
  auto n153 = gate_xor(n275, n152);
  auto n154 = gate_nand(n153, n210);
  auto n6 = gate_and(n20, n154);
  auto n194 = gate_nand(n6, n210);
  auto n156 = gate_xor(n1, n155);
  auto n160 = gate_nand(n157, n156);
  auto n209 = gate_mux(n160, n159, n158);
  auto n205 = gate_not(n209);
  auto n192 = gate_nand(n205, n275);
  auto n190 = gate_xor(n205, n275);
  auto n165 = gate_not(n161);
  auto n163 = gate_xor(n263, n162);
  auto n164 = gate_nand(n173, n163);
  auto n214 = gate_xor(n165, n164);
  auto n189 = gate_nand(n214, n2);
  auto n187 = gate_xor(n2, n214);
  auto n167 = gate_xor(n229, n166);
  auto n168 = gate_nand(n173, n167);
  auto n220 = gate_xor(n169, n168);
  auto n186 = gate_nand(n220, n263);
  auto n184 = gate_xor(n263, n220);
  auto n175 = gate_not(n170);
  auto n172 = gate_xor(n3, n171);
  auto n174 = gate_nand(n173, n172);
  auto n226 = gate_xor(n175, n174);
  auto n183 = gate_nand(n226, n229);
  auto n181 = gate_xor(n229, n226);
  auto n180 = gate_nand(n198, n3);
  auto n178 = gate_xor(n198, n3);
  auto n176 = gate_nand(a[7], a[0]);
  auto n200 = gate_xor(a[1], n176);
  auto n177 = gate_mux(b[7], n200, b[0]);
  auto n195 = gate_not(n177);
  auto n179 = gate_nand(n178, n195);
  auto n222 = gate_nand(n180, n179);
  auto n182 = gate_nand(n181, n222);
  auto n217 = gate_nand(n183, n182);
  auto n185 = gate_nand(n184, n217);
  auto n211 = gate_nand(n186, n185);
  auto n188 = gate_nand(n187, n211);
  auto n207 = gate_nand(n189, n188);
  auto n191 = gate_nand(n190, n207);
  auto n248 = gate_nand(n192, n191);
  auto n281 = gate_not(n210);
  auto n193 = gate_nand(n248, n210);
  auto n223 = gate_nand(n194, n193);
  auto n196 = gate_xor(n3, n195);
  auto n197 = gate_nand(n223, n196);
  auto n253 = gate_xor(n198, n197);
  auto n199 = gate_nand(b[0], n223);
  auto n262 = gate_xor(n200, n199);
  auto n204 = gate_nand(n262, n3);
  auto n202 = gate_xor(n262, n3);
  auto n258 = gate_mux(n201, a[0], b[0]);
  auto n203 = gate_nand(n202, n258);
  auto n232 = gate_nand(n204, n203);
  auto n251 = gate_xor(n232, n229);
  auto n206 = gate_xor(n205, n216);
  auto n208 = gate_nand(n207, n206);
  auto n287 = gate_mux(n209, n208, n223);
  auto n282 = gate_not(n287);
  auto n247 = gate_nand(n282, n210);
  auto n245 = gate_xor(n282, n210);
  auto n212 = gate_xor(n211, n2);
  auto n213 = gate_nand(n212, n223);
  auto n279 = gate_xor(n214, n213);
  auto n215 = gate_not(n279);
  auto n244 = gate_nand(n215, n275);
  auto n242 = gate_xor(n216, n279);
  auto n218 = gate_xor(n217, n263);
  auto n219 = gate_nand(n218, n223);
  auto n273 = gate_xor(n220, n219);
  auto n221 = gate_not(n273);
  auto n241 = gate_nand(n221, n2);
  auto n239 = gate_xor(n1, n273);
  auto n224 = gate_xor(n222, n229);
  auto n225 = gate_nand(n224, n223);
  auto n267 = gate_xor(n226, n225);
  auto n227 = gate_not(n267);
  auto n238 = gate_nand(n227, n263);
  auto n236 = gate_xor(n228, n267);
  auto n230 = gate_not(n253);
  auto n235 = gate_nand(n230, n229);
  auto n233 = gate_xor(n231, n253);
  auto n234 = gate_nand(n233, n232);
  auto n264 = gate_nand(n235, n234);
  auto n237 = gate_nand(n236, n264);
  auto n270 = gate_nand(n238, n237);
  auto n240 = gate_nand(n239, n270);
  auto n276 = gate_nand(n241, n240);
  auto n243 = gate_nand(n242, n276);
  auto n284 = gate_nand(n244, n243);
  auto n246 = gate_nand(n245, n284);
  auto n290 = gate_nand(n247, n246);
  auto n250 = gate_not(n290);
  auto n249 = gate_mux(n281, n210, n248);
  auto n289 = gate_nand(n6, n249);
  auto n285 = gate_nand(n250, n289);
  auto n252 = gate_nand(n251, n285);
  auto n254 = gate_xor(n253, n252);
  auto n298 = gate_xor(a[7], n254);
  auto n257 = gate_xor(a[7], n255);
  auto n256 = gate_nand(b[0], n285);
  auto n302 = gate_xor(n257, n256);
  y[0] = gate_xor(a[7], n302);
  auto n10 = gate_and(a[7], n302);
  auto n260 = gate_xor(n3, n258);
  auto n261 = gate_nand(n285, n260);
  auto n301 = gate_xor(n262, n261);
  auto n22 = gate_and(n10, n301);
  auto n11 = gate_and(n298, n22);
  auto n265 = gate_xor(n264, n263);
  auto n266 = gate_nand(n265, n285);
  auto n268 = gate_xor(n267, n266);
  auto n297 = gate_xor(a[7], n268);
  auto n19 = gate_and(n11, n297);
  auto n271 = gate_xor(n270, n2);
  auto n272 = gate_nand(n271, n285);
  auto n274 = gate_xor(n273, n272);
  auto n296 = gate_xor(a[7], n274);
  auto n9 = gate_and(n19, n296);
  auto n277 = gate_xor(n276, n275);
  auto n278 = gate_nand(n277, n285);
  auto n280 = gate_xor(n279, n278);
  auto n295 = gate_xor(a[7], n280);
  auto n21 = gate_and(n9, n295);
  auto n283 = gate_xor(n282, n281);
  auto n286 = gate_nand(n284, n283);
  auto n288 = gate_mux(n287, n286, n285);
  auto n8 = gate_xnor(a[7], n288);
  auto n294 = gate_nand(n21, n8);
  auto n291 = gate_not(n289);
  auto n292 = gate_nand(n291, n290);
  auto n293 = gate_nand(a[7], n292);
  y[7] = gate_xor(n294, n293);
  y[6] = gate_xor(n21, n8);
  y[5] = gate_xor(n9, n295);
  y[4] = gate_xor(n19, n296);
  y[3] = gate_xor(n11, n297);
  y[2] = gate_xor(n298, n22);
  auto n299 = gate_not(n302);
  auto n300 = gate_nand(a[7], n299);
  y[1] = gate_xor(n301, n300);
}
template<> void PilUint<8>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_and(b[0], a[6]);
  auto n3 = gate_and(b[1], a[4]);
  auto n4 = gate_and(b[0], a[4]);
  auto n5 = gate_and(a[2], b[1]);
  auto n7 = gate_and(b[1], a[1]);
  auto n8 = gate_and(b[0], a[1]);
  auto n9 = gate_and(b[1], a[0]);
  y[0] = gate_and(b[0], a[0]);
  y[1] = gate_xor(n8, n9);
  auto n17 = gate_nand(n8, n9);
  auto n11 = gate_not(n17);
  auto n12 = gate_nand(a[0], b[2]);
  auto n16 = gate_xor(n7, n12);
  auto n15 = gate_nand(a[2], b[0]);
  auto n18 = gate_xor(n16, n15);
  y[2] = gate_xor(n11, n18);
  auto n24 = gate_nand(a[1], b[2]);
  auto n25 = gate_nand(b[3], a[0]);
  auto n14 = gate_xor(n24, n25);
  auto n13 = gate_not(n12);
  auto n29 = gate_nand(n7, n13);
  auto n33 = gate_xor(n14, n29);
  auto n21 = gate_not(n33);
  auto n20 = gate_nand(n16, n15);
  auto n19 = gate_nand(n18, n17);
  auto n32 = gate_nand(n20, n19);
  auto n22 = gate_nand(a[3], b[0]);
  auto n31 = gate_xor(n5, n22);
  auto n34 = gate_xor(n32, n31);
  y[3] = gate_xor(n21, n34);
  auto n23 = gate_not(n22);
  auto n47 = gate_nand(n5, n23);
  auto n27 = gate_not(n24);
  auto n26 = gate_not(n25);
  auto n28 = gate_nand(n27, n26);
  auto n48 = gate_nand(n29, n28);
  auto n55 = gate_nand(a[3], b[1]);
  auto n49 = gate_xor(n4, n55);
  auto n30 = gate_xor(n48, n49);
  auto n40 = gate_xor(n47, n30);
  auto n38 = gate_not(n40);
  auto n36 = gate_nand(n32, n31);
  auto n35 = gate_nand(n34, n33);
  auto n39 = gate_nand(n36, n35);
  auto n41 = gate_not(n39);
  auto n59 = gate_nand(b[3], a[1]);
  auto n58 = gate_nand(b[4], a[0]);
  auto n61 = gate_xor(n59, n58);
  auto n60 = gate_nand(a[2], b[2]);
  auto n43 = gate_xor(n61, n60);
  auto n37 = gate_xor(n41, n43);
  y[4] = gate_xor(n38, n37);
  auto n45 = gate_nand(n39, n38);
  auto n42 = gate_nand(n41, n40);
  auto n44 = gate_nand(n43, n42);
  auto n93 = gate_nand(n45, n44);
  auto n46 = gate_not(n49);
  auto n54 = gate_nand(n46, n48);
  auto n52 = gate_not(n47);
  auto n50 = gate_not(n48);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n2 = gate_and(n54, n53);
  auto n95 = gate_xor(n93, n2);
  auto n73 = gate_nand(b[0], a[5]);
  auto n80 = gate_xor(n73, n3);
  auto n56 = gate_not(n55);
  auto n79 = gate_nand(n4, n56);
  auto n78 = gate_nand(a[3], b[2]);
  auto n81 = gate_xor(n79, n78);
  auto n70 = gate_xor(n80, n81);
  auto n85 = gate_nand(b[5], a[0]);
  auto n89 = gate_nand(b[3], a[2]);
  auto n84 = gate_nand(b[4], a[1]);
  auto n57 = gate_xor(n89, n84);
  auto n65 = gate_xor(n85, n57);
  auto n63 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n66 = gate_nand(n63, n62);
  auto n64 = gate_xor(n65, n66);
  auto n94 = gate_xor(n70, n64);
  y[5] = gate_xnor(n95, n94);
  auto n72 = gate_nand(n65, n66);
  auto n68 = gate_not(n65);
  auto n67 = gate_not(n66);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n130 = gate_nand(n72, n71);
  auto n74 = gate_not(n73);
  auto n155 = gate_nand(n74, n3);
  auto n154 = gate_nand(b[3], a[3]);
  auto n156 = gate_nand(a[2], b[4]);
  auto n75 = gate_xor(n154, n156);
  auto n132 = gate_xor(n155, n75);
  auto n118 = gate_nand(a[4], b[2]);
  auto n117 = gate_nand(a[1], b[5]);
  auto n119 = gate_nand(a[0], b[6]);
  auto n76 = gate_xor(n117, n119);
  auto n131 = gate_xor(n118, n76);
  auto n77 = gate_xor(n132, n131);
  auto n104 = gate_xor(n130, n77);
  auto n83 = gate_nand(n79, n78);
  auto n82 = gate_nand(n81, n80);
  auto n143 = gate_nand(n83, n82);
  auto n91 = gate_nand(n84, n85);
  auto n87 = gate_not(n84);
  auto n86 = gate_not(n85);
  auto n88 = gate_nand(n87, n86);
  auto n90 = gate_nand(n89, n88);
  auto n146 = gate_nand(n91, n90);
  auto n92 = gate_nand(b[1], a[5]);
  auto n145 = gate_xor(n1, n92);
  auto n144 = gate_xor(n146, n145);
  auto n100 = gate_xor(n143, n144);
  auto n97 = gate_nand(n2, n93);
  auto n96 = gate_nand(n95, n94);
  auto n99 = gate_nand(n97, n96);
  auto n102 = gate_not(n99);
  auto n98 = gate_xor(n100, n102);
  y[6] = gate_xor(n104, n98);
  auto n106 = gate_nand(n100, n99);
  auto n101 = gate_not(n100);
  auto n103 = gate_nand(n102, n101);
  auto n105 = gate_nand(n104, n103);
  auto n125 = gate_nand(n106, n105);
  auto n108 = gate_nand(a[6], b[1]);
  auto n107 = gate_nand(a[7], b[0]);
  auto n113 = gate_xor(n108, n107);
  auto n110 = gate_not(b[2]);
  auto n109 = gate_nand(b[1], n1);
  auto n111 = gate_xor(n110, n109);
  auto n112 = gate_nand(a[5], n111);
  auto n123 = gate_xor(n113, n112);
  auto n115 = gate_not(n119);
  auto n114 = gate_not(n118);
  auto n116 = gate_nand(n115, n114);
  auto n121 = gate_nand(n117, n116);
  auto n120 = gate_nand(n119, n118);
  auto n122 = gate_nand(n121, n120);
  auto n124 = gate_xor(n123, n122);
  auto n127 = gate_xor(n125, n124);
  auto n126 = gate_nand(b[6], a[1]);
  auto n138 = gate_xor(n127, n126);
  auto n129 = gate_not(n132);
  auto n128 = gate_not(n131);
  auto n136 = gate_nand(n129, n128);
  auto n134 = gate_not(n130);
  auto n133 = gate_nand(n132, n131);
  auto n135 = gate_nand(n134, n133);
  auto n137 = gate_nand(n136, n135);
  auto n164 = gate_xor(n138, n137);
  auto n140 = gate_nand(b[5], a[2]);
  auto n139 = gate_nand(b[4], a[3]);
  auto n162 = gate_xor(n140, n139);
  auto n142 = gate_nand(b[7], a[0]);
  auto n141 = gate_nand(a[4], b[3]);
  auto n150 = gate_xor(n142, n141);
  auto n148 = gate_nand(n144, n143);
  auto n147 = gate_nand(n146, n145);
  auto n149 = gate_nand(n148, n147);
  auto n160 = gate_xor(n150, n149);
  auto n152 = gate_not(n156);
  auto n151 = gate_not(n155);
  auto n153 = gate_nand(n152, n151);
  auto n158 = gate_nand(n154, n153);
  auto n157 = gate_nand(n156, n155);
  auto n159 = gate_nand(n158, n157);
  auto n161 = gate_xor(n160, n159);
  auto n163 = gate_xor(n162, n161);
  y[7] = gate_xor(n164, n163);
}
template<> void PilUint<8>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n14 = gate_and(a[5], a[7]);
  auto n18 = gate_and(a[2], a[0]);
  auto n19 = gate_and(a[1], a[3]);
  auto n16 = gate_and(n19, n18);
  auto n20 = gate_and(a[6], a[4]);
  auto n17 = gate_and(n14, n20);
  y[0] = gate_and(n16, n17);
}
template<> void PilUint<8>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n14 = gate_and(a[5], a[7]);
  auto n17 = gate_and(a[2], a[0]);
  auto n18 = gate_and(a[1], a[3]);
  auto n15 = gate_and(n18, n17);
  auto n19 = gate_and(a[6], a[4]);
  auto n16 = gate_and(n14, n19);
  y[0] = gate_nand(n15, n16);
}
template<> void PilUint<8>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n31 = gate_not(a[0]);
  auto n36 = gate_not(a[4]);
  auto n30 = gate_not(a[1]);
  auto n26 = gate_and(n31, n30);
  auto n33 = gate_not(a[3]);
  auto n32 = gate_not(a[6]);
  auto n28 = gate_and(n33, n32);
  auto n35 = gate_not(a[2]);
  auto n34 = gate_not(a[5]);
  auto n27 = gate_and(n35, n34);
  auto n24 = gate_and(n28, n27);
  auto n37 = gate_not(a[7]);
  auto n29 = gate_and(n37, n36);
  auto n25 = gate_and(n24, n29);
  y[0] = gate_and(n26, n25);
}
template<> void PilUint<8>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n28 = gate_not(a[1]);
  auto n27 = gate_not(a[3]);
  auto n24 = gate_and(n28, n27);
  auto n30 = gate_not(a[2]);
  auto n29 = gate_not(a[0]);
  auto n23 = gate_and(n30, n29);
  auto n21 = gate_and(n24, n23);
  auto n32 = gate_not(a[5]);
  auto n31 = gate_not(a[7]);
  auto n26 = gate_and(n32, n31);
  auto n34 = gate_not(a[6]);
  auto n33 = gate_not(a[4]);
  auto n25 = gate_and(n34, n33);
  auto n22 = gate_and(n26, n25);
  y[0] = gate_nand(n21, n22);
}
template<> void PilUint<8>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n11 = gate_xor(a[0], a[1]);
  auto n14 = gate_xor(a[7], a[6]);
  auto n10 = gate_xor(a[2], a[3]);
  auto n13 = gate_xor(n11, n10);
  auto n12 = gate_xor(a[4], a[5]);
  auto n15 = gate_xor(n13, n12);
  y[0] = gate_xnor(n15, n14);
}
template<> void PilUint<8>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n8 = gate_xor(a[0], a[1]);
  auto n7 = gate_xor(a[2], a[3]);
  auto n12 = gate_xor(n8, n7);
  auto n10 = gate_xor(a[4], a[5]);
  auto n9 = gate_xor(a[7], a[6]);
  auto n11 = gate_xor(n10, n9);
  y[0] = gate_xor(n12, n11);
}
template<> void PilUint<8>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n66 = gate_not(b[3]);
  auto n65 = gate_not(b[4]);
  auto n58 = gate_and(n66, n65);
  auto n68 = gate_not(b[5]);
  auto n67 = gate_not(b[6]);
  auto n53 = gate_and(n68, n67);
  auto n50 = gate_and(n58, n53);
  auto n69 = gate_not(b[7]);
  auto n54 = gate_and(n50, n69);
  auto n64 = gate_and(b[2], n54);
  auto n88 = gate_not(b[2]);
  auto n52 = gate_and(n54, n88);
  auto n70 = gate_mux(a[7], a[5], b[1]);
  auto n73 = gate_nand(n52, n70);
  auto n71 = gate_mux(a[6], a[4], b[1]);
  auto n72 = gate_nand(n52, n71);
  auto n76 = gate_mux(n73, n72, b[0]);
  auto n74 = gate_mux(a[3], a[2], b[0]);
  auto n106 = gate_mux(a[1], a[0], b[0]);
  auto n103 = gate_mux(n74, n106, b[1]);
  y[3] = gate_and(n52, n103);
  auto n75 = gate_nand(n64, n103);
  y[7] = gate_nand(n76, n75);
  auto n77 = gate_mux(a[6], a[5], b[0]);
  auto n99 = gate_mux(a[4], a[3], b[0]);
  auto n78 = gate_mux(n77, n99, b[1]);
  auto n81 = gate_nand(n52, n78);
  auto n98 = gate_mux(a[2], a[1], b[0]);
  auto n79 = gate_not(b[0]);
  auto n59 = gate_and(a[0], n79);
  auto n104 = gate_mux(n98, n59, b[1]);
  y[2] = gate_and(n52, n104);
  auto n80 = gate_nand(n104, n64);
  y[6] = gate_nand(n81, n80);
  auto n105 = gate_not(b[1]);
  auto n51 = gate_and(n52, n105);
  auto n55 = gate_and(n59, n105);
  y[0] = gate_and(n51, n59);
  y[1] = gate_and(n51, n106);
  auto n82 = gate_not(a[5]);
  auto n83 = gate_nand(n105, n82);
  auto n86 = gate_mux(a[1], n83, n88);
  auto n84 = gate_not(a[3]);
  auto n85 = gate_nand(b[1], n84);
  auto n94 = gate_nand(n86, n85);
  auto n87 = gate_not(a[4]);
  auto n89 = gate_nand(n87, n105);
  auto n92 = gate_mux(a[0], n89, n88);
  auto n90 = gate_not(a[2]);
  auto n91 = gate_nand(b[1], n90);
  auto n93 = gate_nand(n92, n91);
  auto n95 = gate_mux(n94, n93, b[0]);
  auto n96 = gate_not(n95);
  auto n56 = gate_and(n54, n96);
  auto n97 = gate_nand(b[2], b[1]);
  y[5] = gate_and(n56, n97);
  auto n100 = gate_mux(n99, n98, b[1]);
  auto n102 = gate_nand(n52, n100);
  auto n101 = gate_nand(n64, n55);
  y[4] = gate_nand(n102, n101);
}
template<> void PilUint<8>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n66 = gate_not(b[3]);
  auto n65 = gate_not(b[4]);
  auto n52 = gate_and(n66, n65);
  auto n68 = gate_not(b[5]);
  auto n67 = gate_not(b[6]);
  auto n53 = gate_and(n68, n67);
  auto n50 = gate_and(n52, n53);
  auto n69 = gate_not(b[7]);
  auto n54 = gate_and(n50, n69);
  auto n61 = gate_and(b[2], n54);
  auto n85 = gate_not(b[2]);
  auto n51 = gate_and(n54, n85);
  auto n84 = gate_not(b[1]);
  auto n58 = gate_and(n51, n84);
  auto n70 = gate_not(b[0]);
  auto n64 = gate_and(a[7], n70);
  auto n55 = gate_and(n64, n84);
  y[7] = gate_and(n58, n64);
  auto n71 = gate_mux(a[6], a[7], b[0]);
  y[6] = gate_and(n58, n71);
  auto n73 = gate_mux(a[5], a[6], b[0]);
  auto n98 = gate_mux(n73, n64, b[1]);
  y[5] = gate_and(n51, n98);
  auto n72 = gate_mux(a[4], a[5], b[0]);
  auto n104 = gate_mux(n72, n71, b[1]);
  y[4] = gate_and(n51, n104);
  auto n74 = gate_mux(a[3], a[4], b[0]);
  auto n75 = gate_mux(n74, n73, b[1]);
  auto n77 = gate_nand(n51, n75);
  auto n76 = gate_nand(n61, n55);
  y[3] = gate_nand(n77, n76);
  auto n78 = gate_not(a[2]);
  auto n79 = gate_nand(n84, n78);
  auto n82 = gate_mux(a[6], n79, n85);
  auto n80 = gate_not(a[4]);
  auto n81 = gate_nand(b[1], n80);
  auto n91 = gate_nand(n82, n81);
  auto n83 = gate_not(a[3]);
  auto n86 = gate_nand(n84, n83);
  auto n89 = gate_mux(a[7], n86, n85);
  auto n87 = gate_not(a[5]);
  auto n88 = gate_nand(b[1], n87);
  auto n90 = gate_nand(n89, n88);
  auto n92 = gate_mux(n91, n90, b[0]);
  auto n93 = gate_not(n92);
  auto n59 = gate_and(n54, n93);
  auto n94 = gate_nand(b[1], b[2]);
  y[2] = gate_and(n59, n94);
  auto n95 = gate_mux(a[1], a[3], b[1]);
  auto n102 = gate_nand(n51, n95);
  auto n96 = gate_mux(a[2], a[4], b[1]);
  auto n97 = gate_nand(n51, n96);
  auto n100 = gate_mux(n102, n97, b[0]);
  auto n99 = gate_nand(n98, n61);
  y[1] = gate_nand(n100, n99);
  auto n101 = gate_mux(a[0], a[2], b[1]);
  auto n103 = gate_nand(n51, n101);
  auto n106 = gate_mux(n103, n102, b[0]);
  auto n105 = gate_nand(n104, n61);
  y[0] = gate_nand(n106, n105);
}
template<> void PilUint<8>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[7] = gate_buf(a[7]);
  auto n40 = gate_not(b[1]);
  auto n67 = gate_not(b[0]);
  auto n41 = gate_nand(n40, n67);
  auto n60 = gate_mux(a[6], y[7], n41);
  auto n43 = gate_not(b[3]);
  auto n42 = gate_not(b[4]);
  auto n33 = gate_and(n43, n42);
  auto n45 = gate_not(b[5]);
  auto n44 = gate_not(b[6]);
  auto n34 = gate_and(n45, n44);
  auto n35 = gate_and(n33, n34);
  auto n46 = gate_not(b[7]);
  auto n55 = gate_nand(n35, n46);
  auto n59 = gate_not(n55);
  auto n36 = gate_and(b[2], n59);
  auto n47 = gate_not(b[2]);
  auto n52 = gate_nand(n59, n47);
  auto n71 = gate_not(n52);
  y[6] = gate_mux(y[7], n60, n71);
  auto n48 = gate_mux(a[5], a[6], b[0]);
  auto n65 = gate_mux(n48, y[7], b[1]);
  y[5] = gate_mux(y[7], n65, n71);
  auto n50 = gate_mux(a[4], a[6], b[1]);
  auto n49 = gate_mux(a[5], y[7], b[1]);
  auto n74 = gate_mux(n50, n49, b[0]);
  y[4] = gate_mux(y[7], n74, n71);
  auto n56 = gate_mux(a[3], a[5], b[1]);
  auto n51 = gate_mux(n56, n50, b[0]);
  auto n54 = gate_nand(n71, n51);
  auto n53 = gate_nand(y[7], n52);
  y[3] = gate_nand(n54, n53);
  auto n73 = gate_nand(y[7], n55);
  auto n62 = gate_mux(a[2], a[4], b[1]);
  auto n57 = gate_mux(n62, n56, b[0]);
  auto n58 = gate_nand(n71, n57);
  auto n39 = gate_and(n73, n58);
  auto n61 = gate_nand(n36, n60);
  y[2] = gate_nand(n39, n61);
  auto n69 = gate_mux(a[1], a[3], b[1]);
  auto n63 = gate_mux(n69, n62, b[0]);
  auto n64 = gate_nand(n71, n63);
  auto n38 = gate_and(n73, n64);
  auto n66 = gate_nand(n36, n65);
  y[1] = gate_nand(n38, n66);
  auto n68 = gate_mux(a[0], a[2], b[1]);
  auto n70 = gate_mux(n69, n68, n67);
  auto n72 = gate_nand(n71, n70);
  auto n37 = gate_and(n73, n72);
  auto n75 = gate_nand(n36, n74);
  y[0] = gate_nand(n37, n75);
}
template<> void PilUint<8>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n34 = gate_xor(b[7], a[7]);
  auto n4 = gate_not(b[1]);
  auto n6 = gate_xor(a[1], n4);
  auto n3 = gate_not(a[0]);
  auto n5 = gate_nand(b[0], n3);
  y[1] = gate_xor(n6, n5);
  auto n9 = gate_not(b[2]);
  auto n11 = gate_xor(a[2], n9);
  auto n8 = gate_nand(a[1], n4);
  auto n7 = gate_nand(n6, n5);
  auto n10 = gate_nand(n8, n7);
  y[2] = gate_xor(n11, n10);
  auto n14 = gate_not(b[3]);
  auto n16 = gate_xor(a[3], n14);
  auto n13 = gate_nand(a[2], n9);
  auto n12 = gate_nand(n11, n10);
  auto n15 = gate_nand(n13, n12);
  y[3] = gate_xor(n16, n15);
  auto n19 = gate_not(b[4]);
  auto n21 = gate_xor(a[4], n19);
  auto n18 = gate_nand(a[3], n14);
  auto n17 = gate_nand(n16, n15);
  auto n20 = gate_nand(n18, n17);
  y[4] = gate_xor(n21, n20);
  auto n24 = gate_not(b[5]);
  auto n26 = gate_xor(a[5], n24);
  auto n23 = gate_nand(a[4], n19);
  auto n22 = gate_nand(n21, n20);
  auto n25 = gate_nand(n23, n22);
  y[5] = gate_xor(n26, n25);
  auto n29 = gate_not(b[6]);
  auto n31 = gate_xor(a[6], n29);
  auto n28 = gate_nand(a[5], n24);
  auto n27 = gate_nand(n26, n25);
  auto n30 = gate_nand(n28, n27);
  y[6] = gate_xor(n31, n30);
  auto n33 = gate_nand(a[6], n29);
  auto n32 = gate_nand(n31, n30);
  auto n35 = gate_nand(n33, n32);
  y[7] = gate_xnor(n35, n34);
}
template<> void PilUint<8>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  auto n25 = gate_not(y[0]);
  auto n24 = gate_not(a[1]);
  auto n19 = gate_and(n25, n24);
  auto n31 = gate_not(a[2]);
  auto n20 = gate_and(n19, n31);
  auto n30 = gate_not(a[3]);
  auto n21 = gate_and(n20, n30);
  auto n29 = gate_not(a[4]);
  auto n22 = gate_and(n21, n29);
  auto n28 = gate_not(a[5]);
  auto n23 = gate_and(n22, n28);
  auto n27 = gate_not(a[6]);
  auto n26 = gate_nand(n23, n27);
  y[7] = gate_xor(a[7], n26);
  y[6] = gate_xor(n23, n27);
  y[5] = gate_xor(n22, n28);
  y[4] = gate_xor(n21, n29);
  y[3] = gate_xor(n20, n30);
  y[2] = gate_xor(n19, n31);
  y[1] = gate_xor(y[0], a[1]);
}
// === BEGIN circuit.cpp Name=Pil

CircuitEvalKey * g_pek_Pil = nullptr;
CircuitEvalKey * PilBaseBit::pek = nullptr;
const PilBit * PilBaseBit::zero = nullptr;
const PilBit * PilBaseBit::unit = nullptr;

void PilBaseBit::init_pek()
{
    using namespace e3;
    if ( pek ) return;

    initEvalKey
    < CircuitEvalKey, CircuitEvalKey_pilc >
    (name(), pek, g_pek_Pil);

    if ( !zero ) zero = new PilBit("133:14:392:62");
    if ( !unit ) unit = new PilBit("47:39:380:27");
}

// === END circuit.cpp Name=Pil
// === BEGIN circuit.pilc.cpp Name=Pil

PilBit PilBit::gate_buf(const PilBit & a)
{
    return a;
}

PilBit PilBit::gate_not(const PilBit & a)
{
    e3::PilArith pa(kb());
    PilBit r;
    r.x = unit->x - a.x;
    return r;
}

PilBit PilBit::gate_and(const PilBit & a, const PilBit & b)
{
    e3::PilArith pa(kb());
    PilBit r;
    r.x = a.x * b.x;
    return r;
}

PilBit PilBit::gate_or(const PilBit & a, const PilBit & b)
{
    e3::PilArith pa(kb());
    PilBit r;
    r.x = a.x + b.x - a.x * b.x;
    return r;
}

PilBit PilBit::gate_nand(const PilBit & a, const PilBit & b)
{
    return gate_not(gate_and(a, b));
}

PilBit PilBit::gate_nor(const PilBit & a, const PilBit & b)
{
    return gate_not(gate_or(a, b));
}

PilBit PilBit::gate_xnor(const PilBit & a, const PilBit & b)
{
    return gate_not(gate_xor(a, b));
}

PilBit PilBit::gate_xor(const PilBit & a, const PilBit & b)
{
    e3::PilArith pa(kb());
    PilBit r;
    auto z = a.x * b.x;
    r.x = a.x + b.x - ( z + z );
    return r;
}

// a ? b : c
PilBit PilBit::gate_mux(const PilBit & a, const PilBit & b, const PilBit & c)
{
///    return gate_or(gate_and(c, gate_not(a)), gate_and(b, a));
    e3::PilArith pa(kb());
    PilBit r;
    auto z = a.x * b.x;
    auto u = a.x * c.x;
    r.x = z + u - c.x;
    return r;
}

// === END circuit.pilc.cpp Name=Pil
