#include <stdio.h>
#include <stdlib.h>

int main() {
	int qtdidades=0;
	float media=0;
	int soma=0;

	printf("quantas idades serão informadas?");
	scanf("%d", &qtdidades);
  
  int idades[qtdidades];
	
	for(int i=0; i < qtdidades; i++){
		printf("Digite a idade %d:", i);
		scanf("%d", &idades[i]);
		soma = soma + idades[i];
	}

	media = soma / qtdidades;
	
	printf("a média é: %f", media);

  for(int i=0; i < qtdidades; i++){
    if(idades[i] > media){
      printf("Números maiores que a média : %d\n", idades[i]);
    }
  }
}