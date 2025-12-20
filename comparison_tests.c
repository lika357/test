#include "comparison.h"
#include "assert.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>

building create_test_building(const char* dev, const char* dist, int type, 
                            int year, int elevator, int chute, 
                            int apt, int floors, double area) {
    building b;
    strncpy(b.developer, dev, 20);
    strncpy(b.microdistrict, dist, 20);
    b.type = type;
    b.year = year;
    b.elevator = elevator;
    b.garbage_chute = chute;
    b.apartments = apt;
    b.floors = floors;
    b.average_apartment_area = area;
    return b;
}

void test_different_developer() {
    building b1 = create_test_building("AAA", "Center", 1, 2000, 1, 1, 100, 10, 50.0);
    building b2 = create_test_building("BBB", "Center", 1, 2000, 1, 1, 100, 10, 50.0);
    
    assert(compare_buildings_inc(&b1, &b2) < 0);
    assert(compare_buildings_dec(&b1, &b2) > 0);
    
}

void test_different_district() {
    building b1 = create_test_building("Same", "AAA", 1, 2000, 1, 1, 100, 10, 50.0);
    building b2 = create_test_building("Same", "BBB", 1, 2000, 1, 1, 100, 10, 50.0);

    assert(compare_buildings_inc(&b1, &b2) < 0);
    assert(compare_buildings_dec(&b1, &b2) > 0);
    
}

void test() {
    building b1 = create_test_building("Same", "Same", 1, 2000, 1, 1, 100, 10, 50.0);
    building b2 = create_test_building("Same", "Same", 1, 2000, 1, 1, 100, 10, 50.0);
    
    assert(compare_buildings_inc(&b1, &b2) == 0);
    assert(compare_buildings_dec(&b1, &b2) == 0);
    
}

void test_different_year() {
    building b1 = create_test_building("Same", "Same", 1, 2000, 1, 1, 100, 10, 50.0);
    building b2 = create_test_building("Same", "Same", 1, 2010, 1, 1, 100, 10, 50.0);
    
    assert(compare_buildings_inc(&b1, &b2) < 0);
    assert(compare_buildings_dec(&b1, &b2) > 0);
    
}

void test_different_elevator() {
    building b1 = create_test_building("Same", "Same", 1, 2000, 0, 1, 100, 10, 50.0);
    building b2 = create_test_building("Same", "Same", 1, 2000, 1, 1, 100, 10, 50.0);
    
    assert(compare_buildings_inc(&b1, &b2) < 0);
    assert(compare_buildings_dec(&b1, &b2) > 0);
    
}

void test_different_apartments() {
    building b1 = create_test_building("Same", "Same", 1, 2000, 1, 1, 50, 10, 50.0);
    building b2 = create_test_building("Same", "Same", 1, 2000, 1, 1, 100, 10, 50.0);
    
    assert(compare_buildings_inc(&b1, &b2) < 0);
    assert(compare_buildings_dec(&b1, &b2) > 0);
    
}

void test_different_floors() {
    building b1 = create_test_building("Same", "Same", 1, 2000, 1, 1, 100, 5, 50.0);
    building b2 = create_test_building("Same", "Same", 1, 2000, 1, 1, 100, 10, 50.0);
    
    assert(compare_buildings_inc(&b1, &b2) < 0);
    assert(compare_buildings_dec(&b1, &b2) > 0);
    
}

void test_different_area() {
    building b1 = create_test_building("Same", "Same", 1, 2000, 1, 1, 100, 10, 40.0);
    building b2 = create_test_building("Same", "Same", 1, 2000, 1, 1, 100, 10, 60.0);

    assert(compare_buildings_inc(&b1, &b2) < 0);
    assert(compare_buildings_dec(&b1, &b2) > 0);
    
}

void test_different_type() {
    building b1 = create_test_building("Same", "Same", 0, 2000, 1, 1, 100, 10, 50.0);
    building b2 = create_test_building("Same", "Same", 2, 2000, 1, 1, 100, 10, 50.0);
    
    assert(compare_buildings_inc(&b1, &b2) < 0);
    assert(compare_buildings_dec(&b1, &b2) > 0);
    
}

void test_order() {
    building b1 = create_test_building("BBB", "Same", 1, 2010, 1, 1, 100, 10, 50.0);
    building b2 = create_test_building("AAA", "Same", 1, 2000, 1, 1, 100, 10, 50.0);

    assert(compare_buildings_inc(&b2, &b1) < 0);
    
}

void test_different_chute() {
    building b1 = create_test_building("Same", "Same", 1, 2000, 1, 0, 100, 10, 50.0);
    building b2 = create_test_building("Same", "Same", 1, 2000, 1, 1, 100, 10, 50.0);
    assert(compare_buildings_inc(&b1, &b2) < 0);
    assert(compare_buildings_dec(&b1, &b2) > 0);
}
    

int main() {
    
    test_different_developer();
    test_different_district();
    test();
    test_different_year();
    test_different_elevator();
    test_different_apartments();
    test_different_floors();
    test_different_area();
    test_different_type();
    test_order();
    test_different_chute();
    printf("успешных проверок: %zu\n", get_true_tests());
    printf("неудачных проверок: %zu\n", get_failed_tests());
    
    return 0;
}