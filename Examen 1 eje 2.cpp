#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Venta {
    int numeroFactura;
    char cedula[20];
    char nombre[50];
    int localidad; 
    int cantidadEntradas;
};

int main() {
    Venta ventas[100]; 
    int contador = 0;
    char seguir;
    
    int entradasLocalidad[3] = {0}; 
    double acumuladoLocalidad[3] = {0}; 
    double precios[3] = {10500, 20500, 25500}; 

    do {
        printf("Ingrese el numero de factura: \n");
        scanf("%d", &ventas[contador].numeroFactura);
        printf("Ingrese la cedula del comprador: \n");
        scanf("%s", ventas[contador].cedula);
        printf("Ingrese el nombre del comprador: \n");
        getchar();
        fgets(ventas[contador].nombre, sizeof(ventas[contador].nombre), stdin);
    
        printf("Seleccione la localidad (1: Sol Norte/Sur, 2: Sombra Este/Oeste, 3: Preferencial): \n");
        scanf("%d", &ventas[contador].localidad);
        
        while (ventas[contador].localidad < 1 || ventas[contador].localidad > 3) {
            printf("Localidad no valida. Intente de nuevo: \n");
            scanf("%d", &ventas[contador].localidad);
        }
      
        printf("Ingrese la cantidad de entradas (maximo 4): \n");
        scanf("%d", &ventas[contador].cantidadEntradas);
    
        while (ventas[contador].cantidadEntradas < 1 || ventas[contador].cantidadEntradas > 4) {
            printf("Cantidad no válida. Ingrese de nuevo (maximo 4): \n");
            scanf("%d", &ventas[contador].cantidadEntradas);
        }

        double precioEntrada = precios[ventas[contador].localidad - 1];
        double subtotal = ventas[contador].cantidadEntradas * precioEntrada;
        double cargos = 1000 * ventas[contador].cantidadEntradas;
        double totalPagar = subtotal + cargos;

        entradasLocalidad[ventas[contador].localidad - 1] += ventas[contador].cantidadEntradas;
        acumuladoLocalidad[ventas[contador].localidad - 1] += subtotal;

        printf("\n Venta:\n");
        printf("Numero de factura: %d\n", ventas[contador].numeroFactura);
        printf("Cedula: %s\n", ventas[contador].cedula);
        printf("Nombre del comprador: %s", ventas[contador].nombre);
        printf("Localidad: %d\n", ventas[contador].localidad);
        printf("Cantidad de entradas: %d\n", ventas[contador].cantidadEntradas);
        printf("Subtotal: %.2f colones\n", subtotal);
        printf("Cargos por servicios: %.2f colones\n", cargos);
        printf("Total a pagar: %.2f colones\n", totalPagar);

        contador++;

        printf("\n Quiere ingresar otra venta? (s/n): \n");
        seguir = getch(); // Leer opción sin necesidad de Enter

    } while (seguir == 's' || seguir == 'S');

    printf("Cantidad de entradas en la localidad Sol Norte/Sur: %d\n", entradasLocalidad[0]);
    printf("Acumulado de dinero en la localidad Sol Norte/Sur: %.2f colones\n", acumuladoLocalidad[0]);
    printf("Cantidad de entradas en la localidad Sombra Este/Oeste: %d\n", entradasLocalidad[1]);
    printf("Acumulado de dinero en la localidad Sombra Este/Oeste: %.2f colones\n", acumuladoLocalidad[1]);
    printf("Cantidad de entradas en la localidad Preferencial: %d\n", entradasLocalidad[2]);
    printf("Acumulado de dinero en la localidad Preferencial: %.2f colones\n", acumuladoLocalidad[2]);

    return 0;
}

