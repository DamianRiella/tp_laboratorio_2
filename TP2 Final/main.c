#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ArrayEmployees.h"
#include "ArrayEmployees.c"
#include "utn.h"

#define CANT 1000



int main()
{
    char respuesta;
    char auxName[51];
    char auxLastName[51];

    float auxSalary;

    int opc1, opc2, opc3;
    int auxSector;
    int auxAlta;
    int contaAltas=0;
    int contaId=0;
    int auxId;
    int idBaja;
    int auxBaja;
    int index;
    int auxIndex;
    int listadoEmpleados;

    Employee emple[CANT];

    initEmployee(emple,CANT);

    do{

        system("cls");
        utn_getNumeroAvanzada(&opc1, "------MENU PRINCIPAL------\n 1. Altas \n 2. Modificacion  \n 3. Bajas  \n 4. Informar \n"," \n Seleccione una opcion valida.", 1, 4,3);

        switch(opc1)
        {
            case 1:
                    system("cls");
                    printf("------------------------------------------------------\n");
                    getStringLetras("Ingrese nombre:\n",auxName);
                    printf("------------------------------------------------------\n");
                    getStringLetras("Ingrese apellido:\n",auxLastName);
                    printf("------------------------------------------------------\n");
                    auxSector= getValidInt("Ingrese sector:\n","Error. Ingrese solo numeros.\n",1,5);
                    printf("------------------------------------------------------\n");
                    auxSalary= getValidFloat("Ingrese salario:\n","Error. Ingrese solo numeros.\n",1,99999999);

                    contaId++;
                    auxId=contaId;

                    auxAlta= addEmployee(emple,CANT,auxId,auxName,auxLastName,auxSalary,auxSector);
                    if(auxAlta== 0)
                    {
                        printf("Se ha registrado correctamente.\n");
                        contaAltas++;

                    }
                    else
                    {
                        printf("No quedan lugares libres.\n");
                    }

                    break;

             case 3:
                    if(contaAltas>0)
                    {
                        system("cls");
                        idBaja= getValidInt("Ingrese ID:\n","Error. Ingrese solo numeros.\n",1,1000);
                        auxBaja= removeEmployee(emple,CANT, idBaja);
                        if(auxBaja== 0)
                        {
                            printf("Se aha dado de baja correctamente.\n");
                            contaAltas--;

                        }
                        else
                        {
                            printf("No se pudo encontrar ID.\n");
                        }

                    }
                    else
                    {
                        printf("Error. No hay empleado dado de alta.");
                    }
                    break;

                case 2:
                        if(contaAltas>0)
                        {
                            system("cls");
                            utn_getNumeroAvanzada(&auxIndex, " \n Ingrese el ID del empleado que desea modificar: ", "El ID ingresado debe ser numerico", 0, 1000, 3);

                            index=findEmployeeById(emple, CANT, auxIndex);

                            if (index==-1)
                            {
                                printf("No se encuentra ese ID...\n");
                                break;
                            }

                            do
                            {
                                utn_getNumeroAvanzada(&opc2, "\n 1. Modificar nombre \n 2. Modificar apellido  \n 3. Modificar salario  \n 4. Modificar sector \n 5. Salir. \n \n"," \n Seleccione una opcion valida.", 1, 5,3);


                                switch (opc2)
                                {
                                    case 1:

                                        utn_getCadenaDeCaracteresAvanzada( emple[index].name, "\n Ingrese su nombre: ", "El nombre ingresado no es valido, debe ingresar solo letras....\n", 3 );
                                        printf( "\n -------- Fue modificado con exito. ------\n \n ");
                                        break;

                                    case 2:

                                        utn_getCadenaDeCaracteresAvanzada( emple[index].lastName, "\n Ingrese su apellido: ", "El apellido ingresado no es valido, debe ingresar solo letras....\n ", 3 );
                                        printf( "\n -------- Fue modificado con exito. ------\n \n ");
                                        break;

                                    case 3:

                                        utn_getNumeroConDecimalesAvanzada(& emple[index].salary, "\n Ingrese salario: ", "El salario ingresado no es valido, debe ingresar solo numeros....\n ", 1 , 99999999, 3  );
                                        printf( "\n -------- Fue modificado con exito. ------\n \n ");
                                        break;

                                    case 4:

                                        utn_getNumeroAvanzada(&emple[index].sector, "\n Ingrese sector: ", "El sector ingresado no es valido, debe ser numerico...\n ", 1 , 5, 3 );
                                        printf( "\n ----- Fue modificado con exito. ------\n \n ");
                                        break;
                                }

                            } while (opc2 != 5);

                            break;


                    }
                    else
                    {
                        printf("Error. No hay empleado dado de alta.");
                    }
                    break;

            case 4:
                if (contaAltas > 0)
                {
                    do
                    {
                        utn_getNumeroAvanzada(&opc3, "\n 1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n 2. Total salarios, promedio de salarios y cantidad de empleados que superan el promedio.\n 3. Salir. \n \n Seleccione una opcion: ",
                                        " \n Seleccione una opcion valida.", 1, 3,  3 );

                        switch (opc3)
                        {
                            case 1:

                                utn_getNumeroAvanzada(&listadoEmpleados, " 1.Ordenar de manera decendente.\n 2. Ordenar de manera ascendente. ", " \n Seleccione una opcion valida.", 1, 2, 3 );

                                sortEmployees(emple, CANT, listadoEmpleados);

                                printEmployees(emple, CANT);

                            break;

                            case 2:

                                printSalary(emple, CANT);

                            break;
                        }

                     }while (opc3!=3);

                          break;

                }
               else
                {
                    printf("Error. No hay empleado dado de alta.");
                }
                break;

            default:
                printf("Error. La opcion ingresada no es correcta.");
                break;
        }

         printf("Desea volver al menu? (s\n).");
         scanf("%c",respuesta);

    }while(respuesta == 's');

    return 0;
}



