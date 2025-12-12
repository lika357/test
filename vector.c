#include "vector.h"
#include <stdlib.h>
#include <string.h>

void vector_init(vector* v) {
    v->data = NULL;
    v->size = 0;
    v->max = 0;
}

int vector_size(vector* v) {
    return v->size;
}

building* vector_get(vector* v, int index) {
    if (index < 0 || index >= v->size) return NULL;
    return &v->data[index];
}

building* vector_begin(vector* v) {
    return v->data;
}

building* vector_end(vector* v) {
    return v->data + v->size;
}

