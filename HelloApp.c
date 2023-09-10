#include <stdio.h>
#include <stdlib.h>

FILE* openFile(const char*, const char*);
void printFileContent(FILE*);
int* createDynamicArray(int);
void fillArrayWithIndices(int*, int);
void printArrayRange(int*, int, int);

int main() {
    char* fileName = "D:\\ParallelProg\\comp_system.txt";
    char* mode = "r";
    FILE* file = openFile(fileName, mode);

    printFileContent(file);

    int size;
    printf("\n\nВведите размер массива: ");
    scanf("%d", &size);

    int* myArray = createDynamicArray(size);

    fillArrayWithIndices(myArray, size);

    printf("Массив заполнен индексами от 0 до %d.\n", size - 1);

    int start, end;
    printf("Введите начало и конец диапазона (например, 0 4): ");
    scanf("%d %d", &start, &end);

    printf("Содержимое массива в заданном диапазоне: ");
    printArrayRange(myArray, start, end);

    free(myArray);
    fclose(file);
    return 0;
}

FILE* openFile(const char* fileName, const char* mode) {
    FILE* file = fopen(fileName, mode);
    if (file == NULL) {
        perror("Не удалось открыть файл");
        exit(1);
    }
    return file;
}

void printFileContent(FILE* file) {
    if (file != NULL) {
        perror("Ошибка чтения файла! Невозможно вывести содержимое в консоль.");
        return;
    }
    char line[100];

    printf("Технические характеристики вычислительной системы:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
}

int* createDynamicArray(int size) {
    int* dynamicArray = (int*)malloc(size * sizeof(int));

    if (dynamicArray == NULL) {
        perror("Ошибка выделения памяти.\n");
        exit(1);
    }

    return dynamicArray;
}

void fillArrayWithIndices(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }
}

void printArrayRange(int* array, int start, int end) {
    for (int i = start; i <= end; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}