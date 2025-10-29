#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auditorium.h"
#include "section.h"


static row_t *row_add (section_t *sp)
{
   row_t
      *rp = malloc(sizeof(row_t));

   if (!rp) {
      printf("%s: error allocating row\n", __func__);
      exit(1);
   }

   if (sp->first_row) {
      sp->last_row->next = rp;
   }
   else {
      sp->first_row = rp;
   }

   sp->last_row = rp;

   rp->next = NULL;

   return rp;
}

row_t *section_add_row(section_t *sp, uint32_t count)
{
   return section_add_row_split(sp, count, 0);
}

row_t *section_add_row_split(section_t *sp, uint32_t count1, uint32_t count2)
{
   row_t
      *rp;

   rp = row_add(sp);

   rp->count1 = count1;
   rp->count2 = count2;

   sp->chairs += (count1 + count2);

   return rp;
}

section_t *section_create (void      *ap,
			   char      *name,
			   int32_t   rotate,
			   uint32_t  anchor_x,
			   uint32_t  anchor_y,
			   uint32_t  width,
			   justify_e justify)
{
   section_t
      *sp;

   sp = calloc (1, sizeof(section_t));

   if (!sp) {
      printf("%s: error allocating section\n", __func__);
      exit(1);
   }

   auditorium_section_add(ap, sp);

   sp->name     = strdup(name);
   sp->anchor_x = anchor_x;
   sp->anchor_y = anchor_y;
   sp->width    = width;
   sp->rotate   = rotate + 90;
   sp->justify  = justify;

   return sp;
}
