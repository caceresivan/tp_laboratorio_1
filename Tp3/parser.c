#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char auxId[1024];
    char auxNombre[1024];
    char auxHorasTrabajadas[1024];
    char auxSueldo[1024];
    int flagOnce=1;
    Employee* auxEmpleado;
    int retorno=0;


    while(!feof(pFile))
    {
        if(flagOnce)
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,
                                                      auxNombre,
                                                      auxHorasTrabajadas,
                                                      auxSueldo);
            flagOnce=0;
        }
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,
                                                      auxNombre,
                                                      auxHorasTrabajadas,
                                                      auxSueldo)==4)
        {
            auxEmpleado=employee_newParametros(auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
            if(auxEmpleado!=NULL)
            {
                ll_add(pArrayListEmployee,auxEmpleado);
                retorno=1;
            }
            else
            {
                break;
            }
        }
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee *pEmpleado;
    do
    {
        pEmpleado = Employee_new();
        fread(pEmpleado,sizeof(Employee),1,pFile);
        ll_add(pArrayListEmployee,pEmpleado);
    }while(!feof(pFile));

    return 1;
}
