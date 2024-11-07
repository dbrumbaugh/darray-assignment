/*
 * darray.h
 * A simple dynamic array for storing integers
 *
 * Copyright (C) 2024 Douglas Rumbaugh <dbrumbaugh@harrisburgu.edu>
 *
 * Distributed under the Modified BSD License.
 */
#ifndef H_DARRAY
#define H_DARRAY

#include <stdlib.h>

/* opaque type -- the struct should be implemented in a .c file  */
typedef struct darray darray;
   struct darray{
    size_t size;
    int *data;
};

/*
 * Create an empty darray object of size 0 and return a pointer to it. If the
 * creation should fail, return NULL.
 */
darray *da_create() {
    darray *new_darray = (darray *)malloc(sizeof(darray));
    if (!new_darray){
        return NULL;
    }
    new_darray->size = 0
    new_darray->data = NULL;
    return new_darray;
}


/*
 * Access the element stored at index idx within the darray and return a
 * pointer to it. If the idx is out of range for the darray, return NULL
 * instead. If the provided array pointer is NULL, return NULL.
 */
int *da_get(darray *array, size_t idx) {
    if (array == NULL || idx >= array->size){
        return NULL;
    }
    return &array->data[idx];
}

/*
 * Increase the length of array by 1 and place value within the newly created
 * spot. If the append operation fails, return 0. Otherwise return 1. Return 0
 * also if the provided array pointer is null.
 */
int da_append(darray *array, int value) {
    if (array == NULL) {
        return -1;
    }
    int *new_data = realloc(array->data, (array->size + 1) * sizeof(int));
    if (new_data == NULL){
        return -1;
    }
    array->data = new_data;
    array->data[array->size] = value;
    array->size +=1

    return 0;
}

/*
 * Returns the size of the array. Note that this size should be the accessible
 * size (using get, for example), not the physical size of the allocation,
 * which may be larger. If array is NULL, return 0.
 */
size_t da_size(darray *array){
    if (array == NULL) {
        return 0;
    }

    return array->size;
}

/*
 * Free all the allocated memory associated with array. If array is NULL, do
 * nothing.
 */
void da_delete(darray *array) {
    if (array == NULL) {
        return;
    }
    free(array->data);
    free(array);
    
    return;
}

#endif
