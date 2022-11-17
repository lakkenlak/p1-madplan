#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.c"
#include "Food.c"

//define recipe struct

//define fridge item struct

Food *read_fridge_from_file();

int main(void) {

    //read recipe file
    //read fridge file
    //read user config file
    read_fridge_from_file();
    print_main_menu();

    return 0;
}

/*
*   Returns a Food array that contains the contents of fridge.txt as Food structs
*/
Food* read_fridge_from_file(){
    int i = 0, j = 0, count = 0;
    char line[150];
    char *raw_values;
    Food *food_array;
    Food new;
    FILE * fridge_content_txt;
    fridge_content_txt = fopen("fridge.txt", "r");
    if(fridge_content_txt == NULL){
        fridge_content_txt = fopen("fridge.txt", "a+");
    }
    while(fgets(line, 150, fridge_content_txt) != NULL){
        count++;
    }
    rewind(fridge_content_txt);
    food_array = (Food *) malloc(sizeof(Food) * (count+50));

    while(fgets(line, 150, fridge_content_txt) != NULL){
        char saved_values[3][150] = {"", "", ""};
        //printf("%s \n", line); temp line for test

        raw_values = strtok(line, ",");
        strcat(saved_values[0], raw_values);
        
        raw_values = strtok(NULL, ",");
        strcat(saved_values[1], raw_values);
        
        raw_values = strtok(NULL, ",");
        strcat(saved_values[2], raw_values);

        food_array[i] = food_constructor(saved_values[0], strtod(saved_values[1], NULL), atoi(saved_values[2]));
        i++;
    }

    printf("TEMPORARY PRINT FOR TESTING read_fridge_from_file() :::: \n");
    for(int p = 0; p<count; p++){
        printf("[%d] : name : %s\n", p, (food_array[p].name));
        printf("[%d] : CO2_emission: %lf\n", p, food_array[p].CO2_emission);
        printf("[%d] : isVegetarian: %d\n", p, food_array[p].isVegetarian);
    }
    return food_array;
}   

/*
read_fridge_from_file(){}
read_recipes_from_file(){}
read_user_config_from_file(){}

interperet_user_input(){
    //read user input
    //decide what action to take
}

print_fridge_content(){
    //format input array to string
    //output string
}
add_fridge_content(){}
remove_fridge_content(){}

get_recipe_from_list(){}
search_for_recipe(){}
 */