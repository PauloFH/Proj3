//Paulo Roberto Fernandes Holanda
#include "funcs.h"
/*Judson, Eu sei que esse programa não chega nem perto do pedido no trabalho,
* ele está incompleto e não atende a maioria dos requesitos pedidos, mas foi o meu máximo na minha atual situação
* não quero justificar minha mediocridade, e que embora o senhor seja um ótimo professor e que o meu projeto não reflete tudo 
* o que aprendi com o senhor durante esse semestre, não só sobre lógica, mas também sobre COMO SER UM ÓTIMO PROGRAMADOR
* Grande Abraço, 
* Paulo Roberto
*/
int main() {
	int Sz{}, times{}, ct{}, tam{}, Szz{}, newsz{}, controle{};
	char tpname[25]{}, swch{};// variável que define a escolha do que será feito.
	system("chcp 1252 > nul");
		
	Dvector DynamicV;
		Dvector* DyDvector =&DynamicV;//Ponteiro que apontará para os vetores
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
		cin >> swch;//recebe a entrada da opção e verifica qual ação deve ser realizada
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
			cout << "opção inválida\n";
			system("Pause");
			system("CLS");
			break;
		}
		inicio();
		system("CLS");
	}while (swch != 's');
	delete[]DyDvector;
}

