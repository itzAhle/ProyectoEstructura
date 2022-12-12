#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Quuitar comas al csv y columnas
typedef struct {
    char trackName[100];
    char albumName[100];
    char artistName[100];
    char duration[10];
    char dur[6];
    char genre[100];
}trackInfo; //ok

void printValues (trackInfo songs[]  );

int main() {

    /*FILE *file;
    file = fopen("E:\\Documents\\UV\\UV\\SpotiUV2\\sent.csv", "r"); //ok

    if (file == NULL) {
        printf("Error al abrir el archivo");
        return 1;
    }

    trackInfo songs[100]; //ok
    int read = 0; //campos que se van a leer
    int records = 0;//registros OK

    do {
        read = fscanf(file, "%49[^,],%49[^,],%49[^,],%d,%49[^,]\n",
                      songs[records].trackName,
                      songs[records].albumName,
                      songs[records].artistName,
                      &songs[records].duration,
                      songs[records].genre);

        if(read == 4) records++;

        if (read != 4 && !feof(file)) {
            printf("Formato incorrecto");
            return 1;
        }

        if (ferror(file)) {
            printf("Error leyendo archivo.");
            return 1;
        }
    } while (!feof(file));

    fclose(file);

    printf("\n%d Records read\n", records);

    for (int i = 0; i < records; ++i) {
        printf("%s %s %s %d %s",
               songs[i].trackName,
               songs[i].albumName,
               songs[i].artistName,
               songs[i].duration,
               songs[i].genre);
        printf("\n\n");
    }
*/
    setlocale(LC_ALL, "spanish"); 
    FILE *file;
    file = fopen("maldito_amor.csv", "r");

    if (!file) {
        printf("Error");
        return 0;
    }

    char buff[1024];

    int rowCount = 0;
    int fieldCount = 0;

    trackInfo songs[100];

    int i = 0;
    while (fgets(buff, 1024, file)) {
        //printf("%s\n", buff ); //parsea el csv
        fieldCount = 0;
        rowCount++;
        if (rowCount == 1)  continue; //Para no tomar en cuenta los campos

        char *field = strtok(buff, ","); //token separador de registros

        while (field) {
            if (fieldCount == 0){
                strcpy(songs[i].trackName, field);}

            if (fieldCount == 1) {
                strcpy(songs[i].albumName, field);}

            if (fieldCount == 2) {
                strcpy(songs[i].artistName, field);}

            if (fieldCount == 3) {
                strcpy(songs[i].duration, field );}

            if (fieldCount == 4) {
                strcpy(songs[i].genre, field);}

            field = strtok(NULL, ",");
            fieldCount++;
        }
        i++;
    }
    fclose(file);

    printValues(songs);

    printf("\n\n%s", songs[1].duration);
    return 0;
}
 //La información de las canciones ya está en el arreglo de estructuras
void printValues (trackInfo songs[]) {
    for (int i = 0; i < 50; ++i) {
        printf("Cancion: %s\n"
               "Album: %s\n"
               "Artista: %s\n"
               "Duracion:  %s\n"
               "Genero: %s\n",
               songs[i].trackName,
               songs[i].albumName,
               songs[i].artistName,
               songs[i].duration,
               songs[i].genre);
        printf("\n");
    }
}
