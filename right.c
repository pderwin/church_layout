#include <stdio.h>
#include "right.h"
#include "section.h"
#include "subs.h"

#define RIGHT_x        700
#define RIGHT_FRONT_y  150
#define RIGHT_REAR_y   (RIGHT_FRONT_y + 200)
#define RIGHT_ROTATE   -10

section_t *right_section_front_create( auditorium_t *ap )
{
   section_t
      *sp;

   sp = section_create(ap, "right-front", RIGHT_ROTATE, RIGHT_x, RIGHT_FRONT_y);

   section_add_row(sp, 9);
   section_add_row(sp, 11);
   section_add_row(sp, 13);
   section_add_row(sp, 14);
   section_add_row(sp, 16);
   section_add_row_split(sp, 8, 7);
   section_add_row_split(sp, 9, 9);
   section_add_row_split(sp, 9, 10);
   section_add_row_split(sp, 10, 11);
   section_add_row_split(sp, 10, 12);
   section_add_row_split(sp, 11, 14);
   section_add_row_split(sp, 12, 15);
   section_add_row_split(sp, 12, 15);
   section_add_row_split(sp, 13, 16);

   return sp;
}



void right_section_rear_create( auditorium_t *ap )
{
   section_t
      *sp;

   sp = section_create(ap, "right-rear", RIGHT_ROTATE, RIGHT_x, RIGHT_REAR_y);

   section_add_row_split(sp, 13, 14);
   section_add_row_split(sp, 13, 14);
   section_add_row_split(sp, 13, 14);
   section_add_row_split(sp, 13, 13);
   section_add_row_split(sp, 13, 13);
   section_add_row_split(sp, 13, 13);
   section_add_row_split(sp, 13, 12);
   section_add_row_split(sp, 13, 11);
   section_add_row_split(sp, 13,  9);
   section_add_row_split(sp, 13, 10);
   section_add_row_split(sp, 12, 10);
   section_add_row_split(sp, 11,  9);
   section_add_row_split(sp, 11,  9);
   section_add_row_split(sp,  7,  7);
   section_add_row_split(sp,  6,  8);
   section_add_row_split(sp,  0,  8);
}

void right_section_create( auditorium_t *ap )
{
   right_section_front_create(ap);
   right_section_rear_create(ap);
}
