#include "generation.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

building* generation_building(size_t n) {
    char* dev[] = {
        "ПИК", "ГК Самолет", "ГК A101", "MR Group", "ДОНСТРОЙ", 
        "ГК ФСК", "Level Group", "Группа ЛСР", "ГК АБСОЛЮТ", 
        "ГК Гранель", "Брусника", "Seven Suns Development", 
        "Фонд реновации", "TEKTA GROUP", "ГК Главстрой"
    };
    
    char* district[] = {
        "9-й квартал Новых Черёмушек", "Бусиново", "Востряково", 
        "Гавриково", "Дангауэровка", "Загорье", "Ленинские горы", 
        "Матвеевское", "Новоподрезково", "Олимпийская деревня", 
        "Район Песчаных улиц", "Рублёво-Архангельское", "Чечёра", 
        "Щербинка", "Южное Измайлово"
    };
 
    building* b = malloc(n * sizeof(building));
    
    if (!b) {
        return NULL;  
    }
    
    srand(time(NULL));
    
    for (size_t i = 0; i < n; i++) {
        strcpy(b[i].developer, dev[rand() % 15]);
        strcpy(b[i].microdistrict, district[rand() % 15]);
        b[i].type = rand() % 3;
        b[i].year = 1900 + rand() % 125;
        b[i].elevator = rand() % 2;
        b[i].garbage_chute = rand() % 2;
        b[i].apartments = 50 + rand() % 500;
        b[i].floors = 5 + rand() % 20;
        b[i].average_apartment_area = 40.0 + (double)rand() / RAND_MAX * 20.0;
    }
    
    return b; 
}