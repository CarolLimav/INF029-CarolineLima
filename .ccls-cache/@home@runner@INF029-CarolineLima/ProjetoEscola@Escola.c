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

int main(){

  





  
}