/* 
 *
 *	Utilizando os recursos mostrados pelos usuários do stackoverflow.com
 *		     /questions/3501338/c-read-file-line-by-line
 *			Também foi utilizado:
 *
 *  https://www.codingame.com/playgrounds/14213/how-to-play-with-strings-in-c/string-split
 *  	Para entendimento de como o procedimento strtok() funciona
 *	por motivos de portabilidade, não foi utilizado getline() (POSIX) 
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convString(char* linha, char delimit[], double* pont_tempo, double* x, double* y)
{
	char* s_ponteiro	= strtok(linha, delimit); // strtok separa string por tokens e finaliza com \0, para final de linha.
	int k;
	for( k = 1 ; s_ponteiro ; s_ponteiro = strtok(NULL, delimit))
	{
		printf("%i\t%s\n", k, s_ponteiro); // tempo com k = 1, x com k = 2 e y com k = 3, converter todos num switch case ou if
		k++;
	}
}


int leitura (void)
{
	FILE*	 arq_coord; // ponteiro do tipo FILE
	char	 linha[26]; // char string declarada com 26 caracteres deve conter o NULL character
	char	 delimit[] 	= ";\n"; // separar por ";" e novas linhas
	int	 i;
	double	 xf, yf, tempo;

	arq_coord 		= fopen( "../recursos/trajetoria_bola.csv" , "r" );
	

	if(arq_coord == NULL)
	{
		puts("Não foi possível ler as coordenadas\n");
		return 1;
	}

	for( i = 0 ; fgets(linha, 26, arq_coord) ; i++ ) { // fgets retorna ponteiro NULL se encontrar EOF
		if( i > 1 ) 		// ignora a primeira linha (nomes dos eixos)
		{
			 convString( linha, delimit, &tempo, &xf, &yf);
   		 	 //printf("%s", linha);
		}
	}

	fclose(arq_coord);
	return 0;
}
int main (void)
{

	printf("Processo terminado com %i\n", leitura());
	return 0;

}
