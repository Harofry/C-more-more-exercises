#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>   

class Sapo {
private:
    std::string nome;
    std::string cor; // Atributo extra: definindo uma cor para os sapos baseado nos jogos do bom dia e companhia do SBT
    int identificador;
    int distanciaPercorrida; 
    int quantidadePulosDados;
    int quantidadeProvasDisputadas;
    int vitorias;
    int empates;
    int quantidadeTotalPulosDados;
    static int distanciaTotalCorrida; // estático

public:
    // Utilizando o construtor
    Sapo(std::string nome, std::string cor, int id) 
        : nome(nome), cor(cor), identificador(id), distanciaPercorrida(0), quantidadePulosDados(0), 
          quantidadeProvasDisputadas(0), vitorias(0), empates(0), quantidadeTotalPulosDados(0) {}

    // Utilizando getters
    std::string getNome() const { return nome; }
    std::string getCor() const { return cor; }
    int getIdentificador() const { return identificador; }
    int getDistanciaPercorrida() const { return distanciaPercorrida; }
    int getQuantidadePulosDados() const { return quantidadePulosDados; }
    int getQuantidadeProvasDisputadas() const { return quantidadeProvasDisputadas; }
    int getVitorias() const { return vitorias; }
    int getEmpates() const { return empates; }

    // Método de pulo
    void pular(int maxDistanciaPorPulo) {
        int pulo = rand() % maxDistanciaPorPulo + 1; 
        distanciaPercorrida += pulo;
        quantidadePulosDados++;
        quantidadeTotalPulosDados++;
    }

    // Método inicio da corrida
    void iniciarCorrida() {
        distanciaPercorrida = 0;
        quantidadePulosDados = 0;
    }

    // Método sapo já venceu a corrida?
    bool venceuCorrida() const {
        return distanciaPercorrida >= distanciaTotalCorrida;
    }

    // Vitórias
    void incrementarVitoria() {
        vitorias++;
    }

    // Empates
    void incrementarEmpate() {
        empates++;
    }

    // Método estático para definir a distância total da corrida
    static void setDistanciaTotalCorrida(int distancia) {
        distanciaTotalCorrida = distancia;
    }
};

// atributo estático definido em 50 metros
int Sapo::distanciaTotalCorrida = 50; 

int main() {
    srand(static_cast<unsigned int>(time(0))); 

    // Número de sapos determinado em 3
    Sapo sapo1("Sapo1", "vermelho", 1);
    Sapo sapo2("Sapo2", "verde", 2);
    Sapo sapo3("Sapo3", "amarelo", 3);

    // Parte do código que visa apostas esportivas (brincadeira, visa apenas a vibração do público XD)
    std::cout << "Para qual sapo você irá torcer? Digite o número correspondente:" << std::endl;
    std::cout << "1. Sapo1 (vermelho)" << std::endl;
    std::cout << "2. Sapo2 (verde)" << std::endl;
    std::cout << "3. Sapo3 (amarelo)" << std::endl;

    int escolha;
    std::cin >> escolha;

    Sapo* sapoEscolhido = nullptr;

    switch (escolha) {
        case 1:
            sapoEscolhido = &sapo1;
            break;
        case 2:
            sapoEscolhido = &sapo2;
            break;
        case 3:
            sapoEscolhido = &sapo3;
            break;
        default:
            std::cout << "Escolha inválida! A corrida será feita sem torcedores." << std::endl;
            break;
    }

    
    Sapo::setDistanciaTotalCorrida(50); 

    // Simulando a corrida
    while (!sapo1.venceuCorrida() && !sapo2.venceuCorrida() && !sapo3.venceuCorrida()) {
        sapo1.pular(2); // máximo de 2 metros por pulo para cada sapo afim de deixar justo
        sapo2.pular(2);
        sapo3.pular(2);

        std::cout << sapo1.getNome() << " (" << sapo1.getCor() << ") está na distância: " << sapo1.getDistanciaPercorrida() << " metros" << std::endl;
        std::cout << sapo2.getNome() << " (" << sapo2.getCor() << ") está na distância: " << sapo2.getDistanciaPercorrida() << " metros" << std::endl;
        std::cout << sapo3.getNome() << " (" << sapo3.getCor() << ") está na distância: " << sapo3.getDistanciaPercorrida() << " metros" << std::endl;

        
        if (sapoEscolhido != nullptr) {
            std::cout << "Seu sapo " << sapoEscolhido->getNome() << " (" << sapoEscolhido->getCor() << ") está na distância: " 
                      << sapoEscolhido->getDistanciaPercorrida() << " metros" << std::endl;
        }
    }

    // Determinando o sapo campeão
    if (sapo1.venceuCorrida()) {
        std::cout << sapo1.getNome() << " venceu a corrida!" << std::endl;
        sapo1.incrementarVitoria();
    } else if (sapo2.venceuCorrida()) {
        std::cout << sapo2.getNome() << " venceu a corrida!" << std::endl;
        sapo2.incrementarVitoria();
    } else if (sapo3.venceuCorrida()) {
        std::cout << sapo3.getNome() << " venceu a corrida!" << std::endl;
        sapo3.incrementarVitoria();
    }

    return 0;
}
