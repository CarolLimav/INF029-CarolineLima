
#include <stdio.h>

#define TAMALUNO 3
#define TAMDATA 3
#define TAMDISCIPLINA 3
#define TAMPROFESSOR 3
//protótipos
void menuGeral();


typedef struct dt {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct dadosaluno {
  int matriculaAluno;
  char nomeAluno[50];
  char sexoAluno[1];
  char cpfAluno[11];
  Data nascimento;
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
  char sexoProfessor[1];
  char cpfProfessor[11];
  Data nascimento;
} dadosProfessor;

Aluno alunos[TAMALUNO]; // aqui é um vetor de uma estrutura
// Data datas[TAMDATA];

Disciplina discs[TAMDISCIPLINA];
dadosProfessor professores[TAMPROFESSOR];

int main() {
  int contagemAluno = 0;
  int contagemProfessor = 0; 
  int contagemDisciplna = 0;
  int sair = 0;

  int opcao, opcaoMenu, opcaoAluno;

  while(! sair){
  menuGeral();
  scanf("%d",&opcaoMenu);
    
  switch (opcaoMenu) {
  case 0:
    printf("Encerrando sistema...");
    break;

  case 1:{
    printf("Digite a opção desejada:\n");
    printf("{0} sair:\n");
    printf("{1} Inserir aluno:\n");
    printf("{2} Listar alunos:\n");
    scanf("%d", &opcaoAluno);

    switch (opcaoAluno) {

      case 0: {
        printf("Saindo...");
       break;
        }
      case 1: {
        system("clear");
        if (contagemAluno != TAMALUNO) {
          printf("Digite a matrícula:\n");
          scanf("%d", &alunos[contagemAluno].matriculaAluno);
          getchar();
          printf("Digite o nome:\n");
          getchar();
          fgets(alunos[contagemAluno].nomeAluno, 50, stdin);
          printf("Digite o gênero do Aluno: F OU M\n");
          getchar();
          fgets(alunos[contagemAluno].sexoAluno, 1, stdin);
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
        } else {
          printf("Lista cheia!");
        }
        break;
        }
       case 2: {
    if (contagemAluno == 0) {
      printf("Sem alunos matriculados!\n");
      break;
    } else {
      printf("Listagem de aluno:\n");
      for (int i = 0; i < contagemAluno; i++) {
        fflush(stdin);
        printf("Matricula: %d\n", &alunos[i].matriculaAluno);
        printf("Nome: %s\n", &alunos[i].nomeAluno);
        printf("Data de nascimento: %d %d %d", &alunos[i].nascimento.dia,
               &alunos[i].nascimento.mes, &alunos[i].nascimento.ano);
      }
    }
    getchar();
    break;
        }
      }
    }
  
  case 2: {
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
        fgets( &professores[contagemProfessor].sexoProfessor, 1, stdin);
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
      break;
  }
  case 3:{
    if(contagemDisciplna != TAMDISCIPLINA){
    system("clear");
    printf("Digite o nome da disciplina:\n");
    fgets(discs[contagemDisciplna].nomeDisciplina, 50, stdin);
    fflush(stdin);
    printf("Digite o Código:\n");
    fgets(discs[contagemDisciplna].codigoDisciplina, 50, stdin);
    fflush(stdin);
    printf("Digite o semestre \n:");
    scanf("%d", &discs[contagemDisciplna].semestreDisciplina);
    fflush(stdin);
    printf("Digite o nome do professor:\n");
    fgets(discs[contagemDisciplna].professorDisciplina, 50, stdin);
    fflush(stdin);
    printf("Disciplina cadastrada com sucesso!");
    contagemDisciplna++;
      }
    else{
      printf("Lista cheia!");
    }
    break;
    }
  }
}
//funções 
 void menuGeral (){
  printf("Digite a opção desejada:\n");
  printf("{0} sair:\n");
  printf("{1} Aluno:\n");
  printf("{2} Professor:\n");
  printf("{3} Disciplina:\n");
}