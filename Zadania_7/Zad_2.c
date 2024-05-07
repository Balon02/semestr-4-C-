#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 180

int extract_game_number(char line[]) {
    int i = 0;
    int game_number = 0;
    int is_game_found = 0;

    // Find the position
    while (line[i] != '\0') {
        if (line[i] == 'G' && line[i + 1] == 'a' && line[i + 2] == 'm' && line[i + 3] == 'e') {
            is_game_found = 1;
            break;
        }
        i++;
    }

    if (is_game_found) {
        i += 5; // Skip
        while (isdigit(line[i])) {
            game_number = game_number * 10 + (line[i] - '0');
            i++;
        }
    }

    return game_number;
}

int main(){
    const char *filename = "../input2.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Nie mozna otworzyc pliku.\n");
        exit(EXIT_FAILURE);
    }

    int idsum = 0;
    int powsum = 0;
    char line[MAX];
    int max_red = 12;
    int max_green = 13;
    int max_blue = 14;

    while (fgets(line, sizeof(line), file)) {
        int linelen = 0;
        int flag = 0;
        int redmin = 0;
        int greenmin = 0;
        int bluemin = 0;

        for (int i = 0; i < strlen(line); i++){
            if(line[i] != NULL){
                linelen++;
            }
        }

        int game_number = extract_game_number(line);
        int number;

        for (int i = 8; i < linelen; i++) {
            if (isdigit(line[i])) {
                if (isdigit(line[i + 1])) {
                    number = (line[i] - '0') * 10 + (line[i + 1] - '0');
                    i++;
                } else {
                    number = line[i] - '0';
                }
            }

            if (strncmp(&line[i], "red", 3) == 0) {
                if (number > max_red) {
                    flag = 1;
                }
                if (number > redmin){
                    redmin = number;
                }
            }

            if (strncmp(&line[i], "green", 5) == 0) {
                if (number > max_green) {
                    flag = 1;
                }
                if (number > greenmin){
                    greenmin = number;
                }
            }

            if (strncmp(&line[i], "blue", 4) == 0) {
                if (number > max_blue) {
                    flag = 1;
                }
                if (number > bluemin){
                    bluemin = number;
                }
            }

        }

        powsum += (redmin * greenmin * bluemin);

        if (flag == 0){
            idsum += game_number;
        }
    }

    fclose(file);

    printf("suma gier: %d\n",idsum);
    printf("suma mocy: %d",powsum);

    char keepopen[999];
    scanf("%s", keepopen);
    return 0;
}