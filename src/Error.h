#ifndef CUSOBJECT_ERROR_H
#define CUSOBJECT_ERROR_H

#include "Object.h"

struct String8Appendable;

typedef void (*ErrorMethod_printMessage8To)(
	const struct Error *error,
	struct Error **exception,
	struct String8Appendable *sink
);

typedef struct ErrorVTable {
	ObjectVTable Object;
	ptrdiff_t Object_displace;
	ErrorMethod_printMessage8To printMessage8To;
} ErrorVTable;

typedef struct ErrorFacet {
	/* interface */
} ErrorFacet;

typedef struct Error {
	const ErrorVTable *CUSOBJ_CONST vtable;
	ErrorFacet Error;
} Error;

inline void ErrorFacet_init(
	CUSOBJ_UNUSED(ErrorFacet*, error),
	CUSOBJ_UNUSED(Error**, exception)
) {
	/* no fields */
}

inline void ErrorFacet_destroy(
	CUSOBJ_UNUSED(const ErrorFacet*, error),
	CUSOBJ_UNUSED(Error**, exception)
) {
	/* no fields */
}

#include "OutOfMemoryError.h"

#endif /* CUSOBJECT_ERROR_H */
