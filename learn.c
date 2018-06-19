#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include "learn.h"
/*char*createBuffer(char*argv){
	int fs=open(argv, O_RDONLY);
	if(fs==-1){
		printf("error\n");	
		return NULL;
	}
	int i=0;
	int numBytes=9;
	int numRead=9;
	int totalRead=0;
	char*tempBuffer=(char*)malloc(sizeof(char)*numBytes+1);
	if(tempBuffer==NULL){
		printf("error\n");
		return NULL;
	}
	for(i=0; i<numBytes+1; ++i){
		tempBuffer[i]='\0';
	}
	char*buffer=(char*)malloc(sizeof(char)*numBytes+1);
	if(buffer==NULL){
		printf("error\n");
		return NULL;
	}
	for(i=0; i<numBytes+1; ++i){
		buffer[i]='\0';
	}
	while(numRead==numBytes){
		numRead=read(fs, tempBuffer, numBytes);
		if(numRead==0&&totalRead==0){
			printf("error\n");
			return NULL;
		}
		else if(numRead==0){
			break;
		}
		totalRead+=numRead;
		tempBuffer[numBytes]='\0';
		buffer=(char*)realloc(buffer, sizeof(char)*totalRead);
		for(i=0; i<numRead; ++i){
			buffer[totalRead-numRead+i]=tempBuffer[i];
		}
	}
	free(tempBuffer);
	return buffer;
}

double **createArray(char*buffer, int numCols, int numRows){
	int i=0;
	char*str=(char*)malloc(sizeof(char)*100);
	if(str==NULL){
		printf("error\n");
		return NULL;
	}
	for(i=0; i<100; ++i){
		str[i]='\0';
	}
	double temp=0;
	int j=0;
	int index=0;
	i=0;
	int m=0;;
	double **arr=(double**)malloc(sizeof(double*)*numRows);
	for(j=0; j<numRows; ++j){
		arr[j]=(double*)malloc(sizeof(double)*(numCols));
		if(arr[j]==NULL){
			printf("error\n");
			return NULL;
		}
	}
	j=0;
	while(j<numRows){
		if(buffer[i]==','||buffer[i]=='\n'){
			temp=atof(str);
			while(index>=0){
				str[index]='\0';
				--index;
			}
			arr[j][m]=temp;
			index=0;
			if(buffer[i]=='\n'){
				m=-1;
				++j;
			}
			++i;
			++m;
		}else{
			str[index]=buffer[i];
			++index;
			++i;
		}
	}
	free(str);
	return arr;
}*/
double**createX(double**array, int k, int numRows){
	int i=0;
	int j=0;
	double**x=(double**)malloc(sizeof(double*)*numRows);
	for(i=0; i<numRows; ++i){
		x[i]=(double*)malloc(sizeof(double)*(k+1));
		if(x[i]==NULL){
			printf("error\n");
			return NULL;
		}
	}
	for(i=0; i<numRows; ++i){
		x[i][0]=1;
		for(j=0; j<k; ++j){
			x[i][j+1]=array[i][j];
		}
	}
	return x;
}
double**createY(double**array, int k, int numRows){
	int i=0;
	double**y=(double**)malloc(sizeof(double*)*numRows);
	for(i=0; i<numRows; ++i){
		y[i]=(double*)malloc(sizeof(double));
		if(y[i]==NULL){
			printf("error\n");
			return NULL;
		}
	}
	for(i=0; i<numRows; ++i){	
		y[i][0]=array[i][k];
	}
	return y;
}
/*	
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
}*/
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
}
/*
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
}*/

int main(int argc, char*argv[]){
	char*trainBuffer=createBuffer(argv[1]);
	if(trainBuffer==NULL){
		return 0;
	}
	char*testBuffer=createBuffer(argv[2]);
	if(testBuffer==NULL){
		return 0;
	}
	int i=0;
	int j=0;
	char *num=(char*)malloc(sizeof(char)*100);
	if(num==NULL){
		printf("error\n");
		return 0;
	}
	for(i=0; i<100; ++i){
		num[i]='\0';
	}
	i=0;
	while(trainBuffer[j]!='\n'){		
		num[i]=trainBuffer[j];
		++j;
		++i;
	}
	num[i]='\0';
	++j;
	++i;
	int k=atoi(num);
	while(i>=0){
		num[i]='\0';
		--i;
	}
	++i;
	while(trainBuffer[j]!='\n'){	
		num[i]=trainBuffer[j];
		++j;
		++i;
	}
	trainBuffer+=j+1;
	int n=atoi(num);
	i=0;
	while(num[i]!='\0'){
		num[i]='\0';
		++i;
	}
	j=0;
	i=0;
	while(testBuffer[j]!='\n'){	
		num[j]=testBuffer[j];
		++j;
	}
	int target=atoi(num);
	testBuffer+=j+1;
	free(num);
	double **trainArray=createArray(trainBuffer, k+1, n);
	double **testArray=createArray(testBuffer, k, target);
	double **x=createX(trainArray, k, n);
	double **testx=createX(testArray, k, target);
	double **y=createY(trainArray, k, n);
	free(trainArray);
	free(testArray);
	double **transposed=transpose(x, k+1, n);	
	double**weight=multiply(multiply(invert(multiply(transposed, x, k+1, n, n, k+1), k+1),transposed, k+1, k+1, k+1, n), y, k+1, n, n, 1);
	free(transposed);
	double **price=multiply(testx,weight, target, k+1, k+1, 1);
	free(weight);
	for(i=0; i<target; ++i){
		printf("%0.0f\n", price[i][0]);
	}
	free(price);
	return 0;
}



