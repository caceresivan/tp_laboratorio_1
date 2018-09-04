#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
   float operandoA;
   float operandoB;
   float sumaDeOperandos;
   float restaDeOperandos;
   float multiplicacionDeOperandos;
   float divisionDeOperandos;
   int factorialDeOperando;

    printf("Ingrese el primer numero.");
    scanf("%f",operandoA);
    printf("Ingrese el segundo numero.");
    scanf("%f",operandoB);
    sumaDeOperandos=operandoA+operandoB;
    restaDeOperandos=operandoA-operandoB;
    multiplicacionDeOperandos=operandoA*operandoB;
    divisionDeOperandos=operandoA/operandoB;

    return 0;
}

