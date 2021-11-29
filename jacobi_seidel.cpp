#include<iostream>
#include<iomanip>
#include<math.h>
#include <bits/stdc++.h>

/*
------------------------------------------------
2x + 5y = -3        Sistema a ser trabalhado
3x + y = 2

f1 x = (-3 - 5*y)/2
f2 y= 2 - 3*x
-------------------------------------------------
3x + y = 2          Sistema com linhas permutadas
2x + 5y = -3 

f1 x = (2 - y)/3
f2 y = (-3 -2*x)/5
-------------------------------------------------
*/

#define f1(x,y)  (2 - y)/3
#define f2(x,y)  (-3 -2*x)/5

float returnMax(float vetor[], int numElements) {
   
   float max = vetor[0];
   
   for (int i=0; i < numElements; i++) {
      if (vetor[i] >= max ) {
         max = vetor[i];
      }
   }

   return max;
}

/* Tratamento de dados */
void jacobiIteration(float e)             // Função que recebe como parametro a precisão
{
   float x0=0, y0=0;                      // Caso inicial
   float x1, y1, e1, e2;                  // Definindo variaveis
   int step=0;                            // Número de iterações

   /* Definindo a precisão para as casas decimais */
   std::cout<< std::setprecision(6)<< std::fixed;

   std::cout<<"It. \t x \t\t y \t\t Erro: \t\t e1 \t\t e2"<< std::endl;    // It. = 0 ---> Caso inicial

   float maxTeps = 0;
   float maxError = 0;

   do
   {
   /* Atribuição de valores para os proximos x, y, z */
   x1 = f1(x0,y0);
   y1 = f2(x0,y0);

   /* Erro */
   e1 = fabs(x0-x1);
   e2 = fabs(y0-y1);

   std::cout<< step<<"\t"<< x1<<"\t"<< y1<<"\t\t\t"<< e1 <<"\t"<< e2 <<"\t"<< std::endl;

   step++;

   /* Redefinindo valore para a proxima iteração */
   x0 = x1;
   y0 = y1;

   float vTeps[] = {fabs(x0), fabs(y0)};
   float vError[] = {e1, e2};

   maxTeps = returnMax(vTeps, 2);
   maxError = returnMax(vError, 2);

   }while((maxError/maxTeps) > e);

   std::cout<<"Solução: x = "<< x1 <<", y = "<< y1 << std::endl;

}

/* Tratamento de dados */
void seidelIteration(float e)             // Função que recebe como parametro a precisão
{
    float x0=0, y0=0;               // Caso inicial
    float x1, y1, e1, e2;          // Definindo variaveis
    int step=0;                            // Número de iterações

    /* Definindo a precisão para as casas decimais */
    std::cout<< std::setprecision(6)<< std::fixed;

    std::cout<<"It. \t x \t\t y \t\t Erro: \t\t e1 \t\t e2"<< std::endl;    // It. = 0 ---> Caso inicial

    float maxTeps = 0;
    float maxError = 0;

    do
    {
    /* Atribuição de valores para os proximos x, y, z */
    if (step == 0) {
        x1 = f1(x0,y0);
        y1 = f2(x0,y0);
    }
    else {
        x1 = f1(x0,y0);
        y1 = f2(x1,y0);
    }

    /* Erro */
    e1 = fabs(x0-x1);
    e2 = fabs(y0-y1);

    std::cout<< step<<"\t"<< x1<<"\t"<< y1<<"\t\t\t"<< e1 <<"\t"<< e2 <<"\t" << std::endl;

    step++;

    /* Redefinindo valore para a proxima iteração */
    x0 = x1;
    y0 = y1;

    float vTeps[] = {fabs(x0), fabs(y0)};
    float vError[] = {e1, e2};

    maxTeps = returnMax(vTeps, 2);
    maxError = returnMax(vError, 2);

    }while((maxError/maxTeps) > e);

    std::cout<<"Solução: x = "<< x1 <<", y = "<< y1 << std::endl;

}