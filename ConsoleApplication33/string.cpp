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
    StringNova() : string("") {};
    StringNova(const char* s) : string(s) {};
};

int main(void)
{
    const string str[4] = {
        "ovo","andré","os","amarelo" };


    // opcao 1, moderninha mas usa size()
    cout << "\ncaso 1: mostra so as letras na saida\n\n";
    for (const auto& uma : str)
    {
        int n = uma.size() / 2;
        cout << "\"meio\" de '" << uma << "' = ";
        if (!(uma.size() % 2)) cout << uma[n - 1];
        cout << uma[n] << endl;
    };  // for()

    // opcao 2 sem usar funcoes
    cout << "\ncaso 2: cria uma string\n\n";
    for (const auto& uma : str)
    {
        string saida = "";
        int len = uma.length();
        if (len > 0)
        {
            if (len % 2 == 1)
                saida += uma[len / 2];
            else
            {
                saida += uma[(len / 2) - 1];
                saida += uma[(len / 2)];
            };
            cout << "String: '" << uma
                << "'\tTamanho: " << len
                << "\tMeio: '" << saida << "'\n";
        };  // if
    };  // for()

    cout << "\ncaso 3: deriva classe 'string'"
        "e cria metodo meio()\n\n";
    for (const auto& uma : str)
    {
        StringNova valor(uma.c_str());
        cout << "String: '" << valor <<
            "'\tTamanho: " << valor.length() <<
            "\tMeio: '" << valor.meio() << "'\n";
    };  // for()

    return 0;
};

// deriva string 

