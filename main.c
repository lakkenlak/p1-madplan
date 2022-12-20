#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "recipes.c"
#include "fridge.c"
#include "menu.c"

int main(void){
    struct fridge_item *fridge_array;
    int fridge_occupied_length;
    int fridge_total_length;
    fridge_array = read_fridge_from_file(&fridge_occupied_length, 
                                         &fridge_total_length);
    start_menu(fridge_array, fridge_occupied_length, fridge_total_length);
    free(fridge_array);
    return 0;
}