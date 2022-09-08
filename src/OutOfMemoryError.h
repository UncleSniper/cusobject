#ifndef CUSOBJECT_OUTOFMEMORYERROR_H
#define CUSOBJECT_OUTOFMEMORYERROR_H

#include "Error.h"

struct OutOfMemoryError;
struct String8Appendable;

typedef struct OutOfMemoryErrorVTable {
	ErrorVTable Error;
	ptrdiff_t Error_displace;
} OutOfMemoryErrorVTable;

typedef struct OutOfMemoryErrorFacet {
	ErrorFacet Error;
} OutOfMemoryErrorFacet;

typedef struct OutOfMemoryError {
	const OutOfMemoryErrorVTable *CUSOBJ_CONST vtable;
	OutOfMemoryErrorFacet OutOfMemoryError;
} OutOfMemoryError;

typedef Error *(*cusobj_out_of_memory_error_factory_t)(void);

extern cusobj_out_of_memory_error_factory_t cusobj_out_of_memory_error_factory;

extern Error *const singleton_OutOfMemoryError;

inline void OutOfMemoryErrorFacet_init(
	OutOfMemoryErrorFacet* error,
	Error** exception
) {
	ErrorFacet_init((ErrorFacet*)error, exception);
}

inline void OutOfMemoryErrorFacet_destroy(
	const OutOfMemoryErrorFacet* error,
	Error** exception
) {
	ErrorFacet_destroy((ErrorFacet*)error, exception);
}

void OutOfMemoryError_destroyWhole(
	const Object *error,
	Error** exception
);

void OutOfMemoryError_printMessage8To(
	const Error *error,
	Error **exception,
	struct String8Appendable *sink
);

Error *cusobj_default_out_of_memory_error_factory(void);

#endif /* CUSOBJECT_OUTOFMEMORYERROR_H */
