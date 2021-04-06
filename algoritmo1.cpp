/*
Algoritmo Paridad
void mensaje-paridad (entero xx , entero zz)
Comienzo
constante y=2
SI ((xx + zz) resto y != 0 )
entonces Escribir xx , “+”, zz, “es impar”
sino Escribir xx , “+”, zz, “es Par”
FinSi
retorna ()
Fin
//Algoritmo principal----
Comienzo
entero x, z
Escribir “Introduzca primer valor (entero):"
Leer x
Escribir “Introduzca segundo valor (entero): “
Leer z
mensaje-paridad (x,z)
Fin
*/
#include <stdio.h>

void msj_paridad(int xx, int zz) {
    int y = 2;
    if ( (xx + zz) % y != 0 )
        printf("%d + %d es impar. \n", xx, zz);
    else
        printf("%d + %d es par. \n", xx, zz);

}

int main(){
    int x, z;
    printf("Ingrese valor 1 (entero): \n");
    scanf("%d", &x);
    printf("Ingrese valor 2 (entero): \n");
    scanf("%d", &z);

    msj_paridad(x,z);
}
