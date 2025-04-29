# include<stdio.h>
int main(){
	int row,col,k=0;
	printf("Enter the no of Rows and Columns: \n");
	scanf("%d%d",&row,&col);
	int a[row][col];
	
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("Enter the element at %d , %d",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("The entered array is: \n");
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%d  ",a[i][j]);
		}
		printf("\n");
		}
	
	int z=0,nz=0;
		
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(a[i][j]==0){
				z++;
			}
			else{
				nz++;
			}
		}
		}
		int b[nz][3];
	if(nz>z){
		printf("Not a sparse matrix");
		return 0;
	}
	else{
		for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(a[i][j]!=0){
				b[k][0]=i;
				b[k][1]=j;
				b[k][2]=a[i][j];
				k++;
			}
		}
		}
	}
	printf("\n");
	for(int i=0;i<nz;i++){
		for(int j=0;j<3;j++){
			printf("%d  ",b[i][j]);
		}
		printf("\n");
	}
}
