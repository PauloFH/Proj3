//Paulo Roberto Fernandes Holanda
#include "funcs.h"
/*Judson, Eu sei que esse programa n�o chega nem perto do pedido no trabalho,
* ele est� incompleto e n�o atende a maioria dos requesitos pedidos, mas foi o meu m�ximo na minha atual situa��o
* n�o quero justificar minha mediocridade, e que embora o senhor seja um �timo professor e que o meu projeto n�o reflete tudo 
* o que aprendi com o senhor durante esse semestre, n�o s� sobre l�gica, mas tamb�m sobre COMO SER UM �TIMO PROGRAMADOR
* Grande Abra�o, 
* Paulo Roberto
*/
int main() {
	int Sz{}, times{}, ct{}, tam{}, Szz{}, newsz{}, controle{};
	char tpname[25]{}, swch{};// vari�vel que define a escolha do que ser� feito.
	system("chcp 1252 > nul");
		
	Dvector DynamicV;
		Dvector* DyDvector =&DynamicV;//Ponteiro que apontar� para os vetores
		static ifstream fin;
		static ofstream fout;

		fin.open("Data.dat", ios_base::in | ios_base::binary);
		if (fin.is_open()) {
			fin.read((char*)&Szz, sizeof(int));
			fin.read((char*)&times, sizeof(int));
			fin.read((char*)&ct, sizeof(int));
			DyDvector = new Dvector[Szz]; 
			DyDvector->sz = Szz;
			DyDvector->times = times;
			DyDvector->ct = ct;
			for (int i{}; i < Szz ; i++) {
				fin.read((char*)&DyDvector[i].Prd,sizeof(DyDvector[i].Prd));
			}
		}
		else{
			DyDvector = new Dvector[Szz];
			DyDvector->times = {};
			DyDvector->ct = {};
			DyDvector->sz = {};
		}
		fin.close();

		do {
		inicio();
		cin >> swch;//recebe a entrada da op��o e verifica qual a��o deve ser realizada
		system("CLS");
		switch (tolower(swch)){
		case 'p':
			system("CLS");
			Pedir(DyDvector);
			break;
		case 'a':
			system("CLS");
			DyDvector = Adicionar(DyDvector);//Roda o adicionar
			times = DyDvector->times;
			ct = DyDvector->ct;
			Szz = DyDvector->sz;

			break;
		case 'e':
			system("CLS");
			Excluir(DyDvector, ct);
			break;
		case 'l':
			system("CLS");
			Listar(DyDvector);
			break;
		case 's':
			system("CLS");
			Sair(DyDvector);
			break;
		default:
			cout << "op��o inv�lida\n";
			system("Pause");
			system("CLS");
			break;
		}
		inicio();
		system("CLS");
	}while (swch != 's');
	delete[]DyDvector;
}

