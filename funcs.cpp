#include "funcs.h"
//Paulo Roberto Fernandes Holanda

void inicio(){
	cout << "Sistema de Controle\n";
	cout << "===================\n";
	cout << "(P)edir\n";
	cout << "(A)dicionar\n";
	cout << "(E)xcluir\n";
	cout << "(L)istar\n";
	cout << "(S)air\n";
	cout << "====================\n";
	cout << "Opção: [_]\b\b";
}

request * Pedir(Dvector* vet){
	char ch{},acname[25]{}, newacname[25]{}, cb[50]{}, tx[50]{};
	request tmp{};
	request* pedidos{};
	unsigned sz{};
	int i{};
	ifstream addped;
	cout << "Pedir\n-------\n";
	cout << "Arquivo: ";
	cin >> acname;
	while(acname[i] != '.') {
		newacname[i] = acname[i];
		i++;
	}
	newacname[i] = '\0';
	strcat(newacname,".nfc");

	addped.open(acname, ios_base::in);
	if (!addped.is_open()) {
		cout << "arquivo inexistente";
	}else{
		while (addped.get(ch)){
			if (ch == '\n')
				sz++;
		}
		pedidos = new request[sz];
			unsigned szs{};
		szs = strlen(tmp.name);
		addped.getline(cb, 50);
		addped.getline(tx, 50);
		addped >> tmp.name;
		if (!isupper(tmp.name[0]))
			tmp.name[0] = towupper(tmp.name[0]);
		for (int f{ 1 }; f < sz; f++) {
			if (isupper(tmp.name[f]))
				tmp.name[f] = towlower(tmp.name[f]);
		}
		addped >> tmp.need;
		int cont{}, tst{}, vazio{};
		for (int f{}; f < sz; f++) {
			if (!(strcmp(pedidos[f].name, tmp.name))) {
				cont = f;
				tst++;
			}
			if (tst > 0) {
				pedidos[f].need += tmp.need;

			}
			else {
					int i{};
					while (vazio == 0) {
						if (pedidos[i].name == "") {
							strcpy(pedidos[f].name, tmp.name);
							vazio++;
						}
						else {
							i++;
						}
					}
			}

		}
	}
}

void Adicionar(Dvector* dvet) {
	int sz{}, newsz{}, ct{};

	Products pduct{};
	sz = dvet->sz;
	dvet->ct++;
	if (ct >= sz) {
		newsz = sz + (pow(2, dvet->times));
		Dvector* temp{};
		temp = new Dvector[newsz];
		dvet->times++;
		for (int i{}; i < sz; i++) {
			temp[i] = dvet[i];
		}
		delete[] dvet;
		dvet = temp;
		temp = {};
		dvet->sz = newsz;
	}
	cout << "Adicionar\n";
	cout << "----------\n";
	cout << "Produto :";
	cin >> pduct.name;
	if (!isupper(pduct.name[0]))
		pduct.name[0] = towupper(pduct.name[0]);
	for (int f{ 1 }; f < sz; f++) {
		if (isupper(pduct.name[f]))
			pduct.name[f] = towlower(pduct.name[f]);
	}

	cout << "Preço :";
	cin >> pduct.price;
	cout << "Quantidade:";
	cin >> pduct.stocked;
	unsigned tst{}, cont{};

	for (int f{}; f < sz; f++) {
		if (!(strcmp(dvet[f].Prd.name, pduct.name))) {
			cont = f;
			tst++;
		}
		if (cont++ > 0) {
			dvet[cont].Prd.price = pduct.price;
			dvet[cont].Prd.stocked += pduct.stocked;
		}
		else {
			strcpy(dvet[sz].Prd.name, pduct.name);
			dvet->Prd.price = pduct.price;
			dvet->Prd.stocked = pduct.stocked;
		}

	}

}

void Excluir(Dvector* dvet){
	int tst{};
	char vf{};
	cout << "Excluir\n-------\n";
	for(int i{}; i < dvet->sz;i++) {
		cout << (i + 1) << ") ";
		cout << dvet->Prd.name << endl;
	}
	cout << "Número do produto: ";
	cin >> tst;
	if (tst < dvet->sz) {
		cout << "Deseja excluir "<< dvet[tst-1].Prd.name << "(S / N) ? ";
	}
	cin >> vf;

	if(vf == 's' || vf == 'S') {
		for(int i ={tst}; i < dvet->sz;i++){
			dvet[i - 1] = dvet[i];
		}
	}
}

void Listar(Dvector* vet){
	cout << "Listagem\n---------";
	for (int i{}; i < vet->sz; i++) {
		cout << left; cout.width(25); cout.fill(' ');
		cout << vet[i].Prd.name;

		cout << " - " << "R$";

		cout << fixed; cout.precision(2); cout.fill('0');
		cout << vet[i].Prd.price;
		cout << left; cout.width(10); cout.fill(' ');
		cout << " - " << vet[i].Prd.stocked << "KG";
	}
}

void Sair(Dvector* vet){

}
