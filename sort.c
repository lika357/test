#include "sort.h"

int compare_year_asc(const building* a, const building* b) {
    return a->year - b->year;
}

int compare_year_desc(const building* a, const building* b) {
    return b->year - a->year;
}

void bubble_sort(vector* v, comparator_func cmp) {
    int n = vector_size(v);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            building* a = vector_get(v, j);
            building* b = vector_get(v, j + 1);
            if (cmp(a, b) > 0) {
                vector_swap(v, j, j + 1);
            }
        }
    }
}