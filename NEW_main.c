#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>
#include <Food.c>

#define MAX_FOODS 25 // maximum number of foods
#define MAX_RECIPES 20000 // max number of recipes
#define MAX_RECIPE_ITEMS 30 // max number of recipe items in structs
#define NAME_LEN 30

//define recipe struct
typedef struct ingredient
{
    char *name;
    double amount;
    char *unit;
}ingredient;

typedef struct recipe
{
    char *name;
    char *url;
    struct ingredient *ingredients;
    int n_ingredients;
}recipe;

typedef struct fridge
{
    char *name;
    double amount;
}fridge;

//define fridge item struct

/*PROTOTYPES DECLARATIONS*/
void search_recipe_from_fridge (struct fridge* fridge[], struct recipe recipes[], int recipe_list_size, int fridge_list_size);
struct ingredient *get_ingredients(struct json_object *ingredients_array);
struct recipe *get_recipes(char *filename, int *length);
struct Food *read_fridge_from_file();
void list_recipes(struct recipe *recipes, int n_recipes);
json_object *load_parse_json_data(char *filename);

/*******MAIN*******/
int main (){  
    
    int n_rec;
    struct recipe *rec = get_recipes("./recipes.json", &n_rec);
    struct fridge *fridge[MAX_FOODS];
    
    list_recipes(rec, n_rec);
    read_fridge_from_file();

    print_main_menu();   
    
    answer_1 = search_recipe_from_fridge(fridge, recipe, recipe_list_size, fridge_list_size);
    //answer_2 = //function 
    //answer_2 = //function
    
    return 0
}

/* MAIN */
void print_main_menu(){
    int input;

    printf("\nSelect an option: \n"
           "\t1. Generate meal \n"
           "\t2. See refrigerator \n"
           "\t3. See recipes \n"
           "\t4. Add/remove food \n"
           "\t5. Add/remove/search recipe \n"
           "\t6. Quit \n");

    input = validate_menu_input(6);

    switch(input){
        case 1: generate_meal(); break;
        case 2: print_refrigerator(); break;
        case 3: print_recipes(); break;
        case 4: print_edit_food_menu(); break;
        case 5: print_edit_recipe_menu(); break; 
        case 6: quit(); break;
        default: exit(EXIT_FAILURE);
    }
}

/////   read_fridge_from_file(){}
Food* read_fridge_from_file(){
    int i = 0, j = 0, count = 1;
    char line[150];
    char *raw_values;
    Food *food_array;
    Food new;
    FILE * fridge_content_txt;
    fridge_content_txt = fopen("fridge.txt", "r");
    if(fridge_content_txt == NULL){
        fridge_content_txt = fopen("fridge.txt", "a+");
    }
    while(fgets(line, 150, fridge_content_txt) != NULL){
        count++;
    }
    rewind(fridge_content_txt);
    food_array = (Food *)malloc(sizeof(Food) * (count+50));

    while(fgets(line, 150, fridge_content_txt) != NULL){
        char saved_values[5][150] = {"", "", "", "", ""};
        //printf("%s \n", line); temp line for test

         raw_values = strtok(line, ",");
        strcat(saved_values[0], raw_values);
        
        raw_values = strtok(NULL, ",");
        strcat(saved_values[1], raw_values);
        
        raw_values = strtok(NULL, ",");
        strcat(saved_values[2], raw_values);

        food_array[i] = food_constructor(saved_values[0], saved_values[1], strtod(saved_values[2], NULL), atoi(saved_values[3]), atoi(saved_values[4]));
        i++;
    }
    return food_array;
}

/*
                read_recipes_from_file(){}
/**
 * Lists recipes
 * @param recipes the list of recipes to list
 * @param n_recipes the length of the recipies list
 */

void list_recipes(struct recipe *recipes, int n_recipes)
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
struct recipe *get_recipes(char *filename, int *length)
{
    json_object *recipes_array = NULL;
    int n_recipes_array;
    struct recipe *recipes;

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
        struct ingredient *ingredients = get_ingredients(ingredients_array);

        if (i == 0) // make sure all recipe pointers are first initialized with malloc
        {
            recipes = malloc(sizeof(struct recipe));
        }
        else
        {
            recipes = realloc(recipes, sizeof(struct recipe) * (i + 1));
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
struct ingredient *get_ingredients(struct json_object *ingredients_array)
{
    struct ingredient *ingredients;

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
            ingredients = malloc(sizeof(struct ingredient));
        }
        else
        {
            ingredients = realloc(ingredients, sizeof(struct ingredient) * (i + 1));
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
/*
read_user_config_from_file(){}

interperet_user_input(){
    //read user input
    //decide what action to take
}

print_fridge_content(){
    //format input array to string
    //output string
}
add_fridge_content(){}
remove_fridge_content(){}
*/
/////get_recipe_from_list(){}
void search_recipe_from_fridge (struct fridge_item_t* fridge[],
                                struct recipe* recipes[], 
                                int recipe_list_size, 
                                int fridge_list_size){

struct recipe* matches[MAX_RECIPES];
int m = 0; //matches index
int status = 0; //number of food values found true
int r, f;      
        //More generalised algoritm
        while ( r <= recipe_list_size){  
            for (f = 0; f <= fridge_list_size; f++ ){    
                int i = 0;//reset iteration variable
                do {
                    if (fridge[f]->name == *recipes[r]->ingredients[i]->name){ // maybe instead strcmp 
                        status++;
                        i++;
                        f++;
                    }    
                    else {   
                        i++;
                    }
                    //if all fridge content is found or more than 5 values, then recipe is stored in matches and exit loop
                    if (status > 5){
                        matches[m++] = *recipes[r];
                        break;
                    }
                
                }while (i <= sizeof(recipes[r]->ingredients) ); //number of recipe items
            
            } 

            recipes[r++]; //iterate to next structure element
            status = 0; //reset status to 0
        }
    //print result
    for (int i = 0 ; i <= len(matches) ; i++){
        printf("This is is the list of recipes you can choose from:\n%s\n%s\n", matches[i]->name, matches[i]->url );
    }

    return 0;
}
//search_for_recipe(){}
