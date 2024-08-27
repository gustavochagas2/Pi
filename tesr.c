#include <stdio.h>
typedef struct aluno {
int numero;
char nome[100];
int miniT [6];
float teste;
} Aluno

int nota (Aluno a){
    int i;
    int soma=0;
    for( i=0;i<6; i++){
        soma += a.MiniT[i];

    }
    float final = soma* 0.2 + a.teste*0.8;
    if(final<9.5){
        return 0;

    } else return 1;
}


int procuraNum (int num, Aluno t[], int N){
    int i;
    for (i=0; i<N; i++){
        if(num== t[i].numero){
            return i;
        }
        else return -1;
    }
}


void ordenaPorNum (Aluno t [], int N){
int i;
int j;
for(i=0;i<N-1;i++){
    for(j=0;j<N;j++){
        (if t[i].numero> t[j].numero){
            aluno temp = t[i];
            t[i]=t[j];
            t[j]= temp;
        }
    }
}
}

void imprimeTurma(int ind[], Aluno t[], int N) {
    for (int i = 0; i < N; i++) {
        int index = ind[i];
        printf("Número: %d, Nome: %s, Nota: %.2f\n", t[index].numero, t[index].nome, nota(t[index]));
    }
}
int procuraNum(int num, Aluno t[], int ind[], int N) {
    int inicio = 0, fim = N - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (t[ind[meio]].numero == num)
            return ind[meio];
        else if (t[ind[meio]].numero < num)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}
#include <string.h>

void criaIndPorNome(Aluno t[], int N, int ind[]) {
    for (int i = 0; i < N; i++) {
        ind[i] = i;
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (strcmp(t[ind[i]].nome, t[ind[j]].nome) > 0) {
                int temp = ind[i];
                ind[i] = ind[j];
                ind[j] = temp;
            }
        }
    }
}



struct staticStack {
int sp;
int values [Max];
} STACK, *SStack;

void SinitStack (SStack s){
   s->sp=0;

}

 int SisEmpty (SStack s){
    return s->sp==0;
 }


 int Spush (SStack s, int x){

 if (s->sp < Max) {
        s->values[s->sp++] = x;
        return 0; // Operação bem-sucedida
    } else {
        return 1; // Pilha cheia
    }
 }


 int Spop(SStack s, int *x) {
    if (!SisEmpty(s)) {
        *x = s->values[--(s->sp)];
        return 0; // Operação bem-sucedida
    } else {
        return 1; // Pilha vazia
    }
}

// (e) Coloca no endereço x o elemento que está no topo da pilha (sem modificar a pilha); retorna 0 se a operação foi bem-sucedida, 1 se a pilha estiver vazia
int Stop(SStack s, int *x) {
    if (!SisEmpty(s)) {
        *x = s->values[s->sp - 1];
        return 0; // Operação bem-sucedida
    } else {
        return 1; // Pilha vazia
    }
}
struct staticQueue {
int front;
int length;
int values [Max];
} QUEUE, *SQueue;


 void SinitQueue (SQueue q){
    q ->front =0;
    q->lenght=0;
 }

 int SisEmptyQ (SQueue q){
   return q-> lenght= 0;
 }



 int Senqueue(SQueue q, int x) {
    if (q->length < Max) {
        q->values[(q->front + q->length) % Max] = x;
        q->length++;
        return 0; // Operação bem-sucedida
    } else {
        return 1; // Fila cheia
    }
}



int Sdequeue(SQueue q, int *x) {
    if (!SisEmptyQ(q)) {
        *x = q->values[q->front];
        q->front = (q->front + 1) % Max;
        q->length--;
        return 0; // Operação bem-sucedida
    } else {
        return 1; // Fila vazia
    }
}


int Sfront(SQueue q, int *x) {
    if (!SisEmptyQ(q)) {
        *x = q->values[q->front];
        return 0; // Operação bem-sucedida
    } else {
        return 1; // Fila vazia
    }
}




typedef struct celula {
char *palavra;
int ocorr;
struct celula * prox;
} * Palavras;


void libertaLista (Palavras){
    Palavras= temp;
    while(l!= NULL){
        temp =l;
        l=l->prox;
        free(temp->palavra);
        free(temp);
    }
  
  
}



  int quantasP(Palavras l){
        int count=0;
        while(l-!=NULL){
            count++;
            l=l->prox;
        }
        return count;
    }


    void listaPal(Palavras l) {
    while (l != NULL) {
        printf("%s - %d\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}
. char * ultima (Palavras l){
    if (l==NULL) return NULL;
    while(l-> prox!= NULL){
        l=l-> prox;
    }
    return l-> palavra;
}
Palavras novaCelula(char *p) {
    Palavras nova = (Palavras)malloc(sizeof(struct celula));
    nova->palavra = strdup(p); // Aloca e copia a palavra
    nova->ocorr = 1;
    nova->prox = NULL;
    return nova;
}
Palavras acrescentaInicio(Palavras l, char *p){
    palavras nova = novaCelula(p);
    nova ->prox = l;
    return nova;


}

Palavras acrescentaFim(Palavras l, char *p) {
    if (l == NULL) return novaCelula(p);
    Palavras temp = l;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = novaCelula(p);
    return l;
}
Palavras acrescenta(Palavras l, char *p) {
    Palavras temp = l;
    Palavras anterior = NULL;

    // Percorre a lista para encontrar a posição correta para inserir a palavra ou a posição onde ela já existe
    while (temp != NULL && strcmp(temp->palavra, p) < 0) {
        anterior = temp;
        temp = temp->prox;
    }

    // Se a palavra já existe na lista, incrementa o número de ocorrências
    if (temp != NULL && strcmp(temp->palavra, p) == 0) {
        temp->ocorr++;
    } 
    // Se a palavra não existe na lista, insere uma nova célula
    else {
        Palavras nova = (Palavras)malloc(sizeof(struct celula));
        nova->palavra = strdup(p); // Aloca e copia a palavra
        nova->ocorr = 1;
        nova->prox = temp;

        // Se a inserção for no início da lista
        if (anterior == NULL) {
            l = nova;
        } 
        // Se a inserção for no meio ou final da lista
        else {
            anterior->prox = nova;
        }
    }
    return l;
}



typedef struct slist {
int valor;
struct slist * prox;
} * LInt;

LInt newLInt (int x, LInt xs) {
LInt r = malloc (sizeof(struct slist));
if (r!=NULL) {
r->valor = x; r->prox = xs;
}
return r;
}

typedef LInt Stack;
typedef struct {
LInt inicio,fim;
} Queue;



void initStack (Stack *s){
    *s==NULL;
}


int SisEmpty (Stack s){
    return s== NULL;
}

int push(Stack *s,int x){
    LInt novo= newLInt(x,*s);

    if (novo == NULL){
        return 0;
    }
}
*s = novo;
return 1;


int pop (Stack *s, int *x){
    if(SisEmpty(*s)){
        return 0;

    }
    *x = (*s)->valor; // Salva o valor do topo da stack
    LInt temp = *s; // Salva o endereço do nó a ser removido
    *s = (*s)->prox; // Atualiza o ponteiro para o topo da stack
    free(temp); // Libera a memória do nó removido
    return 1; 
}



int top(Stack s, int *x) {
    if (SisEmpty(s)) {
        return 0; // Stack vazia, não é possível obter o topo
    }
    *x = s->valor; // Salva o valor do topo da stack
    return 1; // Operação bem-sucedida
}


void initQueueC (Queue *q){
      *q== NULL,
}


int QisEmptyC (Queue q){

    return q==NULL;
}


int enqueueC (Queue *q, int x){
    LInt novo= newLInt(x,*q);
    if(novo==NULL){
        return 0;
    }
    novo ->valor=x;

    
if(QisEmptyC(*q)){
    novo->prox=novo;
    *q=novo;

} else{
    novo -> prox =(*q)-> prox;
    *q = novo;
}
return 1;
}


int dequeueC(QueueC *q, int *x) {
    if (QisEmptyC(*q)) {
        return 0; // Fila circular vazia, não é possível remover
    }
    *x = (*q)->prox->valor; // Salva o valor do elemento a ser removido
    LInt temp = (*q)->prox; // Salva o endereço do nó a ser removido
    if (*q == (*q)->prox) { // Se a fila circular tiver apenas um elemento
        *q = NULL; // A fila circular se torna vazia
    } else {
        (*q)->prox = temp->prox; // O próximo do último nó atual aponta para o próximo do nó a ser removido
    }
    free(temp); // Libera a memória do nó removido
    return 1; // Remoção bem-sucedida
}
 int frontC(QueueC q, int *x) {
    if (QisEmptyC(q)) {
        return 0; // Fila circular vazia, não é possível obter o elemento do início
    }
    *x = q->prox->valor; // Salva o valor do elemento do início da fila
    return 1; // Operação bem-sucedida
}



typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} * ABin;

ABin newABin (int r, ABin e, ABin d) {
ABin a = malloc (sizeof(struct nodo));
if (a!=NULL) {
a->valor = r; a->esq = e; a->dir = d;
}
return a;
}


int altura (ABin a){
    int t;
    if(a==NULL){
        t=0;
    }
    int ae= altura(a->esq);
    int ad =altura(a->dir);
    t=1+ ae +ad;
    return t;
}


int nFolhas (ABin a){
  if (a==NULL){
    return 0;
  }
  if (a->esq==NULL && a->dir==NULL){
    return 1;

  }
  return nFolhas(a->esq)+ nFolhas(a->dir);

}
ABin maisEsquerda (ABin a){
    int v;
    if (a==NULL|| a->esq==NULL){
        return a;
    }
   return maisEsquerda(a->esq);
}
void imprimeNivel(ABin a, int l) {
    if (a == NULL) {
        return; // árvore vazia
    }
    if (l == 0) {
        printf("%d ", a->valor); // se estivermos no nível desejado, imprime o valor do nó
    } else {
        imprimeNivel(a->esq, l - 1); // desce à esquerda
        imprimeNivel(a->dir, l - 1); // desce à direita
    }
}
int procuraE(ABin a, int x) {
    if (a == NULL) {
        return 0; // árvore vazia, elemento não encontrado
    }
    return a->valor == x || procuraE(a->esq, x) || procuraE(a->dir, x);
}
int nivel(ABin a, int x){
    if(a==NULL){
        return -1;
    }
    if (a->valor==x){
        return 0;
    }
    int ne= nivel(a->esq,x);
    int nd= nivel(a->dir,x)
    if (ne==-1 && nd==-1){
        return-1;
    }
    return 1+ ne+nd;
}


void imprimeAte(ABin a, int x) {
    if (a == NULL) {
        return; // árvore vazia
    }
    if (a->valor < x) {
        imprimeAte(a->esq, x); // imprime à esquerda
        printf("%d ", a->valor); // imprime o valor do nó
        imprimeAte(a->dir, x); // imprime à direita
    }
}

ABin removeMenor(ABin *a) {
    if (*a == NULL) {
        return NULL;
    }
    
    ABin atual = *a;
    ABin pai = NULL;
    
    while (atual->esq != NULL) {
        pai = atual;
        atual = atual->esq;
    }
    
    if (pai != NULL) {
        pai->esq = atual->dir;
    } else {
        *a = atual->dir;
    }
    
    return atual;
}

void removeRaiz(ABin *a) {
    if (*a == NULL) {
        return;
    }
    
    ABin temp;
    if ((*a)->esq == NULL) {
        temp = *a;
        *a = (*a)->dir;
    } else if ((*a)->dir == NULL) {
        temp = *a;
        *a = (*a)->esq;
    } else {
        ABin menor = removeMenor(&(*a)->dir);
        menor->esq = (*a)->esq;
        menor->dir = (*a)->dir;
        temp = *a;
        *a = menor;
    }
    free(temp);
}




int removeElem(ABin *a, int x) {
    if (*a == NULL) {
        return 1; // Elemento não encontrado
    }
    
    if (x < (*a)->valor) {
        return removeElem(&(*a)->esq, x);
    } else if (x > (*a)->valor) {
        return removeElem(&(*a)->dir, x);
    } else { // Elemento encontrado
        removeRaiz(a);
        return 0;
    }
}


void promoveMenor(ABin *a) {
    if (*a == NULL) return;
    
    while ((*a)->esq != NULL) {
        rodaDireita(a);
    }
}


void promoveMaior(ABin *a) {
    if (*a == NULL) return;
    
    while ((*a)->dir != NULL) {
        rodaEsquerda(a);
    }
}



int constroiEspinhaAux(ABin *a, ABin *ult) {
    if (*a == NULL) return 0;
    
    int n = 0;
    ABin atual = *a;
    while (atual != NULL) {
        if (atual->esq != NULL) {
            rodaDireita(&atual);
        } else {
            *ult = atual;
            atual = atual->dir;
            n++;
        }
    }
    return n;
}

int constroiEspinha(ABin *a) {
    ABin ultimo = NULL;
    return constroiEspinhaAux(a, &ultimo);
}




void equilibraEspinhaAux(ABin *a, int n) {
    if (n <= 1) return;
    
    int m = (n - 1) / 2;
    ABin temp = *a;
    for (int i = 0; i < m; i++) {
        temp = temp->dir;
    }
    rodaEsquerda(a);
    equilibraEspinhaAux(&(*a)->esq, m);
    equilibraEspinhaAux(&(*a)->dir, n - m - 1);
}

void equilibraEspinha(ABin *a, int n) {
    equilibraEspinhaAux(a, n);
}



void equilibra(ABin *a) {
    int n = constroiEspinha(a);
    equilibraEspinha(a, n);
}


