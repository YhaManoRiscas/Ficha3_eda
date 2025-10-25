#pragma once
class Complex
{
	
	private:
		double re, im;
	public:
		/* construtor sem par�metros. Cria um complexo nulo */
		Complex();
		/* Cria um complexo com o coeficiente imagin�rio nulo */
		Complex(double r);
		/* Cria um complexo com coeficientes real e imagin�rio */
		Complex(double r, double i);
		/* devolve a parte real do complexo */
		double real();
		/* devolve a parte imagin�ria do complexo */
		double imag();
		/* escreve no ecr� o complexo na forma (a + bi) */
		void print();
		/* devolve o conjugado do complexo */
		Complex conjugate();
		/* devolve o m�dulo do complexo */
		double modulus();
		/* devolve o argumento do complexo, em radianos */
		double arg_rad();
		/* devolve o argumento do complexo, em graus */
		double arg_deg();
		/* devolve a soma de 2 complexox */
		Complex operator + (Complex& c);
		/* devolve a diferen�a de 2 complexos*/
		Complex operator - (Complex& c);
		/* devolve o sim�trico do complexo */
		Complex operator-();
		/* devolve o produto de 2 complexos */
		Complex operator * (Complex& c);
		/* devolve o produto de um complexo por um escalar */
		Complex operator* (double k);
		/* devolve a divis�o do 2 complexos */
		Complex operator / (Complex& c);
		/* devolve a divis�o do complexo por um escalar*/
		Complex operator / (double k);
		/* adiciona ao complexo um outro complexo, devolvendo o resultado */
		Complex operator += (Complex& c);
		/* multiplica��o do complexo por outro complexo, devolvendo o resultado */
		Complex operator *= (Complex& c);
	
};

