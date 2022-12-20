#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "recipes.c"
#include "fridge.c"
#include "menu.c"

// Global variables (bad practice but works for now)
struct fridge_item *fridge_array;
int fridge_occupied_length;
int fridge_total_length;

int main(void){
    fridge_array = read_fridge_from_file(&fridge_occupied_length, 
                                         &fridge_total_length);
    start_menu();
    return 0;
}

struct fridge_item *get_fridge_array_real(){
    return fridge_array;
}

void set_fridge_array_real(struct fridge_item *array){
    fridge_array = array;
}

int get_fridge_occupied_length(){
    return fridge_occupied_length;
}

void set_fridge_occupied_length(int occupied_length){
    fridge_occupied_length = occupied_length;
}

int get_fridge_total_length(){
    return fridge_total_length;
}

void set_fridge_total_length(int total_length){
    fridge_total_length = total_length;
}

/**/
void recipes_search_with_fridge(struct fridge_item fi[], int occupied_length)
{
    int n_recipes;
    int n_words = occupied_length;
    int n_results = 0;
    struct Recipe *recipes;
    char *words[100];

    printf("\n");

    // read contents from json recipe file
    recipes = get_recipes("recipes.json", &n_recipes);

    for(int i = 0; i < occupied_length; i++){
        words[i] = malloc(sizeof(char) * 30);
        strcpy(words[i], fi[i].name);
    }

    // search for recipes matching entered keywords
    int *results = search_recipes(recipes, n_recipes, words, n_words);


    // print results
    for (int i = 0; i < 20; i++)
    {
        printf("%d. %s\n    - %s\n", i + 1, recipes[results[i]].name, recipes[results[i]].url);
    }
}