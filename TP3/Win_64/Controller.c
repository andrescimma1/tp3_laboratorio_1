#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    system("cls");
    FILE* pArchivo;
    pArchivo = fopen(path, "r");

    if(pArchivo != NULL)
    {
        parser_EmployeeFromText(pArchivo, pArrayListEmployee);
    }
    else
    {
        printf("No se pudo leer el archivo.\n\n");
    }

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
    char c;
    system("cls");
    FILE *pArchivo = NULL;
    pArchivo = fopen(path, "rb");
    if(pArchivo != NULL)
    {
        while(1)
        {
            c=fgetc(pArchivo);
            if(feof(pArchivo))
            {
                break;
            }
            printf("%c", c);
        }
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }

    fclose(pArchivo);

    return 1;
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
    system("cls");

    Employee* emp;

    int indice = -1;
    char auxId[20];
    char auxNombre[20];
    char auxHoras[20];
    char auxSueldo[20];

    Employee* auxEmp;

    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        auxEmp = ll_get(pArrayListEmployee, i);
        if(auxEmp->id == auxId)
        {
            indice = i;
        }
    }



    return 1;
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
    return 1;
}

