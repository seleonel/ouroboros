set encoding utf8
set term pngcairo font "helvetica, 16" size 1440, 900 enhanced

set title 'Y em função de tempo'

set xlabel 'Tempo (s)'
set ylabel 'Y (m)'

set key below right

set grid ytics mytics
set grid xtics mxtics
set mxtics 4
set mytics 4
set grid

set out '../graficos/yPorTempo.png'

plot '../recursos/coordenadas/yBolaPorTempo.txt' title 'Bola' lt rgb 'blue' with lines, \
     '../recursos/coordenadas/yRoboPorTempo.txt' title 'Robô' lt rgb '#ee42f4' with lines
