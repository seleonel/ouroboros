
#
# wrapper para python detectar o sistema operacional, e mandar os
# dados para determinado programa em C por motivos de compatibilidade
#

import sys # contém as funções necessárias para detectar o SO


def main ():
    sistema = sys.platform
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
