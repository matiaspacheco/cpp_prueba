/*Algoritmo IPV
//subprograma
void menu()
comienzo
	escribir "Ingrese opción \n 1: Trabajar \n 0: Salir \n"
	retorna()
fin
void op_menu()
comenzar
	escribir "Ingrese tipo de operación \n P: Procrear \n S: Sorteo \n A: Préstamo para ampliación \n"
	retorna()
fin
//calculo porcentaje
real cal_por(enter v1, entero v2)
comenzar
	real porc = (v1*100)/v2
	retorna(porc)
fin
cadena tipoOp(caracter op)
comenzar
	//'P'. Procrear, 'S': sorteo, 'A': préstamo para ampliación
	segun(op)
		'P': retorna ('Procrear')
		'S': retorna ('Sorteo')
		'A': retorna ('Préstamo para ampliación')
	finsegun
	retorna()
fin

void xshow( entero xdeudores, entero adj_p_xmil_nocuota, entero adj_a_xxmil_deuda, entero adj_a_deuda, real deudatotal, booleano xmas8, cadena min_nom, caracter min_op )
comenzar
	escribir "Los adjudicatarios que adeudan cuotas:", xdeudores
	escribir "La cantidad de adjudicatarios por la operatoria de Procrear, con un ingreso mensual superior a los $10000 que no adeudan cuotas son: ", adj_p_xmil_nocuota
	escribir "El porcentaje respecto del total que adeudan cuotas, de adjudicatarios por la operatoria de préstamo para ampliación son: ",cal_por(adj_a_xxmil_deuda,adj_a_deuda)
	escribir "El importe total de dinero adeudado al IPV por los adjudicatarios es de: ", deudatotal
	si (xmas8)
		entonces escribir "Hay adjudicatarios que debe mas de 8 cuotas"
	finsi
	escribir "La persona con el menor ingreso mensual es ", min_nom, " y realizaba una operación tipo: ", tipoOp(min_op)
    retorna()
fin

//principal
comienzo
	//variables
	entero cant_adj_p = 0, cant_adj_s = 0, cant_adj_a = 0, xdeudores = 0 
	entero adj_p_xmil_nocuota = 0, adj_a_xxmil_deuda = 0, adj_p_deuda = 0, adj_s_deuda = 0, adj_a_deuda = 0
	entero dni_adj, imp_cuota, deudaxcuota, op
	real ingresoxmes, deudatotal = 0
	booleano xmas8 = falso
	cadena nombre_adj
	caracter operatoria // P - S - A
	//min
	entero min_ing = 1000000000 //valor absurdo
	caracter min_op
	cadena min_nom


	//init
	menu()
	leer op
	mientras( op > 0 )
		escribir "Ingrese DNI del adjudicatario"
		leer dni_adj
		escribir "Ingrese NOMBRE del adjudicatario"
		leer nombre_adj
		op_menu()
		leer operatoria
		escribir "Ingrese Cuota Adeudada"
		leer deudaxcuota
		escribir "Ingrese importe de la cuota"
		leer imp_cuota
		escribir "Ingreso mensual del adjudicatario"
		leer ingresoxmes

		si ( deudaxcuota > 0 )
			entonces xdeudores++ // TODO: 1
		finsi

		// TODO: 2
		segun(operatoria)
			'P': si ( (deudaxcuota==0)  y (ingresoxmes>10000))
					entocnes adj_p_xmil_nocuota++
					sino si( deudaxcuota > 0 )
						entonces adj_p_deuda++
					finsi
				finsi
				cant_adj_p++
			'S': si ( deudaxcuota > 0 )
					entonces adj_s_deuda++
				finsi
				cant_adj_s++
			'A': si ( ( ingresoxmes >= 10000 y ingresoxmes <= 20000 ) y ( deudaxcuota > 2 ) ) // TODO: 3
					entonces adj_a_xxmil_deuda++
							 adj_a_deuda++
					sino si ( deudaxcuota > 0 )
						entonces adj_a_deuda++
					finsi
				finsi
				cant_adj_a++
		finsegun


		// TODO: 4
		deudatotal = deudatotal + ( imp_cuota * deudaxcuota )

		// TODO: 5
		si ( deudaxcuota > 8 )
			entonces xmas8 = verdadero

		// TODO: 6
		si ( ingresoxmes < min_ing )
			entocnes min_ing = ingresoxmes
					 min_op = operatoria
					 min_nom = nombre_adj
		finsi

		menu()
		leer op
	finmientras

	xshow( xdeudores, adj_p_xmil_nocuota, adj_a_xxmil_deuda, adj_a_deuda, deudatotal, xmas8, min_nom, min_op )

	retorna()
fin
*/

#include <stdio.h>
#include <string.h>

void menu() {
	printf("Ingrese opcion \n 1: Trabajar \n 0: Salir \n");
	return;
}
void op_menu() {
	printf("Ingrese tipo de operacion \n P: Procrear \n S: Sorteo \n A: Prestamo para ampliacion \n");
	return;
}

//calculo porcentaje
float cal_por(int v1, int v2) {
	float porc = (v1*100)/v2;
	return(porc);
	
}

char* tipoOp(char op) {
	char tipo[25];
	switch( op ) {
		case 'p':
		case 'P': {
			strcpy(tipo, "Procrear"); 
			//tipo = "Procrear";
			break;
		}
		case 's':
		case 'S': {
			strcpy(tipo, "Sorteo"); 
			//tipo = "Sorteo";	
			break;
		}
		case 'a':
		case 'A': {
			strcpy(tipo, "Prestamo para ampliacion"); 
			//tipo = "Prestamo para ampliacion";				
			break;
		}		
	}	
	return tipo;
}


void xIPVshow( int xdeudores, int adj_p_xmil_nocuota, int adj_a_xxmil_deuda, int adj_a_deuda, float deudatotal, bool xmas8, char min_nom[20], char min_op ) {
	printf("Los adjudicatarios que adeudan cuotas: %d \n", xdeudores);
	if (adj_p_xmil_nocuota)
		printf("La cantidad de adjudicatarios por la operatoria de Procrear, con un ingreso mensual superior a los $10000 que no adeudan cuotas son: %d \n", adj_p_xmil_nocuota);
	if (adj_a_xxmil_deuda)
		printf("El porcentaje respecto del total que adeudan cuotas, de adjudicatarios por la operatoria de prestamo para ampliacion son: %.2f \n", cal_por(adj_a_xxmil_deuda, adj_a_deuda));
	if (deudatotal)
		printf("El importe total de dinero adeudado al IPV por los adjudicatarios es de: %.2f \n", deudatotal);
	if (xmas8)
		printf("Hay adjudicatarios que debe mas de 8 cuotas \n");
	if (min_nom)
		printf("La persona con el menor ingreso mensual es '%s' y realizaba una operacion tipo: %s \n", min_nom, tipoOp(min_op) );
    return;
}

int main(){
	//variables
	int cant_adj_p = 0, cant_adj_s = 0, cant_adj_a = 0, xdeudores = 0;
	int adj_p_xmil_nocuota = 0, adj_a_xxmil_deuda = 0, adj_p_deuda = 0, adj_s_deuda = 0, adj_a_deuda = 0;
	int dni_adj, imp_cuota, deudaxcuota, op;
	float ingresoxmes, deudatotal = 0;
	bool xmas8 = false;
	char nombre_adj[20];
	char operatoria; // P - S - A
	//min
	int min_ing = 1000000000; //valor absurdo
	char min_op;
	char min_nom[20];
	
	menu();
	scanf("%d", &op);
	
	while( op > 0 ) {		
		printf("Ingrese DNI del adjudicatario \n");
		scanf("%d", &dni_adj);
		fflush(stdin);
		printf("Ingrese NOMBRE del adjudicatario\n");
		scanf("%s", &nombre_adj);
		fflush(stdin);	
		op_menu();
		scanf("%c", &operatoria);			
		printf("Ingrese Cuota Adeudada\n");
		scanf("%d", &deudaxcuota);		
		printf("Ingrese importe de la cuota\n");
		scanf("%d", &imp_cuota);		
		printf("Ingreso mensual del adjudicatario\n");
		scanf("%f", &ingresoxmes);
		
		//int
		if ( deudaxcuota > 0 )
			xdeudores++; // TODO: 1
		
		// TODO: 2
		switch(operatoria) {
			case 'p':
			case 'P': {
				if ((deudaxcuota==0) && (ingresoxmes>10000))
					adj_p_xmil_nocuota++;
				else if ( deudaxcuota > 0 ) {
					adj_p_deuda++;
				}
				cant_adj_p++;
				break;
			}
			case 's':
			case 'S': {
				if ( deudaxcuota > 0 ) {
					adj_s_deuda++;
				}
				cant_adj_s++;
				break;
			}
			case 'a':
			case 'A': {
				if ( ( ingresoxmes >= 10000 || ingresoxmes <= 20000 ) && ( deudaxcuota > 2 ) ) { // TODO: 3
					adj_a_xxmil_deuda++;
					adj_a_deuda++;
				} else {
					if ( deudaxcuota > 0 ) 
						adj_a_deuda++;
				}
				cant_adj_a++;
				break;
			}
				
		}
		
		// TODO: 4
		deudatotal = deudatotal + ( imp_cuota * deudaxcuota );
		
		// TODO: 5
		if ( deudaxcuota > 8 )
			xmas8 = true;
			
		// TODO: 6
		if ( ingresoxmes < min_ing ) {
			min_ing = ingresoxmes;
			min_op = operatoria;
			strcpy(min_nom, nombre_adj); 	
		}				
		
		menu();
		scanf("%d", &op);
	}
	
	xIPVshow(xdeudores, adj_p_xmil_nocuota, adj_a_xxmil_deuda, adj_a_deuda, deudatotal, xmas8, min_nom, min_op);
	return(0);
}
