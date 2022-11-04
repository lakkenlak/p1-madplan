typedef struct {
    char name[20];
    char unit[5];
    double CO2_emission;
    unsigned int isVegetarian;
    unsigned int expiration_date;
} Food;


Food food_constructor(char name[], char unit[], double CO2_emission, unsigned short isVegetarian, unsigned int expiration_date){
    Food food;
    strcpy(food.name,name);
    strcpy(food.unit,unit);
    food.CO2_emission = CO2_emission;
    food.isVegetarian = isVegetarian;
    food.expiration_date = expiration_date;

    return food;
}

void print_food_name(Food food){
    printf("%s\n", food.name);
}

void print_isVegetarian(Food food){
    if(food.isVegetarian == 1)
        printf("%s is vegetarian", food.name);
    else
        printf("%s is not vegetarian", food.name);
}