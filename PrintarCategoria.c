#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

int verifica(char* v, char* quer, int tam){

    int i=0, j=0;

    for (i = 0; i < tam; ++i) {
        if (v[i] != ' ') {


            if (v[i] == quer[j]) {
                //printf("v[%d] = %c    ---------   quer[%d] = %c\n", i, v[i], j, quer[j]);
                j++;
            }

        }

    }

    if(j == 7)
        return 1;
    j=0;


    return 0;

}


int main() {



    //scanf("%s", vet);
    char c;
    //char vet[100];
    char line[100000];
    char v[] = {"moradia"};
    int index = 0;

    FILE* file;

    file = fopen("projeto.txt", "r");

    c = getc(file);

    while ( 1 ) {

        if ( c != '\n'){
            line[index++] = c;
        }
        else {

            if(verifica(line, v, index)) {
                printf("%s\n", line);
            }
            line[index] = '\0';
            index = 0;

            memset(line, 0, sizeof(line));


        }
        if( c == EOF){
            //printf("%s\n", line);
            break;
        }

        c = getc ( file );
    }




    fclose(file);


    return 0;
}