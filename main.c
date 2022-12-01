#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "recipes.c"

#include "menu.c"

// Global variables (bad practice but works for now)
char *fridge[] = {"Spunk", "Feces", "Coochie soup", "Ass juice"};
int fridge_size = sizeof(fridge) / (sizeof(fridge[0]));

int main(void)
{
    start_menu();
    return 0;
}

char **get_fridge_array()
{
    return fridge;
}

int get_fridge_size()
{
    return fridge_size;
}

// Placeholder
void cook_meal(int meal)
{
    printf("Meal cooked!\n");
}

void recipes_search()
{
    int n_recipes;
    int n_words = 0;
    int n_results = 0;
    char *words[100];
    struct Recipe *recipes;

    printf("\n");

    // read contents from json recipe file
    recipes = get_recipes("recipes.json", &n_recipes);

    // print instructions
    printf("Enter a maximum of 100 keywords seperated by spaces, end with a \"q\":\n");

    // read input keywords from user
    for (int i = 0; i < 100; i++)
    {
        words[i] = malloc(sizeof(char) * 30);
        scanf("%s", words[i]); // scan inputs

        if (strcmp(words[i], "q") == 0)
        {
            break;
        }

        n_words++;
    }

    // search for recipes matching entered keywords
    int *results = search_recipes(recipes, n_recipes, words, n_words, &n_results);

    // print results
    for (size_t i = 0; i < n_results; i++)
    {
        printf("%d. %s\n    - %s\n", i + 1, recipes[results[i]].name, recipes[results[i]].url);

        if (i >= 19)
            break;
    }
}