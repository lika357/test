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
building* vector_next(vector* v, building* current) {
    if (current == vector_end(v) - 1) return NULL;
    return current + 1;
}
building* vector_to(vector* v, building* current) {
    if (current == vector_begin(v)) return NULL;
    return current - 1;
}
static void vector_resize(vector* v, int new_max) {
    building* new_data = (building*)malloc(new_max * sizeof(building));
    for (int i = 0; i < v->size; i++) {
        new_data[i] = v->data[i];
    }
    free(v->data);
    v->data = new_data;
    v->max = new_max;
}
void vector_push_back(vector* v, building* b) {
    if (v->size >= v->max) {
        int new_max1 = v->max * 2;
        vector_resize(v, new_max1);
    }
    v->data[v->size] = *b;
    v->size++;
}
void vector_insert(vector* v, int index, building* b) {
    if (index < 0 || index > v->size) return;
    
    if (v->size >= v->max) {
        int new_max1 = v->max * 2;
        vector_resize(v, new_max1);
    }
    
    for (int i = v->size; i > index; i--) {
        v->data[i] = v->data[i - 1];
    }
    
    v->data[index] = *b;
    v->size++;
}
void vector_push_front(vector* v, building* b) {
    vector_insert(v, 0, b);
}
void vector_remove(vector* v, int index) {
    if (index < 0 || index >= v->size) return;
    
    for (int i = index; i < v->size - 1; i++) {
        v->data[i] = v->data[i + 1];
    }
    
    v->size--;
}
void vector_pop_front(vector* v) {
    vector_remove(v, 0);
}
void vector_pop_back(vector* v) {
     v->size--;
}
void vector_swap(vector* v, int i, int j) {
    if (i < 0 || i >= v->size || j < 0 || j >= v->size) return;
    
    building x = v->data[i];
    v->data[i] = v->data[j];
    v->data[j] = x;
}
void vector_clear(vector* v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->max = 0;
}
void vector_from_array(vector* v, building* array, int n) {
    vector_clear(v);
    for (int i = 0; i < n; i++) {
        vector_push_back(v, &array[i]);
    }
}

building* vector_to_array(vector* v) {
    building* array = (building*)malloc(v->size * sizeof(building));
    for (int i = 0; i < v->size; i++) {
        array[i] = v->data[i];
    }
    return array;
}