#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include<ctype.h>
#include <math.h>
#define N 100


typedef struct {
    char saida[N];
    int cont;
}fila;

typedef struct {
    char token[N];
    int topo ;
    
}Pilha;

typedef struct{
    float resultfloat[N];
    int tpfloat; 

}pilhafloat; 


void limpar_fila(fila *f);
 void limpar_float(pilhafloat *pf);
void limpar_pilha(Pilha *p) ;
int exp_mal_form(char *x);
int pilha_vazia(Pilha *p);
int pilha_cheia(Pilha *p);
void fila_inicia(fila *p1);
void pilha_inicia(Pilha *p);
char pilha_remover(Pilha *p);
int float_vazia(pilhafloat *pf);
void float_inicia(pilhafloat *pf);
char remover_antecessor(Pilha *p);
int float_cheia(pilhafloat *pf);
void pilha_push(Pilha *p , char x );
int verificador_de_pareteses(char *x);
void  float_empilha(pilhafloat *pf , float x );
int precedencia_char(char c , char c1);
float float_remover(pilhafloat *pf);
void shunting_yard( Pilha *p, fila *p1,char x[]);
float resultado_shinting_year(pilhafloat *pf ,fila *p1);
float operacao_shanting_year(float c2 , float c1,char c);


   int main( ){
   char aux ;
   char armando[N];
   char *telma;
   int cont2=-100;
   float result;
   
   Pilha p ; 
   fila p1 ;
   pilhafloat pf ;  
    
  pilha_inicia(&p);
  fila_inicia(&p1);
  float_inicia(&pf);
  
  FILE *arquivo, *arquinovo ;
  arquivo = fopen("/storage/emulated/0/Download/CodingC/textetokem/in.txt","r");
  arquinovo = fopen("/storage/emulated/0/Download/CodingC/textetokem/out.txt","w");
    
  if(arquivo == NULL){
      printf("erro ao abri o arquivo ");
      return 0;
  }
  if(arquinovo == NULL){
      printf("erro ao abri o arquivo para saida  ");
      return 0;
  }
    
  printf("início \n");
    
  while(fscanf(arquivo,"%s \n",armando) != EOF){
  
          cont2 = exp_mal_form(&armando);
          if(cont2==1){
              fputs("ERRO : caracteres invalido \n",arquinovo);
              limpar_fila(&p1);
              limpar_pilha(&p);
              limpar_float(&pf);
              continue;
          }else{
              cont2 = verificador_de_pareteses(&armando);
              printf(" valor do cont2 %d \n",cont2);
              if(cont2==0){
                   fputs( "ERRO : parenteses desbalanciado \n",arquinovo);
                   limpar_fila(&p1);
                   limpar_pilha(&p);
                   limpar_float(&pf);
                   continue;
              }else{
                    shunting_yard(&p , &p1, &armando );
                    result = resultado_shinting_year(&pf , &p1);
                    if(result == 404.0 || result == 404){
                          fputs( "ERRO : divisao por zero 0 \n",arquinovo);
                          limpar_fila(&p1);
                          limpar_pilha(&p);
                          limpar_float(&pf);
                          continue;
                    }else{
                        telma= malloc(10);
                        sprintf(telma,"%.1f", result);
                        printf("obrigado Deus  %s \n",telma);
                        
                    }
              }
          }
          fprintf(arquinovo,"\n %s \n",telma);
          free(telma);
          fila_inicia(&p1);
          limpar_fila(&p1);
          limpar_pilha(&p);
          limpar_float(&pf);

  }
  
   
  fclose(arquivo);
  fclose(arquinovo);
  printf("FIM DO PROGRAMA SUCESSO  \n");
   
   return 1;
   
  }// fim main 
  
  
  // funcao para iniciar a posicao da pilha e saida 
void pilha_inicia(Pilha *p){
    p->topo=-1;
}
void fila_inicia(fila *p1){
    p1->cont=-1;
}
//=============== função para limpar o lixo dos dados 
void limpar_pilha(Pilha *p) {
    memset(p->token, 0, sizeof(p->token));
    p->topo = -1;
}
          
 void limpar_float(pilhafloat *pf) {
    memset(pf->resultfloat, 0, sizeof(pf->resultfloat));
    pf->tpfloat = -1;
}
          

void limpar_fila(fila *f) {
    memset(f->saida, 0, sizeof(f->saida));
    f->cont = -1;
}         
  
//=======================================
// para ver se a pilha esta vazia 
int pilha_vazia(Pilha *p){
   if(p->topo==-1){ return 1;
   }else{ return 0; }
}

// se a pilha esta cheia  retorna 0 se nao 1 
int pilha_cheia(Pilha *p){
    if(p->topo==N-1){
        printf("erro...! a pilha esta cheia \n");
        return 1;
    }else{  return 0; }
}

// funcao para empilhar um caracter  do tipo ()[]
void  pilha_push(Pilha *p , char x ){
    if(pilha_cheia(p) == 1){
         printf("erro pilha cheia \n");
    }else{
       p->topo++;
       p->token[p->topo]=x;    
    }
    printf(" empilha %c \n",x);
}

// funcao para remover 
char pilha_remover(Pilha *p){
    char x;
    if(pilha_vazia(p) == 1){
        printf("a pilha esta vazia \n");
        return 0;
    }else{
        x = p->token[p->topo];
        p->topo--;
        printf(" os que foram removido da pilha %c \n",x);
    }
    return x;
}


// funcao para remover 
char remover_antecessor(Pilha *p){
    char x;
    if(pilha_vazia(p) == 1 || p->topo<0){
        printf("a pilha antecessor esta vazia \n");
        return 0;
    }else{
        x = p->token[p->topo];
      //  printf(" os que foram removido da pilha1 antecessor %c \n",x);
    }
    return x;
}


void float_inicia(pilhafloat *pf){
    pf->tpfloat=-1;
}
// para ver se a pilha esta vazia 
int float_vazia(pilhafloat *pf){
   if(pf->tpfloat==-1){ 
   printf("erro pilhafloat vazio \n");
   return 1;
   }else{ return 0; }
}

// se a pilha float esta cheia  retorna 0 se nao 1 
int float_cheia(pilhafloat *pf){
    if(pf->tpfloat==N-1){
        printf("erro...! a pilha float esta cheia \n");
        return 1;
    }else{  return 0; }

}

void  float_empilha(pilhafloat *pf , float x ){
    if(float_cheia(pf) == 1){
         printf("erro pilha cheia \n");
    }else{
       pf->tpfloat++;
       pf->resultfloat[pf->tpfloat]=x;    
       printf(" empilha %.2f \n",x); 
    }
    
}

// funcao para remover 
float float_remover(pilhafloat *pf){
    float x;
    if(pilha_vazia(pf) == 1){
        printf("a pilha esta vazia \n");
        return 0;
    }else{
        x = pf->resultfloat[pf->tpfloat];
        pf->tpfloat--;
        printf(" os que foram removido da pilha float %.1f \n",x);
    }
    return x;
}







// funcao para verificar se a expressao esta bem formado  se sim retorna 1 se nao retorna 0 
int verificador_de_pareteses(char *x){
        printf("\n\n\nverificador_de_pareteses  \n\n\n");
        int b=0,i=0,u=0;
        char c;
        u=strlen(x);
        int val=0; 
        while(i<=u) {
            c = x[i];
            b = ispunct(c);
            if(b!=0 ){
                if(c =='(' || c =='[' || c =='{' ||c == ']' || c == ')'|| c =='}' ){ 
                val+=1;
            }
        }
        i++;
        }
        
        if(val%2==0){
            return 1;
        }else{
            return 0; 
        }
        
}
    
// funcao para ver se a expressao contem letra 
    
    
    int exp_mal_form(char *x){
    printf("\n\n\nfuncao para expressão mal formado  \n\n\n");
    int d,i=0,u=0;
    u= strlen(x);
    char c;
         while(i<=u){
         printf("%c \n",c);
            c = x[i];
            d = isalpha(c);
            if(d!=0 &&  !(c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}')) {
                 return 1;
            }
            i++; 
         }
         return 0;    
    }
    
void shunting_yard(Pilha *p, fila *p1, char *x){
printf("\n\n\nfuncao shunting_yard \n\n\n");
    int a,b,l,v;   
    int tm =  strlen(x);
    int i =0;
    char c,c1,c2;

    while(i<tm){
            c= x[i];
            a= isspace(c); 
            if(a!=0){
                i++;
                continue;
            }else{
                 b= isdigit(c); 
                 if(b!=0){
                      p1->cont++;
                      p1->saida[p1->cont]=c;
                 }else{ 
                      l = ispunct(c);
                      if(l!=0){
                          if(c == ']' || c == ')'|| c =='}'){  
                               do{        
                                  c1= pilha_remover(p);       
                                  if(c1!='(' && c1 !='[' && c1 !='{'){   
                                      p1->cont++;
                                      p1->saida[p1->cont]=c1;
                                  }
                                 
                               }while(c1!='(' && c1 !='[' && c1 !='{'); 
                       
                          }else{
                              if(pilha_vazia(p) != 1 && p->topo>0){
                                   c2 = remover_antecessor(p);
                                   v = precedencia_char(c,c2);
                                   if(v!=0){
                                           c1= pilha_remover(p);  
                                           p1->cont++;
                                           p1->saida[p1->cont]=c1;
                                           pilha_push(p,c);
                                   }else {
                                           pilha_push(p,c);
                                   }
                              } else{
                                  pilha_push(p,c);
                              }    
                        
                          }
                    
                      }
                 }
            }
            i++;
    }
    
    while(pilha_vazia(p)==0){
       c1= pilha_remover(p);
       if (!(c1 == '(' || c1 == ')' || c1 == '[' || c1 == ']' || c1 == '{' || c1 == '}')) {
            p1->cont++;
            p1->saida[p1->cont]=c1;
       }
    }
    c1= pilha_remover(p);

}// fim função shanting year 



    
    
    
    
int precedencia_char(char c, char c1) {
   printf("\n\n\n precedencia_char  \n\n\n");
   int p1, p2;
   if( c=='(' || c=='[' || c =='{' || c == ']' || c== ')'|| c =='}' ){  return 0;}
    
   if (c == '+' || c == '-'){
        p1 = 1; 
   }else{ 
        if (c == '*' || c == '/') {
            p1 = 2;
        }else{ 
            if (c == '^') {
                p1 = 3;
            } else{
                 p1 = 0;
            }
        }
   } 
     
   if (c1 == '+' || c1 == '-'){ 
       p2 = 1;
   }else{
       if(c1 == '*' || c1 == '/') {
           p2 = 2;
       }else{ 
          if (c1 == '^'){
               p2 = 3;
          }else {
                 p2 = 0;
          }
       }
   }   
    
  
   if (p1 <= p2){
        return 1;
   }else{
        return 0;
   }
}// fim precedencia_char
    
    
float resultado_shinting_year(pilhafloat  *pf ,fila *p1 ){
printf("\nresultado_shinting_year \n\n\n");
     int a=0,b=0;
     char c;
     float c1=0,c2=0;
     float conv=0;
     float val=0;
     int  i= 0; 
     while(p1->saida[i]!='\0'){
         printf("resultado digito da saída %c \n", p1->saida[i]);
         i++;
     }
     i=0;           
                    
     while(p1->saida[i]!='\0'){
           c= p1->saida[i];
           a= isdigit(c);
           if(a!=0){
               conv = (float)(c-'0') ;
               float_empilha(pf,conv);
           }else {
              c1 = float_remover(pf); // último 
              c2 = float_remover(pf);// penúltimo 
              val = operacao_shanting_year(c2 , c1, c );
              printf("resultado depois da operação   shanting year%.2f \n",val);
              if(val == 404.0){
                  printf("erro divisao por zero \n");
                  return 404.0;
              }
              float_empilha(pf,val);    
           } 
           i++;
     } 
     
     while(float_vazia(pf)!=0){
       val = float_remover(pf); 
     }          
     return val; 
}// fim   resultado_shinting_year


float operacao_shanting_year(float c2 , float c1,char c){
printf("\n\n\noperacao_shanting_year  \n\n\n");
printf("char saio c2=[%.1f]    c1=[%.1f]   c=[%c] \n",c2, c1, c);
        float b,a;
        float result;
        a = c2;
        b = c1; 
        if(c1==0 && c2==0 && c=='/'){  return 0.0;} 
        
        printf("valor de a [%.1f] \n",a);
        printf("valor de b [%.1f] \n",b);
        switch(c){
            case '+':
                printf(" soma %c\n",c);
                result = a+b;
                return  result;
            break; 
            case '-':
                 printf(" subtração %c\n",c);
                result=a-b;
                return result;
            break;
            case '*':
                 printf(" multiplicação %c\n",c);
                result = a*b;
                return result; 
            break;
            case '/':
                if( b == 0){
                    printf("erro divisao por zero 0\n");
                    return 404.0;
                }else{
                     printf(" divisão %c\n",c);
                     result = a/b;
                }
                return result ;
            break;
            case '^':
                 printf(" exponencial %c\n",c);
                result = pow(a,b);
                return result;
            break;
            default : 
            printf("\t expressao mal formada  \n");
        }

}


    
