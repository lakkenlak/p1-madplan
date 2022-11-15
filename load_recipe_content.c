#include <stdio.h>
#include <stdlib.h>


typedef struct recipe_ingredient_t{
        char *name;
        double amount;

} recipe_ingredient_t;

typedef struct recipe_t { 
    char *name;
    struct recipe_ingredient_t *item; //ingredients struct array nested
    char *instructions;
} recipe_t;



// the call
// load_recipe(MAX_RECIPE, recipe, &recipe_list_size);

void load_recipe(int MAX_recipe,
                recipe_t recipe[], /* output - array of data */
                int *recipe_list_size) /* output - number of data values stored in units */
                {

    FILE *inp;
    recipe_t recipe_data; 
    int i, status, status_items;

    /* Gets database of recipes from file */
    inp = fopen("recipe.txt", "r");
    i = 0;

        if (inp == NULL){
            printf("could not load file\n");
            return;
        }
            for (status = fscan_recipe(inp, &recipe_data, &status_items); 
                status == 1 && i < MAX_recipe; 
                status = fscan_recipe(inp, &recipe_data, &status_items)) {
                    
                recipe[i++] = recipe_data;
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
    *recipe_list_size = i;
}
int fscan_recipe(FILE *filep, /* input - input file pointer */
                recipe_t *recipe_data) /* output - structure to fill */
                int *status_items; // trying to output number of items in recipe element????? 
                {
    int status, items;

    status = fscanf(filep,"%s%s",recipe_data->name, 
                                 recipe_data->item
                                    // maybe a way to scan variable ingredient list??                                
                                    for (int i = 0; recipe_data->item[i]; i++)
                                    { 
                                        items += fscanf(filep, "%s",recipe_data->item[i]);
                                        printf("scanned this item &s\n",recipe_data->item[i]);
                                         
                                    },
                                 recipe_data->instructions);
        *status_items = items;

        if (status == 3)
            status = 1;
        else if (status != EOF)
            status = 0;

    return (status);
}

