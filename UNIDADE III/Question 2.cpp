#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//Foi feito busca por ajuda para tentar fazer um layout de placarzinho

class Sapo {
private:
	string nome;
	int id;
	int distPercorrida;
	int pulosDados;
	int provasDisputadas;
	int vit;
	int emp;
	int der;
	int pulosTotais;

public:
	//atributo estatico publico
	static int distanciaTotalCorrida;
	//construtor
	Sapo(const string& nome, int identificador) 
		: nome(nome), id(identificador), distPercorrida(0), 
		  pulosDados(0), provasDisputadas(0), vit(0), emp(0), der(0), pulosTotais(0) {}

	//getters e setters
	string getNome() const { return nome; }
	void setNome(const string& nome) { this->nome = nome; }

	int getId() const { return id; }
	void setId(int id) { this->id = id; }

	int getDistPerco() const { return distPercorrida; }
	void setDistPerco(int distancia) { this->distPercorrida = distancia; }

	int getPulosDados() const { return pulosDados; }
	void setPulosDados(int pulos) { this->pulosDados = pulos; }

	int getProvasDisputadas() const { return provasDisputadas; }
	void setProvasDisputadas(int provas) { this->provasDisputadas = provas; }

	int getVitorias() const { return vit; }
	void setVitorias(int vit) { this->vit = vit; }

	int getEmpates() const { return emp; }
	void setEmpates(int emp) { this->emp = emp; }

	int getDerrotas() const { return der; }
	void setDerrotas(int der) { this->der = der; }

	int getPulosTotais() const { return pulosTotais; }
	void setPulosTotais(int pulos) { this->pulosTotais = pulos; }

	//pular
	void pular() {
		int maxDistancia = 10; //deixar a distancia maxima do pulo em 10
		int salto = rand() % maxDistancia + 1; //gera um numero aleatorio de 1 e 10
		distPercorrida += salto;
		pulosDados++;
		pulosTotais++;
	}
	//disputar uma prova
	void disputarProva(bool venceu, bool empatou) {
		provasDisputadas++;
		if (venceu) {
			vit++;
		} else if (empatou) {
			emp++;
		} else {
			der++;//adicionando derrotas também 
		}
	}
	//obter distancia total da corrida
	static int getDistTotalCorr() {
		return distanciaTotalCorrida;
	}
	//definir a distancia total da corrida
	static void setDistTotalCorr(int distancia) {
		distanciaTotalCorrida = distancia;
	}
	//exibir informacoes do sapo
	void exibirInfo() const {
		cout << setw(15) << nome
			 << setw(15) << id
			 << setw(20) << distPercorrida
			 << setw(15) << pulosDados
			 << setw(20) << provasDisputadas
			 << setw(10) << vit
			 << setw(10) << emp
			 << setw(10) << der
			 << setw(15) << pulosTotais
			 << endl;
	}
};

//inicializa o atributo estatico
int Sapo::distanciaTotalCorrida = 0;

int main() {
	//inicializa a semente para numeros aleatorios
	srand(static_cast<unsigned int>(time(nullptr))); 

	//gera a distancia total da corrida aleatoria entre 100 e 1000
	//deixe entre 100 e 1000 pra corrida nao ficar tao grande 
	int distanciaTotal = rand() % (1000 - 100 + 1) + 100;
	Sapo::setDistTotalCorr(distanciaTotal);

	//nao consegui fazer como que possam ser adicionados quantos sapos quiser 
	Sapo sapo1("Sapo Verde", 1);
	Sapo sapo2("Sapo Azul", 2);

	//simulando corrida ate que pelo menos um sapo atinja a distancia total
	while (sapo1.getDistPerco() < Sapo::getDistTotalCorr() &&
		   sapo2.getDistPerco() < Sapo::getDistTotalCorr()) {
		sapo1.pular();
		sapo2.pular();
	}

	//determina o resultado da corrida
	if (sapo1.getDistPerco() >= Sapo::getDistTotalCorr() &&
		sapo2.getDistPerco() >= Sapo::getDistTotalCorr()) {
		//empate
		sapo1.disputarProva(false, true);
		sapo2.disputarProva(false, true);
	} else if (sapo1.getDistPerco() >= Sapo::getDistTotalCorr()) {
		//sapo 1 vence
		sapo1.disputarProva(true, false);
		sapo2.disputarProva(false, false);
	} else {
		//sapo 2 vence
		sapo1.disputarProva(false, false);
		sapo2.disputarProva(true, false);
	}

	//exibindo cabecalho
	cout << left
		 << setw(15) << "Nome"
		 << setw(15) << "ID"
		 << setw(20) << "Distancia"
		 << setw(15) << "Pulos"
		 << setw(20) << "Provas Disputadas"
		 << setw(10) << "Vitorias"
		 << setw(10) << "Empates"
		 << setw(10) << "Derrotas"
		 << setw(15) << "Pulos Totais"
		 << endl;

	cout << string(95, '-') << endl; //linha de separacao

	//exibindo informacoes dos sapos lado a lado
	sapo1.exibirInfo();
	sapo2.exibirInfo();

	cout << "Distancia Total da Corrida: " << Sapo::getDistTotalCorr() << "\n";

	return 0;
}
