#include <stdlib.h>
#include <stdio.h>
#define MAX 10
#include <windows.h>

FILE *arq;

void populaArquivo(FILE *arq)
{
    arq = fopen("500.txt","w");
    for(int i=0; i<MAX; i++)
    {
        fprintf(arq,"%d\n",rand()%500);
    }
    fclose(arq);
}

void populaVetorArquivo(int *v,int K,FILE *arq)
{
    arq = fopen("500.txt","r");
    for(int i=0; i<K; i++)
    {
        fscanf(arq,"%d",&v[i]);
    }
    fclose(arq);
}

void populaVetor(int *v,int K)
{
    for(int i=0; i<K; i++)
    {
        v[i] = rand()%150000;
    }
}


void BubbleSort(int *v,int K)
{
    int aux = 0;
    for(int i=1; i<K; i++)
    {
        for(int j=0; j<K-i; j++)
        {
            if(v[j]>v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }

        }
    }
}

void InsertionSort(int *v,int K)
{
    int i, j, atual;
    for(i=1; i<K; i++)
    {
        atual = v[i];
        for(j=i-1; (j >= 0) && (atual < v[j]); j--)
        {
            v[j+1] = v[j];
        }
        v[j+1] = atual;
    }
}

int selmin(int *v,int i, int K)
{
    int j,n=i;
    for(j=i+1; j<K; j++)
    {
        if(v[n]>v[j])
        {
            n=j;
        }
    }
    return n;
}

void SelectionSort(int *v, int K)
{
    int i,n,x;
    for(i=0; i<K-1; i++)
    {
        n = selmin(v,i,K);
        x = v[i];
        v[i] = v[n];
        v[n] = x;
    }
}

void ShowArray(int *v,int K)
{
    system("cls");
    printf("Vetor:\n");
    for(int i=0; i<K; i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
    system("pause");
    system("cls");
}

void ShowResult(){
system("cls");
printf("Comando realizado com sucesso!\n");
system("pause");
}

int verifyOrd(int *v, int K){
for(int i =0;i<K;i++){
    if(v[i]>v[i+1]){
        return -1;
    }
}
return 1;
}

int buscaBinaria(int *v, int K)
{
    int result = verifyOrd(v,K);
    if(result)
    {
        int x;
        printf("Digite o numero a ser pesquisado:\n");
        scanf("%d",&x);
        int e = -1, d = K; // atenção!
        while (e < d-1)
        {
            int m = (e + d)/2;
            if (v[m] < x)
                e = m;
            else
                d = m;
        }
        return d;


    }
    else
    {
        printf("O vetor nao esta ordenado!\n");
        system("pause");
        return -1;
    }


}

int menu()
{
    printf("1 - Preencher aleatoriamente o primeiro vetor \n");
    printf("2 - Preencher aleatoriamente o segundo vetor \n");
    printf("3 - Preencher aleatoriamente o terceiro vetor \n");
    printf("4 - Imprimir Vetor 1 \n");
    printf("5 - Imprimir Vetor 2 \n");
    printf("6 - Imprimir Vetor 3\n");
    printf("7 - Busca sequencial(vetor1)\n");
    printf("8 - Ordenacao por trocas - bubbleSort - (vetor1) \n");
    printf("9 - Ordenacao por selecao(vetor2) \n");
    printf("10 - Ordenacao por Insercao(vetor3) \n");
    printf("11 - Busca Binaria(vetor3) \n");
    printf("12 - Sair\n\n");

    int k = 0;
    printf("Option: \n");
    scanf("%d",&k);
    return k;
}

int buscaLinear(int *v, int K)
{
    system("cls");
    int aux;
    printf("Digite o numero a ser pesquisado:\n");
    scanf("%d",&aux);
    for(int i=0; i<K; i++)
    {
        if(v[i]==aux)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
//populaArquivo(arq);
    int v1[MAX] = {0},v2[MAX] = {0},v3[MAX]= {0};
    //populaVetor(v1,MAX,arq);

    int op = 0;
    int bl = 0;
    int bb = 0;

    do
    {
        system("cls");
        op = menu();
        switch(op)
        {
        case 1:
            populaVetor(v1,MAX);
            ShowResult();
            break;

        case 2:
            populaVetor(v2,MAX);
            ShowResult();
            break;

        case 3:
            populaVetor(v3,MAX);
            ShowResult();
            break;

        case 4:
            ShowArray(v1,MAX);
            break;

        case 5:
            ShowArray(v2,MAX);
            break;

        case 6:
            ShowArray(v3,MAX);
            break;

        case 7:
            bl = buscaLinear(v1,MAX);
            if(bl!= -1)
            {
                printf("Numero encontrado!\nPosicao: [%d]\n",bl);
                system("pause");
            }
            else
            {
                printf("Numero nao encontrado!\n");
                system("pause");

            }
            break;

        case 8:
            BubbleSort(v1,MAX);
            ShowResult();
            break;

        case 9:
            SelectionSort(v2,MAX);
            ShowResult();
            break;

        case 10:
            InsertionSort(v3,MAX);
            ShowResult();
            break;

        case 11:
            bb = buscaBinaria(v3,MAX);
            if(bb!= -1)
            {
                printf("Numero encontrado!\nPosicao: [%d]\n",bb);
                system("pause");
            }
            else
            {
                printf("Numero nao encontrado!\n");
                system("pause");

            }
            break;


        }
    }
    while(op!=12);

    getchar();
    return 0;
}
