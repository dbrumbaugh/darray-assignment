/*
 * darray.c
 * A simple dynamic array for storing integers
 *
 * Copyright (C) 2024 Douglas Rumbaugh <dbrumbaugh@harrisburgu.edu>
 *
 * Distributed under the Modified BSD License.
 */
#include "darray.h"

struct darray {
  /* your attributes go here */
};

/*
 * Create an empty darray object of size 0 and return a pointer to it. If the
 * creation should fail, return NULL.
 */
darray *da_create() {
 
}


/*
 * Access the element stored at index idx within the darray and return a
 * pointer to it. If the idx is out of range for the darray, return NULL
 * instead. If the provided array pointer is NULL, return NULL.
 */
int *da_get(darray *array, size_t idx) {
 
}

/*
 * Increase the length of array by 1 and place value within the newly created
 * spot. If the append operation fails, return 0. Otherwise return 1. Return 0
 * also if the provided array pointer is null.
 */
int da_append(darray *array, int value) {
 
}

/*
 * Returns the size of the array. Note that this size should be the accessible
 * size (using get, for example), not the physical size of the allocation,
 * which may be larger. If array is NULL, return 0.
 */
size_t da_size(darray *array) {
 
}

/*
 * Free all the allocated memory associated with array. If array is NULL, do
 * nothing.
 */
void da_delete(darray *array) {
 
}
