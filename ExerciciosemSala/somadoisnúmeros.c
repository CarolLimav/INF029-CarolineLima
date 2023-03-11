// função que soma dois números soma e retorna o resultado 
#include <stdio.h>

int soma(int n1, int n2){
  return n1 + n2;
}// se eu colocasse a dunção no final eu teria que declarar int soma();
int main(){
  int n1, n2; 
  printf("Digite o valor de n1:");
  scanf("%d", &n1);
  printf("Digite o valor de n2:");
  scanf("%d",&n2); 

  int resultado;
  
  resultado = soma(n1, n2); //aqui eu chamo a função

  printf("o resultado é: %d", resultado);
  
}