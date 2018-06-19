#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
char*createBuffer(char*argv){
	int fs=open(argv, O_RDONLY);
	if(fs==-1){
		printf("error\n");
		return NULL;
	}
	int i=0;
	int numBytes=9;
	int numRead=9;
	int totalRead=0;
	char*tempBuffer=(char*)malloc(sizeof(char)*(numBytes+1));
	if(tempBuffer==NULL){
		printf("error\n");
		return NULL;
	}
	for(i=0; i<numBytes+1; ++i){
		tempBuffer[i]='\0';
	}
	char*buffer=(char*)malloc(sizeof(char*)*(numBytes+1));
	if(buffer==NULL){
		printf("error\n");
		return NULL;
	}

	for(i=0; i<(numBytes+1); ++i){
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
}
