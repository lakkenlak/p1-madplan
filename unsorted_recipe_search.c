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

#define MAX_FOODS 25 // maximum number of food items
#define MAX_RECIPES 20000


typedef struct fridge_item {
    char name[50];
    char unit[10];
    double CO2_emission;
    unsigned int isVegetarian;
    unsigned int expiration_date;
} fridge_item_t;

typedef struct recipe{ 
    char name[30];
    char item2[30];
    char item3[30];
    char item4[30];
} recipe_t;


void load_fridge(int MAX_FOODS, fridge_item_t fridge[], int *unit_sizep);
void load_recipe(int MAX_RECIPE, recipe_t recipe[], &fridge_list_size, &recipe_list_size);
void search_recipe_from_fridge (fridge_item_t fridge[], recipe_t recipe[], int recipe_list_size,int fridge_list_size);


// MAIN 

void main (void){

    fridge_item_t fridge[MAX_FOODS];
    recipe_t recipe[MAX_RECIPES];
    int recipe_list_size,
        fridge_list_size;

    load_fridge(MAX_FOODS, fridge, &fridge_list_size);
    load_recipe(MAX_RECIPE, recipe, &recipe_list_size);

    search_recipe_from_fridge( fridge, recipe, recipe_list_size, fridge_list_size);
}


void search_recipe_from_fridge (fridge_item_t fridge[],
                                    recipe_t recipe[], 
                                    int recipe_list_size, 
                                    int fridge_list_size){

recipe_t matches[50];
char found_foods[MAX_FOODS];
int m = 0; //matches index
int status = 0; //number of food values found true
       
        //More generalised algoritm
        while (int r <= recipe_list_size){
                
                for (int f = 0; f <= fridge_list_size; f++ ){    
                    i = 0;//reset iteration variable
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
                            matches[m] = recipe[r];
                            m++;
                            break;
                        }
                    
                    }while (i <= /*recipe element members)*/);
                
                } 

            recipe[r++]; //iterate to next structure element
            status = 0; //reset status to 0
            f = 0; // reset fridge list for new recipe search
        }
    //print result
    printf("From the matched food: %s\n
            This is is the list of recipes you can choose from: %s\n", found_foods, matches) // printing structs??????

}

/*
* Opens database file and gets data to place in units until end
* of file is encountered. 
*/
void load_fridge(int MAX_FOODS,
                fridge_item_t fridge[], /* output - array of data */
                int *unit_sizep) /* output - number of data values stored in units */
                {

    FILE * inp;
    fridge_item_t data;
    int i, status;

    /* Gets database of units from file */
    inp = fopen("fridge.txt", "r");
    i = 0;

        for (status = fscan_fridge(inp, &data); 
             status == 1 && i < unit_max; 
             status = fscan_fridge(inp, &data)) {
                
            fridge[i++] = data;
        }
        
    fclose(inp);

/* Issue error message on premature exit */
        if (status == 0) {
            printf("\n*** Error in data format ***\n");
            printf("*** Using first %d data values ***\n", i);
        } 
        
        else if (status != EOF) {
            printf("\n*** Error: too much data in file ***\n");
            printf("*** Using first %d data values ***\n", i);
        }

    /* Send back size of used portion of array */
    *unit_sizep = i;
}
int fscan_fridge(FILE *filep, /* input - input file pointer */
                unit_t *unitp) /* output - unit_t structure to fill */
                {
    int status;

    status = fscanf(filep, "%s%s%s%lf", unitp->name,
                                        unitp->abbrev,
                                        unitp->class,
                                        &unitp->standard);

        if (status == 4)
            status = 1;
        else if (status != EOF)
            status = 0;

    return (status);
}