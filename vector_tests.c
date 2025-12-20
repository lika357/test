#include "vector.h"
#include "assert.h"
#include "generation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

building test_building(int n) {
    building b;
    snprintf(b.developer, 20, "developer%d", n);
    snprintf(b.microdistrict, 20, "district%d", n);
    b.type = n % 3;
    b.year = 2000 + n;
    b.elevator = n % 2;
    b.garbage_chute = (n + 1) % 2;
    b.apartments = 50 + n * 10;
    b.floors = 5 + n;
    b.average_apartment_area = 40.0 + n * 0.5;
    return b;
}

void test_vector_init() {
    vector v;
    vector_init(&v);
    
    assert(v.data == NULL);
    assert(vector_size(&v) == 0);
    assert(v.max == 0);
}

void test_vector_push_back() {
    vector v;
    vector_init(&v);
    
    building b1 = test_building(1);
    building b2 = test_building(2);
    
    vector_push_back(&v, &b1);
    assert(vector_size(&v) == 1);
    assert(v.max == 4);
    
    building* first = vector_get(&v, 0);
    assert(first != NULL);
    assert(strcmp(first->developer, "developer1") == 0);
    
    vector_push_back(&v, &b2);
    assert(vector_size(&v) == 2);
    
    vector_clear(&v);
}

void test_vector_push_front() {
    vector v;
    vector_init(&v);
    
    building b1 = test_building(1);
    building b2 = test_building(2);
    
    vector_push_front(&v, &b1);
    assert(vector_size(&v) == 1);
    
    vector_push_front(&v, &b2);
    assert(vector_size(&v) == 2);
    
    building* first = vector_get(&v, 0);
    assert(strcmp(first->developer, "developer2") == 0);
    
    building* second = vector_get(&v, 1);
    assert(strcmp(second->developer, "developer1") == 0);

    vector_clear(&v);
}

void test_vector_insert() {
    vector v;
    vector_init(&v);
    
    building b1 = test_building(1);
    building b2 = test_building(2);
    building b3 = test_building(3);
    
    vector_push_back(&v, &b1);
    vector_push_back(&v, &b3);
    
    vector_insert(&v, 1, &b2);
    assert(vector_size(&v) == 3);
    
    assert(strcmp(vector_get(&v, 0)->developer, "developer1") == 0);
    assert(strcmp(vector_get(&v, 1)->developer, "developer2") == 0);
    assert(strcmp(vector_get(&v, 2)->developer, "developer3") == 0);
    
    vector_clear(&v);
}

void test_vector_remove() {
    vector v;
    vector_init(&v);
    
    building b1 = test_building(1);
    building b2 = test_building(2);
    building b3 = test_building(3);
    
    vector_push_back(&v, &b1);
    vector_push_back(&v, &b2);
    vector_push_back(&v, &b3);
    
    assert(vector_size(&v) == 3);
    
    vector_remove(&v, 1);
    assert(vector_size(&v) == 2);
    assert(strcmp(vector_get(&v, 0)->developer, "developer1") == 0);
    assert(strcmp(vector_get(&v, 1)->developer, "developer3") == 0);
    
    vector_pop_front(&v);
    assert(vector_size(&v) == 1);
    assert(strcmp(vector_get(&v, 0)->developer, "developer3") == 0);
    
    vector_pop_back(&v);
    assert(vector_size(&v) == 0);
    
    vector_clear(&v);
}

void test_vector_clear() {
    vector v;
    vector_init(&v);
    
    for (int i = 0; i < 10; i++) {
        building b = test_building(i);
        vector_push_back(&v, &b);
    }
    
    assert(vector_size(&v) == 10);
    
    vector_clear(&v);
    assert(vector_size(&v) == 0);
    assert(v.data == NULL);
    assert(v.max == 0);
    
}

void test_vector_swap() {
    vector v;
    vector_init(&v);
    
    building b1 = test_building(1);
    building b2 = test_building(2);
    
    vector_push_back(&v, &b1);
    vector_push_back(&v, &b2);
    
    vector_swap(&v, 0, 1);
    
    assert(strcmp(vector_get(&v, 0)->developer, "developer2") == 0);
    assert(strcmp(vector_get(&v, 1)->developer, "developer1") == 0);
    
    vector_clear(&v);
}

void test_vector_begin_end() {
    vector v;
    vector_init(&v);
    
    for (int i = 0; i < 5; i++) {
        building b = test_building(i);
        vector_push_back(&v, &b);
    }

    building* begin = vector_begin(&v);
    building* end = vector_end(&v);
    assert(begin != NULL);
    assert(end != NULL);
    assert(end - begin == 5);
    
    building* first = begin;
    building* second = vector_next(&v, first); 
    assert(second != NULL);
    assert(second == begin + 1);

    vector_clear(&v);
}

void test_vector_array() {
    vector v;
    vector_init(&v);
    
    building array[3];
    for (int i = 0; i < 3; i++) {
        array[i] = test_building(i);
    }
    
    vector_from_array(&v, array, 3);
    assert(vector_size(&v) == 3);
    
    building* new_array = vector_to_array(&v);
    assert(new_array != NULL);

    for (int i = 0; i < 3; i++) {
        assert(strcmp(new_array[i].developer, array[i].developer) == 0);
    }
    
    free(new_array);
    vector_clear(&v);
}

void test_vector_null() {
    vector v;
    vector_init(&v);
    
    assert(vector_get(&v, 0) == NULL);
    assert(vector_get(&v, -1) == NULL);
    assert(vector_get(&v, 10) == NULL);
    
    vector_clear(&v);
}

void test_vector_resize() {
    vector v;
    vector_init(&v);
    
    for (int i = 0; i < 100; i++) {
        building b = test_building(i);
        vector_push_back(&v, &b);
    }
    
    assert(vector_size(&v) == 100);
    assert(v.max >= 100);  
    
    vector_clear(&v);
}

int main() {
    
    test_vector_init();
    test_vector_push_back();
    test_vector_push_front();
    test_vector_insert();
    test_vector_remove();
    test_vector_clear();
    test_vector_swap();
    test_vector_begin_end();
    test_vector_array();
    test_vector_null();
    test_vector_resize();
    printf("успешных проверок: %zu\n", get_true_tests());
    printf("неудачных проверок: %zu\n", get_failed_tests());
    
    return 0;
}