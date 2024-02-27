#include <stdio.h>
#include <string.h>
#include "StrList.h"

void test_StrList_alloc_free() {
    // Test StrList_alloc and StrList_free
    printf("Testing StrList_alloc and StrList_free:\n");
    StrList* list = StrList_alloc();
    if (list != NULL) {
        printf("PASS: StrList_alloc returned a non-NULL pointer.\n");
    } else {
        printf("FAIL: StrList_alloc returned a NULL pointer.\n");
    }
    StrList_free(list);
    printf("StrList_free called successfully.\n\n");
}

void test_StrList_size() {
    // Test StrList_size
    printf("Testing StrList_size:\n");
    StrList* list = StrList_alloc();
    size_t initialSize = StrList_size(list);
    if (initialSize == 0) {
        printf("PASS: Initial size is 0.\n");
    } else {
        printf("FAIL: Initial size is not 0.\n");
    }

    StrList_insertLast(list, "Hello");
    StrList_insertLast(list, "World");
    size_t updatedSize = StrList_size(list);
    if (updatedSize == 2) {
        printf("PASS: Size after insertion is 2.\n");
    } else {
        printf("FAIL: Size after insertion is not 2.\n");
    }

    StrList_free(list);
    printf("\n");
}

void test_StrList_insertLast() {
    // Test StrList_insertLast
    printf("Testing StrList_insertLast:\n");
    StrList* list = StrList_alloc();
    StrList_insertLast(list, "Apple");
    StrList_insertLast(list, "Banana");
    StrList_insertLast(list, "Cherry");

    printf("Elements after insertion:\n");
    StrList_print(list);

    StrList_free(list);
    printf("\n");
}

void test_StrList_firstData() {
    // Test StrList_firstData
    printf("Testing StrList_firstData:\n");
    StrList* list = StrList_alloc();
    StrList_insertLast(list, "Apple");
    StrList_insertLast(list, "Banana");
    StrList_insertLast(list, "Cherry");

    char* first = StrList_firstData(list);
    if (first != NULL && strcmp(first, "Apple") == 0) {
        printf("PASS: First element is 'Apple'.\n");
    } else {
        printf("FAIL: First element is not 'Apple'.\n");
    }

    StrList_free(list);
    printf("\n");
}

void test_StrList_print() {
    // Test StrList_print
    printf("Testing StrList_print:\n");
    StrList* list = StrList_alloc();
    StrList_insertLast(list, "Apple");
    StrList_insertLast(list, "Banana");
    StrList_insertLast(list, "Cherry");

    printf("Elements in the list:\n");
    StrList_print(list);

    StrList_free(list);
    printf("\n");
}

void test_StrList_count() {
    // Test StrList_count
    printf("Testing StrList_count:\n");
    StrList* list = StrList_alloc();
    StrList_insertLast(list, "Apple");
    StrList_insertLast(list, "Banana");
    StrList_insertLast(list, "Apple");
    StrList_insertLast(list, "Cherry");
    StrList_insertLast(list, "Apple");

    int countApple = StrList_count(list, "Apple");
    if (countApple == 3) {
        printf("PASS: Count of 'Apple' is 3.\n");
    } else {
        printf("FAIL: Count of 'Apple' is not 3.\n");
    }

    int countBanana = StrList_count(list, "Banana");
    if (countBanana == 1) {
        printf("PASS: Count of 'Banana' is 1.\n");
    } else {
        printf("FAIL: Count of 'Banana' is not 1.\n");
    }

    int countOrange = StrList_count(list, "Orange");
    if (countOrange == 0) {
        printf("PASS: Count of 'Orange' is 0.\n");
    } else {
        printf("FAIL: Count of 'Orange' is not 0.\n");
    }

    StrList_free(list);
    printf("\n");
}

void test_StrList_remove() {
    // Test StrList_remove
    printf("Testing StrList_remove:\n");
    StrList* list = StrList_alloc();
    StrList_insertLast(list, "Apple");
    StrList_insertLast(list, "Banana");
    StrList_insertLast(list, "Apple");
    StrList_insertLast(list, "Cherry");
    StrList_insertLast(list, "Apple");

    printf("List before removal:\n");
    StrList_print(list);

    StrList_remove(list, "Apple");
    printf("List after removing 'Apple':\n");
    StrList_print(list);

    StrList_free(list);
    printf("\n");
}

void test_StrList_removeAt() {
    // Test StrList_removeAt
    printf("Testing StrList_removeAt:\n");
    StrList* list = StrList_alloc();
    StrList_insertLast(list, "Apple");
    StrList_insertLast(list, "Banana");
    StrList_insertLast(list, "Cherry");
    StrList_insertLast(list, "Orange");

    printf("List before removal at index 2:\n");
    StrList_print(list);

    StrList_removeAt(list, 2);
    printf("List after removal at index 2:\n");
    StrList_print(list);

    StrList_removeAt(list, 0);
    printf("List after removal at index 0:\n");
    StrList_print(list);

    StrList_removeAt(list, 1);
    printf("List after removal at index 1:\n");
    StrList_print(list);

    // Test with empty list
    StrList* emptyList = StrList_alloc();
    printf("Removing from an empty list:\n");
    StrList_removeAt(emptyList, 0);
    printf("List after removal:\n");
    StrList_print(emptyList);
    StrList_free(emptyList);

    // Test with NULL list
    printf("Removing from a NULL list:\n");
    StrList_removeAt(NULL, 0);
    printf("\n");

    StrList_free(list);
    printf("\n");
}

void test_StrList_isEqual() {
    // Test StrList_isEqual
    printf("Testing StrList_isEqual:\n");
    StrList* list1 = StrList_alloc();
    StrList_insertLast(list1, "Apple");
    StrList_insertLast(list1, "Banana");
    StrList_insertLast(list1, "Cherry");

    StrList* list2 = StrList_alloc();
    StrList_insertLast(list2, "Apple");
    StrList_insertLast(list2, "Banana");
    StrList_insertLast(list2, "Cherry");

    StrList* list3 = StrList_alloc();
    StrList_insertLast(list3, "Apple");
    StrList_insertLast(list3, "Banana");
    StrList_insertLast(list3, "Orange");

    printf("List 1:\n");
    StrList_print(list1);
    printf("List 2:\n");
    StrList_print(list2);
    printf("List 3:\n");
    StrList_print(list3);

    int isEqual12 = StrList_isEqual(list1, list2);
    if (isEqual12 == 1) {
        printf("PASS: List 1 is equal to List 2.\n");
    } else {
        printf("FAIL: List 1 is not equal to List 2.\n");
    }

    int isEqual13 = StrList_isEqual(list1, list3);
    if (isEqual13 == 0) {
        printf("PASS: List 1 is not equal to List 3.\n");
    } else {
        printf("FAIL: List 1 is equal to List 3.\n");
    }

    // Test with empty lists
    StrList* emptyList1 = StrList_alloc();
    StrList* emptyList2 = StrList_alloc();
    printf("Comparing empty lists:\n");
    int isEqualEmpty = StrList_isEqual(emptyList1, emptyList2);
    if (isEqualEmpty == 1) {
        printf("PASS: Empty lists are equal.\n");
    } else {
        printf("FAIL: Empty lists are not equal.\n");
    }
    StrList_free(emptyList1);
    StrList_free(emptyList2);

    // Test with NULL lists
    printf("Comparing NULL lists:\n");
    int isEqualNull = StrList_isEqual(NULL, NULL);
    if (isEqualNull == 1) {
        printf("PASS: NULL lists are equal.\n");
    } else {
        printf("FAIL: NULL lists are not equal.\n");
    }
    printf("\n");

    StrList_free(list1);
    StrList_free(list2);
    StrList_free(list3);
}

void test_StrList_clone() {
    // Test StrList_clone
    printf("Testing StrList_clone:\n");
    StrList* list = StrList_alloc();
    StrList_insertLast(list, "Apple");
    StrList_insertLast(list, "Banana");
    StrList_insertLast(list, "Cherry");

    StrList* clonedList = StrList_clone(list);

    printf("Original list:\n");
    StrList_print(list);
    printf("Cloned list:\n");
    StrList_print(clonedList);

    StrList_free(list);
    StrList_free(clonedList);
    printf("\n");
}

void test_StrList_reverse() {
    // Test StrList_reverse
    printf("Testing StrList_reverse:\n");
    StrList* list = StrList_alloc();
    StrList_insertLast(list, "Apple");
    StrList_insertLast(list, "Banana");
    StrList_insertLast(list, "Cherry");
    StrList_insertLast(list, "Orange");

    printf("List before reverse:\n");
    StrList_print(list);

    StrList_reverse(list);
    printf("List after reverse:\n");
    StrList_print(list);

    // Test with empty list
    StrList* emptyList = StrList_alloc();
    printf("Reversing an empty list:\n");
    StrList_reverse(emptyList);
    printf("List after reverse:\n");
    StrList_print(emptyList);
    StrList_free(emptyList);

    // Test with NULL list
    printf("Reversing a NULL list:\n");
    StrList_reverse(NULL);
    printf("\n");

    StrList_free(list);
    printf("\n");
}

void test_StrList_sort() {
    // Test StrList_sort
    printf("Testing StrList_sort:\n");
    StrList* list = StrList_alloc();
    StrList_insertLast(list, "Banana");
    StrList_insertLast(list, "Cherry");
    StrList_insertLast(list, "Apple");
    StrList_insertLast(list, "Orange");

    printf("List before sorting:\n");
    StrList_print(list);

    StrList_sort(list);
    printf("List after sorting:\n");
    StrList_print(list);

    // Test with empty list
    StrList* emptyList = StrList_alloc();
    printf("Sorting an empty list:\n");
    StrList_sort(emptyList);
    printf("List after sorting:\n");
    StrList_print(emptyList);
    StrList_free(emptyList);

    // Test with NULL list
    printf("Sorting a NULL list:\n");
    StrList_sort(NULL);
    printf("\n");

    StrList_free(list);
    printf("\n");
}

int main() {
    test_StrList_alloc_free();
    test_StrList_size();
    test_StrList_insertLast();
    test_StrList_firstData();
    test_StrList_print();
    test_StrList_count();
    test_StrList_remove();
    test_StrList_removeAt();
    test_StrList_isEqual();
    test_StrList_clone();
    test_StrList_reverse();
    test_StrList_sort();

    return 0;
}
