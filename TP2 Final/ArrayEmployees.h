#ifndef ArrayEmployee_H_INCLUDE
#define ArrayEmployee_H_INCLUDE

typedef struct
{    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;


/***************************************************/
///Funciones del TP2

int initEmployee(Employee* list, int len);///COLOCA EN TRUE TODAS LA POCICIONES DEL ARRAY.
int findEmployeePlace(Employee* list, int len);///BUSCA UN ESPACIO VACIO
int findEmployeeById(Employee* list, int len,int id);///BUSCA UN EMPLEADO A TRAVES DE SU ID.
int addEmployee(Employee* list, int len, int id, char* name,char*
lastName,float salary,int sector);///ALTA DE EMPLEADO.
int removeEmployee(Employee* list, int len, int id);///BAJA DE EMPLEADO.
int sortEmployees(Employee* list, int len, int order);///ORDENA EL ARRAY DE EMPLEADOS POR APELLIDO Y POR SECTOR.
int printEmployees(Employee* list, int len);///IMPRIME EL ARRAY DE EMPLEADOS EN FORMA ENCOLUMNADA.
int printSalary(Employee* list, int len);///IMPRIME EL TOTAL, PROMEDIO Y CANTIDAD DE SALARIOS SUPERIORES AL PROMEDIO.

#endif
