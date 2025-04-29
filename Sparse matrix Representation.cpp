# include<stdio.h>
// program for sparse matrix
int main(){
	printf("Program for sparse matrix !\n");
	printf("____________________________\n");
	int row,col,i,j;
	printf("\nEnter the number of rows: ");
	scanf("%d",&row);
	printf("\nEnter the number of cols: ");
	scanf("%d",&col);
	// taking input matrix.
	int m[row][col];
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("\nEnter the element for %d,%d: ",i,j);
			scanf("%d",&m[i][j]);
		}
	}
	// printing the matrix.
	printf("The entered matrix is: \n");
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf(" |%d| ",m[i][j]);
		}
		printf("\n");
	}
	// checking for number or zero and non zero elements.
	int nz=0, z=0;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(m[i][j]!= 0){
				nz++;
			}
			else{
				z++;
			}
		}
	}
	// checking if the matrix is sparse of not.
	if(nz>z){
		printf("The matrix entered is not sparse! ");
	}
	else{
		int s[nz][3],k=0;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(m[i][j]!=0){
				s[k][0]=i;
				s[k][1]=j;
				s[k][2]=m[i][j];
				k++;
			}
			}
		}
		printf("The sparse matrix representation is: \n");
		printf("________________________________________\n");
		for(i=0;i<nz;i++){
			for(j=0;j<3;j++){
				printf("| %d |",s[i][j]);
			}
			printf("\n");
		}
	}
}
