#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "biblioteca.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pArchivo;
    pArchivo=fopen(path,"r");
    parser_EmployeeFromText(pArchivo,pArrayListEmployee);
    fclose(pArchivo);

    return 1;
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
    pArchivo=fopen(path,"rb");
    parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
    fclose(pArchivo);
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
    char auxId[50];
    char auxNombre[50];
    char auxSueldo[50];
    char auxHorasTrabajadas[50];
    int retorno=0;


    if(utn_getLetras(auxId,1000,5,"Ingrese ID: ","Error")&&
       utn_getLetras(auxNombre,1000,5,"Ingrese Nombre: ","Error")&&
       utn_getLetras(auxSueldo,1000,5,"Ingrese Sueldo: ","Error")&&
       utn_getLetras(auxHorasTrabajadas,1000,5,"Ingrese Horas Trabajadas: ","Error"))
       {
            pEmployee=employee_newParametros(auxId,
                                             auxNombre,
                                             auxHorasTrabajadas,
                                             auxSueldo);
       }
       if(pEmployee!=NULL)
       {
            ll_add(pArrayListEmployee,pEmployee);
            retorno=1;
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
    int pSueldo;
    int pHorasTrabajadas;
    Employee* pEmpleado;
    int limite;
    int retorno=0;



    return 1;
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
    return 1;
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
    return 1;
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
    return 1;
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
    return 1;
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
    FILE *pArchivo=fopen(path,"wb");
    Employee* pEmpleado;
    int i;
    int lenArray = ll_len(pArrayListEmployee);
    if(pArchivo != NULL)
    {
        for(i=0;i<lenArray;i++)
        {
            pEmpleado=ll_get(pArrayListEmployee,i);
            fwrite(pEmpleado,sizeof(Employee),1,pArchivo);
        }
    }
    fclose(pArchivo);

    return 1;
}

