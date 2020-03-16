/*
jovani de souza
arvore PV. preta-vermelha
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

struct noh
{
    int numero_arvore;
    char cor;
    struct noh *pai;
    struct noh *esquerda;
    struct noh *direita;
};

typedef struct noh nohVP;

// Prototipo das funçoes
nohVP* criaNovoNoh();
nohVP* inserir_Novo_Noh_PV(nohVP **Arvore_PV, nohVP *noh);
nohVP* sucessorVP(nohVP *noh);
nohVP* maximoVP(nohVP *noh);
nohVP* minimoVP(nohVP *noh);
nohVP* localizar_Noh_Arvore(nohVP* noh, int numero_arvore);
nohVP* rotacaoDireitaEsquerda(nohVP* arvore);
nohVP* rotacaoEsquerdaDireita(nohVP*arvore);
nohVP *removerVP(nohVP **Arvore_PV, nohVP *noh);

void rotacaoEsquerda(nohVP **Arvore_PV, nohVP *noh);
void rotacaoDireita(nohVP **Arvore_PV, nohVP *noh);
void inserirCorVP(nohVP **Arvore_PV, nohVP *noh);
void removerCorVP(nohVP **Arvore_PV, nohVP *noh);
void visitarEmOrdem(nohVP* Arvore_PV);
void mostraDadosNoh(nohVP* noh);

int menu();
int calcularAlturaPreta(nohVP *noh);
int numteclado();


nohVP *vazio = NULL;

int main(){

    nohVP *Arvore_PV = NULL;
    nohVP *aux;
    int valor, altura, opc;

    vazio = (nohVP*)malloc(sizeof(nohVP));
    vazio->pai = Arvore_PV;
    vazio->direita = vazio->esquerda = vazio;

    int i=0,j;

    srand( (unsigned)time(NULL) );

    int inicio, fim, tmili;
    int iniciob, fimb, somab;


    do
    {
        opc = menu();
        switch (opc)
        {

        case 1:
            inserir_Novo_Noh_PV(&Arvore_PV, criaNovoNoh(numteclado()));
            break;
        case 2:
            printf("\nListagem dos nos da Arvore \n\n");
            if(Arvore_PV != NULL)
            {
                visitarEmOrdem(Arvore_PV);
            }
            else
            {
                printf("Sem Elementos na Arvore \n");
            }

            break;
        case 3:
                printf("\n Numero de nodos aleatorios?\n\n");
                scanf("%d", &j);

                inicio = GetTickCount();

                for(i=1;i<=j;i++){
                    inserir_Novo_Noh_PV(&Arvore_PV, criaNovoNoh(i));
                }
                printf("\n\n--> %d Nodos inseridos\n\n", j);

                fim = GetTickCount();
                tmili = fim - inicio;
                printf("--> Tempo decorrido: %d ms\n\n\n", tmili);


            break;

        case 4:
            if(Arvore_PV != NULL)
            {
                altura = calcularAlturaPreta(Arvore_PV);
                printf("Altura preta da arvore: %d\n", altura);
            }
            else
            {
                printf("Sem Elementos na Arvore \n");
            }
            break;
        case 5:
            if(Arvore_PV != NULL)
            {
                printf("Digite o numero da Arvore para Remocao ?   \n");
                scanf("%d", &valor);
                aux = localizar_Noh_Arvore(Arvore_PV, valor);
                if (aux->numero_arvore == valor)
                {
                    mostraDadosNoh(aux);
                    removerVP(&Arvore_PV, aux);
                }
                else
                {
                    printf("\nO numero %d nao encontrada!\n\n", valor);
                }
                if(Arvore_PV == vazio)
                {
                    vazio = (nohVP*)malloc(sizeof(nohVP));
                    vazio->pai = Arvore_PV = NULL;
                    vazio->direita = vazio->esquerda = vazio;
                }
            }
            else
            {
                printf("Sem Elementos na Arvore \n");
            }
            break;
        case 6:

            printf("\n Numero de nodos para busca aleatoria?\n\n");
            scanf("%d", &j);

            iniciob = GetTickCount();

                for(i=1;i<=j;i++){
                    localizar_Noh_Arvore(Arvore_PV, rand());
                }
                printf("\n\n--> %d Nodos buscados\n\n", j);

                fimb = GetTickCount();
                somab = fimb - iniciob;
                printf("--> Tempo decorrido: %d ms\n\n\n", somab);


            break;
        }
    }
    while (opc != 0);

    return 0;
}
// Rotacao a Esquerda do Noh

void rotacaoEsquerda(nohVP **Arvore_PV, nohVP *noh)
{
    nohVP *y;

    if(((*Arvore_PV)->pai == vazio) && (noh->direita != vazio))
    {
        y = noh->direita;
        noh->direita = y->esquerda;
        y->esquerda->pai = noh;
        y->pai = noh->pai;

        if(noh->pai == vazio)
        {
            *Arvore_PV = y;
        }
        else if(noh == noh->pai->esquerda)
        {
            noh->pai->esquerda = y;
        }
        else
        {
            noh->pai->direita = y;
        }
    }
    y->esquerda = noh;
    noh->pai = y;
    (*Arvore_PV)->pai = vazio;
}

//Rotacao a Direita do no
void rotacaoDireita(nohVP **Arvore_PV, nohVP *noh)
{
    nohVP *y;

    if(((*Arvore_PV)->pai == vazio) && (noh->esquerda != vazio))
    {
        y = noh->esquerda;
        noh->esquerda = y->direita;
        y->direita->pai = noh;
        y->pai = noh->pai;

        if(noh->pai == vazio)
        {
            *Arvore_PV = y;
        }
        else if(noh == noh->pai->direita)
        {
            noh->pai->direita = y;
        }
        else
        {
            noh->pai->esquerda = y;
        }
    }
    y->direita = noh;
    noh->pai = y;
    (*Arvore_PV)->pai = vazio;
}


nohVP* inserir_Novo_Noh_PV(nohVP **Arvore_PV, nohVP *noh)// Insere na arvore
{
    nohVP *y = vazio;
    nohVP *x = *Arvore_PV;

    if((*Arvore_PV)== NULL)// Verifica se a arvore é NULL
    {
        *Arvore_PV = noh;
        (*Arvore_PV)->pai = vazio;
        vazio->pai = *Arvore_PV;
        (*Arvore_PV)->cor = 'P';
        return;
    }

    if((*Arvore_PV)->numero_arvore == noh->numero_arvore)
    {
        //printf(" Numero duplicado, Coloque outro numero !!\n\n");

        return ;
    }

    while(x != vazio)
    {
        y = x;

        if(noh->numero_arvore < x->numero_arvore)
        {
            x = x->esquerda;
        }
        else
        {
            x = x->direita;
        }
    }

    noh->pai = y;

    if(noh->numero_arvore < y->numero_arvore)
    {
        y->esquerda = noh;
    }
    else if(noh->numero_arvore > y->numero_arvore)
    {
        y->direita = noh;
    }
    else if(noh->numero_arvore == y->numero_arvore)
    {
        //printf("Numeros iguais, Tente outro numero !!\n\n");
        return ;
    }

    noh->esquerda = vazio;
    noh->direita = vazio;
    noh->cor = 'V';

    inserirCorVP(&(*Arvore_PV), noh);
    return noh;
}
// Insere a Cor do no e faz o balaceamento caso precisar
void inserirCorVP(nohVP **Arvore_PV, nohVP *noh)//
{
    nohVP *y;

    while(noh->pai->cor == 'V')
    {
        if(noh->pai == noh->pai->pai->esquerda)
        {
            y = noh->pai->pai->direita;

            if(y->cor == 'V')
            {
                noh->pai->cor = 'P';
                y->cor = 'P';
                noh->pai->pai->cor = 'V';
                noh = noh->pai->pai;
            }
            else
            {
                if(noh == noh->pai->direita)
                {
                    noh = noh->pai;
                    rotacaoEsquerda(&(*Arvore_PV), noh);
                }

                noh->pai->cor = 'P';
                noh->pai->pai->cor = 'V';
                rotacaoDireita(&(*Arvore_PV), noh->pai->pai);
            }
        }
        else
        {
            y = noh->pai->pai->esquerda;

            if(y->cor == 'V')
            {
                noh->pai->cor = 'P';
                y->cor = 'P';
                noh->pai->pai->cor = 'V';
                noh = noh->pai->pai;
            }
            else
            {
                if(noh == noh->pai->esquerda)
                {
                    noh = noh->pai;
                    rotacaoDireita(&(*Arvore_PV), noh);
                }

                noh->pai->cor = 'P';
                noh->pai->pai->cor = 'V';
                rotacaoEsquerda(&(*Arvore_PV), noh->pai->pai);
            }
        }
    }

    (*Arvore_PV)->cor = 'P';
}

// Remove o noh da Arvore

nohVP *removerVP(nohVP **Arvore_PV, nohVP *noh)
{
    nohVP *y, *x;

    if((noh->esquerda == vazio) || (noh->direita == vazio))
    {
        y = noh;
    }
    else
    {
        y = sucessorVP(noh);
    }

    if(y->esquerda != vazio)
    {
        x = y->esquerda;
    }
    else
    {
        x = y->direita;
    }

    x->pai = y->pai;


    if(y->pai == vazio)
    {
        *Arvore_PV = x;
    }
    else if(y == y->pai->esquerda)
    {
        y->pai->esquerda = x;
    }
    else
    {
        y->pai->direita = x;
    }

    if(y != noh)
    {
        noh->numero_arvore = y->numero_arvore;        //Aqui os dados sao transferidos
    }

    if(y->cor == 'P')
    {


        if((*Arvore_PV)->direita == vazio && (*Arvore_PV)->esquerda->direita != vazio)
        {

            rotacaoEsquerda(&(*Arvore_PV), (*Arvore_PV)->esquerda);
            removerCorVP(&(*Arvore_PV), (*Arvore_PV)->esquerda);
            rotacaoDireita(&(*Arvore_PV), (*Arvore_PV));
        }
        else
        {

            if((*Arvore_PV)->esquerda == vazio && (*Arvore_PV)->direita->esquerda != vazio)
            {

                rotacaoDireita(&(*Arvore_PV), (*Arvore_PV)->direita);
                removerCorVP(&(*Arvore_PV), (*Arvore_PV)->direita);
                rotacaoEsquerda(&(*Arvore_PV), (*Arvore_PV));
            }
        }
        removerCorVP(&(*Arvore_PV), x);
    }
    return y;
    free(y);
    free(x);

}
// Faz o balaceamento da cor caso tenha alguma incosistencia

void removerCorVP(nohVP **Arvore_PV, nohVP *noh)
{
    nohVP *aux;

    while(((*Arvore_PV) != noh) && (noh->cor == 'P'))
    {
        if(noh == noh->pai->esquerda)
        {
            aux = noh->pai->direita;

            if(aux->cor == 'V')
            {
                aux->cor = 'P';
                noh->pai->cor = 'V';
                rotacaoEsquerda(&(*Arvore_PV), noh->pai);
                aux = noh->pai->direita;
            }

            if((aux->esquerda->cor == 'P') && (aux->direita->cor == 'P'))
            {
                aux->cor = 'V';
                noh = noh->pai;
            }
            else if(aux->direita->cor == 'P')
            {
                aux->esquerda->cor = 'P';
                aux->cor = 'V';
                rotacaoDireita(&(*Arvore_PV), aux);
                aux = noh->pai->direita;
                aux->cor = noh->pai->cor;
                noh->pai->cor = 'P';
                aux->direita->cor = 'P';
                rotacaoEsquerda(&(*Arvore_PV), noh->pai);
                noh = *Arvore_PV;
            }
        }
        else
        {
            aux = noh->pai->esquerda;

            if(aux->cor == 'V')
            {
                aux->cor = 'P';
                noh->pai->cor = 'V';
                rotacaoDireita(&(*Arvore_PV), noh->pai);
                aux = noh->pai->esquerda;
            }

            if((aux->esquerda->cor == 'P') && (aux->direita->cor == 'P'))
            {
                aux->cor = 'V';
                noh = noh->pai;
            }
            else if(aux->esquerda->cor == 'P')
            {
                aux->direita->cor = 'P';
                aux->cor = 'V';
                rotacaoEsquerda(&(*Arvore_PV), aux);
                aux = noh->pai->esquerda;
                aux->cor = noh->pai->cor;
                noh->pai->cor = 'P';
                aux->esquerda->cor = 'P';
                rotacaoDireita(&(*Arvore_PV), noh->pai);
                noh = *Arvore_PV;
            }
        }
    }
    noh->cor = 'P';
}
// Sucessor do noh para o balaceamento

nohVP* sucessorVP(nohVP *noh)
{
    nohVP *aux;

    if(noh->direita != vazio)
    {
        return minimoVP(noh->direita);
    }

    aux = noh->pai;

    while((aux != vazio) && (noh == aux->direita))
    {
        noh = aux;
        aux = aux->pai;
    }

    return aux;
}
// Maximo da Arvore

nohVP* maximoVP(nohVP *noh)
{
    while(noh->direita != vazio)
    {
        noh = noh->direita;
    }
    return noh;
}
// Minimo da Arvore
nohVP* minimoVP(nohVP *noh)
{
    while(noh->esquerda != vazio)
    {
        noh = noh->esquerda;
    }
    return noh;
}


//pegar dados do teclado
int numteclado(){

    int num;

    printf("Informe um numero para a Arvore ");
    scanf("%d", &num);
    if(num < 0){
        printf("Numero Invalido! informe outro numero !!!\n");
        return numteclado();
    }

    return num;


}
// Cria o no para a Arvore
nohVP* criaNovoNoh(int a)
{
    nohVP *novo;
    novo = (nohVP*)malloc(sizeof(nohVP));
    //arrumar aqui
    novo->numero_arvore=a;
    novo->cor = 'V'; // todo novo no e vermelho
    novo->pai = vazio;
    novo->direita = vazio;
    novo->esquerda = vazio;

    return novo;
}
// Funçao de Listagem dos dados
void visitarEmOrdem(nohVP* Arvore_PV)
{
    if (Arvore_PV != vazio){

        mostraDadosNoh(Arvore_PV);
        visitarEmOrdem(Arvore_PV->esquerda);
        visitarEmOrdem(Arvore_PV->direita);
    }
}
// printa informações
void mostraDadosNoh(nohVP* noh)
{
    printf("Endereco do no---------------------- %p\n", noh);
    printf("Valor do no------------------------- %d\n", noh->numero_arvore);
    printf("Cor do no -------------------------- %c\n\n", noh->cor);
    printf("Pai do no--------------------------- %p\n", noh->pai);
    printf("Filho da esquerda------------------- %p\n", noh->esquerda);
    printf("Filho da direita-------------------- %p\n\n", noh->direita);
    printf("\n\n");
}
//Menu do Usuario
int menu(){



    int opcao;

    printf("\n----------------------------\n");
    printf("\nArvore RubroNegra\n\n\n");
    printf("1-Inserir na arvore--------|\n");
    printf("2-Imprimir arvore----------|\n");
    printf("3-Inserir aleatorios-------|\n");
    printf("4-Calcular altura preta----|\n");
    printf("5-Remover no da arvore-----|\n");
    printf("6-Busca aleatoria----------|\n");
    printf("0-Sair do programa---------|\n");
    printf("\n----------------------------\n");
    printf("\nEscolha uma opcao!\n ");





    scanf("%d", &opcao);

    return opcao;
}
// Calculo do balaceamento
int calcularAlturaPreta(nohVP *noh)
{
    int alt_esquerda = 0, alt_direita = 0;

    if(!noh)
    {
        return 0;
    }

    if (noh == vazio)
    {
        return 1;
    }

    if (noh->cor == 'P')
    {
        alt_esquerda += calcularAlturaPreta(noh->esquerda);
        alt_direita +=  calcularAlturaPreta(noh->direita);
    }
    else
    {
        calcularAlturaPreta(noh->esquerda);
        calcularAlturaPreta(noh->direita);
    }

    if (alt_esquerda > alt_direita)
    {
        return alt_esquerda + 1;
    }
    else
    {
        return alt_direita + 1;
    }
}
// Localizar o no da Arvore para devidas alteraçoes ou remoçoes

nohVP* localizar_Noh_Arvore(nohVP* noh, int numero_arvore)
{
    if ((noh == vazio) || (noh->numero_arvore == numero_arvore))
    {
        return noh;
    }

    if (numero_arvore < noh->numero_arvore)
    {
        return localizar_Noh_Arvore(noh->esquerda, numero_arvore);
    }
    else
    {
        return localizar_Noh_Arvore(noh->direita, numero_arvore);
    }
}
