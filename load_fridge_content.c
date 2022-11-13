
// very cool to copy a file list to an array
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