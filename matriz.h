matriz.h
Ano passado
16 de fev. de 2020

Você fez o upload de 1 item
C
matriz.h
#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED
//==============================================================================================================
/*
	Esse é um arquivo de cabeçalho que contem funções ja prontas para trabalhar com matrizes.
	Você pode usar diretamente incluindo-o nos seus programas ou pode analizar a lógica e a
	sintaxe para replica-la. Caso queira incluir use #include "matriz.h"  .
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

class matriz{
	private:
		vector<vector<double> > matriz;
		int determinant( double** matrix, int n);
	public://======================= AQUI ESTAO AS FUNÇOES INTRA MATRIZ =============================================
		void imprimir();
		void dimensionar(int linhas, int colunas);
		void atribuir();
		void trocarLL(int primeira_linha, int segunda_linha);
		void trocarCC(int primeira_coluna, int segunda_coluna);
		void multiplicar(double constante=1);
		void atribuir(double constante);
		int  contarL();
		int  contarC();
		void transpor();
		double** retornar();
		void atribuir(double **matri);
		double retornar(int linha, int coluna);
		void atribuir(int linha, int coluna, double valor);
		int determinante();
		void atribuir(string identidade);
		void triangularS();
		void triangularI();

};
void matriz::triangularS(){
	for(int l=0;l<matriz.size();l++){
		for(int c=0;c<matriz[l].size();c++){
			if(c<l)
				matriz[l][c]=0;
			}
		}
}
void matriz::triangularI(){
	for(int l=0;l<matriz.size();l++){
		for(int c=0;c<matriz[l].size();c++){
			if(c>l)
				matriz[l][c]=0;
			}
		}
}
void matriz::atribuir(string identidade){
	for(int l=0;l<matriz.size();l++){
		for(int c=0;c<matriz[l].size();c++){
			if(l==c)
				matriz[l][c]=1;
			else matriz[l][c]=0;
		}
	}
}
int matriz::determinante(){
	if(matriz.size()==matriz[0].size()){
		double** matri;
    	matri=(double**)calloc(matriz.size(),sizeof(double*));
    	for(int i=0;i<matriz.size();i++){
	        matri[i]=(double*)calloc(matriz[i].size(),sizeof(double));
    	}
		for(int l=0;l<matriz.size();l++){
			for(int c=0;c<matriz[l].size();c++){
				matri[l][c]=matriz[l][c];
			}
		}
		int determinante,ordem=matriz.size();
		determinante=determinant(matri,ordem);
		return determinante;
	}else{
		cout<<endl<<" ***Erro: Esta matriz nao e quadrada e nao tem determinante.***"<<endl;
	}
}
void matriz::atribuir(int linha, int coluna, double valor){
	int l=linha-1;
	int c=coluna-1;
	if ((l<matriz.size() && c<matriz[0].size()) && (l>=0 && c>=0)){
			matriz[l][c]=valor;
	}else{ cout<<endl<<" ***Erro: Linha ou Coluna escolhida nao existe nesta matriz.***"<<endl;}
}
double matriz::retornar(int linha, int coluna){
	int l=linha-1;
	int c=coluna-1;
	if ((l<matriz.size() && c<matriz[0].size()) && (l>=0 && c>=0)){
		double elemento;
			elemento=matriz[l][c];
			return elemento;
	}else{ cout<<endl<<" ***Erro: Linha ou Coluna escolhida nao existe nesta matriz.***"<<endl;}
}
void matriz::atribuir(double **matri){
	for(int l=0;l<matriz.size();l++){
		for(int c=0;c<matriz[l].size();c++){
			matriz[l][c]=matri[l][c];
		}
	}
}

double** matriz::retornar(){
	double** matri;
	matri=(double**)calloc(matriz.size(),sizeof(double*));
	for(int i=0;i<matriz.size();i++){
	    matri[i]=(double*)calloc(matriz[i].size(),sizeof(double));
	}
	for(int l=0;l<matriz.size();l++){
		for(int c=0;c<matriz[l].size();c++){
			matri[l][c]=matriz[l][c];
		}
	}
	return matri;
}
void matriz::transpor(){
	vector <vector<double> > matriz_auxiliar;
	matriz_auxiliar.resize(matriz[0].size(),vector<double>(matriz.size()));
	for (int l=0;l<matriz.size();l++) {
    	for (int c=0;c<matriz[l].size();c++) {
				matriz_auxiliar[c][l] = matriz[l][c];
      }
    }
    matriz=matriz_auxiliar;
}
int matriz::contarC(){
	return matriz[0].size();
}
int matriz::contarL(){
	return matriz.size();
}
void matriz::multiplicar(double constante){
	for(int l=0;l<matriz.size();l++){
		for(int c=0;c<matriz[l].size();c++){
			matriz[l][c]*=constante;
		}
	}
}
void matriz::atribuir(double constante){
	for(int l=0;l<matriz.size();l++){
		for(int c=0;c<matriz[l].size();c++){
			matriz[l][c]=constante;
		}
	}
}
void matriz::trocarCC(int primeira_coluna, int segunda_coluna){
	int c1=primeira_coluna-1;
	int c2=segunda_coluna-1;
	if ((c1<matriz[0].size() && c2<matriz[0].size()) && (c1>=0 && c2>=0)){
		double troca;
		for(int l=0;l<matriz.size();l++){
			troca=matriz[l][c1];
			matriz[l][c1]=matriz[l][c2];
			matriz[l][c2]=troca;
		}
	}else{ cout<<endl<<" ***Erro: O numero das colunas devem entre zero e "<<matriz[0].size()<<".***"<<endl;}
}

void matriz::trocarLL(int primeira_linha, int segunda_linha){
	int l1=primeira_linha-1;
	int l2=segunda_linha-1;
	if ((l1<matriz.size() && l2<matriz.size()) && (l1>=0 && l2>=0)){
		double troca;
		for(int c=0;c<matriz[0].size();c++){
			troca=matriz[l1][c];
			matriz[l1][c]=matriz[l2][c];
			matriz[l2][c]=troca;
		}
	}else{ cout<<endl<<" ***Erro: O numero das linhas devem entre zero e "<<matriz.size()<<".***"<<endl;}
}

void matriz::atribuir(){
	cout<<endl<<" Vamos atribuir valores na matriz. "<<endl;
	for(int l=0;l<matriz.size();l++){
		for(int c=0;c<matriz[l].size();c++){
			cout<<" Digite o valor da "<<l+1<<" linha e da "<<c+1<<" coluna."<<endl;
			cin>>matriz[l][c];
		}
		cout<<endl;
	}
	cout<<endl;
}
void matriz::dimensionar(int linhas, int colunas){
	if (linhas>0 && colunas>0){
		matriz.resize(linhas,vector<double>(colunas));
	}else{
	cout<<endl<<" ***Erro: O numero de linhas e colunas deve ser maior que zero.***"<<endl;
	}
}
void matriz::imprimir(){
	cout<<endl<<" A matriz eh : "<<endl;
	for(int l=0;l<matriz.size();l++){
		for(int c=0;c<matriz[l].size();c++){
			cout<<matriz[l][c]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
//============================= AQUI ESTÃO AS FUNÇÕES INTER MATRIZ ===========================================

matriz somar(matriz m1,matriz m2){
	if (m1.contarC()==m2.contarC() && m1.contarL()==m2.contarL()){
		matriz somar;
		somar.dimensionar(m1.contarL(),m1.contarC());
		for(int l=1;l<=m1.contarL();l++){
			for(int c=1;c<=m1.contarC();c++){
				somar.atribuir(l,c,m1.retornar(l,c)+m2.retornar(l,c));
			}
		}
		return somar;
	}else{
		cout<<endl<<" ***Erro: O numero de linhas e colunas das matrizes devem ser iguais.***"<<endl;
	}
}
matriz subtrair(matriz m1,matriz m2){
	if (m1.contarC()==m2.contarC() && m1.contarL()==m2.contarL()){
		matriz subtrair;
		subtrair.dimensionar(m1.contarL(),m1.contarC());
		for(int l=1;l<=m1.contarL();l++){
			for(int c=1;c<=m1.contarC();c++){
				subtrair.atribuir(l,c,m1.retornar(l,c)-m2.retornar(l,c));
			}
		}
		return subtrair;
	}else{
		cout<<endl<<" ***Erro: O numero de linhas e colunas das matrizes devem ser iguais.***"<<endl;
	}
}
matriz multiplicar(matriz m1,matriz m2){
	if (m1.contarC()==m2.contarL()){
		matriz multiplicar;
		multiplicar.dimensionar(m1.contarL(),m2.contarC());
		for(int l=1;l<=m1.contarL();l++){
			for(int c=1;c<=m2.contarC();c++){
				double acumula=0;
				for(int i=1;i<=m1.contarC();i++){
					acumula+=m1.retornar(l,i)*m2.retornar(i,c);
				}
				multiplicar.atribuir(l,c,acumula);
			}
		}
		return multiplicar;
	}else{
		cout<<endl<<
		" ***Erro: O numero de linhas da primeira matriz deve ser igual ao numero de colunas da segunda matriz.***"<<
		endl;
	}
}

int matriz::determinant( double** matrix, int n) {   
    int det = 0;
    double **submatrix;
    submatrix=(double**)calloc(n,sizeof(double*));
    for(int i=0;i<n;i++){
        submatrix[i]=(double*)calloc(n,sizeof(double));
    }
    if (n == 2)
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    else {
        for (int x = 0; x < n; x++) {
            int subi = 0; 
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x)
                    continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, n - 1 ));
        }
    }
    return det;
}

//==============================================================================================================
#endif // MATRIZ_H_INCLUDED
