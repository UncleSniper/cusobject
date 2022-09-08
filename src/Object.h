#ifndef CUSOBJECT_OBJECT_H
#define CUSOBJECT_OBJECT_H

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#include "api.h"

struct Object;
struct Error;

typedef void (*ObjectMethod_destroyWhole)(
	const struct Object *object,
	struct Error **exception
);

typedef struct ObjectVTable {
	ObjectMethod_destroyWhole destroyWhole;
} ObjectVTable;

typedef struct Object {
	const ObjectVTable *CUSOBJ_CONST vtable;
} Object;

void Object_setVTable(
	Object *object,
	const ObjectVTable *vtable
);

void cusobj_destroy(
	const Object *object,
	struct Error **exception
);

void cusobj_delete(
	Object *object,
	struct Error **exception
);

#include "Error.h"
#include "memory.h"

#endif /* CUSOBJECT_OBJECT_H */
