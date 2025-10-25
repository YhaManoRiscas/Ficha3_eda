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
	/* construtor por omiss�o */
	Matrix();
	/* inicia uma matriz de dimens�o rows x cols, com elementos nulos */
	Matrix(int rows, int cols);
	/* faz a leitura dos dados de uma matriz, a partir de um ficheiro */
	Matrix(const char file_name[]);
	/* construtor por c�pia */
	Matrix(const Matrix& m2);
	/* operador de atribui��o */
	const Matrix& operator = (const Matrix& m2);
	~Matrix(); // destrutor
	int rows() { return nrows; } //devolve n� de linhas da matriz
	int cols() { return ncols; } //devolve n� de colunas da matriz
	/* devolve, ou atribui valor, ao elemento [i][j] da matriz */
	Complex* operator [](int row);
	/* Soma de duas matrizes da mesma ordem, mantendo a original*/
	Matrix operator +(const Matrix& m2);
	/* produto de 2 matrizes, mantendo a original */
	Matrix operator *(const Matrix& m2);
	/* devolve a matriz transposta, mantendo a original*/
	Matrix transpose();
	void print(); // faz o output da matriz para o ecr�
};