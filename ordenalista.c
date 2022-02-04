#include <stdio.h>
#include <stdlib.h>
 
typedef struct elemento Elemento;
struct elemento {
    int valor;
    Elemento *proximo;
    Elemento *anterior;
};
Elemento *inicio;
Elemento *fim;
int tamanho;
 
void criaLista();
Elemento *aloca(int valor);
void insereInicio(int valor);
void insereFim(int valor);
void removeInicio();
void removeFim();
void ordemCrescente();
void ordemDecrescente();
void maiorNum();
void menorNum();
void imprimeLista();
 
void criaLista() {
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
}
Elemento *aloca(int valor) {
    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}
 
void removeInicio() {
    Elemento *atual = inicio;
    inicio = atual->proximo;
    inicio->anterior = NULL;
    tamanho--;
}
void removeFim() {
    Elemento *atual = fim;
    fim = atual->anterior;
    fim->proximo = NULL;
    tamanho--;
}
 
void insereInicio(int valor) {
    Elemento *novo = aloca(valor);
    if(inicio==NULL){
        inicio=novo;
        fim=novo;
 
    }else{
        Elemento *atual;
        atual = inicio;
        novo->proximo = atual;
        atual->anterior = novo;
        inicio = novo;
    }
    tamanho++;
}
 
void insereFim(int valor) {
    Elemento *novo = aloca(valor);
    if(inicio==NULL){
        inicio=novo;
        fim=novo;
    }else{
        Elemento *atual;
        atual = fim;
        novo->anterior = atual;
        atual->proximo = novo;
        fim = novo;
    }
    tamanho++;
}
 
void imprimeLista() {
    Elemento *atual;
    atual = inicio;
    while(atual){
        printf("%d ",atual->valor);
        atual=atual->proximo;
    }
}
 
void ordemCrescente()
{
    Elemento *node=NULL, *temp = NULL;
    int tempvar;
    node = inicio;
    while(node != NULL)
    {
        temp=node; 
        while (temp->proximo !=NULL)
        {
           if(temp->valor > temp->proximo->valor) 
            {
              tempvar = temp->valor;
              temp->valor = temp->proximo->valor;
              temp->proximo->valor = tempvar;
            }
         temp = temp->proximo; 
        }
        node = node->proximo;
    }
}
 
void ordemDecrescente()
{
    Elemento *node=NULL, *temp = NULL;
    int tempvar;
    node = inicio;
    while(node != NULL)
    {
        temp=node; 
        while (temp->proximo !=NULL) 
        {
           if(temp->valor < temp->proximo->valor)
            {
              tempvar = temp->valor;
              temp->valor = temp->proximo->valor;
              temp->proximo->valor = tempvar;
            }
         temp = temp->proximo;
        }
        node = node->proximo;
    }
}
 
 
void maiorNum() {
    Elemento *atual;
    atual = inicio;
    
    int maior = 0;
    
    while(atual){
        
        if(maior < atual->valor)
            maior = atual->valor;
        
        atual=atual->proximo;
    }
    
    printf("%d\n",maior);
}
 
void menorNum() {
    Elemento *atual;
    atual = inicio;
    
    int menor = 9999999;
    
    while(atual){
        
        if(menor > atual->valor)
            menor = atual->valor;
        
        atual=atual->proximo;
    }
    
    printf("%d\n",menor);
}
 
void imprimeListaContrario() {
    Elemento *atual;
    atual = fim;
    while(atual){
        printf("%d ",atual->valor);
        atual=atual->anterior;
    }
}
 
int main() {
    criaLista();
    int i=0;
    char resposta;
    
    printf("Insira os números da lista [coloque -1 por último]:\n");

    while(i != -1 && i >= 0 && i <= 100000){
        scanf("%d", &i);
        
        if(i == -1)
            break;
        
        insereFim(i);
    }
    
    printf("'C' = ordem crescente\n'D' = ordem decrescente\n'M' = maior valor\n'm' = menor valor\nInsira a operação -> ");
    scanf(" %c", &resposta);
    
    if(resposta == 'C' || resposta == 'c'){
        
        ordemCrescente();
        imprimeLista();
        
    } else if(resposta == 'D' || resposta == 'd'){
        
        
        ordemCrescente();
        imprimeListaContrario();
        
    } else if(resposta == 'M'){
        
        maiorNum();
        
    } else if(resposta == 'm'){
        
        menorNum();
    }
    
    
    return 0;
}