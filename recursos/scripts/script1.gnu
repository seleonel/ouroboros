set encoding utf8
set term pngcairo font "helvetica,16" size 1440, 900 enhanced

set title 'Posição da bola'

set xrange [0:9]
set yrange [0:6]

set xlabel 'X (m)'
set ylabel 'Y (m)'

set key below right

set out '../graficos/posicaoBola.png'

plot '../recursos/coordenadas/posicaoBola.txt' title 'Bola' lt rgb 'blue' with lines, \
     '../recursos/coordenadas/trajetoriaRobo.txt' title 'Robô' lt rgb '#ee42f4' with lines
