#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Products {
	char name[25];
	float price;
	unsigned stocked;
};

struct request{
	char name[25];
	unsigned need;
};
struct Dvector {
	request pds;
	Products Prd;
	unsigned sz;
	unsigned times;
	unsigned ct;
};

void inicio();// Fun��o que imprime o no cmd as sele��es iniciais.

request * Pedir(Dvector* vet);

void Adicionar(Dvector*vet1);//adiciona um novo registro ao vetor de estoque contendo o nome, pre�o e quantidade.

void Excluir(Dvector*vet);

void Listar(Dvector*vet);

void Sair(Dvector*vet);