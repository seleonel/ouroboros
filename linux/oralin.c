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
#include "logar.h"
#include "leitura.h"
#include "plotar.h"
// nosso header contendo a estrutura de medidas do robo e bola
#include "elementos.h"
#define NUM_LINHAS 367
#define LINHA_INIC 2
#define PI 3.141592653589793238462643383
/*
 * Mais tardiamente, poderá ser adicionada a biblioteca SDL, a gameengine pedida
 */

// funcoes podem ser "jogadas" num header para mais limpeza
void definicaoPosRobo(elementos *r, short int v)
{
	double x0, y0;
	/*
	 * Primeiro contato com usuário, serão pedidas as coordenadas x e y iniciais
	 * Se possível, evitar utilizar scanf (buffer overflow), fgets() será implementado mais tarde
	 */
	// checar se usuário errou a entrada de dados
	puts("Insira um valor para X e Y iniciais para o robô\n");
	scanf("%lf", &x0);
	scanf("%lf", &y0);
	r->x[LINHA_INIC] = x0;
	r->y[LINHA_INIC] = y0;
	if (v != 0)
		logar("posicao robo","X0", "Y0", x0, y0 );

}

void definicaoDirRobo(int* mpx, int* mpy,
	              double robo_x0, double robo_y0,
		      double bola_x0, double bola_y0,
		      short int v)
{
	if (robo_x0 > bola_x0)
	{
    		*mpx = -1;
    		if(robo_y0 > bola_y0)
        		*mpy = -1;
    		else if(robo_y0 < bola_y0)
        		*mpy = 1;
				else
						*mpy = 0;
 	}else if(robo_x0 < bola_x0)
	{
    		*mpx = 1;
    		if(robo_y0 > bola_y0)
       			*mpy = -1;
    		else if(robo_y0 < bola_y0)
        		*mpy = 1;
				else
						*mpy = 0;
	}
	else
	{
			 *mpx = 0;
			 if(robo_y0 > bola_y0)
					 *mpy = -1;
			 else if(robo_y0 < bola_y0)
					 *mpy = 1;
			 else
					 *mpy = 0;
	}
	if (v != 0)
		logar("direcao", "Versor X", "Versor Y", *mpx, *mpy);
}



void definicVelRobo(elementos *Rob, elementos *Bol, int i, float comp_x, float comp_y,  int versor_x, int versor_y )
{
	double  velocidade_x	= 0.0;
	double  velocidade_y	= 0.0;
	double  modulo_vel	= 0.0;
	double	accel		= 0.0;
	double  delta_x		= Rob->x[i] - Rob->x[i-1];
	double  delta_y		= Rob->y[i] - Rob->y[i-1];
	float desa_max = 2.64f;
	if(Rob->vel.mod[i-1] <= 2.3)
		accel		= a_max;
	else
		accel		= desa_max;

	velocidade_x 	= (Rob->vel.x[i-1] + (2 * accel * delta_x)) * versor_x;
	velocidade_y 	= (Rob->vel.y[i-1] + (2 * accel * delta_y)) * versor_y ;
	modulo_vel 	= sqrt(pow(velocidade_x, 2) + pow(velocidade_y, 2));


}


float definicAngul(double rob_x0, double rob_xf, double rob_y0, double rob_yf, int vers_x, int vers_y, short int v)
{
    float angulo    = 0.0f;
    // x e y positivo, considerar a opção
    // considerar y positivo

		if(vers_y < 0) //Robô acima da bola
			angulo = atan2(fabs(rob_xf - rob_x0), fabs(rob_yf - rob_y0));
		else if(vers_y > 0) //Robô abaixo da bola
			angulo = atan2(fabs(rob_yf - rob_y0), fabs(rob_xf - rob_x0));
		else //Robô na mesma posição Y que a bola
			return 0;
	if(v != 0)
		logar("definicao angulo", "angulo", "", angulo * (180/PI), 0);
    return angulo * (180/PI); //converte de radianos para graus
}

void defineComponentes(double* componenteX, double* componenteY, float modulo, float angulo, int vers_x, int vers_y, short int v) {

	if(vers_x > 0){ //Robô anda pra direita
		if(vers_y < 0) { //Robô anda pra baixo
			*componenteX = sin(angulo) * modulo;
			*componenteY = (cos(angulo) * modulo) * -1;
		}
		else if(vers_y > 0) { //Robô anda pra cima
			*componenteX = cos(angulo) * modulo;
			*componenteY = sin(angulo) * modulo;
		}
		else{ // Y do Robô igual ao da bola
			*componenteX = modulo;
			*componenteY = 0;
		}
	}
	else if(vers_x < 0){ //Robô anda pra esquerda
		if(vers_y < 0) { //Robô anda pra baixo
			*componenteX = (sin(angulo) * modulo) * -1;
			*componenteY = (cos(angulo) * modulo) * -1;
		}
		else if(vers_y > 0) { //Robô anda pra cima
			*componenteX = (cos(angulo) * modulo) * -1;
			*componenteY = sin(angulo) * modulo;
		}
		else{ // Y do Robô igual ao da bola
			*componenteX = modulo * -1;
			*componenteY = 0;
		}
	}
	else{ // X do Robô igual ao da bola
		if(vers_y < 0) { //Robô anda pra baixo
			*componenteX = 0;
			*componenteY = modulo * -1;
		}
		else if(vers_y > 0) { //Robô anda pra cima
			*componenteX = 0;
			*componenteY = modulo;
		}
		else{ // Y do Robô igual ao da bola
			*componenteX = 0;
			*componenteY = 0;
		}
	}
	if (v != 0)
		logar("definicao componentes", "componente x", "componente y",*componenteX, *componenteY);
}

void atualizaPosicao(elementos* Rob, double componenteX, double componenteY, int i){
	//como dito, os componentes serão positivo ou negativo dependendo da direção, bastando somar
	Rob->x[i] = Rob->x[i-1] + componenteX;
	Rob->y[i] = Rob->y[i-1] + componenteY;
}

float distanciaRoboBola(double robX, double bolaX, double robY, double bolaY){
	return sqrt(pow(fabs(robX-bolaX), 2) + pow(fabs(robY-bolaY), 2));
}


int definicMovRobo(elementos *Bol, elementos *Rob, int versor_x, int versor_y, float raio_interc, float vel_max, short int v )
{
	double rob_x0 	 	= Rob->x[LINHA_INIC];
	double rob_y0	 	= Rob->y[LINHA_INIC];
	double angulo_temp	= 0.0;
	double rob_xf, rob_yf;
	double soma_tempos	= 0.0;
	double componenteX, componenteY, distancia;
	float temp_accel = 0.575f;
	float temp_desac = 0.4924242424f;
	int i;

	distancia = 0.023f;
	// calcular todas as distancias possíveis
	for(i = LINHA_INIC + 1; i <= NUM_LINHAS; i++) // linha inicial + endereço da posição inicial
	{
		rob_xf = Bol->x[i];
		rob_yf = Bol->y[i];
		Rob->tempo[i] = Bol->tempo[i];
		soma_tempos += Bol->tempo[i];

		definicaoDirRobo(&versor_x, &versor_y, Rob->x[i-1], Rob->y[i-1], Bol->x[i-1], Bol->y[i-1], v);

		if(soma_tempos >= temp_accel && soma_tempos <= (temp_accel + temp_desac))
		// definicao do modulo
			distancia = 0.033f;
		else
			distancia = 0.02f;

    // definição do angulo
    angulo_temp = definicAngul(Rob->x[i-1], rob_xf, Rob->y[i-1], rob_yf, versor_x, versor_y, v );
		//define componentes
		defineComponentes(&componenteX, &componenteY, distancia, angulo_temp, versor_x, versor_y, v);
		atualizaPosicao(Rob, componenteX, componenteY, i);

//	 	definicVelRobo(Rob, Bol, i, componenteX, componenteY, versor_x, versor_y);


		if(distanciaRoboBola(Rob->x[i], Bol->x[i], Rob->y[i], Bol->y[i]) <= raio_interc)
			break;
	}
	return i;
}

int main (int argc, char * argv[])
{
	FILE * log = fopen("../logs/log", "w");
	fclose(log);
	elementos bola, robo;
	robo.diam		 = 0.180f;
	bola.diam	 	 = 0.046f;
	robo.vel.x[2] 		 = 0.0;
	robo.vel.y[2] 		 = 0.0;
	short int verboso 	= 0;	
	if(argc > 3)
	{
		puts("O programa apenas recebe um argumento");
		return 0;
	}
	if(!(strcmp(argv[1], "-e")) || !(strcmp(argv[1], "-v")))
		verboso = 1;
	else
		printf("Argumento %s não reconhecido\n", argv[1]);

	// para for loops
	int i, pontoDeEncontro;
	float raio_interc = (robo.diam/2) + (bola.diam/2) + dist_bounce; // bola sob o domínio do robo

	// zero os vetores da bola e robo
	for(i = 0; i < 400; i++)
		bola.tempo[i] = bola.x[i] = bola.y[i] = robo.x[i] = robo.y[i] = robo.tempo[i] = 0;

	// definiçao das posições iniciais do robo (vetor no indice 2)
	definicaoPosRobo(&robo, verboso);
	int controle = leitura(bola.tempo, bola.x, bola.y); // funcao leitura le cada linha do arquivo, erros são guardados em controle
	pontoDeEncontro = definicMovRobo(&bola, &robo, multipy, multipx, raio_interc, vel_robo, verboso);

	// última função antes da finalização do programa
	plotGraficos(&bola, &robo, NUM_LINHAS, pontoDeEncontro, robo.diam, bola.diam);

	logar("Final programa", "erro?", "",controle , 0);
	return controle;
}
