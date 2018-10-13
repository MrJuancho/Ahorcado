#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int comprobar_letra(char letra);
int buscar_letra(char letra);

char *palabra;
char palabra_escrita[20];
char palabra_adivinar[20];

int main() {
    char menu;
    int vida = 0;
    int juego = 1;
    int existe;
    int acierto = 0;

    char letra;
    do {
        menu_i();
        scanf("%c",&menu);
        switch (menu){
            case '1':
                palabra = random_p();
                int x = 0;
                for (x = 0; *(palabra+x) != '\0' ; ++x) { palabra_escrita[x] = *(palabra + x); }
                palabra_escrita[x] = '\0';
                int y = 0;
                for (y = 0; palabra_escrita[y] != '\0' ; ++y);
                int i = 0;
                for (i = 0; i < y; ++i) { palabra_adivinar[i] = '_'; }
                palabra_adivinar[i] = '\0';
                vida = vidas(vida);
                do {
                    do {
                        system("cls");
                        existe=acierto=0;
                        ahorcado(vida);
                        inicializar_juego(palabra, palabra_adivinar);
                        printf("Ingresa una letra :");
                        scanf(" %c",&letra);
                        fflush(stdin);
                        existe = comprobar_letra(letra);
                    }while(existe);
                    acierto = buscar_letra(letra);
                    if (acierto == 1){
                        if(strcmp(palabra_escrita,palabra_adivinar)!=0){
                            juego = 1;
                        }else{
                            printf("Ganaste :D\n");
                            printf("La palabra es :");
                            puts(palabra_adivinar);
                            juego = 0;
                        }
                    }else{
                        --vida;
                        if(vida == 0){
                            juego = 0;
                            printf("Perdiste :C\n");
                            printf("La palabra era : ");
                            puts(palabra_escrita);
                        }
                    }
                }while(juego == 1);
                system("pause");
                fflush(stdin);
                break;
            case '2':
                printf("Ingresa la palabra para jugar(esto no lo deberia de ver el otro jugador).\n");
                scanf("%s",palabra_escrita);
                system("cls");
                vida = vidas(vida);
                palabra = palabra_escrita;
                puts(palabra);
                int b = 0;
                for (b = 0; palabra_escrita[b] != '\0' ; ++b);
                int c = 0;
                for (c = 0; c < b; ++c) { palabra_adivinar[c] = '_'; }
                palabra_adivinar[c] = '\0';
                do {
                    do {
                        system("cls");
                        existe=acierto=0;
                        ahorcado(vida);
                        inicializar_juego(palabra, palabra_adivinar);
                        printf("Ingresa una letra :");
                        scanf(" %c",&letra);
                        fflush(stdin);
                        existe = comprobar_letra(letra);
                    }while(existe);
                    acierto = buscar_letra(letra);
                    if (acierto == 1){
                        if(strcmp(palabra_escrita,palabra_adivinar)!=0){
                            juego = 1;
                        }else{
                            printf("Ganaste :D\n");
                            printf("La palabra es :");
                            puts(palabra_adivinar);
                            juego = 0;
                        }
                    }else{
                        --vida;
                        if(vida == 0){
                            juego = 0;
                            printf("Perdiste :C\n");
                            printf("La palabra era : ");
                            puts(palabra_escrita);
                        }
                    }
                }while(juego == 1);
                system("pause");
                break;
            case '0':
                printf("MADE BY : Juan Carlos Calderon Davila.\n");
                break;
            default:
                printf("Error, vuelve a intentarlo.\n");
                system("cls");
                break;
        }
        fflush(stdin);
    }while(menu != '0');
    system("pause");
    return 0;
}

int buscar_letra(char letra){
    int acierto = 0;
    int a = 0;
    for (a = 0; palabra_escrita[a] != '\0' ; ++a);
    for (int i = 0; i < a ; ++i) {
        if(letra == palabra[i]){
            palabra_adivinar[i] = letra;
            acierto = 1;
        }
    }
    return acierto;
}

int comprobar_letra(char letra){
    int existe = 0;
    int x;
    int a = 0;
    for (a = 0;  palabra_adivinar[a] != '\0' ; ++a);
    for (x = 0; x < a; ++x) {
        if(letra == palabra_adivinar[x]){
            printf("Esa letra ya ha sido escrita\n");
            existe = 1;
            system("pause");
        }
    }
    return existe;
}