typedef struct FOOD_LIST {
    char name[20];
    char unit[5];
    double CO2_emission;
    unsigned int isVegetarian;
    unsigned int expiration_date;
} FOOD_LIST;


FOOD_LIST food_constructor(char name[], char unit[], double CO2_emission, unsigned short isVegetarian, unsigned int expiration_date){
    FOOD_LIST food;
    strcpy(food.name,name);
    strcpy(food.unit,unit);
    food.CO2_emission = CO2_emission;
    food.isVegetarian = isVegetarian;
    food.expiration_date = expiration_date;

    return food;
}

void print_food_name(FOOD_LIST food){
    printf("%s\n", food.name);
}

void print_isVegetarian(FOOD_LIST food){
    if(food.isVegetarian == 1)
        printf("%s is vegetarian", food.name);
    else
        printf("%s is not vegetarian", food.name);
}