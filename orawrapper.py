
#
# wrapper para python detectar o sistema operacional, e mandar os
# dados para determinado programa em C por motivos de compatibilidade
#
# -> a bola possui trajetória fixa definida pelo arquivo trajetoria_1sem2019.txt
# -> as coordenadas X e Y do robô serão definidas aleatoriamente durante a
#    apresentação
# -> o projeto todo utilizará como base apenas um robô para todo seu
#    funcionamento: KidSize Humanoid ou Small Size
# -> o objetivo do projeto resume-se em realizar o econtro do robô com a bola
#    antes que ela saia do campo de futebol

import sys # contém as funções necessárias para detectar o SO

def main ():
    sistema = sys.platform # checa o sistema operacional
    print("Rodando em %s" % sistema)

    if (sistema[:3] == "win"):
        # "dar" load no c compilado para windows
        pass
    elif (sistema == "linux"):
        pass
    #elif (sistema == "macos"):
    else:
        print("Seu sistema não é compatível")




main();
