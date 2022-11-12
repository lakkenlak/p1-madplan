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

    FOOD_LIST fridge_food_list; //struct array?
    RECIPE_LIST recipe;
    int N;

    search_recipe_from_fridge(fridge_food_list, recipe_list, N );

}

// LinSearch to modify
void search_recipe_from_fridge (FOOD_LIST fridge_food_list, RECIPE_LIST recipe, int lengt_of_recipe_list  ){
  
  int f = 0;
  int r = 0;
//   char fridge_item_name[] = food.name;
//   char recipe_item_name[] = recipe.name;
  char recipe_matches[]; //output array to print

    while (r != lengt_of_recipe_list) {
        r++;
        // find out how to access structs elements individually
        // how to iterate through structs?
        if (fridge_food_list.name == recipe.item1){
            
            while (fridge_food_list.name == recipe.item1){
                recipe++;

            recipe_matches[] = recipe.name;
            }
            
        }

        //print recipe_matches array[]
        
    }

    return main
}