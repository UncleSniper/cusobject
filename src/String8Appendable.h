#ifndef CUSOBJECT_STRING8APPENDABLE_H
#define CUSOBJECT_STRING8APPENDABLE_H

#include "Error.h"

struct String8Appendable;

typedef void (*String8AppendableMethod_appendString)(
	struct String8Appendable *appendable,
	Error **exception,
	const char *string
);

typedef struct String8AppendableVTable {
	ObjectVTable Object;
	ptrdiff_t Object_displace;
	String8AppendableMethod_appendString appendString;
} String8AppendableVTable;

typedef struct String8AppendableFacet {
	/* interface */
} String8AppendableFacet;

typedef struct String8Appendable {
	const String8AppendableVTable *CUSOBJ_CONST vtable;
	String8AppendableFacet String8Appendable;
} String8Appendable;

inline void String8AppendableFacet_init(
	CUSOBJ_UNUSED(String8AppendableFacet*, appendable),
	CUSOBJ_UNUSED(Error**, exception)
) {
	/* no fields */
}

inline void String8AppendableFacet_destroy(
	CUSOBJ_UNUSED(const String8AppendableFacet*, appendable),
	CUSOBJ_UNUSED(Error**, exception)
) {
	/* no fields */
}

#endif /* CUSOBJECT_STRING8APPENDABLE_H */
