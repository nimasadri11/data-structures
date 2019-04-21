#include <stdlib.h>
#include <stdio.h>

void print_matrix(int **a, int m, int n) {
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int dot_product(int* a, int* b, int n) {
    int res = 0;
    for(int i = 0; i < n; i++) {
        res += a[i] * b[i];
    }
    return res;
}


void free_matrix(int** a, int m) {
    for(int i = 0; i < m; i++) {
        free(a[i]);
    }
    free(a);
}

int** mult(int** a, int**b, int m, int n, int p) {
    int **res = malloc(m * sizeof(int *));
    int res_val;
    int i; 
    int j;
    int** new_b = malloc(p * sizeof(int *));
    for (i = 0; i < p; i++) {
        int* b_col = malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            b_col[j] = b[j][i];
        }
        new_b[i] = b_col;
    }

    for (i = 0; i < m; i++) {
        int *res_row = malloc(p * sizeof(int));
        for(j = 0; j < p; j++) {
            res_val = dot_product(a[i], new_b[j], n);

            res_row[j] = res_val;
        }
        res[i] = res_row;
    }

    free_matrix(new_b, p);
    return res;
    
}



int main() {
    return 0;
}