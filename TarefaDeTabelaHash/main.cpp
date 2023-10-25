#include <iostream>
#include <vector>
#include <list>

const int primeiroNivel = 10;  
const int segundoNivel = 10;   

using namespace std;

struct Objeto {
    int chave;
    string dados;
    Objeto* proximo;
};


vector<list<Objeto*>> vetorSegundoNivel(segundoNivel);


int HashPrimeiroNivel(int chave) {
    return chave % primeiroNivel;
}

int HashSegundoNivel(int chave) {
    return chave % segundoNivel;
}

void InserirObjeto(int chave, const std::string& dados) {
    Objeto* objeto = new Objeto;
    objeto->chave = chave;
    objeto->dados = dados;
    objeto->proximo = nullptr;

    int indicePrimeiroNivel = HashPrimeiroNivel(chave);
    int indiceSegundoNivel = HashSegundoNivel(chave);

    vetorSegundoNivel[indiceSegundoNivel].push_back(objeto);
}

Objeto* RecuperarObjeto(int chave) {
    int indiceSegundoNivel = HashSegundoNivel(chave);

    for (Objeto* objeto : vetorSegundoNivel[indiceSegundoNivel]) {
        if (objeto->chave == chave) {
            return objeto;
        }
    }

    return nullptr;
}

int main() {

    InserirObjeto(42, "Dados do objeto 42");
    InserirObjeto(25, "Dados do objeto 25");
    

    Objeto* objetoRecuperado = RecuperarObjeto(42);
    if (objetoRecuperado != nullptr) {
        std::cout << "Objeto com chave 42: Chave = " << objetoRecuperado->chave << ", Dados = " << objetoRecuperado->dados << std::endl;
    } else {
        std::cout << "Objeto com chave 42 não encontrado." << std::endl;
    }

    objetoRecuperado = RecuperarObjeto(25);
    if (objetoRecuperado != nullptr) {
        std::cout << "Objeto com chave 25: Chave = " << objetoRecuperado->chave << ", Dados = " << objetoRecuperado->dados << std::endl;
    } else {
        std::cout << "Objeto com chave 25 não encontrado." << std::endl;
    }

    return 0;
}
