set encoding utf8
set term pngcairo font "helvetica, 16" size 1366, 690 enhanced

set title 'X em função de tempo'

set xlabel 'Tempo (s)'
set ylabel 'X (m)'

set key below right

set grid ytics mytics
set grid xtics mxtics
set mxtics 4
set mytics 4
set grid

set out '../graficos/xPorTempo.png'

plot '../recursos/coordenadas/xBolaPorTempo.txt' title 'Bola' lt rgb 'blue' with lines, \
     '../recursos/coordenadas/xRoboPorTempo.txt' title 'Robô' lt rgb '#ee42f4' with lines
