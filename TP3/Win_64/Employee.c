#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu()
{
    int option;
    printf("*** MENU DE OPCIONES ***\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &option);

    return option;
}

int employee_setId(Employee* this,int id)
{
    int todoOk = 0;

    if(this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}

int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }

    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if(this != NULL && nombre != NULL && strlen(nombre) > 1)
    {
        strcpy(this->nombre,nombre);
        todoOk = 1;
    }

    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }

    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;

    if(this != NULL && sueldo != NULL)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }

    return todoOk;
}


Employee* employee_new()
{
    Employee* this = (Employee*)malloc(sizeof(Employee)); //Crea un espacio en memoria dinámica para una estructura

    if(this != NULL) //Si "this" es distinto de NULL, inicializo los campos.
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }

    return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this; //Creo un puntero a la estructura empleado

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        this = employee_new(); //La funcion retorna un puntero en memoria dinámica que apunta a una estructura.
        if(this != NULL)
        {
            if( !employee_setId(this, atoi(idStr))||
                !employee_setNombre(this, nombreStr)||
                !employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr))||
                !employee_setSueldo(this, atoi(sueldoStr)))  //Si no se pudieron pasar todos los datos..
            {
                free(this); //Libera el puntero en memoria dinámica que apunta a la estructura
                this = NULL; //Le asigna un valor nulo
            }
        }
    }

    return this;
}


void mostrarEmpleado(Employee* emp)
{
    printf("%d   %s   %d   %d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
}

int ordenarXSueldo(void* emp1, void* emp2)
{
    int retorno = 0;

    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL)
    {
        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if(p1->sueldo > p2->sueldo)
        {
            retorno = 1;
        }
        else if(p1->sueldo < p2->sueldo)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}
