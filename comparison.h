#pragma once

#include "building.h"

typedef int (*comparator_func)(const building*, const building*);

int compare_buildings_inc(const building* a, const building* b);
int compare_buildings_dec(const building* a, const building* b);
