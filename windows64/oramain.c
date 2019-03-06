/*
 *	Este programa simula as a��es de um rob� jogador de futebol e plota os respectivos gr�ficos
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
#include <locale.h>
#include "plotar.h"

/*
 * Mais tardiamente, poder� ser adicionada a biblioteca SDL, a gameengine pedida
 */

// funcoes podem ser "jogadas" num header para mais limpeza
void definicaoPosRobo(float *r_x0, float *r_y0)
{
	/*
	 * Primeiro contato com usu�rio, ser�o pedidas as coordenadas x e y iniciais
	 * Se poss�vel, evitar utilizar scanf (buffer overflow), fgets() ser� implementado mais tarde
	 */
	puts("Insira um valor para X e Y iniciais para o rob�");
	scanf("%f %f", r_x0, r_y0);

}

void leituraBola(float *b_x0, float *b_y0, float *b_x, float *b_y)
{

	/*
	 * funcao getline (https://linux.die.net/man/3/getline) do stdin l� uma linha de uma stream
	 *
	 * Como separar os car�cteres pelo espa�o? strtok() separa cada string em tokens e finaliza com NULL
	 *
	 * devemos usar essa fun��o pra tudo?
	 *
	 */


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
    setlocale(LC_ALL, "Portuguese"); //defini��o do terminal para o padr�o UTF-8
	 /*
	  *  Ser�o determinadas dimens�es do rob� e da bola
	 */

	// determinado pelo comit� da robocup como limite 0,18 metros de raio
	float raio_robo = 0.180f;

	// determinado pela for�a aplicada sobre a bola
	float dist_bounce = 0.0f;

	//padr�es de uma bola de golfe
	float raio_bola = 0.046f;
	float raio_interc = raio_robo + raio_bola + dist_bounce; // bola sob o dom�nio do robo

	float vel_robo = 6.5f; // 6,5 m/s como limite determinado pela robocup

	// posicoes iniciais e momentaneas x e y do robo
	float robo_x0, robo_y0, robo_x, robo_y;
	// utilizaremos ponteiros
	definicaoPosRobo(&robo_x0, &robo_y0);

	// posicao da bola sera determinada pela leitura do arquivo txt, tamb�m ser�o usados ponteiros
	float bola_x0, bola_y0, bola_x, bola_y;
	leituraBola(&bola_x0, &bola_y0, &bola_x, &bola_y); // funcao le cada linha do arquivo linha da bola


	// �ltima fun��o antes da finaliza��o do programa
	void plotGraficos();

    int c;
    if((scanf("%d", &c)) != EOF){
        main();
    }

	return 0;
}
