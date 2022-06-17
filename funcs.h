//Paulo Roberto Fernandes Holanda
#pragma once

#include <iostream>
#include <fstream>
#define  _CRT_SECURE_NO_WARNINGS
using namespace std;

struct Products {
	char name[25];
	float price;
	int stocked;
};

struct request{
	char name[25];
	int need;
};
struct Dvector {
	Products Prd;
	int sz;
	int times;
	int ct;
};

void inicio();// Função que imprime o no cmd as seleções iniciais.

Dvector* Pedir(Dvector* vet);


Dvector* Adicionar(Dvector*vet1);//adiciona um novo registro ao vetor de estoque contendo o nome, preço e quantidade.

void Excluir(Dvector* vet, int ct);

void Listar(Dvector*vet);

void Sair(Dvector*vet);