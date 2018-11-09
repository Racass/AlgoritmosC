/*
    EX02
    a) Testar rotina fatorial recursiva
    b) Testar a rotina fibonacci recursiva
    c) testar a rotina hanoi recursiva
    d) testar a rotina busca binária recursiva
    e) implementar uma busca sequencial recursiva
        Para isso lembre-se que a rotina deve verificar se o 1º elemento é o procurado, se não deve recursivamente verificar
        se o elemento está no resto dos elementos do vetor
*/
#include <stdio.h>

int fat(unsigned long int n)
{
    if (n == 0)
        return 1;
    return n * fat(n-1);
}

int fib(int n)
{
    if(n < 3)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int hanoi(int n, char a, char b, char c)
{
    if(n > 0)
    {
        hanoi(n - 1, a, c, b);
        printf("Disco %d de %c para %c\n", n, a, c);
        hanoi(n - 1, b, a, c);
    }
}

int bb(int v[], int i, int f, int x)
{
    if(i <= f)
    {
        int m = (i + f) / 2;
        if(x < v[m]) return bb(v, i, m - 1, x);
        else if(x > v[m]) return bb(v, m + 1, f, x);
        else return 1;
    }
    else return 0;
}

int seq(int arr[], int tamanho, int inicio, int procurar)
{
    if(tamanho < inicio)
        return 0;

    if(arr[inicio] == procurar)
        return 1;

    seq(arr, tamanho + 1, inicio + 1, procurar);
}

int main()
{
    unsigned long int foo;
    printf("Realizando fatorado\n");
    foo = fat(25);
    printf("<%d>\n", foo);

    printf("Realizando fibonacci\n");
    foo = fib(25);
    printf("<%d>\n", foo);

    printf("realizando hanoi\n");
    foo = hanoi(3, 'A', 'B', 'C');
    printf("hanoi executado\n");

    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    printf("realizando bb\n");
    foo = bb(arr, 0, 9, 3);
    printf("<%d>\n", foo);

    int ver[10] = {0,1,2,3,4,5,6,7,8,9};
    printf("realizando sequencial\n");
    foo = seq(ver, 10, 0, 3);
    printf("<%d>\n", foo);

}
