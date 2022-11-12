//Search recipe from fridge
// take in array of strings frim fridge list
// first element (name of item) iterates and compares to first element of recipe list (name of recipe item)
// if first element is found, then compare second element if fridge elements to that specific recipe
// if all elements match then recipe is returned to an array of recipes, maybe called print_matched_recipes
//return print_matched_recipes

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define "filename" // filename has to b

// very cool algoritm to copy a file list to an array
    
void copy_fridge_content (){
    char filename[20];
     *myFile;
    int array[N];
    int k;

    myFile = fopen(filename); // input fridgelist name 

    /* indlæs fil ind i array */
    for (k = 0; k < N; k++){
        fscanf(myFile, "%s", &array[k]); // scan in fridge content
    }
    fclose(myFile);


}


//BinSearch to modify 
void BinSearch(char fridge_list[], char recipe_list[], int lengt_of_recipe_list ){
  
  int m;
  int l = lengt_of_recipe_list;
  int f = 
  char fridge_item_name = fridge_list[];
  char recipe_item_name = recipe_list[];
  
  
    while (i < l){
        
        m = ((i+l)/ 2);
        
        if (x > array [m]){
            i = m + 1;
        }
        else {
            l = m;
        }    
        if (x == array[i]){
            printf("%d er på position %d\n",x,i+1);
        }
        else {
            printf("%d er ikke i listen \n",x);
        }

    }
}

// LinSearch to modify
void LinSearch(char fridge_list[], char recipe_list[], int lengt_of_recipe_list  ){
  
  int f = 0;
  int r = 0;
  char fridge_item_name = fridge_list[i];
  char recipe_item_name = recipe_list[r];
  char recipe_name;
  char recipe_matches[];


    while (r != lengt_of_recipe_list) {
        r++;
        f++;
        // firs compare first element, then compare second, compare third etc...
        // find out how to access structs elements individually

        if (fridge_item_name[f] == recipe_item_name[r]){
            int f = f;
            int r = r;
            int i = 1
            recipe_name = recipe_list[r-1];

        if (fridge_item_name[f + i] == recipe_item_name[r + i])
            
        }

        //return recipe array
        
    }

}
void search_recipe(fridge_item_name[i] == recipe_item_name[r]){
    int i = i;
    int r = r;
    if (fridge_item:name)


}