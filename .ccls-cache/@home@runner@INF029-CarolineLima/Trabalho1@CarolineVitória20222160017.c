// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do
//  trabalho

//  ----- Dados do Aluno -----
//  Nome: Caroline Matilde Lima Vitória
//  email: carol.lima.vitoria@gmail.com
//  Matrícula: 20222160017
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include "CarolineVitória20222160017.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarData(DataQuebrada dataquebrada);
/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y) {
  int soma;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x) { // função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}

int teste(int a) {
  int val;
  if (a == 2)
    val = 3;
  else
    val = 4;

  return val;
}

DataQuebrada quebraData(char data[]) {
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i;

  for (i = 0; data[i] != '/'; i++) {
    sDia[i] = data[i];
  }
  if (i == 1 || i == 2) { // testa se tem 1 ou dois digitos
    sDia[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

  int j = i + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++) {
    sMes[i] = data[j];
    i++;
  }

  if (i == 1 || i == 2) { // testa se tem 1 ou dois digitos
    sMes[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

  j = j + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '\0'; j++) {
    sAno[i] = data[j];
    i++;
  }

  if (i == 2 || i == 4) { // testa se tem 2 ou 4 digitos
    sAno[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno);

  dq.valido = 1;

  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia,
mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa
podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]) { // questão pronta
  int datavalida = 1;
  DataQuebrada dataQuebrada = quebraData(data);
  if (dataQuebrada.valido == 0)
    return 0;

  // printf("%s\n", data);
  return validarData(dataQuebrada);
}
int validarData(DataQuebrada dataquebrada) {
  if (dataquebrada.iAno > 1 &&
      dataquebrada.iAno <
          100) { // aqui é para caso digitem apenas duas casas do ano, ex: "95"
    dataquebrada.iAno = dataquebrada.iAno + 2000;
  }
  if (dataquebrada.iDia < 1 || dataquebrada.iDia > 31 || dataquebrada.iAno < 0)
    return 0;
  switch (dataquebrada.iMes) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12: {
    if (dataquebrada.iDia > 31)
      return 0;
    break;
  }
  case 4:
  case 6:
  case 9:
  case 11: {
    if (dataquebrada.iDia > 30)
      return 0;
    break;
  }
  case 2: {
    if ((dataquebrada.iAno % 4 == 0 && dataquebrada.iAno % 100 != 0) ||
        dataquebrada.iAno % 400 == 0) {
      if (dataquebrada.iDia > 29) {
        return 0;
      }
    } else if (dataquebrada.iDia > 28) {
      return 0;
    }
  } break;
  default:
    return 0;
  }
  return 1;
}
/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis
 valores abaixo 1 -> cálculo de diferença realizado com sucesso 2 -> datainicial
 inválida 3 -> datafinal inválida 4 -> datainicial > datafinal Caso o cálculo
 esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos
 com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[]) // quase pronta
{
  // calcule os dados e armazene nas três variáveis a seguir
  DiasMesesAnos dma;
  if (q1(datainicial) == 0) {
    dma.retorno = 2;
    return dma;
  } else if (q1(datafinal) == 0) {
    dma.retorno = 3;
    return dma;
  }
  DataQuebrada data1 = quebraData(datainicial);
  DataQuebrada data2 = quebraData(datafinal);
  if (data1.iAno > data2.iAno) {
    dma.retorno = 4;
    return dma;
  } else if (data1.iAno == data2.iAno && data1.iMes > data2.iMes) {
    dma.retorno = 4;
    return dma;
  } else if (data1.iAno == data2.iAno && data1.iMes == data2.iMes &&
             data1.iDia > data2.iDia) {
    dma.retorno = 4;
    return dma;
  }
  int anos = data2.iAno - data1.iAno;
  int meses = data2.iMes - data1.iMes;
  int dias = data2.iDia - data1.iDia;

  if (dias < 0) {
    switch (data2.iMes) {
    case 1:
      dias += 31;
      break;
    case 2:
      if (data2.iAno % 4 == 0 &&
          (data2.iAno % 100 != 0 || data2.iAno % 400 == 0)) {
        dias += 29;
      } else {
        dias += 28;
      }
      break;
    case 3:
      dias += 31;
      break;
    case 4:
      dias += 30;
      break;
    case 5:
      dias += 31;
      break;
    case 6:
      dias += 30;
      break;
    case 7:
      dias += 31;
      break;
    case 8:
      dias += 31;
      break;
    case 9:
      dias += 30;
      break;
    case 10:
      dias += 31;
      break;
    case 11:
      dias += 30;
      break;
    case 12:
      dias += 31;
      break;
    }
    meses--;
    if (meses < 0) {
      meses += 12;
      anos--;
    }
  }
  dma.qtdDias = dias;
  dma.qtdMeses = meses;
  dma.qtdAnos = anos;
  dma.retorno = 1;
  return dma;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa
 Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar
 diferenças entre maiúsculos e minúsculos. Se isCaseSensitive != 1, a pesquisa
 não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive) // questão pronta
{
  int qtdOcorrencias = 0;
  for (int i = 0; texto[i] != '\0'; i++) {
    if (isCaseSensitive == 1) {
      if (c == texto[i])
        qtdOcorrencias++;
    } else if (texto[i] == c || texto[i] == c - 32 ||
               texto[i] == c + 32) { // 32 por conta da tabela ASCII
      qtdOcorrencias++;
    }
  }
  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros
 (posicoes) que irá guardar as posições de início e fim de cada ocorrência da
 palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída
 correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do
 vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve
 ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a
 segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente.
 Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como
 há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da
 seguinte forma: posicoes[0] = 13; posicoes[1] = 16; Observe que o índice da
 posição no texto deve começar ser contado a partir de 1. O retorno da função,
 n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30]) {
  for (int i = 0; strTexto[i] != '\0';
       i++) { // remove o caractere acentuado de strBusca e strTexto movendo-os
              // para a esquerda
    if (strTexto[i] == -61) {
      for (int j = i; strTexto[j] != '\0'; j++) {
        strTexto[j] = strTexto[j + 1];
      }
    }
  }
  for (int i = 0; strBusca[i] != '\0'; i++) {
    if (strBusca[i] == -61) {
      for (int j = i; strBusca[j] != '\0'; j++) {
        strBusca[j] = strBusca[j + 1];
      }
    }
  }
  int qtdOcorrencias = 0;
  int index = 0;
  for (int i = 0; i < strlen(strTexto); i++) {
    if (strBusca[0] == strTexto[i]) {
      int contador = 1;
      for (int j = 1; j < strlen(strBusca); j++) {
        if (strBusca[j] == strTexto[i + j]) {
          contador++;
        } else
          break;
      }
      if (contador == strlen(strBusca)) {
        qtdOcorrencias++;
        posicoes[index] = i + 1; // i + 1 pq os indices começam em 0
        posicoes[index + 1] =
            i + strlen(strBusca); // armazena posição final da ocorrência
        index +=
            2; // incrementa o índice do vetor de posições, incremento com 2
               // porque a string ocupa duas posiçoes no vetor: inicial e final.
               // Assim, é reservado 2 posições para a próxima ocorrência.
      }
    }
  }
  return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num) // questão pronta
{
  int resto;
  int inverso = 0;
  while (num != 0) {
    resto = num % 10;
    inverso = inverso * 10 + resto;
    num /= 10;
  }
  return inverso;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca) // questão pronta
{
  int numDigitosBusca = 0, numDigitosBase = 0;
  int qtdOcorrencias = 0;
  int tmpBusca = numerobusca;
  int tmpBase = numerobase;
  int digitoBusca, digitoBase;

  while (tmpBusca > 0) { // aqui é o cálculo do número de digitos do número
                         // busca
    numDigitosBusca++;
    tmpBusca /= 10;
  }
  while (tmpBase > 0) {
    digitoBase = tmpBase % 10; // ultimo digito do numero base
    if (digitoBase ==
        numerobusca %
            10) { // verifica se é igual ao primeiro digito do numero busca
      numDigitosBase = 1;
      tmpBusca = numerobusca / 10;
      tmpBase /= 10;
      while (numDigitosBase < numDigitosBusca) {
        digitoBusca = tmpBusca % 10;
        digitoBase = tmpBase % 10;
        if (digitoBusca != digitoBase) {
          break;
        }
        numDigitosBase++;
        tmpBusca /= 10;
        tmpBase /= 10;
      }
      if (numDigitosBase ==
          numDigitosBusca) { // se todos os dígitos coincidirem, eu incremento a
                             // qtd de ocorrências
        qtdOcorrencias++;
      }
      tmpBusca = numerobusca; // volto o número de busca para o inicio;
    } else { // se não for igual eu avanço para o próximo digito do númerobase
      tmpBase /= 10;
    }
  }
  return qtdOcorrencias;
}
// 2345

// 34