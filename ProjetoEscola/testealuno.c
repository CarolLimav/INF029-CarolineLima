#include <stdio.h>

#define TAMALUNO 3
#define TAMDATA 3
#define TAMDISCIPLINA 3
#define TAMPROFESSOR 3

typedef struct dt {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct dadosaluno {
  int matriculaAluno;
  char nomeAluno[50];
  char sexoAluno[2];
  char cpfAluno[11];
  Data nascimento;
  int ativo;
} Aluno;

struct dadosaluno AlunosCadastrados[3];

typedef struct disc {
  char nomeDisciplina[50];
  char codigoDisciplina[50];
  int semestreDisciplina;
  char professorDisciplina[50];
} Disciplina;

typedef struct Professor {
  int matriculaProfessor;
  char nomeProfessor[50];
  char sexoProfessor[2];
  char cpfProfessor[11];
  Data nascimento;
} dadosProfessor;
//protótipos das funções; 
int menuGeral();
int menuAluno();
int menuProfessor(); 
int CadastrarAluno(int contagemAluno, Aluno alunos[]);
int ListarAlunos(int contagemAluno,Aluno alunos[]);
int CadastrarProfessor(int contagemProfessor, dadosProfessor professores[]);
int listarProfessores(int contagemProfessor, dadosProfessor professores[]);


Aluno alunos[TAMALUNO]; // aqui é um vetor de uma estrutura
// Data datas[TAMDATA];

Disciplina discs[TAMDISCIPLINA];
dadosProfessor professores[TAMPROFESSOR];

int main(void) {
  
  int contagemAluno = 0;
  int contagemProfessor = 0; 
  int contagemDisciplna = 0;
  int sair = 0;

  int opcao, opcaoMenu, opcaoAluno;

  while(! sair){
  opcaoMenu = menuGeral();
  
    
  switch (opcaoMenu) {
  case 0:{
    opcaoMenu = 1; 
    printf("Encerrando sistema...");
    break;
  }
  case 1 : {
  int sairAluno = 0;
  int opcaoAluno = 0;
  printf(" Aluno\n");
    while( ! sair){
     opcaoAluno = menuAluno(); 
      
  switch (opcaoAluno) {
    case 0:{
    sairAluno = 1; 
    break;
    }
      case 1:{ 
        CadastrarAluno(contagemAluno, alunos);
        contagemAluno++; 
        break;
    }
    case 2:{
      ListarAlunos(contagemAluno, alunos);   
  }
    case 3: {
      int achou; 
      printf("Digite a matrícula do aluno que deseja excluir:");
      scanf("%d", &alunos[contagemAluno].matriculaAluno);
      for(int i = 0; i<contagemAluno; i++){
        if(alunos[contagemAluno].matriculaAluno == alunos[i].matriculaAluno){
        alunos[i].ativo = -1; 
          for(int j = i; j < contagemAluno - 1; j++){
            alunos[j].matriculaAluno = alunos[j + 1].matriculaAluno;
            //alunos[j].sexoAluno = alunos[j + 1].sexoAluno;
            alunos[j].ativo = alunos[j + 1].ativo;
          }
        contagemAluno--;
        achou = 1;
        break;
        
        }
      }
      if(achou){
        printf("Aluno excluído\n");
      }else{
        printf("Matrícula inexistente\n");
      }
    }
    
    default:{
      printf("Opção inválida\n");
    }
  }
}
 break;
}
case 2: {
printf("  Professor\n ");
  int sairProfessor = 0;
  int opcaoProfessor = 0;
    while( ! sair){
    opcaoProfessor = menuProfessor(); 

      switch(opcaoProfessor){
        case 0: {
        sairProfessor = 1;
        break;
      }
        case 1:{
        CadastrarProfessor(contagemProfessor, professores);
        contagemProfessor++; 
        break;
  }
        case 2: {
        listarProfessores(contagemProfessor, professores);
          break;
        }
        case 3:
}
}
  break;
}

case 3:{
  printf(" Disciplina\n");
  break;
}
  default:{
    printf("Opção inválida\n");
  }
 break;;
}  
    
  }
}

//funções 
 int menuGeral (){
  int opcaoMenu; 
  printf("Digite a opção desejada:\n");
  printf("{0} sair:\n");
  printf("{1} Aluno:\n");
  printf("{2} Professor:\n");
  printf("{3} Disciplina:\n");
    scanf("%d",&opcaoMenu);
    return opcaoMenu; 
}
int menuAluno(){
  int opcaoAluno; 
printf("Digite a opção desejada:\n");
  printf("{0} voltar ao menu principal:\n");
  printf("{1} Inserir aluno:\n");
  printf("{2} Listar alunos:\n");
  printf("{3} Excluir aluno");
  scanf("%d", &opcaoAluno);
  return opcaoAluno; 
}

int CadastrarAluno(int contagemAluno, Aluno alunos[] ){
if (contagemAluno != TAMALUNO) {
           printf("CADASTRO DE ALUNO\n");
          printf("Digite a matrícula:\n");
          scanf("%d", &alunos[contagemAluno].matriculaAluno);
          getchar();
          printf("Digite o nome:\n");
          getchar();
          fgets(alunos[contagemAluno].nomeAluno, 50, stdin);
          printf("Digite o gênero do Aluno: F OU M\n");
          getchar();
          fgets(alunos[contagemAluno].sexoAluno, 2, stdin);
          printf("Digite o cpf:\n");
          getchar();
          fgets(alunos[contagemAluno].cpfAluno, 11, stdin);
          printf("Digite a data de nascimento\n");
          scanf("%d", &alunos[contagemAluno].nascimento.dia);
          getchar();
          printf("Digite o mês de nascimento\n");
          scanf("%d", &alunos[contagemAluno].nascimento.mes);
          getchar();
          printf("Digite o ano de nascimento\n");
          scanf("%d", &alunos[contagemAluno].nascimento.ano);
          getchar();
          printf("Aluno cadastrado com sucesso\n");
          getchar();
          contagemAluno++; 
    }  
}
int ListarAlunos(int contagemAluno,Aluno alunos[]){
  if (contagemAluno == 0) {
      printf("Sem alunos matriculados!\n");
    } else {
      printf("Listagem de aluno:\n");
      for (int i = 0; i < contagemAluno; i++) {
        fflush(stdin);
        printf("Matricula: %d\n", &alunos[i].matriculaAluno);
        printf("Nome: %s\n", &alunos[i].nomeAluno);
        printf("Data de nascimento: %d %d %d\n", &alunos[i].nascimento.dia, &alunos[i].nascimento.mes, &alunos[i].nascimento.ano);
        printf("Sexo %s\n", &alunos[i].sexoAluno);
        printf("CPF: %s\n", &alunos[i].cpfAluno);
      }
    }
}
int menuProfessor(){
  int opcaoProfessor;
  printf("Digite a opção desejada:\n");
  printf("{0} voltar ao menu principal:\n");
  printf("{1} Cadastrar professor:\n");
  printf("{2} Listar professores:\n");
  printf("{3} Listar professores por sexo:\n");
  printf("{4} Listar professore ordenados por nome\n");
  printf("{5} Listar professores ordenados por data de nascimento\n");
  scanf("%d", &opcaoProfessor);
  return opcaoProfessor; 
}
int listarProfessores(int contagemProfessor, dadosProfessor professores[]){
  if (contagemProfessor == 0) {
      printf("Sem alunos matriculados!\n");
    } else {
      printf("Listagem de Professores:\n");
      for (int i = 0; i < contagemProfessor; i++) {
        fflush(stdin);
        printf("Matricula: %d\n", &professores[i].matriculaProfessor);
        printf("Nome: %s\n", &professores[i].nomeProfessor);
        printf("Data de nascimento: %d %d %d\n", &professores[i].nascimento.dia, &alunos[i].nascimento.mes, &alunos[i].nascimento.ano);
        printf("Sexo %c\n", &professores[i].sexoProfessor);
        printf("CPF: %s\n", &professores[i].cpfProfessor);
      }
    }
}
int CadastrarProfessor(int contagemProfessor, dadosProfessor professores[] ){
 system("clear");
      if (contagemProfessor != TAMPROFESSOR) {
        printf("Digite a matrícula:\n");
        scanf("%d", &professores[contagemProfessor].matriculaProfessor);
        getchar();
        printf("Digite o nome:\n");
        getchar();
        fgets(&professores[contagemProfessor].nomeProfessor, 50, stdin);
        printf("Digite o gênero do professor: F OU M\n");
        getchar();
        fgets( &professores[contagemProfessor].sexoProfessor, 2, stdin);
        printf("Digite o cpf:\n");
        getchar();
        fgets( &professores[contagemProfessor].cpfProfessor, 11, stdin);
        printf("Digite a data de nascimento\n");
        scanf("%d", &professores[contagemProfessor].nascimento.dia);
        getchar();
        printf("Digite o mês de nascimento\n");
        scanf("%d", &professores[contagemProfessor].nascimento.mes);
        getchar();
        printf("Digite o ano de nascimento\n");
        scanf("%d", &professores[contagemProfessor].nascimento.ano);
        getchar();
        printf("Professor cadastrado com sucesso\n");
        getchar();
        contagemProfessor++;
      } else {
        printf("Lista cheia!");
        }
}
