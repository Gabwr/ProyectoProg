#include <string.h>
#include <stdio.h>
#define rowE 5
#define colE 2
#define rowS 3
#define colS 2
struct Empresa
{
char Nombre_empresa;
long int RUC_empresa;
char Direccion_empresa;
char trabajadores_nombre_estado[rowE][colE];
long int numero_Factura[10];
};

struct Clientes
{
char nombre_cliente;
long int ruc_cliente;
long int cedula_cliente;
char direccion_cliente;
};

struct Servicio
{
char nmservicio_$servicio[rowS][colS];
char servicio_seleccionado[3][3];
};
struct Proyecto
{
Empresa datos_emp;
Clientes datos_clt;
Servicio datos_srv;
};
void ingreso_datos_C(Proyecto *x) 
{
    printf("coloque el nombre del cliente");
}
int main()
{
    Proyecto a1;
    ingreso_datos_C(&a1);
    return 0;
}