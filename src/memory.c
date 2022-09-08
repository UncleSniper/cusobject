#include "OutOfMemoryError.h"

cusobj_allocator_t cusobj_allocator = malloc;

cusobj_deallocator_t cusobj_deallocator = free;

void *cusobj_alloc(
	size_t size,
	struct Error **exception
) {
	void *object;
	if(!size)
		return NULL;
	object = (cusobj_allocator ? cusobj_allocator : malloc)(size);
	if(object)
		return object;
	if(exception) {
		*exception = cusobj_out_of_memory_error_factory ? cusobj_out_of_memory_error_factory() : NULL;
		if(!*exception)
			*exception = singleton_OutOfMemoryError;
	}
	return NULL;
}
