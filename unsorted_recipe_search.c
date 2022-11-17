/*
 *   Search recipe from fridge
 *   take in array of strings frim fridge list
 *   first element (name of item) iterates and compares to first element of recipe list (name of recipe item)
 *   if first element is found, then compare second element if fridge elements to that specific recipe
 *   if all elements match then recipe is returned to an array of recipes, maybe called print_matched_recipes
 *   return print_matched_recipes
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <erer.c>

#define MAX_FOODS 25 // maximum number of foods
#define MAX_RECIPES 20000 // max number of recipes
#define MAX_RECIPE_ITEMS 30 // max number of recipe items in structs
#define NAME_LEN 30

/****PROTOTYPE declarations*****/
int search_recipe_from_fridge (struct fridge* fridge[], struct recipe recipes[], int recipe_list_size, int fridge_list_size);


/*******MAIN*******/

  int main (){
        
        
        search_recipe_from_fridge(fridge, recipe, recipe_list_size, fridge_list_size);
 
  }



int search_recipe_from_fridge (struct fridge_item_t* fridge[],
                                struct recipe* recipes[], 
                                int recipe_list_size, 
                                int fridge_list_size){

struct recipe matches[MAX_RECIPES];
int m = 0; //matches index
int status = 0; //number of food values found true
int r, f;      
        //More generalised algoritm
        while ( r <= recipe_list_size){  
            for (f = 0; f <= fridge_list_size; f++ ){    
                int i = 0;//reset iteration variable
                do {
                    if (fridge[f]->name == *recipes[r]->ingredients[i]->name){ // maybe instead strcmp 
                        status++;
                        i++;
                        f++;
                    }    
                    else {   
                        i++;
                    }
                    //if all fridge content is found or more than 5 values, then recipe is stored in matches and exit loop
                    if (status > 5){
                        matches[m++] = *recipes[r];
                        break;
                    }
                
                }while (i <= sizeof(recipes[r]->ingredients) ); //number of recipe items
            
            } 

            recipes[r++]; //iterate to next structure element
            status = 0; //reset status to 0
        }
    //print result
    for (int i = 0 ; i <= len(matches) ; i++){
        printf("This is is the list of recipes you can choose from:\n%s\n%s\n", matches[i]->name, matches[i]->url );
    }

    return 0;
}

// String compare method??? 
/*Compare name and abbrev components of each element to target 
 *      if (strcmp(fridge[f]->name, *recipes[r]->ingredients[i]->name == 0)
*/         