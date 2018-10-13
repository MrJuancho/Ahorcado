#ifndef AHORCADO_FUNCIONES_H
#define AHORCADO_FUNCIONES_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu_i(){
    printf("-A H O R C A D O-\n");
    printf("Selecciona una opcion para continuar...\n");
    printf("1 >> P V E\n");
    printf("2 >> P V P\n");
    printf("0 >> Salir\n");
}

char *random_p(){
    const char *palabras[30] = {"juanelo", "diego", "perro", "gato", "tacos", "pescado", "silla", "mesa", "lapiz", "jessy",
                                "pluma", "leche", "pan", "papa", "paloma","metrobus","concha","anime","cinturon","balon",
                                "juegos","tormenta","calor","waifu","hermano","escuela","pastor","quesadilla","programacion","upiita"};
    srand((unsigned)time(NULL));
    int x = rand()%31;
    char *p = palabras[x];
    return p;
}

int vidas(int vida){
    printf("Ingresa un numero de vidas entre 1 y 10 :");
    while(vida < 1 || vida > 10) {
        scanf("%d", &vida);
        if (vida < 1 || vida > 10) {
            fflush(stdin);
            printf("Sobrepasas el limite...\n");
        }
    }
    return vida;
}

void inicializar_juego(char *palabra, char *adivinar){
    int a = 0;
    for (a = 0; *(palabra + a) != '\0' ; ++a);
    for (int i = 0; i < a; ++i) {
        printf("%c ", adivinar[i]);
    }
    printf("\n");
}

void ahorcado(int vidas){
    printf("Que comience el juego:\n");
        if(vidas == 10){
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\t");
            printf("\nTienes %d vidas.\n",vidas);
        }else if(vidas == 9){
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("\t");
            printf("\nTienes %d vidas.\n",vidas);
        }else if(vidas == 8){
            printf("|----\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("\t");
            printf("\nTienes %d vidas.\n",vidas);
        }else if(vidas == 7){
            printf("|--------|\n");
            printf("|         \n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("\t");
            printf("\nTienes %d vidas.\n",vidas);
        }else if(vidas == 6){
            printf("|--------|\n");
            printf("|       OnO \n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("\t");
            printf("\nTienes %d vidas.\n",vidas);
        }else if(vidas == 5){
            printf("|--------|\n");
            printf("|       OnO \n");
            printf("|        |\n");
            printf("|\n");
            printf("|\n");
            printf("\t");
            printf("\nTienes %d vidas.\n",vidas);
        }else if(vidas == 4){
            printf("|--------|\n");
            printf("|       OnO \n");
            printf("|        |/\n");
            printf("|\n");
            printf("|\n");
            printf("\t");
            printf("\nTienes %d vidas.\n",vidas);
        }else if(vidas == 3){
            printf("|--------|\n");
            printf("|       OnO \n");
            printf("|        |/\n");
            printf("|       /|\n");
            printf("|\n");
            printf("\t");
            printf("\nTienes %d vidas.\n",vidas);
        }else if(vidas == 2){
            printf("|--------|\n");
            printf("|       OnO \n");
            printf("|       -|/\n");
            printf("|        |\n");
            printf("|       \n");
            printf("\t");
            printf("\nTienes %d vidas.\n",vidas);
        }else if(vidas == 1){
            printf("|--------|\n");
            printf("|       OnO \n");
            printf("|       -|/\n");
            printf("|       /|\n");
            printf("|         \n");
            printf("\t");
            printf("\nTienes %d vidas.\n",vidas);
        }else if(vidas == 0){
            printf("|--------|\n");
            printf("|       XnX \n");
            printf("|        |/\n");
            printf("|       /|\n");
            printf("|         \n");
            printf("\t");
            printf("\nTienes %d vidas.\n",vidas);
        }
}

#endif //AHORCADO_FUNCIONES_H
