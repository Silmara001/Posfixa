/* Tipo ListaR */
/*
  Arquivo: SAB_ListaR.h
  Autor: Silmara Alvares Barbosa
  Date: 31/10/16 19:40
  Descrição: Implementação de uma Lista de numeros reais.
*/

#include<stdio.h>
#define MAX 200
#define FANTASMA -2

typedef struct{
	float elemento[MAX];
}ListaR;

typedef struct{
	float c_valor[10];
	char c_letra[10];
}Tab;

//Interface
void criarListaVazia(ListaR *lista);
int obterTamanho(ListaR *lista);
float obterElemento(ListaR *lista, int posicao);
float buscarElemento(ListaR *lista, float item);
void mostrarLista(ListaR *lista);
void inserirElemento(ListaR *lista, float n);
void removerElemento(ListaR *lista);
void gerarTabela(Tab *tabela);

//Implementações
void gerarTabela(Tab *tabela){
	int i, l = 65;
	tabela->c_valor[0] = 10;
	tabela->c_letra[0] = '#';
	for(i=1; i<10; i++){
		tabela->c_valor[i] = i;
		tabela->c_letra[i] = l;
		l++;
	}
	printf("TABELA DOS IDENTIFICADORES: \n");
	for(i=1; i<10; i++){
		printf("%c = %.1f, ",tabela->c_letra[i], tabela->c_valor[i]);
	}
	printf("\n");
}
void criarListaVazia(ListaR *lista){
	lista->elemento[0] = 0;
}
void mostrarLista(ListaR *lista){
	int tamanhoLista, i;
	tamanhoLista = lista->elemento[0];
	if((tamanhoLista > 0)&&(tamanhoLista < MAX)){
		for(i=1; i<=tamanhoLista; i++){
			printf(" %.3f ", lista->elemento[i]);
		}
	}
}
float obterElemento(ListaR *lista, int posicao){
	int item = lista->elemento[posicao]; 
	return item;
}
float buscarElemento(ListaR *lista, float item){
	int i=1;
	float r;
	while((item != lista->elemento[i]) && (i<lista->elemento[0])&&(lista->elemento[0] != 0)){
		i++;
	}
	if(item == lista->elemento[i]){
		r = lista->elemento[i];
	}else{
		r = FANTASMA;
	}
	return r;
}
int obterTamanho(ListaR *lista){
	int tam = lista->elemento[0];
	return tam;
}
void inserirElemento(ListaR *lista, float n){
	int t;
	t = lista->elemento[0];
	lista->elemento[t+1] = n;
	lista->elemento[0] = t + 1;
}
void removerElemento(ListaR *lista){
	int tam = lista->elemento[0];
	lista->elemento[0] = tam - 1;
}
