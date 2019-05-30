/* Tipo PilhaR */
/*
  Arquivo: SAB_PilhaR.h
  Autor: Silmara Alvares Barbosa
  Date: 31/10/16 19:43
  Descrição: Implementação de uma Pilha de numeros Reais.
*/

#include "Booleano.h"
#define SINAL -1
#define FANTASMA -2

#define Max 200
typedef struct {
    int topo;    // topo indica o local onde se encontra o último caractere colocado na pilha
    float tabela[Max];
} PilhaR;

/* interface */
void criarPilhaRVazia(PilhaR *);
float acessarTopoPilhaR(PilhaR *);
void mostrarPilhaR(PilhaR *);
bool verificarPilhaRVazia(PilhaR *);
bool verificarPilhaRCheia(PilhaR *);
void pushPilhaR(PilhaR *, float);
void popPilhaR(PilhaR *);

/* implementações */
void criarPilhaRVazia(PilhaR *s){
	s->topo = SINAL;
}
float acessarTopoPilhaR(PilhaR * s){
    bool vazia;
    float elemento;
    vazia = verificarPilhaRVazia(s);
      
    if(vazia == TRUE){
		elemento = FANTASMA;
	}else{
    	elemento = s->tabela[s->topo];
	}
    return elemento;
}     
bool verificarPilhaRVazia(PilhaR *s){
    bool decisao;
    if(s->topo == SINAL){
     	decisao =  TRUE;
	}else{
	 	decisao =  FALSE;
	}
	return decisao;
}
bool verificarPilhaRCheia(PilhaR *s){
    bool decisao;
    if(s->topo == (Max-1)){
    	decisao = TRUE;
    }else{
    	decisao = FALSE;
	}
	return decisao;
}
void pushPilhaR(PilhaR *s, float n){
    if((verificarPilhaRCheia(s)) != TRUE){
    	s->tabela[s->topo+1] = n;
    	s->topo = s->topo + 1;
	}
}
void popPilhaR(PilhaR * s){
      if((verificarPilhaRVazia(s)) != TRUE){
    	s->topo = s->topo - 1;
	}
}
void mostrarPilhaR(PilhaR *s){
	int t = s->topo, i;
	for(i=0; i<=t;i++){
		printf(" %.3f ",s->tabela[i]);
	}
	printf("\n");
}
