#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ERRO pow(10,-16) 
#define TAM_MAX 50

void print_vet(double vet[TAM_MAX])
{
    for(int i = 0; i < TAM_MAX; i++)
    {
        printf("Elemento %d = %.16lf\n",i, vet[i]);
    }
}

double f1(double x)
{
    return x - cos(x); 
}

double f2(double x)
{
    return (pow(x, 3) - 9*pow(x,2) + 27*x - 27);
}

double f3(double x)
{
    return (exp(x) - cos(x));
}

//Função recebe como parâmetro o intervalo de resposta
void bisseccaof1(double a, double b, double it[TAM_MAX])
{
    double x0 = (a+b)/2.0;
    it[0] = x0;
    double x1 = a;
    double x2 = b;

    //PARA A PRIMEIRA FUNÇÃO
    for(int i = 1; i < TAM_MAX; i++)
    {
        if((i != 1 && fabs(it[i-1] - it[i-2]) < ERRO) || f1(it[i-1]) == 0)
            return;
        if(f1(x0)*f1(x1) < 0)
        {
            x2 = x0;
            x0 = (x0 + x1)/2.0;
            it[i] = x0;
        }
        else
        {
            x1 = x0;
            x0 = (x0 + x2)/2.0;
            it[i] = x0;
        }
    }
}

void bisseccaof2(double a, double b, double it[TAM_MAX])
{
    double x0 = (a+b)/2.0;
    it[0] = x0;
    double x1 = a;
    double x2 = b;

    //PARA A SEGUNDA FUNÇÃO
    for(int i = 1; i < TAM_MAX; i++)
    {
        if((i != 1 && fabs(it[i-1] - it[i-2]) < ERRO) || f2(it[i-1]) == 0)
            return;
        if(f2(x0)*f2(x1) < 0)
        {
            x2 = x0;
            x0 = (x0 + x1)/2.0;
            it[i] = x0;
        }
        else
        {
            x1 = x0;
            x0 = (x0 + x2)/2.0;
            it[i] = x0;
        }
    }
}

void bisseccaof3(double a, double b, double it[TAM_MAX])
{
    double x0 = (a+b)/2.0;
    it[0] = x0;
    double x1 = a;
    double x2 = b;

    //PARA A TERCEIRA FUNÇÃO
    for(int i = 1; i < TAM_MAX; i++)
    {
        if((i != 1 && fabs(it[i-1] - it[i-2]) < ERRO) || f3(it[i-1]) == 0)
        {
            printf("\nRETORNOU EM i = %d\n", i);
            return;
        }
        if(f3(x0)*f3(x1) < 0)
        {
            x2 = x0;
            x0 = (x0 + x1)/2.0;
            it[i] = x0;
        }
        else
        {
            x1 = x0;
            x0 = (x0 + x2)/2.0;
            it[i] = x0;
        }
    }
}

int main()
{
    double it1[TAM_MAX];
    double it2[TAM_MAX];
    double it3[TAM_MAX];

    int a = 0;
    int b = 2;
    bisseccaof1(a, b, it1);
    b = 4;
    bisseccaof2(a, b, it2);
    a = -5;
    bisseccaof3(a, b, it3);

    print_vet(it1);
    print_vet(it2);
    print_vet(it3);

    return 0;
}