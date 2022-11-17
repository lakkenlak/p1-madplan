#include "main.h"

void print_main_menu();                 //char *fridge[], int fridge_size);
int validate_menu_input(int number_of_options);
void generate_meal();
void print_refrigerator();              //char *fridge[], int fridge_size);
void print_recipes();
void print_edit_food_menu();
void add_food_to_refrigerator();
void remove_food_from_refrigerator();
void print_edit_recipe_menu ();
void add_recipe();
void remove_recipe();
void search_recipe();
void quit();

void print_main_menu(){                 //char *fridge[], int fridge_size){
    printf("\nSelect an option: \n"
           "\t1. Generate meal \n"
           "\t2. See refrigerator \n"
           "\t3. See recipes \n"
           "\t4. Add/remove food \n"
           "\t5. Add/remove/search recipe \n"
           "\t6. Quit \n");

    int menu_input = validate_menu_input(6);
    switch(menu_input){
        case 1: generate_meal(); break;
        case 2: print_refrigerator(); break;            // fridge, fridge_size
        case 3: print_recipes(); break;
        case 4: print_edit_food_menu(); break;
        case 5: print_edit_recipe_menu(); break; 
        case 6: quit(); break;
        default:
            perror("Woopsie! Something went wrong in: print_main_menu()");
            exit(EXIT_FAILURE);
    }
}

int validate_menu_input(int number_of_options){
    int menu_input, succesful_scan, sentinel;

    do{
        sentinel = 0;
        printf("Enter a number (1-%d):", number_of_options);
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

// Placeholder
void generate_meal(){
    printf("- Million Beef generated! \n");
    print_main_menu();
}

void print_refrigerator(){                  //char *fridge[], int fridge_size){
    char** fridge = get_fridge_array();
    int fridge_size = get_fridge_size();

    printf("Refrigerator (%d items): \n", fridge_size);
    for(int i = 0; i < fridge_size; i++){
        printf("- %s \n", fridge[i]);
    }

    print_main_menu();                      // fridge, fridge_size
}

// Placeholder
void print_recipes(){
    printf("Recipes: \n"
           "- Lasagna \n"
           "- Shit Cake \n");
    print_main_menu();
}

void print_edit_food_menu(){
    printf("\nAdd or remove food? \n"
           "1. Add food \n"
           "2. Remove food \n"
           "3. Return \n");

    int menu_input = validate_menu_input(3);

    switch(menu_input){
        case 1: add_food_to_refrigerator(); break;
        case 2: remove_food_from_refrigerator(); break;
        case 3: print_main_menu(); break;
        default:
            perror("Woopsie! Something went wrong in: print_edit_food_menu()");
            exit(EXIT_FAILURE);
    }
}

// Placeholder
void add_food_to_refrigerator(){
    printf("- Poop added to refrigerator! \n");
    print_edit_food_menu();
}

// Placeholder
void remove_food_from_refrigerator(){
    printf("- Blood removed from refrigerator! \n");
    print_edit_food_menu();
}

void print_edit_recipe_menu(){
    printf("\nAdd or remove recipe? \n"
           "1. Add recipe \n"
           "2. Remove recipe \n"
           "3. Search for recipe \n"
           "4. Return \n");

    int menu_input = validate_menu_input(4);

    switch(menu_input){
        case 1: add_recipe(); break;
        case 2: remove_recipe(); break;
        case 3: search_recipe(); break;
        case 4: print_main_menu(); break;
        default:
            perror("Woopsie! Something went wrong in: print_edit_recipe_menu()");
            exit(EXIT_FAILURE);
    }
}

// Placeholder
void add_recipe(){
    printf("- Lasagna recipe added! \n");
    print_edit_recipe_menu();
}

// Placeholder
void remove_recipe(){
    printf("- Lasagna recipe removed! \n");
    print_edit_recipe_menu();
}

// Placeholder
void search_recipe(){
    printf("Found recipe for 'Lasagna': \n"
           "- Lots of cheese! \n"
           "- A pinch of semen \n");
    print_edit_recipe_menu();
}

void quit(){
    // save_refrigerator();
    // save_recipes();
    printf("\nGood-bye! \n");
    exit(EXIT_SUCCESS);
}