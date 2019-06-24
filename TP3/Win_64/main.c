#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
   /* do{
        switch(menu())
        {
            case 1:
                controller_loadFromText("data.csv", listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("data.csv", listaEmpleados);
                break;
            default:
                printf("Opcion ingresada invalida.\n");
                break;
        }
    }while(option != 10);*/

    //Hardcodeo 3 empleados
/*    Employee* emp1 = employee_newParametros("1234", "Juan", "234", "25000");
    Employee* emp2 = employee_newParametros("2222", "Julia", "100", "15000");
    Employee* emp3 = employee_newParametros("1111", "Juana", "330", "35000");
    Employee* emp4 = employee_newParametros("5555", "Sofia", "210", "23000");

    //Muestro la cantidad de elementos dentro de la lista vacia.
    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));

    if(ll_add(listaEmpleados, emp1)==0)
    {
        printf("Se ha agregado el empleado con exito a la lista\n");
    }

    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));

    if(ll_add(listaEmpleados, emp2)==0)
    {
        printf("Se ha agregado el empleado con exito a la lista\n");
    }

    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));

    if(ll_add(listaEmpleados, emp3)==0)
    {
        printf("Se ha agregado el empleado con exito a la lista\n");
    }

    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));

    mostrarEmpleado((Employee*) ll_get(listaEmpleados, 1));

    if(ll_push(listaEmpleados, 1, emp4)==0)
    {
        printf("Se ha agregado el empleado con exito a la lista\n");
    }

    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));

    mostrarEmpleado((Employee*) ll_get(listaEmpleados, 1));

    mostrarEmpleado((Employee*) ll_get(listaEmpleados, 2));

    printf("----------------------------------------\n\n");

    int i;
    for(i=0; i<ll_len(listaEmpleados); i++)
    {
        mostrarEmpleado((Employee*) ll_get(listaEmpleados, i));
    }

    printf("Ordeno la lista por sueldo\n\n");

    ll_sort(listaEmpleados, ordenarXSueldo, 1);

    for(i=0; i<ll_len(listaEmpleados); i++)
    {
        mostrarEmpleado((Employee*) ll_get(listaEmpleados, i));
    }
*/
    Employee* emp;
    FILE *pFile;
    int todoOk;
    int r;
    int i = 0;
    char cad1[20], cad2[20], cad3[20], cad4[20];

    pFile = fopen("data.csv", "r");

    if(pFile == NULL)
    {
        return -1;
    }

    do
    {
        r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", cad1, cad2, cad3, cad4);
        if(strcmp(cad1, "id") && r==4)
        {
            Employee* pAux = employee_new();
            employee_setId(pAux, atoi(cad1));
            employee_setNombre(pAux, cad2);
            employee_setHorasTrabajadas(pAux, atoi(cad3));
            employee_setSueldo(pAux, atoi(cad4));
            emp = pAux;
            todoOk = ll_add(listaEmpleados, emp);
            printf("%d", todoOk);

            printf("%d %s %d %d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);

            i++;
        }
    }while(!feof(pFile) && i < 100);

    return 0;
}
