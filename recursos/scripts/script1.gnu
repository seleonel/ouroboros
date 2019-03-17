set terminal png medium size 600,600 enhanced;

set encoding utf8
set term pngcairo font "sans,12"

set title 'Posição da bola'

set xrange [0:9]
set yrange [0:6]

set xlabel 'Coordenada X'
set ylabel 'Coordenada Y'

set out '../graficos/posicaoBola.png'

plot '../recursos/coordenadas/posicaoBola.txt' with lines
