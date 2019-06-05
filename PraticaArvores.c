#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>

/*typedef struct elementos {
  int numero;	
}t_elemento;*/

typedef struct no {
  struct no * esq;
  int dado;
  struct no * dir;
}t_no;

typedef t_no* t_arvore;

void menu();
t_no * criar();
t_no * buscaSetPai(t_arvore tree, int dado, t_no ** pai);
int inserir (t_arvore *tree, int item);
int remover (t_arvore *tree, int item);
t_no * pesquisar(t_arvore tree, int dado);
void esvaziar(t_arvore *tree);
void exibir(t_arvore tree, int col, int lin, int desloc);
int compara(int dado, int dado1);
void gotoxy(int coluna, int linha);
t_no * loadTree();


int main() {
  setlocale(LC_ALL, "Portuguese");  
  menu();
  return 0;
}

void menu(){
  int n = 1, valor, i,valoresNewTree;
  t_arvore arv = loadTree();
  
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
      	system("cls");
        printf("Informe o valor que deseja inserir: ");
        scanf("%d", &valor);
        inserir(&arv, valor);
        break;
      case 2:
      	system("cls");
      	printf("Informe o valor que deseja remover: ");
        scanf("%d", &valor);
        remover(&arv, valor);
        break;
      case 3:
      	system("cls");
      	printf("Por qual valor deseja procurar?\n");
      	scanf("%d", &valor);
        pesquisar(arv, valor);
        break;
      case 4:
        esvaziar(&arv);
        break;
      case 5:
      	system("cls");
        exibir(arv, 10, 10, 3);
        printf("\n\n");
        break;
    }
  }
}

int inserir(t_arvore *tree, int item){
  int ok;
  if(*tree == NULL) {
    *tree = criar();
    if (*tree == NULL)
      return 0;
      (*tree)->dado = item;
      return 1;
    }
    
  if(compara((*tree)->dado, item) == 2)
    ok = inserir (&((*tree)->dir), item);
  else
    if (compara((*tree)->dado, item) == 1)
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

int remover (t_arvore *tree, int item){
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

t_no * buscaSetPai(t_arvore tree, int dado, t_no ** pai){
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

t_no * pesquisar(t_arvore tree, int dado){
  if(tree == NULL){
    return NULL;
  }

  if(compara(tree->dado, dado) == 0){
  	printf("O valor %d está na arvore.\n\n", dado);
    return tree;
  }

  if(compara(tree->dado, dado)!=0){
  	printf("O valor %d não está na arvore.\n\n", dado);
    return pesquisar(tree->esq, dado);
  }
  else{
    return pesquisar(tree->dir, dado);
    printf("pesquisa 3");
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
  printf("%d",tree->dado);
  if(tree->esq != NULL){
    exibir(tree->esq,col-desloc,lin+2,desloc/2+1);
  }
  if(tree->dir != NULL){
    exibir(tree->dir,col+desloc,lin+2,desloc/2+1);
  }
}

int compara(int dado, int dado1){
	int r;
  if((dado - dado1) == 0){
    r = 0;
  }
  else if((dado - dado1) > 0){
    r = 1;
  }
  else if((dado - dado1) < 0){
    r = 2;
  }
  return r;
}

void gotoxy(int coluna, int linha){
	COORD point;
	point.X = coluna;
	point.Y = linha;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

t_arvore loadTree(){
	FILE * arquivo = fopen("tree.txt", "r");
	//checa a abertura do arquivo
	if(!arquivo){
		return 0;
	}
	//aloca um ponteiro pra t_arvore
    t_no * lista = (t_no*) malloc (sizeof(t_no));
    //checa a alocação
    if(!lista) {
    	return 0;
	}
	//define o tamanho da linha
	char linha [60];
	//le a linha
	fgets(linha, 60, arquivo);
	//se o arquivo estiver vazio, printa mensagem e retorna 0
	if(feof(arquivo)) {
      printf("Não há dados para serem inseridos na árvore.\n");
      return 0;
	}
	//variavel para receber o valor do número lido no arquivo, separando-os nas virgulas
	char * valor = strtok(linha, ",");
	//convertendo o valor obtido anteriormente e atribuindo-o ao dado da arvore
	lista->dado = atoi(valor);
	//auxiliar pra não perder o anterior
	t_no * aux = lista;
	
	//enquanto não for o fim do arquivo, repete o processo anterior
	while(!feof(arquivo)){
        t_no * novo = (t_no*) malloc (sizeof(t_no));
            
        if(!novo) {
        	return 0;
		}

        novo->dado = atoi(strtok(linha, ","));
        inserir(&lista, novo->dado);
        fgets(linha, 60, arquivo);
    }
    fclose(arquivo);
    return lista;
}
