///////////////////////////////////////////////////
//Jovani de Souza
//Algoritmo de Kruskal e Prim aplicado em Grafos
///////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void kruskal(){//função que faz o exercicio 1, algoritmo de kruskal

  int vetorver[8]={-1,-1,-1,-1,-1,-1,-1,-1}; //VETOR AUX

  int matrizkruskal[3][11] = {
                              {2,3,3,4,4,7,7,7,8,8,8}, //custos das arestas
                              {6,0,0,0,5,4,4,5,2,2,3}, //representa o vertice "origem"
                              {7,1,3,2,6,6,7,7,4,5,5}  //representa o outro vertice que compoe a aresta
  };

  int vert_i, vert_j,  auxi=0, auxj=0, x=0, x1, custo = 0; // DECLARAÇÃO DAS VARIAVEIS

  printf("\nResultado final do Kruskal\n");
  printf("\nvertice i, vertice j, custo da aresta\n\n");

  for(x = 0; x < 11; x++){//for para percorrer a matriz do kruskal


      vert_i=matrizkruskal[1][x];//vert_i RECEBE O VALOR DA PRIMEIRA LINHA DOS VERTICES NA POSIÇÃO X
      vert_j=matrizkruskal[2][x];//vert_j RECEBE O VALOR DA SEGUNDA LINHA DOS VERTICES NA POSIÇÃO X

      auxi=vert_i;// auxi RECEBE O VALOR CONTINDO EM vert_i
      auxj=vert_j;// auxj RECEBE O VALOR CONTIDO EM vert_j

      while((auxi = vetorver[auxi])>0){// compara se posição no vertor é maior do que 0
        vert_i = auxi;
      };
      while((auxj = vetorver[auxj])>0){ // compara se posição no vertor é maior do que 0
        vert_j = auxj;
      };



      if(auxi>=auxj && vert_i!=vert_j){ //SE auxi MAIOR OU IGUAL A auxj E vert_i DIFERENTE DE vert_j

          printf("%d--%d------", matrizkruskal[1][x],matrizkruskal[2][x]); //PRINTA OS VETORES - LINHA 1 E LINHA 2
          printf("%d\n",matrizkruskal[0][x]); // PRINTA o custo da aresta
          vetorver[vert_j] = vetorver[vert_i] + vetorver[vert_j]; //VETOR DE Vertices EM vert_j = VetorVer EM vert_i + VetorVer EM vert_j
          vetorver[vert_i] = vert_j; // vert_i=vert_j
          custo+=matrizkruskal[0][x];//incrementa o custo final

      }else if(vert_i<vert_j){
          printf("%d--%d------", matrizkruskal[1][x],matrizkruskal[2][x]); //PRINTA OS VETORES - LINHA 1 E LINHA 2
          printf("%d\n" ,matrizkruskal[0][x]); //PRINTA A RESTA E CUSTO
           vetorver[vert_i] = vetorver[vert_i] + vetorver[vert_j]; //VETOR DE VALORESM E vert_i = VV EM vert_i + VV EM vert_j
          vetorver[vert_j] = vert_i; //vert_j=vert_i
          custo+=matrizkruskal[0][x];//incrementa o custo

      }
  }

printf("\nCusto total da arvore: %d\n", custo);

};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int encontramenor(int * vetorvalores, int * vabertos){//recebe o vetor de custos das arestas e o vetor de vertices abertos
    int x, y = -1, valor = 10;
    for(x = 0; x < 8; x++)//passa pelos vetores
        if(vetorvalores[x] < valor && vabertos[x] != -1){//verifica se o valor do custo é menor que 10 e se o vetor de abertos é diferente de -1
            y = x;//atribui sempre o menor valor para y
            valor = vetorvalores[x];//atualiza o menor valor sempre para comparar
        }
    return y;//retorna o menor valor encontrado no vetor de custos
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void prim(){//função que faz o ecercicio 2, algoritmo de prim
                            //   A B C D E F G H  //MATRIZ ADJ DO GRAFO PARA PRIM
  int matrizadj[8][8] = {   //   0 1 2 3 4 5 6 7
                                {0,2,0,6,5,0,0,0},  //0/A
                                {2,0,7,7,0,0,0,0},  //1/B
                                {0,7,0,0,6,2,0,0},  //2/C
                                {6,7,0,0,0,0,0,0},  //3/D
                                {5,0,6,0,0,0,4,5},  //4/E
                                {0,0,2,0,0,0,4,6},  //5/F
                                {0,0,0,0,4,4,0,1},  //6/G
                                {0,0,0,0,5,6,1,0},  //7/H
                          };


  int matrizprim[3][8] = {      //matriz para calcular o prim // exemplo do slide
                                {0,1,2,3,4,5,6,7},//vertice atual
                                {0,10,10,10,10,10,10,10},//valor da menor aresta que liga so dois vertices
                                {-1,-1,-1,-1,-1,-1,-1,-1}//vertice anterior, inicia com -1 e vai sendo substituido pelo vertice que tem a menor aresta em comum
                          };


  int vabertos[8] = {0,1,2,3,4,5,6,7};//vetor com os vertices abertos, que ainda precisam ser verificados
  int vatual = 0;// flag usada para percorrer o grafo, indica o vertice atual
  int x, y;//auxiliares
  int custototal=0;

  while(-1 != (vatual=encontramenor(matrizprim[1],vabertos))){//realiza o passo a passo do algoritmo enquanto o vertice atual fou diferente de -1
      for(y = 0; y < 8; y++){//passa pela linha inteira
          if(matrizadj[vatual][y] != 0){//verifica se o valor é diferente de 0, pois 0 indica que nao existe aresta
              if(matrizprim[1][y] > matrizadj[vatual][y] && vabertos[y] != -1){//se existir um valor, verifica o custo atual (10) é amior que o encontrado e também se o vetor de acertos não é -1
                  matrizprim[1][y] = matrizadj[vatual][y];//atribui o custo, substituindo o (10) e depois o valor maior
                  matrizprim[2][y] = vatual;//atualiza o vertice origem da aresta
              }
              vabertos[vatual] = -1;//remove o vertice do vetor de abertos
          }
      }
  }

  for(x=0; x<8; x++){//soma o custo total da arvore, passa pela linha dos custos somando tudo em custototal
    custototal=custototal+matrizprim[1][x];
  }

  printf("\nMatriz com resultado do algoritmo Prim:\n");
  printf("\nvertice atual, custo da aresta, vertice origem\n\n");

  for(x = 0; x < 3; x++){//for que imprime na tela a matriz final com vertices/arestas e os custos
      for(y = 0; y < 8; y++)
          printf("%d\t",matrizprim[x][y]);
      printf("\n");
  }

  printf("\nCusto total da arvore: %d\n", custototal);//imprime o custo total da arvore

};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//menu
int menu(){

    int aux=1;// variavel que seleciona um item o menu

    while(aux){

      //imprime cabeçalho do programa
      printf("_______________________________________________________________________\n");
      printf("_______________________________________________________________________\n");
      printf("\tJovani de Souza & Duan Pedroso da Silva\n\n");
      printf("\t\tAlgoritmos de Kruskal e Prim\n");
      printf("_______________________________________________________________________\n");
      printf("_______________________________________________________________________\n");
      printf("\n Pressione 0 para sair\n\n");
      printf("\n Pressione 1 para o  exercicio 1 - Kruskal\n\n");
      printf("\n Pressione 2 para o  exercicio 2 - Prim\n\n");
      printf("_______________________________________________________________________\n");
      printf("_______________________________________________________________________\n");

      //Pega um valor do teclado para usar como escolha do menu
      scanf("%d", &aux);

      switch(aux){

        case(0):{
          return 0;
        }
        case(1):{
          kruskal();
          break;
        }
        case(2):{
          prim();
          break;
        }
      }

    }


}

//main
int main(){

    menu();
}
