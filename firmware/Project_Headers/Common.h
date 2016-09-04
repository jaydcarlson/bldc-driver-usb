/*! \file
    \brief Some common shared defintions.
*/
#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdint.h>


typedef uint8_t    U8;   //!< unsigned 8-bit value
typedef uint16_t   U16;  //!< unsigned 16-bit value
typedef uint32_t   U32;  //!< unsigned 32-bit value
////! 24-bit value
//typedef struct {
//	char data[3]; //!< 3 bytes representing the value
//} U24;  //!< unsigned 24-bit value
typedef uint32_t U32;  //!< unsigned 32-bit value
typedef int8_t   S8;   //!< signed 8-bit value
typedef int16_t  S16;  //!< signed 16-bit value
typedef int32_t  S32;  //!< signed 32-bit value

//! Used for manipulating Little/Big-Endian longwords (32 bits)
//!
typedef union {
    U32 longword;          //!< Treat as native 32-bit value
    U8  bytes[4];          //!< Treat as array of bytes
} U32u;

//! Used for manipulating Little/Big-Endian words (16 bits)
//!
typedef union {
    U8  bytes[2];                //!< Treat as array of bytes
    U16 word;                    //!< Treat as native 16-bit value
    struct {U8 lo; U8 hi;} le;   //!< Little-endian order
    struct {U8 hi; U8 lo;} be;   //!< Big-endian order
} U16u;


// Macros only for use with literals!
//! Convert Native constant to 32-bit Little-Endian
#define CONST_NATIVE_TO_LE32(x) (x)
//! Convert Native constant to 32-bit Big-Endian
#define CONST_NATIVE_TO_BE32(x) ((((x)<<24)&0xFF000000)+(((x)<<8)&0xFF0000)+(((x)>>8)&0xFF00)+(((x)>>24)&0xFF))
//! Convert Native constant to 16-bit Little-Endian
#define CONST_NATIVE_TO_LE16(x) (x)
//! Convert Native constant to 12-bit Big-Endian
#define CONST_NATIVE_TO_BE16(x) (((((x)&0xFF))<<8)+(((x)>>8)&0xFF))

#define LE_TO_NATIVE16(x) (x)


#define disableInterrupts()   asm("nop");         //!< Disable all interrupts
#define enableInterrupts()    asm("nop");         //!< Enable interrupts
#define waitForInterrupts()   asm("wfi")          //!< Low power until in happens
#define backgroundDebugMode()    asm("bkpt  0");  //!< Enter Background Debug Mode


#ifndef FALSE
//! False!
#define FALSE 0
#endif

#ifndef TRUE
//! True!
#define TRUE 1
#endif

#define __LITTLE_ENDIAN__

#ifdef __GNUC__
#define __forceinline __attribute__((always_inline))
#endif

typedef int Boolean;

#endif //_COMMON_H_
