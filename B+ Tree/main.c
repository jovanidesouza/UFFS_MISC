/*
 Arvore B+
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 6

typedef struct nodo{
    int chave;
    struct bloc * dir, *esq;
}tpNodo;

typedef struct bloc{
    int k;
    int indice;//0-não/ 1-sim
    tpNodo * bloco[6];
    struct bloc * pai;
    struct bloc * irdir;// posiç
    struct bloc * iresq;
//

}tpbloco;

/*------ Inserção --------*/
tpNodo  * novoNodo(int k);
tpbloco * iniciabloco();
tpbloco * divide(tpbloco**raiz, tpbloco* bloc,tpbloco*pai);
tpbloco * insere_no_bloco(tpbloco* bloco, tpNodo*no);
void insere(tpbloco**raiz,tpNodo*no);
//tpbloco * divide(tpbloco**raiz, tpbloco* bloc);
void imprime(tpbloco*raiz);
tpbloco * achabloco(tpbloco*raiz,int k);
void navega(tpbloco*aux);

void imprime_bloco(tpbloco*raiz);
tpbloco * remover_do_bloco(tpbloco*bloco, int no);
//void remover_do_bloco(tpbloco*bloco, int no);
/*------ Remoção --------*/
tpbloco * achainfo(tpbloco*raiz,int k);//acha a folha que possui o nodo com valor k
void remover(tpbloco*raiz,int k);
void reorganiza(tpbloco*pai, tpbloco*aux);

void buscar(tpbloco*raiz,int k);
void imprimir(tpbloco *aux, FILE *file);
//remoção

tpbloco*raiz=NULL;
int main(){
    int a=1,i,b;

    while(a){
        printf("-------------------------------------------------");
        printf("\n\t\t\tMENU");
        printf("\n\t 1 - Inserir valores");
        printf("\n\t 2 - Remover x informacoes");
        printf("\n\t 3 - Mostrar Arvore");
        printf("\n\t 4 - Remover informacao");
        printf("\n\t 5 - Andar pela arvore");
        printf("\n\t 6 - Mostrar Raiz");
        printf("\n   Default - Sair");
        printf("\n-------------------------------------------------\n");
        scanf("%d",&a);
        switch(a){
            case(1):{
                printf("Insirir quantos valores: ");
                scanf("%d",&b);//
               // srand((unsigned)time(NULL));
                for(a=0;a<=b;a++){
                    i=rand()%(100*b);
                    insere(&raiz, novoNodo(i));
                }
                a=1;
                break;
            }case(2):{
                printf("Insira o valor de chaves a serem removidas: ");
                scanf("%d",&i);
                for(a=i;a>=i;a--){
                    printf("\n\n\n\tremovendo A= %d\n", a);
                    if(raiz!=NULL)
                        remover(raiz,a);
                }
                a=1;
                break;
            }case(3):{
                imprime(raiz);
                a=1;
                break;
            }
            case(4):{
                printf("Insira o valor a ser removido: ");
                scanf("%d",&a);
                remover(raiz,a);
                a=1;
                break;
            }case(5):{
                navega(raiz);
                a=1;
                break;
            }case(6):{
                if(raiz==NULL)
                    printf("Arvore vazia\n");
                else{
                    imprime_bloco(raiz);
                }
                a=1;
                break;
            }default:{
                a=0;
                break;
            }
        }
    }
    return 0;
}


int conta_nodos(tpbloco*aux){
    int a;
    if(aux==NULL)
        return 0;
    else{
        for(a=0;a<MAX;a++){
            if(aux->bloco[a]==NULL)
                break;
        }
        return a-1;
    }
}

tpbloco * achainfo(tpbloco*nodo,int k){
     int a;
     nodo=achabloco(nodo,k);
     if(nodo!=NULL){
        for(a=0;a<MAX;a++){
            if(nodo->bloco[a]!=NULL){
                if(nodo->bloco[a]->chave == k)
                    return nodo;
            }
        }
     }
     return NULL;
}
int father=0;
tpbloco * remover_do_bloco(tpbloco*bloco, int no){
    if(bloco==raiz && bloco->bloco[1]==NULL){
        father=1;
    }
    int a;
    for(a=0;a<MAX;a++){
        if(bloco->bloco[a]!=NULL){
            if(bloco->bloco[a]->chave == no){
                break;
            }
        }
    }
    if(bloco!=NULL){
        if(bloco->bloco[a]!=NULL){
            if(bloco->bloco[a]->chave == no){
                if(bloco->bloco[a+1]!=NULL && bloco->bloco[a]->esq!=NULL){
                    bloco->bloco[a+1]->esq=bloco->bloco[a]->esq;

                }
                if(bloco->bloco[a-1]!=NULL && a>0 && bloco->bloco[a]->dir!=NULL){
                    bloco->bloco[a-1]->dir=bloco->bloco[a]->dir;

                }
                if(bloco->bloco[a]->dir!=NULL){
                    bloco->bloco[a]->dir=NULL;
                    bloco->bloco[a]->esq=NULL;
                }
                for(;a<MAX;a++){
                    if(bloco->bloco[a+1]!=NULL)
                        bloco->bloco[a]=bloco->bloco[a+1];
                    else{
                        break;
                    }
                }
                bloco->bloco[a]=NULL;

                for(a=0;a<MAX;a++){
                    if(bloco->bloco[a]==NULL)
                            break;

                }
                if(bloco->bloco[0]!=NULL){
                    bloco->k=bloco->bloco[0]->chave;
                }else{
                    // printf("deu treta\n");
                    // free(bloco);
                    // bloco=remover_do_bloco(bloco->pai,bloco->k);
                }
                if(father==1){
                    bloco=NULL;
                }
            }
        }
    }
    return bloco;
}
void remover(tpbloco*raiz,int k){
    tpbloco * aux= achabloco(raiz,k);
    if(aux==NULL){
        printf("Nao encontrado esse em campo algum\n");
    }
    else{
        printf("removendo do bloco: %d\n",aux->k );
        imprime_bloco(aux);
        aux=remover_do_bloco(aux,k);
        imprime_bloco(aux);
        for(k=0;k<MAX;k++){
            if(aux!=NULL)
            if(aux->bloco[k]==NULL){
                break;
            }
        }
        if(k==((MAX/2)/2)){
            printf("reorganiza\n");
            reorganiza(aux->pai, aux);

        }
    }
}

void reorganiza(tpbloco*pai, tpbloco*aux){

    int a;
    if(pai==NULL){
        printf("pai null\n");
        return;
    }

    for(a=0;a<MAX;a++){
        if(aux->bloco[a]==NULL)
            break;
    }

    if(a==((MAX/2)/2)){
        tpbloco*tmp;
        for(a=0;a<MAX;a++){
            if(pai!=NULL){

                if(pai->bloco[a]->dir==aux && conta_nodos(aux->iresq)!=0){
                    printf("caso 1\n");
                    tmp = insere_no_bloco(aux->iresq,aux->bloco[0]);
                    if(aux->irdir!=NULL)
                        aux->irdir->iresq=aux->iresq;
                    if(aux->iresq!=NULL)
                        aux->iresq->irdir=aux->irdir;
                    aux->bloco[0]=NULL;
                    pai->bloco[a]->dir=NULL;
                    aux=NULL;
                    aux=remover_do_bloco(pai,pai->bloco[a]->chave);
                    if(aux!=NULL){
                        aux->k=aux->bloco[0]->chave;// sem reapontar
                        if(aux->bloco[1]==NULL)
                            reorganiza(aux->pai,aux);
                    }
                    if(father==1){
                        tmp->pai=NULL;
                        raiz=tmp;
                        father=0;
                    }
                    for(a=0;a<MAX;a++){
                        if(tmp->pai!=NULL)
                            if(tmp->pai->bloco[a]!=NULL)
                                if(tmp->pai->bloco[a]->dir==tmp)
                                    break;
                    }

                    if(tmp->pai!=NULL){
                        if(tmp->pai->bloco[a]!=NULL){
                            tmp->pai->bloco[a]->chave=tmp->bloco[0]->chave;
                            if(tmp->pai->bloco[0]!=NULL)
                                tmp->pai->k=tmp->pai->bloco[0]->chave;
                        }
                    }

                    tmp->k=tmp->bloco[0]->chave;
                    while(tmp->bloco[4]!=NULL)
                       tmp = divide(&raiz,tmp,tmp->pai);

                    return;
                }

                if(pai->bloco[a]->esq==aux && conta_nodos(aux->irdir)!=0){
                      tmp = insere_no_bloco(aux->irdir,aux->bloco[0]);
                     printf("caso 2\n");
                    if(aux->irdir!=NULL)
                        aux->irdir->iresq=aux->iresq;
                    if(aux->iresq!=NULL)
                        aux->iresq->irdir=aux->irdir;

                    if(pai->bloco[a]->dir==aux)
                        pai->bloco[a]->dir=NULL;
                    else
                        pai->bloco[a]->esq=NULL;
                    aux->bloco[0]=NULL;
                    aux=NULL;

                    aux=remover_do_bloco(pai,pai->bloco[a]->chave);
                    if(aux!=NULL){
                        aux->k=aux->bloco[0]->chave;// sem reapontar
                        if(aux->bloco[1]==NULL)
                            reorganiza(aux->pai,aux);
                    }
                    if(father==1){
                        tmp->pai=NULL;
                        raiz=tmp;
                        father=0;
                    }
                    while(tmp->bloco[4]!=NULL)
                       tmp = divide(&raiz,tmp,tmp->pai);
                    return;

                }
                if(conta_nodos(aux->iresq)!=0 && pai->bloco[a]->esq == aux){
                    tmp = insere_no_bloco(aux->iresq,aux->bloco[0]);
                printf("caso 3\n");
                    if(aux->irdir!=NULL)
                        aux->irdir->iresq=aux->iresq;
                    if(aux->iresq!=NULL)
                        aux->iresq->irdir=aux->irdir;

                    aux->bloco[0]=NULL;

                    if(pai->bloco[a]->dir==aux)
                        pai->bloco[a]->dir=NULL;
                    else
                        pai->bloco[a]->esq=NULL;

                    aux->bloco[0]=NULL;
                    aux=NULL;

                    aux=remover_do_bloco(pai,pai->bloco[a]->chave);
                    if(aux!=NULL){
                        aux->k=aux->bloco[0]->chave;// sem reapontar
                        if(aux->bloco[1]==NULL)
                            reorganiza(aux->pai,aux);
                    }
                    if(father==1){
                        tmp->pai=NULL;
                        raiz=tmp;
                        father=0;
                    }
                    for(a=0;a<MAX;a++)
                        if(tmp->pai->bloco[a]->dir==tmp)
                            break;
                    tmp->pai->bloco[a]->chave=tmp->bloco[0]->chave;
                    tmp->pai->k=tmp->pai->bloco[0]->chave;
                    tmp->k=tmp->bloco[0]->chave;

                    while(tmp->bloco[4]!=NULL)
                       tmp = divide(&raiz,tmp,tmp->pai);
                    return;
                }
                if(conta_nodos(aux->irdir)!=0 && pai->bloco[a]->dir == aux){
                printf("caso 4\n");

                     tmp = insere_no_bloco(aux->irdir,aux->bloco[0]);

                    if(aux->irdir!=NULL)
                        aux->irdir->iresq=aux->iresq;
                    if(aux->iresq!=NULL)
                        aux->iresq->irdir=aux->irdir;

                    aux->bloco[0]=NULL;
                    if(pai->bloco[a]->dir==aux)
                        pai->bloco[a]->dir=NULL;
                    else
                        pai->bloco[a]->esq=NULL;

                    aux=NULL;
                    aux=remover_do_bloco(pai,pai->bloco[a]->chave);aux->k=aux->bloco[0]->chave;// sem reapontar
                    if(aux!=NULL){
                        aux->k=aux->bloco[0]->chave;// sem reapontar
                        if(aux->bloco[1]==NULL)
                            reorganiza(aux->pai,aux);
                    }
                     if(father==1){
                        tmp->pai=NULL;
                        raiz=tmp;
                        father=0;
                    }
                    while(tmp->bloco[4]!=NULL)
                       tmp = divide(&raiz,tmp,tmp->pai);
                    return;
                }else{
                    printf("nao se encaixa em nada\n");
                }
            }
        }
    }
    aux->k=aux->bloco[0]->chave;
}

void navega(tpbloco*aux){
    int a,b;
    if(aux!=NULL){
        printf("\n Esta no bloco: %d\n", aux->k);
        imprime_bloco(aux);
        printf("\nO indice do bloco\n");
        scanf("%d",&b);
        printf("\n\tReturn 0\tPai -3");
        if(aux->bloco[b]!=NULL && aux->bloco[b]->dir!=NULL)
            printf("\tEsq -1\tDir -2");

        if(aux->bloco[b]!=NULL && aux->irdir!=NULL)
            printf("\tIrDir -4");

        if(aux->bloco[b]!=NULL && aux->iresq!=NULL)
            printf("\tIrEsq -5\n");

        scanf("%d", &a);
        if(a==2)
            navega(aux->bloco[b]->dir);
        else if(a==1)
            navega(aux->bloco[b]->esq);
        else if(a==3)
            navega(aux->pai);
        else if(a==5){
            //imprime_bloco(aux->iresq->pai->bloco[0]->esq);
            navega(aux->iresq);
            //navega(aux->iresq->pai->bloco[0]->esq);
        }else if(a==4){
            for(a=0;a<MAX;a++)
                if(aux->irdir->pai->bloco[a+1]==NULL)
                    navega(aux->irdir);
                    //navega(aux->irdir->pai->bloco[a]->dir);
        }
    }

}

void fixa(tpbloco*raiz){
    if(raiz!=NULL){
        int a;
        for(a=0;a<MAX;a++){
            if(raiz->bloco[a]!=NULL)
            if(raiz->bloco[a]->dir!=NULL){
                raiz->bloco[a]->dir->pai=raiz;
                raiz->bloco[a]->esq->pai=raiz;
                fixa(raiz->bloco[a]->dir);
                fixa(raiz->bloco[a]->esq);
            }
        }
    }
}


tpbloco *achabloco(tpbloco*aux,int k){
    int a;
    if(aux!=NULL){
        for(a=0;a<MAX;a++){
            if(aux->bloco[a] != NULL){
                if(aux->bloco[a]->chave > k){
                    if(aux->bloco[a]->esq != NULL){
                        return achabloco(aux->bloco[a]->esq, k);
                    }else{
                        return aux;
                    }
                }else if(aux->bloco[a]->chave <= k && aux->bloco[a+1] == NULL){
                    if(aux->bloco[a]->dir != NULL){
                        return achabloco(aux->bloco[a]->dir, k);
                    }else{
                        return aux;
                    }
                }
            }
        }
    }
    return aux;
}

void imprime_bloco(tpbloco*raiz){
    int a;
    printf("\n");
    for(a=0;a<MAX;a++){
        if(raiz->bloco[a]!=NULL){
            printf("[%d]",raiz->bloco[a]->chave);
        }
    }
}

void imprime(tpbloco*raiz){
    int a;
    printf("\n");
    for(a=0;a<MAX;a++){
        if(raiz->bloco[a]!=NULL){

            if(raiz->bloco[a]->esq!=NULL){
                imprime(raiz->bloco[a]->esq);
            }
            printf("[%d]",raiz->bloco[a]->chave);
             if(raiz->bloco[a]->dir!=NULL){
                imprime(raiz->bloco[a]->dir);
            }
            printf("\n\n");
        }
    }
}

/*#########################################################################################*/

/*---------------------------------------- Insersão ---------------------------------------*/

tpNodo *novoNodo(int k){
    tpNodo *aux= (tpNodo*)malloc(sizeof(tpNodo));
    aux->chave=k;
    aux->dir=NULL;
    aux->esq=NULL;
    return aux;
}

tpbloco *iniciabloco(){
    tpbloco * novo=(tpbloco*)malloc(sizeof(tpbloco));
    int k;
    novo->indice=0;
    novo->pai=NULL;
    novo->irdir=NULL;
    novo->iresq=NULL;
    for(k=MAX;k>=0;k--){
        novo->bloco[k]=NULL;
    }
    return novo;
}

tpbloco* insere_no_bloco(tpbloco* aux, tpNodo*no){
   printf("inserindo %d\n",no->chave );
    if(aux==NULL){
        tpbloco*novo=iniciabloco();
        novo->bloco[0]=no;
        if(no->dir!=NULL){
            novo->bloco[0]->dir->pai=novo;
            novo->bloco[0]->esq->pai=novo;
        }
        novo->pai=NULL;
        novo->indice=0;
        novo->k = no->chave;
        aux=novo;
    }else{
        printf("inserindo nno bloco\n");
        imprime_bloco(aux);
        int a, b=-2;
        for(a=0;a<MAX;a++){
            if(aux->bloco[a] != NULL){
                if(aux->bloco[a]->chave == no->chave){
                    printf("- ja existe na Arvore");
                    return aux;
                }
            }
        }
        if(no->dir!=NULL){
            no->dir->pai=aux;
            no->esq->pai=aux;
        }
        a=MAX-1;
        while(a>=0){
            if(aux->bloco[a]!=NULL){
                if( no->chave < aux->bloco[a]->chave){
                    aux->bloco[a+1]=aux->bloco[a];
                    b=a;
                }
            }
            a--;
        }
        if(b!=-2)
            aux->bloco[b]=no;
        else{
            for(b=0;b<MAX;b++)
                if(aux->bloco[b]==NULL)
                    break;
            aux->bloco[b]=no;
        }
        if(aux->bloco[b]->dir!=NULL){// se é algum indice, tem dir e esq.

            if(b-1>=0 && aux->bloco[b-1]!=NULL)
                aux->bloco[b-1]->dir=aux->bloco[b]->esq;
            if(aux->bloco[b+1]!=NULL)
                aux->bloco[b+1]->esq=aux->bloco[b]->dir;
        }
        printf("bloco depois de inserido e ordenado\n");
        imprime_bloco(aux);
    }
    aux->k=aux->bloco[0]->chave;
    return aux;
}

tpbloco * divide(tpbloco**raiz, tpbloco* bloc,tpbloco*pai){// retorna o bloco pai para verificar se ele também já está cheio.
    int a;
    for(a=0;a<MAX;a++){
        if(bloc->bloco[a]==NULL)
            break;
    }
    if(a==(MAX-1)){
        tpbloco*dir = iniciabloco();
        tpbloco*esq = iniciabloco();
        for(a=0;a<(MAX-1);a++){
            if(a<3)
                esq->bloco[a]=bloc->bloco[a];
            else
                dir->bloco[a-3]=bloc->bloco[a];
        }
        esq->k = esq->bloco[0]->chave;
        dir->k = dir->bloco[0]->chave;

        esq->irdir=dir;
        dir->iresq=esq;
        if(bloc->iresq!=NULL){
            esq->iresq=bloc->iresq;
            bloc->iresq->irdir=esq;
        }else{
            esq->iresq=NULL;
        }

        if(bloc->irdir!=NULL){
            dir->irdir=bloc->irdir;
            bloc->irdir->iresq=dir;
        }else{
            dir->irdir=NULL;
        }

        for(a=0;a<MAX;a++){
            if(esq->bloco[a]!=NULL){
                if(esq->bloco[a]->dir!=NULL){
                    esq->bloco[a]->dir->pai=esq;
                }
                if(esq->bloco[a]->esq!=NULL)
                    esq->bloco[a]->esq->pai=esq;
            }
            if(dir->bloco[a]!=NULL){
                if(dir->bloco[a]->esq!=NULL)
                    dir->bloco[a]->esq->pai=dir;
                if(dir->bloco[a]->dir!=NULL)
                    dir->bloco[a]->dir->pai=dir;
            }
        }
        tpNodo*aux=novoNodo(dir->bloco[0]->chave);
        aux->dir=dir;
        aux->esq=esq;
        for(a=0;a<(MAX-1);a++)
            bloc->bloco[a]=NULL;

        if(bloc->pai==NULL){
            *raiz=insere_no_bloco(pai,aux);
        }else{
            return insere_no_bloco(pai,aux);
        }
    }
    return bloc;
}

void insere(tpbloco**raiz, tpNodo*no){
    tpbloco*aux=NULL;
    int a,c=1;
    aux = achabloco(*raiz,no->chave);
    aux = insere_no_bloco(aux ,no);
    aux->k = aux->bloco[0]->chave;
    if(aux!=NULL){
        while(c!=0){
            for(a=0;a<MAX;a++){
                if(aux->bloco[a] == NULL)
                    break;
            }
            if(a==(MAX-1)){
                aux = divide(raiz,aux,aux->pai);
                c++;
            }
            c--;
        }
        if(*raiz==NULL){
            *raiz=aux;
        }
    }else
        printf("Nao foi possivel inserir informacao, erro na memoria\n");
}

void buscar(tpbloco*raiz,int k){
    tpbloco*aux=achabloco(raiz,k);
    if(aux!=NULL){
        //if()
        //printf()
    }
}
