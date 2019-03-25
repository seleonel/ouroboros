#ifndef PLOTAR_H
#define PLOTAR_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void salvarCoordenadas(double bola_tempo[], double bola_x[], double bola_y[],  double robo_x[], double robo_y[], int numlinhas){
  int i = 0;
  FILE * coordenadas; // ponteiro do tipo FILE

  coordenadas = fopen("../recursos/coordenadas/posicaoBola.txt", "w");
  for(i = 2; i < numlinhas; i++) // posição da bola (x em função de y)
    fprintf(coordenadas, "%f %f\n", bola_x[i], bola_y[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/xBolaPorTempo.txt", "w");
  for(i = 2; i < numlinhas; i++) // posição da bola X em função do tempo
    fprintf(coordenadas, "%f %f\n", bola_tempo[i], bola_x[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/yBolaPorTempo.txt", "w");
  for(i = 2; i < numlinhas; i++) // posição da bola Y em função do tempo
    fprintf(coordenadas, "%f %f\n", bola_tempo[i], bola_y[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/trajetoriaRobo.txt", "w");
  fprintf(coordenadas, "%f %f\n%f %f\n", robo_x[2], robo_y[2], robo_x[3], robo_y[3]);
  fclose(coordenadas);

}

void plotGraficos(double bola_tempo[], double bola_x[], double bola_y[], double robo_x[], double robo_y[], int numlinhas)
{
	salvarCoordenadas(bola_tempo, bola_x, bola_y, robo_x, robo_y, numlinhas); // salva as coordenadas em um arquivo

  system("gnuplot ../recursos/scripts/script1.gnu");
  system("gnuplot ../recursos/scripts/script2.gnu");
  system("gnuplot ../recursos/scripts/script3.gnu");

}

#endif /* PLOTAR_H */
