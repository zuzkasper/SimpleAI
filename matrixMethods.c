#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

double **transpose(double **array, int cols, int rows){
	int i=0;
	int j=0;
	double **transposed=(double**)malloc(sizeof(double*)*cols);
	for (i=0; i<cols;++i){
		transposed[i]=(double*)malloc(sizeof(double)*rows);
		if(transposed[i]==NULL){
			printf("error\n");
			return NULL;
		}
	}
	j=0;
	for(i=0; i<cols; ++i){
		for(j=0; j<rows; ++j){
			transposed[i][j]=array[j][i];
		}
	}
	return transposed;
}
double **multiply(double **array1, double**array2, int rows1, int cols1, int rows2, int cols2){
	double**newArray=(double**)malloc(sizeof(double*)*rows1);
	int i=0;
	for (i=0; i<rows1;++i){
		newArray[i]=(double*)malloc(sizeof(double)*cols2);
		if(newArray[i]==NULL){
			printf("error\n");
			return NULL;
		}
	}
	i=0;
	int j=0;
	int common=0;
	double sum=0;
	double temp=0;
	for(i=0; i<rows1; ++i){
		for(j=0; j<cols2; ++j){
			for(common=0; common<cols1; ++common){
				temp=array1[i][common]*array2[common][j];
				sum+=temp;
			}
			newArray[i][j]=sum;
			sum=0;
		}
	}
	return newArray;
}/*
double **invert(double **array, int x){
	if (array==NULL){
		printf("error\n");
		return NULL;
	}
	int i=0;
	int j=0;
	double f=0;
	double **augMatrix=(double**)malloc(sizeof(double*)*x);
	for(i=0; i<x; ++i){
		augMatrix[i]=(double*)malloc(sizeof(double)*2*x);
		if(augMatrix[i]==NULL){
			printf("error\n");
			return NULL;	
		}
	}
	for(i=0; i<x; ++i){
		for(j=0; j<x; ++j){
			augMatrix[i][j]=array[i][j];
		}
		for(j=x; j<2*x; ++j){
			if(i==j-x){
				augMatrix[i][j]=1.00000;
			}
			else{
				augMatrix[i][j]=0.000000;
			}
		}
		j=0;
	}
	i=0;
	j=0;
	int k=0;
	for(j=0; j<x; ++j){
		for(i=0; i<x; ++i){
			if (i!=j&&i>j){
				if(augMatrix[i][j]!=0){
					f=augMatrix[i][j];
					augMatrix=subtractRow(augMatrix, i, j, f, x, 2*x);
				}
			}
			else if(i==j){
				if(augMatrix[i][j]!=1){
					if(augMatrix[i][j]!=0){
						augMatrix=divideRow(augMatrix, i, augMatrix[i][j], x, 2*x);
					}
					if(augMatrix[i][j]==0){
						k=i;
						while(augMatrix[k][j]==0&&k<x){
							k++;

						}
						if(k==x){
							k=i;
							while(augMatrix[k][j]==0&&k>=0){
								k--;
							}
						}
						if(k<0){
							printf("error\n");
							break;
						}
						f=1/augMatrix[k][j];
						augMatrix=subtractRow(augMatrix, i, k, f,x, 2*x);
					}
				}
			}	
		}
	}
	for(j=x-1; j>=0; --j){
		for(i=x-1; i>=0; --i){
			if (i!=j&&i<j){
				if(augMatrix[i][j]!=0){
					f=augMatrix[i][j];
					augMatrix=subtractRow(augMatrix, i, j, f, x, 2*x);
				}
			}	
		}
	}
	double **newArray=(double**)malloc(sizeof(double*)*x);
	for(j=0; j<x; ++j){
		newArray[j]=(double*)malloc(sizeof(double)*x);
		if(newArray[j]==NULL){
			printf("error\n");
			return NULL;	
		}
	}
	for(i=0; i<x; ++i){
		for(j=0; j<x; ++j){
			newArray[i][j]=augMatrix[i][j+x];
		}
	}
	free(augMatrix);
	return newArray;	
}*/
