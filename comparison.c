#include "comparison.h"
#include <string.h>

int compare_buildings_inc(const building* a, const building* b) {
    int result;
    
    result = strcmp(a->developer, b->developer);
    if (result != 0) return result;
    
    result = strcmp(a->microdistrict, b->microdistrict);
    if (result != 0) return result;
    
    result = a->type - b->type;
    if (result != 0) return result;

    result = a->year - b->year;
    if (result != 0) return result;

    result = (int)a->elevator - (int)b->elevator;
    if (result != 0) return result;
    
    result = (int)a->garbage_chute - (int)b->garbage_chute;
    if (result != 0) return result;

    result = a->apartments - b->apartments;
    if (result != 0) return result;
    
    result = a->floors - b->floors;
    if (result != 0) return result;
    
    if (a->average_apartment_area < b->average_apartment_area) return -1;
    if (a->average_apartment_area > b->average_apartment_area) return 1;
    
    return 0; 
}

int compare_buildings_dec(const building* a, const building* b) {
    return compare_buildings_asc(b, a);
}