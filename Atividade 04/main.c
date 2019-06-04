/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/

// Síntese
// Objetivo: Organizar fila de vôos de aeroporto
// Entrada:
// Saída: log dos acontecimentos do aeroporto

#include "fila.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#define UNI_TIME 5 // unidade de tempo 1 uma unidade = 5 mim
#define MAX_AVI 64 // maximo de avioes
#define MIM_AVI 20 // mminimo de avioes

int inic_aletorio(int NVoos, int *NAproximacoes, int *NDecolagens);
fila inic_lista( int *NAproximacoes, int *NDecolagens, fila aviao, char *cod_Voos, int *NVoos);
int* inic_combustivel(int NAproximacoes, int* comb);
int main()
{
  //Declarações:
  char *cod_Voos[64] = {"VG3001", "JJ4404", "LN7001", "TG1501", "GL7602", "TT1010", "AZ1009",
                        "AZ1008", "AZ1010", "TG1506", "VG3002", "JJ4402", "GL7603", "RL7880",
                        "AL0012", "TT4544", "TG1505", "VG3003", "JJ4403", "JJ4401", "LN7002",
                        "AZ1002", "AZ1007", "GL7604", "AZ1006", "TG1503", "AZ1003", "JJ4403",
                        "AZ1001", "LN7003", "AZ1004", "TG1504", "AZ1005", "TG1502", "GL7601",
                        "TT4500", "RL7801", "JJ4410", "GL7607", "AL0029", "VV3390", "VV3392",
                        "GF4681", "GF4690", "AZ1020", "JJ4435", "VG3010", "LF0920", "AZ1065",
                        "LF0978", "RL7867", "TT4502", "GL7645", "LF0932", "JJ4434", "TG1510",
                        "TT1020", "AZ1098", "BA2312", "VG3030", "BA2304", "KL5609", "KL5610",
                        "KL5611"};

  int NVoos;         // numero de voos (20 ate 64) NVoos = NAproximaçoes + NDecolagens
  int NAproximacoes; // numero de avioes querendo pousar (10 32)
  int NDecolagens;   // avioes querendo decolar (10 a 32)
  fila oi;
  fila aviao;
  data ale;
  list_enc bagaca;
  int i;
  
  //Instruções:
  aviao = inic_lista( &NAproximacoes,  &NDecolagens,  aviao,  *cod_Voos, &NVoos);
  // ale.nome[0] = 'a';
  // ale.nome[1] = '\0';

  // oi = criaFilaVazia();
  // oi = pushF(oi, ale);
  // oi = pushF(oi, ale);
  // oi = pushF(oi, ale);
  // ale.nome[0] = 'a';
  // ale.nome[1] = 'b';
  // ale.nome[2] = 'a';
  // ale.nome[3] = '\0';
  // oi = pushF(oi, ale);
  // bagaca = *(oi.fim);
  // printf("%s\n", bagaca.dados.nome);
  // bagaca = *(oi.ini);
  // printf("%s\n", bagaca.dados.nome);
  // bagaca = *(bagaca.prox);
  // printf("%s\n", bagaca.dados.nome);
  // bagaca = *(bagaca.prox);
  // printf("%s\n", bagaca.dados.nome);
  // bagaca = *(bagaca.prox);
  // printf("%s\n", bagaca.dados.nome);
  // printf("%d\n", tamanhoFila(oi));
  // ale = popF(&oi);
  // printf("%s\n", ale.nome);
  // ale = popF(&oi);
  // printf("%s\n", ale.nome);
  // ale = popF(&oi);
  // printf("%s\n", ale.nome);
  // ale = popF(&oi);
  // printf("%s\n", ale.nome);
  // printf("%p\n", oi.fim);

  // oi = liberaFila(oi);

  //printaInicio();
  //printaStatus();
  
  printf("total =%d\n", NVoos);
  printf("aprox =%d\n", NAproximacoes);
  printf("decola =%d\n", NDecolagens);
  printf(" tamanho %d \n",tamanhoFila(aviao));
  return 0;
}


// Objetivo: inicializar numero de voos e decolagens
// Entrada: numero de voos ,decolagens e total
// Saída: total
int inic_aletorio(int NVoos, int *NAproximacoes, int *NDecolagens)
{
  srand(time(NULL));

  *NAproximacoes = (rand() % 23)+ 10;
  *NDecolagens = (rand() % 23)+ 10;
  return NVoos = *NAproximacoes + *NDecolagens;
}

// Objetivo: iniciliza valores de combustivel
// Entrada:numero de decolagens e combustivel
// Saída: combustivel
int* inic_combustivel(int NAproximacoes, int *comb)
{
  
  for (int i = 0; i < NAproximacoes; i++)
  {
    comb[i] = rand() % 13;
  }
  return comb;
}
// Objetivo: inicializa fila com os valores de voo
// Entrada: numero de aproximaçoes , decolagens , fila , code de voos e total de voos 
// Saída: fila;
fila inic_lista(int *NAproximacoes, int *NDecolagens, fila aviao, char *cod_Voos, int *NVoos)
{
 int comb[32];
  *NVoos = inic_aletorio(*NVoos,  NAproximacoes,  NDecolagens);
  inic_combustivel(*NAproximacoes, comb );
  data d;
  int i, al_cod;
  for (i = 0; i < *NAproximacoes; i++)
  {

    strcpy(d.codigo, (cod_Voos+i));
    d.sentido = 'A';
    d.combustivel = comb[i];
    
    aviao = pushF(aviao, d);
  }
  for (i = 0; i < *NDecolagens; i++)
  {
    strcpy(d.codigo, (cod_Voos+ i + *NAproximacoes));
    d.sentido = 'D';
    aviao = pushF(aviao, d);
  }
  return aviao;
}