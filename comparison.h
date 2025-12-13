#ifndef COMPARASION_H
#define COMPARASION_H

#include "building.h"

typedef int (*comparator_func)(const building*, const building*);

int compare_year_asc(const building* a, const building* b);
int compare_year_desc(const building* a, const building* b);

#endif