#include <stdio.h>
#include <stdlib.h>

typedef struct fridge_item_t {
    char name[50];
    char unit[10];
    double CO2_emission;
    unsigned int isVegetarian;
    unsigned int expiration_date;
} fridge_item_t;

// the call
load_fridge(MAX_FOODS, fridge, &number_of_fridge_elements);


void load_fridge(int MAX_FOODS,
                fridge_item_t fridge[], /* output - array of data */
                int *fridge_list_size) /* output - number of data values stored in units */
                {

    FILE * inp;
    fridge_item_t fridge_data;
    int i, status;

    /* Gets database of units from file */
    inp = fopen("fridge.txt", "r");
    i = 0;

        if (inp == NULL){
            printf("could not load file\n");
            return;
        }
            for (status = fscan_fridge(inp, &fridge_data); 
                status == 1 && i < MAX_FOODS; 
                status = fscan_fridge(inp, &fridge_data)) {
                    
                fridge[i++] = fridge_data;
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
    *fridge_list_size = i;
}
int fscan_fridge(FILE *filep, /* input - input file pointer */
                fridge_item_t *fridge_data) /* output - structure to fill */
                {
    int status;

    status = fscanf(filep, "%s%s%lf",fridge_data->name,
                                     fridge_data->unit,
                                     fridge_data->CO2-emission,
                                    &fridge_data->standard);

        if (status == 4)
            status = 1;
        else if (status != EOF)
            status = 0;

    return (status);
}