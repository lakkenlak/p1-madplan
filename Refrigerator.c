typedef struct {
    Food items[20];
    int capacity;
} Refrigerator;

Refrigerator refrigerator;

Refrigerator refrigerator_constructor(int capacity){
    refrigerator.capacity = capacity;

    return refrigerator;
}

void add_to_refrigerator(Food food){
    int size = sizeof(refrigerator.items);
    refrigerator.items[size + 1] = food;

    int i;
   /* for(i = 0; i < sizeof(refrigerator.items); i++){
        if(refrigerator.items[i]) { // '\0' or ' '
            refrigerator.items[i] = food;
        }
    }*/
}


Food get_items(){

}