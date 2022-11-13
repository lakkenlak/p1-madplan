
// copy a file list to an array
// NEEDS modification

#define "filename" // list filename

void copy_fridge_content (){
    char filename[20];
    FILE *myFile;
    int array[N];
    int k;

    myFile = fopen(filename); // input fridgelist name 

    /* indlæs fil ind i array */
    for (k = 0; k < N; k++){
        fscanf(myFile, "%s", &array[k]); // scan in fridge content
    }
    fclose(myFile);


}
        // FOUND THESE READ/COPY STRUCT ARRAY FILE ALGORITM IN IMPR-C BOOK
        // COULD MODIFY TO READ STRUCT
/*
 * Gets data from a file to fill output argument
 * Returns standard error code: 1 => successful input, 0 => error,
 * negative EOF value => end of file
 */

int fscan_unit (FILE *filep, /* input - input file pointer */
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
/*
* Opens database file units.txt and gets data to place in units until end
* of file is encountered. Stops input prematurely if there are more than
* unit_max data values in the file or if invalid data is encountered.
*/
void load_units(int unit_max, /* input - declared size of units */
                unit_t units[], /* output - array of data */
                int *unit_sizep) /* output - number of data values
stored in units */
                {

    FILE * inp;
    unit_t data;
    int i, status;

    /* Gets database of units from file */
    inp = fopen("units.txt", "r");
    i = 0;

        for (status = fscan_unit(inp, &data); 
             status == 1 && i < unit_max; 
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