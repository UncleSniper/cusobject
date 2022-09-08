#ifndef CUSOBJECT_API_H
#define CUSOBJECT_API_H

#ifdef BULIDING_CUSOBJECT_API
#define CUSOBJ_CONST
#else /* !BULIDING_CUSOBJECT_API */
#define CUSOBJ_CONST const
#endif /* BULIDING_CUSOBJECT_API */

#ifdef __GNUC__
#define CUSOBJ_UNUSED(type, name) __attribute__((unused)) type name
#else /* unknown compiler */
#define CUSOBJ_UNUSED(type, name) type name
#endif /* compiler */

#endif /* CUSOBJECT_API_H */
