/*
Nombre: Facturacion
Autor: Richard Ramirez Patiño - Sebastian Urbano
Fecha: 11/09/2017
Resumen: Software de facturacion.
*/
//Libreria
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Estructura Contacto
struct Contacto{
	char nombre[30];
	int  cedula;
	char direccion[30];
	int  id;
	char telefono[13];
}c[100], *pC = c;
//Estructura Productos
struct Productos{
	int id;
	char nombre[30];
	float valor;
}p[100], *pP = p;
//Estructura Factura
struct factura{
	int id;
	int cantidad;
	int total;
	bool estado;
}f[100], *pf = f;
//Prototipos Funciones Productos
void Ingresar_Producto();
void Lista_Producto();
void Editar_Producto();
void menu_producto();
//Prototipo Funciones Clientes
void leerContacto();
void Editar_Clientes();
void Lista_clientes();
void menu_cliente();
//prototipos Funciones Facturas
void Crear_Factura();
void Lista_Factura();
//Prototipo Funcion Menu
void Menu();
void menu_cliente();
void menu_producto();
void menu_factura();
//Variables Globales
int prod = 0;
int cont = 0;
int fact = 0;
void Menu();
//Funcion Principal
int main(){
	Menu();
}
//MEnu Principal
void Menu(){
	int opcion;
	fflush(stdin);
	do{
		printf("******************************\n");
		printf("*           MENU             *\n");
		printf("******************************\n");
		printf("*                            *\n");
		printf("*     1. Clientes            *\n");
		printf("*     2. Productos           *\n");
		printf("*     3. Facturas            *\n");
		printf("*     0. Salir               *\n");
		printf("*                            *\n");
		printf("******************************\n\n");
		printf("Que deceas hacer: ");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
		case 1:menu_cliente();
			break;
		case 2:menu_producto();
			break;
		case 3:menu_factura();
			break;
		case 0:exit(0);
			break;
		default:printf("\t\tNumero Equivocado\n\n");
			break;
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}
//Funcion Menu Cliente
void menu_cliente(){
	int opcion;
	fflush(stdin);
	do{
		printf("******************************\n");
		printf("*           MENU             *\n");
		printf("******************************\n");
		printf("*                            *\n");
		printf("*     1. Ingresar Cliente.   *\n");
		printf("*     2. Mostar Cliente.     *\n");
		printf("*     3. Editar Clientes.    *\n");
		printf("*     0. Salir               *\n");
		printf("*                            *\n");
		printf("******************************\n\n");
		printf("Que deceas hacer: ");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
		case 1:leerContacto();
			break;
		case 2:Lista_clientes();
			break;
		case 3:Editar_Clientes();
			break;
		case 0:Menu();
			break;
		default:printf("\t\tNumero Equivocado\n\n");
			break;
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}

void leerContacto(){
	int n;
	fflush(stdin);
	printf("--- Clientes ---\n\n");
	printf("Cuantos clientes vas a ingresar: ");
	scanf("%d",&n);
	system("cls");
	if(cont != 0){
		n = n+2;
	}
	for(int i = cont; i < n; i++){
		fflush(stdin);
		(pC+i)->id = i+1;
		printf("--- Clientes ---\n\n");
		fflush(stdin);
		printf("Nombre: ");
		fgets((pC + i)->nombre,30,stdin);
		fflush(stdin);
		printf("\nCedula: ");
		fflush(stdin);
		scanf("%d",&(pC + i)->cedula);
		printf("\nDireccion: ");
		fflush(stdin);
		fgets((pC + i)->direccion,30,stdin);
		printf("\nTelefono: ");
		fflush(stdin);
		fgets((pC + i)->telefono,13,stdin);
		cont ++;
		system("cls");
	}printf("\nGuardado con exito\n\n");
}

void Lista_clientes(){
	int i, j;
	int aux;
	
	for(i = 0; i < cont-1; i++){
		for(j = i+1; j < cont; j++){
			if((pC + i)->id > (pC + j)->id){
				aux = (pC + i)->id;
				(pC + i)->id = (pC + j)->id;
				(pC + j)->id = aux;
			}
		}
	}
	printf("--- Clientes ---\n\n");
	for(int i = 0; i < cont; i++){
		fflush(stdin);
		printf("Nombre: %s",(pC + i)->nombre);
		printf("ID: %d",(pC + i)->id);
		printf("\nCedula: %d",(pC + i)->cedula);
		printf("\nDireccion: %s",(pC + i)->direccion);
		printf("Telefono: %s\n\n",(pC + i)->telefono);
	}
	
}
void Editar_Clientes(){
	int opc = 0;
	char opcion;
	int i, j;
	int aux;
	
	fflush(stdin);
	printf("--- Clientes ---\n\n");
	for(int i= 0; i < cont; i++){
		printf("%d. %s",i,(pC+i)->nombre);
		printf("\nID: %d\n\n",(pC+i)->id);
	}
	printf("Que clientes quieres editar: ");
	scanf("%d",&opc);
	(pC+opc)->id = i+1;
	system("cls");
	fflush(stdin);
	printf("--- Clientes ---\n\n");
	printf("Nombre: ");
	fgets((pC + opc)->nombre,30,stdin);
	fflush(stdin);
	printf("\nCedula: ");
	fflush(stdin);
	scanf("%d",&(pC + opc)->cedula);
	printf("\nDireccion: ");
	fflush(stdin);
	fgets((pC + opc)->direccion,30,stdin);
	printf("\nTelefono: ");
	fflush(stdin);
	fgets((pC + opc)->telefono,13,stdin);
	system("cls");
	printf("\n\nEditado con exito\n\n");
	printf("Quieres editar otro cliente\n\n");
	printf("1. si \n");
	printf("2. no\n\n");
	printf("Que deceas hacer: ");
	scanf("%d",&opcion);
	while(opcion != 2){
		for(i=0; i < cont-1; i++){
			for(j = i+1; j < cont; j++){
				if((pC + i)->id > (pC + j)->id){
					aux = (pC + i)->id;
					(pC + i)->id = (pC + j)->id;
					(pC + j)->id = aux;
				}
			}
		}
		Editar_Clientes();
	}	
}
void menu_producto(){
	int opcion;
	fflush(stdin);
	do{
		printf("******************************\n");
		printf("*           MENU             *\n");
		printf("******************************\n");
		printf("*                            *\n");
		printf("*     1. Ingresar Producto.  *\n");
		printf("*     2. Mostrar Producto.   *\n");
		printf("*     3. Editar Producto.    *\n");
		printf("*     0. Salir               *\n");
		printf("*                            *\n");
		printf("******************************\n\n");
		printf("Que deceas hacer: ");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
		case 1:Ingresar_Producto();
		break;
		case 2:Lista_Producto();
		break;
		case 3:Editar_Producto();
		break;
		case 0:Menu();
		break;
		default:printf("\t\tNumero Equivocado\n\n");
		break;
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}

void Ingresar_Producto(){
	int numero;
	fflush(stdin);
	printf("--- Productos ---\n\n");
	printf("Cuantos Productos vas a ingresar: ");
	scanf("%d",&numero);
	system("cls");
	if(prod != 0){
		numero = numero+2;
	}
	for(int i = prod; i < numero; i++){
		fflush(stdin);
		(pP+i)->id = i+1;
		printf("--- Productos ---\n\n");
		fflush(stdin);
		printf("Nombre: ");
		fgets((pP + i)->nombre,30,stdin);
		fflush(stdin);
		printf("\nValor: ");
		fflush(stdin);
		scanf("%f",&(pP + i)->valor);
		printf("\nIngrese la cantidad comprada por el cliente:  ");
		scanf("%d",&(pf + i)->cantidad);
		prod ++;
		system("cls");
	}printf("\nGuardado con exito\n\n");
}

void Lista_Producto(){
	int i, j;
	int temp;
	
	/*for(i = 0; i < prod-1; i++){
		for(j = i+1; j < prod; j++){
			if((pP + i)->id > (pP + j)->id){
				temp = (pP + i)->id;
				(pP + i)->id = (pP + j)->id;
				(pP + j)->id = temp;
			}
		}
	}*/
	printf("--- Producto ---\n\n");
	for(int i = 0; i < prod; i++){
		fflush(stdin);
		printf("Nombre: %s",(pP + i)->nombre);
		printf("ID: %d\n",(pP + i)->id);
		printf("Valor: %.1f\n\n",(pP + i)->valor);
	}
	
}
void Editar_Producto(){
	int Opc = 0;
	char Opcion;
	int i, j;
	int temp;
	
	fflush(stdin);
	printf("--- Clientes ---\n\n");
	for(int i= 0; i < prod; i++){
		printf("%d. %s",i,(pP+i)->nombre);
		printf("\n  ID: %d\n\n",(pP+i)->id);
	}
	printf("Que clientes quieres editar: ");
	(pP+Opc)->id = i+1;
	scanf("%d",&Opc);
	system("cls");
	fflush(stdin);
	fflush(stdin);
	printf("--- Datos Antiguos ---\n\n");
	printf("Nombre: %s\n",(pP + Opc)->nombre);
	printf("ID: %d\n",(pP + Opc)->id);
	printf("Valor: %.1f\n\n",(pP + Opc)->valor);
	printf("--- Datos Nuevos ---\n\n");
	printf("\nNombre: ");
	fgets((pP + Opc)->nombre,30,stdin);
	fflush(stdin);
	printf("\nID: ");
	scanf("%d",&(pP + Opc)->id);
	printf("\nValor: ");
	fflush(stdin);
	scanf("%f",&(pP + Opc)->valor);
	system("cls");
	printf("\n\nEditado con exito\n\n");
	printf("Quieres editar otro Producto\n\n");
	printf("1. si \n");
	printf("2. no\n\n");
	printf("Que deceas hacer: ");
	scanf("%d",&Opcion);
	while(Opcion != 2){
		/*for(i=0; i < prod-1; i++){
			for(j = i+1; j < prod; j++){
				if((pP + i)->id > (pP + j)->id){
					temp = (pP + i)->id;
					(pP + i)->id = (pP + j)->id;
					(pP + j)->id = temp;
				}
			}
		}*/
		Editar_Producto();
	}	
}

void menu_factura(){
	int opcion; 
	fflush(stdin);
	do{
		printf("******************************\n");
		printf("*           MENU             *\n");
		printf("******************************\n");
		printf("*                            *\n");
		printf("*     1. Crear Factura.      *\n");
		printf("*     2. Listar Factura.     *\n");
		printf("*     0. Salir               *\n");
		printf("*                            *\n");
		printf("******************************\n\n");
		printf("Que deceas hacer: ");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
			case 1:Crear_Factura();
				break;
			case 2:Lista_Factura();
				break;
			case 0:Menu();
				break;
			default:printf("Numero Equivocado\n\n");
				break;
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}

void Crear_Factura(){
	int i = 0, opcion, id;
	for(i=fact; i<cont; i++){
		(pf+i)->estado = true;
		
		(pf+i)->id  = (pf + i)->cantidad *2;
		printf("\nFactura creada");
		printf("\nquiere generar otra factura?");
		printf("\n1.si");
		printf("\n2.no\n");
		scanf("%d",&opcion);
		if(opcion == 1){
			fflush(stdin);
			Crear_Factura();
		}
		fact++;
	}
}

void Lista_Factura(){
	int i, j;
	int temp;
	
	/*for(i = 0; i < prod-1; i++){
		for(j = i+1; j < prod; j++){
			if((pf + i)->id > (pf + j)->id{
				temp = (pf + i)->id;
				(pf + i)->id = (pf + j)->id;
				(pf + j)->id = temp;
			}
		}
	}*/
	
	printf("\t\t--- FACTURA ---\n\n");
	for(int i = 0; i < prod; i++){
		printf("\nID: %d\n",(pf + i)->id);
		printf("Cliente: %s",(pC + i)->nombre);
		printf("Producto: %s",(pP + i)->nombre);
		printf("Valor: %.1f",(pP + i)->valor);
		printf("\nCantidad de productos: %d",(pf + i)->cantidad);
		((pf + i)->total)= ((pP + i)->valor)*((pf + i)->cantidad);
		printf("\nValor total de la compra: %d",(pf + i)->total);	
		printf("\nEstado: %B\n\n",(pf + i)->estado);	
	}	
}


