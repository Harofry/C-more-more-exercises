#include <iostream>
#include <cmath> 
#include <vector> 

// Inserindo a constante pi solicitada na questão
const double PI = 3.14;

// Classe base de figura
class FiguraGeometrica {
public:
    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;
    virtual ~FiguraGeometrica() = default; // Adicionando um destruidor virtual para uma boa prática
};

// 
class Piramide : public FiguraGeometrica {
private:
    double area_base;
    double area_lateral;
    double altura;

public:
    Piramide(double ab, double al, double h) : area_base(ab), area_lateral(al), altura(h) {}

    double calcularArea() const override {
        return area_base + area_lateral;
    }

    double calcularPerimetro() const override {
        return sqrt(area_base) * 4; // Aproximação: considerando a base da piramide como quadrado a dica definiu
    }
};


class Cubo : public FiguraGeometrica {
private:
    double aresta;

public:
    Cubo(double a) : aresta(a) {}

    double calcularArea() const override {
        return 6 * pow(aresta, 2);
    }

    double calcularPerimetro() const override {
        return 12 * aresta;
    }
};


class Paralelepipedo : public FiguraGeometrica {
private:
    double aresta1;
    double aresta2;
    double aresta3;

public:
    Paralelepipedo(double a1, double a2, double a3) : aresta1(a1), aresta2(a2), aresta3(a3) {}

    double calcularArea() const override {
        return 2 * ((aresta1 * aresta2) + (aresta1 * aresta3) + (aresta2 * aresta3));
    }

    double calcularPerimetro() const override {
        return 4 * (aresta1 + aresta2 + aresta3);
    }
};


class Esfera : public FiguraGeometrica {
private:
    double raio;

public:
    Esfera(double r) : raio(r) {}

    double calcularArea() const override {
        return 4 * PI * pow(raio, 2);
    }

    double calcularPerimetro() const override {
        // perímetro díficil de ser definido e por isso foi considerada a circunferência máxima
        return 2 * PI * raio;
    }
};

// Function figura com base no número
FiguraGeometrica* criarFigura(int numero) {
    switch (numero) {
        case 1:
            return new Piramide(10.0, 20.0, 15.0); 
        case 2:
            return new Cubo(5.0); 
        case 3:
            return new Paralelepipedo(3.0, 4.0, 5.0); 
        case 4:
            return new Esfera(7.0); 
        default:
            std::cout << "Número inválido!" << std::endl;
            return nullptr;
    }
}

// B-) Definindo função para calcular a área usando ponteiro
typedef double (*FuncaoArea)(const FiguraGeometrica*);
double calcularArea(const FiguraGeometrica* figura) {
    return figura->calcularArea();
}

// Calculando o perímetro usando ponteiro de função
typedef double (*FuncaoPerimetro)(const FiguraGeometrica*);
double calcularPerimetro(const FiguraGeometrica* figura) {
    return figura->calcularPerimetro();
}

int main() {
    std::vector<FiguraGeometrica*> figuras(4, nullptr);
    std::vector<int> ordem(4);
//Interação com o usuário
    std::cout << "Insira a ordem que as figuras devem aparecer (1 a 4):" << std::endl;
    std::cout << "1: Piramide" << std::endl;
    std::cout << "2: Cubo" << std::endl;
    std::cout << "3: Paralelepipedo" << std::endl;
    std::cout << "4: Esfera" << std::endl;

    for (int i = 0; i < 4; ++i) {
        int escolha;
        std::cout << "Digite o número da figura para a posição " << (i + 1) << ": ";
        std::cin >> escolha;

        if (escolha >= 1 && escolha <= 4) {
            ordem[i] = escolha;
            figuras[i] = criarFigura(escolha);
        } else {
            std::cout << "Número inválido. Por favor, insira um número entre 1 e 4." << std::endl;
            --i; // Se deve epetir a entrada para a mesma posição
        }
    }

    // Ponteiros:
    FuncaoArea funcaoArea = calcularArea;
    FuncaoPerimetro funcaoPerimetro = calcularPerimetro;

    // Exibição de resultado
    for (size_t i = 0; i < figuras.size(); ++i) {
        std::cout << "Analisando figura na posição " << (i + 1) << ":" << std::endl;
        if (figuras[i]) {
            std::cout << "Área: " << funcaoArea(figuras[i]) << std::endl;
            std::cout << "Perímetro: " << funcaoPerimetro(figuras[i]) << std::endl;
            delete figuras[i]; // Liberação
        }
    }

    return 0;
}
