/*Desarrolle un programa en c que permita registrar las citas medicas de la clinica abc de n cantidad
de pacientes permitiendo mostrar por pantalla:
    1)cantidad de pacientes femeninos
    2)cantidad de pacientes masculinos
    3)cantidad de pacientes mayores de edad
    4)cantidad de pacientes menores de edad
y que ademas permita validar las fechas de nacimiento de cada paciente y los pacientes cuya C.I. terminen
en un numero par y sean del sexo femenino tendran un descuento del 15% sobre el costo de la consulta y los
pacientes del sexo masculino que no tengan una edad mayor a 60 años tendran un descuento del 30%*/

#include<stdio.h>

int main()
{
    int n, i;
    int edad, ci, sexo, n_dia, n_mes, n_year;
    int p_femeninos, p_masculinos, p_mayores, p_menores;
    float costo;

    do{
        printf("Ingrese la cantidad de pacientes: ");
        scanf("%d",&n);
    }while(n<1);

    for(i = 0; i<n; i++)
    {
        do
        {
            printf("Ingrese el sexo del paciente (1:femenino 0:masculino): ");
            scanf("%d",&sexo);        
        } while (sexo > 1 || sexo<0);
        do
        {
            printf("Ingrese la edad del paciente: ");
            scanf("%d",&edad);
        }while(edad < 0 || edad > 100);

        printf("Ingrese la fecha de nacimiento en el siguiente formato dia/mes/año:\n");
        do
        {
            printf("Ingrese el dia: ");
            scanf("%d", &n_dia);  
        } while (n_dia < 0 || n_dia > 31);
        do
        {
            printf("Ingrese el mes:");
            scanf("%d", &n_mes);
        } while (n_mes < 0 || n_mes > 12);
        do
        {
            printf("Ingrese el año: ");
            scanf("%d", &n_year);
        }while(n_year < 1923 || n_year > 2023);
        
        printf("Ingrese la C.I del paciente: ");
        scanf("%d", &ci);
        printf("Ingrese el costo de la consulta: ");
        scanf("%f", &costo);

        if(edad > 17)
        {
            p_mayores++;
        }
        else
        {
            p_menores++;
        }

        if(sexo == 1)
        {
            p_femeninos++;
        }
        else
        {
            p_masculinos++;
        }

        if((ci % 10) % 2 == 0 && sexo == 1)
        {
            costo -= (costo*15)/100;
        }else if(edad <= 60 && sexo == 0)
        {
            costo -= (costo*30)/100;
        }
        printf("El costo total de la consulta es %f\n", costo);
    }

    printf("La cantidad de pacientes femeninos es %d\n", p_femeninos);
    printf("La cantidad de pacientes masculinos es %d\n", p_masculinos);
    printf("La cantidad de pacientes mayores de edad es %d\n", p_mayores);
    printf("La cantidad de pacientes menores de edad es %d\n", p_menores);

    return 0;
}