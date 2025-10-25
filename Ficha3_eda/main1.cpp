#include "Matriz.h"
#define _CRT_SECURE_NO_WARNINGS_

#include "Complex.h"
#include <iostream>
using namespace std;

int main() {
    Matrix M;
    int n, m;
    /*
    int c;
    cout << "Deseja intruduzir uma matriz ja existente? [1 (sim) | 0 (nao)]";
    cin >> c;
    
    if (c == 1) {
        M.Ler("yh.txt");
    }
    else*/
    cout << "Introduza as dimensoes da matriz (n m): ";
    cin >> n >> m;
    
    Matrix A(n, m), B(n, m);

    cout << "Introduza os valores da matriz A (parte real e imaginaria):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            double real, imag;
            cin >> real >> imag;
            A[i][j] = Complex(real, imag);
        }
    }

    cout << "Introduza os valores da matriz B (parte real e imaginaria):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            double real, imag;
            cin >> real >> imag;
            B[i][j] = Complex(real, imag);
        }
    }

    cout << "\nMatriz A:\n";
    A.print();
    cout << "\nMatriz B:\n";
    B.print();

    Matrix C = A + B;
    cout << "\nA + B:\n";
    C.print();

    Matrix D = A * B;
    cout << "\nA * B:\n";
    D.print();

    Matrix T = A.transpose();
    cout << "\nTransposta de A:\n";
    T.print();

    return 0;
}