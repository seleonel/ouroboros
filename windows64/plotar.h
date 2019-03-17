#ifndef PLOTAR_H
#define PLOTAR_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*char* pegarDiretorio(){
    int i;
    char diretorio[FILENAME_MAX];
    getcwd(diretorio, FILENAME_MAX); //detecta o diretório no qual contém o arquivo executável e salva na
    for(i=0;i<FILENAME_MAX;i++){ //substitui as "\" por "/", pois são estas as utilizadas para a função main
        if(diretorio[i] == '\\'){
            diretorio[i] = '/';
        }
    }
    return diretorio;
}*/

void salvarCoordenadas(double bola_tempo[], double bola_x[], double bola_y[], int numlinhas){
  //pegarDiretorio()
  int i = 0;
  FILE * coordenadas; // ponteiro do tipo FILE

  coordenadas = fopen("../recursos/coordenadas/posicaoBola.txt", "w");
  for(i = 2; i < numlinhas; i++) // posição da bola (x em função de y)
    fprintf(coordenadas, "%f %f\n", bola_x[i], bola_y[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/xPorTempo.txt", "w");
  for(i = 2; i < numlinhas; i++) // posição da bola X em função do tempo
    fprintf(coordenadas, "%f %f\n", bola_tempo[i], bola_x[i]);
  fclose(coordenadas);

  coordenadas = fopen("../recursos/coordenadas/yPorTempo.txt", "w");
  for(i = 2; i < numlinhas; i++) // posição da bola Y em função do tempo
    fprintf(coordenadas, "%f %f\n", bola_tempo[i], bola_y[i]);
  fclose(coordenadas);
}

void plotGraficos(double bola_tempo[], double bola_x[], double bola_y[], int numlinhas)
{
	salvarCoordenadas(bola_tempo, bola_x, bola_y, numlinhas); // salva as coordenadas em um arquivo

  system("gnuplot ../recursos/scripts/script1.gnu");
  system("gnuplot ../recursos/scripts/script2.gnu");
  system("gnuplot ../recursos/scripts/script3.gnu");

}

/* Exemplo para função main
int main(){
    char diretorio[FILENAME_MAX];
    pegarDiretorio(diretorio);
    printf("%s", diretorio);
    return 0;
}
*/

#endif /* PLOTAR_H */
