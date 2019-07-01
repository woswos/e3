#include <string>

class CiphertextBit
{

    private:
        int x = 0;

    public:
        CiphertextBit() {};

        CiphertextBit(std::string value)
        {
            if (value == "0")
            {
                x = 0;
            }
            else
            {
                x = 1;
            }
        }

        std::string str() const
        {
            return std::to_string(x);
        }

        static CiphertextBit nand(CiphertextBit a, CiphertextBit b)
        {
            CiphertextBit r;
            r.x = 1 & ~(a.x & b.x);
            return r;
        }

};

