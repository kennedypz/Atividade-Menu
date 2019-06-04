#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>

typedef struct elementos {
  int numero;	
}t_elemento;

typedef struct no {
  struct no * esq;
  t_elemento dado;
  struct no * dir;
}t_no;

typedef t_no* t_arvore;

void menu();
t_no * criar();
t_no * buscaSetPai(t_arvore tree, t_elemento dado, t_no ** pai);
int inserir (t_arvore *tree, t_elemento item);
int remover (t_arvore *tree, t_elemento item);
t_no * pesquisar(t_arvore tree, t_elemento dado);
void esvaziar(t_arvore *tree);
void exibir(t_arvore tree, int col, int lin, int desloc);
int compara(t_elemento dado, t_elemento dado1);
void gotoxy(int coluna, int linha);


int main() {
  setlocale(LC_ALL, "Portuguese");  
  menu();
  return 0;
}

void menu(){
  int n = 1, valor, i,valoresNewTree;
  t_arvore *arv;
  
  /*for(i = 0; i <10; i++){
  	srand(time(NULL));
    rand();
	(*arv)->dado.numero = rand() % 100;
  	inserir(&(*arv), (*arv)->dado);
  }*/
  
  while(n != 0){
    printf("------------------------------------------------\n");
    printf("|ALUNO: PAULO KENNEDY TAVARES REIS/1810023234  |\n");
    printf("|DISCIPLINA: ESTRUTURA DE DADOS I              |\n");
    printf("|PROFESSOR: WALACE BONFIM                      |\n");
    printf("|                                              |\n");
    printf("|            EDITOR DE ÁRVORE                  |\n");
    printf("|                                              |\n");
    printf("|1 - INSERIR                                   |\n");
    printf("|2 – REMOVER APENAS UM NÓ                      |\n");
    printf("|3 – PESQUISAR                                 |\n");
    printf("|4 – ESVAZIAR A ÁRVORE                         |\n");
    printf("|5 – EXIBIR A ÁRVORE                           |\n");
    printf("|0 - SAIR                                      |\n");
    printf("------------------------------------------------\n");
    scanf("%d", &n);

    switch(n){
      case 0:
        printf("Programa encerrado.");
        return;
      case 1:
        printf("Informe o valor que deseja inserir: ");
        scanf("%d", &valor);
        //inserir();
        break;
      case 2:
        //remover();
        break;
      case 3:
        //pesquisar();
        break;
      case 4:
        //esvaziar();
        break;
      case 5:
        //exibir();
        break;
    }
  }
}

int inserir (t_arvore *tree, t_elemento item){
  int ok;
  if(*tree == NULL) {
    *tree = criar();
    if (*tree == NULL)
      return 0;
      (*tree)->dado = item;
      return 1;
    }
  if(compara((*tree)->dado, item) < 0)
    ok = inserir (&((*tree)->dir), item);
  else
    if (compara((*tree)->dado, item)>0)
      ok = inserir (&((*tree)->esq), item);
      else
        ok = 0;
    return ok;
}

t_no * criar(){
  t_no * no = (t_no*) malloc(sizeof(t_no));

  if(no){
    no->esq = no->dir = NULL;
  }
  return no;
}

int remover (t_arvore *tree, t_elemento item){
  t_no *no, *pai, *sub, *paiSuce, *suce; 
  
  no = *tree; pai=NULL;
  no = buscaSetPai(*tree, item, &pai);
    
  if(no==NULL){
    return 0; 
  }
  
  if(no->esq == NULL){
    sub = no->dir;
  }
  else{
    if(no->dir == NULL){
      sub = no->esq;
    }
  }
  
  if(pai == NULL){
    *tree = sub;
  }
  else{
    if(no == pai->esq){
      pai->esq = sub;
    }
    else{
      pai->dir = sub;
    }
  }
  free(no); 
  return 1;
}

t_no * buscaSetPai(t_arvore tree, t_elemento dado, t_no ** pai){
  if(tree == NULL) {
    *pai = NULL;
    return NULL;
  }
  
  if(compara(tree->dado, dado)==0){
    return tree;
  }

  if(compara(tree->dado, dado)>0) {
    *pai = tree;
    return buscaSetPai(tree->esq, dado, pai);
  }
  else {
    *pai = tree;
    return buscaSetPai(tree->dir, dado, pai);
  }
}

t_no * pesquisar(t_arvore tree, t_elemento dado){
  if(tree == NULL){
    return NULL;
  }

  if(compara(tree->dado, dado)==0){
    return tree;
  }

  if(compara(tree->dado, dado)>0){
    return pesquisar(tree->esq, dado);
  }
  else{
    return pesquisar(tree->dir, dado);
  }
}

void esvaziar(t_arvore *tree){
  if (*tree == NULL){
    return;
  }
  esvaziar(&(*tree)->esq);
  esvaziar(&(*tree)->dir);
  free(*tree);
  *tree = NULL;
}

void exibir(t_arvore tree, int col, int lin, int desloc){
  if(tree == NULL){
    return;
  }
  gotoxy(col,lin);
  printf("%d",tree->dado.numero);
  if(tree->esq != NULL){
    exibir(tree->esq,col-desloc,lin+2,desloc/2+1);
  }
  if(tree->dir != NULL){
    exibir(tree->dir,col+desloc,lin+2,desloc/2+1);
  }
}

int compara(t_elemento dado, t_elemento dado1){
  int n1, n2;
  n1 = dado.numero;

  if(dado.numero == dado1.numero){
    return 0;
  }
  else{
    return 1;
  }
}

void gotoxy(int coluna, int linha){
	COORD point;
	point.X = coluna;
	point.Y = linha;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
