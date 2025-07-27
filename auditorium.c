#include <stdio.h>
#include <stdlib.h>
#include "auditorium.h"
#include "row.h"
#include "section.h"
#include "subs.h"

uint32_t auditorium_chairs (auditorium_t *ap)
{
   uint32_t
      chairs = 0;
   section_t
      *sp;

   /*
    * Roll through each section and render it on the page
    */
   for (sp = ap->first_section; sp; sp = sp->next) {
      chairs += sp->chairs;
   }

   return chairs;
}

auditorium_t *auditorium_create (void)
{
   auditorium_t
      *ap;

   ap = calloc (1, sizeof(auditorium_t) );

   if (ap == NULL) {
      fprintf(stderr, "%s: Error allocating auditorium\n", __func__);
      exit(1);
   }

   return ap;
}

void auditorium_render (auditorium_t *ap)
{
   uint32_t
      row_y;
   row_t
      *rp;
   section_t
      *sp;

   pagesize(612, 1008);
   translate(590,0);


   /*
    * Roll through each section and render it on the page
    */
   for (sp = ap->first_section; sp; sp = sp->next) {

      gsave();
      rotate(sp->rotate);

      /*
       * Draw a box representing the section
       */
      box(sp->anchor_x, sp->anchor_y, 100, 10);

      /*
       * Put out section name
       */
      text_at(sp->anchor_x, sp->anchor_y, sp->name);

      /*
       * Draw each row
       */
      row_y = sp->anchor_y;

      /*
       * Increment Y to avoid overwrite of section name
       */
      row_y += 20;

      for (rp = sp->first_row; rp; rp = rp->next) {

	 row_render(rp, sp->anchor_x, row_y);

	 row_y += 10;
      }

      grestore();
   }

   showpage();
}


void auditorium_section_add(void *_ap, section_t *sp)
{
   auditorium_t *ap = _ap;

   if (ap->first_section) {
      ap->last_section->next = sp;
   }
   else {
      ap->first_section = sp;
   }

   ap->last_section = sp;
}
