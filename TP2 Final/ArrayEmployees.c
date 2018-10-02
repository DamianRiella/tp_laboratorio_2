#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ArrayEmployees.h"
#include "utn.h"

int initEmployee(Employee* list, int len)
{
     int retorno = -1, i;
    if(list!= NULL && len>0)
    {
        retorno = 0;
        for (i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
    }
    return retorno;
}

/********************************************************************************/
/********************************************************************************/

int findEmployeePlace(Employee* list, int len)
{
    int i;
    int retorno = -1;
    if(list!= NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**********************************************************************************/
/**********************************************************************************/

int findEmployeeById(Employee* list, int len,int idBuscar)
{
    int retorno = -1, i;

    if(list != NULL && len > 0)
    {
        for (i=0; i<len; i++)
        {
            if (list[i].id == idBuscar)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/********************************************************************************/
/********************************************************************************/


int addEmployee(Employee* list, int len, int id, char* name,char*
lastName,float salary,int sector)
{
    int i;
    int retorno = -1;
    if(list!= NULL && len>0)
    {
        i= findEmployeePlace(list,len);
        if(i!= -1)
        {
            list[i].isEmpty = 0;
            list[i].id = id;
            strcpy(list[i].name,name);
            strcpy(list[i].lastName,lastName);
            list[i].salary = salary;
            list[i].sector = sector;
            retorno = 0;
        }
    }
    return retorno;
}
/*******************************************************************************/
/*******************************************************************************/

int removeEmployee(Employee* list, int len, int id)
{
    int retorno= -1;
    int i;
    if(list!= NULL && len>0)
    {
       for(i=0; i<len; i++)
       {
           if(list[i].id == id)
           {
               list[i].isEmpty = 1;
               retorno = 0;
           }
       }
    }
    return retorno;
}
/******************************************************************************/
/******************************************************************************/


int sortEmployees(Employee* list, int len, int orden)
{
    int i, j, retorno=-1;
    Employee auxlist;

    if (list!= NULL && len> 0)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if (orden ==2)
                {
                    if (strcmp(list[i].lastName,list[j].lastName) >0)
                    {
                        auxlist = list[i];
                        list[i] = list[j];
                        list[j] = auxlist;
                        retorno=0;
                    }
                    else
                    {
                        if (strcmp(list[i].lastName,list[j].lastName)==0)
                        {
                            if (list[i].sector > list[j].sector)
                            {
                                auxlist = list[i];
                                list[i] = list[j];
                                list[j] = auxlist;
                                retorno=0;
                            }
                        }
                    }
                }
                else
                {
                    if (strcmp(list[i].lastName,list[j].lastName) < 0)
                    {
                        auxlist = list[i];
                        list[i] = list[j];
                        list[j] = auxlist;
                        retorno=0;
                    }
                    else
                    {
                        if (strcmp(list[i].lastName,list[j].lastName) ==0)
                        {
                            if (list[i].sector < list[j].sector)
                            {
                                auxlist = list[i];
                                list[i] = list[j];
                                list[j] = auxlist;
                                retorno=0;
                            }
                        }
                    }

                }
            }
        }
    }
            return retorno;
}

/***************************************************************************************************/
/***************************************************************************************************/

int printEmployees(Employee* list, int len)
{
    int i;
    int retorno=-1;

    if (list!= NULL && len > 0)
    {
         for (i=0; i< len ; i++)
        {
            if (list[i].isEmpty != 1)
            {
                printf("Apellido:%s\tNombre:%s\tSector:%d\tSalario:%0.2f\tID:%d\t\n",
                    list[i].lastName, list[i].name, list[i].sector , list[i].salary , list[i].id );
            }
        }
        retorno=0;
    }
    return retorno;
}

/***************************************************************************************************/
/***************************************************************************************************/

int printSalary(Employee* list, int len)
{
    int i, contadorSalarios=0, contadorSalariosMax=0;
    float salarioPromedio, acumuladorSalarios=0;
    int retorno=-1;

    if (list!= NULL && len > 0)
    {
        for (i=0; i< len ; i++)
        {
            if (list[i].isEmpty ==0)
            {
                acumuladorSalarios= acumuladorSalarios + list[i].salary;
                contadorSalarios++;
                salarioPromedio= acumuladorSalarios / contadorSalarios;
            }
        }

        for (i=0; i< len ; i++)
        {
            if ((list[i].isEmpty ==0) && (list[i].salary > salarioPromedio))
            {
                    contadorSalariosMax ++;
            }
        }

        printf( "\n El total de los Salarios es: %0.2f \n El promedio de los salarios es: %0.2f \n La cantidad de empleados que superan el salario promedio son: %d \n"
                 ,acumuladorSalarios, salarioPromedio, contadorSalariosMax);

        retorno=0;
    }
    return retorno;
}


