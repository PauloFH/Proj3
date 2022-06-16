//Paulo Roberto Fernandes Holanda


#include "funcs.h"

int main() {
	unsigned Sz{}, times{}, ct{}, tam{};
	char tpname[25]{}, swch{};// variável que define a escolha do que será feito.
	system("chcp 1252 > nul");
	do {
		Dvector* DyDvector{};//Ponteiro que apontará para os vetores
		ifstream fin;
		ofstream fout;

		fin.open("Data.dat", ios_base::in | ios_base::binary);
		if (fin.is_open()) {
			fin.read((char*)&Sz, sizeof(unsigned));
			DyDvector = new Dvector[Sz];
			tam = ((unsigned)sizeof(Dvector)*Sz);
			fin.read((char*)DyDvector, tam);
			fin.close();
		}
		else{
			DyDvector = new Dvector[0]{};
		}
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
			Adicionar(DyDvector);//Roda o adicionar
			break;
		case 'e':
			system("CLS");
			Excluir(DyDvector);
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
	}while (swch != 's');
}

