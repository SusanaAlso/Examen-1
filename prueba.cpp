#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Empleado {
    char cedula[20];
    char nombre[50];
    int tipo; 
    double horasLaboradas;
    double precioHora;
};

int main() {
    Empleado empleados[100];
    int contador = 0;
    char continuar;

    do {
        printf("Ingrese la cedula del empleado: \n");
        scanf("%s", empleados[contador].cedula);
        printf("Ingrese el nombre completo del empleado: \n");
        getchar(); 
        fgets(empleados[contador].nombre, sizeof(empleados[contador].nombre), stdin);
        printf("Ingrese el tipo de empleado (1: Operario, 2: Tecnico, 3: Profesional): \n");
        scanf("%d", &empleados[contador].tipo);
        printf("Ingrese la cantidad de horas laboradas: \n");
        scanf("%lf", &empleados[contador].horasLaboradas);
        printf("Ingrese el precio por hora: \n");
        scanf("%lf", &empleados[contador].precioHora);

        contador++;

        printf("Quiere ingresar otro empleado? (s/n): \n");
        continuar = getch(); 

    } while (continuar == 's' || continuar == 'S');

    for (int i = 0; i < contador; i++) {
        double salarioOrdinario = empleados[i].horasLaboradas * empleados[i].precioHora;
        double aumento = 0;

        switch (empleados[i].tipo) {
            case 1: aumento = salarioOrdinario * 0.15; 
			break;
            case 2: aumento = salarioOrdinario * 0.10; 
			break; 
            case 3: aumento = salarioOrdinario * 0.05; 
			break; 
        }

        double salarioBruto = salarioOrdinario + aumento;
        double deduccionCCSS = salarioBruto * 0.0917;
        double salarioNeto = salarioBruto - deduccionCCSS;

        printf("\n Empleado %d: \n", i + 1);
        printf("Cedula: %s\n", empleados[i].cedula);
        printf("Nombre: %s", empleados[i].nombre);
        printf("Salario Ordinario: %.2f\n", salarioOrdinario);
        printf("Aumento: %.2f\n", aumento);
        printf("Salario Bruto: %.2f\n", salarioBruto);
        printf("Deducción CCSS: %.2f\n", deduccionCCSS);
        printf("Salario Neto: %.2f\n", salarioNeto);
    }

    return 0;
}

