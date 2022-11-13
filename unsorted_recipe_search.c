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

typedef struct RECIPE_LIST{


} RECIPE_LIST;


typedef struct MATCHES {

    char recipe_matches[50];

} MATCHES;


void search_recipe_from_fridge (const FOOD_LIST fridge[],
                                const RECIPE_LIST recipe[], 
                                int recipe_list_size, 
                                int number_of_fridge_values, 
                                int number_of_recipe_values){

MATCHES matches;
char found_foods[25];
int NR = number_of_recipe_values;
int NF = number_of_fridge_values;
int r = 0; //recipe index
int f = 0; //fridge index
int m = 0; //matches index
int i; // recipe item index
int status = 0; //number of food values found true
    
       //call to load fridge and recipe content directly from file ??
        
        
        //More generalised algoritm
        while (r <= recipe_list_size){
                
                for (f = 0; f <= NF; f++ ){    
                    i = 0;
                    do {
                        if (fridge[f].name == recipe[r].item[i]){
                            found_food[] = recipe[r].item[i];
                            status++;
                            i++;
                            f++;
                            printf("Matched a food! %s \n", *recipe[r].item[i]); //for testing output

                            //if all fridge content is found or more than 5 values, then recipe is stored in matches and exit loop
                            if (status > 5){
                                matches[m] = recipe[r];
                                m++;
                                exit;
                            }
                        else    
                            i++;
                        }
                    
                    }while (i <= NR);
                
                } 

            recipe[r++]; //iterate to next structure element
            status = 0; //reset status to 0
            f = 0;
        }
    //print result
    printf("This is the list of recipes you can choose from: %s\n", matches) // printing a struct??????

}

// String compare method??? 
// /*Compare name and abbrev components of each element to target */
//     i = 0;
//     while (!found && i < n) {
//         if (strcmp(fridge[i].name, recipe[i]) == 0)
//             found = 1;
//         else
//             ++i;