/* 
 *
 *	Utilizando os recursos mostrados pelos usuários do stackoverflow.com
 *		     /questions/3501338/c-read-file-line-by-line
 *	
 *	por motivos de portabilidade, não foi utilizado getline() (POSIX) 
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int leitura (void)
{
	FILE*	 arq_coord; // ponteiro do tipo FILE
	char	 linha[25]; // char string declarada deve conter o NULL character
	int	 i;	   	
	arq_coord = 	fopen( "../recursos/trajetoria_bola.csv" , "r" );
	
	if(arq_coord == NULL)
	{
		puts("Não foi possível ler as coordenadas\n");
		return 1;
	}

	for( i = 0 ; fgets(linha, 25, arq_coord) ; i++ ) { // fgets retorna ponteiro NULL se encontrar EOF
		if( i > 1 ) 		// ignora a primeira linha (nomes dos eixos)
		{

   		 	 printf("%s", linha);
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
