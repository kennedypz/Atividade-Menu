#include <stdio.h>
#include <stdlib.h>

//copiado do codigo que escrevi no Repl.it, se houver problemas de identacao este é o motivo.
//código com o intuito de recriar as funcoes strcpy, strcmp, strcat, e strlen.

void menu();
int tamanho; //declarei essa varial global para que ele assuma o valor do tamanho das strings e possa ser usada em outros escopos.
int comprimento_string(char*x);
char copiar_string(char* s1);
int comparar_string(char* s1, char* s2);
char concatenar_string(char*s1, char* s2);

int main(){

  char* y = "batata";
  char* q = "barreira";

  copiar_string(q);
  comprimento_string(y);
  printf("Sua string contem %d caracteres.\n\n", tamanho); //optei por colcoar o printf aqui pra não aparecer quando eu chamar outras funçoes que tambem precisam do tamanho de strings.
  comparar_string(y, q);
  concatenar_string(y, q);
  return 0;
}

int comprimento_string(char*x){
  int t;

  for(t = 0; x[t] != '\0'; t++);
  tamanho = t;
  return t; //esse return não retorna nada ¯\_(?)_/¯
}

char copiar_string(char*s1){
  int i, t;

  comprimento_string(s1); //Usando a função criada para saber o comprimento da string para que seja feita uma alocação dinamica.
  
  char* s2 = ((char*) malloc(t + 1 * sizeof(char)));

  if(!s2){
    return 0;
  }

  for(i = 0; i < tamanho; i++){
  s2[i] = s1[i];
  }
  printf("A palavra digitada foi: %s\n\n", s2);
}

int comparar_string(char* s1, char* s2){
  int i, tam1, tam2, resultado;
  char *x, *g;

  //Usando a função criada para saber o comprimento das strings para saber até onde meu loop 'for' deve ir.
  tam1 = comprimento_string(s1);
  tam2 = comprimento_string(s2);

  for(i = 0; i < tam1 && i < tam2; i++){

    if(s1[i] != s2[i]){
      resultado = 1;
    }
    else
      resultado = 0;
  }

  if (resultado == 1){
    printf("As strings são diferentes.\n\n");
  }
  else {
    printf("As strings são iguais.\n\n");
  }
}

char concatenar_string(char*s1, char* s2){
  int i, tam1, tam2;

  tam1 = comprimento_string(s1);
  tam2 = comprimento_string(s2);

  char* string_concatenada = (char*) malloc((tam1 + tam2) *sizeof(char));
  //alocando um espaço na memoria do tamanho da soma da quantidade de caracteres das duas strings.

  for(i = 0; i < tam1; i++){
    string_concatenada[i] = s1[i];
  }

  for(int j = 0; j < tam2; j++){
    string_concatenada[i + j] = s2[j];
  }
  printf("Ao juntarmos as duas strings obtemos: %s\n\n", string_concatenada);
}
