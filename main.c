#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.c"

//define recipe struct

//define fridge item struct

// Global variables (bad practice but works for now)
char *fridge[] = {"Spunk", "Feces", "Coochie soup", "Ass juice"};
int fridge_size = sizeof(fridge) / (sizeof(fridge[0]));

int main(void) {

    //read recipe file
    //read fridge file
    //read user config file

    print_main_menu();

    return 0;
}

char** get_fridge_array(){
    return fridge;
}

int get_fridge_size(){
    return fridge_size;
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