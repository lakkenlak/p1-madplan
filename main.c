#include "User.c"
#include "Food.c"
#include "Refrigerator.c"

int main(void) {
    User u1 = user_constructor("Martin", 34);
    Food f1 = food_constructor("Ost", "kg", 42, 0, 010124);
    Food f2 = food_constructor("Sæd", "l", 69, 0, 060666);
    //Refrigerator r1 = refrigerator_constructor(42);
    //add_to_refrigerator(f1);


    //printf("u1: %s", u1.name);


    print_name(u1);
    print_isVegetarian(f1);

    return 0;
}

