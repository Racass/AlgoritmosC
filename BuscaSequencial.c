
#include <stdio.h>
/*
########################################## EXERCICIO 01 ##############################################
a) TESTAR BUSCA SEQUENCIAL QUE RETORNA 0 OU 1
b) TESTAR BUSCA BINÁRIA QUE RETORNA 0 OU 1
c) ALTERAR A BUSCA SEQUENCIAL PARA RETORNAR -1 SE NÃO ECNONTRAR OU INDICE ONDE ENCONTROU O ELEMENTO
d) ALTERAR A BUSCA BINÁRIA PARA RETORNAR -1 SE NÃO ENCONTRAR OU INDICE ONDE ENCONTROU O ELEMENTO
######################################################################################################
*/

int seqNor(int arr[], int x, int szeArr)
{
    for(int i = 0; i < szeArr; i++)
    {
        if(arr[i] == x)
            return i;
    }
    return -1;
}

int seqOtimi(int arr[], int find, int szeArr)
{
    int i = 0;
    int temp = arr[szeArr - 1];
    arr[szeArr - 1] = find;

    while(find != arr[i])
        i++;
       
    arr[szeArr - 1] = temp;

    return find == arr[i];
}

int bin(int arr[], int find, int szeArr)
{
    int cnt = 0;
    if(arr[szeArr / 2] >= find )
    {
        cnt = szeArr;
        while(cnt >= 0)
        {
            if(arr[cnt] == find)
                return cnt;
            cnt--;
        }
        return -1;
    }
    else
    {
        cnt = (szeArr / 2);
        while(cnt <= szeArr)
        {
            if(arr[cnt] == find)
                return cnt;
            cnt++;
        }
        return -1;
    }
}

int main()
{
    int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
   
    int buscar = -50;

    int posBin = bin(arr, buscar, 10);
    int posSeq = seqNor(arr, buscar, 10);
    printf("Resultado Binário é: %d\nResultado sequencial é: %d\n", posBin, posSeq);
}
