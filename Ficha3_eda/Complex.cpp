#include "Complex.h"
#define _USE_MATH_DEFINES 
#include <math.h>
#include <stdio.h>
#include <cmath>



Complex::Complex() : re(0), im(0) {} // Construtor sem parâmetros: inicializa o complexo como (0 + 0i)
Complex::Complex(double r) : re(r), im(0) {} // Construtor com parte real e parte imaginária nula
Complex::Complex(double r, double i) : re(r), im(i) {} // Construtor com parte real e imaginária

double Complex::real() { return re; }
double Complex::imag() { return im; }

void Complex::print() {
    if (im >= 0)
        printf("(%.2f + %.2fi)", re, im);
    else
        printf("(%.2f - %.2fi)", re, -im);
}

Complex Complex::conjugate() {
    return Complex(re, -im);
} 

double Complex::modulus() {
    return std::sqrt(re * re + im * im);
}

double Complex::arg_rad() {
    return std::atan2(im, re);
}

double Complex::arg_deg() {
    return std::atan2(im, re) * (180.0 / M_PI);
}

Complex Complex::operator+(Complex& c) {
    return Complex(re + c.re, im + c.im);
}

Complex Complex::operator-(Complex& c) {
    return Complex(re - c.re, im - c.im);
}

Complex Complex::operator-() {
    return Complex(-re, -im);
}

Complex Complex::operator*(Complex& c) {
    return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
}

Complex Complex::operator*(double k) {
    return Complex(re * k, im * k);
}

Complex Complex::operator/(Complex& c) {
    double denom = c.re * c.re + c.im * c.im;
    return Complex((re * c.re + im * c.im) / denom, (im * c.re - re * c.im) / denom);
}

Complex Complex::operator/(double k) {
    return Complex(re / k, im / k);
}

Complex Complex::operator+=(Complex& c) {
    re += c.re;
    im += c.im;
    return *this;
}

Complex Complex::operator*=(Complex& c) {
    double tempRe = re * c.re - im * c.im;
    double tempIm = re * c.im + im * c.re;
    re = tempRe;
    im = tempIm;
    return *this;
}
