#ifndef ELEMENTOS_H
#define ELEMENTOS_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct
{
    double tempo[400];
    double    x[400] ;
    double    y[400] ;
    double    distancia[400];
}elementos;

int multipy, multipx;

 //  Serão determinadas dimensões do robô e da bola
// determinado pelo comitê da robocup como limite 0,18 metros de raio
float raio_robo = 0.180f;
// determinado pela força aplicada sobre a bola
float dist_bounce = 0.0f;
//padrões de uma bola de golfe
float raio_bola = 0.046f;
float vel_robo = 6.5f; // 6,5 m/s como limite determinado pela robocup                                                        
#endif
