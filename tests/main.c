#include <stddef.h>
#include <cmocka.h>
#include <stdlib.h>
#include <check.h>
#include <string.h>
#include "../lists.h"


static void null_test_success(void **state)
{
    (void) state;
}

static void test_L_list_new1(void **state)
{
    char *expected = "Joe";
    typedef struct data_t {
        char *name;
        int age;
    } Data;

    Data *data;

    data = malloc(sizeof(Data));
    data->name = malloc(sizeof(expected));
    strcat(data->name, expected);
    data->age = 47;

    L_List *list = L_list_new(data);
    /* unit test code */
    Data *resultData = list->data;
    assert_string_equal(expected, resultData->name);
    assert_int_equal(47, resultData->age);
    /* clean up */
    free(data);
    free(list);
}

static void test_L_list_insert(void **state)
{
    // Setup
    typedef struct data_t {
        char *name;
    } Data;

    Data *data = malloc(sizeof(Data));
    Data *data3 = malloc(sizeof(Data)); // for negative test
    data->name = calloc(4, sizeof(char));
    strcpy(data->name, "Joe");
    L_List *list = L_list_new(data);

    // Setup for L_list_insert
    Data *data2 = malloc(sizeof(Data));
    data2->name = calloc(4, sizeof(char));
    strcpy(data2->name, "Ted");
    int result1 = L_list_insert(list, data2);

    // Test
    assert_int_equal(result1, L_NO_ERROR);
    assert_ptr_equal(list->data, data);
    assert_string_equal(((Data*)list->data)->name, "Joe");
    assert_ptr_equal(list->next->data, data2);
    assert_ptr_not_equal(list->next->data, data3);
    assert_string_equal(((Data*)list->next->data)->name, "Ted");
}

static void test_L_list_delete(void **state)
{
    // Setup
    typedef struct data_t {
        char *name;
    } Data;

    Data *data = malloc(sizeof(Data));
    data->name = calloc(4, sizeof(char));
    strcat(data->name, "Joe");
    L_List *list = L_list_new(data);

    // Insert another item
    Data *data2 = malloc(sizeof(Data));
    data2->name = calloc(4, sizeof(char));
    strcpy(data2->name, "Ted");
    L_list_insert(list, data2);

    // Insert another item
    Data *data3 = malloc(sizeof(Data));
    data3->name = calloc(4, sizeof(char));
    strcpy(data3->name, "Pat");
    L_list_insert(list, data3);

    // Delete the #2nd item
    void *result = L_list_delete(list, data2);

    // Test
    assert_ptr_equal(result, data2);
    assert_ptr_equal(list->data, data);
    assert_ptr_equal(list->next->data, data3);
    assert_ptr_equal(list->next->next, NULL);
}

static void test_L_LIST_IS_EMPTY(void **state)
{
    int d = 1;
    L_List *l = L_list_new(&d);
    int result = L_LIST_IS_EMPTY(l);
    assert_int_equal(result, 0);
    result = L_LIST_IS_EMPTY(NULL);
    assert_int_equal(result, 1);
}

static void test_L_list_size(void **state)
{
    int d1 = 1;
    int d2 = 1;
    int d3 = 1;
    int d4 = 1;
    int result;
    L_List *l = L_list_new(&d1);
    L_list_insert(l, &d2);
    L_list_insert(l, &d3);
    L_list_insert(l, &d4);
    result = L_list_size(l);
    assert_int_equal(result, 3);
}

static void test_L_LIST_NEXT(void **state)
{
    int d1 = 1;
    int d2 = 2;
    int d3 = 3;
    int d4 = 4;
    L_List *l = L_list_new(&d1);
    L_list_insert(l, &d2);
    L_list_insert(l, &d3);
    L_list_insert(l, &d4);
    assert_ptr_equal(l->data, &d1);
    L_List *l2 = L_LIST_NEXT(l);
    assert_ptr_equal(l2->data, &d2);
    L_List *l3 = L_LIST_NEXT(l2);
    assert_ptr_equal(l3->data, &d3);
    L_List *l4 = L_LIST_NEXT(l3);
    assert_ptr_equal(l4->data, &d4);
}

static void test_L_LIST_DATA(void **state)
{
    int d1 = 1;
    L_List *l = L_list_new(&d1);
    int* result = L_LIST_DATA(l);
    assert_ptr_equal(result, &d1);
}

static void test_L_list_destroy(void **state)
{
    int d1 = 1;
    int d2 = 2;
    int d3 = 3;
    int d4 = 4;
    int result;
    L_List *l = L_list_new(&d1);
    L_list_insert(l, &d2);
    L_list_insert(l, &d3);
    L_list_insert(l, &d4);
    L_list_destroy(l);
    assert_int_equal(L_LIST_IS_EMPTY(l), 0);
}

static void test_L_list_tail(void **state)
{
    int d1 = 1;
    int d2 = 2;
    int d3 = 3;
    int d4 = 4;
    L_List *l = L_list_new(&d1);
    L_list_insert(l, &d2);
    L_list_insert(l, &d3);
    L_list_insert(l, &d4);
    L_List *l2 = L_LIST_NEXT(l);
    L_List *l3 = L_LIST_NEXT(l2);
    L_List *l4 = L_LIST_NEXT(l3);
    L_List *tail = L_list_tail(l);
    assert_ptr_equal(tail, l4);
}

int main()
{
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(null_test_success),
            cmocka_unit_test(test_L_list_new1),
            cmocka_unit_test(test_L_list_insert),
            cmocka_unit_test(test_L_list_delete),
            cmocka_unit_test(test_L_LIST_IS_EMPTY),
            cmocka_unit_test(test_L_list_size),
            cmocka_unit_test(test_L_LIST_NEXT),
            cmocka_unit_test(test_L_LIST_DATA),
            cmocka_unit_test(test_L_list_destroy),
            cmocka_unit_test(test_L_list_tail)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
