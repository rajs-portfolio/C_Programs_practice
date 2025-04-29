#include <stdio.h>

#define mrow 20
#define mcolumn 20
#define srow 50

int main() {
    int mat[mrow][mcolumn], sparse[srow][3];
    int nzero = 0, mr, mc, i, j, s;

    printf("Enter number of rows: ");
    scanf("%d", &mr);

    printf("Enter number of columns: ");
    scanf("%d", &mc);

    // Input the matrix elements
    for(i = 0; i < mr; i++) {
        for(j = 0; j < mc; j++) {
            printf("Enter element for row %d, column %d: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);

            if(mat[i][j] != 0) 
                nzero++;
        }
    }

    printf("Entered matrix is:\n");
    for(i = 0; i < mr; i++) {
        for(j = 0; j < mc; j++) {
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }

    // First row of sparse matrix with meta-data
    sparse[0][0] = mr;
    sparse[0][1] = mc;
    sparse[0][2] = nzero;

    // Filling the sparse matrix with non-zero elements
    s = 1;
    for(i = 0; i < mr; i++) {
        for(j = 0; j < mc; j++) {
            if(mat[i][j] != 0) {
                sparse[s][0] = i + 1;
                sparse[s][1] = j + 1;
                sparse[s][2] = mat[i][j];
                s++;
            }
        }
    }

    // Printing the sparse matrix
    printf("Sparse matrix is:\n");
    for(i = 0; i <= nzero; i++) {
        for(j = 0; j < 3; j++) {
            printf("%5d", sparse[i][j]);
        }
        printf("\n");
    }

    return 0;
}