typedef struct {
    char name[20];
    unsigned int age;
} User;


User user_constructor(char name[], unsigned int age){
    User user;
    strcpy(user.name, name);
    user.age = age;

    return user;
}



void print_name(User user){
    printf("Name is: %s \n", user.name);
}

void print_age(User user){
    printf("Age is: %d \n", user.age);
}