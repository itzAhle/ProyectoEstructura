#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
//Este solo contiene las funciones para agregar a la lista y 
//las colas a partir del struct que lee el archivo csv
//Quuitar comas al csv y columnas

//Va a dar error porque hay dos archivos con funcion main
typedef struct { //Estructura guardada a partir del CSV
    char trackName[100];
    char albumName[100];
    char artistName[100];
    char duration[10];
    char dur[6];
    char genre[100];
}trackInfo; //ok
trackInfo songs[100]; 

typedef struct nodo { //Estructura para la lista
  char *trackName;
  char *artistName;
  struct nodo *sig;
}listaTrack; 

//--- Estructuras y funciones para la cola
typedef struct elemento {
  char *trackName; 
  char *artistName; 
  struct elemento *sig; 
}elemento;

elemento *inicio = NULL;
elemento *fin = NULL; 

void agregarACola (elemento * elem) {
  elem -> sig = NULL; 
  if (inicio == NULL) {
    inicio = elem;
    fin = elem; 
  } else {
    fin -> sig = elem;
    fin = elem; 
  }
}

elemento * extraer () {
  if (inicio == NULL) {
    return NULL; 
  }

  elemento * elem = inicio; 
  inicio = inicio -> sig; 
  return elem; 
}

void agregarCancionCola (trackInfo songs[], int n) {
  elemento * nuevaCancion = (elemento *) malloc(sizeof(elemento));
  nuevaCancion -> trackName = songs[n].trackName;
  nuevaCancion -> trackName = songs[n].artistName;
  agregarACola(nuevaCancion);
}

//---- Funciones para la lista

listaTrack * listaCancion(listaTrack * lista) {
  lista = NULL; 
  return lista;
}

listaTrack *agregarTrack (listaTrack * lista, trackInfo songs[]) {
  listaTrack * nuevoTrack, *aux;   //Funcion para agregar varias canciones, no está terminada
  for(int i = 0; i < 10; ++i) {
    nuevoTrack = (listaTrack *) malloc (sizeof (listaTrack)); 
    nuevoTrack -> trackName = songs[i].trackName; 
    nuevoTrack -> artistName = songs[i].artistName; 
    nuevoTrack -> sig = NULL; 

    if (lista == NULL) {
      lista = nuevoTrack; 
    } else {
      aux = lista; 
      while (aux -> sig == NULL) {
        aux = aux -> sig; 
      }
      aux -> sig = nuevoTrack; 
    }
  }
  return lista; 
}

listaTrack *agregarTrackUnico (listaTrack *lista, trackInfo songs[]) {
  listaTrack *nuevoTrack, * aux; //Esta funcion puede tomar como parametro un entero para seleccionar la cancion desde el menú de canciones, no está terminada
  nuevoTrack = (listaTrack *) malloc (sizeof (listaTrack)); 
  nuevoTrack -> trackName = songs[2].trackName; 
  nuevoTrack -> artistName = songs[2].artistName; 
  nuevoTrack -> sig = NULL;

  if(lista == NULL) {
    lista = nuevoTrack;
  } else {
      aux = lista;
      while (aux->sig != NULL) {
        aux = aux->sig;
      }
    aux->sig = nuevoTrack;
  }
  return lista;   
}

//---Defincion de algunas funciones 
//Programacion en espanglish xd
void printValues (trackInfo songs[]);
void imprimirCanciones (trackInfo songs[]);
void elegirCancion (trackInfo songs[]); //No está terminada, ta complica

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
*/ //Codigo feooooooo


    setlocale(LC_ALL, "spanish"); 
    FILE *file;
    file = fopen("feeling2.csv", "r"); //Voy a cambiar archivo de las canciones

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

  printValues(songs); //Estas dos hacen dos cosas diferentes pero no me acuerdo
  imprimirCanciones(songs); 

  listaTrack *lista = listaCancion(lista);
  lista = agregarTrack(lista, songs); 
  lista = agregarTrack(lista, songs); 
  lista = agregarTrackUnico(lista, songs);

  while (lista != NULL) { //imprime la informacion que se agregó a la lista
    printf("'%s'\n%s\n\n", lista -> trackName, lista -> artistName);
    lista = lista -> sig; 
  }

  agregarCancionCola(songs, 5); 
  agregarCancionCola(songs, 6); 

  elemento * di = extraer(); 

  while (di != NULL) {
    printf("'%s'\n%s\n\n", di -> trackName, di -> artistName); 
    di = di -> sig; //No encontraba el error aqui aaaaa
  }

  printf("\n\n%s", songs[1].duration);
  return 0;
}
 //La información de las canciones ya está en el arreglo de estructuras
void printValues (trackInfo songs[]) {
    for (int i = 0; i < 2; ++i) {
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

void imprimirCanciones(trackInfo songs[]) {
  printf("Canción\nArtista\n\n");
  for (int i = 0; i < 10; ++i) {
    printf("[%d] -> '%s'\n       %s\n\n", i, songs[i].trackName, 
      songs[i].artistName);
  }
}
