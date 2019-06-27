/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/
#include "funcoes.h"

double F_logistica(double n)
{
    double e = 2.71828182;
    double p = 0;
    p = 1/(1+exp((-1*n)));
    

    return p;
}
double F_mult(int p, double w)
{
    double s = 0;
    s = p * w;
    return s;
}
// entradas: vetor de elementos, vetor de pesos , deslocamento
// responsavel por fazer o somatorio com os pesos e o deslocamento do neuronio;
double F_aux(double *p, double *w, double b)
{
    double s=0;

    for (int i = 0; i < VET_FEQ; i++)
    {
        s += F_mult(p[i], w[i]);
    }
    printf(" b= %lf\n",b);
    s += b;
    return s;
}
// aloca neuronios e inicializa peso e deslocamento
// entrada: quantidade de neuronios peso
Neuronio *inicializa_neuronio(int qtd)
{
    Neuronio *neu;
    for (int i = 0; i < qtd; i++)
    {
        neu = (Neuronio *)malloc(sizeof(Neuronio) * qtd);
        
    }
    if (neu == NULL){
        printf("deu ruim no alocamento");
        exit(1);
    }
        for (int i = 0; i < qtd; i++)
    {
       
        inic_peso(neu[i].pesos);
        neu[i].deslocamento = inic_deslocamento();
    }


    return neu;
}

double *inic_peso(double *vet){
    
    for (int i = 0; i < TAMANHO_VET; i++)
    {   
        vet[i]= rand()%10;
    }
    return vet;
    
}
double inic_deslocamento(){
    return rand()%10;
}



// entrada:vetor de feature e camada inicial, camada oculta , numeros de neuronios da camada ouculta e neuronio final
// retorna o valor de saida de um neuronio
double F_neuronio(double *vet, Neuronio *camada1, Neuronio *camada2,int N_camada, Neuronio *n_f){
    double * aux_vet = (double*)malloc(sizeof(double)*TAMANHO_VET);
    double * aux_oculta = (double*)malloc(sizeof(double)*N_camada);
   for (int i = 0; i < VET_FEQ; i++)
   {
      
     camada1[i].saida = F_logistica(F_aux(vet, camada1[i].pesos, camada1[i].deslocamento));
     aux_vet[i] = camada1[i].saida;
   }
   // camada oculta
   for (int i = 0; i < N_camada; i++)
   {
       camada2[i].saida = F_logistica(F_aux(aux_vet, camada2[i].pesos, camada2[i].deslocamento));
       aux_vet[i] = camada2[i].saida;
   }
          n_f->saida = F_logistica(F_aux(aux_vet, n_f->pesos, n_f->deslocamento));

   free(aux_oculta);
   free(aux_vet);
   return n_f->saida; 
     
}
