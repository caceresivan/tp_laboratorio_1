#include <stdio_ext.h>
#include <stdlib.h>
#include "funciones.h"

/**
*\mostarMenu: Muestra el menu de una calculadora
             que pide y muestra dos operandos.

*\brief: verifica que el usuario no ingrese
        un dato incorrecto en el menu.

*\param: mensaje Es el mensaje a ser mostrado
         informando sobre el resultado de cada
         opcion o de error en caso de que
         sea necesario.

*\return: Se devuelve la opcion que el
          usuario haya elegido.
*/
int mostrarMenu(float numeroA,float numeroB,int *respuesta)
{
    int opcion;

    printf("1- Ingresar 1er operando. (A= %.1f)\n",numeroA);
    printf("2- Ingresar 2do operando. (B= %.1f)\n",numeroB);
    printf("3- Calcular todos las siguientes opciones.\n");
    printf("a) Calcular la suma (A+B).\n");
    printf("b) Calcular la resta (A-B).\n");
    printf("c) Calcular la multiplicacion (A*B).\n");
    printf("d) Calcular la division (A/B).\n");
    printf("e) Calcular el factorial (A!).\n");
    printf("4- Mostrar resultados.\n");
    printf("5- Salir.\n");
    printf("Elegir una opcion.\n");
    if(scanf("%d",&opcion)!=1 || (opcion<1 && opcion>5))
    {
        __fpurge(stdin);
        system("clear");
        printf("Error, ingrese una opcion entre 1 y 5.\n");

        mostrarMenu(numeroA,numeroB,&opcion);
    }
    system("clear");
    *respuesta=opcion;
    return 0;
}
/**
*\verificarNumeroFlotante: Pide al usuario que ingrese
                           un numero y lo verifica.

*\mensaje: Mensaje de error en caso de que
           se ingrese otra cosa que no sea
           un numero.Se pide nuevamente
           ingreso del numero.
*\return: Se devuelve un numero flotante.
*/
int verificarNumeroFlotante(float *resultado)
{
    float numFlotante;
    printf("Ingrese un operando.");
    while(scanf("%f",&numFlotante)!=1)
    {
        __fpurge(stdin);
        system("clear");
        printf("Error, ingrese numeros, no letras.\n");
        printf("Por favor ingrese un operando.");
    }
    *resultado=numFlotante;
    return 0;
}
/**
*\sumaDeDosNumeros: Se ingresan dos numeros
                    y se suman.

*\param: variables: tipo de variable y nombre
                    de la misma.

*\param: puntero: puntero donde se va a guardar
                  el resultado del calculo de
                  la funcion.

*\return: Se devuelve el resultado de la funcion.
*/
float sumaDeDosNumeros(float x,float y,float *resultado)
{
    float suma;
    suma=x+y;
    *resultado=suma;
    return 0;
}
/**
*\restaDeDosNumeros: Se ingresan dos numeros
                    y se restan.

*\param: variables: tipo de variable y nombre
                    de la misma.

*\param: puntero: puntero donde se va a guardar
                  el resultado del calculo de
                  la funcion.

*\return: Se devuelve el resultado de la funcion.
*/

float restaDosNumeros(float x,float y,float *resultado)
{
    float resta;
    resta=x-y;
    *resultado=resta;
    return 0;
}
/**
*\divisionDeDosNumeros: Se ingresan dos numeros
                        y se dividen.

*\param: variables: tipo de variable y nombre
                    de la misma.

*\param: puntero: puntero donde se va a guardar
                  el resultado del calculo de
                  la funcion.

*\mensaje: Mensaje de error en caso
           de que no se pueda dividir
           por cero.

*\return: Se devuelve el resultado de la funcion.
*/

float divisonDeDosNumeros(float x,float y,float *resultado)
{
    float division;
    if(x==0 || y==0)
    {
        printf("\n No se puede dividir por 0.");
        division=0;
    }
    else
    {
        division = x/y;
        *resultado=division;
    }
    return 0;
}
/**
*\multiplicacionDeDosNumeros: Se ingresan dos numeros
                              y se multiplican.

*\param: variables: tipo de variable y nombre
                    de la misma.

*\param: puntero: puntero donde se va a guardar
                  el resultado del calculo de
                  la funcion.
*\return: Se devuelve el resultado de la funcion.
*/

float multiplicacionDeDosNumeros(float x,float y,float *resultado)
{
    float multiplicacion;
    multiplicacion=x*y;
    *resultado=multiplicacion;
    return 0;
}
/**
*\calculoFactorial: Se ingresa un numero y
                    se calcula su factorial.

*\param: variables: tipo de variable y nombre
                    de la misma.

*\param: puntero: puntero donde se va a guardar
                  el resultado del calculo de
                  la funcion.

*\mensaje: Mensaje de error en caso de
           que no se pueda calcular el factorial
           de cero o un numero negativo.

*\return: Se devuelve el resultado de la funcion.
*/

int calculoFactorial(float numero,int*resultado)
{
    int factorial;

    if(numero==1)
    {
        return 1;
    }
    if(numero<=0)
    {
        printf("\n\n");
        printf("No se puede calcular factorial de 0 o un numero negativo.");
        return 0;
    }
    else
    {   factorial=1;
        int i;
        for(i=1;i<=numero;i++)
        {
            factorial=factorial*i;
        }
    }
    *resultado=factorial;
    return 0;
}
