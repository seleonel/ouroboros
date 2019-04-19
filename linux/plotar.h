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


  //Trajetórias
  coordenadas = fopen("../recursos/coordenadas/posicaoBolaAteEncontro.txt", "w");
  for(i = 2; i <= pontoDeEncontro; i++) // posição da bola (x em função de y)
    fprintf(coordenadas, "%lf %lf\n", Bola->x[i], Bola->y[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/posicaoBolaAposEncontro.txt", "w");
  for(i = pontoDeEncontro; i < numlinhas; i++) // posição da bola (x em função de y)
    fprintf(coordenadas, "%lf %lf\n", Bola->x[i], Bola->y[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/trajetoriaRobo.txt", "w");
  for(i = 2; i <= pontoDeEncontro; i++)
    fprintf(coordenadas, "%lf %lf\n", Robo->x[i], Robo->y[i]);
  fclose(coordenadas);


  //Raios
  coordenadas = fopen("../recursos/coordenadas/raioRobo.txt", "w");
  fprintf(coordenadas, "%lf %lf %f\n", Robo->x[pontoDeEncontro], Robo->y[pontoDeEncontro], diametroRobo/2);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/raioBola.txt", "w");
  fprintf(coordenadas, "%lf %lf %f\n", Bola->x[pontoDeEncontro], Bola->y[pontoDeEncontro], diametroBola/2);
  fclose(coordenadas);


  //Posições X e Y por tempo
  coordenadas = fopen("../recursos/coordenadas/xBolaPorTempo.txt", "w");
  for(i = 2; i <= pontoDeEncontro; i++) // posição da bola X em função do tempo
    fprintf(coordenadas, "%f %lf\n", Bola->tempo[i], Bola->x[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/yBolaPorTempo.txt", "w");
  for(i = 2; i <= pontoDeEncontro; i++) // posição da bola Y em função do tempo
    fprintf(coordenadas, "%lf %lf\n", Bola->tempo[i], Bola->y[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/xRoboPorTempo.txt", "w");
  for(i = 2; i <= pontoDeEncontro; i++) // posição da bola X em função do tempo
    fprintf(coordenadas, "%f %lf\n", Robo->tempo[i], Robo->x[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/yRoboPorTempo.txt", "w");
  for(i = 2; i <= pontoDeEncontro; i++) // posição da bola Y em função do tempo
    fprintf(coordenadas, "%lf %lf\n", Robo->tempo[i], Robo->y[i]);
  fclose(coordenadas);


  //Velocidades X e Y por tempo
  coordenadas = fopen("../recursos/coordenadas/VelxRoboPorTempo.txt", "w");
  for(i = 2; i <= pontoDeEncontro; i++) // velocidade do Robo X em função do tempo
    fprintf(coordenadas, "%f %lf\n", Robo->tempo[i], Robo->vel.x[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/VelyRoboPorTempo.txt", "w");
  for(i = 2; i <= pontoDeEncontro; i++) // velocidade do Robo Y em função do tempo
    fprintf(coordenadas, "%lf %lf\n", Robo->tempo[i], Robo->vel.y[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/VelxBolaPorTempo.txt", "w");
  for(i = 2; i <= pontoDeEncontro; i++) // velocidade da bola X em função do tempo
    fprintf(coordenadas, "%f %lf\n", Bola->tempo[i], Bola->vel.x[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/VelyBolaPorTempo.txt", "w");
  for(i = 2; i <= pontoDeEncontro; i++) // velocidade da bola Y em função do tempo
    fprintf(coordenadas, "%lf %lf\n", Bola->tempo[i], Bola->vel.y[i]);
  fclose(coordenadas);


  //Aceleração X e Y por tempo
  coordenadas = fopen("../recursos/coordenadas/AccelxRoboPorTempo.txt", "w");
  for(i = 2; i <= pontoDeEncontro; i++) // aceleração do Robo X em função do tempo
    fprintf(coordenadas, "%f %lf\n", Robo->tempo[i], Robo->acc.x[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/AccelyRoboPorTempo.txt", "w");
  for(i = 2; i <= pontoDeEncontro; i++) // aceleração do Robo Y em função do tempo
    fprintf(coordenadas, "%lf %lf\n", Robo->tempo[i], Robo->acc.y[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/AccelxBolaPorTempo.txt", "w");
  for(i = 2; i <= pontoDeEncontro; i++) // aceleração da bola X em função do tempo
    fprintf(coordenadas, "%f %lf\n", Bola->tempo[i], Bola->acc.x[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/AccelyBolaPorTempo.txt", "w");
  for(i = 2; i <= pontoDeEncontro; i++) // aceleração da bola Y em função do tempo
    fprintf(coordenadas, "%lf %lf\n", Bola->tempo[i], Bola->acc.y[i]);
  fclose(coordenadas);

  //Distância relativa
  coordenadas = fopen("../recursos/coordenadas/distRelativa.txt", "w");
  for(i = 3; i <= pontoDeEncontro; i++) // aceleração da bola Y em função do tempo
    fprintf(coordenadas, "%lf %lf\n", Bola->tempo[i], dist_relativa[i]);
  fclose(coordenadas);
}

void plotGraficos(elementos *Bola, elementos *Robo, int numlinhas, int pontoDeEncontro, float diametroRobo, float diametroBola)
{
	salvarCoordenadas(Bola, Robo, numlinhas, pontoDeEncontro, diametroRobo, diametroBola); // salva as coordenadas em um arquivo

  system("gnuplot ../recursos/scripts/script1.gnu");
  system("gnuplot ../recursos/scripts/script2.gnu");
  system("gnuplot ../recursos/scripts/script3.gnu");
  system("gnuplot ../recursos/scripts/script4.gnu");
  system("gnuplot ../recursos/scripts/script5.gnu");
  system("gnuplot ../recursos/scripts/script6.gnu");
  system("gnuplot ../recursos/scripts/script7.gnu");
  system("gnuplot ../recursos/scripts/script8.gnu");

}

#endif /* PLOTAR_H */
