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

int search_recipe_from_fridge (const FOOD_LIST fridge[],
                                const RECIPE_LIST recipe[], 
                                int recipe_list_size, 
                                int number_of_fridge_values, 
                                int number_of_recipe_values);

int main(void){

    
    int N;

    search_recipe_from_fridge(FOOD_LIST, RECIPE_LIST, N, NF, NR);

}

// LinSearch to modify
int search_recipe_from_fridge (const FOOD_LIST fridge[],
                                const RECIPE_LIST recipe[], 
                                int recipe_list_size, 
                                int number_of_fridge_values, 
                                int number_of_recipe_values){
  
    char matches[100];
    int NR = number_of_recipe_values;
    int NF = number_of_fridge_values;
    int r = 0; //recipe index
    int f = 0; //fridge index
    int m = 0; //matches index
    int i = 0;
    int found = 1;
    int status = 0; //number of food values found true
        
        // compare values of fridge struct and recipe struct      
        while (r <= recipe_list_size){
            //find first match before comparing whole recipe
            if (fridge[f].name == recipe[r].item[i]){    
                //compare all fridge elements to all recipe values, linear search, has to be sorted
                for (f = 0; f <= NF || i <= NR;){
                    if (fridge[f].name == recipe[r].item[i]){
                        status++;
                        i++;
                        f++;
                        //if all fridge content is found then recipe is stored in matches
                        if (status == NF){
                            matches[m] = recipe[r].name;
                            m++;
                        }
                    else 
                        i++;
                    }  

                    else if(){

                    }
                }
            }

            recipe[r++]; //iterate to next array structure
            status = 0; //reset status to 0
        }
     

    //print result
    printf("This is the list", matches)
    
    return 0
}

// String compare method??? 
// /*Compare name and abbrev components of each element to target */
//     i = 0;
//     while (!found && i < n) {
//         if (strcmp(fridge[i].name, recipe[i]) == 0)
//             found = 1;
//         else
//             ++i;