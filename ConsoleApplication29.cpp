#include <iostream>
using namespace std;

class StringNova : public std::string
{
public:
    string meio()
    {
        if (size() == 0) return "";
        if (size() % 2 == 1)
            return substr(size() / 2, 1);
        else
            return substr((size() / 2) - 1, 2);
    };
    StringNova() : string(""){};
    StringNova(const char* s) : string(s){};
};

int main(void)
{
    string str = "teste";
    int inicio = 0;
    int total = 0;
    if (str.size() == 0) return 0;
    if (str.size() % 2 == 1)
    {   inicio = str.length() / 2;
        total = 1; // impar
    }
    else
    {   inicio = str.length() / 2 - 1;
        total = 2; // par
    };
    cout << "String: '" << str
        << "'\tTamanho: " << str.length()
        << "\tMeio: '" << str.substr(inicio, total)
        << "'\n";

    string saida = "";
    int len = str.length();
    if (len > 0)
    {
        if (len % 2 == 1)
            saida += str[len/2];
        else
        {
            saida += str[(len / 2) - 1];
            saida += str[(len / 2)];
        };
        cout << "String: '" << str
            << "'\tTamanho: " << len
            << "\tMeio: '" << saida << "'\n";
    };  // if

    StringNova valor{ "teste" };
    cout << "String: '" << valor <<
        "'\tTamanho: " << valor.length() <<
        "\tMeio: '" << valor.meio() << "'\n";

    return 0;
};

