/**
 * PSS Library for C
 * https://github.com/Prof-Saulo_Santos/pss-library
 * https://www.youtube.com/@profsaulosantos
 * instagram.com/profsaulosantos
 * profsaulosantos@gmail.com
 *
 * 
 * Copyright (c) 2024
 * All rights reserved
 *
 * BSD 3-Clause License
 * http://www.opensource.org/licenses/BSD-3-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * * Neither the name of PSS nor the names of its contributors may be used
 *   to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <inttypes.h>
#include <errno.h>
#include <float.h>
#include <math.h>
#include <ctype.h>

/* função privada do módulo */
static void limpa_buffer();

static void limpa_buffer() {
    int lixo;
    while ((lixo = getchar()) != '\n' && lixo != '\r' && lixo != EOF);
}

char input_c(const char *mensagem) {
    int x;
    do {
        printf("%s", mensagem);
        x = fgetc(stdin); 
        if (x == EOF) break;
        if (x == '\n') continue;
        limpa_buffer();
    } while (x == '\n'); 
    return (char)x;
}

void input_s(const char *mensagem, char *x, size_t tamanho) {	
    do {
        printf("%s", mensagem);
        if (fgets(x, (int)tamanho, stdin) == NULL) {
            x[0] = '\0';
            break;
        }
        x[strcspn(x, "\n")] = '\0';
    } while (strlen(x) == 0);
    if (strlen(x) == tamanho - 1) limpa_buffer();    
}

int input_d(const char *mensagem) {
    char aux[1024];
    char *endptr;
    long temp;
    do{
        input_s(mensagem, aux, sizeof(aux));
        if (aux[0] == '\0') return 0;
        errno = 0;
        temp = strtol(aux, &endptr, 10);
        while (isspace((unsigned char)*endptr)) endptr++;
        if (errno == ERANGE || temp < INT_MIN || temp > INT_MAX) {
            temp = (temp < 0) ? INT_MIN : INT_MAX;
        }
    }while(*endptr != '\0' || endptr == aux);
    return (int)temp;
}

float input_f(const char *mensagem) {
    char aux[1024];
    char *endptr;
    float x;
    do{
        input_s(mensagem, aux, sizeof(aux));
        if (aux[0] == '\0') return 0.0f;
        errno = 0;
        x = strtof(aux, &endptr);
        while (isspace((unsigned char)*endptr)) endptr++;
        if (errno == ERANGE) {
            if (x == HUGE_VALF) x = FLT_MAX;
            else if (x == -HUGE_VALF) x = -FLT_MAX;
        }
    }while(*endptr != '\0' || endptr == aux);
    return x;
}

long int input_ld(const char *mensagem) {
    char aux[1024];
    char *endptr;
    long int x;
    do{
        input_s(mensagem, aux, sizeof(aux));
        if (aux[0] == '\0') return 0;
        errno = 0;
        x = strtol(aux, &endptr, 10);
        while (isspace((unsigned char)*endptr)) endptr++;
        if (errno == ERANGE) {
            if (x == LONG_MAX) x = LONG_MAX;
            else if (x == LONG_MIN) x = LONG_MIN;
        }
    }while(*endptr != '\0' || endptr == aux);
    return x;
}

double input_lf(const char *mensagem) {
    char aux[1024];
    char *endptr;
    double x;
    do{
        input_s(mensagem, aux, sizeof(aux));
        if (aux[0] == '\0') return 0.0;
        errno = 0;
        x = strtod(aux, &endptr); 
        while (isspace((unsigned char)*endptr)) endptr++;
        if (errno == ERANGE) {
            if (x == HUGE_VAL) x = DBL_MAX;
            else if (x == -HUGE_VAL) x = -DBL_MAX;
        }
    }while(*endptr != '\0' || endptr == aux);
	return x; 
}

long double input_Lf(const char *mensagem) {
    char aux[5120];
    char *endptr;
    long double x;
    do{
        input_s(mensagem, aux, sizeof(aux));
        if (aux[0] == '\0') return 0.0;
        errno = 0;
        x = strtold(aux, &endptr); 
        while (isspace((unsigned char)*endptr)) endptr++;
        if (errno == ERANGE) {
            if (x == HUGE_VALL) x = LDBL_MAX;
            else if (x == -HUGE_VALL) x = -LDBL_MAX;
        }
    }while(*endptr != '\0' || endptr == aux); 
    return x; 
}