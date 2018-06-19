#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

double **divideRow(double **array, int a, double c, int x, int y){
	int i=0;
	int j=0;
	double **tempArray=(double**)malloc(sizeof(double*)*x);
	for(i=0; i<x; ++i){
		tempArray[i]=(double*)malloc(sizeof(double)*y);
		if(tempArray[i]==NULL){
			printf("error\n");
		}
	}
	for (i=0; i<x; ++i){
		for (j=0; j<y; ++j){
			if(i==a){
				tempArray[a][j]=array[a][j]/c;
			}
			else{
				tempArray[i][j]=array[i][j];
			}
		}
	}
	return tempArray;
}	
double **subtractRow(double **array, int a, int b, double f, int x, int y){
	int i=0;
	int j=0;
	double **tempArray=(double**)malloc(sizeof(double*)*x);
	for(i=0; i<x; ++i){
		tempArray[i]=(double*)malloc(sizeof(double)*y);
		if(tempArray[i]==NULL){
			printf("error\n");
		}
	}
	for (i=0; i<x; ++i){
		for (j=0; j<y; ++j){
			if(i==a){
				tempArray[a][j]=array[a][j]-(f*(array[b][j]));
			}
			else{
				tempArray[i][j]=array[i][j];
			}
		}
	}
	return tempArray;	
}

