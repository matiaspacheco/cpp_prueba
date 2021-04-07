/*
Un banco tiene un sistema la compra de dólares. Para la operación de compra se conoce la cantidad
de dólares que se quiere comprar y el importe de venta de cada dólar. Esta operación tiene una
comisión administrativa 5% sobre el importe total si la cantidad de dólares es más de 5000. Dicha
comisión se adiciona al monto que el cliente debe pagar.
Realizar un algoritmo que usando subprogramas muestre un ticket indicando: la cantidad de dólares
que se compraron, el valor de cada dólar, el monto de la comisión y el monto total que el cliente
debe abonar por la compra.
*/

#include <stdio.h>

void ticket(float xdolar, float prdolar, float xcomi){
    float xtotal;
    printf(" ******** Ticket ******** \n");
    printf(" *Cant. Dolar **** %.2f \n", xdolar);
    printf(" *Prec. Dolar **** %.2f \n", prdolar);

    xtotal = xdolar * prdolar;
    if (xcomi != 0)
        printf(" *Comision ****** %.2f \n", (xtotal * 5)/100 );
        xtotal = xtotal * 1.05;

    printf(" *Total ****** %.2f \n", xtotal);

}

int main(){
    float dolar = 5498.5, xdinero = 190.4 ;
    int comision = 0 ;
    if (dolar > 5000)
        comision = 1;

    ticket(dolar, xdinero, comision);

}
