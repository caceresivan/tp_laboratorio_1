#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "employee.h"

int menu(int* opcion);
int main()
{
    Employee employees[CANTIDADEMPLOYEES];
    int opcion;
    char auxName[50];
    char auxLastName[50];
    int auxId;
    int auxSector;
    float auxSalary;
    int mayorAPromedio;
    float promedioSalarios;
    float totalSalarios;

    initEmployees(employees,CANTIDADEMPLOYEES);
    ingresoForzado(employees,CANTIDADEMPLOYEES,"ivan","caceres",generarId(),6000,2);
    ingresoForzado(employees,CANTIDADEMPLOYEES,"juan","caceres",generarId(),3000,2);
    ingresoForzado(employees,CANTIDADEMPLOYEES,"facundo","caceres",generarId(),10000,1);
    ingresoForzado(employees,CANTIDADEMPLOYEES,"jorge","caceres",generarId(),2500,3);
    ingresoForzado(employees,CANTIDADEMPLOYEES,"pedro","caceres",generarId(),5000,1);
    ingresoForzado(employees,CANTIDADEMPLOYEES,"hernan","caceres",generarId(),18000,1);
    ingresoForzado(employees,CANTIDADEMPLOYEES,"alfredo","caceres",generarId(),10000,2);
    ingresoForzado(employees,CANTIDADEMPLOYEES,"jose","caceres",generarId(),30000,3);

    do
    {
        system("clear");
        menu(&opcion);
        switch(opcion)
        {
            case 1:
                if(utn_getLetras(auxName,CANTIDADEMPLOYEES,5,"Ingrese nombre:  ","Error,ingrese nombre.")==0&&
                   utn_getLetras(auxLastName,CANTIDADEMPLOYEES,5,"Ingrese apellido:  ","Error,ingrese apellido.")==0&&
                   utn_getFloat(&auxSalary,"Ingrese sueldo:  ","Error,ingrese sueldo.",0,999999,5)==0&&
                   utn_getInt(&auxSector,"Ingrese sector:  ","Error,ingrese sector entre 1 y 3.",1,3,5)==0)
                   {
                    auxId=generarId();
                   }
                altaEmployee(employees,CANTIDADEMPLOYEES,auxId,auxName,auxLastName,auxSalary,auxSector);
                break;
            case 2:
                if(utn_getInt(&auxId,"Ingrese ID a modificar:  ","Error,ingrese ID valido.",-1,999,5)==0)
                {
                    modificarById(employees,CANTIDADEMPLOYEES,auxId);
                }
                break;
            case 3:
                if(utn_getInt(&auxId,"Ingrese ID de empleado a borrar:  ","Error,ingrese ID valido.",-1,999,5)==0)
                {
                    bajaEmployee(employees,CANTIDADEMPLOYEES,auxId);
                }
                break;
            case 4:
                ordenByLastNameOrSector(employees,CANTIDADEMPLOYEES,1);
                printEmployees(employees,CANTIDADEMPLOYEES);
                emp_totalPromedioYMayoresAlPromedio(employees,CANTIDADEMPLOYEES,&mayorAPromedio,&promedioSalarios,&totalSalarios);
                printf("\nTotal de salarios: %.2f \tpromedio de salarios: %.2f\nSalarios mayores al promedio: %d",totalSalarios,promedioSalarios,mayorAPromedio);
                getchar();
                break;
        }
    }while(opcion != 5);
    return 0;
}

int menu(int* opcion)
{
    printf("\n 1) Altas \n 2) Modificar \n 3) Baja \n 4) Informar \n 5) salir");
    utn_getInt(opcion,"\n Ingrese opcion: ","\n Error, ingrese opcion valida.",1,5,5);

    return 0;
}
