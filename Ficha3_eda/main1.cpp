#include "Matriz.h"
#define _CRT_SECURE_NO_WARNINGS_

#include "Complex.h"
#include <iostream>
using namespace std;

int main() {
    Matrix M;
    int n, m;
    char choice;
    std::cout << "Deseja introduzir uma matriz a partir de um ficheiro? (s/n): ";
    std::cin >> choice;

    if (choice == 's' || choice == 'S') {
        std::string fileName;
        std::cout << "Introduza o nome do ficheiro: ";
        std::cin >> fileName;

        Matrix M(fileName.c_str()); // Cria a matriz a partir do ficheiro
        if (M.rows() > 0 && M.cols() > 0) {
            std::cout << "Matriz lida com sucesso:\n";
            M.print(); // Exibe a matriz
            cout << "Introduza as dimensoes da matriz (n m): ";
            cin >> n >> m;
            Matrix A(n, m);
            cout << "Introduza os valores da matriz A (parte real e imaginaria):\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    double real, imag;
                    cin >> real >> imag;
                    A[i][j] = Complex(real, imag);
                }
            }
            cout << "\nMatriz A:\n";
            A.print();
            Matrix C = M + A;
            cout << "\nA + B:\n";
            C.print();

            Matrix D = M * A;
            cout << "\nA * B:\n";
            D.print();

            Matrix T = M.transpose();
            cout << "\nTransposta de M:\n";
            T.print();

            return 0;
        }
        else {
            std::cout << "Falha ao carregar a matriz a partir do ficheiro.\n";
        }
    }
    else {
        std::cout << "Operação cancelada. Matriz não criada.\n";
    }

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