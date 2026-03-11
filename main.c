#include "pss.h"
#include <stdio.h>

int main(){

    char c;         // 1 caractere                      
    int  d;         // inteiro                      
    long int ld;    // inteiro longo          
    float    f;     // float                   
    double lf;      // double                  
    long double Lf; // long double 
    char s[10];     // string de 10 caracteres  

    c =  input_c("Digite um char: ");                 
    d =  input_d("Digite um inteiro: ");              
    ld = input_ld("Digite um inteiro longo: ");       
    f =  input_f("Digite um float: ");                
    lf = input_lf("Digite um double: ");              
    Lf = input_Lf("Digite um long double: "); 
    input_s("Digite uma string: ",s,sizeof(s)); 

    printf("%c\n",c);
    printf("%d\n",d);
    printf("%ld\n",ld);
    printf("%f\n",f);
    printf("%lf\n",lf);
    printf("%Lf\n",Lf);
    printf("%s\n",s);
    return 0;
}
