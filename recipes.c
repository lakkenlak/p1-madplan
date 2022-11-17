#include <stdio.h>
#include <string.h>
<<<<<<< HEAD
#include <json-c/json.h >
=======
#include "json-c/json.h"
>>>>>>> 16b22854034747507514ebb14f1f6a9daa1bf251

struct Ingredient *get_ingredients(struct json_object *ingredients_array);
struct Recipe *get_recipes(char *filename, int *length);

json_object *load_parse_json_data(char *filename);
void list_recipes(struct Recipe *recipes, int n_recipes);

struct Ingredient
{
    char *name;
    double amount;
    char *unit;
};

struct Recipe
{
    char *name;
    char *url;
    struct Ingredient *ingredients;
    int n_ingredients;
};

// for testing
 int main()
{
    int n_rec;
    struct Recipe *rec = get_recipes("./recipes.json", &n_rec);

    list_recipes(rec, n_rec);
}

/**
 * Lists recipes
 * @param recipes the list of recipes to list
 * @param n_recipes the length of the recipies list
 */
void list_recipes(struct Recipe *recipes, int n_recipes)
{
    printf("\n");

    for (size_t i = 0; i < n_recipes; i++)
    {
        printf("%s:\n", recipes[i].name);
        printf("    url: %s\n", recipes[i].name);
        printf("    ingredients:\n");

        for (size_t n = 0; n < recipes[i].n_ingredients; n++)
        {
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
json_object *load_parse_json_data(char *filename)
{
    long fsize;
    char *buffer;
    FILE *fp;
    json_object *recipes_array;

    // open json file
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("ERROR: could not open %s\n", filename);
        exit(0);
    }

    // get length of file buffer
    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    rewind(fp);

    buffer = malloc(fsize + 1);

    // read json file
    fread(buffer, fsize, 1, fp);
    fclose; // close file

    // parse json
    recipes_array = json_tokener_parse(buffer);

    return recipes_array;
}

/**
 * get recipes from json data
 * @param filename the name of the file to read recipes from
 * @param length output parameter to get the length
 */
struct Recipe *get_recipes(char *filename, int *length)
{
    json_object *recipes_array = NULL;
    int n_recipes_array;
    struct Recipe *recipes;

    // parse json
    recipes_array = load_parse_json_data(filename);

    if (recipes_array == NULL)
    {
        printf("ERROR: not able to parse data\n");
        exit(0);
    }

    n_recipes_array = json_object_array_length(recipes_array);
    *length = n_recipes_array;

    printf("loaded %d recipes\n", n_recipes_array);

    for (int i = 0; i < n_recipes_array; i++)
    {
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
        {
            recipes = malloc(sizeof(struct Recipe));
        }
        else
        {
            recipes = realloc(recipes, sizeof(struct Recipe) * (i + 1));
        }

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
struct Ingredient *get_ingredients(struct json_object *ingredients_array)
{
    struct Ingredient *ingredients;

    // get length of ingredients_array
    int n_ingredients_array = json_object_array_length(ingredients_array);

    for (int i = 0; i < n_ingredients_array; i++)
    {
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
        {
            ingredients = malloc(sizeof(struct Ingredient));
        }
        else
        {
            ingredients = realloc(ingredients, sizeof(struct Ingredient) * (i + 1));
        }

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