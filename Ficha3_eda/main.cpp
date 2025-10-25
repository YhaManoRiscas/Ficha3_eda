#include "Complex.h"

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <cmath>


int main() {
    double re1, im1, re2, im2;

    printf("Introduza a parte real do primeiro numero complexo: ");
    scanf("%lf", &re1);
    printf("Introduza a parte imaginária do primeiro numero complexo: ");
    scanf("%lf", &im1);

    printf("Introduza a parte real do segundo numero complexo: ");
    scanf("%lf", &re2);
    printf("Introduza a parte imaginária do segundo numero complexo: ");
    scanf("%lf", &im2);

    Complex a(re1, im1);
    Complex b(re2, im2);

    printf("\nNumero complexo A: ");
    a.print();
    printf("Numero complexo B: ");
    b.print();

    printf("\nConjugado de A: ");
    a.conjugate().print();
    printf("Modulo de A: %.2f\n", a.modulus());
    printf("Argumento de A (radianos): %.2f\n", a.arg_rad());
    printf("Argumento de A (graus): %.2f\n", a.arg_deg());

    printf("\nA + B = ");
    (a + b).print();
    printf("A - B = ");
    (a - b).print();
    printf("A * B = ");
    (a * b).print();
    printf("A / B = ");
    (a / b).print();

    printf("\nNegacao de A: ");
    (-a).print();

    a += b;
    printf("Apos A += B, A = ");
    a.print();

    a *= b;
    printf("Apos A *= B, A = ");
    a.print();

    return 0;
}
