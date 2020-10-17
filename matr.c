#include "masmatr.h"

int get_matr_count(int *matr, int size_m){
    int k = 0, i;
    for(i = 0; i < size_m; i++){
        if(matr[i] < 0){
            k++;
        }
    }
    return k;
}
