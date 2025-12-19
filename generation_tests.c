#include "generation.h"

//1 компилируем 1 файл где есть реализация тестируемых функций
//2 собираю в библиотеку
//3 компилирую тест -fprofile-arcs -ftest-coverage
//4 собираю тест линкуя его с библиотекой 2 и ковередж 
//5 

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "vector.h"
#include "assert.h"
#include <stdio.h>

void test_one() {
    
    building* b = generation_building(1);

    assert(b!=NULL);
    assert(b[0].developer[0] != '\0');
    assert(b[0].microdistrict[0] != '\0');
    assert(b[0].type >= 0 && b[0].type <= 2);
    assert(b[0].year >= 1900 && b[0].year <= 2025);
    assert(b[0].elevator==0 || b[0].elevator==1);
    assert(b[0].garbage_chute==0 || b[0].garbage_chute==1);
    assert(b[0].apartments>=50 && b[0].apartments<=550);
    assert(b[0].floors>=5 && b[0].floors<=25);
    assert(b[0].average_apartment_area>39 && b[0].average_apartment_area<61);
    
    free(b);
}
void test_many() {
    
    building* buildings = generation_building(5);
    
    assert(buildings!=NULL);
        size_t n = 0;
    for (size_t i = 0; i < 5; i++) {
        for (size_t j = i+1; j < 5; j++) {
            if (buildings[i].developer != buildings[j].developer||
                buildings[i].microdistrict != buildings[j].microdistrict ||
                buildings[i].type != buildings[j].type  ||
                buildings[i].year != buildings[j].year||
                buildings[i].elevator != buildings[j].elevator ||
                buildings[i].garbage_chute != buildings[j].garbage_chute ||
                buildings[i].apartments != buildings[j].apartments||
                buildings[i].floors != buildings[j].floors ||
                buildings[i].average_apartment_area != buildings[j].average_apartment_area)
                {
                n++;
            }
        }
    }
    
    assert(n > 0);
    
    free(buildings);
}

void test_zero() {
    
    building* buildings = generation_building(0);
    
    assert(buildings != NULL);
}


int main() {
    
    test_one();
    test_many();
    test_zero();
    printf("успешных проверок: %zu\n", get_true_tests());
    printf("неудачных проверок: %zu\n", get_failed_tests());
    
    return 0;
}