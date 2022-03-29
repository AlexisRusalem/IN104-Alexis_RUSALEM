#include <stdio.h>
#include <stdlib.h>
	
	
int main(){
	int area[9][9];
	int i, j;

	for(j=0;j<9;++j){
		for(i=0;i<9;++i){
			area[j][i]=(i+j*3+j/3)%9 +1;
			}
			}
	for(i=0;i<9;++i)
		{
		for(j=0;j<9;++j){
			printf("%d  ", area[i][j]);
			}
		printf("\n");
	}
	}

