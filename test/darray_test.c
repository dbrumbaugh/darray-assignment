/* test/darray_test.c
 * 
 * Simple unit tests for the darray.h dynamic array library
 *
 * Copyright (C) 2024 Douglas Rumbaugh <dbrumbaugh@harrisburgu.edu>
 *
 * Distributed under the Modified BSD License.
*/
#include <assert.h>
#include "darray.h"

int main(int argc, char **argv) {
    darray *array = da_create();
    asser(array != NULL);

    for (int i = 0; i < 100; i++) {
        assert(da_append(array, i) == 1);
    }

    assert(da_size(array) == 100);

    for (int i = 0; i < 100; i++) {
        assert(*(da_get(array, i)) == i);
    }

    assert(da_get(array, 101) == NULL);

    da_delete(array);
}
