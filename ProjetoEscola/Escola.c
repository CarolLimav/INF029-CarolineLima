#include <stdio.h>
#include <string.h>

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
  char cpfAluno[12];
  Data nascimento;
  int ativo;
} Aluno;

typedef struct disc {
  char nomeDisciplina[50];
  int codigoDisciplina;
  int semestreDisciplina;
  char professorDisciplina[50];
} Disciplina;

typedef struct Professor {
  int matriculaProfessor;
  char nomeProfessor[50];
  char sexoProfessor;
  char cpfProfessor[12];
  Data nascimento;
} dadosProfessor;
// protótipos das funções;
int menuGeral();
int menuAluno();
int menuDisciplina();
int menuProfessor();
int menuRelatorios();
int menuRelatorioAlunos();
int CadastrarAluno(int contagemAluno, Aluno alunos[]);
int ListarAlunos(int contagemAluno, Aluno alunos[]);
int CadastrarProfessor(int contagemProfessor, dadosProfessor professores[]);
int listarProfessores(int contagemProfessor, dadosProfessor professores[]);
int CadastrarDisciplina(int contagemDisciplina, Disciplina discs[]);
int listarDisciplinas(int contagemDisciplina, Disciplina discs[]);
int listarAlunoPorSexo(int contagemAluno, Aluno alunos[]);
int ExcluirAluno(int contagemAluno, Aluno alunos []); 
int ExcluirProfessor(int contagemProfessor, dadosProfessor professores[]);
int atualizarAlunos(int contagemAluno, Aluno alunos[]);
int atualizarProfessores(int contagemProfessor, dadosProfessor professores[]);
int excluirDisciplina(int contagemDisciplina, Disciplina discs[]);
int atualizarDisciplina(int contagemDisciplina, Disciplina discs[]);
int listarProfessorPorSexo(int contagemProfessor, dadosProfessor professores[]);
int listarPorOrdemAlfabetica(int contagemAluno, Aluno alunos[]);
int OrdenarporNome(int contagemAluno, Aluno alunos[]);
int ordenarPorNascimentoAluno(int contagemAluno, Aluno alunos[]);
int validacaoCpf(int contagemAluno, Aluno alunos[]); 
int validarCpfProfessor(int contagemProfessor, dadosProfessor professores[]);
int validarNascimentoAluno(int contagemAluno, Aluno alunos[]);
int validarNascimentoProfessor(int contagemProfessor, dadosProfessor professores[]);

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

  while (!sair) {
    opcaoMenu = menuGeral();
    switch (opcaoMenu) {
    case 0: {
      opcaoMenu = 1;
      printf("Encerrando sistema...");
      break;
    }
    case 1: {
      int sairAluno = 0;
      int opcaoAluno = 0;
      printf(" Aluno\n");
      while (!sairAluno) {
        opcaoAluno = menuAluno();
        switch (opcaoAluno) {
        case 0: {
          sairAluno = 1;
          break;
        }
        case 1: {
          CadastrarAluno(contagemAluno, alunos);
          contagemAluno++;
          break;
        }
        case 2: {
          ListarAlunos(contagemAluno, alunos);
          break;
        }
        case 3: {
         ExcluirAluno(contagemAluno, alunos);
          contagemAluno--;
          break;
        }
        case 4: {
        atualizarAlunos(contagemAluno, alunos);
          break;
        }
        default: {
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
      while (!sairProfessor) {
        opcaoProfessor = menuProfessor();
        switch (opcaoProfessor) {
        case 0: {
          sairProfessor = 1;
          break;
        }
        case 1: {
          CadastrarProfessor(contagemProfessor, professores);
          contagemProfessor++;
          break;
        }
        case 2: {
          listarProfessores(contagemProfessor, professores);
          break;
        }
        case 3: {
          ExcluirProfessor(contagemProfessor, professores);
          contagemProfessor--; 
          break;
        }
        case 4:{
          atualizarProfessores(contagemProfessor, professores);
            break;
        }
          default:{
            printf("Opção inválida!!");
          }
        }
      }
      break;
    }
    case 3: {
      int sairDisciplina = 0;
      int opcaoDisciplina = 0;
      printf(" Disciplina\n");
      while (!sairDisciplina) {
        opcaoDisciplina = menuDisciplina();
        switch (opcaoDisciplina) {
        case 0: {
          sairDisciplina = 1;
          break;
        }
        case 1: {
          CadastrarDisciplina(contagemDisciplina, discs);
          contagemDisciplina++;
          break;
        }
        case 2: {
          listarDisciplinas(contagemDisciplina, discs);
          break;
        }
        case 3: {
          excluirDisciplina(contagemDisciplina, discs);
          contagemDisciplina--; 
          break;
        }
          case 4:{
          atualizarDisciplina(contagemDisciplina, discs);
            break; 
          }
          default:{
            printf("Opção inválida!!");
          }
        }
      }
      break;
    }
    case 4: {
      int sairRelatorio = 0;
      int opcaoRelatorio = 0;
      printf("Relatórios");
      while (!sairRelatorio) {
        opcaoRelatorio = menuRelatorios();
        switch (opcaoRelatorio) {
        case 0: {
          sairRelatorio = 1;
          break;
        }
        case 1: {
        listarAlunoPorSexo(contagemAluno, alunos);
          break;
        }
          case 2:{
        listarProfessorPorSexo(contagemProfessor, professores); 
            break;
          }
          case 3:{
        OrdenarporNome(contagemAluno, alunos);
          break; 
        }
        case 4:{
        ordenarPorNascimentoAluno(contagemAluno, alunos);
        }
      }
      break;
    }
    default: {
      printf("Opção inválida\n");
      break;
    }
    }
  }
  }
}
//funções
int ordenarPorNascimentoAluno(int contagemAluno, Aluno alunos[]){
  int i, j;
  Aluno temp;
  for (i = 0; i < contagemAluno-1; i++) {
    for (j = 0; j < contagemAluno-i-1; j++) {
      if (alunos[j].nascimento.ano > alunos[j+1].nascimento.ano) {
        temp = alunos[j];
        alunos[j] = alunos[j+1];
        alunos[j+1] = temp;
      } else if (alunos[j].nascimento.ano == alunos[j+1].nascimento.ano &&
                 alunos[j].nascimento.mes > alunos[j+1].nascimento.mes) {
        temp = alunos[j];
        alunos[j] = alunos[j+1];
        alunos[j+1] = temp;
      } else if (alunos[j].nascimento.ano == alunos[j+1].nascimento.ano &&
                 alunos[j].nascimento.mes == alunos[j+1].nascimento.mes &&
                 alunos[j].nascimento.dia > alunos[j+1].nascimento.dia) {
        temp = alunos[j];
        alunos[j] = alunos[j+1];
        alunos[j+1] = temp;
      }
    }
  }
   printf("Alunos ordenados por data de nascimento:\n");
  for (int i = 0; i < TAMALUNO; i++) {
    printf("%s - %d/%d/%d\n", alunos[i].nomeAluno, alunos[i].nascimento.dia,
           alunos[i].nascimento.mes, alunos[i].nascimento.ano);
  }
  return 0; 
}
int OrdenarporNome(int contagemAluno, Aluno alunos[]){
int i, j;
for (int i = 0; i < TAMALUNO - 1; i++) {
    for (int j = 0; j < TAMALUNO - i - 1; j++) {
        if (strcmp(alunos[j].nomeAluno, alunos[j+1].nomeAluno) > 0) {
            Aluno temp = alunos[j];
            alunos[j] = alunos[j+1];
            alunos[j+1] = temp;
        }
    }
}
  for (int i = 0; i < TAMALUNO; i++) {
    printf("%s\n", alunos[i].nomeAluno);
  }
  return 0; 
}
int menuGeral() {
  int opcaoMenu;
  printf("Digite a opção desejada:\n");
  printf("{0} sair:\n");
  printf("{1} Aluno:\n");
  printf("{2} Professor:\n");
  printf("{3} Disciplina:\n");
  printf("{4} Relatórios\n ");
  scanf("%d", &opcaoMenu);
  return opcaoMenu;
}
int menuRelatorios() {
  int opcaoRelatorio;
  printf("Digite a opção desejada:\n");
  printf("{0} sair:\n");
  printf("{1} Listar alunos por sexo\n");
  printf("{2} Listar professores por sexo\n");
  printf("{3} Listar alunos por ordem Alfabética\n");
  printf("{4} Listar alunos por ordem de nascimento\n");
  printf("{5} Listar professores por ordem alfabética\n");
  printf("{6} Listar professores por ordem de nascimento\n");
  printf("{7} Listar disciplinas e alunos matriculados\n");
  scanf("%d", &opcaoRelatorio);
  return opcaoRelatorio; 
}
int menuDisciplina() {
  int opcaoDisciplina;
  printf("Digite a opção desejada:\n");
  printf("{1} Cadastrar disciplina\n");
  printf("{2} Listar Disciplinas:\n");
  printf("{3} Excluir disciplina\n");
  printf("{4} Atualizar disciplina \n");
  scanf("%d", &opcaoDisciplina);
  return opcaoDisciplina;
}
int menuAluno() {
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
int CadastrarDisciplina(int contagemDisciplina, Disciplina discs[]) {
  if (contagemDisciplina < TAMDISCIPLINA) {
    printf("CADASTRO DE DISCIPLINA\n");
    getchar();
    printf("Digite o nome:\n");
    fgets(discs[contagemDisciplina].nomeDisciplina, 50, stdin);
    printf("Digite o código:\n");
    scanf("%d", &discs[contagemDisciplina].codigoDisciplina);
    printf("Digite o nome do professor:\n");
    getchar();
    fgets(discs[contagemDisciplina].professorDisciplina, 50, stdin);
    printf("Digite o semestre:\n");
    scanf("%d", &discs[contagemDisciplina].semestreDisciplina);
  } else {
    printf("Lista cheia!");
  }
  return 0;
}
int validacaoCpf(int contagemAluno, Aluno alunos[]){//aluno
  if(strlen(alunos[contagemAluno].cpfAluno) != 11){
    printf("Digite um cpf válido!\n");
  }
  return 0; 
}
int validarCpfProfessor(int contagemProfessor, dadosProfessor professores[]){
  if(strlen(professores[contagemProfessor].cpfProfessor) != 12){
    printf("Digite um cpf válido!\n");
  }
  return 0; 
}
int CadastrarAluno(int contagemAluno, Aluno alunos[]) {
 int tamanho;
  tamanho = strlen(alunos[contagemAluno].cpfAluno); 
  if (contagemAluno < TAMALUNO)
  
  {
    system("clear");
    printf("CADASTRO DE ALUNO\n");
    printf("Digite a matrícula:\n");
    scanf("%d", &alunos[contagemAluno].matriculaAluno);
    getchar();
    printf("Digite o nome:\n");
    fgets(alunos[contagemAluno].nomeAluno, 50, stdin);
    getchar();
    printf("Digite o gênero do Aluno: F OU M\n");
    scanf("%c", &alunos[contagemAluno].sexoAluno);
    getchar();
    printf("Digite o cpf:\n"); 
    fgets(alunos[contagemAluno].cpfAluno, 12, stdin);
    validacaoCpf(contagemAluno, alunos);
    fgets(alunos[contagemAluno].cpfAluno, 12, stdin);
    getchar();
    printf("Digite a data de nascimento\n");
    printf("\nDia:\n");
    scanf("%d", &alunos[contagemAluno].nascimento.dia);
    getchar();
    printf("Digite o mês de nascimento\n");
    printf("\nMês:\n");
    scanf("%d", &alunos[contagemAluno].nascimento.mes);
    getchar();
    printf("Digite o ano de nascimento\n");
    printf("\nAno: \n");
    validarNascimentoAluno(contagemAluno, alunos);
    getchar();
    printf("Aluno cadastrado com sucesso\n");
    // getchar();
  } else {
    printf("Lista cheia!!\n");
  }
  return 0;
}
int ListarAlunos(int contagemAluno, Aluno alunos[]) {
  if (contagemAluno == 0) {
    printf("Sem alunos cadastrados!\n");
  }
  for (int i = 0; i < contagemAluno; i++) {
  
    printf("Listagem de alunos:\n");
    printf("Matricula: %d\n", alunos[i].matriculaAluno);
    printf("Nome: %s\n", alunos[i].nomeAluno);
    printf("Data de nascimento: %d %d %d\n", alunos[i].nascimento.dia,
           alunos[i].nascimento.mes, alunos[i].nascimento.ano);
    fflush(stdin);
    printf("Sexo: %c\n", alunos[i].sexoAluno);
    fflush(stdin);
    printf("CPF: %s\n", alunos[i].cpfAluno);
  }
  return 0;
}
int listarDisciplinas(int contagemDisciplina, Disciplina discs[]) {
  if (contagemDisciplina == 0) {
    printf("Sem disciplinas cadastradas!\n");
  }
  for (int i = 0; i < contagemDisciplina; i++) {
    printf("Listagem de disciplinas:\n");
    printf("Nome: %s\n", discs[i].nomeDisciplina);
    printf("Código: %d\n", discs[i].codigoDisciplina);
    printf("Semestre %d\n", discs[i].semestreDisciplina);
    printf("Nome do professor: %s\n", discs[i].professorDisciplina);
  }
  return 0;
}
int menuProfessor() {
  int opcaoProfessor;
  printf("Digite a opção desejada:\n");
  printf("{0} voltar ao menu principal:\n");
  printf("{1} Cadastrar professor:\n");
  printf("{2} Listar professores:\n");
  printf("{3} Excluir professor\n");
  printf("{4} Atualizar professor\n"); 
  scanf("%d", &opcaoProfessor);
  return opcaoProfessor;
}
int listarProfessores(int contagemProfessor, dadosProfessor professores[]) {
  if (contagemProfessor == 0) {
    printf("Sem professores matriculados!\n");
  }
  for (int i = 0; i < contagemProfessor; i++) {
    printf("Listagem de Professores:\n");
    printf("Matricula: %d\n", professores[i].matriculaProfessor);
    printf("Nome: %s\n", professores[i].nomeProfessor);
    printf("Data de nascimento: %d %d %d\n", professores[i].nascimento.dia,
           professores[i].nascimento.mes, professores[i].nascimento.ano);
    printf("Sexo %c\n", professores[i].sexoProfessor);
    printf("CPF: %s\n", professores[i].cpfProfessor);
  }
  return 0;
}
int CadastrarProfessor(int contagemProfessor, dadosProfessor professores[]) {
  system("clear");
  if (contagemProfessor < TAMPROFESSOR) {
    system("clear");
    printf("CADASTRO DE PROFESSORES \n");
    printf("Digite a matrícula:\n");
    scanf("%d", &professores[contagemProfessor].matriculaProfessor);
    getchar();
    printf("Digite o nome:\n");
    fgets(professores[contagemProfessor].nomeProfessor, 50, stdin);
    getchar();
    printf("Digite o gênero: F OU M\n");
    scanf("%c", &professores[contagemProfessor].sexoProfessor);
    getchar();
    printf("Digite o cpf:\n");
    fgets(professores[contagemProfessor].cpfProfessor, 12, stdin);
    validarCpfProfessor(contagemProfessor, professores);
    fgets(professores[contagemProfessor].cpfProfessor, 12, stdin);
    getchar();
    printf("Digite a data de nascimento\n");
    printf("\nDia:\n");
    scanf("%d", &professores[contagemProfessor].nascimento.dia);
    getchar();
    printf("Digite o mês de nascimento\n");
    printf("\nMês:\n");
    scanf("%d", &professores[contagemProfessor].nascimento.mes);
    getchar();
    printf("Digite o ano de nascimento:\n");
    printf("\nAno: \n");
    scanf("%d", &professores[contagemProfessor].nascimento.ano);
    getchar();
    printf("Professor cadastrado com sucesso\n");
    // getchar();
  } else {
    printf("Lista cheia!");
  }
  return 0;
}
void copiaString(char strDestino[], char strOrigem[]){
  for(int i = 0; i < strlen(strOrigem); i++){
    strDestino[i] = strOrigem[i];
  }
}
int ExcluirAluno(int contagemAluno, Aluno alunos []){
  int matricula;
  printf("Exclusão por matrícula\n");
  if(contagemAluno < 0){
    printf("Não há alunos matriculados\n");
  }else{
    printf("EXCLUIR ALUNO\n");
    printf("Digite a matrícula:\n");
    scanf("%d", &matricula);
    for(int i = 0; i < contagemAluno; i++){
      if(matricula == alunos[i].matriculaAluno){
        for(int j = i; j< contagemAluno -1; j++){
          alunos[j].matriculaAluno = alunos[j + 1].matriculaAluno;
          copiaString(alunos[j].nomeAluno, alunos[j + 1].nomeAluno);
          
          alunos[j].sexoAluno = alunos[j + 1].sexoAluno;

          strcpy(alunos[j].cpfAluno,  alunos[j + 1].cpfAluno);
          
          alunos[j].nascimento.dia = alunos[j + 1].nascimento.dia;
          alunos[j].nascimento.mes = alunos[j + 1].nascimento.mes;
          alunos[j].nascimento.ano = alunos[j + 1].nascimento.ano;
        }
        //contagemAluno--;
        printf("\nAluno excluído com sucesso!\n");
      }
    }
  }
   return contagemAluno;
}
int ExcluirProfessor(int contagemProfessor, dadosProfessor professores[]){
   int matricula;
  printf("Exclusão por matrícula\n");
  if(contagemProfessor < 0){
    printf("Não há professores matriculados\n");
  }else{
    printf("EXCLUIR PROFESSOR: \n");
    printf("Digite a matrícula:\n");
    scanf("%d", &matricula);
    for(int i = 0; i < contagemProfessor; i++){
      if(matricula == professores[i].matriculaProfessor){
        for(int j = i; j< contagemProfessor -1; j++){
          professores[j].matriculaProfessor = professores[j + 1].matriculaProfessor;
          copiaString(professores[j].nomeProfessor,professores[j + 1].nomeProfessor);
          professores[j].sexoProfessor = professores[j + 1].sexoProfessor;
          strcpy(professores[j].cpfProfessor,  professores[j + 1].cpfProfessor);
          professores[j].nascimento.dia = professores[j + 1].nascimento.dia;
          professores[j].nascimento.mes = professores[j + 1].nascimento.mes;
          professores[j].nascimento.ano = professores[j + 1].nascimento.ano;
        }
        printf("\nProfessor excluído com sucesso!\n");
      }
    }
  }
   return contagemProfessor;
}
int listarAlunoPorSexo(int contagemAluno, Aluno alunos[]) {
  if (contagemAluno == 0) {
    printf("Lista vazia!\n");
  } else {
    printf("Listagem por gênero\n");
    for (int i = 0; i < contagemAluno; i++) {
      if (alunos[i].sexoAluno == 'f' || alunos[i].sexoAluno == 'F') {
        printf("%s %c\n", alunos[i].nomeAluno, alunos[i].sexoAluno);
      }
    }
    for (int i = 0; i < contagemAluno; i++) {
      if (alunos[i].sexoAluno == 'm' || alunos[i].sexoAluno == 'M' ) {
        printf("%s %c\n", alunos[i].nomeAluno, alunos[i].sexoAluno);
      }
    }
  }
  return 0;
}
int listarProfessorPorSexo(int contagemProfessor, dadosProfessor professores[]){
  if (contagemProfessor == 0) {
    printf("Lista vazia!\n");
  } else {
    printf("Listagem por gênero\n");
    for (int i = 0; i < contagemProfessor; i++) {
      if (professores[i].sexoProfessor == 'f' || professores[i].sexoProfessor == 'F') {
        printf("%s %c\n", professores[i].nomeProfessor, professores[i].sexoProfessor);
      }
    }
    for (int i = 0; i < contagemProfessor; i++) {
      if (professores[i].sexoProfessor == 'm' || professores[i].sexoProfessor == 'M' ) {
        printf("%s %c\n", professores[i].nomeProfessor, professores[i].sexoProfessor);
      }
    }
  }
  return 0;
}
int atualizarAlunos(int contagemAluno, Aluno alunos[]){
  int matricula;
  printf("Digite a matrícula que deseja atualizar:\n");
  scanf("%d",&matricula);
  for(int i = 0; i < contagemAluno; i++){
    if(matricula == alunos[i].matriculaAluno){
      printf("Atualize o nome:\n");
      getchar();
      fgets(alunos[i].nomeAluno, 50, stdin);
      printf("Atualize o cpf:\n");
      fgets(alunos[i].cpfAluno, 50, stdin);
      getchar();
      printf("Atualize o gênero:\n");
      scanf("%c", &alunos[i].sexoAluno);
      getchar();
      printf("Atualize a data de nascimento:\n");
      printf("Dia:\n");
      scanf("%d", &alunos[i].nascimento.dia);
      getchar();
      printf("Mês:\n");
      scanf("%d", &alunos[i].nascimento.mes);
      getchar();
      printf("Ano:\n");
      scanf("%d", &alunos[i].nascimento.ano);
      getchar();
      printf("Aluno atualizado com sucesso!!\n");
      }
  }
  return 0; 
}
int atualizarProfessores(int contagemProfessor, dadosProfessor professores[]){
 int matricula;
  printf("Digite a matrícula que deseja atualizar:\n");
  scanf("%d",&matricula);
  for(int i = 0; i < contagemProfessor; i++){
    if(matricula == professores[i].matriculaProfessor){
      printf("Atualize o nome:\n");
      getchar();
      fgets(professores[i].nomeProfessor, 50, stdin);
      printf("Atualize o cpf:\n");
      fgets(professores[i].cpfProfessor, 50, stdin);
      getchar();
      printf("Atualize o gênero:\n");
      scanf("%c", &professores[i].sexoProfessor);
      getchar();
      printf("Atualize a data de nascimento:\n");
      printf("Dia:\n");
      scanf("%d", &professores[i].nascimento.dia);
      getchar();
      printf("Mês:\n");
      scanf("%d", &professores[i].nascimento.mes);
      getchar();
      printf("Ano:\n");
      scanf("%d", &professores[i].nascimento.ano);
      getchar();
      printf("Professor atualizado com sucesso!!\n");
      }
  }
  return 0; 
}
int excluirDisciplina(int contagemDisciplina, Disciplina discs[]){
  int codigo;
  printf("Exclusão por Código\n");
  if(contagemDisciplina < 0){
    printf("Não há disciplinas.\n");
  }else{
    printf("EXCLUIR DISCIPLINA\n");
    printf("Digite o código:\n");
    scanf("%d", &codigo);
    for(int i = 0; i < contagemDisciplina; i++){
      if(codigo == discs[i].codigoDisciplina){
        for(int j = i; j< contagemDisciplina -1; j++){
          discs[j].codigoDisciplina = discs[j + 1].codigoDisciplina;
          copiaString(discs[j].nomeDisciplina, discs[j + 1].nomeDisciplina);
          discs[j].semestreDisciplina = discs[j + 1].semestreDisciplina;
          strcpy(discs[j].professorDisciplina,  discs[j + 1].professorDisciplina);
        }
        //contagemAluno--;
        printf("\nDisciplina excluída com sucesso!\n");
      }
    }
  }
   return contagemDisciplina;
}
int atualizarDisciplina(int contagemDisciplina, Disciplina discs[]){
   int codigo;
  printf("Digite o código da disciplina que deseja atualizar:\n");
  scanf("%d",&codigo);
  for(int i = 0; i < contagemDisciplina; i++){
    if(codigo == discs[i].codigoDisciplina){
      printf("Atualize o nome:\n");
      getchar();
      fgets(discs[i].nomeDisciplina, 50, stdin);
      printf("Atualize o semestre:\n");
      scanf("%d",&discs[i].semestreDisciplina);
      printf("Atualize o nome do professor:\n");
      getchar(); 
      fgets(discs[i].professorDisciplina, 50, stdin);
      printf("Disciplina atualizada com sucesso!!\n");
      }
  }
  return 0; 
}
int validarNascimentoAluno(int contagemAluno, Aluno alunos[]){
    if(alunos[contagemAluno].nascimento.dia > 31 || alunos[contagemAluno].nascimento.dia < 1 || alunos[contagemAluno].nascimento.mes > 12||alunos[contagemAluno].nascimento.mes < 1 || alunos[contagemAluno].nascimento.ano > 2023 || alunos[contagemAluno].nascimento.ano < 1) {
      printf("Diigite uma data válida\n");
      printf("Digite a data de nascimento\n");
      printf("\nDia:\n");
      scanf("%d", &alunos[contagemAluno].nascimento.dia);
      getchar();
      printf("Digite o mês de nascimento\n");
      printf("\nMês:\n");
      scanf("%d", &alunos[contagemAluno].nascimento.mes);
      getchar();
      printf("Digite o ano de nascimento\n");
      printf("\nAno: \n");
      scanf("%d", &alunos[contagemAluno].nascimento.ano);
      }
    return 0; 
}
