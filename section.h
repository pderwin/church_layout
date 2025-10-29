#pragma once

#include <stdint.h>
#include "row.h"

typedef enum {
   JUSTIFY_LEFT,
   JUSTIFY_CENTER,
   JUSTIFY_RIGHT
} justify_e;

typedef struct section_s section_t;

struct section_s {

   char
       *name;

   uint32_t
       anchor_x,
       anchor_y;

   uint32_t
       width;

   uint32_t
       rotate;

   uint32_t
       chairs;

   justify_e
       justify;

   row_t
       *first_row,
       *last_row;

   section_t
       *next;
};


section_t *section_create       (void      *ap,
				 char      *name,
				 int32_t   rotate,
				 uint32_t  anchor_x,
				 uint32_t  anchor_y,
				 uint32_t  width,
				 justify_e justify);
row_t     *section_add_row      (section_t *sp, uint32_t count);
row_t     *section_add_row_split(section_t *sp, uint32_t count1, uint32_t count2);
