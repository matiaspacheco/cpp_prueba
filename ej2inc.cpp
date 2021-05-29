// Pacheco, Matias W.

/*
Ejercicio 2
En un centro médico se procesa la información de los pacientes que asisten, de cada uno se registra el número de
especialidad (1..12) en la que se atiende
Construya un algoritmo que, usando de manera óptima subprogramas (al menos uno por ítem) permita:
1. Indicar la cantidad de pacientes por especialidad.
2. Generar un subarreglo que contenga el Numero de especialidad para aquellas especialidades donde la cantidad
de pacientes atendidos es menor a 10.
3. Muestre la estructura de datos generada en el inciso 2) ordenada descendentemente.
*/
#include <stdio.h>
#define N 5 //ToDO: change N pacientes

struct paciente {
	int cant;
	int esp;
};

//subprograma
void cerea(paciente P[N]) {
	int i;
	for (i=0; i<N; i++) {
		P[i].esp = 0;
		P[i].cant = 0;
	}
	return;
}

void carga(paciente P[N]) {
	int esp
	;

	printf("Ingrese especialidad (1 hasta 12) \n");
	scanf("%d", &esp);

	while ( (esp>0) && (esp<=12) ) {
		if (esp != P[esp-1].esp) {
			P[esp-1].esp = esp;
			P[esp-1].cant = P[esp-1].cant+1;
		} else {
			P[esp-1].cant = P[esp-1].cant+1;
		}

		printf("Ingrese especialidad (1 hasta 12) \n");
		scanf("%d", &esp);
	}
	return;
}

void muestra_cant(paciente P[N]) {
	int i;

	for(i=0; i<N; i++) {
		printf("La especialidad: %d tiene un total de: %d pacientes \n", P[i].esp, P[i].cant);
	}

	return;
}

int genera_sub(paciente P[N], int subAr[N]) {
	int i, e=0;

	for(i=0; i<N; i++) {
		if ( P[i].cant < 10 ) {
			subAr[e] = P[i].esp;
			e++;
		}
	}

	return(e);
}

void ordena(int subAr[N]) {
    int k, i, aux, cota;
    cota = N-1;
    k = 1;
    while(k!=-1) {
        k=-1;
        for(i=0; i<cota-1;i++) {
            if (subAr[i] > subAr[i+1]) {
                aux = subAr[i];
                subAr[i] = subAr[i+1];
                subAr[i+1] = aux;
                k = i;
            }
        }
        cota = k;
    }

	return;
}

void mostrar(int subAr[N], int e) {
	int i;

	printf("La especialidades con menos de 10 pacientes son: \n");

    for(i=e+1; i>=0; i--) {
	    if (subAr[i]!=0)
            printf("Especialidad: %d \n", subAr[i]);
	}

	return;
}

// Principal
int main() {
	paciente P[N];
	int subAr[N], e;

	cerea(P);
	carga(P);
	muestra_cant(P);//1
	e = genera_sub(P, subAr); //2
	//3
	ordena(subAr);
	mostrar(subAr, e);
}



