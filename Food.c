typedef struct {
    char name[20];
    double CO2_emission;
    unsigned int isVegetarian;
} Food;


Food food_constructor(char name[], double CO2_emission, unsigned short isVegetarian){
    Food food;
    strcpy(food.name,name);
    food.CO2_emission = CO2_emission;
    food.isVegetarian = isVegetarian;
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