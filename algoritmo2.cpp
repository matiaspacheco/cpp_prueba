/*Algoritmo Media
entero calculo (entero xa , entero xb)
Comienzo
entero c
c= (xa + xb) / 2
retorna (c)
Fin
//----Algoritmo principal----
Comienzo
entero a, b
Escribir “Introduzca primer número (entero):"
Leer a
Escribir “Introduzca segundo número (entero): “
Leer b
Si (( a > 0) y (b > 0 ))
entonces Escribir “La media aritmética de: ”, a, b, “es”, calculo (a, b)
sino Escribir “uno de los dos números no es positivo ”
Finsi
Fin
*/

#include <stdio.h>

int calcula_media(int xa, int xb){
    return((xa+xb)/2);
}

int main(){
    int a, b;
    printf("Introduzca primer numero (entero): \n");
    scanf("%d", &a);
    printf("Introduzca segundo numero (entero): \n");
    scanf("%d", &b);

    if (a > 0 && b > 0)
        printf("La media aritmetica de %d y %d es: %d \n", a, b, calcula_media(a, b));
    else
        printf("Uno de los dos numeros no es positivo");

}
