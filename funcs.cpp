//Paulo Roberto Fernandes Holanda
#include "funcs.h"
#pragma warning(disable : 4996)


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

Dvector* Pedir(Dvector* vet) {// Ler o arquivo, cria nfc do pedido com o preço
	char ch{},acname[25]{}, newacname[25]{}, cb[50]{}, tx[50]{};
	request tmp{};
	request* pedidos{};
	int sz{};
	int i{};
	ifstream addped;
	cout << "Pedir\n-------\n";
	cout << "Arquivo: ";
	cin >> acname;// recebe nome do arquivo
	while(acname[i] != '.') {
		newacname[i] = acname[i];
		i++;
	}
	newacname[i] = '\0';
	strcat(newacname,".nfc");//cria o nome em .nfc
	
	addped.open(acname, ios_base::in);// abre o arquivo texto para leitura.
	if (!addped.is_open()) {// caso o arquivo não exista, não abre nada e volta para o inicio
		cout << "arquivo inexistente";
	}else{
		while (addped.get(ch)){
			if (ch == '\n')
				sz++;
		}// conta a quantidade de linhas
		pedidos = new request[sz];// vetor que carrega os pedidos
			int szs{};
			addped.getline(cb, 50);
			addped.getline(tx, 50);
		szs = (int)strlen(tmp.name); // tamanho dos pedidos
		addped >> tmp.name;// recebe nome do produto pedido
		if (!isupper(tmp.name[0]))// coloca o nome no modelo primeira maiuscula 
			tmp.name[0] = (char)towupper(tmp.name[0]);
		for (int f{ 1 }; f < sz; f++) {
			if (isupper(tmp.name[f]))
				tmp.name[f] = (char)towlower(tmp.name[f]);
		}
		addped >> tmp.need;
		int cont{}, tst{}, vazio{};
		for (int f{}; f < sz; f++) {
			if (!(strcmp(pedidos[f].name, tmp.name))) {
				cont = f;
				tst++;
			}
			if (tst > 0) {
				pedidos[cont].need += tmp.need;

			}
			else {
			strcpy(pedidos[f].name, tmp.name);
			pedidos[f].need = tmp.need;
			}
		}

	}
		int tst = {};
		int controle{};
		while (controle!= 0 && tst >=0){
			for (int i{}; i < sz;) {

			}
		}
		int valT{}, ds{};
		for (int i{}; i < vet->ct; i++) {
			valT += vet[i].Prd.price;
		}
		ofstream nfc;
		nfc.open(newacname);
		nfc << cb << endl;
		nfc << "---------------------------------------------------\n";
		nfc << "Compra";
		nfc << right; nfc.width(30); nfc.fill(' ');
		nfc << "=";
		nfc << right; nfc.width(6); nfc.fill(' ');
		nfc << "R$" << valT<<endl;
		if (valT > 1000) {
			ds = (valT * 0.1);
			valT -= ds;
		}

		nfc << right; nfc.width(30); nfc.fill(' ');
		nfc << "Desconto";
		nfc << right; nfc.width(6); nfc.fill(' ');
		nfc << "=";
		nfc << right; nfc.width(5); nfc.fill(' ');
		nfc << "R$" << ds << endl;

		nfc << right; nfc.width(30); nfc.fill(' ');
		nfc << "Total";
		nfc << right; nfc.width(6); nfc.fill(' ');
		nfc << "=";
		nfc << right; nfc.width(5); nfc.fill(' ');
		nfc << "R$" << valT << endl;
	}
	return vet ;
}


Dvector* Adicionar(Dvector* dvet){
	Products pduct{};
	int sz = dvet->sz, ct = dvet->ct, times = dvet->times;
	if (sz == ct) {
		int sz = dvet->sz;
		int newsz{};
		Dvector* temp{};
		newsz = sz + (int)(pow(2, times));
		temp = new Dvector[sz + (pow(2,times++))];
		for (int i{}; i < sz; i++) {
			temp[i] = dvet[i];
		}
		delete[] dvet;
		dvet = temp;
		temp = 0;
		dvet->sz = newsz;
		sz = newsz;
		dvet->times = times;

	}
	int tst{1}, cont{};
	cout << "Adicionar\n";
	cout << "----------\n";

	cout << "Produto :";
	cin >> pduct.name;
	if (islower(pduct.name[0]))
		pduct.name[0] = towupper((pduct.name[0]));
	for (int f{1}; f <= strlen(pduct.name); f++) {
		if (isupper(pduct.name[f]))
		pduct.name[f] = towlower((pduct.name[f]));
	}
	int is{}, control{};
	while (tst != 0 && is < sz) { //Verificação se o produto então inserido é um mesmo já existente
		tst = strcmp(pduct.name, dvet[is].Prd.name);
		if (tst == 0) {
			control++;
		}
		is++;
	}	
	if (tst == 0) {
		cout << "Preço :";
		strcpy(dvet[is].Prd.name, pduct.name);
		cin >> dvet[is].Prd.price;
		cout << "Quant: ";
		cin >> dvet[is].Prd.stocked;
		dvet->sz = sz;
	}
	else {
		strcpy(dvet[ct].Prd.name,pduct.name);
		cout << "Preco: ";
		cin >> dvet[ct].Prd.price;
		cout << "Quant: ";
		cin >> dvet[ct].Prd.stocked;
		ct++;
		dvet->ct = ct;
	}
	
	
	return dvet;
}

void Excluir(Dvector* dvet, int ct) {
	int tst{};
	char vf{};
	cout << "Excluir\n-------\n";
	for(int i{}; i < dvet->ct;i++) {
		cout << (i + 1) << ") ";
		cout << dvet[i].Prd.name << endl;
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
		dvet[ct--] = {};
	}
}

void Listar(Dvector* vet){
	cout << "Listagem\n---------\n";
	for (int i{0}; i < vet->ct; i++) {
		cout << vet[i].Prd.name;

		cout << " - " << "R$";

		cout << fixed; cout.precision(2); cout.fill('0');
		cout << vet[i].Prd.price;
		cout << " - " << vet[i].Prd.stocked << "KG" <<  endl;
	}
	system("pause");
}

void Sair(Dvector* vet){
	ofstream fout;
	fout.open("Data.dat", ios_base::out | ios_base::binary);
	fout.write((char*)&vet->sz, sizeof(int));
	fout.write((char*)&vet->times, sizeof(int));
	fout.write((char*)&vet->ct, sizeof(int));

	for (int i = 0; i < vet->sz; i++) {
		fout.write((char*)&vet[i].Prd, sizeof(vet[i].Prd));
	}
	fout.close();
}
