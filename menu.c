#include "main.h"

struct fridge_item *get_fridge_array_real();
void set_fridge_array_real(struct fridge_item *array);
void set_fridge_occupied_length(int occupied_length);
void set_fridge_total_length(int total_length);
int get_fridge_occupied_length();
int get_fridge_total_length();
void recipes_search_with_fridge(struct fridge_item fi[], int occupied_length);
int search_recipe_with_fridge();
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

enum menu_selection {
    MAIN_MENU = 0,
    COOK_MEAL = 1,
    REFRIGERATOR = 2,
    RECIPES = 3,
    FOOD_MENU = 4,
        ADD_FOOD = 41,      // Sub-menu
        REMOVE_FOOD = 42,
    RECIPE_MENU = 5,
        ADD_RECIPE = 51,    // Sub-menu
        REMOVE_RECIPE = 52,
        SEARCH_RECIPE = 53,
        SEARCH_FRIDGE_RECIPES = 54,
    QUIT = 6
};

void start_menu(){
    int run = 1;
    int menu_selection = print_main_menu();

    while(run){
        switch(menu_selection){
            case MAIN_MENU:             menu_selection = print_main_menu();               break;
            case COOK_MEAL:             menu_selection = print_meal_menu();               break;
            case REFRIGERATOR:          menu_selection = print_refrigerator();            break;
            case RECIPES:               menu_selection = print_recipes();                 break;

            case FOOD_MENU:             menu_selection = print_edit_food_menu();          break;
            case ADD_FOOD:              menu_selection = add_food_to_refrigerator();      break;
            case REMOVE_FOOD:           menu_selection = remove_food_from_refrigerator(); break;

            case RECIPE_MENU:           menu_selection = print_edit_recipe_menu();        break;
            case ADD_RECIPE:            menu_selection = add_recipe();                    break;
            case REMOVE_RECIPE:         menu_selection = remove_recipe();                 break;
            case SEARCH_RECIPE:         menu_selection = search_recipe();                 break;
            case SEARCH_FRIDGE_RECIPES: menu_selection = search_recipe_with_fridge();     break;

            case QUIT:                  quit(); run = 0;                                  break;
            default:
                perror("Woopsie! Something went wrong in: start_menu()");
                exit(EXIT_FAILURE);
        }
    }
}

int print_main_menu(){
    printf("Select an option: \n"
           "\t1. Cook meal \n"
           "\t2. See refrigerator \n"
           "\t3. See recipes \n"
           "\t4. Add/remove food \n"
           "\t5. Add/remove/search recipe \n"
           "\t6. Quit \n");

    int menu_selection = validate_menu_input(6);
    return menu_selection;
}

int validate_menu_input(int number_of_options){
    int menu_input, succesful_scan, sentinel;

    do{
        sentinel = 0;
        printf("Enter a number (1-%d): ", number_of_options);
        succesful_scan = scanf("%d", &menu_input);

        if(succesful_scan != 1 || menu_input < 1 || menu_input > number_of_options) {
            sentinel = 1;
            printf("\nNo characters! Try again!\n");
        }

        // Skips rest of data line just in case a char is entered
        while(getchar() != '\n');
    }
    while(sentinel);

    printf("\n");
    return menu_input;
}

// Placeholder
int print_meal_menu(){
    int number_of_options = 5; // Place holder for: array_length + 1 (+ 1 for 'Return')
    printf("List of meals that can be cooked with ingredients from refrigerator:\n");
    printf("\t1. Meal 1 \n"
           "\t2. Meal 2 \n"
           "\t3. Meal 3 \n"
           "\t4. Meal 4 \n"
           "\t5. Return \n");

    int menu_selection = validate_menu_input(number_of_options);

    if(menu_selection < number_of_options){
        printf("Cooking meal %d! \n\n", menu_selection);
    }

    // Return to main menu if last menu option (Return) is selected (which is equal to number_of_options)
    return (menu_selection != number_of_options);
}

int print_refrigerator(){
    struct fridge_item *fridge_array = get_fridge_array_real();
    int occupied_length = get_fridge_occupied_length();
    print_fridge_items(fridge_array, occupied_length);

    return MAIN_MENU;
}

// Placeholder
int print_recipes(){

    // Go back to 'main menu'
    return MAIN_MENU;
}

int print_edit_food_menu(){
    printf("Add or remove food? \n"
           "1. Add food \n"
           "2. Remove food \n"
           "3. Return \n");

    int menu_selection = validate_menu_input(3);
    return (menu_selection == 3) ? MAIN_MENU : menu_selection + 40;
}

int add_food_to_refrigerator(){
    struct fridge_item items[100];
    struct fridge_item *new_fridge_array;
    int occupied_length;
    int total_length;
    int n_items = 0;
    printf("Please enter the name of the ingredients you wish to add to the fridge, end with  \"q\"\n");
    for (int i = 0; i < 100; i++)
    {
        scanf(" %29[^\n]", items[i].name); 

        if (strcmp(items[i].name, "q") == 0)
        {
            break;
        }

        n_items++;
    }
    write_fridge_items_to_fridge(items, n_items);

    new_fridge_array = read_fridge_from_file(&occupied_length, &total_length);
    set_fridge_array_real(new_fridge_array);
    set_fridge_occupied_length(occupied_length);
    set_fridge_total_length(total_length);

    // Go back to 'edit food menu'
    return FOOD_MENU;
}

int remove_food_from_refrigerator(){
    
    struct fridge_item *fridge_array = get_fridge_array_real();
    int occupied_length = get_fridge_occupied_length();
    char string_deletion[101];
    int int_string_deletion; 
    int deletions[occupied_length];
    int num_deletions = 0; //change name to num_deletions
    int quit = 0;

    print_fridge_items(fridge_array, occupied_length);
    printf("Which items would you like to remove?\n");
    printf("Input each number that corresponds to the item, seperated by spaces\n");
    printf("Once you have inputted the numbers, write 'q' to proceed (without quotes)\n");
    do{
        scanf("%s", &string_deletion);

        if(strcmp(string_deletion, "q") != 0){
            int_string_deletion = atoi(string_deletion);
            if(int_string_deletion < occupied_length && int_string_deletion >= 0){
                deletions[num_deletions] = int_string_deletion;
                num_deletions++;
            }
            else{
                printf("The inputted number %s does not correspond to any items\n", string_deletion);
            }
        }
        else{
            quit = 1;
        }
    }while(!quit && num_deletions < occupied_length);
    
    printf("The following item(s) have been removed from your fridge:\n");
    for(int j = 0; j<num_deletions; j++){
        printf("%s\n", fridge_array[deletions[j]].name);
    }

    printf("Deletions array:\n");
    for(int j = 0; j<num_deletions; j++){
        printf("deletions[%d] = %d\n", j, deletions[j]);
    }

    struct fridge_item *new_fridge;
    int new_fridge_occupied_length;
    int new_fridge_total_length;
    new_fridge = remove_items_from_fridge(fridge_array, occupied_length, deletions, num_deletions, 
                                            &new_fridge_occupied_length, &new_fridge_total_length);
    set_fridge_array_real(new_fridge);
    set_fridge_total_length(new_fridge_total_length);
    set_fridge_occupied_length(new_fridge_occupied_length);

    // Go back to 'edit food menu'
    return FOOD_MENU;
}

int print_edit_recipe_menu(){
    printf("\nAdd or remove recipe? \n"
           "1. Add recipe \n"
           "2. Remove recipe \n"
           "3. Search for recipe \n"
           "4. Search for recipe by contents of fridge \n"
           "5. Return \n");

    int menu_selection = validate_menu_input(5);
    return (menu_selection == 5) ? MAIN_MENU : menu_selection + 50;
}

// Placeholder
int add_recipe(){

    // Go back to 'edit recipe menu'
    return RECIPE_MENU;
}

// Placeholder
int remove_recipe(){

    // Go back to 'edit recipe menu'
    return RECIPE_MENU;
}

// Placeholder
int search_recipe(){
    recipes_search();

    // Go back to 'edit recipe menu'
    return RECIPE_MENU;
}

int search_recipe_with_fridge(){
    struct fridge_item *fridge_array = get_fridge_array_real();
    int length = get_fridge_occupied_length();
    print_fridge_items(fridge_array, length);
    recipes_search_with_fridge(fridge_array, length);

    // Go back to 'edit recipe menu'
    return RECIPE_MENU;
}

void quit(){
    printf("Have a nice day! \n");
}