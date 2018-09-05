#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
   float numeroA;
   float numeroB;
   float suma;
   float resta;
   float multiplicacion;
   float division;
   int factorialA;
   int factorialB;
   int opcion;

   numeroA=0;
   numeroB=0;

   do
   {
    mostrarMenu(numeroA,numeroB,&opcion);

    switch(opcion)
    {
        case 1:
            verificarNumeroFlotante(&numeroA);
            system("clear");
                break;
        case 2:
            verificarNumeroFlotante(&numeroB);
            system("clear");
                break;
        case 3:
            sumaDeDosNumeros(numeroA,numeroB,&suma);
            restaDosNumeros(numeroA,numeroB,&resta);
            divisonDeDosNumeros(numeroA,numeroB,&division);
            multiplicacionDeDosNumeros(numeroA,numeroB,&multiplicacion);
            calculoFactorial(numeroA,&factorialA);
            calculoFactorial(numeroB,&factorialB);
                break;
        case 4:
            system("clear");
            printf("El resultado de la suma A+B es: %.1f \n",suma);
            printf("El resultado de la resta A-B es: %.1f \n",resta);
            printf("La division entre los operandos A/B es: %.1f \n",division);
            printf("El resultado de la multiplicacion A*B es: %.1f \n",multiplicacion);
            printf("El factorial de A es: %d \n",factorialA);
            printf("El factorial de A es: %d \n\n",factorialB);
                break;
            printf("Pulse una tecla para continuar. \n");
            getchar();
            getchar();
            system("clear");
    }
   }
   while(opcion!=5);
   printf("Nos vemos.");

    return 0;
}

