set encoding utf8
set term pngcairo font "helvetica, 16" size 1440, 900 enhanced

set title 'Y em função de tempo'

set xrange [0:8]
set yrange [0:6]

set xlabel 'Tempo (s)'
set ylabel 'Y (m)'

set key below right

set out '../graficos/yPorTempo.png'

plot '../recursos/coordenadas/yBolaPorTempo.txt' title 'Bola' with lines
     # , \ '../recursos/coordenadas/yRoboPorTempo.txt' title 'Robô' with lines
