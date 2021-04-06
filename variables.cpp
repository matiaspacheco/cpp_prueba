#include <stdio.h>

int sumar(int n1, int n2){
    int total;
    total = n1 + n2;
    return(total);
}

// Principal
int main(){
    int onNumber, twNumber; //Variable Entero
    float onReal; // Variable Real
    char onText; // Variable caracter

    printf("Ingrese un  numero \n");
    scanf("%d", &onNumber);

    twNumber = 10;

    printf("La suma de %d + %d = %d \n", onNumber, twNumber, sumar(onNumber, twNumber));

    fflush(stdin); //TODO: colocarlo siempre antes de asignar un char
    printf("Ingrese una letra \n");
    scanf("%c", &onText);

    printf("La letra ingresada es %c \n", onText);


}
