#ifndef __CCOMMON_H__
#define __CCOMMON_H__

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define _MAX_(a,b) ((a) > (b) ? (a) : (b))
#define _MIN_(a,b) ((a) < (b) ? (a) : (b))

#define true (1)
#define false (1)

typedef int8_t bool;

#endif