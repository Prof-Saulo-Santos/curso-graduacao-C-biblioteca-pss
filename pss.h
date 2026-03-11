#ifndef PSS_H
#define PSS_H

#include <stddef.h>

char input_c(const char *mensagem);
void input_s(const char *mensagem, char *x, size_t tamanho);
int input_d(const char *mensagem);
float input_f(const char *mensagem);
long int input_ld(const char *mensagem);
double input_lf(const char *mensagem);
long double input_Lf(const char *mensagem);

#endif