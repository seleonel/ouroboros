set encoding utf8
set term pngcairo font "helvetica, 16" size 1440, 900 enhanced

set title 'Velocidade X em função de tempo'

set xlabel 'Tempo (s)'
set ylabel 'Vel X (m/s)'

set key below right

set grid ytics mytics
set grid xtics mxtics
set mxtics 4
set mytics 4
set grid

set out '../graficos/VelxPorTempo.png'

plot '../recursos/coordenadas/VelxBolaPorTempo.txt' title 'Bola' lt rgb 'blue' with lines, \
     '../recursos/coordenadas/VelxRoboPorTempo.txt' title 'Robô' lt rgb '#ee42f4' with lines
