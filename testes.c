#include <stdio.h>
#include <stdlib.h>

// Função de comparação para qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Função nesimo para encontrar o i-ésimo menor elemento
int nesimo(int a[], int N, int i) {
    // Ordena o array
    qsort(a, N, sizeof(int), compare);
    // Retorna o i-ésimo menor elemento (considerando i começando de 1)
    return a[i - 1];
}



LInt removeMaiores(LInt l, int x) {
    // Encontrar o ponto onde o valor é maior que x
    LInt current = l;
    LInt prev = NULL;

    while (current != NULL && current->valor <= x) {
        prev = current;
        current = current->prox;
    }

    // Se prev é NULL, todos os elementos da lista são maiores que x
    if (prev == NULL) {
        // Liberar a memória dos nós que estão sendo removidos
        while (l != NULL) {
            current = l;
            l = l->prox;
            free(current);
        }
        return NULL;
    }

    // Cortar a lista e liberar a memória dos nós que estão sendo removidos
    prev->prox = NULL;
    while (current != NULL) {
        LInt temp = current;
        current = current->prox;
        free(temp);
    }

    return l;
}


LInt caminho(ABin a, int x) {
    if (a == NULL) return NULL;  // Se a árvore está vazia, retorna NULL

    if (a->valor == x) {
        return newLInt(x, NULL);  // Encontramos o valor, retorna um novo nó da lista com x
    }

    LInt path = NULL;

    if (x < a->valor) {
        path = caminho(a->esq, x);  // Procura na subárvore esquerda
    } else {
        path = caminho(a->dir, x);  // Procura na subárvore direita
    }

    if (path != NULL) {
        // Se encontramos o valor na subárvore, adicionamos o valor atual ao início da lista
        path = newLInt(a->valor, path);
    }

    return path;
}



void inc(char s[]) {
    int n = strlen(s);
    int carry = 1;  // Inicialmente, queremos incrementar em 1

    // Percorre a string de trás para frente
    for (int i = n - 1; i >= 0; i--) {
        int digit = s[i] - '0';  // Converte o caractere para um dígito
        digit += carry;  // Adiciona o carry

        if (digit == 10) {
            s[i] = '0';  // Se a soma for 10, o dígito vira '0'
            carry = 1;   // E temos um carry para o próximo dígito
        } else {
            s[i] = digit + '0';  // Atualiza o dígito na string
            carry = 0;           // Não há carry para o próximo dígito
            break;  // Podemos parar, pois não há mais carry
        }
    }

    // Se após o loop ainda houver carry, precisamos adicionar '1' no início
    if (carry == 1) {
        // Movemos todos os caracteres uma posição para a direita
        for (int i = n; i > 0; i--) {
            s[i] = s[i - 1];
        }
        s[0] = '1';  // Colocamos '1' no início
        s[n + 1] = '\0';  // Adicionamos o terminador nulo no final
    }
}
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Ordena em ordem decrescente
}

int sacos(int p[], int N, int C) {
    // Ordena os pesos em ordem decrescente
    qsort(p, N, sizeof(int), compare);

    int *bins = (int *)malloc(N * sizeof(int));
    int bin_count = 0;

    for (int i = 0; i < N; i++) {
        int j;
        // Tenta colocar o produto no primeiro saco que tenha espaço
        for (j = 0; j < bin_count; j++) {
            if (bins[j] + p[i] <= C) {
                bins[j] += p[i];
                break;
            }
        }
        // Se não encontrou um saco com espaço, cria um novo
        if (j == bin_count) {
            bins[bin_count++] = p[i];
        }
    }

    int result = bin_count;
    free(bins); // Libera a memória alocada
    return result;
}


int pesquisa(int a[], int N, int x) {
    for (int i = 0; i < N; i++) {
        if (a[i] == x) {
            return i; // Elemento encontrado, retorna o índice
        }
    }
    return -1; // Elemento não encontrado
}



void roda(LInt *l) {
    if (*l == NULL || (*l)->prox == NULL) {
        return;
    }

    LInt current = *l;
    LInt prev = NULL;

    while (current->prox != NULL) {
        prev = current;
        current = current->prox;
    }

    prev->prox = NULL;
    current->prox = *l;
    *l = current;
}


int apaga(ABin a, int n) {
    // Caso base: se a árvore for vazia, retorna 0
    if (a == NULL) {
        return 0;
    }

    // Apaga os nodos da subárvore esquerda
    int apagadosEsq = apaga(a->esq, n);

    // Se já foram apagados mais de n nodos, retorna o total de nodos apagados
    if (apagadosEsq >= n) {
        return apagadosEsq;
    }

    // Se não foram apagados n nodos ainda, continua a apagar os nodos da subárvore direita
    int apagadosDir = apaga(a->dir, n - apagadosEsq - 1); // Subtrai 1 para contar o próprio nodo a

    // Atualiza o total de nodos apagados
    int totalApagados = apagadosEsq + apagadosDir + 1; // Adiciona 1 para contar o próprio nodo a

    // Libera a memória do nodo atual
    free(a);

    // Retorna o total de nodos efetivamente apagados
    return totalApagados;
}



int perfeito(int x) {
    int somaDivisores = 0;

    // Percorre todos os possíveis divisores do número x
    for (int i = 1; i < x; i++) {
        if (x % i == 0) { // Verifica se i é divisor de x
            somaDivisores += i; // Adiciona i à soma dos divisores próprios
        }
    }

    // Se a soma dos divisores próprios for igual a x, então x é um número perfeito
    if (somaDivisores == x) {
        return 1; // Retorna verdadeiro
    } else {
        return 0; // Retorna falso
    }
}


void checksum(char s[]) {
    int len = strlen(s);
    int sum = 0;
    int doubleDigit = 0;

    // Percorre a string da direita para a esquerda
    for (int i = len - 1; i >= 0; i--) {
        int digit = s[i] - '0'; // Converte o caractere para inteiro

        // Se for um dígito em posição par, soma o dobro do valor
        if (doubleDigit) {
            digit *= 2;
            // Se o valor resultante tiver dois dígitos, soma-os separadamente
            if (digit > 9) {
                digit = digit % 10 + digit / 10;
            }
        }
        sum += digit;
        doubleDigit = !doubleDigit;
    }

    // Calcula o dígito de controle necessário para que a soma seja um múltiplo de 10
    int controlDigit = (10 - (sum % 10)) % 10;

    // Acrescenta o dígito de controle ao final da string
    s[len] = controlDigit + '0';
    s[len + 1] = '\0';
}

int escolhe(int N, int valor[], int peso[], int C, int quant[]) {
    int maxValor = 0; // Valor total máximo dos produtos transportados
    int capacidadeAtual = C; // Capacidade atual da mochila

    // Inicializa o array de quantidades com 0
    for (int i = 0; i < N; i++) {
        quant[i] = 0;
    }

    // Algoritmo guloso para escolha de produtos
    for (int i = 0; i < N; i++) {
        // Calcula a quantidade máxima possível para o produto i
        int qtd = capacidadeAtual / peso[i];
        // Verifica se a quantidade máxima excede a quantidade disponível do produto
        if (qtd > valor[i]) {
            qtd = valor[i];
        }
        // Atualiza a capacidade atual da mochila
        capacidadeAtual -= qtd * peso[i];
        // Atualiza o valor total máximo
        maxValor += qtd * valor[i];
        // Atualiza o array de quantidades
        quant[i] = qtd;
    }

    return maxValor;
}


int perfeito(int x) {
    int somaDivisores = 0;

    // Percorre todos os possíveis divisores do número x
    for (int i = 1; i < x; i++) {
        if (x % i == 0) { // Verifica se i é divisor de x
            somaDivisores += i; // Adiciona i à soma dos divisores próprios
        }
    }

    // Se a soma dos divisores próprios for igual a x, então x é um número perfeito
    if (somaDivisores == x) {
        return 1; // Retorna verdadeiro
    } else {
        return 0; // Retorna falso
    }
}





typedef struct {
int x,y;
} Ponto;

 double distanciaOrigem(Ponto p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

// Função de comparação para a ordenação dos pontos por distância à origem
int comparaPontos(const void *p1, const void *p2) {
    Ponto *pt1 = (Ponto *)p1;
    Ponto *pt2 = (Ponto *)p2;
    
    double dist1 = distanciaOrigem(*pt1);
    double dist2 = distanciaOrigem(*pt2);
    
    if (dist1 < dist2) return -1;
    if (dist1 > dist2) return 1;
    return 0;
}

// Função para ordenar os pontos por distância à origem
void ordena(Ponto pos[], int N) {
    qsort(pos, N, sizeof(Ponto), comparaPontos);
}



int depth(ABin a, int x){
    if(a==NULL){
        return -1;
    }
    if(a->valor== x){
        return 0;
    }
    int e =depth(a-> esq,x);
    int d =depth (a->dir,x);
    if(e>=0){
        return e+1;
    }
    if(d>=0){
        return d +1;
    }
    return -1;
}



int wordle(char secreta[], char tentativa[]) {
    int acertos = 0;
    int tam = strlen(secreta);
    
    for (int i = 0; i < tam; i++) {
        if (secreta[i] == tentativa[i]) {
            acertos++;
            tentativa[i] = toupper(tentativa[i]); // Converte a letra para maiúscula
        } else {
            tentativa[i] = '*'; // Substitui por '*'
        }
    }
    
    return acertos;
}


LInt periodica(char s[]) {
    int len = strlen(s);
    int inicio = -1; // Índice de início do parêntesis de abertura
    int fim = -1;    // Índice de início do parêntesis de fecho
    int tamPeriodo = 0; // Tamanho do período repetido
    LInt lista = NULL;
    LInt fimLista = NULL;

    // Encontra o índice de início do parêntesis de abertura e de fecho
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            inicio = i;
        } else if (s[i] == ')') {
            fim = i;
            break;
        }
    }

    // Calcula o tamanho do período repetido
    tamPeriodo = fim - inicio - 1;

    // Cria a lista com o período repetido
    for (int i = fim + 1; i < len; i++) {
        lista = newLInt(s[i] - '0', lista);
        if (fimLista == NULL) {
            fimLista = lista;
        }
    }

    // Conecta o último elemento ao primeiro para formar a lista circular
    fimLista->prox = lista;

    // Copia o período repetido para o final da lista
    LInt temp = lista;
    for (int i = 0; i < tamPeriodo; i++) {
        temp->prox = newLInt(temp->valor, temp->prox);
        temp = temp->prox;
    }

    return lista;
}

nt isFib(int x) {
    int fib1 = 0; // Primeiro número da sequência de Fibonacci
    int fib2 = 1; // Segundo número da sequência de Fibonacci

    // Se o número dado for 0 ou 1, ele é um número de Fibonacci
    if (x == fib1 || x == fib2) {
        return 1;
    }

    // Procura na sequência de Fibonacci
    while (fib2 <= x) {
        int temp = fib2;
        fib2 = fib1 + fib2;
        fib1 = temp;
        // Se encontrarmos o número na sequência de Fibonacci, retornamos verdadeiro
        if (fib2 == x) {
            return 1;
        }
    }
    // Se chegarmos até aqui e não encontrarmos o número na sequência de Fibonacci, retornamos falso
    return 0;
}


int moda(Aluno turma[], int N) {
    int frequencia[101] = {0}; // Array para armazenar a frequência de cada nota final
    int modaNota = 0; // Inicializa a moda como 0 (reprovado)
    int maxFrequencia = 0; // Inicializa a frequência máxima como 0

    // Calcula a frequência de cada nota final
    for (int i = 0; i < N; i++) {
        if (turma[i].teste * 0.8 + turma[i].minis * 0.2 >= 9.5) {
            frequencia[(int)(turma[i].teste * 0.8 + turma[i].minis * 0.2)]++;
            // Atualiza a moda e a frequência máxima, se necessário
            if (frequencia[(int)(turma[i].teste * 0.8 + turma[i].minis * 0.2)] > maxFrequencia) {
                maxFrequencia = frequencia[(int)(turma[i].teste * 0.8 + turma[i].minis * 0.2)];
                modaNota = (int)(turma[i].teste * 0.8 + turma[i].minis * 0.2);
            }
        }
    }

    // Se a moda for 0, significa que ninguém passou, então retorna 0
    if (modaNota == 0) {
        return 0;
    }

    return modaNota; // Retorna a nota final mais frequente
}


 take(int n, LInt *l) {
    LInt temp = *l;
    int count = 0;

    // Conta o número de nodos na lista
    while (temp != NULL) {
        count++;
        temp = temp->prox;
    }

    // Se o número de nodos for menor ou igual a n, não há nada para apagar
    if (count <= n) {
        return 0;
    }

    // Se o número de nodos for maior que n, apaga os nodos excedentes
    temp = *l;
    for (int i = 0; i < n; i++) {
        *l = (*l)->prox;
        free(temp);
        temp = *l;
    }

    return count - n; // Retorna o número de nodos apagados
}



int verifica(char frase[], int k) {
    int i = 0;

    // Itera sobre a frase
    while (frase[i] != '\0') {
        int len = 0;
        // Conta o número de caracteres em cada palavra
        while (frase[i] != ' ' && frase[i] != '\0') {
            len++;
            i++;
        }
        // Verifica se a palavra tem pelo menos k caracteres
        if (len < k) {
            return 0; // Se uma palavra não tiver pelo menos k caracteres, retorna falso
        }
        if (frase[i] != '\0') {
            i++; // Avança para o próximo caractere
        }
    }
    return 1; // Se todas as palavras tiverem pelo menos k caracteres, retorna verdadeiro
}


ABin reconstroi(char s[]) {
    ABin raiz = NULL;
    return reconstroiAux(&raiz, s);
}

ABin reconstroiAux(ABin *a, char s[]) {
    static int i = 0; // Variável estática para acompanhar a posição na string
    if (s[i] == '*' || s[i] == '\0') {
        i++; // Avança para o próximo caractere na string
        return NULL;
    }
    // Aloca espaço para o novo nó e define seus valores
    *a = malloc(sizeof(struct nodo));
    (*a)->valor = s[i] - '0'; // Converte de caractere para inteiro
    i++;
    // Chama a função recursivamente para os filhos esquerdo e direito
    (*a)->esq = reconstroiAux(&((*a)->esq), s);
    (*a)->dir = reconstroiAux(&((*a)->dir), s);
    return *a;
}


 int length (LInt){
    int count =0;
    LInt current = l;
    while (current != NULL){
        count++;
        current = current-> prox;
        
    }
    return count;
 }


 void freeL (LInt){
    LInt temp;
    while (l!= NULL){
        temp = l;
        l = l-> prox;
         free(temp);
             }
 }



 void imprimeL (LInt) {
    LInt current;

    while(l!=NULL){

        current = l;
        printf("%d",&current);

        l = l-> prox;
    }

 }


LInt reverseL (LInt){
    LInt current=l;
    LInt prev= NULL;

    while (l!=NULL){

 LInt next = current->prox; 
        current->prox = prev; 

        
        prev = current;
        current = next;
    }
}


 void insertOrd (LInt *, int){
    LInt current = l;
    LInt prev = NULL;
    LInt novo = malloc (sizeof(struct ligada));
            novo-> valor= valor;
novo-> prox = NULL;

    while (current!= NULL && current -> valor < valor ){

        prev = current;
        current = current -> prox;

    }
    if (prev == NULL) {
        novo->prox = *l;
        *l = novo;
    } else {
       
        prev->prox = novo;
        novo->prox = current;
    }


 }

int removeOneOrd(LInt *l, int valor) {
    LInt current = *l; // Ponteiro para percorrer a lista
    LInt prev = NULL; // Ponteiro para o nó anterior

    // Percorre a lista até encontrar o elemento ou o final da lista
    while (current != NULL && current->valor != valor) {
        prev = current;
        current = current->prox;
    }

    // Se current for NULL, o elemento não foi encontrado
    if (current == NULL) {
        return 1; // Retorna 1 indicando que o elemento não existe
    }

    // Se prev for NULL, o elemento a ser removido é o primeiro da lista
    if (prev == NULL) {
        *l = current->prox; // Atualiza o início da lista
    } else {
        prev->prox = current->prox; // Remove o nó da lista
    }

    free(current); // Libera o nó removido da memória
    return 0; // Retorna 0 indicando sucesso
}


void merge (LInt *r, LInt a, LInt b) {
  LInt resultado = NULL;
  LInt *atual = &resultado;

  while(a!=NULL && b !=NULL){

    if ( a -> valor <= b -> valor){
         *atual =a;
         a = a->prox;
    } else {
        *atual = b;
        b = b-> prox;
    }
    atual= & ((*atual)-> prox);
  }  
  if (a !=NULL){
    *atual = a;
  } else {
    *atual = b;
  }

  *r = resultado;

}

void splitQS(LInt l, int x, LInt *mx, LInt *Mx){
    *mx= NULL;
    *Mx= NULL;
    LInt atual = l;
     
     While( atual != NULL){
         LInt proximo = atual -> prox;
         if(atual -> valor < x){
            atual ->prox = *mx;
            *mx = autal;
         } else{
            atual -> prox = *Mx;
            *Mx = atual;
         }
         atual = proximo;
     }
}

LLig parteAmeio(LLig *l){
     if (*l == NULL || (*l)-> prox == NULL){
        return NULL;
     }
     LLig slow = *l;
     LLig fast = *l;
     LLig prevs=NULL;
      while ( fast != NULL && fast -> prox != NULL){
         prevs= slow;
         slow = slow -> prox;
         fast = fast ->prox -> prox;
      }
      LLig s2 = slow;
      if( prevs!=NULL){
        prevs -> prox = NULL;
      }
return s2;

}


int removeAll (LInt *l, int){
    int count = 0;
    LInt prev = NULL;
    while(*l){
        if ((*l)-> valor==x){
            if(!=prev) (*l)= (*l)-> prox;
            else prev -> prox = (*l) -> prox ;
            count ++;
        } else {
            prev = *l;
            *l = & ((*l)->prox);
        }
    }
     return count ;
}

int removeDups(LInt *l){
    int count = 0;
    for(; *l; l = (&(*l)-> prox)){
        LInt prev =(*l);
        LInt next = (*l)-> prox;
        for (;next; next = prev -> prox){
            if(next-> valor == (*l)-> valor){
                count+=1;
                prev -> +prox= next -> prox;

            } else prev= next;
        }
    }
return count;

}


int removeMaiorL(LInt *l){
    Lint current = *l;
    int max =  current -> valor;
    LInt prev= NULL;
    LInt maxprev=NULL;
    LInt maxl=*l;
    for (;current;current = current ->prox;){
        if (current ->valor >max){
            maxprev = prev;
            maxl=current
            max = current-> valor;
        }
        if (!maxprev) (*l)= (*l)-> prox;
        else maxprev -> prox= maxl -> prox;
        return max;
    }

}

void init(LInt *l){

    LInt current = *l;
    if( current== NULL!! current -> prox == NULL){
        free(current);
        *l =NULL;

    } while( current -> prox- > prox != NULL){
        current = current -> prox;
    }
    free(current-> prox;)
    current -> prox = NULL;

}


 void appendL (LInt *l, int){
    Lint current = *l;
    Lint prev = NULL;

    LInt novo = malloc(sizeof(struct lligada));
    novo->valor = valor;
    novo->prox = NULL;
    if (current == NULL){
        current = novo;
    } else {
        LInt current *L;
        while (current -> prox; != NULL){
            current = current -> prox;
        }
        current -> prox = novo;
    }
void concatL (LInt *a, LInt b){
    if (*a == NULL){
        *a=b;
    } else{
        LInt current=*a;
        while(current -> prox !=NULL){
            current = current -> prox;
        }
    }
current ->prox =b;
}



}


LInt cloneL (LInt l){
    LInt new = (LInt) malloc (sizeof(struct ligada));
    new -> valor = l-> valor;
    new ->prox = NULL;
    LInt currentnew=new;
    LInt currentold=l->prox;

    while( currentold !=NULL){
         LInt newNode = (LInt)malloc(sizeof(struct lligada));
         newnode-> valor = currentold -> valor;
         newnode -> prox = NULL;

         currentnew -> prox = newnode
         currentnew = newnode
         currentold=currentold -> prox;

    }
    return new;
} int maximo (LInt l){
    Lint current = l->prox;
    int max =l->valor;

while (current != NULL){
    if (current ->valor >max){
        max = current -> valor;
    }
    current = current -> valor;

}
return max;
}

int take(int n, LInt *l){
    if (n<=0){
        LInt temp;
        while ( *l!= NULL){
            temp = *l;
            *l= (*l)-> prox;
            free (temp);
        }
return 0;
    }

    LInt current = *l;
    int count = 1;
    while (current != NULL && count <n){
        current = current -> prox;
        count++;}

        if(current != NULL && current -> prox; !=NULL){
            LInt tofree == current -> prox;
            current -> prox= NULL;
            while (tofree !=NULL){
                Lint temp = tofree;
                tofree = tofree -> prox;
                free(temp);
            }
        } 
    
    return count;
}


int drop(int n, LInt *l){
    itn count=0;
    While (*l!=NULL; && count <n){
        LInt temp =*l;
        *l=(*l)-> prox;
        free(temp);
        count++;

    }
    return count;
}

LInt Nforward(LInt l, int N){
    if(l==NULL) return NULL;

    LInt current= l;
    for (int i =0; i<N;i++){
        current = current -> prox;
    }
    return current;

}

int listToArray(LInt l, int v[], int N){
    while(l!= NULL && i <N){
        v[i]= l-> valor;
        l=l-> prox;
        i++;
    }

    return i;

}

LInt arrayToList(int v[], int N) {
    if( N==0) return NULL;


   LInt head = (LInt)malloc(sizeof(struct lligada));
        head-> valor = v[0];
        head-> prox= NULL;

        LInt current = head;

        for (int i = 1;i<N;i++){

             LInt newNode = (LInt)malloc(sizeof(struct lligada));
        newNode->valor = v[i];
        newNode->prox = NULL;
        current->prox = newNode;
        current = newNode;

        }
        return head;
}

LInt somasAcL(LInt l){
    LInt newHead = (LInt)malloc(sizeof(struct lligada));
    newHead->valor = l->valor;
    newHead->prox = NULL;
    LInt currentold = l-> prox;
    LInt currentnew = newHead;
    int acumula = newHead -> valor;
    
    while(currentold!=NULL){
         acumula += currentold -> valor;
          LInt newNode = (LInt)malloc(sizeof(struct lligada));
          newNode -> valor=acumula;
          newNode-> prox=NULL;
          currentnew -> prox =newNode;
          currentnew = newNode;
          currentold = currentold -> prox;

    }
    return newHead;
}



void remreps(LInt l) {
    if (l == NULL) return; // Se a lista estiver vazia, não há nada a fazer

    LInt current = l;

    while (current->prox != NULL) {
        if (current->valor == current->prox->valor) {
            // Nó duplicado encontrado
            LInt temp = current->prox;
            current->prox = temp->prox; // Salta o nó duplicado
            free(temp); // Libera a memória do nó duplicado
        } else {
            current = current->prox; // Avança para o próximo nó
        }
    }
}

LInt rotateL(LInt l) {
    if (l == NULL || l->prox == NULL) return l; // Se a lista estiver vazia ou tiver um só elemento, retorna a lista inalterada

    LInt first = l; // Primeiro nó da lista
    LInt current = l;

    // Percorre a lista até o último nó
    while (current->prox != NULL) {
        current = current->prox;
    }

    // Conecta o último nó ao primeiro nó
    current->prox = first;
    // Ajusta a cabeça da lista para o segundo nó
    l = first->prox;
    // Define o novo final da lista
    first->prox = NULL;

    return l;
}
 int altura (ABin a){
        int t;
        if (a==NULL){
            t=0;
        }
        int ae= altura (a-> esq);
        int ad= altura (a->dir);
        return t;
 }

 ABin cloneAB (ABin a){
    newABin=(ABin) malloc(sizeof(struct ABin));
    if(newABin==NULL) return NULL;

     newABin -> valor = a-> valor;
     newABin -> esq= cloneAB(a->esq);
     newABin -> dir = cloneAB (a-> dir);
     return newABin
 }



void mirror(ABin *a){
    ABin temp = (*a) -> esq;
    (*a-> esq)= (*a)-> dir;
    (*a)-> dir = temp;


     mirror(&((*a)->esq));
    mirror(&((*a)->dir));
}

void append(LInt *list, int valor) {
    LInt newNode = (LInt)malloc(sizeof(struct lligada));
    newNode->valor = valor;
    newNode->prox = NULL;

    if (*list == NULL) {
        *list = newNode;
    } else {
        LInt current = *list;
        while (current->prox != NULL) {
            current = current->prox;
        }
        current->prox = newNode;
    }
}

// Função que realiza a travessia inorder e cria a lista ligada
void inorder(ABin a, LInt *list) {
    if (a == NULL) return;

    inorder(a->esq, list); // Percorrer a subárvore esquerda
    append(list, a->valor); // Inserir o valor do nó atual na lista
    inorder(a->dir, list); // Percorrer a subárvore direita
}


// Função auxiliar para inserir um valor no final da lista ligada
void append(LInt *list, int valor) {
    LInt newNode = (LInt)malloc(sizeof(struct lligada));
    newNode->valor = valor;
    newNode->prox = NULL;

    if (*list == NULL) {
        *list = newNode;
    } else {
        LInt current = *list;
        while (current->prox != NULL) {
            current = current->prox;
        }
        current->prox = newNode;
    }
}

// Função que realiza a travessia preorder e cria a lista ligada
void preorder(ABin a, LInt *list) {
    if (a == NULL) return;

    append(list, a->valor); // Inserir o valor do nó atual na lista
    preorder(a->esq, list); // Percorrer a subárvore esquerda
    preorder(a->dir, list); // Percorrer a subárvore direita
}


void append(LInt *list, int valor) {
    LInt newNode = (LInt)malloc(sizeof(struct lligada));
    newNode->valor = valor;
    newNode->prox = NULL;

    if (*list == NULL) {
        *list = newNode;
    } else {
        LInt current = *list;
        while (current->prox != NULL) {
            current = current->prox;
        }
        current->prox = newNode;
    }
}

// Função que realiza a travessia posorder e cria a lista ligada
void posorder(ABin a, LInt *list) {
    if (a == NULL) return;

    posorder(a->esq, list); // Percorrer a subárvore esquerda
    posorder(a->dir, list); // Percorrer a subárvore direita
    append(list, a->valor); // Inserir o valor do nó atual na lista
}

int depth(ABin a, int x){
    if (a== NULL){
        return -1;
    }
    if (a-> valor == x){
        return 0;

    }
    int ed = depth ( a-> esq, x);
    int dd = depth ( a -> dir,x);
    if (ed == -1 && dd == -1){
        return -1;
    }
    int min = (ed |=-1) ? ed : dd;
    if( ed !=-1 && dd !=-1){
        min = (ed < dd)? ed : dd;
    }
    return 1 + min;
}

int freeAB (ABin a){
    int count = 0;
    if (a==NULL){
        return 0;
    }

    int e = freeAB(a-> esq);
    int d= freeAB ( a- dir);

    
        free(a);
       
    

    return 1+ e + d;

}




int pruneAB(ABin *a, int l) {
    if (*a == NULL) {
        return 0; // Se a árvore estiver vazia, não há nós para remover
    }

    if (l <= 0) {
        // Se a profundidade é 0 ou menor, remove toda a árvore
        int numNodosRemovidos = freeAB(*a);
        *a = NULL;
        return numNodosRemovidos;
    }

    // Se a profundidade é maior que 0, continua a poda nas subárvores
    int esqCount = pruneAB(&((*a)->esq), l - 1);
    int dirCount = pruneAB(&((*a)->dir), l - 1);

    return esqCount + dirCount; // Retorna o número total de nós removidos
}
// Função auxiliar para criar um novo nó da lista ligada
LInt newLInt(int valor) {
    LInt node = (LInt)malloc(sizeof(struct lint));
    node->valor = valor;
    node->prox = NULL;
    return node;
}

// Função que constrói uma lista com os valores dos elementos que estão armazenados na árvore ao nível n
LInt nivelL(ABin a, int n) {
    if (a == NULL) {
        return NULL; // Se a árvore estiver vazia, retorna NULL
    }

    if (n == 1) {
        // Se o nível atual é o nível desejado, cria um nó na lista com o valor do nó da árvore
        return newLInt(a->valor);
    }

    // Caso contrário, continua a busca nos níveis mais profundos
    LInt listaEsq = nivelL(a->esq, n - 1); // Busca na subárvore esquerda com nível decrementado
    LInt listaDir = nivelL(a->dir, n - 1); // Busca na subárvore direita com nível decrementado

    // Junta as duas listas
    if (listaEsq == NULL) {
        return listaDir; // Se a lista esquerda for NULL, retorna a lista direita
    }

    // Encontra o final da lista esquerda e junta com a lista direita
    LInt temp = listaEsq;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = listaDir;

    return listaEsq; // Retorna a lista combinada
}


int contaFolhas (ABin a){
    int count= 0;

    if (a== NULL){
        return 0;

    }

    int e = contaFolhas(a-> esq);
    int d= contaFolhas (a-> dir);

    if(a ->esq == NULL && a-> dir== NULL){
        return 1;
    }
    return e +d:

}~





int inorderAux(ABin a, int v[], int N, int *index) {
    if (a == NULL || *index >= N) {
        return *index; // Se a árvore for vazia ou o array estiver cheio, retorna o índice atual
    }

    // Travessia inorder: esquerda, raiz, direita
    inorderAux(a->esq, v, N, index); // Visita a subárvore esquerda

    if (*index < N) {
        v[*index] = a->valor; // Adiciona o valor do nó atual ao array
        (*index)++; // Incrementa o índice
    }

    inorderAux(a->dir, v, N, index); // Visita a subárvore direita

    return *index; // Retorna o número de elementos preenchidos
}

// Função principal para preencher o array com elementos da árvore em ordem inorder
int dumpAbin(ABin a, int v[], int N) {
    int index = 0;
    return inorderAux(a, v, N, &index);
}

int lookupAB(ABin a, int x) {
    // Percorre a árvore iterativamente
    while (a != NULL) {
        if (a->valor == x) {
            return 1; // Encontrou o elemento
        } else if (x < a->valor) {
            a = a->esq; // Move para a subárvore esquerda
        } else {
            a = a->dir; // Move para a subárvore direita
        }
    }
    return 0; // Não encontrou o elemento
}


int depthOrd(ABin a, int x) {
    int nivel = 1; // Começamos a contagem de níveis a partir de 1 (raiz)

    // Percorre a árvore iterativamente
    while (a != NULL) {
        if (a->valor == x) {
            return nivel; // Encontrou o elemento, retorna o nível atual
        } else if (x < a->valor) {
            a = a->esq; // Move para a subárvore esquerda
        } else {
            a = a->dir; // Move para a subárvore direita
        }
        nivel++; // Incrementa o nível a cada iteração
    }
    return -1; // Não encontrou o elemento
}


void removeMaior(ABin *a) {
    ABin atual = *a;
    ABin pai = NULL;

    // Percorre a árvore até encontrar o nó com o maior elemento
    while (atual->dir != NULL) {
        pai = atual;
        atual = atual->dir;
    }

    // Verifica se o nó com o maior elemento é a raiz da árvore
    if (pai == NULL) {
        *a = atual->esq;
    } else {
        pai->dir = atual->esq;
    }

    free(atual); // Libera o nó com o maior elemento
}


void listToBTree(LInt l, ABin *a, int n) {
    if (n <= 0) {
        *a = NULL; // Caso base: árvore é nula
        return;
    }

    // Encontrar o meio da lista
    int meio = n / 2;

    // Avançar até o meio da lista
    LInt meioPtr = l;
    for (int i = 0; i < meio; i++) {
        meioPtr = meioPtr->prox;
    }

    // Criar o nó da árvore com o valor do meio da lista
    *a = novoNo(meioPtr->valor);

    // Construir a subárvore esquerda recursivamente com a metade esquerda da lista
    listToBTree(l, &((*a)->esq), meio);

    // Construir a subárvore direita recursivamente com a metade direita da lista
    listToBTree(meioPtr->prox, &((*a)->dir), n - meio - 1);
}






