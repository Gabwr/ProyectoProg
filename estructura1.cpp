#include <string.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#define rowE 5
#define colE 2
#define rowS 3
#define colS 2
#define ced 10
#define ruc 13
#define Cl 400
#define ser_fil 100
#define MAX_ARBUSTOS 100
#define MAX_CESPED 100
#define MAX_PAVIMENTO 100
struct Empresa
{
const char *Nombre_empresa = "NaturVerde";
    const char *RUC_empresa = "2300548657002";
    const char *Direccion_empresa = "Av. 6 de Diciembre y Gaspar de Vilaroel";
    char trabajadores_nombre_estado[6][50];
    int B[6]; 
    int indiceActual = 0; 
    int numero_Factura = 9;
};

struct Clientes
{
char nombre_cliente[50];
long long int ruc_cliente;
long long int cedula_cliente;
char direccion_cliente[100];
};

struct Servicio
{
    char nmservicio_servicio[rowS][colS][200];
    char servicio_seleccionado[rowS][colS][200];
};
struct Proyecto
{
Empresa datos_emp;
Clientes datos_clt;
Servicio datos_srv;
};
void validDir(char x[100])
{
	 size_t found1 = std::string(x).find("AV.");
	size_t found2 = std::string(x).find("Calle.");
	int cont=0, letterCount = 0;
	do{
		cont=0;
    if (found1 != std::string::npos && strlen(x)  > (found1 + 3)||found2 != std::string::npos && strlen(x) > (found2 + 6)) 
	{
		for (size_t i = found1 + 7; i < strlen(x); ++i) {	
            if (std::isalpha(x[i])|| std::isdigit(x[i]) || x[i] == ' ' || x[i] == '.') 
                letterCount++;
            }
        }
        if (letterCount < 7) {
            fflush(stdin);
			printf("La direccion no contiene al menos 7 letras despues de AV. o Calle\n");
			gets(x);
			cont++;
        }
	}while(cont!=0);
}
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

void cedulavolveringresar(long long int *a)
{
	printf("coloque una cedula valida\n");
		scanf("%lld",a);
}

void crear (int B[ced], long long int *c)
{	
	long long int  f=*c, cosc;
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

void validarced(long long int *y)
{
	long long int b=*y, llp=3999999999;
	int A[ced],cont=0,s,res,mul=0,sumpr=0,sumimp=0,sumt=0;
	do{
	cont=0;
	crear(A,&b);
	while(b<0)
	{
		if(b<0||b>llp)
		{
			cedulavolveringresar(&b);
			cont++;
		}
	}
while(A[0]==0&&A[1]==0)
	{
		if(A[0]==0&&A[1]==0)
			{
			cedulavolveringresar(&b);
			cont++;
			crear(A,&b);
			}
	}
	while(A[0]==2&&A[1]>4)
	{
		if(A[0]==2&&A[1]==4)
			{
			cedulavolveringresar(&b);
			cont++;
			crear(A,&b);
			}
	}
	while(A[0]==3&&A[1]>4)
	{
		if(A[0]==3&&A[1]>4)
			{
			cedulavolveringresar(&b);
			cont++;
			crear(A,&b);
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
void Ruccolveringreso(long long int *c)
{
	printf("coloque un RUC valido\n");
		scanf("%lld",c);
}
void CrearR(int C[ruc], long long int *d)
{
	long long int  f=*d, cosc;
	int  rsd;
	for(int i=12;i>=0;i--)
	{
	cosc=*d/10;
	rsd=*d%10;
	C[i]=rsd;
	*d=cosc;
	}
	*d=f;	
}
void CrearC(int C[9], long long int *d)
{
	long long int  f=*d, cosc;
	int  rsd;
	for(int i=8;i>=0;i--)
	{
	cosc=*d/10;
	rsd=*d%10;
	C[i]=rsd;
	*d=cosc;
	}
	*d=f;	
}
void CrearD(int C[8], long long int *d)
{
	long long int  f=*d, cosc;
	int  rsd;
	for(int i=7;i>=0;i--)
	{
	cosc=*d/10;
	rsd=*d%10;
	C[i]=rsd;
	*d=cosc;
	}
	*d=f;	
}
void vaidarRU(long long int *y)
{
long long int b=*y,c,d;
int A[ruc],B[9],C[8],cont=0,sumd=0,res,cont1=0;
	d=432765432;
	c=32765432;
CrearC(B,&d);
CrearD(C,&c);
do{
CrearR(A,&b);
if(A[2]==8||A[2]==7||A[2]<6)
{
	while(A[2]==8||A[2]==7||A[2]<6)
	{
		Ruccolveringreso(&b);
		CrearR(A,&b);
		cont++;
	}
}
//ruc para Juridico/extranjero
if(A[2]==9)
{
	cont=0;
	cont1=0;
	CrearR(A,&b);
	while(b<0)
	{
		if(b<0||b>3000000000000)
		{
			Ruccolveringreso(&b);
			cont++;
		}
	}
	while(A[0]==0&&A[1]==0)
	{
		if(A[0]==0&&A[1]==0)
			{
			Ruccolveringreso(&b);
			cont++;
			CrearR(A,&b);
			}
	}
	while(A[0]==2&&A[1]>4)
	{
		if(A[0]==2&&A[1]==4)
			{
			Ruccolveringreso(&b);
			cont++;
			CrearR(A,&b);
			}
	}
	while(A[2]!=9)
	{
		if(A[2]!=9)
			{
			Ruccolveringreso(&b);
			cont++;
			CrearR(A,&b);
			}
	}
	while(A[10]!=0&&A[11]!=0&&A[12]!=1)
	{
		if(A[10]!=0&&A[11]!=0&&A[12]!=1)
			{
			Ruccolveringreso(&b);
			cont++;
			CrearR(A,&b);
			}
	}
	sumd=0;
	for(int i=0;i<10;i++)
	{
		sumd+=(A[i]*B[i]);
	}
	res=sumd%11;
	if (A[9]!=(11-res))
	{
		Ruccolveringreso(&b);
		cont++;
		CrearR(A,&b);
	}
	*y=b;
	}
//ruc publicos	
if(A[2]==6)
{
cont=0;
cont1++;
while(b<0)
{
	if(b<0||b>3000000000000)
	{
		Ruccolveringreso(&b);
		cont++;}
}
while(A[0]==0&&A[1]==0)
{
	if(A[0]==0&&A[1]==0)
		{
		Ruccolveringreso(&b);
		cont++;
		CrearR(A,&b);
		}
}
while(A[0]==2&&A[1]>4)
{
	if(A[0]==2&&A[1]==4)
		{
		Ruccolveringreso(&b);
		cont++;
		CrearR(A,&b);
		}
}
sumd=0;
	for(int i=0;i<8;i++)
	{
		sumd+=(A[i]*C[i]);
	}
	res=sumd%11;
	if (A[8]!=(11-res))
	{
		Ruccolveringreso(&b);
		cont++;
		CrearR(A,&b);
	}
}
}while(cont!=0);
}


void ingreso_datos_C(Proyecto x[Cl], int k) 
{
    int a;
	fflush(stdin);
    printf("coloque el nombre del cliente\n");
    gets(x[k].datos_clt.nombre_cliente);
    validnom(x[k].datos_clt.nombre_cliente);
    printf("Que datos ingresara\n 1.RUC \n 2.Cedula\n");
    scanf("%i",&a);
    while(a>2||a<1)
    {printf("Que datos ingresara\n 1.RUC \n 2.Cedula\n");
    scanf("%i",&a);
    }
    switch (a)
    {
    case (1):
	{
		printf("Ingrese el RUC del cliente\n");
		scanf("%lld",&x[k].datos_clt.ruc_cliente);
		vaidarRU(&x[k].datos_clt.ruc_cliente);
	}    
		break;
    
    default:
        printf("Ingrese la Cedula del cliente\n");
        scanf("%lld",&x[k].datos_clt.cedula_cliente);
        validarced(&x[k].datos_clt.cedula_cliente);
        break;
    }
	fflush(stdin);
	printf("coloque la dirreccion del cliente\n");
	gets(x[k].datos_clt.direccion_cliente);
	validDir(x[k].datos_clt.direccion_cliente);
}
void MenuPrincipal()
{
	printf("================================================\n");
	printf("Bienvenido al menu de Facturacion de NaturVerde\n");
	printf("================================================\n");
	printf("Que desea realizar?\n");
	printf("1.Ingresar una nueva factura\n");
	printf("2.Buscar una factura\n");
	printf("3.Modificar una factura\n");
	printf("4.Eliminar una factura\n");
	printf("5.Imprimir una factura\n");
	printf("6.Imprimir todas las facturas\n");
	printf("7.Salir del Menu\n");
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
	printf("5.Imprimir una factura\n");
	printf("6.Imprimir todas las facturas\n");
	printf("7.Salir del Menu\n");
	printf("Elija una opcion:\n");
}
void menudecedulas_ruc(Proyecto z[Cl],int j, int *k)
{
	long long int p=1000000000000;
		printf("Indique que cedula o RUC del  cliente que va a cambiar\n");
			for(int t=0;t<j;t++)
			{
			if(z[t].datos_clt.cedula_cliente!=0)
			{
			if(z[t].datos_clt.cedula_cliente<1000000000)
			printf("%i. 0%lld\n",t+1,z[t].datos_clt.cedula_cliente,z[t]);
			else
			printf("%i. %lld\n",t+1,z[t].datos_clt.cedula_cliente,z[t]);
			}
			else
			{
			if(z[t].datos_clt.ruc_cliente<p)
			printf("%i. 0%lld\n",t+1,z[t].datos_clt.ruc_cliente);
			else
			printf("%i. %lld\n",t+1,z[t].datos_clt.ruc_cliente);
			}
}
scanf("%i",k);
}
void menudecedulas_ruc2(Proyecto z[Cl],int j, int *k)
{
	long long int p=1000000000000;
		printf("Indique que cedula o RUC del  cliente que va a cambiar valido\n");
			for(int t=0;t<j;t++)
			{
			if(z[t].datos_clt.cedula_cliente!=0)
			{
			if(z[t].datos_clt.cedula_cliente<1000000000)
			printf("%i. 0%lld\n",t+1,z[t].datos_clt.cedula_cliente);
			else
			printf("%i. %lld\n",t+1,z[t].datos_clt.cedula_cliente);
			}
			else
			{
			if(z[t].datos_clt.ruc_cliente<p)
			printf("%i. 0%lld\n",t+1,z[t].datos_clt.ruc_cliente);
			else
			printf("%i. %lld\n",t+1,z[t].datos_clt.ruc_cliente);
			}
}
scanf("%i",k);
}

void Trabajadores(Empresa &Empresa) {
    int B[6];
    char A[6][100]={"Stiven Celi","Gabriel Lopez","Alexander Toapanta","Maycol Gomez","Josue Castillo","Martin Correa"};

// para guardar los nombres en la estructura de trabajadores nombres estado
        for (int i = 0; i < 6; i++) {//5
            strcpy(Empresa.trabajadores_nombre_estado[i],A[i] );
            strcat(Empresa.trabajadores_nombre_estado[i], " (D)");
            Empresa.B[i]=0;// Inicializar B con 0 (Disponible)
        }
}
bool todosOcupados(Empresa &Empresa, int i) {
    for (i ; i < 6; i++) {
        if (Empresa.B[i] == 0) {
            return false; // Al menos uno no está ocupado
        }
    }
    return true; // Todos están ocupados
}

void cambiarestado(Empresa &Empresa){
    if (Empresa.indiceActual >= 0 && Empresa.indiceActual < 6) {
        if (strstr(Empresa.trabajadores_nombre_estado[Empresa.indiceActual], "D")) {
            Empresa.B[Empresa.indiceActual] = 1; // Cambiar el valor en B a 1 (Ocupado)
            strcpy(Empresa.trabajadores_nombre_estado[Empresa.indiceActual] + strlen(Empresa.trabajadores_nombre_estado[Empresa.indiceActual]) - 4, " (O)");
        }
    }
}


void cambiar_sin_estado(Empresa &Empresa, int k) {
    printf("Trabajador Asignado:\n");
    for (k ; k < 6; k++) {
        char nombreCompleto[50];
        strcpy(nombreCompleto, Empresa.trabajadores_nombre_estado[k]);

        char *estadoPos = strstr(nombreCompleto, " (O)");
        if (estadoPos == nullptr) {
            estadoPos = strstr(nombreCompleto, " (D)");
        }

        if (estadoPos != nullptr) {
            *estadoPos = '\0'; // Reemplazar el paréntesis y el estado por un carácter nulo
        }

        printf("- %s\n", nombreCompleto);
        k++;
        break;
    }
}

void mostrarDatosEmpresa(Proyecto x[Cl], int j,int k)
{
    Trabajadores(x->datos_emp);
    int contador=10+j;
	const char *numeroSerie= "001-001-";
	std::string NumS= numeroSerie;
	std::string NumP= std::to_string(contador);
	std::string NumeroF = NumS + NumP;

    if (todosOcupados(x->datos_emp,k))
    printf("Ya no hay trabajadores disponibles.\n");
    else {
            printf("----DATOS EMPRESA----\n");
            printf("Nombre Empresa: %s\n",x[j].datos_emp.Nombre_empresa);
            printf("RUC Empresa: %s\n",x[j].datos_emp.RUC_empresa);
            printf("Direccion Empresa (Matriz): %s\n",x[j].datos_emp.Direccion_empresa);
            std::puts(NumeroF.c_str());
            cambiarestado(x->datos_emp); // Cambiar estado para la siguiente impresión
    for (k; k < 6; k++)
	{
        cambiar_sin_estado(x->datos_emp, k);
        break;
   	}
    // Actualizar el índice para la siguiente impresión
  x->datos_emp.indiceActual = (x->datos_emp.indiceActual + 1) % 6;
		}
}

void cambiarM(Proyecto y[Cl],int j)
{
	int h=0,i=0,k=0;
	do{
	printf("Que desea modificar? \n1.Datos Cliente \n2.Datos Servicio \n3.volver al menu anterior\n");
	scanf("%i",&h);
	while(h<1||h>3)
    {
     printf("Eliga una opcion valida \n1.Datos Cliente \n2.Datos Servicio \n3.volver al menu anterior\n");
	scanf("%i",&h);
    }
    if(h!=3)
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
			printf("Que desea cambiar del Cliente \n1.Nombre del Cliente \n2.Cedula/ruc del cliente \n3.Dirrección del Cliente  \n4.volver al menu anterior\n");
			scanf("%i",&i);
			while(i<1||i>4)
			{
			printf("Escoja una opción existente \n1.Nombre del Cliente \n2.Cedula/ruc del cliente \n3.Dirrección del Cliente  \n4.volver al menu anterior\n");
			scanf("%i",&i);
			}
			switch(i)
			{
			case 1:
			{
			printf("Escriba el nuevo nombre\n");
			fflush(stdin);
			gets(y[k].datos_clt.nombre_cliente);
			validnom(y[k].datos_clt.nombre_cliente);
			}
			break;
			case 2:
			{
			do{
			printf("Que desea cambiar 1.Cedula \n 2.Ruc \n 3. volver almenu anterior\n");
			scanf("%i",&j);
			switch (j)
			{
			case 1:
			{
				if(y[k].datos_clt.cedula_cliente==0)
				printf("No hay cedula para cambiar\n");
				else
				{
				printf("coloque la nueva cedula\n");
				scanf("%lld",&y[k].datos_clt.cedula_cliente);
				validarced(&y[k].datos_clt.cedula_cliente);
				}
			}
				break;
			case 2:
			{
				if(y[k].datos_clt.ruc_cliente==0)
				printf("No hay Ruc que cambiar\n");
				else
				{			
				printf("coloque el nuevo RUC\n");
				scanf("%lld",&y[k].datos_clt.ruc_cliente);
				vaidarRU(&y[k].datos_clt.ruc_cliente);
				}
			}
			break;
			default:
				printf("Volviendo al menu anterior\n");
				system("pause"); 
			}
			}while(j!=3);
			}
			break;
			case 3:
			{
				fflush(stdin);
				printf("Escriba la nueva Dirrección\n");
				gets(y[k].datos_clt.direccion_cliente);	
				validDir(y[k].datos_clt.direccion_cliente);
			}
			break;
			default:
			{
			printf("Volviendo al menu principal\n");
			system("pause"); 
			}
			}
			}while(i!=4);
		}
		break;
		case 2:
		{
			do{
			printf("Que desea cambiar de los servicios del cliente\n1.Cambiar un servicio\n2.Volver al menu principal\n");
			scanf("%i",&i);
			while(i<1||i>2)
			{
			printf("Escoja una opción valida\n1.Cambiar un servicio\n2.Volver al menu principal\n");
			scanf("%i",&i);
			}
			switch(i)
			{
				case 1:
				{
				printf("\nQue servicio desea cambiar?");
				for(int t=0;t<3;t++)
				puts(y[k].datos_srv.nmservicio_servicio[0][t]);
				}
				break;
				default:
				printf("volviendo al menu anterior\n");
				system("pause"); 
			}
			}while(i!=2);
			}
		break;
		default:
			printf("volviendo al menu anterior\n");
			system("pause"); 
	}
	}while(h!=3);
}

void servicios(struct Proyecto x[Cl], int y, int *z, int *q, int *r)
{
    char o[100],k[100],h[100],u[100],f[100],w[100],v[3][2][100], m[100],n[100]; 
    const char *s="s",*t="n";
     int A;
    do
    {
        printf("Elija uno de los siguientes servicios:\n");
        strcpy(v[0][0], "Cortar cesped");
        strcpy(v[1][0], "Podar arbusto");
        strcpy(v[2][0], "Limpieza de pavimento");
        strcpy(v[0][1], "4$ el mt2");
        strcpy(v[1][1], "0.5-5 metros(4$)\t6-10 metros(10$)\t10-15 metros(20$)\tmas de 15 metros (50$)");
        strcpy(v[2][1], "5$ el mt2");
        
        for (int i = 0; i < rowS; i++)
        {
            for (int j = 0; j < colS; j++)
            {
                printf("%s\t", v[i][j]);
            }
            printf("\n");
        }
        
        printf("Escriba el servicio que desee:\t");
        gets(o);
        
        while (strcasecmp(v[0][0], o) != 0 &&
               strcasecmp(v[1][0], o) != 0 &&
               strcasecmp(v[2][0], o) != 0)
        {
            printf("Ingrese un servicio valido: ");
            fgets(o, sizeof(o), stdin);
    		o[strcspn(o, "\n")] = '\0';
        }
         if (strcasecmp(v[0][0], o) == 0)
				{
				    (*z)++;
				    printf("Cuantos metros de cesped desea cortar:\t");
				    gets(h);
				    while (atof(h) == 0 || atof(h) < 0||atof(h)>150)
				    {
				        printf("Ingrese un valor numerico positivo distinto de 0 y que sea menor a 150:\t");
				        gets(h);
				    }
				    sprintf(w, "%.2f", atof(h));
				    strcpy(x[y].datos_srv.nmservicio_servicio[0][*z - 1], w);
				}
    if (strcasecmp(v[1][0], o) == 0)
{
    (*r)++;

    printf("Ingrese la medida en metros del arbusto:\t");
				    gets(f);
				    while (atof(f) == 0 || atof(f) < 0||atof(f)>150)
				    {
				        printf("Ingrese un valor numerico positivo distinto de 0 y que sea menor a 150:\t");
				        gets(f);
				    }
				    sprintf(w, "%.2f", atof(f));
				    strcpy(x[y].datos_srv.nmservicio_servicio[1][*r - 1], w);
}
            if (strcasecmp(v[2][0], o) == 0)
            {
                (*q)++;
                printf("Cuantos metro de pavimento desea limpiar:\t");
                gets (u);
              while (atof(u)==0||atof(u)<0||atof(u)>150)
                {
                	printf("Ingrese un valor numerico positivo distinto de 0 y que sea menor 150:\t");
                	gets (u);
				}
						sprintf(m, "%.2f", atof(u));
					    strcpy(x[y].datos_srv.nmservicio_servicio[2][*q - 1], m);
            } 
        printf("Desea elegir otro servicio (s/n): ");
	       fgets(w, sizeof(w), stdin);
	        w[strcspn(w, "\n")] = '\0';
        if(strcasecmp(w,s) != 0 &&strcasecmp(w,t) != 0 )
        {
        	while (strcasecmp(w,s) != 0 &&strcasecmp(w,t) != 0 )
        	{
        		printf("Las opciones validas son si(s) o no (n),ingres una de las opciones validas:");
	        	fgets(w, sizeof(w), stdin);
	            w[strcspn(w, "\n")] = '\0';
			}
		}
		A=*z+*q+*r;
		if (A>=10)
				   {
				   	printf ("Solo se pueden agregar un maximo de 10 pedidos por servicios\n");
				   	break;
				   }
    } while (strcasecmp(w,s) == 0 );

	}
void acomodar (struct Proyecto x[Cl], int k, int z, int q, int r)
{
    int i;
    
    for (i = 0; i < z; i++)
    {
        strcpy(x[k].datos_srv.servicio_seleccionado[i][1], x[k].datos_srv.nmservicio_servicio[0][i]);
    }

    for (i = 0; i < r; i++)
    {
        strcpy(x[k].datos_srv.servicio_seleccionado[z + i][1], x[k].datos_srv.nmservicio_servicio[1][i]);
    }

    for (i = 0; i < q; i++)
    {
        strcpy(x[k].datos_srv.servicio_seleccionado[z + r + i][1], x[k].datos_srv.nmservicio_servicio[2][i]);
        
    }
printf("\n");
}

void menuOp(Proyecto x[Cl])
{
	int f,cont=0,i=0,k=0,z=0, q=0, r=0;;
	do
	{
		MenuPrincipal();
		scanf("%i",&f);
		while(f<1||f>7)
		{
		MenuPrincipal2();
		scanf("%i",&f);
		}
		switch (f)
		{
		case 1:
		{
			mostrarDatosEmpresa(x,i,k);
			ingreso_datos_C(x,i);
			servicios(x,i,&z, &q, &r);
			i++;
		}
		break;
		case 2:
		{
			if(x[0].datos_clt.cedula_cliente==0&&x[0].datos_clt.ruc_cliente==0)
			{
			printf("No existe facturas para buscar\n");
			break;
			}
		}
		break;
		case 3:
		{
			if(x[0].datos_clt.cedula_cliente==0&&x[0].datos_clt.ruc_cliente==0)
			{
			printf("No existe facturas para Cambiar\n");
			break;
			}
			cambiarM(x,i);
		}
			break;
		case 4:
		{
			if(x[0].datos_clt.cedula_cliente==0&&x[0].datos_clt.ruc_cliente==0)
			{
			printf("No existe facturas para Eliminar\n");
			break;
			}
		}
			break;
		case 5:
		{
			if(x[0].datos_clt.cedula_cliente==0)
			{
			printf("No existe facturas para imprimir una factura buscada\n");
			break;
			}

		}
			break;
		case 6:
		{
			if(x[0].datos_clt.cedula_cliente==0&&x[0].datos_clt.ruc_cliente==0)
			{
			printf("No existe facturas para imprimir todas\n");
			break;
			}
		}
			break;
		default:
		{
			printf("Gracias por utilizar el programa\n");
			cont++;
			system("pause"); 
		}
		}
	} while (cont<1);
	
}
int main()
{
    Proyecto a2[Cl];
	menuOp(a2);
    return 0;
}