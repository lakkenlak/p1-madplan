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

void search_recipe_from_fridge (const FOOD_LIST fridge[],
                                const RECIPE_LIST recipe[], 
                                int recipe_list_size, 
                                int number_of_fridge_values, 
                                int number_of_recipe_values);

void main(void){

    
    int N;

    search_recipe_from_fridge(FOOD_LIST, RECIPE_LIST, N, NF, NR);

}

// LinSearch to modify
void search_recipe_from_fridge (const FOOD_LIST fridge[],
                                const RECIPE_LIST recipe[], 
                                int recipe_list_size, 
                                int number_of_fridge_values, 
                                int number_of_recipe_values){
  
    char matches[100];
    char match;
    int NR = number_of_recipe_values;
    int NF = number_of_fridge_values;
    int r = 0; //recipe index
    int f = 0; //fridge index
    int found = 1;
    int status = 0; // status on number of values found true
        
        // compare components of fridge structure and recipe structure       
        while (!found && r <= recipe_list_size){
 
            if (fridge[f].name == recipe[r].item){
                status = 1;
                match = recipe[r].name;

                    while (f != NF){
                        if (fridge[f++].name == recipe[r].item[++] ){
                        status++;
                        f++;

                        else 
                            status = 0;
                        }

                        if (status == NF){
                            matches[] = match;
                        }
                    }
            }

           
        }
             // recipe[r++]; //iterate to next structure

            //print recipe_matches array[]
            printf("This is the list", matches)
    return main;
}

// String compare method??? 
// /*Compare name and abbrev components of each element to target */
//     i = 0;
//     while (!found && i < n) {
//         if (strcmp(fridge[i].name, recipe[i]) == 0)
//             found = 1;
//         else
//             ++i;