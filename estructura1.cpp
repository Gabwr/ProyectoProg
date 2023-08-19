#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define rowE 5
#define colE 2
#define rowS 3
#define colS 2
#define ced 10
#define ruc 13
#define Cl 400
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
unsigned long int ruc_cliente;
unsigned long int cedula_cliente;
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

void validnom(char *x) 
{
    int contieneNumeros = 1; 
    while(strlen(x)==0||strlen(x)<3)
    {
    	printf("Ingrese un nombre valido:");
    	gets (x);
	}
    while (contieneNumeros) {
        contieneNumeros = 0;
        for (int i = 0; i < strlen(x); i++) 
		{
            if (isdigit(x[i])) {
                contieneNumeros = 1;
                break;
            }
        }
        if (contieneNumeros) {
            printf("El nombre contiene numeros. Por favor, ingrese solo caracteres.\n");
            scanf("%s",x); 
        }
    }
}

void cedulavolveringresar(long int *a)
{
	printf("coloque una cedula valida\n");
		scanf("%ld",a);
}

void crear (int B[ced], long int *c)
{	
	long int  f=*c, cosc;
	int  rsd;
for(int i=9;i>=0;i--)
	{
	cosc=*c/10;
	rsd=*c%10;
	B[i]=rsd;
	*c=cosc;
	}
	*c=f;
}

void validarced(unsigned long int *y)
{
	long int b=*y;
	int A[ced],cont=0,s,res,mul=0,sumpr=0,sumimp=0,sumt=0;
	do{
	cont=0;
	crear(A,&b);
	if(b<0)
		{
	while(b<0)
	{
		if(b<0)
		{
			cedulavolveringresar(&b);
			cont++;
		}
	}
	}
	if(A[0]==0&&A[1]==0)
	{
	while(A[0]==0&&A[1]==0)
	{
		if(A[0]==0&&A[1]==0)
			{
			cedulavolveringresar(&b);
			cont++;
			crear(A,&b);
			}
	}
	}
	if(A[0]==2&&A[1]==4)
	{
	while(A[0]==2&&A[1]>4)
	{
		if(A[0]==2&&A[1]==4)
			{
			cedulavolveringresar(&b);
			cont++;
			crear(A,&b);
			}
	}
	}
	if(A[0]==3&&A[1]>4)
	{
	while(A[0]==3&&A[1]>4)
	{
		if(A[0]==3&&A[1]>4)
			{
			cedulavolveringresar(&b);
			cont++;
			crear(A,&b);
			}
	}
	}
	mul=0;
	sumimp=0;
	sumpr=0;
	res=0;
	for(int i=0;i<9;i+=2)
	{
	mul=A[i]*2;
		if (mul>9)
		mul-=9;
	sumpr+=mul;
	}
	for (int i=1;i<9;i+=2)
	sumimp+=A[i];
	sumt=sumpr+sumimp;
	res=sumt%10;
	s=10-res;
	if(s==10)
		s=0;
	if(s==A[9])
		mul=0;
	else
	{
	cedulavolveringresar(&b);
	crear(A,&b);
	cont++;
	}
	}while(cont!=0);
	
	*y=b;

}
void Ruccolveringreso(long int *c)
{
	printf("coloque un RUC valida\n");
		scanf("%ld",c);
}
void CrearR(int C[ruc], int *d)
{
	long int  f=*d, cosc;
	int  rsd;
	for(int i=13;i>=0;i--)
	{
	cosc=*d/10;
	rsd=*d%10;
	C[i]=rsd;
	*d=cosc;
	}
	*d=f;	
}
void CrearC(int C[9], int *d)
{
	long int  f=*d, cosc;
	int  rsd;
	for(int i=9;i>=0;i--)
	{
	cosc=*d/10;
	rsd=*d%10;
	C[i]=rsd;
	*d=cosc;
	}
	*d=f;	
}
void vaidarRU(unsigned long int *y)
{
long int b=*y;
	int A[ruc],B[9],d,cont=0,ver,sumd=0,res;
	d=432765432;
	CrearC(B,&d);
	do{
	cont=0;
	crear(A,&b);
	if(b<0)
		{
	while(b<0)
	{
		if(b<0)
		{
			Ruccolveringreso(&b);
			cont++;
		}
	}
	}
	if(A[0]==0&&A[1]==0)
	{
	while(A[0]==0&&A[1]==0)
	{
		if(A[0]==0&&A[1]==0)
			{
			Ruccolveringreso(&b);
			cont++;
			crear(A,&b);
			}
	}
	}
	if(A[0]==2&&A[1]==4)
	{
	while(A[0]==2&&A[1]>4)
	{
		if(A[0]==2&&A[1]==4)
			{
			Ruccolveringreso(&b);
			cont++;
			crear(A,&b);
			}
	}
	}
	if(A[2]!=9)
	{
	while(A[2]!=9)
	{
		if(A[2]!=9)
			{
			Ruccolveringreso(&b);
			cont++;
			crear(A,&b);
			}
	}
	}
	if(A[10]!=0&&A[11]!=0&&A[12]!=1)
	while(A[10]!=0&&A[11]!=0&&A[12]!=1)
	{
		if(A[10]!=0&&A[11]!=0&&A[12]!=1)
			{
			Ruccolveringreso(&b);
			cont++;
			crear(A,&b);
			}
	}
	sumd=0;
	ver=A[9];
	for(int i=0;i<10;i++)
	{
		sumd+=(A[0]*B[0]);
	}
	res=sumd%11;
	if (A[10]!=res)
	{
		Ruccolveringreso(&b);
		cont++;
		crear(A,&b);
	}
	}while(cont!=0);
	
	*y=b;

}

void ingreso_datos_C(Proyecto x[Cl], int k) 
{
    int a;
	fflush(stdin);
    printf("coloque el nombre del cliente\n");
    gets(&x[k].datos_clt.nombre_cliente);
    validnom(&x[k].datos_clt.nombre_cliente);
    printf("Que datos ingresara\n 1.RUC \n 2.Cedula\n");
    scanf("%i",&a);
    while(a>2||a<1)
    {printf("Que datos ingresara\n 1.RUC \n 2.Cedula\n");
    scanf("%i",&a);
    }
    switch (a)
    {
    case (1):
        printf("Ingrese el RUC del cliente\n");
		scanf("%ld",&x[k].datos_clt.ruc_cliente);
		vaidarRU(&x[k].datos_clt.ruc_cliente);
        break;
    
    default:
        printf("Ingrese la Cedula del cliente\n");
        scanf("%lu",&x[k].datos_clt.cedula_cliente);
        validarced(&x[k].datos_clt.cedula_cliente);
        break;
    }
	fflush(stdin);
	printf("coloque la dirreccion del cliente\n");
	gets(&x[k].datos_clt.direccion_cliente);
}
void MenuPrincipal()
{
	printf("================================================\n");
	printf("Bienvenido al menu de Facturación de NaturVerde\n");
	printf("================================================\n");
	printf("Que desea realizar?\n");
	printf("1.Ingresar una nueva factura\n");
	printf("2.Buscar una factura\n");
	printf("3.Modificar una factura\n");
	printf("4.Eliminar una factura\n");
	printf("5.Buscar una factura\n");
	printf("6.Imprimir una factura\n");
	printf("7.Imprimir todas las facturas\n");
	printf("8.Salir del Menu\n");
	printf("Elija una opcion:\n");
}
void MenuPrincipal2()
{
	printf("Elija una opcion Existente\n");
	printf("Que desea realizar?\n");
	printf("1.Ingresar una nueva factura\n");
	printf("2.Buscar una factura\n");
	printf("3.Modificar una factura\n");
	printf("4.Eliminar una factura\n");
	printf("5.Buscar una factura\n");
	printf("6.Imprimir una factura\n");
	printf("7.Imprimir todas las facturas\n");
	printf("8.Salir del Menu\n");
	printf("Elija una opcion:\n");
}
void menudecedulas_ruc(Proyecto z[Cl],int j, int *k)
{
	long long int p=1000000000000;
		printf("Indique que cedula o RUC del  cliente que va a cambiar\n");
			for(int t=0;t<j+1;t++)
			{
			if(z[t].datos_clt.cedula_cliente!=0)
			{
			if(z[t].datos_clt.cedula_cliente<1000000000)
			printf("%i. 0%lu\t%s\n",t+1,z[t].datos_clt.cedula_cliente,z[t].datos_clt.nombre_cliente);
			else
			printf("%i. %lu\t%s\n",t+1,z[t].datos_clt.cedula_cliente,z[t].datos_clt.nombre_cliente);
			}
			else
			{
			if(z[t].datos_clt.ruc_cliente<p)
			printf("%i. 0%lu\t%s\n",t+1,z[t].datos_clt.ruc_cliente,z[t].datos_clt.nombre_cliente);
			else
			printf("%i. %lu\t%s\n",t+1,z[t].datos_clt.ruc_cliente,z[t].datos_clt.nombre_cliente);
			}
}
scanf("%i",k);
}
void menudecedulas_ruc2(Proyecto z[Cl],int j, int *k)
{
	long long int p=1000000000000;
		printf("Indique que cedula o RUC del  cliente que va a cambiar valido\n");
			for(int t=0;t<j+1;t++)
			{
			if(z[t].datos_clt.cedula_cliente!=0)
			{
			if(z[t].datos_clt.cedula_cliente<1000000000)
			printf("%i. 0%lu\t%s\n",t+1,z[t].datos_clt.cedula_cliente,z[t].datos_clt.nombre_cliente);
			else
			printf("%i. %lu\t%s\n",t+1,z[t].datos_clt.cedula_cliente,z[t].datos_clt.nombre_cliente);
			}
			else
			{
			if(z[t].datos_clt.ruc_cliente<p)
			printf("%i. 0%lu\t%s\n",t+1,z[t].datos_clt.ruc_cliente,z[t].datos_clt.nombre_cliente);
			else
			printf("%i. %lu\t%s\n",t+1,z[t].datos_clt.ruc_cliente,z[t].datos_clt.nombre_cliente);
			}
}
scanf("%i",k);
}

void cambiarM(Proyecto y[Cl],int j)
{
	int h=0,i=0,k=0,p=0,l=0;
	do{
	printf("Que desea modificar? \n1.Datos Cliente \n2.Datos Servicio \n3.volver al menu anterior\n");
	scanf("%i",&h);
	if(h!=4)
	{
	menudecedulas_ruc(y,j,&k);
	while(k>j+1||k<1)
	{menudecedulas_ruc2(y,j,&k);
	}
	}
	k--;
switch(h)
	{
		case 1:
		{
			do{
			printf("Que desea cambiar del Cliente \n1.Nombre del Cliente \n2.Dirrección del Cliente \n3.Cedula del cliente \n4.volver al menu anterior\n");
			scanf("%i",&i);
			while(i<1||i>4)
			switch(i)
			{
			case 1:
			1+1;
			break;
			default:
			1+2;
			}
			}while(i!=4);
		}
		break;
		case 2:
		{
			do
			{
			printf("Que desea cambiar de los servicios del cliente\n");

			scanf("%i",&i);
			while(i<1||i>2)
			{
			printf("Escoja una opción valida\n1.Notas del estudiante \n2.volver al menu anterior\n");
			scanf("%i",&i);
			}
			switch(i)
			{
				case 1:
				{
				printf("\ningrese la nota parcial de la materia ");
				}
				break;
				default:
				printf("volviendo al menu anterior\n");
			}
			}while(i!=2);
			}
		break;
		default:
			printf("volviendo al menu anterior\n");
	}
	}while(h!=3);
}
void menuOp(Proyecto x[Cl])
{
	int f,cont=0,i=0;
	do
	{
		MenuPrincipal();
		scanf("%i",&f);
		while(f<1||f>8)
		{
		MenuPrincipal2();
		scanf("%i",&f);
		}
		switch (f)
		{
		case 1:
			{
				ingreso_datos_C(x,i);
				i++;
			}
			break;
		case 2:
			1+1;
			break;
		case 3:
			cambiarM(x,i);
			break;
		case 4:
			1+1;
			break;
		case 5:
			1+1;
			break;
		case 6:
			1+1;
			break;
		case 7:
			1+1;
			break;
		default:
		{
			printf("Gracias por utilizar el programa");
			cont++;
		}
		}
	} while (cont<1);
	
}
int main()
{
    Proyecto a1[Cl];
	menuOp(a1);
    return 0;
}