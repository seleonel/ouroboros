#ifndef PLOTAR_H
#define PLOTAR_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char* pegarDiretorio(char diretorio[]){
    int i;
    getcwd(diretorio, FILENAME_MAX); //detecta o diretório no qual contém o arquivo executável e salva na
    for(i=0;i<FILENAME_MAX;i++){ //substitui as "\" por "/", pois são estas as utilizadas para a função main
        if(diretorio[i] == '\\'){
            diretorio[i] = '/';
        }
    }
    return diretorio;
}

/* Exemplo para função main
int main(){
    char diretorio[FILENAME_MAX];
    pegarDiretorio(diretorio);
    printf("%s", diretorio);
    return 0;
}
*/

#endif /* PLOTAR_H */
