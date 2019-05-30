/* 
  Arquivo: Silmara Alvares_POSFIXA.c
  Autor: Silmara Alvares Barbosa
  Date: 31/10/16 19:45
  Descrição: Implementação de um programa para fazer a conversão de uma expressão infixa para posfixa e fazer a avaliação.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SAB_ListaR.h"
#include "SAB_PilhaR.h"
#include "SAB_PilhaC.h"

typedef enum{PaE,PaD,OpA,OpM,Ident,TerM} TokenIn;

TokenIn obterToken(char);
void conversaoInfixa(char matrizPos[7][28], char matriz[7][28],ListaR *lista, PilhaC *pilha);
void mostrarPosfixa(char matrizPosfixa[7][28], ListaR *lista);
void avaliarPosfixa(float valor[6], char matriz[7][28], PilhaR *pilhaReais, Tab *tabela);

main(){
	int i=0, cont=0, qtd=0, a=0, k=0;
	unsigned char linha[28], matriz[7][28], matrizPos[7][28];
	float valor[6];
	Tab tabela;
	PilhaC pilha;
	ListaR lista;
	PilhaR pilhaReais;
	
	gerarTabela(&tabela);
	criarPilhaChVazia(&pilha);
	criarPilhaRVazia(&pilhaReais);
	criarListaVazia(&lista);
	
	FILE *entrada;
	entrada = fopen("INFIXA.txt", "r");
	if(entrada == NULL){
		printf("\n nao encontrado \n");
	}else{
		printf("LEITURA DO ARQUIVO:\n");	
		while(fscanf(entrada,"%28s",linha)==1){
			printf("%s", linha);
			printf("\n");
			cont = 0;
				for(i=1; i<28; i++){
					matriz[a][i] = linha[i-1];
					if(matriz[a][i] == ';'){
						i=28;
						cont++; 
						matriz[a][0] = cont;
					}else{
						cont++;
					}
				}
			a++;
		}
		fclose(entrada);
	}
	
	conversaoInfixa(matrizPos, matriz, &lista, &pilha);
	mostrarPosfixa(matrizPos, &lista);	
	avaliarPosfixa(valor,matrizPos,&pilhaReais,&tabela);
	printf("\n\n");
	system("pause");
}

TokenIn obterToken(char ch){
    TokenIn result;
    switch (ch){
    	case '(': result = PaE;break;
        case ')': result = PaD;break;
        case ';': result = TerM;break;
        case '*': result = OpM;
        case '/': result = OpM;break;
        case '+': result = OpA;
        case '-': result = OpA;break;
        default: result = Ident;
    }
    return result;
}

void conversaoInfixa(char matrizPos[7][28], char matriz[7][28],ListaR *lista, PilhaC *pilha){
	int k=0, tam, i, cont,l,c, qtd;
	TokenIn token, token2;
	unsigned char ch, chp;
	bool ok, teste;
	
	while(k < 6){
		cont = 0;
		tam = matriz[k][0];
		for(i=1; i<=tam; i++){
			ch = matriz[k][i];
			token = obterToken(ch);
			switch(token){
				case 0:
					pushPilhaCh(pilha, ch); 
				break;
				case 2:
					ok = FALSE;
					do{
						if(verificarPilhaChVazia(pilha) == 1){
							pushPilhaCh(pilha, ch); 
							ok = TRUE;
						}else{
							chp = acessarTopo(pilha);
							if(chp == '('){
								pushPilhaCh(pilha, ch);
								ok = TRUE;
							}else{
								inserirElemento(lista, chp); cont++; 
								popPilhaCh(pilha);
							}
						}
					}while(ok == FALSE);
				break;
				case 3:
					 ok = FALSE;
					 do{
					 	if(verificarPilhaChVazia(pilha) == 1){
					 		pushPilhaCh(pilha, ch);
					 		ok = TRUE;
						}else{
							chp = acessarTopo(pilha);
							token2 = obterToken(chp);
							switch(token2){
								case 0:
									pushPilhaCh(pilha, ch);
					 				ok = TRUE;
								break;
								case 2:
									pushPilhaCh(pilha, ch);
					 				ok = TRUE;
								break;
								case 3:
									inserirElemento(lista, chp); cont++;
									popPilhaCh(pilha);
								break;
							}
						}
					 }while(ok == FALSE);
				break;
				case 5:
					while( verificarPilhaChVazia(pilha) == 0){
						chp = acessarTopo(pilha);
						popPilhaCh(pilha);
						inserirElemento(lista, ch); cont++;
					}
					inserirElemento(lista, ch); cont++;
				break;
				case 1:
					if(verificarPilhaChVazia(pilha) == 0){
						chp = acessarTopo(pilha);
						ok = FALSE;
						do{
							chp = acessarTopo(pilha);
							if(chp == '('){
								popPilhaCh(pilha);
								ok = TRUE;
							}else{
								inserirElemento(lista, chp); cont++;
								popPilhaCh(pilha);
							}
						}while(ok == FALSE);
					}
				break;
				default: 
					inserirElemento(lista, ch); cont++;
			}
		}
		matrizPos[k][0] = cont;
		k++;
	}
}

void mostrarPosfixa(char matrizPos[7][28], ListaR *lista){
	int a =0, i, qtd, k=0;
	printf("\nEXPRESSOES POSFIXA: \n");
	for(a=0; a<6;a++){
		qtd = matrizPos[a][0];
		i=0; 
		while( i < qtd){
			i++; k++;
			matrizPos[a][i] = lista->elemento[k];
			printf("%c",matrizPos[a][i]);
		}	
		printf("\n");	
	}
}

void avaliarPosfixa(float valor[6], char matriz[7][28], PilhaR *pilhaReais, Tab *tabela){
	int tamanho, i, k, a, p=1;
	TokenIn token;
	bool ok;
	char ch;
	float v1, v2, v;
	printf("\nAVALIACAO DA POSFIXA:\n");
	for(k=0; k<6; k++){
		tamanho = matriz[k][0];
		for(i=1; i<tamanho; i++){
			ch = matriz[k][i];
			token = obterToken(ch);
			if(ch == '3'){
				pushPilhaR(pilhaReais, 3);
			}
			if(token == 4){
				for(a=1; a<10; a++){
					if(ch == tabela->c_letra[a]){
						pushPilhaR(pilhaReais, tabela->c_valor[a]);
						a=10;
					}
				}
			}else{
			
				v1 = acessarTopoPilhaR(pilhaReais);
				popPilhaR(pilhaReais);
				v2 = acessarTopoPilhaR(pilhaReais);
				popPilhaR(pilhaReais);
				switch(ch){
					case '-':
						v = v2 - v1;
						pushPilhaR(pilhaReais, v);
					break;
					case '+':
						v = v2 + v1;
						pushPilhaR(pilhaReais, v);
					break;
					case '*':
						v = v2 * v1;
						pushPilhaR(pilhaReais, v);
					break;
					case '/':
						v = v2 / v1;
						pushPilhaR(pilhaReais, v);
					break;
				}
				
			}
		}
	
	valor[p] = acessarTopoPilhaR(pilhaReais);
	printf("Valor da posfixa %.3f\n", valor[p]);
	p++;
	}
}
