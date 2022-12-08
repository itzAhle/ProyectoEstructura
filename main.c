#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  setlocale(LC_ALL, "spanish");
  int num;
  // Spotify UV
  // Menu de inicio
  printf("Spotify UV\n");
  printf("[1] Explora Generos\n");
  printf("[2] Explorar Canciones\n");
  printf("[3] Reproducir\n");
  printf("[4] Salir\n");

  switch (num) {
  case 1:
    printf("[1] Explora Generos\n");
    break;
  case 2:
    printf("[2] Explorar Canciones\n");
    break;
    case 3:
    printf("[3] Reproducir\n");
    break;
    case 4:
    
  }

  /*for(int i = 0; i < 10; i++)
    printf("Ayudaaaaa\n"); */

  return 0;
}