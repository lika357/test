#include "sort.h"
#include "vector.h"
#include "comparison.h"
#include "assert.h"
#include <stdio.h>
#include <string.h>

building create_test_building(const char* dev, const char* dist, int type, 
                            int year, int elevator, int chute, 
                            int apt, int floors, double area) {
    building b;
    strncpy(b.developer, dev, 99);
    strncpy(b.microdistrict, dist, 99);
    b.type = type;
    b.year = year;
    b.elevator = elevator;
    b.garbage_chute = chute;
    b.apartments = apt;
    b.floors = floors;
    b.average_apartment_area = area;
    return b;
}

int is_sorted(vector* v, comparator_func cmp) {
    for (int i = 0; i < vector_size(v) - 1; i++) {
        building* a = vector_get(v, i);
        building* b = vector_get(v, i + 1);
        if (cmp(a, b) > 0) {
            return 0; 
        }
    }
    return 1; 
}
void test_sort_one() {
    vector v;
    vector_init(&v);
    
    building b1 = create_test_building("Company", "Center", 1, 2000, 1, 1, 100, 10, 50.0);
    vector_push_back(&v, &b1);

    bubble_sort(&v, compare_buildings_inc);
    
    assert(vector_size(&v) == 1);
    assert(is_sorted(&v, compare_buildings_inc) == 1);

    vector_clear(&v);
}

void test_sort_two_sorted() {
    vector v;
    vector_init(&v);
    
    building b1 = create_test_building("AAA", "Center", 1, 2000, 1, 1, 100, 10, 50.0);
    building b2 = create_test_building("BBB", "Center", 1, 2000, 1, 1, 100, 10, 50.0);
    
    vector_push_back(&v, &b1);
    vector_push_back(&v, &b2); 
    
    bubble_sort(&v, compare_buildings_inc);
    
    assert(vector_size(&v) == 2);
    assert(is_sorted(&v, compare_buildings_inc) == 1);
    
    assert(strcmp(vector_get(&v, 0)->developer, "AAA") == 0);
    assert(strcmp(vector_get(&v, 1)->developer, "BBB") == 0);

    vector_clear(&v);
}

void test_sort_two_reverse() {
    vector v;
    vector_init(&v);
    
    building b1 = create_test_building("BBB", "Center", 1, 2000, 1, 1, 100, 10, 50.0);
    building b2 = create_test_building("AAA", "Center", 1, 2000, 1, 1, 100, 10, 50.0);
    
    vector_push_back(&v, &b1); 
    vector_push_back(&v, &b2); 
    
    bubble_sort(&v, compare_buildings_inc);
    
    assert(vector_size(&v) == 2);
    assert(is_sorted(&v, compare_buildings_inc) == 1);
    
    assert(strcmp(vector_get(&v, 0)->developer, "AAA") == 0);
    assert(strcmp(vector_get(&v, 1)->developer, "BBB") == 0);
    
    vector_clear(&v);
}

void test_sort_many() {
    vector v;
    vector_init(&v);
    
    building b1 = create_test_building("CCC", "Center", 1, 2000, 1, 1, 100, 10, 50.0);
    building b2 = create_test_building("AAA", "Center", 1, 2000, 1, 1, 100, 10, 50.0);
    building b3 = create_test_building("BBB", "Center", 1, 2000, 1, 1, 100, 10, 50.0);
    building b4 = create_test_building("DDD", "Center", 1, 2000, 1, 1, 100, 10, 50.0);
    
    vector_push_back(&v, &b3); 
    vector_push_back(&v, &b1);
    vector_push_back(&v, &b4);
    vector_push_back(&v, &b2); 
    
    bubble_sort(&v, compare_buildings_inc);
    
    assert(vector_size(&v) == 4);
    assert(is_sorted(&v, compare_buildings_inc) == 1);
    
    assert(strcmp(vector_get(&v, 0)->developer, "AAA") == 0);
    assert(strcmp(vector_get(&v, 1)->developer, "BBB") == 0);
    assert(strcmp(vector_get(&v, 2)->developer, "CCC") == 0);
    assert(strcmp(vector_get(&v, 3)->developer, "DDD") == 0);
    
    vector_clear(&v);
}

void test_sort_dec() {
    vector v;
    vector_init(&v);
    
    building b1 = create_test_building("AAA", "Center", 1, 2000, 1, 1, 100, 10, 50.0);
    building b2 = create_test_building("BBB", "Center", 1, 2000, 1, 1, 100, 10, 50.0);
    building b3 = create_test_building("CCC", "Center", 1, 2000, 1, 1, 100, 10, 50.0);
    
    vector_push_back(&v, &b1); 
    vector_push_back(&v, &b2); 
    vector_push_back(&v, &b3); 
    
    bubble_sort(&v, compare_buildings_dec);
    
    assert(vector_size(&v) == 3);
    assert(is_sorted(&v, compare_buildings_dec) == 1);
    
    assert(strcmp(vector_get(&v, 0)->developer, "CCC") == 0);
    assert(strcmp(vector_get(&v, 1)->developer, "BBB") == 0);
    assert(strcmp(vector_get(&v, 2)->developer, "AAA") == 0);
    
    vector_clear(&v);
}

void test_diff_year() {
    vector v;
    vector_init(&v);
    
    building b1 = create_test_building("Same", "Center", 1, 2010, 1, 1, 100, 10, 50.0);
    building b2 = create_test_building("Same", "Center", 1, 2000, 1, 1, 100, 10, 50.0);
    building b3 = create_test_building("Same", "Center", 1, 2020, 1, 1, 100, 10, 50.0);
    
    vector_push_back(&v, &b3); 
    vector_push_back(&v, &b1);
    vector_push_back(&v, &b2); 
    
    bubble_sort(&v, compare_buildings_inc);
    
    assert(vector_size(&v) == 3);
    assert(is_sorted(&v, compare_buildings_inc) == 1);
    
    assert(vector_get(&v, 0)->year == 2000);
    assert(vector_get(&v, 1)->year == 2010);
    assert(vector_get(&v, 2)->year == 2020);
    
    vector_clear(&v);
}



int main() {
    
    test_sort_one();
    test_sort_two_sorted();
    test_sort_two_reverse();
    test_sort_many();
    test_sort_dec();
    test_diff_year();
    printf("успешных проверок: %zu\n", get_true_tests());
    printf("неудачных проверок: %zu\n", get_failed_tests());
    
    return 0;
}