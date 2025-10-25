#pragma once
#include "Complex.h"
#include <stdio.h>
class Matrix
{
private:
	int nrows, ncols;
	Complex** elems;
	void create_elems(int lines, int cols);
	void delete_elems();
public:
	/* construtor por omissão */
	Matrix();
	/* inicia uma matriz de dimensão rows x cols, com elementos nulos */
	Matrix(int rows, int cols);
	/* faz a leitura dos dados de uma matriz, a partir de um ficheiro */
	Matrix(const char file_name[]);
	/* construtor por cópia */
	Matrix(const Matrix& m2);
	/* operador de atribuição */
	const Matrix& operator = (const Matrix& m2);
	~Matrix(); // destrutor
	int rows() { return nrows; } //devolve nº de linhas da matriz
	int cols() { return ncols; } //devolve nº de colunas da matriz
	/* devolve, ou atribui valor, ao elemento [i][j] da matriz */
	Complex* operator [](int row);
	/* Soma de duas matrizes da mesma ordem, mantendo a original*/
	Matrix operator +(const Matrix& m2);
	/* produto de 2 matrizes, mantendo a original */
	Matrix operator *(const Matrix& m2);
	/* devolve a matriz transposta, mantendo a original*/
	Matrix transpose();
	void print(); // faz o output da matriz para o ecrã
};