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
#include "plotar.h"
// nosso header contendo a estrutura de medidas do robo e bola
#include "elementos.h"
#define NUM_LINHAS 367
#define LINHA_INIC 2
/*
 * Mais tardiamente, poderá ser adicionada a biblioteca SDL, a gameengine pedida
 */

// funcoes podem ser "jogadas" num header para mais limpeza
void definicaoPosRobo(elementos *r)
{
	double x0, y0;
	/*
	 * Primeiro contato com usuário, serão pedidas as coordenadas x e y iniciais
	 * Se possível, evitar utilizar scanf (buffer overflow), fgets() será implementado mais tarde
	 */
	puts("Insira um valor para X e Y iniciais para o robô\n");
	scanf("%lf", &x0);
	scanf("%lf", &y0);
	r->x[LINHA_INIC] = x0;
	r->y[LINHA_INIC] = y0;

}

void definicaoDirRobo(int* mpx, int* mpy,
	              double robo_x0, double robo_y0,
		      double bola_x0, double bola_y0)
{
	if (robo_x0 > bola_x0)
	{
    	*mpx = -1;
    		if(robo_y0 > bola_y0)
        		*mpy = -1;
    		else
        		*mpy = 1;
 	}else
	{
    		*mpx = 1;
    		if(robo_y0 > bola_y0)
       			*mpy = -1;
    		else
        		*mpy = 1;

	}
}

void definicTempoRobo(elementos *Robo, float *menorTempo,int iterador, float v_m)
{
	double tempo_final;
	tempo_final = Robo->distancia[iterador] / v_m;
	if (tempo_final < *menorTempo)
		*menorTempo = tempo_final;
}

void definicMovRobo(elementos *Bol, elementos *Rob, int *versor_x, int *versor_y, float raio_interc, float vel_max )
{
	// começamos por pitagoras
	// distancia é a hipotenusa
	double rob_x0 = Rob->x[LINHA_INIC];
	double rob_y0 = Rob->y[LINHA_INIC];
	double rob_xf, rob_yf, rob_tempos[NUM_LINHAS];
	float menorTempo = 100;
	int i;
	// calcular todas as distancias possíveis
	for(i = LINHA_INIC; i < NUM_LINHAS; i++)
	{
		rob_xf = Bol->x[i];
		rob_yf = Bol->y[i];
		Rob->distancia[i] = (sqrt(pow(( rob_xf - rob_x0)  , 2) + pow(( rob_yf - rob_y0), 2))) - raio_interc;
		definicTempoRobo(Rob, &menorTempo, i, vel_max);
	}

	for(i = LINHA_INIC ; i < NUM_LINHAS ; i++){
		if ((menorTempo == Bol->tempo[i])) {
			rob_xf = Bol->x[i];
			rob_yf = Bol->y[i];
		}
		else if ((menorTempo > Bol->tempo[i]) && (menorTempo < Bol->tempo[i+1])) {
			Rob->x[3] = Bol->x[i];
			Rob->y[3] = Bol->y[i];
		}
	}
	printf("O ponto de encontro da bola e o robô é X: %f, Y: %f\n", Rob->x[3], Rob->y[3]);
}

int main (void)

{

	elementos bola, robo;
	// para for loops
	int i;
	float raio_interc = raio_robo + raio_bola + dist_bounce; // bola sob o domínio do robo

	// zero os vetores da bola e robo
	for(i = 0; i < 400; i++)
		bola.tempo[i] = bola.x[i] = bola.y[i] = robo.x[i] = robo.y[i] = robo.tempo[i] = 0;

	// definiçao das posições iniciais do robo (vetor no indice 2)
	definicaoPosRobo(&robo);
	// define o versor para posição inicial, função será utilizada novamente
	definicaoDirRobo(&multipx, &multipy, robo.x[LINHA_INIC], robo.y[LINHA_INIC], bola.x[LINHA_INIC], bola.y[LINHA_INIC]);
	int controle = leitura(bola.tempo, bola.x, bola.y); // funcao leitura le cada linha do arquivo, erros são guardados em controle
	definicMovRobo(&bola, &robo, &multipy, &multipx, raio_interc, vel_robo);
	// testes
	//
	// teste para ver dados da bola
	//for(i = LINHA_INIC ; i < NUM_LINHAS ; i ++)
	//	printf("tempo: %f x: %.8f y: %f\n ", bola.tempo[i], bola.x[i], bola.y[i]);

	// teste para ver posição inicial do robo
	//	printf("robo: %f %f\n", robo.x[LINHA_INIC], robo.y[LINHA_INIC]);

	// teste para visualizar os versores
	// 	printf("Versor em Y: %d Versor em X: %d\n", multipy, multipx);


	// última função antes da finalização do programa
	plotGraficos(bola.tempo, bola.x, bola.y, robo.x, robo.y, NUM_LINHAS);

	return 0;
}
