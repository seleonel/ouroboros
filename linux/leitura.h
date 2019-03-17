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

#ifndef LEITURA_H
#define LEITURA_H
void convString(char* linha, char delimit[], double* pont_tempo, double* x, double* y)
{
	char* s_ponteiro	= strtok(linha, delimit); // strtok separa string por tokens e finaliza com \0, para final de linha.
	int k = 1;
	
	for( k = 1 ; s_ponteiro != NULL ; s_ponteiro = strtok(NULL, delimit))
	{
	
		switch(k){
			case 1: *pont_tempo = strtod(s_ponteiro, NULL); // k valendo 1 equivale ao tempo 
			case 2:	*x = strtod(s_ponteiro, NULL);	// k como 2 é x
			case 3: *y = strtod(s_ponteiro, NULL);		// k como 3 é y
		}
		k++;
	}
		
}


int leitura (double tempo[], double xf[], double yf[])
{
	double	 tempo_unico, x_un, y_un;
	tempo_unico = x_un = y_un = 0.0f;
	FILE*	 arq_coord; // ponteiro do tipo FILE
	char	 linha[30]; // char string declarada com 26 caracteres deve conter o NULL character
	char	 delimit[] 	= ";\n"; // separar por ";" e novas linhas
	int	 i;

	arq_coord 		= fopen( "../recursos/trajetoria_bola.csv" , "r" );
	

	if(arq_coord == NULL)
	{
		puts("Não foi possível ler as coordenadas\n");
		return 1;
	}

	for( i = 0 ; fgets(linha, 30, arq_coord) ; i++ ) { // fgets retorna ponteiro NULL se encontrar EOF
	
		{
			convString( linha, delimit, &tempo_unico, &x_un, &y_un );
			// grava cada dado convertido num vetor específico definido na função principal 
			tempo[i] 	 = tempo_unico;
			xf[i] 	 = x_un;
			yf[i]	 = y_un;
	 					 
		}
	}

	fclose(arq_coord);
	return 0;
}
#endif
