#include "generation.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
void generation_building(vector* v,int n){
    char* dev[]={"ПИК","ГК Самолет","ГК A101","MR Group","ДОНСТРОЙ","ГК ФСК","Level Group",
        "Группа ЛСР","ГК АБСОЛЮТ","ГК Гранель","Брусника","Seven Suns Development","Фонд реновации",
    "TEKTA GROUP","ГК Главстрой"};
    char* district[]={"9-й квартал Новых Черёмушек","Бусиново","Востряково","Гавриково",
    "Дангауэровка","Загорье","Ленинские горы","Матвеевское","Новоподрезково","Олимпийская деревня",
    "Район Песчаных улиц","Рублёво-Архангельское","Чечёра","Щербинка","Южное Измайлово"};
    srand(time(NULL));
    for(int i=0;i<n;i++){
        building b;
        strcpy(b.developer,dev[rand()%15]);
        strcpy(b.microdistrict,district[rand()%15]);
        b.type = rand() % 3;
        b.year = 1900 + rand() % 125;
        b.elevator = rand() % 2;
        b.garbage_chute = rand() % 2;
        b.apartments = 50 + rand() % 500;
        b.floors = 5 + rand() % 20;
        b.average_apartment_area = 40.0 + (double)rand() / RAND_MAX * 20.0;
        vector_push_back(v, &b);
    }
}