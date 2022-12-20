#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <json-c/json.h>

#define MAX_KEYWORDS 100

json_object *load_parse_json_data(char *filename);
struct Ingredient *get_ingredients(struct json_object *ingredients_array);
struct Recipe *get_recipes(char *filename, int *length);
void list_recipes(struct Recipe *recipes, int n_recipes);
int *search_recipes(struct Recipe *recipes, int n_recipes, char *keywords[], int n_keywords);

struct Ingredient{
    char *name;
    double amount;
    char *unit;
};

struct Recipe{
    char *name;
    char *url;
    struct Ingredient *ingredients;
    int n_ingredients;
};

int cmpfunc(const void *a, const void *b){
    return (*(int *)b - *(int *)a);
}

void copy_arr(int original[], int copy[], int length){
    for (int i = 0; i < length; i++)
        copy[i] = original[i];
}

char *toLowerCase(char *str){
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

void recipes_search(){
    int n_recipes;
    int n_words = 0;
    int n_results = 0;
    char *words[MAX_KEYWORDS];
    struct Recipe *recipes;

    printf("\n");

    // read contents from json recipe file
    recipes = get_recipes("recipes.json", &n_recipes);

    // print instructions
    printf("Enter a maximum of 100 keywords seperated by spaces, end with a \"q\":\n");

    // read input keywords from user
    for (int i = 0; i < 100; i++){
        words[i] = malloc(sizeof(char) * 30);
        scanf("%s", words[i]); // scan inputs

        if (strcmp(words[i], "q") == 0)
            break;

        n_words++;
    }

    // search for recipes matching entered keywords
    int *results = search_recipes(recipes, n_recipes, words, n_words);

    // print results
    for (int i = 0; i < 50; i++)
        printf("%d. %s\n    - %s\n", i + 1, recipes[results[i]].name, recipes[results[i]].url);

    // free memory
    for (int i = 0; i < n_recipes; i++)
    {
        free(recipes[i].name);
        free(recipes[i].url);
        free(recipes[i].ingredients);
    }
    free(recipes);
    free(results);
}

int *search_recipes(struct Recipe *recipes, int n_recipes, char *keywords[], int n_keywords){
    int *points;
    int *results_sorted;

    points = malloc(sizeof(int) * n_recipes);
    results_sorted = malloc(sizeof(int) * n_recipes);

    // loops through recipes
    for (int i = 0; i < n_recipes; i++){
        points[i] = 0;
        // loops through ingredients in the recipe
        for (int ii = 0; ii < recipes[i].n_ingredients; ii++){
            // loops through keywords
            for (int iii = 0; iii < n_keywords; iii++){
                toLowerCase(recipes[i].ingredients[ii].name);
                if (strstr(recipes[i].ingredients[ii].name, keywords[iii])){
                    points[i]++;
                    break;
                }
            }
        }

        double db = (double)points[i] / recipes[i].n_ingredients * 100;

        points[i] = (int)db;
    }

    int i_results_sorted = 0;

    for (int i = 1000; i >= 1; i--){
        for (int ii = 0; ii < n_recipes; ii++){
            if (points[ii] == i){
                results_sorted[i_results_sorted] = ii;
                i_results_sorted++;
            }
        }
    }

    return results_sorted;
}

/**
 * Lists recipes
 * @param recipes the list of recipes to list
 * @param n_recipes the length of the recipies list
 */
void list_recipes(struct Recipe *recipes, int n_recipes){
    printf("\n");

    for (int i = 0; i < n_recipes; i++){
        printf("%s:\n", recipes[i].name);
        printf("    url: %s\n", recipes[i].name);
        printf("    ingredients:\n");

        for (int n = 0; n < recipes[i].n_ingredients; n++){
            printf("        %s\n", recipes[i].ingredients[n].name);
            printf("            amount: %f\n", recipes[i].ingredients[n].amount);
            printf("            unit: %s\n", recipes[i].ingredients[n].unit);
        }

        printf("\n");
    }
}

/**
 * load and parse json data from file
 * @param filename the name of the json file
 */
json_object *load_parse_json_data(char *filename){
    long fsize;
    char *buffer;
    FILE *fp;
    json_object *recipes_array;

    // open json file
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("ERROR: could not open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // get length of file buffer
    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    rewind(fp);

    buffer = malloc(fsize + 1);

    // read json file
    fread(buffer, fsize, 1, fp);
    fclose(fp); // close file

    // parse json
    recipes_array = json_tokener_parse(buffer);

    return recipes_array;
}

/**
 * get recipes from json data
 * @param filename the name of the file to read recipes from
 * @param length output parameter to get the length
 */
struct Recipe *get_recipes(char *filename, int *length){
    json_object *recipes_array = NULL;
    int n_recipes_array;
    struct Recipe *recipes;

    // parse json
    recipes_array = load_parse_json_data(filename);

    if (recipes_array == NULL){
        printf("ERROR: not able to parse data\n");
        exit(EXIT_FAILURE);
    }

    n_recipes_array = json_object_array_length(recipes_array);
    *length = n_recipes_array;

    printf("loaded %d recipes\n", n_recipes_array);

    for (int i = 0; i < n_recipes_array; i++){
        // get all the objects
        json_object *recipe_object = json_object_array_get_idx(recipes_array, i);
        json_object *name_object = json_object_object_get(recipe_object, "name");
        json_object *url_object = json_object_object_get(recipe_object, "url");
        json_object *ingredients_array = json_object_object_get(recipe_object, "ingredients");

        // get strings from object
        const char *name_str = json_object_get_string(name_object);
        const char *url_str = json_object_get_string(url_object);

        // get string and array lengths
        int n_name_str = json_object_get_string_len(name_object);
        int n_url_object = json_object_get_string_len(url_object);
        int n_ingredients_array = json_object_array_length(ingredients_array);

        // get ingredients in recipe
        struct Ingredient *ingredients = get_ingredients(ingredients_array);

        if (i == 0) // make sure all recipe pointers are first initialized with malloc
            recipes = malloc(sizeof(struct Recipe));
        else
            recipes = realloc(recipes, sizeof(struct Recipe) * (i + 1));

        // allocate memory based on the length of the strings and add pointer to current recipe
        recipes[i].name = malloc(sizeof(char) * n_name_str + 1);
        recipes[i].url = malloc(sizeof(char) * n_url_object + 1);

        // copy strings to recipe struct
        strcpy(recipes[i].name, name_str);
        strcpy(recipes[i].url, url_str);

        // assignt values to recipes struct
        recipes[i].ingredients = ingredients;
        recipes[i].n_ingredients = n_ingredients_array;
    }

    return recipes;
}

/**
 * get the ingredients in a recipe
 * @param ingredients_array the object array from json-c that represents the ingredients
 */
struct Ingredient *get_ingredients(struct json_object *ingredients_array){
    struct Ingredient *ingredients;

    // get length of ingredients_array
    int n_ingredients_array = json_object_array_length(ingredients_array);

    for (int i = 0; i < n_ingredients_array; i++){
        // get all json-c objects in ingredient
        json_object *ingredient_object = json_object_array_get_idx(ingredients_array, i);
        json_object *name_object = json_object_object_get(ingredient_object, "name");
        json_object *unit_object = json_object_object_get(ingredient_object, "unit");
        json_object *amount_object = json_object_object_get(ingredient_object, "amount");

        // get json-c object values
        const char *name_str = json_object_get_string(name_object);
        const char *unit_str = json_object_get_string(unit_object);
        double amount = json_object_get_double(amount_object);

        // get lengths of values
        int n_name_str = json_object_get_string_len(name_object);
        int n_unit_str = json_object_get_string_len(unit_object);

        if (i == 0) // always allocate with malloc first
            ingredients = malloc(sizeof(struct Ingredient));
        else
            ingredients = realloc(ingredients, sizeof(struct Ingredient) * (i + 1));

        // allocate memory
        ingredients[i].name = malloc(sizeof(char) * n_name_str + 1);
        ingredients[i].unit = malloc(sizeof(char) * n_unit_str + 1);

        // copy strings to the newly created pointers
        strcpy(ingredients[i].name, name_str);
        strcpy(ingredients[i].unit, unit_str);

        // add amount to struct
        ingredients[i].amount = amount;
    }

    return ingredients;
}