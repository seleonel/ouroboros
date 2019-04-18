#ifndef PLOTAR_H
#define PLOTAR_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "elementos.h"

void salvarCoordenadas(elementos *Bola, elementos *Robo, int numlinhas, int pontoDeEncontro, float diametroRobo, float diametroBola){
  int i;
  FILE * coordenadas; // ponteiro do tipo FILE

  coordenadas = fopen("../recursos/coordenadas/posicaoBolaAteEncontro.txt", "w");
  for(i = 2; i <= pontoDeEncontro; i++) // posição da bola (x em função de y)
    fprintf(coordenadas, "%lf %lf\n", Bola->x[i], Bola->y[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/posicaoBolaAposEncontro.txt", "w");
  for(i = pontoDeEncontro; i < numlinhas; i++) // posição da bola (x em função de y)
    fprintf(coordenadas, "%lf %lf\n", Bola->x[i], Bola->y[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/raioRobo.txt", "w");
  fprintf(coordenadas, "%lf %lf %f\n", Robo->x[pontoDeEncontro], Robo->y[pontoDeEncontro], diametroRobo/2);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/raioBola.txt", "w");
  fprintf(coordenadas, "%lf %lf %f\n", Bola->x[pontoDeEncontro], Bola->y[pontoDeEncontro], diametroBola/2);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/trajetoriaRobo.txt", "w");
  for(i = 2; i <= pontoDeEncontro; i++)
    fprintf(coordenadas, "%lf %lf\n", Robo->x[i], Robo->y[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/xBolaPorTempo.txt", "w");
  for(i = 2; i <= pontoDeEncontro; i++) // posição da bola X em função do tempo
    fprintf(coordenadas, "%f %lf\n", Bola->tempo[i], Bola->x[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/yBolaPorTempo.txt", "w");
  for(i = 2; i <= pontoDeEncontro; i++) // posição da bola Y em função do tempo
    fprintf(coordenadas, "%lf %lf\n", Bola->tempo[i], Bola->y[i]);
  fclose(coordenadas);
}

void plotGraficos(elementos *Bola, elementos *Robo, int numlinhas, int pontoDeEncontro, float diametroRobo, float diametroBola)
{
	salvarCoordenadas(Bola, Robo, numlinhas, pontoDeEncontro, diametroRobo, diametroBola); // salva as coordenadas em um arquivo

  system("gnuplot ../recursos/scripts/script1.gnu");
  system("gnuplot ../recursos/scripts/script2.gnu");
  system("gnuplot ../recursos/scripts/script3.gnu");

}

#endif /* PLOTAR_H */
