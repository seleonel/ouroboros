set terminal png medium size 600,600 enhanced;

set encoding utf8
set term pngcairo font "sans,12"

set title 'X em função de tempo'

set xrange [0:8]
set yrange [0:9]

set xlabel 'Tempo (s)'
set ylabel 'Coordenada X'

set out '../graficos/xPorTempo.png'

plot '../recursos/coordenadas/xPorTempo.txt' with lines
