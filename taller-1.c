#include<stdio.h>

int es_primo(int num);
int num_ceros(int num);

int main()
{
    int i, n=0, num=0, pares=0, impares=0, ceros=0, primos=0;
    do
    {
        printf("Ingrese la cantidad de numeros a leer: ");
        scanf("%d",&n);
    }while(n<1);

    for(i = 0; i<n; i++)
    {
        printf("Ingrese el no.%d: ", i+1);
        scanf("%d", &num);
        if(num != 0)
        {
            if(num % 2 == 0)
            {
                pares++;
            }
            else
            {
                impares++;
            }
        }

        ceros+= num_ceros(num);

        if(es_primo(num))
        {
            primos++;
        }
    }

    printf("La cantidad de numeros pares es %d\n", pares);
    printf("La cantidad de numeros impares es %d\n", impares);
    printf("La cantidad de ceros en los numeros ingresados es %d\n", ceros);
    printf("La cantidad de numeros primos es %d\n", primos);

    return 0;

}

int es_primo(int num)
{
    int band = 1;
    int c = 2;

    if(num <= 1)
    {
        band = 0;
    }
    else
    {
        while(c <= (num - 1) && band)
        {
            if(num % c == 0)
            {
                band = 0; //No es primo
            }
            c++;
        }
    }

    return band; //1: es primo 0: no es primo
}

int num_ceros(int num)
{
    int digit = 0, acum =num, ceros = 0;
    do
    {
        digit=acum%10;
        acum=acum/10;
        if(digit==0)
        {
            ceros++;
        }
    }while(acum!=0);

    return ceros;
}
