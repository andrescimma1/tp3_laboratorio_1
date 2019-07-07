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
    int cantidad;
    int todoOk = 0;
    char buffer[4][30];

    while(!feof(pFile))
    {
        cantidad = fscanf("%[^,],%[^,],%[^,],%[^\n]", buffer[0], buffer[1], buffer[2], buffer[3]);
        Employee* aux = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

        if(aux != NULL)
        {
            ll_add(pArrayListEmployee, aux);
            todoOk++;
        }
        if(cantidad < 4)
        {
            if(feof(pFile))
            {
                break;
            }
        }
    }

    if(todoOk != 0)
    {
        printf("Los archivos se han cargado\n\n");
        system("pause");
    }
    else
    {
        printf("Error al leer el archivo\n\n");
    }

    return 1;
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
    int cantidad;

    while(!feof(pFile))
    {
        Employee* nuevo_empleado = employee_new();

        cantidad = fread(nuevo_empleado, sizeof(Employee), 1, pFile);

        if(nuevo_empleado != NULL)
        {
            ll_add(pArrayListEmployee, nuevo_empleado);
            printf("Empleado agregado a la lista\n\n");
        }
        else
        {
            printf("No se pudo leer el archivo.\n\n");
        }

        if(cantidad <= 0)
        {
            if(feof(pFile))
            {
                break;
            }
            else
            {
                free(nuevo_empleado);
            }
        }
    }

    return 1;
}
