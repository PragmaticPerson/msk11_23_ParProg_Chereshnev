#include <stdio.h>
#include <stdlib.h>

FILE *openFile(const char *, const char *);
void printFileContent(FILE *);

int main() {
    char *fileName = "D:\\ParallelProg\\comp_system.txt";
    char *mode = "r";
    FILE *file = openFile(fileName, mode);

    printFileContent(file);

    fclose(file);
    return 0;
}

FILE *openFile(const char *fileName, const char *mode) {
    FILE *file = fopen(fileName, mode);
    if (file == NULL) {
        perror("Не удалось открыть файл");
        exit(1);
    }
    return file;
}

void printFileContent(FILE *file) {
    if (file != NULL) {
        char line[100];

        printf("Технические характеристики вычислительной системы:\n");
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
    } else {
        printf("Ошибка чтения файла!");
    }
}