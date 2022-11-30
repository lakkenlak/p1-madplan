#include "main.h"

int print_main_menu();
int validate_menu_input(int number_of_options);
int print_meal_menu();
int print_refrigerator();
int print_recipes();
int print_edit_food_menu();
int add_food_to_refrigerator();
int remove_food_from_refrigerator();
int print_edit_recipe_menu ();
int add_recipe();
int remove_recipe();
int search_recipe();
void quit();

void start_menu(){
    int run = 1,
        menu_input = print_main_menu();

    while(run){
        switch(menu_input){
            case 0: case 43: case 54: menu_input = print_main_menu(); break;
            case 1: menu_input = print_meal_menu(); break;
            case 2: menu_input = print_refrigerator(); break;
            case 3: menu_input = print_recipes(); break;
            case 4: menu_input = print_edit_food_menu(); break;
                case 41: menu_input = add_food_to_refrigerator(); break;
                case 42: menu_input = remove_food_from_refrigerator(); break;
            case 5: menu_input = print_edit_recipe_menu(); break;
                case 51: menu_input = add_recipe(); break;
                case 52: menu_input = remove_recipe(); break;
                case 53: menu_input = search_recipe(); break;
            case 6: quit(); run = 0; break;
            default:
                perror("Woopsie! Something went wrong in: start_menu()");
                exit(EXIT_FAILURE);
        }
    }
}

int validate_menu_input(int number_of_options){
    int menu_input, succesful_scan, sentinel;

    do{
        sentinel = 0;
        printf("Enter a number (1-%d): ", number_of_options);
        succesful_scan = scanf("%d", &menu_input);

        if(succesful_scan != 1 || menu_input < 1 || menu_input > number_of_options) {
            sentinel = 1;
            printf("\nAre you stupid? Try again!\n");
        }

        // Skips rest of data line just in case a char is entered
        while(getchar() != '\n');
    }
    while(sentinel);

    return menu_input;
}

int print_main_menu(){
    printf("\nSelect an option: \n"
           "\t1. Cook meal \n"
           "\t2. See refrigerator \n"
           "\t3. See recipes \n"
           "\t4. Add/remove food \n"
           "\t5. Add/remove/search recipe \n"
           "\t6. Quit \n");

    int menu_input = validate_menu_input(6);

    return menu_input;
}

// Placeholder
int print_meal_menu(){
    int number_of_options = 5; // Place holder for: array_length + 1 (+ 1 for 'Return')
    printf("\nList of meals that can be cooked with ingredients from refrigerator:\n");

    // Placeholder for call to function that prints the list of available meals to be cooked
    printf("1. Lasagna \n");
    printf("2. Pizza \n");
    printf("3. Burger \n");
    printf("4. Cream pie (yummy!) \n");
    printf("5. Return \n");

    int menu_input = validate_menu_input(number_of_options);

    if(menu_input < number_of_options){
        cook_meal(menu_input);
    }

    menu_input = (menu_input == number_of_options) ? 0 : 1;
    return menu_input;
}

int print_refrigerator(){
    char** fridge = get_fridge_array();
    int fridge_size = get_fridge_size();

    printf("Refrigerator (%d items): \n", fridge_size);
    for(int i = 0; i < fridge_size; i++){
        printf("- %s \n", fridge[i]);
    }

    return 0;
}

// Placeholder
int print_recipes(){
    printf("Recipes: \n"
           "- Lasagna \n"
           "- Shit Cake \n");

    // Go back to 'main menu'
    return 0;
}

int print_edit_food_menu(){
    printf("\nAdd or remove food? \n"
           "1. Add food \n"
           "2. Remove food \n"
           "3. Return \n");

    int menu_input = validate_menu_input(3);

    return menu_input + 40;
}

// Placeholder
int add_food_to_refrigerator(){
    printf("- Poop added to refrigerator! \n");

    // Go back to 'edit food menu'
    return 4;
}

// Placeholder
int remove_food_from_refrigerator(){
    printf("- Blood removed from refrigerator! \n");

    // Go back to 'edit food menu'
    return 4;
}

int print_edit_recipe_menu(){
    printf("\nAdd or remove recipe? \n"
           "1. Add recipe \n"
           "2. Remove recipe \n"
           "3. Search for recipe \n"
           "4. Return \n");

    int menu_input = validate_menu_input(4);

    return menu_input + 50;
}

// Placeholder
int add_recipe(){
    printf("- Lasagna recipe added! \n");

    // Go back to 'edit recipe menu'
    return 5;
}

// Placeholder
int remove_recipe(){
    printf("- Lasagna recipe removed! \n");

    // Go back to 'edit recipe menu'
    return 5;
}

// Placeholder
int search_recipe(){
    recipes_search();

    // Go back to 'edit recipe menu'
    return 5;
}

void quit(){
    // Save files
    // Free memory
    printf("\nGood-bye! \n");
    //exit(EXIT_SUCCESS);
}