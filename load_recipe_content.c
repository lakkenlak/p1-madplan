

// the call

load_recipe(MAX_RECIPE, recipe, &recipe_list_size);

void load_recipe(int MAX_recipe,
                recipe_t recipe[], /* output - array of data */
                int *recipe_list_size) /* output - number of data values stored in units */
                {

    FILE * inp;
    recipe_t data;
    int i, status;

    /* Gets database of units from file */
    inp = fopen("recipe.txt", "r");
    i = 0;

        for (status = fscan_recipe(inp, &data); 
             status == 1 && i < MAX_recipe; 
             status = fscan_recipe(inp, &data)) {
                
            recipe[i++] = data;
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

