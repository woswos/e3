#include <string>

struct Key{};

class CiphertextBit
{

    private:
        int x = 0;
	static Key key;

    public:
        CiphertextBit() {};

        CiphertextBit(std::string v): x(std::stoi(v)) {}
        std::string str() const { return std::to_string(x); }

        CiphertextBit nand(CiphertextBit b) const
        {
            CiphertextBit r;
            r.x = 1 & ~(x & b.x);
            return r;
        }

};

inline CiphertextBit gate_nand(CiphertextBit a, CiphertextBit b){ return a.nand(b); }
inline CiphertextBit gate_not(CiphertextBit a){ return gate_nand(a,a); }
inline CiphertextBit gate_and(CiphertextBit a, CiphertextBit b){ return gate_not(gate_nand(a,b)); }
// ... etc

