// make recipe struct 
#include <stdio.h>
#include <string.h>
#include <FRIDGE_LIST.h>

#DEFINE 
        // FOUND THESE READ/COPY STRUCT ARRAY FILE ALGORITM IN IMPR-C BOOK
        // COULD MODIFY TO READ STRUCT

/*
* Opens database file units.txt and gets data to place in units until end
* of file is encountered. Stops input prematurely if there are more than
* unit_max data values in the file or if invalid data is encountered.
*/
void load_units(FRIDGE_LIST fridge[], /* output - array of data */
                int *fridge_element_size) /* output - number of data values stored in elements */
                {

    FILE * inp;
    FRIDGE_LIST data;
    int i, status;

    /* Gets database of units from file */
    inp = fopen("fridge.list", "r");
    i = 0;

        for (status = fscan_unit(inp, &data); 
             status == 1; 
             status = fscan_unit(inp, &data)) {
                
            units[i++] = data;
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
/*
 * Gets data from a file to fill output argument
 * Returns standard error code: 1 => successful input, 0 => error,
 * negative EOF value => end of file
 */

int fscan_unit (FILE *filep, /* input - input file pointer */
                FRIDGE_LIST *unitp) /* output - unit_t structure to fill */
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