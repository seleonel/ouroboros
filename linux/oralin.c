/*
 *	Este programa simula as ações de um robô jogador de futebol e plota os respectivos gráficos
 *	
 *	Copyright (C) 2019  Leon Bellini, Guilherme Ormond
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <https://www.gnu.org/licenses/>.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "leitura.h"
#define NUM_LINHAS 367
/* 
 * Mais tardiamente, poderá ser adicionada a biblioteca SDL, a gameengine pedida
 */

// funcoes podem ser "jogadas" num header para mais limpeza
void definicaoPosRobo(float *r_x0, float *r_y0)
{
	/*
	 * Primeiro contato com usuário, serão pedidas as coordenadas x e y iniciais
	 * Se possível, evitar utilizar scanf (buffer overflow), fgets() será implementado mais tarde
	 */ 
	puts("Insira um valor para X e Y iniciais para o robô");	
	scanf("%f %f", r_x0, r_y0);

}





void plotGraficos()
{
	/* 
	 * nos utilizaremos do gnuplot, binario ja na pasta 
	 * de nosso programa
	 */


}

int main (void)

{
	int i;
	 //  Serão determinadas dimensões do robô e da bola

	// determinado pelo comitê da robocup como limite 0,18 metros de raio
	float raio_robo = 0.180f;

	// determinado pela força aplicada sobre a bola
	float dist_bounce = 0.0f;

	//padrões de uma bola de golfe 
	float raio_bola = 0.046f;    
	float raio_interc = raio_robo + raio_bola + dist_bounce; // bola sob o domínio do robo
	
	float vel_robo = 6.5f; // 6,5 m/s como limite determinado pela robocup
	
	// posicoes iniciais e momentaneas x e y do robo
	float robo_x0, robo_y0, robo_x, robo_y;
	// utilizaremos ponteiros
//	definicaoPosRobo(&robo_x0, &robo_y0);	
	
	// posicao da bola sera determinada pela leitura do arquivo txt, também serão usados ponteiros
	double bola_tempo[400]	= {};
	double bola_x[400] 	= {};
       	double bola_y[400] 	= {};
	int controle = leitura(bola_tempo, bola_x, bola_y); // funcao leitura le cada linha do arquivo, erros são guardados em controle
	for(i = 2 ; i < NUM_LINHAS ; i ++) 
		printf("tempo: %f x: %.8f y: %f\n", bola_tempo[i], bola_x[i], bola_y[i]);
		

	// última função antes da finalização do programa
	plotGraficos();
	
	return 0;
}
