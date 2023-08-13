#include <string.h>
#include <stdio.h>
#include<ctype.h>
#include <stdlib.h>
#define rowE 5
#define colE 2
#define rowS 3
#define colS 2
#define ced 10
#define ruc 13
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

void validnom(char *x) 
{
    int contieneNumeros = 1; 
    while (contieneNumeros) {
        contieneNumeros = 0;
        for (int i = 0; i < strlen(x); i++) {
            if (isdigit(x[i])) {
                contieneNumeros = 1;
                break;
            }
        }

        if (contieneNumeros) {
            printf("El nombre contiene numeros. Por favor, ingrese solo caracteres.\n");
            gets(x); 
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

void validarced(long int *y)
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
void vaidarRU(long int *y)
{
long int b=*y;
	int A[ruc],B[9],d,cont=0,sumd=0,ver,res;
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

void ingreso_datos_C(Proyecto *x) 
{
    int a;
    printf("coloque el nombre del cliente\n");
    gets(&x->datos_clt.nombre_cliente);
    validnom(&x->datos_clt.nombre_cliente);
    printf("Que datos ingresara\n 1.RUC \n 2.Cedula\n");
    scanf("%i",&a);
    while(a>2||a<1)
    {printf("Que datos ingresara\n 1.RUC \n 2.Cedula\n");
    scanf("%i",&a);
    }
    switch (a)
    {
    case (1):
        printf("Ingrese el RUC del cliente");
		scanf("%ld",&x->datos_clt.ruc_cliente);
		vaidarRU(&x->datos_clt.ruc_cliente);
        break;
    
    default:
        printf("Ingrese la Cedula del cliente");
        scanf("%ld",&x->datos_clt.cedula_cliente);
        validarced(&x->datos_clt.cedula_cliente);
        break;
    }


}
int main()
{
    Proyecto a1;
    ingreso_datos_C(&a1);
    return 0;
}