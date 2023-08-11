#include <string.h>
#define rowE 2
#define colE 6
#define rowS 3
#define colS 3
struct Empresa
{
char Nombre_empresa;
long int RUC_empresa;
char Direccion_empresa;
char trabajadores_nombre_estado[rowE][colE];
long int numero_Factura;
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
char codigoservicio_nombreservicio_precioservicio[rowS][colS];
int servicio_seleccionado;
int cantidad_de_servicios;
int datos_servicio;
};
struct Proyecto
{
Empresa datos_emp;
Clientes datos_clt;
Servicio datos_srv;
};

int main()
{
    Empresa a1;

    return 0;
}