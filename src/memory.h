#ifndef CUSOBJECT_MEMORY_H
#define CUSOBJECT_MEMORY_H

#include <stdlib.h>

struct Error;

typedef void *(*cusobj_allocator_t)(
	size_t size
);

typedef void (*cusobj_deallocator_t)(
	void *object
);

extern cusobj_allocator_t cusobj_allocator;
extern cusobj_deallocator_t cusobj_deallocator;

void *cusobj_alloc(
	size_t size,
	struct Error **exception
);

inline void cusobj_free(
	void *object
) {
	if(object)
		(cusobj_deallocator ? cusobj_deallocator : free)(object);
}

#endif /* CUSOBJECT_MEMORY_H */
