#pragma once
#include <stdbool.h>
typedef enum {
    panel = 0,     
    brick = 1,     
    monolit = 2 
} building_type;
typedef struct {
    char developer[100];       
    char microdistrict[100];       
    building_type type;     
    int year;              
    bool elevator;      
    bool garbage_chute;  
    int apartments;    
    int floors;         
    double average_apartment_area; 
} building;
