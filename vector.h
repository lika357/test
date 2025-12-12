#ifndef VECTOR_H
#define VECTOR_H
#include "building.h"
typedef struct {
    building* data;
    int size;
    int max;
} vector;
void vector_init(vector* v);
int vector_size(vector* v);
building* vector_get(vector* v, int index);
building* vector_begin(vector* v);
building* vector_end(vector* v) ;
building* vector_next(vector* v, building* current);
building* vector_to(vector* v, building* current);
static void vector_resize(vector* v, int new_max);
void vector_push_back(vector* v, building* b);
void vector_insert(vector* v, int index, building* b);
void vector_push_front(vector* v, building* b);
void vector_remove(vector* v, int index);
void vector_pop_front(vector* v);
void vector_pop_back(vector* v) ;
void vector_swap(vector* v, int i, int j);
void vector_clear(vector* v) ;
void vector_from_array(vector* v, building* array, int n) ;
building* vector_to_array(vector* v);
#endif