set terminal png medium size 600,600 enhanced;

set encoding utf8
set term pngcairo font "sans,12"

set title 'Y em função de tempo'

set xrange [0:8]
set yrange [0:6]

set xlabel 'Tempo (s)'
set ylabel 'Coordenada Y'

set out '../graficos/yPorTempo.png'

plot '../recursos/coordenadas/yPorTempo.txt' with lines
