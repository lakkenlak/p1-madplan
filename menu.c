// Prototypes
int print_main_menu();
int validate_menu_input(int number_of_options);
int print_refrigerator(struct fridge_item *fridge, int occupied_length);
int add_food_to_refrigerator(struct fridge_item *fridge, int *occupied_length, int *total_length);
int remove_food_from_refrigerator(struct fridge_item **fridge, int *fridge_occupied_length, int *fridge_total_length);
int search_recipe();
void recipes_search();
int search_recipe_with_fridge(struct fridge_item *fridge, int occupied_length);
void recipes_search_with_fridge(struct fridge_item fi[], int occupied_length);
void quit_message();

#define MAX_FOOD_ITEMS 100

enum menu_selection {
    MAIN_MENU,
    REFRIGERATOR,
    ADD_FOOD,
    REMOVE_FOOD,
    SEARCH_RECIPE,
    SEARCH_FRIDGE_RECIPES,
    QUIT
};

void start_menu(struct fridge_item *fridge, int occupied_length, int total_length){
    int run = 1;
    int menu_selection = MAIN_MENU;
    while(run){
        switch(menu_selection){
            case MAIN_MENU:             menu_selection = print_main_menu();                                                       
                                        break;
            case REFRIGERATOR:          menu_selection = print_refrigerator(fridge, occupied_length);                             
                                        break;
            case ADD_FOOD:              menu_selection = add_food_to_refrigerator(fridge, &occupied_length, &total_length);       
                                        break;
            case REMOVE_FOOD:           menu_selection = remove_food_from_refrigerator(&fridge, &occupied_length, &total_length); 
                                        break;
            case SEARCH_RECIPE:         menu_selection = search_recipe();                                                         
                                        break;
            case SEARCH_FRIDGE_RECIPES: menu_selection = search_recipe_with_fridge(fridge, occupied_length);                      
                                        break;
            case QUIT:                  quit_message(); run = 0;                                                                  
                                        break;
            default:
                printf("Whoopsie! Something went wrong in: start_menu()");
                exit(EXIT_FAILURE);
        }
    }
}

int print_main_menu(){
    printf("\nSelect an option: \n"
           "   1. See refrigerator \n"
           "   2. Add food \n"
           "   3. Remove food \n"
           "   4. Search specific recipes \n"
           "   5. Search fridge recipes \n"
           "   6. Quit \n");

    int menu_selection = validate_menu_input(6);
    return menu_selection;
}

int validate_menu_input(int number_of_options){
    int menu_input, successful_scan, sentinel;

    do{
        sentinel = 0;
        printf("Enter a number (1-%d): ", number_of_options);
        successful_scan = scanf("%d", &menu_input);

        if(successful_scan != 1 || menu_input < 1 || menu_input > number_of_options) {
            sentinel = 1;
            printf("\nNo characters and stay btw. 1-%d! Try again!\n", number_of_options);
        }

        // Skips rest of data line/input buffer just in case a char is entered
        while(getchar() != '\n');
    }
    while(sentinel);

    printf("\n");
    return menu_input;
}

int print_refrigerator(struct fridge_item *fridge, int occupied_length){
    print_fridge_items(fridge, occupied_length);

    return MAIN_MENU;
}

int add_food_to_refrigerator(struct fridge_item *fridge, int *occupied_length, int *total_length){
    struct fridge_item items[MAX_FOOD_ITEMS];
    int n_items = 0;
    printf("Please enter the name of the ingredients you wish to add to the fridge, seperate them by newlines and
    end with the letter \"q\"\n");
    for (int i = 0; i < MAX_FOOD_ITEMS; i++)
    {
        scanf(" %29[^\n]", items[i].name); 

        if (strcmp(items[i].name, "q") == 0)
            break;

        n_items++;
    }
    
    write_fridge_items_to_fridge(items, n_items);
    
    for(int j = 0; j<n_items; j++){
        fridge[*occupied_length+j] = items[j];
    }
    *occupied_length += n_items;
    return MAIN_MENU;
}

int remove_food_from_refrigerator(struct fridge_item **fridge, int *occupied_length, int *total_length){
    char string_deletion[101];
    int int_string_deletion; 
    int deletions[*occupied_length];
    int num_deletions = 0; 
    int quit = 0;

    print_fridge_items(*fridge, *occupied_length);
    printf("Which items would you like to remove?\n");
    printf("Input each number that corresponds to the item, seperated by spaces\n");
    printf("Once you have inputted the numbers, write 'q' to proceed (without quotes)\n");
    do{
        scanf("%s", string_deletion);

        if(strcmp(string_deletion, "q") != 0){
            int_string_deletion = atoi(string_deletion);
            if(int_string_deletion < *occupied_length && int_string_deletion >= 0){
                deletions[num_deletions] = int_string_deletion;
                num_deletions++;
            }
            else
                printf("The inputted number %s does not correspond to any items\n", string_deletion);
        }
        else
            quit = 1;
        
    }
    while(!quit && num_deletions < *occupied_length);
    
    struct fridge_item *new_fridge;
    int new_fridge_occupied_length;
    int new_fridge_total_length;
    new_fridge = remove_items_from_fridge(*fridge, *occupied_length, deletions, num_deletions, 
                                            &new_fridge_occupied_length, &new_fridge_total_length);
    *occupied_length = new_fridge_occupied_length;
    *total_length = new_fridge_total_length;
    free(*fridge);
    *fridge = new_fridge;
    return MAIN_MENU;
}

int search_recipe(){
    recipes_search();

    return MAIN_MENU;
}

int search_recipe_with_fridge(struct fridge_item *fridge, int occupied_length){
    print_fridge_items(fridge, occupied_length);
    recipes_search_with_fridge(fridge, occupied_length);

    return MAIN_MENU;
}

void quit_message(){
    printf("Have a nice day! \n");
}