#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

//Prototipos 
void menuPrincipal(); 
//explorar generos 
void explorargeneros ();
//Expplorar caciones 
void explorarCanciones(); 

void reproductor(); 
void Genero ();
void salir(); 

int num; //variable para seleccionar Menús
char opc; //variable para seleccionar opciones dentro del menú 

int main() {
  setlocale(LC_ALL, "spanish");
  
  // Spotify UV
  menuPrincipal(); 
  
}


void menuPrincipal(){
  // Menu de inicio
  printf("Spotify UV\n");
  printf("[1] Explora Generos\n");
  printf("[2] Explorar Canciones\n");
  printf("[3] Reproducir\n");
  printf("[4] Salir\n");
  scanf("%d", &num); 
  switch (num) {
  case 1:
    //printf("[1] Explora Generos\n");
    explorargeneros(); 
    break;
  case 2:
    //printf("[2] Explorar Canciones\n");
    explorarCanciones(); 
    break;
  case 3: 
    reproductor(); 
    //printf("[3] Reproducir\n");
    break;
  case 4: salir(); 
  default: 
    break;
  }
  //return 0;
}

void explorargeneros (){
fflush(stdin); 
system("cls");
  printf("[P] Regresar al menu\n");
  printf("[1...n] Selecionar un genero\n");
  printf("Selecione una opcion: ");
  scanf("%c", &opc);

  switch (opc){
    case 'p':
      system("cls"); 
      menuPrincipal(); 
      system("pause"); 
      break;  
    case 'n':
    printf("Nombre de genero");
    break;
          
  }
  }


void explorarCanciones() {
  fflush(stdin); 
  system("cls"); 
  printf("[P] Regresar al menú principal\n"
    "[A] 10 Canciones anteriores\n"
    "[D] 10 canciones siguientes\n"
    "[Q] Agregar a la cola una canción de la lista\n"
    "[R] Reproducir una canción\n\n");
  printf("Seleccione una opción: "); 
  scanf("%c", &opc); 

  switch(opc) {
    case 'p': system("cls"); menuPrincipal(); system("pause"); break; //Simula las funciones
    case 'a': printf("[A] 10 Canciones anteriores\n"); break;             //por el momento
    case 'd': printf("[D] 10 Canciones siguientes\n"); break; 
    case 'q': printf("[Q] Agregar a la cola una canción de la lista"); break; 
    case 'r': printf("[R] Reproducir una canción"); break; 
  
  }
}

void reproductor() {
  fflush(stdin); 
  system("cls"); 
  printf("Reproductor\n\n"); 
  printf("Actualmente sonando: \n\n\n\n"); 
  printf("[P] Regresr al menú principal\n"
    "[A] Canción anterior\n"
    "[D] Siguiente canción\n"
    "[C] Repetir canción\n"
    "[R] Activar / Desactivar repetición\n"
    "Seleccione una opción: ");

  scanf("%c", &opc); 
  switch (opc) {
    case 'p': system("cls"); menuPrincipal(); break; 
    case 'a': printf("Canción anterior"); break; 
    case 'd': printf("Canción siguiente"); break; 
    case 'c': printf("Repetir canción"); break; 
    case 'r': printf("Activar / Desactivar repetición"); break;
  }
}

void genero (){
  fflush(stdin); 
  system("cls");
  printf("[P] Regresar al menu\n");
  printf("[Q] Agregar a la cola de reproduccion\n");
  printf("[R] Reproducir todo a esta lista\n");
  printf("[1...N]+[Q] Agregar a la cola de una cacion de la lista\n" );
  printf("[1...N]+[R] Reproducir una cancion");
  printf("Selecione una opcion: ");
  scanf("%c", &opc); 

    switch (opc){
      case 'p': 
      system("cls");
      menuPrincipal();
      break;
      case 'q':
      printf("Agregar a la cola de reproduccion\n");
      break;
      case 'r':
      printf("Reproducir todo lo de esta lista\n");
      break;
      case 'Q':
      printf("Agrega una cancion a la cola de una cancion de la lista \n");
      break;
      case 'R':
      printf("Reproducir una cancion\n");
    }
}
void salir() {
  exit(1); 
}