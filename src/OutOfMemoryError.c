#include "OutOfMemoryError.h"
#include "String8Appendable.h"

cusobj_out_of_memory_error_factory_t cusobj_out_of_memory_error_factory = cusobj_default_out_of_memory_error_factory;

static const OutOfMemoryErrorVTable vtable = {
	.Error = {
		.Object = {
			.destroyWhole = OutOfMemoryError_destroyWhole
		},
		.Object_displace = (ptrdiff_t)0,
		.printMessage8To = OutOfMemoryError_printMessage8To
	},
	.Error_displace = (ptrdiff_t)0
};

static OutOfMemoryError singleton = {
	.vtable = &vtable,
	.Error = {},
	.OutOfMemoryError = {}
};

Error *const singleton_OutOfMemoryError = (Error*)&singleton;

void OutOfMemoryError_destroyWhole(
	const Object *error,
	Error** exception
) {
	OutOfMemoryError *outOfMemory;
	/* TODO: perform proper downcast */
	outOfMemory = (OutOfMemoryError*)error;
	OutOfMemoryErrorFacet_destroy(&outOfMemory->OutOfMemoryError, exception);
	if(*exception)
		return;
	ErrorFacet_destroy(&outOfMemory->Error, exception);
}

void OutOfMemoryError_printMessage8To(
	CUSOBJ_UNUSED(const Error*, error),
	Error** exception,
	String8Appendable *sink
) {
	sink->vtable->appendString(sink, exception, "Out of memory");
}

Error *cusobj_default_out_of_memory_error_factory(void) {
	return singleton_OutOfMemoryError;
}
