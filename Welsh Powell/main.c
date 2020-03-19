///////////////////////////////////////////////////
//Algoritmo de Welsh Powell
///////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

void welshpowell(){
  //codigo do algoritmo welshpowell
  int matrizadj[11][11]={   //           a b c d e f g h i j k  //matriz de adjacencia usada pra representar o grafo
                                        {0,1,0,0,0,0,0,1,0,0,0},//a
                                        {1,0,0,1,0,0,0,0,0,0,0},//b
                                        {0,0,0,1,0,0,0,0,0,0,0},//c
                                        {0,1,1,0,0,0,0,0,1,0,1},//d
                                        {0,0,0,0,0,1,0,0,0,0,1},//e
                                        {0,0,0,0,1,0,1,0,0,0,0},//f
                                        {0,0,0,0,0,1,0,1,0,0,1},//g
                                        {1,0,0,0,0,0,1,0,1,1,1},//h
                                        {0,0,0,1,0,0,0,1,0,1,0},//i
                                        {0,0,0,0,0,0,0,1,1,0,1},//j
                                        {0,0,0,1,1,0,1,1,0,1,0} //k
  };

  int matrizcalculo[3][11]={//matriz usada para calcular o algoritmo
                                        {7,10,3,6,8,9,0,1,4,5,2},//representa os vertices alocados em forma decrecentes em relação ao grau de cada vértice
                                        {5,5,4,3,3,3,2,2,2,2,1},//número que representa o grau de cada vértice
                                        {0,0,0,0,0,0,0,0,0,0,0}//cor do vertice, 0 indica que inicia sem cor nenhuma
  };



  char vertnome[11] = {'H','K','D','G','I','J','A','B','E','F','C'};//vetor de indices usado na impressão do algoritmo, é estático

  int a, b, c;//variaveis usadas como controle no algoritmo
  int cor, aux;//variaveis usadas para definição das cores de cada vértice
  int x, y;//variaves usadas para fazer a impressão

  ///////////////////////////////////////////////////////////////////////////////////////////////////

  //laço que realiza o algoritmo, como os vertices sao pré-definidos e possuem ordem
  //então a condição de parada não precisa que se remova os vertices ja coloridos, apenas ir até o fim da matriz basta para finalizar
  for(a = 0, cor=0; a < 11; a++){
      if(matrizcalculo[2][a] == 0){//verifica se o vertice está sem cor, ou seja = 0
          cor++;//incrementa a cor
          matrizcalculo[2][a]=cor;//atribui a cor atual para o vertice atual
      }
      for(b = a+1; b < 11; b++){
          aux =1;
          if(matrizadj[matrizcalculo[0][a]][matrizcalculo[0][b]]==0 && matrizcalculo[2][b]==0){//verifica o vertice da matriz de calculo, na matriz de adjacencia. e se o vertice seguinte não foi colorido
              for(c = b-1 ; c >=0; c--){//recursivamente verifica na matriz de adjacencia a cor foi atribuida
                  if(matrizadj[matrizcalculo[0][b]][matrizcalculo[0][c]]!=0 && matrizcalculo[2][c]==cor){//verifica a cor dos vizinhos do vertice
                  aux = 0;
                  break;
                  }
              }
              if(aux){
                  matrizcalculo[2][b]=cor;//caso true atribui a cor ao vertice
              }

          }//A CONDIÇÃO DE PARADA DO ALGORITMO NÃO ENVOLVE REMOVER OS VERTICES COLORIDOS DE UMA FILA. O LAÇO É EXECUTADO TANTAS VEZES QUANTO NECESSÁRIAS PARA COLORIR TODOS OS VERTICES DO GRAFO
      }
  }


  printf("\nMatriz com o resultado do Algoritmo.\n\nLinha 1 - Indice do vertice\nLinha 2 - Indice numerico do vertice\n");
  printf("Linha 3 - Grau de cada vertice\nLinha 4 - Cor do vertice\n\n");

  for(x = 0; x < 11; x++){
    printf("%c\t",vertnome[x]);//imprime o cabeçalho da matriz final, para indicar os nomes dos vertices na matriz
  }
  printf("\n");

//For que imprime todos os valores da matriz de calculo do algoritmo, já com os resultados finais
  for(x = 0; x < 3; x++){//imprime as 3 linhas da matriz de calculo
      for(y = 0; y < 11; y++){//imprime todos os valores da linha atual
          printf("%d\t",matrizcalculo[x][y]);
      }
      printf("\n");
  }
  printf("\n\n");
}

//menu
int menu(){

    int aux=1;// variavel que seleciona um item o menu

    while(aux){

      //imprime cabeçalho do programa, padrão de todos os trabalhos
      printf("_______________________________________________________________________\n");
      printf("_______________________________________________________________________\n");
      printf("\t\tJovani de Souza\n\n");
      printf("\t\tAlgoritmo de Welsh Powell\n");
      printf("_______________________________________________________________________\n");
      printf("_______________________________________________________________________\n");
      printf("\n Pressione 0 para sair\n\n");
      printf("\n Pressione 1 para o  exercicio 1 - Welsh Powell\n\n");
      printf("_______________________________________________________________________\n");
      printf("_______________________________________________________________________\n");

      //Pega um valor do teclado para usar como escolha do menu
      scanf("%d", &aux);

      switch(aux){

        case(0):{
          return 0;
        }
        case(1):{
          welshpowell();
          break;
        }
      }

    }

}

//main
int main(){

    menu();
}
