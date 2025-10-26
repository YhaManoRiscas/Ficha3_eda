#include "Matriz.h"
#include <iostream>
#include <fstream>

using namespace std;

// Private helper functions
void Matrix::create_elems(int lines, int cols) {
    nrows = lines;
    ncols = cols;
    elems = new Complex * [nrows];
    for (int i = 0; i < nrows; i++) {
        elems[i] = new Complex[ncols];
    }
}

void Matrix::delete_elems() {
    if (elems != nullptr) {
        for (int i = 0; i < nrows; i++) {
            delete[] elems[i];
        }
        delete[] elems;
        elems = nullptr;
        nrows = 0;
        ncols = 0;
    }
}

// Default constructor
Matrix::Matrix() : nrows(0), ncols(0), elems(nullptr) {}

// Constructor com linhas e colunas, inicializa a zero
Matrix::Matrix(int rows, int cols) {
    create_elems(rows, cols);
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            elems[i][j] = Complex(0.0, 0.0);  // Assuming Complex has constructor Complex(double, double)
        }
    }
}

// Constructor por ficheiro
Matrix::Matrix(const char file_name[]) : nrows(0), ncols(0), elems(nullptr) {
    std::ifstream in(file_name);
    if (!in.is_open()) {
        std::cerr << "Erro ao abrir o ficheiro: " << file_name << std::endl;
        return; // Retorna uma matriz vazia em caso de erro
    }

    // Lê as dimensões da primeira linha
    in >> nrows >> ncols;
    if (in.fail() || nrows <= 0 || ncols <= 0) {
        std::cerr << "Dimensões inválidas no ficheiro." << std::endl;
        in.close();
        return; // Retorna uma matriz vazia em caso de erro
    }

    // Aloca a matriz
    create_elems(nrows, ncols);

    // Lê os elementos complexos do ficheiro
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j) {
            double real, imag;
            in >> real >> imag; // Lê a parte real e imaginária de cada elemento
            if (in.fail()) {
                std::cerr << "Erro ao ler elemento [" << i << "][" << j << "]." << std::endl;
                delete_elems(); // Libera memória alocada
                nrows = 0;
                ncols = 0;
                elems = nullptr;
                in.close();
                return; // Aborta em caso de erro
            }
            elems[i][j] = Complex(real, imag); // Assume que Complex tem um construtor que aceita (real, imag)
        }
    }

    in.close();
}

// Copy constructor
Matrix::Matrix(const Matrix& m2) : nrows(0), ncols(0), elems(nullptr) {
    *this = m2;
}

// Assignment operator
const Matrix& Matrix::operator=(const Matrix& m2) {
    if (this == &m2) return *this;
    delete_elems();
    create_elems(m2.nrows, m2.ncols);
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            elems[i][j] = m2.elems[i][j];
        }
    }
    return *this;
}

// Destructor
Matrix::~Matrix() {
    delete_elems();
}

// Acesso operator
Complex* Matrix::operator[](int row) {
    return elems[row];  // No bounds checking as per typical assignment
}

// Somador operator
Matrix Matrix::operator+(const Matrix& m2) {
    if (nrows != m2.nrows || ncols != m2.ncols) {
        cerr << "Matrices dimensions incompatible for addition" << endl;
        return Matrix();  // Return empty matrix
    }
    Matrix result(nrows, ncols);
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            result.elems[i][j] = elems[i][j] + m2.elems[i][j];  // Assuming Complex has operator+
        }
    }
    return result;
}

// Multiplicador operator
Matrix Matrix::operator*(const Matrix& m2) {
    if (ncols != m2.nrows) {
        cerr << "Matrices dimensions incompatible for multiplication" << endl;
        return Matrix();  // Return empty matrix
    }
    Matrix result(nrows, m2.ncols);
    Complex sum;
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < m2.ncols; j++) {
            Complex sum2(0.0,0.0);
          
            for (int k = 0; k < ncols; k++) {
                sum =  (elems[i][k] * m2.elems[k][j]);  // Assuming Complex has operator+ and operator*
                sum2 += sum;
            }
            result.elems[i][j] = sum2;
        }
    }
    return result;
}


// Transposta
Matrix Matrix::transpose() {
    Matrix result(ncols, nrows);
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            result.elems[j][i] = elems[i][j];
        }
    }
    return result;
}

// Print matrix
void Matrix::print() {
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            cout << "\t";
            elems[i][j].print();  // Assuming Complex has a print() method
            cout << "\t"; // Or use space/tab for separation
        }
        cout << "\n\n";
    }
}

