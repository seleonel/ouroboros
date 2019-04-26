#ifndef LOGAR_H
#define LOGAR_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void logar(char secao[], char  var_nome[], char var_nome2[], double variavel_1, double variavel_2)
	
{

	FILE*  arq_log;
	arq_log = fopen("../logs/log", "a");
	fprintf(arq_log, "Secao: %s\n%s: %lf\t%s: %lf\n", secao, var_nome, variavel_1, var_nome2, variavel_2 );
	fclose(arq_log);

}
#endif
