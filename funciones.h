#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/*int mostrarElMenu (float ,float ,)
{

}*/
float sumaDeOperandos(float x,float y,float resultado)
{
    resultado = x+y;
    return resultado;
}
float restaDeOperandos(float x,float y,float resultado)
{
    resultado = x-y;
    return resultado;
}
float multiplicacionDeOperandos(float x,float y,float resultado)
{
    resultado = x*y;
    return resultado;
}
float divisionDeOperandos(float x,float y,float resultado)
{
    resultado = x/y;
    return resultado;
}
  int factorialDeOperando(int x,int y,int resultado)
{
    int i=0;
    int numeroAFactorial;
    int factorial;

    for(i=1;i<=numeroAFactorial;i++)
    {
        printf("Ingrese el numero al que quiera sacar su factorial.");
        scanf("%d",&numeroAFactorial);
        factorial=factorial*i;
        printf("el factorial del numero %d es %d",numeroAFactorial,factorial);
        factorial=resultado;
    }
    return resultado;
}


#endif // FUNCIONES_H_INCLUDED
