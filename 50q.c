#include <stdio.h>

int main(int numero,) {
    int maior = 0;

    printf("Digite uma sequência de números inteiros terminada com 0:\n");

    do {
        scanf("%d", &numero);

        // Verifica se o número lido é maior que o maior número atual
        if (numero > maior) {
            maior = numero;
        }
    } while (numero != 0);

   w= printf("O maior elemento da sequência é: %d\n", maior);

    return w;
}



int seq2(int numero){
int menor= 0;

scanf("%d", &numero);

if (numero< menor){

    menor=numero;
}
while (numero!=0){
    w= printf("%d\n"n,menor);

    return w;
}
}



int seq3(int numero1, numero2){
int maior1= 0;
int maior2= 0;

scanf("%d", &numero1);

scanf("%d", &numero2);

if (numero1< numero2){

    maior2=numero1;
} else{
    maior2=numero2;
}
while (numero1 && numero2 !=0){
    w= printf("%d\n"n,maior2);

    return w;
}
}



int bitsUm (unsigned int n){

int r= 0;
while ( n ==1){
    r++
}

return r;

}

int trailingZ(unsigned int n) {
    int count = 0;
    // Enquanto o bit menos significativo for 0 e n não for 0
    while ((n & 1) == 0 && n != 0) {
        count++;
        // Shift right para verificar o próximo bit
        n >>= 1;
    }
    return count;
}



int qDig (unsigned int n){
int r = 0;
while ( n >10){
    n/=10;
    r++;

}
if (n==0){
    count = 1;
}
return r;
}

char *strcat(char s1[], const char s2[]) {
    int i = 0, j = 0;
    // Encontrar o final de s1
    while (s1[i] != '\0') {
        i++;
    }
    // Concatenar s2 a s1
    while (s2[j] != '\0') {
        s1[i++] = s2[j++];
    }
    // Adicionar o terminador nulo ao final
    s1[i] = '\0';
    // Retornar o endereço de s1
    return s1;
}


C int strcmp (char s1[], char s2[]){

    int i = 0; int j = 0;

    while (s1[1]!= '\0'){
        i++;
    }

    while (s2[j] != '\0'){
        j++;
    }

    if (i >j){

        return -1;

    }
    if ( j>i){

        return 1;
    } 
    else return 0;
}


char *strstr (char s1[], char s2[]){
    int i = 0;
    int j = 0;
    
    while (s1[i]!= s2[j]){

        i++;
        j++;
    } 
    if (s1[i]== s2[j]){

        return i;
    } else return 0;
}

void strrev(char s[]) {
    int length = strlen(s);
    int i, j;
    char temp;
    
    for (i = 0, j = length - 1; i < j; i++, j--) {
        // Troca os caracteres de posição
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

#include <stdio.h>

int isVowel(char c) {
    // Verifica se o caractere é uma vogal (maiúscula ou minúscula)
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void strnoV(char s[]) {
    int i = 0, j = 0;
    // Percorre a string
    while (s[i] != '\0') {
        // Se o caractere não for uma vogal, copia-o para a nova posição
        if (!isVowel(s[i])) {
            s[j++] = s[i];
        }
        i++;
    }
    // Adiciona o terminador nulo ao final da nova string
    s[j] = '\0';
}

void truncW(char t[], int n) {
    int length = strlen(t);
    int i = 0, j = 0;
    char s[length]; // Cria um array para armazenar a string truncada
    
    while (i < length) {
        // Ignora espaços no início de uma palavra
        while (i < length && isspace(t[i]))
            i++;
        
        if (i >= length)
            break; // Se atingiu o fim da string, saia do loop
        
        // Inicia a truncagem da palavra
        j = 0;
        while (i < length && !isspace(t[i]) && j < n) {
            s[j] = t[i]; // Copia o caractere atual para o array 's'
            i++;
            j++;
        }
        
        // Adiciona um espaço após a palavra truncada, se não for o último caractere
        if (i < length && !isspace(t[i])) {
            s[j] = ' ';
            j++;
            i++;
        }
    }
    
    // Adiciona o terminador nulo ao final da string 's'
    s[j] = '\0';
    
    // Copia a string truncada 's' de volta para 't'
    strcpy(t, s);
}


#include <stdio.h>

char charMaisfreq(char s[]) {
    // Se a string for vazia, retornar 0
    if (s[0] == '\0')
        return 0;

    int frequencia[256] = {0}; // Array para contar a frequência de cada caractere ASCII
    int i = 0;
    
    // Contar a frequência de cada caractere na string
    while (s[i] != '\0') {
        frequencia[(int)s[i]]++;
        i++;
    }
    
    char maisFrequente = s[0]; // Suponha que o primeiro caractere é o mais frequente
    for (i = 1; s[i] != '\0'; i++) {
        // Se o caractere atual tiver uma frequência maior que o mais frequente atual
        if (frequencia[(int)s[i]] > frequencia[(int)maisFrequente]) {
            maisFrequente = s[i];
        }
    }
    
    return maisFrequente;
}

int iguaisConsecutivos(char s[]) {
    int maxConsecutivos = 0;
    int count = 1; // Contador para contar os caracteres iguais consecutivos

    for (int i = 1; s[i] != '\0'; i++) {
        // Se o caractere atual for igual ao anterior, incrementa o contador
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            // Se encontrarmos um novo caractere, atualizamos o máximo de caracteres iguais consecutivos
            if (count > maxConsecutivos) {
                maxConsecutivos = count;
            }
            // Resetamos o contador para começar a contar a próxima sub-string de caracteres iguais
            count = 1;
        }
    }
    
    // Verifica se a última sub-string de caracteres iguais é maior que a anterior
    if (count > maxConsecutivos) {
        maxConsecutivos = count;
    }

    return maxConsecutivos;
}



int difConsecutivos (char s[]){
    int maxdif = 0,
    int count = 1
    for (int i=1; s[i]!= '\0'; i++){
        if(s[i] != s [i-1]){
            count++;
        } else{
            if (count >maxdif){
                maxdif= count;
            }
            count = 1;
        }
    }
    if (count> maxdif){
        maxdif = count;
    }
    return maxdif;

}


int maiorPrefixo(char s1[], char s2[]) {
    int count1 = 1;
    int count2 = 1;
    int maior1 = 0;
    int maior2 = 0;

    for (int i = 1; s1[i] != '\0'; i++) {
        if (s1[i] == s1[i - 1]) {
            count1++;
        } else {
            if (count1 > maior1) {
                maior1 = count1;
            }
            count1 = 1;
        }
    }
    if (count1 > maior1) {
        maior1 = count1;
    }

    for (int j = 1; s2[j] != '\0'; j++) {
        if (s2[j] == s2[j - 1]) {
            count2++;
        } else {
            if (count2 > maior2) {
                maior2 = count2;
            }
            count2 = 1;
        }
    }
    if (count2 > maior2) {
        maior2 = count2;
    }

    if (maior1 == maior2) {
        return maior1;
    } else {
        return 0; // Não há um maior prefixo comum
    }
}





 #include <string.h>

int maiorSufixo(char s1[], char s2[]) {
    int count = 0;
    int i = strlen(s1) - 1; // Começamos do último caractere de s1 e s2

    while (i >= 0 && s1[i] == s2[i]) {
        count++;
        i--;
    }

    return count;
}

#include <stdio.h>
#include <string.h>

int sufPref(char s1[], char s2[]) {
    int count = 0;
    int i, j;

    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                count++;
                break; 
            }
        }
    }

    return count;
}

#include <stdio.h>

int contaPal(char s[]) {
    int count = 0;
    int i = 0;

    // Percorre a string
    while (s[i] != '\0') {
        // Ignora espaços iniciais
        while (s[i] == ' ') {
            i++;
        }

        // Se encontrarmos um caractere não espaço, contamos uma palavra
        if (s[i] != '\0') {
            count++;
        }

        // Avança para o próximo espaço
        while (s[i] != '\0' && s[i] != ' ') {
            i++;
        }
    }

    return count;
}

int contaVogais(char s[]) {
    int i;
    int count = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            count++;
        }
    }
    return count;
}
int contida (char a[], char b[]){
    int i=0;
    int j;
    for ( j = 0; b[j]!= '\0'; j++){
        if(a[i]== b[j]){
            return True;
            i++;

        } else return False;
    }


}


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool palindrome(char s[]) {
    int inicio = 0;
    int fim = strlen(s) - 1;

    while (inicio < fim) {
        // Compara os caracteres correspondentes nos extremos
        if (s[inicio] != s[fim]) {
            return false; // Se os caracteres forem diferentes, não é um palíndromo
        }
        inicio++;
        fim--;
    }
    return true; // Se chegarmos aqui, a string é um palíndromo
}


int remRep(char x[]) {
    int length = 0; // Comprimento da string resultante
    int i = 0; // Índice para percorrer a string original
    int j = 0; // Índice para percorrer a string resultante

    while (x[i] != '\0') {
        x[j] = x[i]; // Copia o caractere atual para a posição j
        length++; // Incrementa o comprimento da string resultante

        // Avança para o próximo caractere diferente
        while (x[i] == x[i + 1]) {
            i++;
        }
        i++;
        j++;
    }

    // Adiciona o terminador nulo no final da string resultante
    x[j] = '\0';

    return length;
}
int limpaEspacos(char t[]) {
    int i = 0;
    int j = 0;
    int length = 0;

    while (t[i] != '\0') {
        t[j] = t[i];
        length++;

        // Verifica se o caractere atual e o próximo são espaços
        if (t[i] == ' ' && t[i + 1] == ' ') {
            // Avança para o próximo caractere diferente
            while (t[i + 1] == ' ') {
                i++;
            }
        }
        i++;
        j++;
    }

    // Adiciona o terminador nulo no final da string resultante
    t[j] = '\0';

    return length;
}


void insere(int v[], int N, int x) {
    int i = N - 1; // Começa da última posição ordenada
    while (i >= 0 && v[i] > x) {
        // Desloca os elementos maiores para frente
        v[i + 1] = v[i];
        i--;
    }
    // Insere o novo elemento na posição correta
    v[i + 1] = x;
}


void merge(int r[], int a[], int b[], int na, int nb) {
    int i = 0; // Índice para percorrer o vetor a
    int j = 0; // Índice para percorrer o vetor b
    int k = 0; // Índice para percorrer o vetor r

    // Enquanto houver elementos nos vetores a e b
    while (i < na && j < nb) {
        // Se o elemento atual de a for menor ou igual ao elemento atual de b
        if (a[i] <= b[j]) {
            // Insere o elemento de a em r e avança para o próximo elemento de a
            r[k] = a[i];
            i++;
        } else {
            // Insere o elemento de b em r e avança para o próximo elemento de b
            r[k] = b[j];
            j++;
        }
        k++; // Avança para a próxima posição de r
    }

    // Se ainda houver elementos em a, copia-os para r
    while (i < na) {
        r[k] = a[i];
        i++;
        k++;
    }

    // Se ainda houver elementos em b, copia-os para r
    while (j < nb) {
        r[k] = b[j];
        j++;
        k++;
    }
}

int crescente(int a[], int i, int j) {
    while (i < j - 1) {
        if (a[i] > a[i + 1]) {
            return 0; // Se algum elemento estiver fora de ordem, retorna 0
        }
        i++;
    }
    return 1; // Se todos os elementos estiverem em ordem, retorna 1
}


int retiraNeg(int v[], int N) {
    int j = 0; // Índice para posicionar os elementos não negativos
    for (int i = 0; i < N; i++) {
        if (v[i] >= 0) {
            v[j] = v[i]; // Copia o elemento não negativo para a posição correta
            j++; // Incrementa o índice apenas para elementos não negativos
        }
    }
    return j; // Retorna o número de elementos não negativos após a remoção
}
int menosFreq(int v[], int N) {
    int menor_elemento = v[0]; // Elemento menos frequente
    int menor_frequencia = 1; // Menor frequência encontrada até o momento
    int contador = 1; // Contador para a frequência do elemento atual

    // Percorre o vetor a partir do segundo elemento
    for (int i = 1; i < N; i++) {
        // Se o elemento atual for igual ao anterior, incrementa o contador
        if (v[i] == v[i - 1]) {
            contador++;
        } else {
            // Se a frequência do elemento anterior for menor que a menor frequência atual,
            // atualiza o elemento menos frequente e a menor frequência
            if (contador < menor_frequencia) {
                menor_elemento = v[i - 1];
                menor_frequencia = contador;
            }
            contador = 1; // Reinicia o contador para o próximo elemento
        }
    }

    // Verifica a frequência do último elemento do vetor
    if (contador < menor_frequencia) {
        menor_elemento = v[N - 1];
    }

    return menor_elemento;
}


int maisFreq(int v[], int N) {
    int elemento_mais_frequente = v[0]; // Elemento mais frequente
    int frequencia_mais_frequente = 1; // Frequência do elemento mais frequente
    int contador = 1; // Contador para a frequência do elemento atual

    // Percorre o vetor a partir do segundo elemento
    for (int i = 1; i < N; i++) {
        // Se o elemento atual for igual ao anterior, incrementa o contador
        if (v[i] == v[i - 1]) {
            contador++;
        } else {
            // Se a frequência do elemento atual for maior que a frequência do elemento mais frequente,
            // atualiza o elemento mais frequente e a frequência mais frequente
            if (contador > frequencia_mais_frequente) {
                elemento_mais_frequente = v[i - 1];
                frequencia_mais_frequente = contador;
            }
            contador = 1; // Reinicia o contador para o próximo elemento
        }
    }

    // Verifica a frequência do último elemento do vetor
    if (contador > frequencia_mais_frequente) {
        elemento_mais_frequente = v[N - 1];
    }

    return elemento_mais_frequente;
}
 int maxCresc (int v[], int N){
    int i;
    int max = 0;
    int cres=1;

    for(i =1; i<N; i++){

        if(v[i]>= v[i-1]){
            cres++;
        } else{
            if(cres> max){
                max=cres;
                
            }
            cres=1;
        }
        
    }
    return max;
 }

int elimRep(int v[], int n) {
    if (n <= 1) {
        return n; // Se o vetor tiver 0 ou 1 elemento, não há repetições para eliminar
    }

    int novo_tamanho = 1; // Tamanho do vetor resultante (inicializado com 1 para incluir o primeiro elemento)
    
    // Percorre o vetor a partir do segundo elemento
    for (int i = 1; i < n; i++) {
        int repetido = 0; // Flag para indicar se o elemento atual já foi encontrado antes
        
        // Verifica se o elemento atual já foi encontrado antes
        for (int j = 0; j < novo_tamanho; j++) {
            if (v[i] == v[j]) {
                repetido = 1;
                break;
            }
        }
        
        // Se o elemento atual não for repetido, copia-o para a posição correta no vetor resultante
        if (!repetido) {
            v[novo_tamanho] = v[i];
            novo_tamanho++;
        }
    }

    return novo_tamanho; // Retorna o novo tamanho do vetor resultante
}


int elimRepOrd(int v[], int n) {
    int novo_tamanho = 1; // Começamos com 1 elemento, pois o primeiro elemento sempre é mantido
    int i;
    for ( i = 1; i < n; i++) {
        if (v[i] != v[i - 1]) {
            v[novo_tamanho] = v[i]; // Copia o elemento para a posição correta no vetor
            novo_tamanho++; // Incrementa o novo tamanho
        }
    }

    return novo_tamanho; // Retorna o novo tamanho do vetor resultante
}


int comunsOrd (int a[], int na, int b[], int nb){
    int i;
    int j;
    int comun=0;
for(i=0; i<na;i++){
    for (j=0; j<nb;j++){

        if(a[i]==b[j]){
            comum++;
        }
    }
}
return comun;
}

// Função para verificar se um elemento está presente em um vetor
bool estaPresente(int vetor[], int tamanho, int elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == elemento) {
            return true;
        }
    }
    return false;
}

// Função para contar elementos comuns entre dois vetores não ordenados
int comuns(int a[], int na, int b[], int nb) {
    int comuns = 0; // Inicializa o contador de elementos comuns como 0

    // Percorre os elementos do vetor a
    for (int i = 0; i < na; i++) {
        // Verifica se o elemento de a está presente em b
        if (estaPresente(b, nb, a[i])) {
            comuns++; // Incrementa o contador se o elemento estiver presente em ambos
        }
    }

    return comuns; // Retorna o número de elementos comuns
}


int minInd (int v[], int n){
    int i;
    int t;
    int menor;

    for(i=1; i<n;i++){
        if(v[i]<v[i-1]){

            menor =v[i];
            t=i;
        }
        if(menor> v[i]){

            menor=v[i];
            t=i;
        }

    }
    return t;
}

void somasAc(int v[], int Ac[], int N) {
    int soma_acumulada = 0;

   
    for (int i = 0; i < N; i++) {
        soma_acumulada += v[i];
        Ac[i] = soma_acumulada;
    }
}





#include <stdbool.h>

bool triSup(int N, float m[N][N]) {
    // Percorre a matriz abaixo da diagonal principal
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            // Se algum elemento abaixo da diagonal principal não for zero, a matriz não é triangular superior
            if (m[i][j] != 0) {
                return false;
            }
        }
    }
    // Se nenhum elemento abaixo da diagonal principal for diferente de zero, a matriz é triangular superior
    return true;
}




void transposta(int N, float m[N][N]) {
    float temp; // Variável temporária para troca de elementos

    // Percorre a matriz
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) { // Apenas elementos acima da diagonal principal
            // Troca os elementos (i, j) e (j, i)
            temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

int unionSet(int N, int v1[N], int v2[N], int r[N]) {
    // Realiza a união dos conjuntos v1 e v2
    for (int i = 0; i < N; i++) {
        // Se o elemento estiver presente em pelo menos um dos conjuntos, coloca 1 no conjunto resultante
        if (v1[i] == 1 || v2[i] == 1) {
            r[i] = 1;
        } else {
            r[i] = 0;
        }
    }
    return 0; // Retorna 0 indicando que a operação foi realizada com sucesso
}
int intersectSet(int N, int v1[N], int v2[N], int r[N]) {
    // Realiza a interseção dos conjuntos v1 e v2
    for (int i = 0; i < N; i++) {
        // Se o elemento estiver presente em ambos os conjuntos, coloca 1 no conjunto resultante
        if (v1[i] == 1 && v2[i] == 1) {
            r[i] = 1;
        } else {
            r[i] = 0;
        }
    }
    return 0; // Retorna 0 indicando que a operação foi realizada com sucesso
}

int intersectMSet(int N, int v1[N], int v2[N], int r[N]) {
    // Realiza a interseção dos multiconjuntos v1 e v2
    for (int i = 0; i < N; i++) {
        // Define o número de ocorrências no conjunto resultante como o mínimo entre as ocorrências em v1 e v2
        r[i] = (v1[i] < v2[i]) ? v1[i] : v2[i];
    }
    return 0; // Retorna 0 indicando que a operação foi realizada com sucesso
}

int cardinalMSet(int N, int v[N]) {
    int count = 0; // Inicializa o contador de elementos distintos como 0

    // Percorre o multiconjunto e conta o número de elementos distintos
    for (int i = 0; i < N; i++) {
        if (v[i] > 0) { // Se o elemento ocorrer pelo menos uma vez, conta como um elemento distinto
            count++;
        }
    }

    return count; // Retorna o número total de elementos distintos no multiconjunto
}


typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
int x, y;
} Posicao;


int caminho(Posicao inicial, Posicao final, Movimento mov[], int N) {
    int dx = final.x - inicial.x; // Calcula a diferença de coordenadas em x
    int dy = final.y - inicial.y; // Calcula a diferença de coordenadas em y

    int movimentos = abs(dx) + abs(dy); // Calcula o número total de movimentos necessários

    // Verifica se é possível atingir a posição final com N movimentos
    if (movimentos > N) {
        return -1; // Retorna um número negativo se não for possível atingir a posição final
    }

    // Preenche o array de movimentos
    int i;
    for (i = 0; i < movimentos; i++) {
        // Define o movimento necessário para cada etapa do caminho
        if (dx > 0) {
            mov[i] = Este;
            dx--;
        } else if (dx < 0) {
            mov[i] = Oeste;
            dx++;
        } else if (dy > 0) {
            mov[i] = Norte;
            dy--;
        } else {
            mov[i] = Sul;
            dy++;
        }
    }

    return movimentos; // Retorna o número de elementos preenchidos no array
}



int maisCentral(Posicao pos[], int N) {
    int indiceMaisCentral = 0; // Inicialmente, assumimos que a primeira posição é a mais central
    double menorDistancia = sqrt(pos[0].x * pos[0].x + pos[0].y * pos[0].y); // Calcula a distância da primeira posição até a origem

    // Percorre todas as posições
    for (int i = 1; i < N; i++) {
        // Calcula a distância da posição atual até a origem
        double distancia = sqrt(pos[i].x * pos[i].x + pos[i].y * pos[i].y);

        // Se a distância da posição atual até a origem for menor do que a menor distância registrada até o momento,
        // atualiza o índice da posição mais central e a menor distância
        if (distancia < menorDistancia) {
            indiceMaisCentral = i;
            menorDistancia = distancia;
        }
    }

    // Retorna o índice da posição mais central
    return indiceMaisCentral;
}



nt distanciaManhattan(Posicao p1, Posicao p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int vizinhos(Posicao p, Posicao pos[], int N) {
    int count = 0;

    // Itera sobre todas as posições no array pos
    for (int i = 0; i < N; i++) {
        // Verifica se a posição atual pos[i] é adjacente à posição p
        if (distanciaManhattan(p, pos[i]) == 1) {
            count++; // Incrementa o contador se a posição for adjacente
        }
    }

    return count;
}



typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;


int length(LInt l) {
    int count = 0; // Inicializa o contador
    LInt current = l; // Ponteiro auxiliar para percorrer a lista

    // Percorre a lista enquanto não chegar ao final (NULL)
    while (current != NULL) {
        count++; // Incrementa o contador
        current = current->prox; // Avança para o próximo nó
    }

    return count;
}

// Função para criar um novo nó na lista (apenas para exemplo)
LInt novoNo(int valor, LInt proximo) {
    LInt novo = (LInt) malloc(sizeof(struct lligada));
    if (novo != NULL) {
        novo->valor = valor;
        novo->prox = proximo;
    }
    return novo;
}


void freeL(LInt l) {
    LInt temp; // Nó temporário para manter o próximo nó antes de liberar o atual
    
    // Percorre a lista
    while (l != NULL) {
        temp = l; // Salva o endereço do nó atual
        l = l->prox; // Avança para o próximo nó
        free(temp); // Libera o nó atual
    }
}

// Função para criar um novo nó na lista (apenas para exemplo)
LInt novoNo(int valor, LInt proximo) {
    LInt novo = (LInt) malloc(sizeof(struct lligada));
    if (novo != NULL) {
        novo->valor = valor;
        novo->prox = proximo;
    }
    return novo;
}

void imprimeL(LInt l) {
    LInt current = l; // Ponteiro auxiliar para percorrer a lista
    
    // Percorre a lista
    while (current != NULL) {
        printf("%d\n", current->valor); // Imprime o valor do nó
        current = current->prox; // Avança para o próximo nó
    }
} 
LInt reverseL(LInt l) {
    LInt prev = NULL; // Ponteiro para o nó anterior, inicialmente NULL
    LInt current = l; // Ponteiro para o nó atual

    while (current != NULL) {
        LInt next = current->prox; // Salva o próximo nó antes de modificar
        current->prox = prev; // Inverte o ponteiro para o nó anterior

        // Move prev e current para a próxima posição na lista
        prev = current;
        current = next;
    }
}

void insertOrd (LInt *, int){
LInt current= *l;
LInt prev = NULL;
LInt novo =(LInt) malloc(sizeof(struct ligada));

if(novo== NULL) {
    return;
}

novo-> valor= valor;
novo-> prox = NUll;
while( current!=NULL && current->valor < valor){
    prev = current;
    current= current->prox;
}
if (prev == NULL) {
        novo->prox = *l;
        *l = novo;
    } else {
        // Insere o novo nó entre prev e current
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


void merge(LInt *r, LInt a, LInt b) {
    LInt resultado = NULL; // Lista resultante inicialmente vazia
    LInt *atual = &resultado; // Ponteiro para o último nó da lista resultante

    // Percorre ambas as listas enquanto houver elementos em ambas
    while (a != NULL && b != NULL) {
        // Compara os valores dos nós em 'a' e 'b'
        if (a->valor <= b->valor) {
            *atual = a; // Insere o nó de 'a' na lista resultante
            a = a->prox; // Avança para o próximo nó em 'a'
        } else {
            *atual = b; // Insere o nó de 'b' na lista resultante
            b = b->prox; // Avança para o próximo nó em 'b'
        }
        atual = &((*atual)->prox); // Atualiza o ponteiro para o próximo nó na lista resultante
    }

    // Adiciona os elementos restantes de 'a' ou 'b' à lista resultante
    if (a != NULL) {
        *atual = a;
    } else {
        *atual = b;
    }

    // Atualiza o ponteiro para a lista resultante
    *r = resultado;
}

void splitQS(LInt l, int x, LInt *mx, LInt *Mx) {
    *mx = NULL; // Inicializa a lista de elementos menores que x
    *Mx = NULL; // Inicializa a lista de elementos maiores ou iguais a x

    LInt atual = l; // Ponteiro para percorrer a lista original

    // Percorre a lista original
    while (atual != NULL) {
        LInt proximo = atual->prox; // Salva o próximo nó antes de reorganizar

        if (atual->valor < x) {
            // Se o valor do nó atual for menor que x, insere-o na lista de menores
            atual->prox = *mx;
            *mx = atual;
        } else {
            // Se o valor do nó atual for maior ou igual a x, insere-o na lista de maiores
            atual->prox = *Mx;
            *Mx = atual;
        }

        atual = proximo; // Avança para o próximo nó na lista original
    }
}


LLig parteAmeio(LLig *l){
    if (*l == NULL ||(*l)-> prox == NULL ){
        return NULL;

    }
    LLig slow=*l;
    LLig fast =*l;
    LLig prev_slow=NULL;
    while (fast !=NULL && fast -> prox!= NULL){
        prev_ slow = slow;
        slow = slow -> prox;
        fast = fast -> prox -> prox;
    }
    LLig s2= slow;
    if(prev_slow!=NULL){
        prev_slow-> prox= NULL;
    }
    return s2;

}
