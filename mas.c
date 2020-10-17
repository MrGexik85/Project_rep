#include "masmatr.h"

int get_mas_count(int *mas, int size_m){
    int k = 0, i;
    for(i = 0; i < size_m; i++){
        if(mas[i] < 0){
            k++;
        }
    }
    return k;
}
