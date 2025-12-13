#include "comparison.h"

int compare_year_asc(const building* a, const building* b) {
    return a->year - b->year;
}
 
int compare_year_desc(const building* a, const building* b) {
    return b->year - a->year;
}