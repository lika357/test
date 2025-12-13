#ifndef SORT_H
#define SORT_H

#include "vector.h"

typedef int (*comparator_func)(const building*, const building*);
int compare_year_asc(const building* a, const building* b);
int compare_year_desc(const building* a, const building* b);
void bubble_sort(vector* v, comparator_func cmp);

#endif