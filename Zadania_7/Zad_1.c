#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int wordToNumeral(char *word) {
    if (strcmp(word, "zero") == 0) return 0;
    if (strcmp(word, "one") == 0) return 1;
    if (strcmp(word, "two") == 0) return 2;
    if (strcmp(word, "three") == 0) return 3;
    if (strcmp(word, "four") == 0) return 4;
    if (strcmp(word, "five") == 0) return 5;
    if (strcmp(word, "six") == 0) return 6;
    if (strcmp(word, "seven") == 0) return 7;
    if (strcmp(word, "eight") == 0) return 8;
    if (strcmp(word, "nine") == 0) return 9;
    return -1; //
}

int sumEnergy(const char *filename, int option) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Cannot open file");
        exit(EXIT_FAILURE);
    }
    char* words[] = {"zero","one", "two", "three" ,"four", "five" ,"six" ,"seven", "eight", "nine"};

    int sum = 0;
    char line[100];

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;

        int number_first = -1;
        int number_last = -1;
        int line_length = strlen(line);

        if (option == 1) {
            for (int i = 0; i < line_length; i++) {
                if (isdigit(line[i])) {
                    number_first = line[i] - '0';
                    break;
                }
            }
            for (int i = line_length - 1; i >= 0; i--) {
                if (isdigit(line[i])) {
                    number_last = line[i] - '0';
                    break;
                }
            }
        } else if (option == 2) {
            for (int i = 0; i < line_length; i++) {
                if (isdigit(line[i])) {
                    number_first = line[i] - '0';
                    break;
                } else {
                    for (int j = 0; j < 10; j++) {
                        if (strncmp(&line[i], words[j], strlen(words[j])) == 0) {
                            number_first = wordToNumeral(words[j]);
                            break;
                        }
                    }
                    if (number_first != -1) {
                        break;
                    }
                }
            }
            for (int i = line_length - 1; i >= 0; i--) {
                if (isdigit(line[i])) {
                    number_last = line[i] - '0';
                    break;
                } else {
                    for (int j = 0; j < 10; j++) {
                        if (strncmp(&line[i], words[j], strlen(words[j])) == 0) {
                            number_last = wordToNumeral(words[j]);
                            break;
                        }
                    }
                    if (number_last != -1) {
                        break;
                    }
                }
            }
        }

        sum += (number_first * 10) + number_last;
    }

    fclose(file);
    return sum;
}

int main() {
    const char *filename = "../input1.txt";
    int energySum1 = sumEnergy(filename, 1);
    printf("Suma energii 1: %d\n", energySum1);

    int energySum2 = sumEnergy(filename, 2);
    printf("Suma energii 2: %d\n", energySum2);

    char keepopen[999];
    scanf("%s", keepopen);
    return 0;
}