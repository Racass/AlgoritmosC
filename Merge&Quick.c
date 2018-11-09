#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
	a) Testar a função intercala que recebe 2 vetores com 10 posições (A e B) ordenados e coloca no vetor C os elementos intercalados entendidos
	b) Testar a função intercala que recebe 1 vetor com 2 grupos ordenados e inicio, meio (onde começa o 2ºgp) e fim, e ordena os dois grupos tornando o com um único grupo ordenado
	c) testar a função que implementa o mergesort (Tente mostrar os elementos ordenados)
	d) Testar a função partição que divide o vetor passado em 2 grupos ( um menor que o pivô nas 1ºs posições e outro maior que o pivô com valores maiores que o pivô nas últimas posições retornando a posição que o pivô ficou
	e) testar a função que implementa o quicksort ( tente mostraros eleemntos sendo ordenados)
*/
void printVect(int vet[], int n)
{
	int i = 0;
	for(i = 0; i < n; i++)
		printf("<%d> ", vet[i]);
	printf("\n");
}
void **CarregaVetor(int vet[], int size)
{
	int i = 0;
	for(i = 0; i < size; i++)
		vet[i] = rand() % 20;
}
void **intercala(int a[], int b[], int c[])
{
	int i = 0, j = 0, k = 0;
	while( i < 10 && j < 10)
	{
		if(a[i] <= b[j])
			c[k++] = a[i++];	
		else
			c[k++] = b[j++];
		while (i < 10) c[k++] = a[i++];
		while (j < 10) c[k++] = b[j++];
	}
}
void **mergeIntercala(int vetorGrupal[], int ini, int meio, int fim)
{
	int i = ini, j = meio + 1, k = 0, *aux;
	aux = malloc(sizeof(int) * (fim - ini + 1));
	if(aux == NULL) abort();
	while(i <= meio && j <= fim)
	{
		if (vetorGrupal[i] <= vetorGrupal[j]) aux[k++] = vetorGrupal[i++];
		else aux[k++] = vetorGrupal[j++];
	}
	while ( i <= meio) aux[k++] = vetorGrupal[i++];
	while ( j <= fim ) aux[k++] = vetorGrupal[j++];		
	for(i = ini, j = 0; i<= fim; i++, j++)
		vetorGrupal[i] = aux[j];
	free(aux);
}
void **mergeSort(int vetor[], int ini, int fim)
{
	if(ini < fim)
	{
		int meio = (ini + fim) / 2;
		mergeSort(vetor, ini, meio);
		mergeSort(vetor, meio + 1, fim);
		mergeIntercala(vetor, ini, meio, fim);
	}
}
int particao(int vetor[], int ini, int fim)
{
	int pivo = vetor[ini], esq = ini + 1, dir = fim, aux;
	while (esq <= dir)
	{
		while(esq <= dir && vetor[esq] <= pivo) esq++;
		while(vetor[dir] > pivo) dir--;
		if(esq < dir)
		{
			aux = vetor[esq];
			vetor[esq] = vetor[dir];
			vetor[dir] = aux;
			esq++;
			dir--;
		}
	}
	vetor[ini] = vetor[dir];
	vetor[dir] = pivo;
	return dir;
}
void **quickSort(int vetor[], int ini, int fim)
{
	if(ini < fim)
	{
		int pivo = particao(vetor, ini, fim);
		quickSort(vetor, ini, pivo - 1);
		quickSort(vetor, pivo + 1, fim);
	}
}
void EX05A()
{
	int ASize = 10;
	int vet_1[ASize];
	int vet_2[ASize];
	int vet_3[ASize * 2];
	
	CarregaVetor(vet_1, ASize);
	CarregaVetor(vet_2, ASize);
	
	printf("Vetor 1 : ");
	printVect(vet_1, ASize);
	printf("Vetor 2 : ");
	printVect(vet_2, ASize);
	
	intercala(vet_1, vet_2, vet_3);
	printf("Vetor final: ");
	printVect(vet_3, 20);
	
	printf("\n\t\tFIM A\t\t\n");
}
void EX05B()
{
	int vetorGrupal[16] = {0, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 8};
	mergeIntercala(vetorGrupal, 0, 7, 16);
	printf("Vetor grupal: ");
	printVect(vetorGrupal, 16);
	printf("\n\t\tFIM B\t\t\n");
}
void EX05C()
{
	int vetorMerge[15];
	CarregaVetor(vetorMerge, 15);
	printf("Antes: ");
	printVect(vetorMerge, 15);
	mergeSort(vetorMerge, 0, 15);
	printf("Depois: ");
	printVect(vetorMerge, 15);
	printf("\n\t\tFIM C\t\t\n");
}
void EX05D()
{
	int vetorMerge[16] = {0, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 8};
	printVect(vetorMerge, 16);
	int posPivo = particao(vetorMerge, 0, 16);
	printVect(vetorMerge, 16);
	int i = 0;
	printf("Posição do pivo: <%d>. Pivo: <%d>.\n Menores que o pivo: \n", posPivo, vetorMerge[posPivo]);
	for(i = 0; i <= posPivo; i++)
		printf("<%d> ", vetorMerge[i]);
	printf("\nMaiores que o pivo: ");
	for(i = posPivo + 1; i < 16; i++)
		printf("<%d> ", vetorMerge[i]);
	printf("\n\t\tFIM D\t\t\n");
}
void EX05E()
{
	int vetorMerge[15];
	CarregaVetor(vetorMerge, 15);
	printf("Antes: ");
	printVect(vetorMerge, 15);
	quickSort(vetorMerge, 0, 15);
	printf("Depois: ");
	printVect(vetorMerge, 15);
	printf("\n\t\tFIM E\t\t\n");
}
int main()
{
	EX05A();
	printf("\n");
	EX05B();
	printf("\n");
	EX05C();
	printf("\n");
	EX05D();
	printf("\n");
	EX05E();
	printf("\n");
}
