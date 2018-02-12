/*
 * Описание прототипов в соответствии с C Coding Standard
 * Micrium, Inc. http://www.micrium.com
 * mailto: Jean.Labrosse@Micrium.com
 */ 

#ifndef _TYPEDEF_H
#define _TYPEDEF_H 1

typedef unsigned char BOOLEAN;     /* Logical data type (TRUE or FALSE)   */
typedef unsigned char INT8U;      /* Unsigned  8 bit value               */
typedef signed   char INT8S;      /* Signed    8 bit value               */
typedef unsigned int  INT16U;     /* Unsigned 16 bit value               */
typedef signed   int  INT16S;     /* Signed   16 bit value               */
typedef unsigned long INT32U;     /* Unsigned 32 bit value               */
typedef signed   long INT32S;     /* Signed   32 bit value               */
/* typedef unsigned long INT64U;     /* Unsigned 64 bit value (if available)*/
/* typedef signed   long INT64S;     /* Signed   64 bit value (if available)*/
typedef float         FP32;       /* 32 bit, single prec. floating-point */
typedef double        FP64;       /* 64 bit, double prec. floating-point */

#endif
