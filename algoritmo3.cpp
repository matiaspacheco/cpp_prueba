/*
Realizar un algoritmo con subprogramas que determine si alcanzan los bancos existentes en un
aula, de no ser así, informar cuantos bancos es necesario agregar. Se cuenta con la cantidad de
bancos del aula y la cantidad de alumnos inscriptos para ese curso.
*/

#include <stdio.h>

void banco(int banc, int alumn) {
    if (banc < alumn)
        printf("Faltan %d bancos para los %d alumnos", (alumn - banc), alumn);
    else
        printf("Hay bancos de sobra");
}

int main(){
    int bancos = 45, alumnos = 50;
    banco(bancos, alumnos);
}
