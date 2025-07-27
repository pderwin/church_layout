#include <stdio.h>
#include "center.h"
#include "section.h"

#define CENTER_x       400
#define CENTER_FRONT_y 30
#define CENTER_REAR_y  (CENTER_FRONT_y + 200)
#define CENTER_ROTATE  0

section_t *center_section_front_create( void *ap )
{
   section_t
      *sp;

   sp = section_create( ap, "center-front", CENTER_ROTATE, CENTER_x, CENTER_FRONT_y);

   section_add_row_split(sp, 8,   8);
   section_add_row_split(sp, 8,   8);
   section_add_row_split(sp, 8,   8);
   section_add_row_split(sp, 9,   8);
   section_add_row_split(sp, 10,  8);
   section_add_row_split(sp, 10,  9);
   section_add_row_split(sp, 10,  9);
   section_add_row_split(sp, 11, 10);
   section_add_row_split(sp, 11, 11);
   section_add_row_split(sp, 11, 11);
   section_add_row_split(sp,  0,  7);
   section_add_row_split(sp,  0,  7);
   section_add_row_split(sp,  0,  7);

   /*
    * Need to add two cameras and production booth
    */
   return sp;
}



section_t *center_section_rear_create( void *ap )
{
   section_t
      *sp;

   sp = section_create(ap, "center-rear", CENTER_ROTATE, CENTER_x, CENTER_REAR_y);

   section_add_row_split(sp, 13, 13);
   section_add_row_split(sp, 14, 13);
   section_add_row_split(sp, 14, 14);
   section_add_row_split(sp, 14, 14);
   section_add_row_split(sp, 14, 14);
   section_add_row_split(sp, 15, 15);
   section_add_row_split(sp, 15, 15);
   section_add_row_split(sp, 15, 15);
   section_add_row_split(sp, 15, 15);
   section_add_row_split(sp, 14, 14);
   section_add_row_split(sp, 13, 13);
   section_add_row_split(sp,  4, 12);

   /*
    * This should be 6 and 3 on the right side with a post between them
    */
   section_add_row_split(sp,  3,  6);

   return sp;
}

void center_section_create( void *ap )
{
   center_section_front_create( ap );
   center_section_rear_create ( ap );
}
