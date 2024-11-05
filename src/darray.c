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
  int *data;                 /* backing array for storing data */
  size_t allocation_size;    /* number of INTs allocated in data */
  size_t number_of_elements; /* number of INTs stored in data */
};

/* ensure these are static to keep them encapsulated */
static const size_t g_initial_size = 10;
static const size_t g_growth_factor = 2;

/*
 * Create an empty darray object of size 0 and return a pointer to it. If the
 * creation should fail, return NULL.
 */
darray *da_create() {
  /* allocate and check darray object */
  darray *array = malloc(sizeof(darray));
  if (array == NULL) return NULL; /* failure */

  /* allocate and check backing array */
  array->data = malloc(sizeof(int) * g_initial_size);
  if (array->data == NULL) { /* allocation failure */
    free(array); /* clean up already allocated mem */
    return NULL; /* failure */
  }

  /* initialize attributes of darray */
  array->allocation_size = g_initial_size;
  array->number_of_elements = 0;

  return array; /* success */
}

/*
 * Access the element stored at index idx within the darray and return a
 * pointer to it. If the idx is out of range for the darray, return NULL
 * instead. If the provided array pointer is NULL, return NULL.
 */
int *da_get(darray *array, size_t idx) {
  /*
   * this if statement is safe because of short circuiting;
   * if array is null, then the second condition won't be
   * checked
   */
  if (array == NULL || idx >= array->number_of_elements) {
    return NULL; /* failure */
  }

  return array->data + idx; /* success */
  /* or, return &array->data[idx] */
}

/*
 * Increase the length of array by 1 and place value within the newly created
 * spot. If the append operation fails, return 0. Otherwise return 1. Return 0
 * also if the provided array pointer is null.
 */
int da_append(darray *array, int value) {
  if (array == NULL) return 0; /* failure */

  /* if there isn't space in the array, we need to reallocate */
  if (array->number_of_elements == array->allocation_size) {
    /* use geometric growth for efficiency */
    size_t new_size = array->allocation_size * g_growth_factor;

    /* reallocate backing array and check allocation */
    int *tmp = realloc(array->data, new_size * sizeof(int));
    if (tmp == NULL) return 0; /* failure */

    /* update the backing array and its size in the darray object */
    array->data = tmp;
    array->allocation_size = new_size;
  }

  /* append the element and increase the element counter */
  array->data[array->number_of_elements] = value;
  array->number_of_elements++;

  return 1; /* success */
}

/*
 * Returns the size of the array. Note that this size should be the accessible
 * size (using get, for example), not the physical size of the allocation,
 * which may be larger. If array is NULL, return 0.
 */
size_t da_size(darray *array) {
  return (array == NULL) ? 0 : array->number_of_elements;
}

/*
 * Free all the allocated memory associated with array. If array is NULL, do
 * nothing.
 */
void da_delete(darray *array) {
  if (array == NULL) return; /* failure */

  free(array->data); /* free backing array first */
  free(array);

  return; /* success */
}
