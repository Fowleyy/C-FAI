#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vector {
    int* data;
    int size;
} Vector;

Vector* Vector_create() {
    Vector* vector = (Vector*)malloc(sizeof(Vector));
    vector->data = (int*)malloc(sizeof(int) * 4);
    vector->size = 0;
    return vector;
}

Vector* Vector_insert(Vector* old_vector, int item) {
    Vector* new_vector = (Vector*)malloc(sizeof(Vector));
    new_vector->size = old_vector->size + 1;
    new_vector->data = (int*)malloc(sizeof(int) * new_vector->size);

    memcpy(new_vector->data, old_vector->data, sizeof(int) * old_vector->size);

    new_vector->data[new_vector->size - 1] = item;

    return new_vector;
}



Vector* from_static(int* pole, int size) {
    Vector* new_vector = (Vector*)malloc(sizeof(Vector));
    new_vector->size = size;
    new_vector->data = (int*)malloc(sizeof(int) * size);

    memcpy(new_vector->data, pole, sizeof(int) * size);

    return new_vector;
}



Vector* Vector_delete_at(Vector* old_vector, int p) {
    if (p < 0 || p >= old_vector->size) {
        return old_vector;
    }

    Vector* new_vector = (Vector*)malloc(sizeof(Vector));
    new_vector->size = old_vector->size - 1;
    new_vector->data = (int*)malloc(sizeof(int) * new_vector->size);

    memcpy(new_vector->data, old_vector->data, sizeof(int) * p);

    memcpy(new_vector->data + p, old_vector->data + p + 1, sizeof(int) * (old_vector->size - p - 1));

    return new_vector;
}


Vector *vector_sort(Vector *vector, int ascending) {
    Vector *sorted_vector = Vector_create();
    memcpy(sorted_vector->data, vector->data, sizeof(int) * vector->size);
    sorted_vector->size = vector->size;

    int i, j;
    for (i = 0; i < sorted_vector->size - 1; i++) {
        for (j = 0; j < sorted_vector->size - i - 1; j++) {
            int *current = &sorted_vector->data[j];
            int *next = &sorted_vector->data[j + 1];
            if (ascending) {
                if (*current > *next) {
                    int temp = *current;
                    *current = *next;
                    *next = temp;
                }
            } else {
                if (*current < *next) {
                    int temp = *current;
                    *current = *next;
                    *next = temp;
                }
            }
        }
    }

    return sorted_vector;
}

void Vector_Print(Vector* vector) {
    for (int i = 0; i < vector->size; i++) {
        printf("%d ", vector->data[i]);
    }
    printf("\n");
}