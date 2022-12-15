//Resumen main 2: main2 se encarga de crear el struct de las canciones que utilizaremos 
//, mandaremos a llamar este archivo para la info de las canciones -Jonthan

//feeling2 es el archivo en el que se agregaran las canciones
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
//Este solo contiene las funciones para agregar a la lista y 
//las colas a partir del struct que lee el archivo csv


int n, m;

void imprimcola();


//Va a dar error porque hay dos archivos con funcion main
typedef struct { //Estructura guardada a partir del CSV
    char trackName[100];
    char albumName[100];
    char artistName[100];
    char duration[10];
    char dur[6];
    char genre[100];
}trackInfo; 
trackInfo songs[100]; 

typedef struct nodo { //Estructura para la lista
  char *trackName;
  char *artistName;
  struct nodo *sig;
}listaTrack; 

typedef struct gene { //Estructura para la lista
  char *tr_gen;
  struct nodo *sig;
}gene; 
gene gen[100]; 

//--- Estructuras y funciones para la cola 
typedef struct elemento {    //Esta es la cola de la lista de reproduccion
  char *trackName; 
  char *artistName; 
  struct elemento *sig; 
}elemento;

elemento *inicio = NULL; // ps ya estos son los punteros qe van al inicio yba l final
elemento *fin = NULL; 


void agregarACola (elemento * elem) { //Alejandro - Jeremy
  printf("Aqui tambien entra a AgregarCola\n");
  elem -> sig = NULL;  //Este inicializa los elementos, o sea hace que la cola funcione como tal 
  if (inicio == NULL) {
    inicio = elem;
    fin = elem; 
  } else {
    fin -> sig = elem;
    fin = elem; 
  }
}

elemento * extraer () { // Alejandro
  if (inicio == NULL) { //este se relaciona con la anterior, pero digamos que solo 
    return NULL;  //devuelve el NULL en caso de que esté vacía 
  }

  printf("Entra a extraer\n");
  
  elemento * elem = inicio;  //y ps aqui ya manda los elementos al final de la cola
  inicio = inicio -> sig; 
  return elem; 
}

void impcol();

void agregarCancionCola (trackInfo songs[], int n) { // Alejandro  - Jeremy .En esta funcion toma como parametro la estructura con la info de las canciones, el int n servirá como el parametro para decidir que cancion elegida se agregará a la cola, tomando en cuenta que ya podemos hacerlo desde el menú. 
  elemento * nuevaCancion = (elemento *) malloc(sizeof(elemento));
  nuevaCancion -> trackName = songs[n].trackName;  //Se agregan los valores de songs[] a 
                                                   //nuevacancion. sunombre y artista. 
  
  
  nuevaCancion -> artistName = songs[n].artistName; //artista, es decir las dos info que                                                           //necesitamos mostrar en el reproductor

  
  printf("Si entra a la funcion\n");
 
  
  agregarACola(nuevaCancion); //está es importante porque agrega la informacion de arriba directamente al final de la cola. Es decir, esta hace la chamba. 
    imprimcola();
  }

// Y para usar la funcion sería 
/*
agregarCancionCola(songs, 6);   funcion(estructura, cancion elegida); 

  elemento * di = extraer(); //inicializa la funcion extraer, sirve para poder                                     imprimir los elementos de la cola

  while (di != NULL) {  desde aqui 
    printf("'%s'\n%s\n\n", di -> trackName, di -> artistName); 
    di = di -> sig; //Siempre debe llevar esto que apunte al siguiente porque sino va a imprimir infinitamente. y yap. 
  } 

Imprime los elementos de la cola 

*/

/*void imprep(){
  imprimirCanciones(elemento,1,0);
}*/

void impcol(){
  
  elemento * di = extraer(); //inicializa la funcion extraer, sirve para poder                                     imprimir los elementos de la cola

  while (di != NULL) { // desde aqui 
    printf("'%s'\n%s\n\n", di -> trackName, di -> artistName); 
    di = di -> sig; //Siempre debe llevar esto que apunte al siguiente porque sino va a imprimir infinitamente. y yap. 
  } 
}


//---- Funciones para la lista

listaTrack *listaCancion(listaTrack * lista) { // Alejandro
  lista = NULL; 
  return lista;
}

listaTrack *agregarTrack (listaTrack * lista, trackInfo songs[]) {
  listaTrack * nuevoTrack, *aux;   //Funcion para agregar varias canciones, - Jeremy - Alejandro
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
  listaTrack *nuevoTrack, * aux; //Esta funcion puede tomar como parametro un entero para seleccionar la cancion desde el menú de canciones, 
  nuevoTrack = (listaTrack *) malloc (sizeof (listaTrack)); // Alejandro - Jeremy
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

//void breachcanc(int num);

void breachcanc(int num){

  n=num;
  
  agregarCancionCola(songs,n);
  
}

//---Defincion de algunas funciones 
void printValues (trackInfo songs[]);
void imprimirCanciones (trackInfo songs[],int elmi,int elmf);
void genee();
void elegirCancion (trackInfo songs[]); //No está terminada, ta complica

//Esto era un main pero lo transforme en un void para mandar a llamar la info de las canciones en el main original-Jonathan

void opnf(){
  setlocale(LC_ALL, "spanish"); 
    FILE *file;
    file = fopen("feeling2.csv", "r"); //Voy a cambiar archivo de las canciones

    if (!file) {
        printf("Error");
    }
}

void cancinf(int avr,int avr2) { // - Alejandro - Jonathan - Jeremy
    
    setlocale(LC_ALL, "spanish"); 
    FILE *file;
    file = fopen("feeling2.csv", "r"); //Voy a cambiar archivo de las canciones

    if (!file) {
        printf("Error");
    }

    char buff[1024];
    int rowCount = 0;
    int fieldCount = 0;
    int cont=10;
    int cont2=0;
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
        //cont++;
    }
    fclose(file);
  
    cont=cont+avr;
    cont2=cont2+avr2;
    //printf("%i\n",cont);

  
  //printValues(songs,cont); //Estas dos hacen dos cosas diferentes pero no me acuerdo
  imprimirCanciones(songs,cont2,cont); 
  }
  //No se para que servian pero si son necesarias vuelvan a ponerlas -Jonathan
  
  /*
  listaTrack *lista = listaCancion(lista);
  lista = agregarTrack(lista, songs); 
  lista = agregarTrack(lista, songs); 
  lista = agregarTrackUnico(lista, son

  
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

  printf("\n\n%s", songs[1].duration);*/


 //La información de las canciones ya está en el arreglo de estructuras
void printValues (trackInfo songs[]) { // - Alejandro - Jonathan
    for (int i = 0; i < sizeof(songs); ++i) {
        printf(//"Cancion: %s\n"
               "Album: %s\n"
               //"Artista: %s\n"
               //"Duracion:  %s\n"
               //"Genero: %s\n",
               //songs[i].trackName,
               ,songs[i].albumName
               //songs[i].artistName,
               //songs[i].duration,
               //songs[i].genre
          );
        printf("\n");
    }
}

void imprimirCanciones(trackInfo songs[],int elmi,int elmf) {// Alejandro - Jonathan
  
  printf("Canción\nArtista\n\n");
  for (int i = elmi; i < elmf; ++i) {
    printf("[%d] -> '%s'\n       %s\n\n", i, songs[i].trackName, 
      songs[i].artistName);
  }
}


// Para el menú de generos y canciones por generos
void imprimirGeneros(trackInfo songs[] /*Otro parametro aqui */) { //Alejandro - Jeremy
  for (int i = 0; i < 10; ++i) {
    printf("[%d] -> %s", i, songs[i].trackName); 
  }
}

void imprimcola(){ //Alejandro - Jeremy
  
  elemento * di = extraer(); //inicializa la funcion extraer, sirve para poder                                     imprimir los elementos de la cola

  while (di != NULL) {  //desde aqui 
    printf("'%s'\n%s\n\n", di -> trackName, di -> artistName); 
    di = di -> sig; //Siempre debe llevar esto que apunte al siguiente porque sino va a imprimir infinitamente. y yap. 
  } 
}

//int seleccionGenero(){}

void genee(){

  opnf();

  

  printValues(songs);
  
}

/*void verGeneroSeleccionado(trackInfo songs[]) {
  while(songs[1].genre == songs[]){}
}*/