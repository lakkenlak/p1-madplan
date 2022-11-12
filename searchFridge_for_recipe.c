//Search recipe from fridge
// take in array of strings frim fridge list
// first element (name of item) iterates and compares to first element of recipe list (name of recipe item)
// if first element is found, then compare second element if fridge elements to that specific recipe
// if all elements match then recipe is returned to an array of recipes, maybe called print_matched_recipes
//return print_matched_recipes

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Food.c>

void main(void){

    FOOD *food; //struct array?
    char recipe_matches[];
    char recipe_list[N];
    int N;

    search_recipe_from_fridge(recipe_matches, *food, recipe_list, N,  );

}

// LinSearch to modify
void search_recipe_from_fridge (char recipe_matches[], FOOD *food, char recipe_list[], int lengt_of_recipe_list  ){
  
  int f = 0;
  int r = 0;
  char fridge_item_name = (*food.name);
  char recipe_item_name = recipe_list[r];
  char recipe_matches[]; //output array
  char recipe_name;



    while (r != lengt_of_recipe_list) {
        r++;
        f++;
        // firs compare first element, then compare second, compare third etc...
        // find out how to access structs elements individually

        if (fridge_item_name[f] == recipe_item_name[r]){
            char f = f;
            char r = r;
            int i = 1
            recipe_name = recipe_list[r-1];

            while (fridge_item_name[f + i] == recipe_item_name[r + i]){
                i++;

            }
            
        }

        //return recipe_matches array[]
        
    }

}