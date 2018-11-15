#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "biblioteca.h"
#define FALSE 0
#define TRUE 1

Employee* Employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

void Employee_delete(Employee* this)
{
    free(this);
}

Employee* employee_newParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
    Employee* this;
    this=Employee_new();

    if(isValidParametros(id,nombre,sueldo,horasTrabajadas)&&
    !employee_setId(this,atoi(id))&&
    !employee_setNombre(this,nombre)&&
    !employee_setHorasTrabajadas(this,atoi(horasTrabajadas))&&
    !employee_setSueldo(this,atoi(sueldo)))
        return this;

    Employee_delete(this);
    return NULL;
}

int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

int isValidParametros(char* id,char* nombre,char* sueldo,char* horasTrabajadas)
{
    int retorno=FALSE;
    if(id!=NULL && nombre!=NULL && sueldo!=NULL && horasTrabajadas!=NULL)
    {
        isInt(id);
        isLetras(nombre);
        isInt(sueldo);
        isInt(horasTrabajadas);
        retorno=TRUE;
    }
    return retorno;
}
