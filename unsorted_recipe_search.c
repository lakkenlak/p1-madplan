//Search recipe from fridge
// take in array of strings frim fridge list
// first element (name of item) iterates and compares to first element of recipe list (name of recipe item)
// if first element is found, then compare second element if fridge elements to that specific recipe
// if all elements match then recipe is returned to an array of recipes, maybe called print_matched_recipes
//return print_matched_recipes

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_FOODS 25 // maximum number of foods
#define MAX_RECIPES 20000 // max number of recipes
#define MAX_RECIPE_ITEMS 30 // max number of recipe items in structs
#define NAME_LEN 30

typedef struct fridge_item_t {
    char name[NAME_LEN];
    char unit[10];
    double CO2_emission;
    unsigned int isVegetarian;
    unsigned int expiration_date;
} fridge_item_t;

typedef struct recipe_item_t{
    char name[NAME_LEN];
    char unit[10];
    double amount;
    double CO2_emission;
    unsigned int isVegetarian;
    unsigned int expiration_date;
} recipe_item_t;

typedef struct recipe_t { 
    char name[NAME_LEN];
    struct recipe_item_t *item[MAX_RECIPE_ITEMS]; /* maybe malloc(some size?) - ingredients nested struct array*/
   
} recipe_t;

void load_fridge(int MAX_FOODS, fridge_item_t fridge[], int *fridge_list_size);
void load_recipe(int MAX_RECIPE, recipe_t recipe[], *recipe_list_size);
void search_recipe_from_fridge (fridge_item_t fridge[], recipe_t recipe[], int recipe_list_size,int fridge_list_size);


// MAIN 

void main (void){

    fridge_item_t fridge[MAX_FOODS]; 
    recipe_t* recipe = malloc(sizeof(struct recipe_t) + /*SOME SIZE ???? */);
    int recipe_list_size,                                                                  
        fridge_list_size;

    load_fridge(MAX_FOODS, fridge, &fridge_list_size);
    load_recipe(MAX_RECIPE, recipe, &recipe_list_size);

    search_recipe_from_fridge(fridge, recipe, recipe_list_size, fridge_list_size);
}


void search_recipe_from_fridge (const fridge_item_t* fridge[],
                                const recipe_t* recipe[], 
                                int recipe_list_size, 
                                int fridge_list_size){

recipe_t matches[50];
char found_foods[MAX_FOODS];
int m = 0; //matches index
int status = 0; //number of food values found true
int r;      
        //More generalised algoritm
        while ( r <= recipe_list_size){
                
                for (int f = 0; f <= fridge_list_size; f++ ){    
                    int i = 0;//reset iteration variable
                    do {
                        if (fridge[f]->name == recipe[r]->item[i]){
                            found_foods[status] = recipe[r]->item[i];
                            status++;
                            i++;
                            f++;
                            printf("Matched a food! %s \n", recipe[r]->item[i]); //for testing output

                        else    
                            i++;
                        }

                        //if all fridge content is found or more than 5 values, then recipe is stored in matches and exit loop
                        if (status > 5){
                            matches[m++] = recipe[r];
                            break;
                        }
                    
                    }while (i <= sizeof(recipe[r]->item) ); //number of recipe items
                
                } 

            recipe[r++]; //iterate to next structure element
            status = 0; //reset status to 0
            f = 0; // reset fridge list for new recipe search
        }
    //print result
    printf("From the matched food: %s\n
            This is is the list of recipes you can choose from: %s\n", found_foods, matches) // printing structs??????

}