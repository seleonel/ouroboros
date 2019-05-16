set encoding utf8
set term pngcairo font "helvetica, 16" size 1366, 690 enhanced

set title 'Distância relativa'

set xlabel 'Tempo (s)'
set ylabel 'Distância (m)'

set key below right

set grid ytics mytics
set grid xtics mxtics
set mxtics 4
set mytics 4
set grid

set out '../graficos/DistRelativa.png'

plot '../recursos/coordenadas/distRelativa.txt' title 'Distância' with lines
