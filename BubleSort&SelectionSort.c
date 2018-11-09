#include <stdio.h>

int printVect(int v[], int n)
{
int i;
for(i = 0; i < n; i++)
 printf("<%d> ", v[i]);

printf("\n");
}
int antesDepois(int v[], int n)
{
printf("\t\tAntes:\n");
printVect(v, 10);
printf("\t\tDurante:\n");
}
int bbsort(int v[], int n)
{
int i, j;
int aux;
for(i = n - 1; i > 0; i--)
{
 printVect(v, n);
 for(j = 0; j < i; j++)
 {
  if(v[j] > v[j + 1])
  {
   aux = v[j];
   v[j] = v[j + 1];
   v[j + 1] = aux;
  }
 }
}
printf("\nDepois:\n");
printVect(v, n);
}
int stsort(int v[], int n)
{
int aux, i, j, menor;
for(i = 0; i < n - 1; i++)
{
 printVect(v, n);
 menor = i;
 for(j = i + 1; j < n; j++)
 {
  if(v[j] < v[menor])
   menor = j;
  aux = v[i];
  v[i] = v[menor];
  v[menor] = aux;
 }
}
printf("\nDepois:\n");
printVect(v, n);
}
int bbSortAoContrario(int v[], int n)
{
int i, j;
int aux;
for(i = n - 1; i > 0; i--)
{
 for(j = 0; j < i; j++)
 {
  if(v[j] < v[j + 1])
  {
   aux = v[j];
   v[j] = v[j + 1];
   v[j + 1] = aux;
  }
 }
}
printVect(v, n);
}
int stsortDesc(int v[], int n)
{
int aux, i, j, menor;
for(i = 0; i < n - 1; i++)
{
 menor = i;
 for(j = i + 1; j < n; j++)
 {
  if(v[j] > v[menor])
   menor = j;
  aux = v[i];
  v[i] = v[menor];
  v[menor] = aux;
 }
}

printVect(v, n);
}

int bbSortMenoresPrimeiros(int v[], int n)
{
int i, j;
int aux;
for(i = 0; i < n; i++)
{
 printVect(v, n);
 for(j = n - 1; j >= i; j--)
 {
  if(v[j] > v[j + 1])
  {
   aux = v[j];
   v[j] = v[j + 1];
   v[j + 1] = aux;
  }
 }
}
printf("\nDepois:\n");
printVect(v, n);
}

int stsortMenoresPrimeiros(int v[], int n)
{
int aux, i, j, menor;
for(i = n - 1; i > 0; i--)
{
 printVect(v, n);
 menor = i;
 for(j = 0; j < i; j++)
 {
  if(v[j] > v[menor])
   menor = j;
  aux = v[i];
  v[i] = v[menor];
  v[menor] = aux;
 }
}
printf("\nDepois:\n");
printVect(v, n);
}

int main()
{
int arr[10]       = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int arr_2[10]     = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int arrDesc[10]   = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
int arrDesc_2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
int arrDesc_3[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
int arrDesc_4[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

#pragma region BBSort
printf("\t\t\t\t#####\tExecutando Bubble Sort #####\n\n");
antesDepois(arrDesc, 10);
bbsort(arrDesc, 10);
#pragma endregion

#pragma region SSsort
printf("\n\n\t\t\t        #####Executando Selection Sort #####\n\n");
antesDepois(arrDesc_2, 10);
stsort(arrDesc_2, 10);
#pragma endregion

#pragma region BONUS - DECRESCENTE
/*DESCOMENTAR ABAIXO PARA FUNCIONAR */
/*
#pragma region BBSort Desc
printf("\n\n\t\t\t        #####Executando Bubble Sort Decrescent #####\n\n");
antesDepois(arr, 10);
bbSortAoContrario(arr, 10);
#pragma endregion

#pragma region SSSort Desc
printf("\n\n\t\t\t        #####Executando Selection Sort Decrescent #####\n\n");
antesDepois(arr_2, 10);
stsortDesc(arr_2, 10);
#pragma endregion
#pragma endregion
*/
#pragma region BBSort MenoresFirst
printf("\n\n\t\t\t        #####Executando Selection Bubble Sort Menores Primeiros #####\n\n");
antesDepois(arrDesc_3, 10);
bbSortMenoresPrimeiros(arrDesc_3, 10);
#pragma endregion

#pragma region BBSort MenoresFirst
printf("\n\n\t\t\t        #####Executando Selection Selection Sort Menores Primeiros #####\n\n");
antesDepois(arrDesc_4, 10);
stsortMenoresPrimeiros(arrDesc_4, 10);
#pragma endregion
}
