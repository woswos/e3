#include <string>
#include <iostream>

class Ciphertext
{

private:
    int x = 0;

public:
    Ciphertext(){};

    Ciphertext(std::string value){
        if(value == "0"){
            x = 0;
        } else {
            x = 1;
        }
    }

    std::string str() const {
        return std::string()+'0'+char(x);
    }

    static Ciphertext nand(Ciphertext a, Ciphertext b) {
        Ciphertext r;
        r.x = 1&~(a.x&b.x);
        return r;
    }

};

int main(int argc, char const *argv[]) {

    Ciphertext a("1"), b("0");

    auto c = Ciphertext::nand(a, b);

    std::cout << c.str() << '\n';

    return 0;
}
