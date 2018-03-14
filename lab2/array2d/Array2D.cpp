//
// Created by jasimich on 09.03.18.
//

#include "Array2D.h"

int **Array2D(int n_rows, int n_columns){
    if(n_columns>0 && n_rows>0){
        int liczba=1;
        int **tab =new int*[n_rows];
        for(int i=0;i<n_rows;i++){
            tab[i] = new int[n_columns];
        }
        for(int i=0;i<n_rows;i++){
            for(int j=0;j<n_columns;j++){
                tab[i][j]=liczba;
                liczba++;
            }
        }
        return tab;
    }
    else{
        return nullptr;
    }



}
void DeleteArray2D(int **array, int n_rows, int n_columns){
    for(int i=0;i<n_rows;i++){
        delete array[i];
    }
    delete array;
}