#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "recipes.c"

int main(void)
{
    int n_recipes;
    int n_words = 0;
    char *words[100];
    struct Recipe *recipes;

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
    int *results = search_recipes(recipes, n_recipes, words, n_words);

    // print results
    for (size_t i = 0; i < 30; i++)
    {
        printf("%d. %s\n    - %s\n", i + 1, recipes[results[i]].name, recipes[results[i]].url);
    }

    return 0;
}