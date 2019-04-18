set encoding utf8
set term pngcairo font "helvetica,16" size 1440, 900 enhanced

set title 'Posição da bola'

set xrange [0:9]
set yrange [0:6]

set xlabel 'X (m)'
set ylabel 'Y (m)'

set key below right

set out '../graficos/posicaoBola.png'

plot '../recursos/coordenadas/posicaoBolaAteEncontro.txt' title 'Bola' lt rgb 'blue' with lines, \
     '../recursos/coordenadas/trajetoriaRobo.txt' title 'Robô' lt rgb '#ee42f4' with lines, \
     '../recursos/coordenadas/posicaoBolaAposEncontro.txt' notitle lt rgb 'blue' with dots, \
     '../recursos/coordenadas/raioRobo.txt' title 'Raio Robô' lt rgb '#ee42f4' with circle, \
     '../recursos/coordenadas/raioBola.txt' title 'Raio Bola' lt rgb 'blue' with circle
