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


//BinSearch to modify 
void BinSearch(int array[], int n, int x, int print){
  int i = 1;
  int j = n;
  int m; 
  /* Fyld ind hvad der mangler her */
  
  while (i < j){
      
      m = ((i+j)/ 2);
      
      if (x > array [m]){
        i = m + 1;
      }
      else {
        j = m;
      }    
      if (x == array[i]){
         printf("%d er på position %d\n",x,i+1);
      }
      else {
         printf("%d er ikke i listen \n",x);
      }

}

// LinSearch to modify
void LinSearch(int array[], int n, int x, int print){
  int i = 1;
  
  while (i <= n && x != array[i]) {
      i++;
  }

  if (print == 1){
    if (x == array[i]){
      printf("%d er på position %d\n",x,i+1);
    }
    else {
      printf("%d er ikke i listen \n",x);
    }
  }
}