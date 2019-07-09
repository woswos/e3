#include <string>

struct Key { int k; Key(); };

class CiphertextBit
{

    private:
        int x = 0;
        static Key key;

    public:
        CiphertextBit() {}; // *

        CiphertextBit(std::string v): x(std::stoi(v)) {} // *
        std::string str() const { return std::to_string(x); } // *

        CiphertextBit nand(CiphertextBit b) const
        {
            CiphertextBit r;
            //r.x = ( 1 & ~((x - key.k) & (b.x - key.k)) ) + key.k;
            r.x = 1 & ~(x & b.x);
            return r;
        }

};

// **
inline CiphertextBit gate_buf(const CiphertextBit & a) {
    return a;
}

inline CiphertextBit gate_nand(const CiphertextBit & a, const CiphertextBit & b) {
    return a.nand(b);
}

inline CiphertextBit gate_not(const CiphertextBit & a) {
    return gate_nand(a, a);
}

inline CiphertextBit gate_and(const CiphertextBit & a, const CiphertextBit & b) {
    return gate_not(gate_nand(a, b));
}

inline CiphertextBit gate_or(const CiphertextBit & a, const CiphertextBit & b) {
    return gate_not(gate_and(gate_not(a), gate_not(b)));
}

inline CiphertextBit gate_nor(const CiphertextBit & a, const CiphertextBit & b) {
    return gate_and(gate_not(a), gate_not(b));
}

inline CiphertextBit gate_xor(const CiphertextBit & a, const CiphertextBit & b) {
    return gate_or(gate_and(a, gate_not(b)), gate_and(b, gate_not(b)));
}

inline CiphertextBit gate_xnor(const CiphertextBit & a, const CiphertextBit & b) {
    return gate_not(gate_xor(a, b));
}

inline CiphertextBit gate_mux(const CiphertextBit & a, const CiphertextBit & b, const CiphertextBit & c) {
    return gate_or(gate_and(c, gate_not(a)), gate_and(b, a));
}
// ... etc
