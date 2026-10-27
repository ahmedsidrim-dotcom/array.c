#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

Vector* vector_create(size_t initial_capacity) {
    Vector *v = (Vector*) malloc(sizeof(Vector));
    if (!v) return NULL;
    
    v->data = (int*) malloc(initial_capacity * sizeof(int));
    if (!v->data) {
        free(v);
        return NULL;
    }
    v->size = 0;
    v->capacity = initial_capacity;
    return v;
}

int vector_push(Vector *v, int value) {
    if (v->size >= v->capacity) {
        size_t new_capacity = v->capacity * 2;
        int *temp = (int*) realloc(v->data, new_capacity * sizeof(int));
        if (!temp) return -1; // فشل إعادة تخصيص الذاكرة
        v->data = temp;
        v->capacity = new_capacity;
    }
    v->data[v->size++] = value;
    return 0;
}

void vector_free(Vector *v) {
    if (v) {
        free(v->data);
        free(v);
    }
}

int main() {
    Vector *v = vector_create(2);
    vector_push(v, 42);
    vector_push(v, 100);
    
    printf("Vector element at index 1: %d\n", v->data[1]);
    vector_free(v);
    return 0;
}
