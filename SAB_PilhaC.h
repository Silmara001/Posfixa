/* Tipo PilhaC */
/*
  Arquivo: SAB_PilhaC.h
  Autor: Silmara Alvares Barbosa
  Date: 31/10/16 19:42
  Descrição: Implementação de uma pilha de caracteres.
*/
#include <stdlib.h>
#include <string.h>
#include "Booleano.h"
#define SINAL -1
#define fantasma '#'

#define MaxCh 200
typedef struct {
      int topo;    // topo indica o local onde se encontra o último caractere colocado na pilha
      unsigned char tabela[MaxCh];
} PilhaC;

/* interface */
void criarPilhaChVazia(PilhaC *);
unsigned char acessarTopo(PilhaC *);
void mostrarPilha(PilhaC *);
bool verificarPilhaChVazia(PilhaC *);
bool verificarPilhaChCheia(PilhaC *);
void pushPilhaCh(PilhaC *, unsigned char);
void popPilhaCh(PilhaC *);

/* implementações */
void criarPilhaChVazia(PilhaC *s){
       s->topo = SINAL;
}
unsigned char acessarTopo(PilhaC * s){
    bool vazia;
    unsigned char elemento;
    vazia = verificarPilhaChVazia(s);
      
    if(vazia == TRUE){
		elemento = fantasma;
	}else{
    	elemento = s->tabela[s->topo];
	}
    return elemento;
}     
bool verificarPilhaChVazia(PilhaC *s){
    bool decisao;
    if(s->topo == SINAL){
     	decisao =  TRUE;
	}else{
	 	decisao =  FALSE;
	}
	return decisao;
}
bool verificarPilhaChCheia(PilhaC *s){
    bool decisao;
    if(s->topo == (MaxCh-1)){
    	decisao = TRUE;
    }else{
    	decisao = FALSE;
	}
	return decisao;
}
void pushPilhaCh(PilhaC *s, unsigned char ch){
    if((verificarPilhaChCheia(s)) != TRUE){
    	s->tabela[s->topo+1] = ch;
    	s->topo = s->topo + 1;
	}
}
void popPilhaCh(PilhaC * s){
      if((verificarPilhaChVazia(s)) != TRUE){
    	s->topo = s->topo - 1;
	}
}
void mostrarPilha(PilhaC *s){
	int t = s->topo, i;
	for(i=0; i<=t;i++){
		printf(" %c ",s->tabela[i]);
	}
	printf("\n");
}
