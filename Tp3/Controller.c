#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "biblioteca.h"
#include "Controller.h"

static int controller_saveEmpAsText(FILE* pFile,LinkedList* pArrayEmployee);
static int controller_saveEmpAsBinary(FILE* pFile,LinkedList* pArrayEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE *pArchivo;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pArchivo=fopen(path,"r");
        if(pArchivo!=NULL)
        {
            parser_EmployeeFromText(pArchivo,pArrayListEmployee);
            fclose(pArchivo);
            retorno=0;
        }
        else
        {
            printf("No se puede abrir archivo.");
        }
    }

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE *pArchivo;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pArchivo=fopen(path,"rb");
        if(pArchivo!=NULL)
        {
            parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
            fclose(pArchivo);
            retorno=0;
        }
        else
        {
            printf("No se puede abrir archivo.");
        }
    }

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee *pEmployee;
    char auxNombre[50];
    int auxSueldo;
    int auxHorasTrabajadas;
    char auxId[50];
    int retorno=-1;


    if(pArrayListEmployee!=NULL&&
       !utn_getLetras(auxNombre,50,5,"Ingrese Nombre: ","\nError")&&
       !utn_getInt(&auxSueldo,"Ingrese Sueldo: ","Error...",0,10000,5)&&
       !utn_getInt(&auxHorasTrabajadas,"Ingrese horas trabajadas: ","Error...",0,10000,5))
       {
            pEmployee=employee_newParametros(auxId,
                                             auxNombre,
                                             (char*)auxHorasTrabajadas,
                                             (char*)auxSueldo);
       }
       if(pEmployee!=NULL)
       {
            ll_add(pArrayListEmployee,pEmployee);
            retorno=0;
       }
       else
       {
            Employee_delete(pEmployee);
            pEmployee=NULL;
       }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    char pNombre[50];
    int pId;
    int auxId;
    int pSueldo;
    int pHorasTrabajadas;
    Employee* pEmpleado;
    int limite=ll_len(pArrayListEmployee);
    int retorno=-1;

    if(pArrayListEmployee!=NULL && !utn_getInt(&auxId,"Ingrese id de empleado a modificar: ","Error,ingrese id valido.",0,9999,5))
    {
        for(i=0;i<limite;i++)
        {
            pEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&pId);
            if(pId==auxId && !utn_getLetras(pNombre,50,5,"Ingrese nombre: ","Error.")&&
               !utn_getInt(&pHorasTrabajadas,"Ingrese horas de trabajo: ","Error,ingrese horas de trabajo",1,99999,5)&&
               !utn_getInt(&pSueldo,"Ingrese sueldo: ","Error,ingrese sueldo",1,99999,5)&&
               !employee_setHorasTrabajadas(pEmpleado,pHorasTrabajadas)&&
               !employee_setNombre(pEmpleado,pNombre)&&
               !employee_setSueldo(pEmpleado,pSueldo))
               {
                    retorno=0;
               }
        }
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    Employee* pEmpleado;
    int pId;
    int auxId;
    int lenList=ll_len(pArrayListEmployee);
    if(pArrayListEmployee!=NULL && !utn_getInt(&auxId,"Ingrese id de empleado a borrar: ","Error,ingrese id valido.",0,9999,5))
    {
        for(i=0;i<lenList;i++)
        {
            pEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&pId);
            if(pId==auxId)
            {
                ll_remove(pArrayListEmployee,i);
                retorno=0;

            }
        }
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int retorno=-1;
    int auxHoras;
    int auxId;
    int auxSueldo;
    char auxNombre[50];
    int lenList=ll_len(pArrayListEmployee);
    Employee* pEmployee;
    if(pArrayListEmployee!=NULL)
    {
        retorno=0;
        for(i=0;i<lenList;i++)
        {
            pEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getHorasTrabajadas(pEmployee,&auxHoras);
            employee_getId(pEmployee,&auxId);
            employee_getNombre(pEmployee,auxNombre);
            employee_getSueldo(pEmployee,&auxSueldo);
            printf("Nombre: %s, Sueldo: %d, Horas: %d, ID: %d",auxNombre,auxSueldo,auxHoras,auxId);
        }
        getchar();
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {
        ll_sort(pArrayListEmployee,controller_compareByName,0);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL && !controller_saveEmpAsText(pFile,pArrayListEmployee))
        {
            fclose(pFile);
            printf("Guardado.");
            getchar();
            retorno=0;
        }
        else
        {
            printf("no se puede abrir archivo.");
        }
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE *pFile;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"wb");
        if(pFile!=NULL && !controller_saveEmpAsBinary(pFile,pArrayListEmployee))
        {
            fclose(pFile);
            printf("Guardado.");
            getchar();
            retorno=0;
        }
        else
        {
            printf("no se puede abrir archivo.");
        }
    }

    return retorno;
}

int controller_compareByName(void* this,void* this2)
{
    int retorno;
    char pName1[50];
    char pName2[50];

    employee_getNombre(this,pName1);
    employee_getNombre(this2,pName2);
    if(strcmp(pName1,pName2)<0)
    {
        retorno=-1;
    }
    else if(strcmp(pName1,pName2)>0)
    {
        retorno=1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}
static int controller_saveEmpAsText(FILE* pFile,LinkedList* pArrayEmployee)
{
    int retorno=-1;
    Employee* pEmployee;
    int lenList=ll_len(pArrayEmployee);
    int i=0;
    int auxId;
    int auxHoras;
    int auxSueldo;
    char auxNombre[60];
    if(pFile!=NULL && pArrayEmployee!=NULL)
    {
        fprintf(pFile,"ID,Horas,Sueldo,Nombre\n");
    }
    do
    {
        pEmployee=(Employee*)ll_get(pArrayEmployee,i);
        employee_getId(pEmployee,&auxId);
        employee_getHorasTrabajadas(pEmployee,&auxHoras);
        employee_getSueldo(pEmployee,&auxSueldo);
        employee_getNombre(pEmployee,auxNombre);
        fprintf(pFile,"%d,%d,%d,%s\n",auxId,auxHoras,auxSueldo,auxNombre);
        i++;
    }while(i<lenList);
    if(i==lenList)
    {
        retorno=0;
    }
    return retorno;
}

static int controller_saveEmpAsBinary(FILE* pFile,LinkedList* pArrayEmployee)
{
    int retorno=-1;
    int lenList=ll_len(pArrayEmployee);
    int i;
    Employee* pEmployee;
    if(pFile!=NULL && pArrayEmployee!=NULL)
    {
        retorno=0;
        for(i=0;i<lenList;i++)
        {
            pEmployee=ll_get(pArrayEmployee,i);
            if(pEmployee!=NULL)
            {
                fwrite(pEmployee,sizeof(Employee),1,pFile);
            }
        }
        if(i==lenList)
        {
            retorno=0;
        }
    }
    return retorno;
}
