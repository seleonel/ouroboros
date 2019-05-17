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
#include "elementos.h"

#define NUM_LINHAS 367
#define LINHA_INIC 2
#define PI 3.141592653589793238462643383
#define TEMPO_ITERACAO 0.02f
#define NOT_FOUND 404

void definicaoPosRobo(elementos *r, short int v)
{
	double x0, y0;
	int xCopiados, yCopiados;
	//Primeiro contato com usuário, serão pedidas as coordenadas x e y iniciais
	while(1)
	{
		puts("Insira um valor para X e Y iniciais para o robô\n");
		char buffer[10];
		char buffer2[10];

		fgets(buffer, sizeof(buffer), stdin);
		fgets(buffer2, sizeof(buffer2), stdin);

		xCopiados = sscanf(buffer, "%lf", &x0);
		yCopiados = sscanf(buffer2, "%lf", &y0);

		if (xCopiados >= 1 && yCopiados >= 1 && x0 >= 0 && x0 <= 9 && y0 >= 0 && y0 <= 6) {
			break;
		}
		puts("Coordenadas inválidas, insira novamente");
	}

	r->x[LINHA_INIC] = x0;
	r->y[LINHA_INIC] = y0;
	if (v != 0)
		logar("posicao robo","X0", "Y0", x0, y0 );

}

double definicaoVelFinalRobo(double* deltaT, double* distIteracao, float porcentagem){
	double velFinal = 1.055831105 * (1+porcentagem);
	*deltaT = (vel_robo - velFinal)/desa_max;
	double distTotal = (((vel_robo - velFinal) * *deltaT) / 2) + (velFinal * *deltaT);
	*distIteracao = ((distTotal * 0.02) / *deltaT);
	return velFinal;
}

void definicaoDirRobo(int* mpx, int* mpy, double robo_x0, double robo_y0, double bola_x0, double bola_y0, short int v)
{
	/*
		Verifica a posição X e Y do robô em relação à bola em cada iteração
		criando um versor +1 se estiver abaixo ou -1 se estiver em cima
	*/
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

void definicAccelRobo(elementos *Robo, int i, short int v, double comp_x, double comp_y, double angulo)
{
	Robo->acc.mod[i] = (Robo->vel.mod[i] - Robo->vel.mod[i-1]) / TEMPO_ITERACAO;
	
	if(comp_y > 0){
		Robo->acc.x[i] = Robo->acc.mod[i] * cos(angulo);
		Robo->acc.y[i] = Robo->acc.mod[i] * sin(angulo);
	}
	else if(comp_y < 0){
		Robo->acc.x[i] = Robo->acc.mod[i] * sin(angulo);
		Robo->acc.y[i] = Robo->acc.mod[i] * cos(angulo);
	}

	if ( v != 0){
		logar("Aceleração", "Modulo aceleração", "", Robo->acc.mod[i], 0);
		logar("Aceleração componentes", "AX", "AY", Robo->acc.x[i], Robo->acc.y[i]);
	}
}

void definicVelRobo(elementos *Rob, elementos *Bol, int i, double comp_x, double comp_y, int accel, short int v  , double vel_f, double angulo)
{

	if(accel == 1){
		Rob->vel.mod[i] = Rob->vel.mod[i-1] + (a_max * TEMPO_ITERACAO);
	}else if(accel == -1){
		Rob->vel.mod[i] = Rob->vel.mod[i-1] - (desa_max * TEMPO_ITERACAO);
	}else{
		Rob->vel.mod[i] = vel_f;
	}

	if(comp_y > 0){
		Rob->vel.x[i] = Rob->vel.mod[i] * cos(angulo);
		Rob->vel.y[i] = Rob->vel.mod[i] * sin(angulo);
	}
	else if(comp_y < 0){
		Rob->vel.x[i] = Rob->vel.mod[i] * sin(angulo);
		Rob->vel.y[i] = Rob->vel.mod[i] * cos(angulo);
	}

	if ( v != 0){
		logar("Velocidade", "Modulo velocidade", "", Rob->vel.mod[i], 0);
		logar("Velocidade componentes", "VX", "VY", Rob->vel.x[i], Rob->vel.y[i]);
	}
	definicAccelRobo(Rob, i, v, comp_x, comp_y, angulo);
}

void definicAccelBola(elementos *Bola, int i)
{
	//equações retiradas do Excel
	Bola->acc.x[i] = 0.1092;
	Bola->acc.y[i] = -0.04;
}

void definicVelBola(elementos *Bol, int i)
{
	//equações retiradas do Excel
	Bol->vel.x[i] = (0.1092 * Bol->tempo[i]) + 0.3412;
	Bol->vel.y[i] = (-0.04 * Bol->tempo[i]) + 0.9;

	definicAccelBola(Bol, i);
}

float definicAngul(double rob_x0, double rob_xf, double rob_y0, double rob_yf, int* vers_x, int* vers_y, short int v)
{
    float angulo    = 0.0f;
		//definido atráves da tangente do delta x e y entre robô e bola
		if(*vers_y < 0) //Robô acima da bola
			angulo = atan2(fabs(rob_xf - rob_x0), fabs(rob_yf - rob_y0));
		else if(*vers_y > 0) //Robô abaixo da bola
			angulo = atan2(fabs(rob_yf - rob_y0), fabs(rob_xf - rob_x0));
		else //Robô na mesma posição Y que a bola
			return 0;

  	if(v != 0)
  		logar("definicao angulo", "angulo", "", angulo * (180/PI), 0);
      return angulo;
}

void defineComponentes(double* componenteX, double* componenteY, double modulo, float angulo, int* vers_x, int* vers_y, short int v) {

	if(*vers_x > 0){ //Robô anda pra direita
		if(*vers_y < 0) { //Robô anda pra baixo
			*componenteX = (sin(angulo) * modulo);
			*componenteY = -(cos(angulo) * modulo);
		}
		else if(*vers_y > 0) { //Robô anda pra cima
			*componenteX = (cos(angulo) * modulo);
			*componenteY = (sin(angulo) * modulo);
		}
		else{ // Y do Robô igual ao da bola
			*componenteX = modulo;
			*componenteY = 0;
		}
	}
	else if(*vers_x < 0){ //Robô anda pra esquerda
		if(*vers_y < 0) { //Robô anda pra baixo
			*componenteX = -(sin(angulo) * modulo);
			*componenteY = -(cos(angulo) * modulo);
		}
		else if(*vers_y > 0) { //Robô anda pra cima
			*componenteX = -(cos(angulo) * modulo);
			*componenteY = (sin(angulo) * modulo);
		}
		else{ // Y do Robô igual ao da bola
			*componenteX = modulo * -1;
			*componenteY = 0;
		}
	}
	else{ // X do Robô igual ao da bola
		if(*vers_y < 0) { //Robô anda pra baixo
			*componenteX = 0;
			*componenteY = modulo * -1;
		}
		else if(*vers_y > 0) { //Robô anda pra cima
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
	Rob->x[i] = Rob->x[i-1] + componenteX;
	Rob->y[i] = Rob->y[i-1] + componenteY;
}

double distanciaRoboBola(double robX, double bolaX, double robY, double bolaY){
	//pitágoras
	return sqrt(pow((robX-bolaX), 2) + pow((robY-bolaY), 2));
}

int definicMovRobo(elementos *Bol, elementos *Rob, int* versor_x, int* versor_y, float raio_interc, float vel_max, double temp_desac, double distDesac, short int v, double vel_fin)
{
	double angulo_temp	= 0.0;
	double rob_xf, rob_yf;
	double soma_tempos	= 0.0;
	double componenteX, componenteY, distancia;
	double temp_accel 	= 0.575f;
	int i, accel;

	distancia 		= 0.023f;
	// calcular todas as distancias possíveis
	for(i = LINHA_INIC + 1; i <= NUM_LINHAS; i++) // linha inicial + endereço da posição inicial
	{
		rob_xf = Bol->x[i];
		rob_yf = Bol->y[i];
		Rob->tempo[i] = Bol->tempo[i];
		soma_tempos = Bol->tempo[i];

		accel = 1;
		definicaoDirRobo(versor_x, versor_y, Rob->x[i-1], Rob->y[i-1], Bol->x[i-1], Bol->y[i-1], v);

		if(soma_tempos >= temp_accel && soma_tempos <= (temp_accel + temp_desac)){
		// definicao do modulo
			distancia = 0.033f;
			accel = -1;
		}else if(soma_tempos > (temp_accel+temp_desac)){
			distancia = distDesac;
			accel = 0;
		}

    angulo_temp = definicAngul(Rob->x[i-1], rob_xf, Rob->y[i-1], rob_yf, versor_x, versor_y, v );

		defineComponentes(&componenteX, &componenteY, distancia, angulo_temp, versor_x, versor_y, v);
		atualizaPosicao(Rob, componenteX, componenteY, i);

	 	definicVelRobo(Rob, Bol, i, componenteX, componenteY, accel, v, vel_fin, angulo_temp);
		definicVelBola(Bol, i);

		dist_relativa[i] = distanciaRoboBola(Rob->x[i], Bol->x[i], Rob->y[i], Bol->y[i]);

		if( dist_relativa[i] <= raio_interc)
			return i;
	}
	return NOT_FOUND;
}

int main (int argc, char * argv[])
{
	elementos bola, robo;
	short int verboso 	= 0;
	double temp_desac;
	double distIteracao;
	float porcentagem 	= 0.05;
	int i, pontoDeEncontro;
	robo.diam 		= 0.180f;
	bola.diam		= 0.046f;
	robo.vel.x[2] 		= 0.0;
	robo.vel.y[2] 		= 0.0;

	float raio_interc = (robo.diam/2) + (bola.diam/2) + dist_bounce;

	if(verboso != 0)
		fclose(fopen("../logs/log", "w"));
	for(i = 0; i < 400; i++)
		bola.tempo[i] = bola.x[i] = bola.y[i] = robo.x[i] = robo.y[i] = robo.tempo[i] = 0;
    
    definicaoPosRobo(&robo, 1);
		
// 	robo.x[LINHA_INIC] = strtod(argv[1], NULL);
// 	robo.y[LINHA_INIC] = strtod(argv[2], NULL);

// 	printf("%lf\n%lf\n", robo.x[LINHA_INIC], robo.y[LINHA_INIC]);


	//definicaoPosRobo(&robo, verboso);
	int controle = leitura(bola.tempo, bola.x, bola.y); // funcao leitura le cada linha do arquivo, erros são guardados em controle
	pontoDeEncontro = definicMovRobo(&bola, &robo, &multipy, &multipx, raio_interc, vel_robo, temp_desac, distIteracao, verboso, definicaoVelFinalRobo(&temp_desac, &distIteracao, porcentagem));

	if(pontoDeEncontro == NOT_FOUND) {
		printf("O Robô não conseguiu colidir com a bola durante seu percurso\n");
	}
	else{
		plotGraficos(&bola, &robo, NUM_LINHAS, pontoDeEncontro, robo.diam, bola.diam);
	}

	logar("Final programa", "erro?", "",controle , 0);
	return controle;
}
