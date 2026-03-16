#include "pss.h"
#include <stdio.h>

int main(){

    char sexo;         // 1 caractere                      
    int  idade;         // inteiro                      
    long int quantidade_de_pessoas;    // inteiro longo          
    float  altura;     // float                   
    double salario;      // double                  
    long double variavel_cientifica; // long double 
    char nome[10];     // string de 10 caracteres  

    sexo =  input_c("Digite o sexo: ");                 
    idade =  input_d("Digite a idade: ");              
    quantidade_de_pessoas = input_ld("Digite a quantidade de pessoas: ");       
    altura =  input_f("Digite a altura: ");                
    salario = input_lf("Digite o salario: ");              
    variavel_cientifica = input_Lf("Digite a valor cientifico: "); 
    input_s("Digite o nome: ",nome,sizeof(nome)); 
    idade =  input_d("Digite a idade: "); 

    printf("Sexo = %c\n",sexo);
    printf("Idade = %d\n",idade);
    printf("Quantidade de pessoas = %ld\n",quantidade_de_pessoas);
    printf("Altura = %f\n",altura);
    printf("Salario = %lf\n",salario);
    printf("Variavel cientifica = %Lf\n",variavel_cientifica);
    printf("Nome = %s\n",nome);
    printf("Idade = %d\n",idade);
    return 0;
}
