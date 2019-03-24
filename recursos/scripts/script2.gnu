set encoding utf8
set term pngcairo font "helvetica,16" size 1440, 900 enhanced

set title 'X em função de tempo'

set xrange [0:8]
set yrange [0:9]

set xlabel 'Tempo (s)'
set ylabel 'X (m)'

set key below right

set out '../graficos/xPorTempo.png'

plot '../recursos/coordenadas/xBolaPorTempo.txt' title 'Bola' with lines
     # , \ '../recursos/coordenadas/xRoboPorTempo.txt' title 'Robô' with lines
