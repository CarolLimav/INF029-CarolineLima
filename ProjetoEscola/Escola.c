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
  char sexoAluno;
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
  char sexoProfessor;
  char cpfProfessor[11];
  Data nascimento;
} dadosProfessor;
//protótipos das funções; 
int menuGeral();
int menuAluno();
int menuDisciplina();
int menuProfessor(); 
int menuRelatorios(); 
int menurRelatorioAlunos(); 
int CadastrarAluno(int contagemAluno, Aluno alunos[]);
int ListarAlunos(int contagemAluno,Aluno alunos[]);
int CadastrarProfessor(int contagemProfessor, dadosProfessor professores[]);
int listarProfessores(int contagemProfessor, dadosProfessor professores[]);
int CadastrarDisciplina(int contagemDisciplina, Disciplina discs[]);
int listarDisciplinas(int contagemDisciplina, Disciplina discs[]);
int listarAlunoPorSexo(int contagemAluno, Aluno alunos[]);
int ExcluirAluno(int contagemAluno, Aluno alunos[]);
int atualizarAlunos(int contagemAluno,Aluno alunos[]); 

Aluno alunos[TAMALUNO]; // aqui é um vetor de uma estrutura
// Data datas[TAMDATA];

Disciplina discs[TAMDISCIPLINA];
dadosProfessor professores[TAMPROFESSOR];

int main() {
  
  int contagemAluno = 0;
  int contagemProfessor = 0; 
  int contagemDisciplina = 0;
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
    while( !sairAluno){
     opcaoAluno = menuAluno(); 
  switch (opcaoAluno) {
    case 0:{
    opcaoAluno =  menuGeral(); 
    //sairAluno = 1; 
    break;
    }
      case 1:{ 
        CadastrarAluno(contagemAluno, alunos);
        contagemAluno++; 
        break;
    }
    case 2:{
      ListarAlunos(contagemAluno, alunos);   
      break; 
  }
    case 3:  {
      ExcluirAluno(contagemAluno, alunos);
      contagemAluno --;
              break;
            }
    case 4:{
      atualizarAlunos(contagemAluno, alunos);
      break; 
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
    while( ! sairProfessor){
    opcaoProfessor = menuProfessor(); 
      switch(opcaoProfessor){
        case 0: {
        opcaoProfessor = menuGeral();
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
      case 3:   {
        break;
      }
      }
      }
  break;
  }
case 3:{
  int sairDisciplina = 0;
  int opcaoDisciplina = 0;
  printf(" Disciplina\n");
   while( ! sairDisciplina){
    opcaoDisciplina = menuDisciplina(); 

      switch(opcaoDisciplina){
        case 0: {
        opcaoDisciplina = menuGeral(); 
        //sairDisciplina = 1;
        break;
      }
        case 1:{
        CadastrarDisciplina(contagemDisciplina, discs);
        contagemDisciplina++; 
        break;
  }
        case 2: {
        listarDisciplinas(contagemDisciplina, discs);
          break;
        }
        case 3:{
          
        break;
}
}
}
  break;
}
case 4:{
      int sairRelatorio= 0;
      int opcaoRelatorio = 0;
      printf("Relatórios");
      while(! sairRelatorio){
        opcaoRelatorio = menuRelatorios(); 
      switch(opcaoRelatorio){
        case 0: {
        //opcaoRelatorio = menuRelatorios();
        sairRelatorio = 1;
        break; 
          }
        case 1:{
          listarAlunoPorSexo(contagemAluno, alunos);
          break; 
        }
      }
      }
      break; 
      }
  default:{
    printf("Opção inválida\n");
  }
    }
 break;
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
  printf("{4} Relatórios\n "); 
    scanf("%d",&opcaoMenu);
    return opcaoMenu; 
}
int menuRelatorios(){
  int opcaoRelatório; 
printf("Digite a opção desejada:\n");
printf("{0} sair:\n");
printf("{1} Listar alunos\n");
printf("{2} Listar professores\n");
printf("{3} Listar disciplinas\n");
printf("{4} Listar disciplinas e alunos matriculados\n");
printf("{5} Listar alunos por sexo\n");
printf("{6} Listar alunos por nome\n");
printf("{7} Listar alunos por data de nascimento\n");
printf("{4} Listar professores por sexo\n");
printf("{5} Listar professores por nome\n");
printf("{6} Listar professores por data de nascimento\n");
  scanf("%d",&opcaoRelatório);
}
int menuDisciplina(){
  int opcaoDisciplina;
  printf("Digite a opção desejada:\n");
  printf("{1} Cadastrar disciplina\n");
  printf("{2} Listar Disciplinas:\n");
  printf("{3} Listar disciplinas e alunos matriculados\n");
  scanf("%d", &opcaoDisciplina);
  return opcaoDisciplina;
}
int menuAluno(){
  int opcaoAluno; 
printf("Digite a opção desejada:\n");
  printf("{0} voltar ao menu principal:\n");
  printf("{1} Inserir aluno:\n");
  printf("{2} Listar alunos:\n");
  printf("{3} Excluir aluno\n");
  printf("{4} Atualizar aluno\n"); 
  scanf("%d", &opcaoAluno);
  return opcaoAluno; 
}

int CadastrarDisciplina(int contagemDisciplina, Disciplina discs[]){
if(contagemDisciplina != TAMDISCIPLINA){
    system("clear");
    printf("Digite o nome da disciplina:\n");
    fgets(discs[contagemDisciplina].nomeDisciplina, 50, stdin);
    fflush(stdin);
    printf("Digite o Código:\n");
    fgets(discs[contagemDisciplina].codigoDisciplina, 50, stdin);
    fflush(stdin);
    printf("Digite o semestre \n:");
    scanf("%d", &discs[contagemDisciplina].semestreDisciplina);
    fflush(stdin);
    printf("Digite o nome do professor:\n");
    fgets(discs[contagemDisciplina].professorDisciplina, 50, stdin);
    fflush(stdin);
    // printf("Digite o nome do aluno que deseja cadastrar nessa disciplina:");
    // fgets(alunos[contagemAluno].nomeAluno, 50, stdin);
    printf("Disciplina cadastrada com sucesso!\n");
    contagemDisciplina++;
      }
    else{
      printf("Lista cheia!");
    }  
}
int CadastrarAluno(int contagemAluno, Aluno alunos[] ){
if (contagemAluno != TAMALUNO) {
           system("clear");
          printf("CADASTRO DE ALUNO\n");
          printf("Digite a matrícula:\n");
          scanf("%d", &alunos[contagemAluno].matriculaAluno);
          getchar();
          printf("Digite o nome:\n");
          getchar();
          fgets(alunos[contagemAluno].nomeAluno, 50, stdin);
          printf("Digite o gênero do Aluno: F OU M\n");
          scanf("%c", &alunos[contagemAluno].sexoAluno);
          getchar();
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
    } 
      for (int i = 0; i < contagemAluno; i++) {
        fflush(stdin);
        printf("Listagem de aluno:\n");
        printf("Matricula: %d\n", alunos[i].matriculaAluno);
        printf("Nome: 3%s\n", alunos[i].nomeAluno);
        printf("Data de nascimento: %d %d %d\n", alunos[i].nascimento.dia, alunos[i].nascimento.mes, alunos[i].nascimento.ano);
        fflush(stdin);
        printf("Sexo %c\n", alunos[i].sexoAluno);
        fflush(stdin);
        printf("CPF: %s\n", alunos[i].cpfAluno);
      }
  }

int listarDisciplinas(int contagemDisciplina, Disciplina discs[]){
if (contagemDisciplina == 0) {
      printf("Sem disciplinas cadastradas!\n");
    } 
      for (int i = 0; i < contagemDisciplina; i++) {
        printf("Listagem de disciplinas:\n");
        fflush(stdin);
        printf("Nome: %s\n", discs[i].nomeDisciplina);
        printf("Código: %s\n", discs[i].codigoDisciplina);
        printf("Semestre %d\n", discs[i].semestreDisciplina);
        printf("Nome do professor: %s\n", discs[i].professorDisciplina);
      }
    }

int menuProfessor(){
  int opcaoProfessor;
  printf("Digite a opção desejada:\n");
  printf("{0} voltar ao menu principal:\n");
  printf("{1} Cadastrar professor:\n");
  printf("{2} Listar professores:\n");
  // printf("{3} Listar professores por sexo:\n");
  // printf("{4} Listar professore ordenados por nome\n");
  // printf("{5} Listar professores ordenados por data de nascimento\n");
  scanf("%d", &opcaoProfessor);
  return opcaoProfessor; 
}
int listarProfessores(int contagemProfessor, dadosProfessor professores[]){
  if (contagemProfessor == 0) {
      printf("Sem alunos matriculados!\n");
    } 
      for (int i = 0; i < contagemProfessor; i++) {
        printf("Listagem de Professores:\n");
        fflush(stdin);
        printf("Matricula: %d\n", professores[i].matriculaProfessor);
        printf("Nome: %s\n", professores[i].nomeProfessor);
        printf("Data de nascimento: %d %d %d\n", professores[i].nascimento.dia, alunos[contagemProfessor].nascimento.mes, alunos[i].nascimento.ano);
        printf("Sexo %c\n", professores[i].sexoProfessor);
        printf("CPF: %s\n", professores[i].cpfProfessor);
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
        fgets(professores[contagemProfessor].nomeProfessor, 50, stdin);
        printf("Digite o gênero do professor: F OU M\n");
        scanf("%c", &professores[contagemProfessor].sexoProfessor);
        getchar();
        printf("Digite o cpf:\n");
        getchar();
        fgets(professores[contagemProfessor].cpfProfessor, 11, stdin);
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
int ExcluirAluno(int contagemAluno, Aluno alunos[]){
              printf("Excluir Aluno\n");
              printf("Digite a matricula\n");
              int matricula;
              scanf("%d", &matricula);
              int achou = 0;
              if (matricula < 0){
                printf("Matrícula Inválida\n");
              }else{
                for (int i = 0; i < contagemAluno; i++)
                {
                  if (matricula == alunos[i].matriculaAluno){
                    //exclusão lógica
                    alunos[i].ativo = -1;
                    
                    for (int j = i; j < contagemAluno - 1; j++){ //shift
                      alunos[j].matriculaAluno = alunos[j+1].matriculaAluno;
                      alunos[j].sexoAluno = alunos[j+1].sexoAluno;
                      alunos[j].ativo = alunos[j+1].ativo;
                      //alunos[j].cpfAluno = alunos[j+1].cpfAluno;
                      // alunos[j].nomeAluno = alunos[j+1].sexoAluno;
                      // alunos[i].nascimento = alunos[j + 1].nascimento.dia;
                    }
                    // contagemAluno --;
                    achou = 1;
                    break;
                  }  
                }
                if (achou)
                  printf("Aluno excluído com sucesso\n");
                else
                  printf("Matrícula inexistente\n");
                
              }
}

int listarAlunoPorSexo(int contagemAluno, Aluno alunos[]){
  if(contagemAluno == 0){
    printf("Lista vazia!");
  }else {
    printf("Listagem por gênero");
    for(int i = 0; i< TAMALUNO ; i++){
      if(alunos[i].sexoAluno == 'f'){
        printf("%s %c\n", alunos[i].nomeAluno, alunos[i].sexoAluno);
      }
    }
     for(int i = 0; i< TAMALUNO; i++){
      if(alunos[i].sexoAluno == 'm'){
        printf("%s %c\n", alunos[i].nomeAluno, alunos[i].sexoAluno);
        
  }
}
 }
}

int atualizarAlunos(int contagemAluno,Aluno alunos[]){
  int atualizarMatricula; 
printf("Digite a matricula que deseja atualziar:\n");
scanf("%d", &atualizarMatricula); 
  int achou = 0; 
  if(atualizarMatricula < 0){
    printf("matricula inválida");
  }else{
for(int i = 0; i < contagemAluno;  i++){
  if(atualizarMatricula == alunos[i].matriculaAluno && alunos[i].ativo){
    printf("Digite a nova matricula:");
    int matriculaNova;
    scanf("%d",&matriculaNova);
    alunos[i].matriculaAluno = matriculaNova; 
    achou = 1;
    break; 
  }
}
    if(achou){
      printf("Aluno atualizado!");
    }
    else{
      printf("matricula inexistente"); 
    }
}
}





  
}