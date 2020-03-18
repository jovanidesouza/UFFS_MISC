
//algoritmo BFS
//algoritmo de Dijkstra

//Jovani de souza

#include<stdio.h>

//inicio da função bfs/////////////////////////////////////////////////////////////////////////////////////
void buscalargura(){

  int a, b, count = 0, controle = 0;

                         // matrazi adj
                         //  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  z
  int matrizadj[21][21] = { {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //a
                            {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //b
                            {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //c
                            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //d
                            {0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //e
                            {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //f
                            {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //g
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //h
                            {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //i
                            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},  //j
                            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},  //k
                            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},  //l
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},  //m
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},  //n
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},  //o
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},  //p
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0},  //q
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},  //r
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1},  //s
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},  //t
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0}   //z
                          };
//vetor de nomes para imprimir o menor caminho
  char vnomes[21] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','Z'};

// matriz
  int imprime_bfs[4][21] = {  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//LINHA DOS CUSTOS
                              {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//LINHA DOS VERTICES ANTERIORES
                              {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//LINHA DA COR
                              {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}// LINHA FILA
                           };
  a = 0;
  b = 0;

  while(count < 20){ // percorre a  matriz faz isso 20 vezes pq ja é iniciado no vertice A
    for(b = 0; b < 21; b++){ // FOR QUE VEREFICA TODOS OS VIZINHOS DO VERTICE ATUAL
      if(matrizadj[a][b] != 0 && imprime_bfs[2][b] == 0){ // se na posição da matriz adj existe aresta(=!0) e na matriz imprime = branco
        imprime_bfs[0][b] = (imprime_bfs[0][a]) +1; //substiu o valor da matriz imprimebfs pelo menor custo
        imprime_bfs[3][controle] = b+1; //linha 3 = fila de vertices vizinhos - recebe coluna (0+1)
        controle++;// variavel de referencia para a fila de vizinhos/numero de vizinhos
        imprime_bfs[2][b] = 1;//atrubui cinza
        imprime_bfs[1][b] = a+1; //linha 1 recebe a referencia do vertice anterior
      }
    }
    for(a = 0; a <= controle; a++){
      if(imprime_bfs[3][a]!=0){
        b = a;
        a = imprime_bfs[3][a]-1;
        count++;
        imprime_bfs[2][a] = 2;//seta o verice como preto
        imprime_bfs[3][b] = 0;//seta a fila de vizinhos como zero
        break;
      }
    }
  }
  printf("\nSolucao com BFS\n");
  printf("Matriz com vertice, custo, vertice anterior e cor.\n");

  printf("\n-a--b--c--d--e--f--g--h--i--j--k--l--m--n--o--p--q--r--s--t--z\n");

  for(a = 0; a < 3; a++){//laço usado para imprimir a matriz com os custos e vertices
    for(b = 0; b < 21; b++){
      printf(" %d ",imprime_bfs[a][b]);
    }
    printf("\n");
  }

  a = 20;// a recebe 20 para ser usado na impressao do caminho de trás pra frente
  printf("\nMenor caminho de A ate Z\n\n");
  controle = 0;
  while(b != 0){
    b = a;
    controle++;
    imprime_bfs[3][controle] = a;
    a = imprime_bfs[1][a]-1;
  }
  while(controle > 0){
    b = imprime_bfs[3][controle--];
    printf(" %c ", vnomes[b]);
  }
  printf("\n");
}

//////////////////////////fim função bfs//////////////////////////////////////////////////////////////////////////////////////////////

int verifica(int * vetor, int valor){//função que verifica a existencia de um valor no vetor de vertices abertos
  int a;                             //retorna 1 se encontrar o valor e retorna 0 se não encontrar
  for(a = 0; a < 7; a++){
    if(vetor[a]== valor)
        return 1;
  }
  return 0;
}

void removevetor(int * vetor, int valor){// função que verifica um valor no vetor, se encontrar o valor, substitui por 0, usado para liberar o vetor de abertos
  int a;
  for(a = 0; a < 7; a++){
    if(vetor[a] == valor)
      vetor[a] = 0;
  }
}

int achamenor(int * vetor, int * v_aberto){
  int a, b=0, menor = 1000;

  for(a = 0; a < 7; a++)
    if(vetor[a]!=0  && vetor[a] < menor && verifica(v_aberto, a)){//se o valor for diferente de 0, se o valor sor menor que 1000 e se o valor estiver no vetor de abertos
      menor = vetor[a];                                          //então menor recebe o novo valor
      b = a;
    }                                                           //no fim a função retorna esse menor valor
  return b;
}

void calculadijkstra(){

  char vnomes[7] = {'A','B','C','D','E','F','G'};//vetor com o nome dos vertices
  int v_aberto[7] = {0, 1, 2, 3, 4, 5, 6}; //vetor de vertices abertos
  int v_aux[7];
  int a = 0, x=0, b, controle = 7;// vartiaveis auxiliares



  int matrizadj[7][7] =  {{0, 7, 0, 5, 0, 0, 0},//matriz de adjacencia do segundo grafo
                          {7, 0, 8, 9, 7, 0, 0},
                          {0, 8, 0, 0, 5, 0, 0},
                          {5, 9, 0, 0, 15, 6, 0}, //////////////////////////////
                          {0, 7, 5, 15, 0, 8, 9},
                          {0, 0, 0, 6, 8, 0, 11}, //////////////////////////////
                          {0, 0, 0, 0, 9, 11, 0}
                         };

                         //matrtiz para calcular e imprimir dijkstra
  int matrizdij[3][7] = {{0, 1, 2, 3, 4, 5, 6},
                         {0, 1000, 1000, 1000, 1000, 1000, 1000},
                         {0, 0, 0, 0, 0, 0, 0}
                        };





  while(controle >= 0){//calcula o dijkstra
      for(b = 0; b < 7; b++){
        if(matrizadj[a][b]!=0 && verifica(v_aberto,b) && (matrizdij[1][b] > (matrizadj[a][b]+matrizdij[1][a]))){// se o valor atual for diferente de 0 e o valor de b estiver no vetor de abertos e se o custo é menor que 1000
          matrizdij[1][b] = matrizadj[a][b] +matrizdij[1][a];// assume novo custo
          matrizdij[2][b] = a;//guarda vertice anterior
        }
      }
      removevetor(v_aberto, a);//remove o vertice do vetor de abertos
      controle--;
      a = achamenor(matrizdij[1], v_aberto);//a recebe o valor do menor vizinho
  }

  printf("Solucao com Dijkstra\n");
  printf("Matriz com vertice, custo e vertice anterior\n\n");
  printf("\n\tA\tB\tC\tD\tE\tF\tG\n");
  for(a = 1; a < 3; a++){//laço que imprime a matriz principal
    for(b = 0; b < 7; b++){
      printf("\t%d",matrizdij[a][b]);
    }
    printf("\n");
  }


  a = b = 6;

  while(b != 0){// usa v_aux para salvar o caminho de tras pra frente fazendo o backtracking
    b = a;
    v_aux[x] = b;
    x++;
    a = matrizdij[2][b];
  }

  printf("\nMenor caminho de A ate G\n\n");
  for(a = x-1; a >=0 ; a--){
    printf("%c ",vnomes[v_aux[a]] );//imprime o caminho de A até G
  }
  printf("\n");

  printf("custo do caminho: %d\n", matrizdij[1][6]);//imprime o custo do caminho de A até G
}



//////////////////fim da dijkstra /////////////////////////////////////////////////////////////////////////////////////////////

int menu(){

    int aux=1;// variavel que seleciona um item o menu

    while(aux){

      //imprime cabeçalho do programa
      printf("_______________________________________________________________________\n");
      printf("_______________________________________________________________________\n");
      printf("\tJovani de Souza & Duan Pedroso da Silva\n\n");
      printf("\t\tBusca em largura e Dijkstra\n");
      printf("_______________________________________________________________________\n");
      printf("_______________________________________________________________________\n");
      printf("\n Pressione 0 para sair\n\n");
      printf("\n Pressione 1 para o  exercicio 1 - BFS\n\n");
      printf("\n Pressione 2 para o  exercicio 2 - Dijkstra\n\n");
      printf("_______________________________________________________________________\n");
      printf("_______________________________________________________________________\n");

      //Pega um valor do teclado para usar como escolha do menu
      scanf("%d", &aux);

      switch(aux){

        case(0):{
          return 0;
        }
        case(1):{
          buscalargura();
          break;
        }
        case(2):{
          calculadijkstra();
          break;
        }
      }

    }


}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){

    menu();
}
