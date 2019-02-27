/*
 *	Programa principal para execuçao em linux
 *	servirá de base para o programa para o windows (conterá system pause e dependencias ( binarios ))
 *	
 *
 */


#include <stdio.h>
#include <math.h>
#define VELOCMAX 300 //valor de velocidade máxima do smallsize
#define	ACELMAX 200 // valor de aceleração máxima do smallsize


/* posicao em tempo real da bola, recebida pelo prog através dos métodos discutidos */
/* talvez ponteiros para definir */
double posicBola(int x, int y, int r) // raio r (descontar do valor de raio de interferencia) 
{


}


/* funcao para retornar velocidade instantanea retorna valor double? */
/* usar ponteiros para retornar valores de velocidade inst e velocidade media? Se sim, unificar funcoes */
double velInst(int x, int y)
{
	/* funcao "tira" a derivada da velocidade, talvez enviada por outra funcao (ponteiro)   */
	return velocidade_inst;
}

double velMed(int x, int y)
{
	/* funcao realizada inicialmente para velocidade média */


}

/* recebe do wrapper python os parametros de funcao  
 * receber como array?
   receber no terminal "stdin"
   como fazer no windows?
 * receber como documento texto 
 */

int main (void)
{
	

	
	return 0;
}
