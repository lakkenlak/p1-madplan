#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct fridge_item{
  char name[30];
};

struct fridge_item *read_fridge_from_file(int *occupied_length, int *total_length);
void overwrite_fridge(struct fridge_item f_items[], int length);
void write_fridge_items_to_fridge(struct fridge_item f_items[], int length);
void write_fridge_item_to_fridge(struct fridge_item fi);
void print_fridge_items(struct fridge_item fi[], int occupied_length);

void print_fridge_items(struct fridge_item fi[], int occupied_length){
    printf("\n:::::::: DISPLAYING FRIDGE ::::::::\n");
    printf("Total amount of items registered: %d\n", occupied_length);
    for(int i = 0; i<occupied_length; i++){
        printf("%d - %s\n", i, fi[i].name);
    }
    printf(":::::::::::::::::::::::::::::::::::\n\n");
}

void write_fridge_item_to_fridge(struct fridge_item fi){
    FILE *fridge_txt = fopen("fridge.txt", "a");
    if(fridge_txt == NULL){
        printf("Error opening fridge.txt");
        return;
    }
    fprintf(fridge_txt, "\n%s", fi.name);
    fclose(fridge_txt);
}

void write_fridge_items_to_fridge(struct fridge_item f_items[], int length){
    FILE *fridge_txt = fopen("fridge.txt", "a");
    if(fridge_txt == NULL){
        printf("Error opening fridge.txt");
        return;
    }
    for(int i = 0; i<length; i++){
        fprintf(fridge_txt, "\n%s", f_items[i].name);
    }
    fclose(fridge_txt);
}

/*
*   Overwrites the contents of fridge.txt with the contents of the given fridge_item array
*/
void overwrite_fridge(struct fridge_item f_items[], int length){
    FILE *fridge_txt = fopen("fridge.txt", "w");
    if(fridge_txt == NULL){
        printf("Error opening fridge.txt");
        return;
    }
    for(int i = 0; i<length; i++){
        fprintf(fridge_txt, "\n%s", f_items[i].name);
    }
    fclose(fridge_txt);
}

/*
*   Returns a fridge_item array that contains the contents of fridge.txt as fridge_item structs
*   Also returns an output parameter with the number of occupied spaces in the array,
*   and an output parameter with the total length of the array.
*/
struct fridge_item *read_fridge_from_file(int *occupied_length, int *total_length){
    int count = 0;
    char line[29];
    struct fridge_item *fridge_item_array;
    struct fridge_item new;
    FILE * fridge_txt;

    fridge_txt = fopen("fridge.txt", "r");
    if(fridge_txt == NULL){
        printf("Error opening fridge.txt");
        return NULL;
    }

    while(fgets(line, 29, fridge_txt) != NULL){
        count++;
    }
    rewind(fridge_txt);

    fridge_item_array = (struct fridge_item *) calloc((count+50), sizeof(struct fridge_item));
    if(fridge_item_array == NULL){
        printf("Could not create array of fridge items, something went wrong...");
        return NULL;
    }
    
    int success = 0;
    int items = 0;

    do{
        success = fscanf(fridge_txt, " %29[^\n]", fridge_item_array[items].name);

        if(success == 1){
            items++;
        }
        if(!feof(fridge_txt) && success != 1){
            printf("File format incorrect \n");
            return NULL;
        }

        if(ferror(fridge_txt)){
            printf("Error reading fridge.txt \n");
            return NULL;
        }
    }
    while(!feof(fridge_txt));
    fclose(fridge_txt);

    *occupied_length = items;
    *total_length = count + 50;
    return fridge_item_array;
}  

/*
*   Creates a new fridge_item array given an int array deletions[],
*   which must contain elements representing the indices of the items
*   in the fridge_item array that are desired to be removed.
*   Returns a new fridge_item array with the remaining fridge_items not deleted,
*   as well as the new occupied length & total length of the new fridge_item array
*   as output parameters.
*/
struct fridge_item *remove_items_from_fridge(struct fridge_item fridge[], 
                                            int fridge_occupied_length, 
                                            int deletions[], 
                                            int deletions_length, 
                                            int *new_fridge_occupied_length, 
                                            int *new_fridge_total_length){
    
    int new_total_length = (fridge_occupied_length - deletions_length) + 50;
    *new_fridge_total_length = new_total_length;
    
    struct fridge_item *new_fridge = (struct fridge_item *) calloc((new_total_length), 
    sizeof(struct fridge_item));
    
    int is_marked_for_deletion = 0;
    int i, j, z = 0;

    for(i = 0; i<fridge_occupied_length; i++){
        for(j = 0; j<deletions_length; j++){
            if(i == deletions[j]){
                is_marked_for_deletion = 1;
            }
        }

        if(!is_marked_for_deletion){
            new_fridge[z] = fridge[i];
            z++;
        }
        is_marked_for_deletion = 0;
    }

    *new_fridge_occupied_length = z;

    overwrite_fridge(new_fridge, z);
    return new_fridge;
}

void recipes_search_with_fridge(struct fridge_item fi[], int occupied_length){
    int n_recipes;
    int n_words = occupied_length;
    int n_results = 0;
    struct Recipe *recipes;
    char *words[100];

    printf("\n");

    // read contents from json recipe file
    recipes = get_recipes("recipes.json", &n_recipes);

    for(int i = 0; i < occupied_length; i++){
        words[i] = malloc(sizeof(char) * 30);
        strcpy(words[i], fi[i].name);
    }

    // search for recipes matching entered keywords
    int *results = search_recipes(recipes, n_recipes, words, n_words);

    // print results
    for (int i = 0; i < 20; i++)
    {
        printf("%d. %s\n    - %s\n", i + 1, recipes[results[i]].name, recipes[results[i]].url);
    }
}