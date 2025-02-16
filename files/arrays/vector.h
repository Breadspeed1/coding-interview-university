
typedef struct Vector Vector;

Vector* new_vector();

int size(Vector* vector);
int capacity(Vector* vector);
int is_empty(Vector* vector);

void push(Vector* vector, int item);
void insert(Vector* vector, int index, int item);
void prepend(Vector* vector, int item);
void delete_at(Vector* vector, int index);
void remove_all(Vector* vector, int item);

int at(Vector* vector, int index);
int pop(Vector* vector);
int find(Vector* vector, int item);

void print(Vector* vector);

void delete(Vector* vector);