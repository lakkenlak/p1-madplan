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

    print_main_menu();

    return 0;
}

/*
*   Returns a Food array that contains the contents of fridge.txt as Food structs
*/
Food* read_fridge_from_file(){
    int i = 0, j = 0, count = 1;
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
        char saved_values[5][150] = {"", "", "", "", ""};
        //printf("%s \n", line); temp line for test

        raw_values = strtok(line, ",");
        strcat(saved_values[0], raw_values);
        
        raw_values = strtok(NULL, ",");
        strcat(saved_values[1], raw_values);
        
        raw_values = strtok(NULL, ",");
        strcat(saved_values[2], raw_values);
        
        raw_values = strtok(NULL, ",");
        strcat(saved_values[3], raw_values);
        
        raw_values = strtok(NULL, ",");
        strcat(saved_values[4], raw_values);
        
        food_array[i] = food_constructor(saved_values[0], saved_values[1], strtod(saved_values[2], NULL), atoi(saved_values[3]), atoi(saved_values[4]));
        i++;
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