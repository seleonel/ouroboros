#ifndef ELEMENTOS_H
#define ELEMENTOS_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
typedef struct
{
    double 	mod[400];
    double	x[400];
    double	y[400];
} velocidades;
typedef struct
{
	double mod[400];
	double x[400];
	double y[400];
} aceler;
typedef struct
{
    double 	tempo[400];
    double    	x[400] ;
    double    	y[400] ;
    double    	distancia[400];
    aceler	acc;
    velocidades vel;
   float 	diam;
}elementos;


int multipy, multipx;
double dist_relativa[400];

// determinado pelo comitê da robocup como limite 0,18 metros de raio
//float raio_robo = 0.180f;
// determinado pela força aplicada sobre a bola
const float dist_bounce = 0.0f;
//padrões de uma bola de golfe
//float raio_bola = 0.046f;
const float vel_robo = 2.3f; // 6,5 m/s como limite determinado pelo paper
const float a_max = 4.0f;
const float desa_max = 2.63f;
#endif
