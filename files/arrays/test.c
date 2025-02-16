#include <stdlib.h>
#include <stdio.h>
#include "test.h"
#include "vector.h"

void assert(int res, char* msg) {
    if (!res) printf("TEST FAILED: %s\n", msg);
}

int eq(Vector* v, int* arr) {
    for (int i = 0; i < size(v); i++) {
        if (arr[i] != at(v, i)) {
            return 0;
        }
    }

    return 1;
}

void init_vector(Vector* v) {
    for (int i = 0; i < 5; i++) {
        push(v, i);
    }
}

void test_push() {
    printf("\n===PUSH TESTS===\n");
    Vector* v = new_vector();

    assert(size(v) == 0, "Size of vector upon creation should be 0");

    push(v, 1);

    print(v);

    assert(size(v) == 1, "size of vector upon single push should be 1");

    push(v, 2);
    push(v, 3);

    assert(size(v) == 3, "size of vector upon 3 pushes should be 3");

    print(v);

    delete(v);
}

void test_delete_at() {
    printf("\n===DELETION TESTS===\n");
    Vector* v = new_vector();
    push(v, 1);

    delete_at(v, 0);

    assert(size(v) == 0, "size after deletion should be 0");
    // int arr[] = {1, 2, 3};
    // assert(eq(v, arr), "arrays should be equal");

    push(v, 1);
    push(v, 2);

    print(v);

    delete_at(v, 0);

    assert(size(v) == 1, "size after deletion should be 1");

    print(v);

    push(v, 2);
    push(v, 3);
    push(v, 4);

    //2 2 3 4
    delete_at(v, 3);

    //2 2 3
    print(v);

    delete_at(v, 1);

    //2 3
    print(v);

    delete(v);
}

void test_remove_all() {
    printf("\n===REMOVE ALL TESTS===\n");
    Vector* v = new_vector();

    push(v, 1);
    push(v, 2);
    push(v, 1);
    push(v, 3);
    push(v, 1);

    print(v);

    remove_all(v, 1);

    print(v);

    delete(v);
}

void test_pop() {
    printf("\n===POP TESTS===\n");
    Vector* v = new_vector();

    push(v, 1);
    push(v, 2);

    print(v);

    pop(v);

    print(v);

    pop(v);

    print(v);

    delete(v);
}

void test_insert() {
    printf("\n===INSERT TESTS===\n");
    Vector* v = new_vector();

    insert(v, 0, 1);
    insert(v, 0, 2);
    insert(v, 1, 3);

    print(v);
    delete(v);
}

void run_tests() {
    test_push();
    test_delete_at();
    test_remove_all();
    test_pop();
    test_insert();
}

int main() {
    printf("Beginning test\n");
    run_tests();
    printf("Tests finished.\n");
}
