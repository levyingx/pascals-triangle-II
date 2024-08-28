#include <stdio.h>
#include <stdlib.h>

void create_file(int **matrix, int num) {
    FILE *file = fopen("table.md", "w");
    if (file == NULL) {
        printf("Error opening file\n");
    } 

    for (int i = 1; i <= num; i++) {
        fprintf(file, "| %d ", i);
    }
    
    fprintf(file, "\n");

    for (int i = 0; i < num; i++) {
        fprintf(file, "| :---: ");
    }
    
    fprintf(file, "\n");

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (matrix[i][j] != 0) {
                fprintf(file, "| %d ", matrix[i][j]);
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    int num;

    printf("Quantas linhas?");
    scanf("%d", &num);

    int **matrix = calloc(num, sizeof(int*));

    for (int i = 0; i < num; i++) { 
        matrix[i] = calloc(num, sizeof(int));
    }

    for (int i = 0; i < num; i++) {
        matrix[i][0] = 1;
    }

    for (int i = 1; i < num; i++) {
        for (int j = 1; j < num; j++) { 
            matrix[i][j] = matrix[i - 1][j] + matrix[i - 1][j - 1]; 
        }
    }

    create_file(matrix, num);

    for (int i = 0; i < num; i++) {
        free(matrix[i]);
    }

    free(matrix);
} 
