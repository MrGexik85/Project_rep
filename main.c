#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#include "load.h"


#define N 42
#define M 6
#define K 9

#include "masmatr.h"

int main()
{
    int k[N], i, j, l[M*N], count_m;
    setlocale(LC_CTYPE, "rus");
    srand(time(NULL));

    for(i = 0; i < N; i++){
        srand(rand());
        k[i] = rand()%100-50;
    }
    printf("������:\n");
    for(i = 0; i < N; i++){
        printf("%d  ", k[i]);
    }
    for(i = 0; i < M; i++){
        for(j = 0; j < K; j++){
            srand(rand());
            l[K*i+j] = rand()%100-50;
        }
    }
    printf("\n\n�������:\n");
    for(i = 0; i < M; i++){
        for(j = 0; j < K; j++){
            printf("%d\t", l[K*i+j]);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("��������, ��� ����� ���������� ������������� ���������:\n1 - � �������\n2 - � �������\n3 - �����\n");
    j = 1;
    while(j){
        scanf("%d",&i);
        if(i==1){
            count_m=LoadRun("mas.dll", i, k, N);
            printf("���������� ������������� ��������� � �������: %d\n", count_m);
        }
        if(i==2){
            count_m=LoadRun("matr.dll", i, l, M*K);
            printf("���������� ������������� ��������� � �������: %d\n", count_m);
        }
        if(i==3)
            j=0;
}
    system("pause");
    return 0;
}
