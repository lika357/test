#include "generation.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "vector.h"
include "generation_test.h"
#define assert(condition) assert_((condition), #condition, __FILE__, __LINE__)
void test_building(building* b){
    assert(b!=0);
    assert(b->developer!='\0');
    assert(b->microdistrict!='\0');
    assert(b->type<=2 && b->type>=0);
    assert(b->year>=1900 && b->year<=2025);
    assert(b->elevator==0 && b->elevator==1);
    assert(b->garbage_chute==0 && b->garbage_chute==1);
    assert(b->apartments>=50 && b->apartments<=550);
    assert(b->floors>=5 && b->floors<=25);
    assert(b->average_apartment_area>39 && b->average_apartment_area<61);
}
//1 компилируем 1 файл где есть реализация тестируемых функций
//2 собираю в библиотеку
//3 компилирую тест -fprofile-arcs -ftest-coverage
//4 собираю тест линкуя его с библиотекой 2 и ковередж 
//5 
