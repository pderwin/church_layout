#include <stdio.h>
#include "church_layout.h"
#include "left.h"
#include "section.h"


#define LEFT_x       80
#define LEFT_FRONT_y 0
#define LEFT_REAR_y  200
#define LEFT_ROTATE  10
#define LEFT_WIDTH   DEFAULT_WIDTH

section_t *left_section_front_create(void *ap)
{
   section_t
      *sp;

   sp = section_create(ap,
		       "left-front",
		       LEFT_ROTATE,
		       LEFT_x,
		       LEFT_FRONT_y,
		       LEFT_WIDTH,
		       JUSTIFY_RIGHT);

   section_add_row(sp, 9);
   section_add_row(sp, 12);
   section_add_row(sp, 13);
   section_add_row(sp, 15);
   section_add_row(sp, 16);
   section_add_row(sp, 18);
   section_add_row_split(sp,  9,  8);
   section_add_row_split(sp, 10,  9);
   section_add_row_split(sp, 11, 10);
   section_add_row_split(sp, 12, 10);
   section_add_row_split(sp, 13, 11);
   section_add_row_split(sp, 13, 12);
   section_add_row_split(sp, 14, 13);
   section_add_row_split(sp, 15, 13);

   return sp;
}



section_t *left_section_rear_create( void *ap )
{
   section_t
      *sp;

   sp = section_create(ap,
		       "left-rear",
		       LEFT_ROTATE,
		       LEFT_x,
		       LEFT_REAR_y,
		       LEFT_WIDTH,
		       JUSTIFY_RIGHT);

   section_add_row_split(sp, 12, 13);
   section_add_row_split(sp, 13, 13);
   section_add_row_split(sp, 14, 13);
   section_add_row_split(sp, 14, 13);
   section_add_row_split(sp, 13, 13);
   section_add_row_split(sp, 13, 13);
   section_add_row_split(sp, 13, 13);
   section_add_row_split(sp, 12, 13);
   section_add_row_split(sp, 10, 13);
   section_add_row_split(sp, 10, 12);
   section_add_row_split(sp, 11, 12);
   section_add_row_split(sp, 10, 12);
   section_add_row_split(sp, 10, 11);
   section_add_row_split(sp,  8,  7);
   section_add_row_split(sp,  9,  5);
   section_add_row_split(sp,  8,  0);
   section_add_row_split(sp,  7,  0);

   return sp;
}

void left_section_create(void *ap)
{
   left_section_front_create(ap);
   left_section_rear_create(ap);
}
