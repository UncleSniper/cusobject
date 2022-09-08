#include "Object.h"

void Object_setVTable(
	Object *object,
	const ObjectVTable *vtable
) {
	object->vtable = vtable;
}

void cusobj_destroy(
	const Object *object,
	Error **exception
) {
	if(!object)
		return;
	object->vtable->destroyWhole(object, exception);
}

void cusobj_delete(
	Object *object,
	Error **exception
) {
	if(!object)
		return;
	object->vtable->destroyWhole(object, exception);
	if(*exception)
		return;
	free(object);
}
