#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void menu();
void fatorial();
void primo();
void pot();
void ano6();
void media();
void hex();
void raiz();
void nprimos();
void medpond();

int main() {
    menu();
    printf("Fim do menu.");
    return 0;
}
void menu() {
	int n = 1;
    while(n!=0) {
        printf("1 - Fatorial\n2 - Primo\n3 - Sequencia de primo\n4 - Potencia\n5 - Raiz da potencia\n6 - Ano bissexto\n7 - Media escolar\n8 - Media ponderada\n9 - Matricula em hexadecimal\n0 - Sair\n");
        scanf("%d", &n);
        switch(n) {
            case 0:
                return;
            case 1:
                fatorial();
                break;
            case 2:
                primo();
                break;
            case 3:
                nprimos();
                break;
            case 4:
                pot();
                break;
            case 5:
                raiz();
                break;
            case 6:
                ano6();
                break;
            case 7:
                media();
                break;
            case 8:
                medpond();
                break;
            case 9:
                hex();
                break;
            default:
                printf("Opcao invalida.\n \n");
        }
    }
}
 void fatorial(){
  int num, fat;

  printf("Insira um valor para o qual deseja calcular seu fatorial:\n");
  scanf("%d", &num);
  for(fat = 1;num > 1; num-=1)
    fat *= num;
  printf("Fatorial: %d\n \n", fat);
 }

 void primo(){
   int n, i, div = 0;

   printf("Informe um número para saber se é primo: \n");
   scanf("%d", &n);

   for (i = 1; i <= n; i++){
     if (n % i == 0){
       div++;
     }
   }
     if (div == 2){
      printf("O número %d é primo!\n \n", n);
     }
     else
      printf("O número %d não é primo.\n \n", n);
  }
   
    
  void pot(){
    float A, r;
    int B;

    printf("Informe a base e a potencia a qual deseja elevá-la:\n");
    scanf("%f", &A);
    scanf("%d", &B);

    r = pow(A,B);
    printf("%.2e\n \n", r);
    }
     
   
  void ano6(){
    int ano;

    printf("Informe o ano que deseja saber se é bissexto:\n");
    scanf("%d", &ano);

    if(ano%4 == 0){
     	if (ano < 2018){
			printf("O ano de %d foi bissexto!\n \n", ano);
		}
		else
			printf("O ano de %d será bissexto!\n \n", ano);
    }
    else
    	if(ano < 2018){
    		printf("O ano de %d não foi bissexto. \n \n", ano);
		}
		else
			printf("O ano de %d não será bissexto. \n \n", ano);
  }

  void media(){
    float n1, n2, med = 0.0;

    printf("Informe sua primeira nota:\n");
    scanf("%f", &n1);
    printf("Informe sua segunda nota:\n");
    scanf("%f", &n2);

    if (n1 >= 0.0 && n1 <= 10.0 && n2 >= 0.0 && n2 <= 10.0 ){
      med = (n1 + n2)/2;
      printf("Com as notas %.2f e %.2f sua media é %.2f\n \n", n1, n2, med);
    }
    else
      printf("Valor(es) inválidos.\n \n");

  } 
  void hex(){
    char nome[30];
    int matricula;

    printf("Informe seu primeiro nome: \n");
    scanf("%s", &nome);
    printf("Informe sua matricula: \n");
    scanf("%d", &matricula);

    printf("Seu nome é: %s \nE sua matricula em hexadecimal é: %X\n \n", nome, matricula);
  } 
  void raiz(){
    float v1;
    int v2,fb;

    printf("Informe a potencia que deseja saber qual é a raiz  quadrada \n");
    printf("Base: ");
    scanf("%f", &v1);
    printf("\nExpoente: ");
    scanf("%d", &v2);

    fb = pow(v1,v2);
    printf("\nA raiz quadrada da potencia em notação cientifica é : %.2e \n \n", sqrt(fb));
    }
    
    //a próxima função não funciona corretamente
    
  void nprimos(){
    int n, i, div = 0,np = 1;
  
    printf("Informe a quantidade de numeros que deseja verificar se são primos ou não: \n");
    scanf("%d",np);

  do{
   printf("Informe um número para saber se é primo: \n");
   scanf("%d", &n);

   for (i = 1; i <= n; i++){
     if (n % i == 0){
       div++;
     }
   }
     if (div == 2){
      printf("O número %d é primo!\n \n", n);
     }
     else
      printf("O número %d não é primo.\n \n", n);
    np--;
  } while(np != 0);

  }
  void medpond(){
    float nota1, nota2, nota3, media;

    printf("Insira o valor da primeira nota: ");
    scanf("%f", &nota1);
    printf("Insira o valor da segunda nota: ");
    scanf("%f", &nota2);
    printf("Insira o valor da terceira nota: ");
    scanf("%f", &nota3);
    media = (nota1*1 + nota2*1 + nota3*2)/(4);
    
    if(media >=60){
      printf("Sua media e %.2f e voce foi aprovado :D \n\n", media);
      }
    else
      printf("Sua media e %.2f e voce foi reprovado :C \n\n", media);
  }
