#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct dadosArq{
	int ano;
	char varid[20];
	char pais[20];
	double valor;	
};

struct dadosArq dados[14];

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int tamanho = 14;
	int countLinhas = 0;
	int contador = 0, it = 0, linha =0;
	
	char auxArquivo[1024];
	char buf[1024];
	
	FILE *arq = fopen("gastos_ciencia_desordenado.csv","r");
	
	if(arq == NULL)
		printf("Erro ao abrir arquivo");
		//exit (0);
	
	while(fgets(buf,1024,arq)){
		contador = 0;
		countLinhas++;

		if(countLinhas == 1) continue;
		
		char *campo = strtok(buf, ",");
		while(campo){
			if(contador == 0)	{
				strcpy(auxArquivo,campo);
				dados[linha].ano = atoi(auxArquivo);
			}
			
			if(contador == 1){
				strcpy(auxArquivo,campo);
				strcpy(dados[linha].varid,auxArquivo);
			}
			
			if(contador == 2){
				strcpy(auxArquivo,campo);
				strcpy(dados[linha].pais, auxArquivo);
			}
			
			if(contador == 3){
				strcpy(auxArquivo,campo);
				dados[linha].valor = atof(auxArquivo);
			}
			
			campo = strtok(NULL,",");
			contador++;
		}
			linha++;
	}
	
	imprimirOriginal(dados,tamanho);
	fclose(arq);
	return 0; 

}

void imprimirOriginal(struct dadosArq dados[], int n){
	int i;
	printf(" ano	    varid	  pais	     valor\n");
	for(i=0;i<n;i++){
		printf("%-10d",dados[i].ano);
		printf("%-15s",dados[i].varid);
		printf("%-10s",dados[i].pais);
		printf("%-10.1f",dados[i].valor);
		printf("\n");
	}
	//printf("\n");
}


