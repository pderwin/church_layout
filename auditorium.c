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
   char
      str[80];
   uint32_t
      row_x,
      row_y;
   row_t
      *rp;
   section_t
      *sp;

//   pagesize(612, 1008);
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
//      box(sp->anchor_x, sp->anchor_y, 100, sp->width);

      /*
       * Put out section name and chair count
       */
      sprintf(str, "%s (%d)", sp->name, sp->chairs);

      text_at(sp->anchor_x, sp->anchor_y + 5, str);

      newpath();
      font("Helvetica-Bold", 8);

      /*
       * Draw each row
       */
      row_y = sp->anchor_y;

      /*
       * Increment Y to avoid overwrite of section name
       */
      row_y += 25;

      for (rp = sp->first_row; rp; rp = rp->next) {

	 switch (sp->justify) {
	     case JUSTIFY_LEFT:

		if (rp->count1) {
		   sprintf(str, "%2d", rp->count1);
		   text_at(sp->anchor_x, row_y, str);

		   row_render(sp->anchor_x+12, row_y, rp->count1);
		}

		if (rp->count2) {

		   row_x = sp->anchor_x + (sp->width / 2);

		   sprintf(str, "%2d", rp->count2);
		   text_at(row_x, row_y, str);

		   row_render(row_x + 12, row_y, rp->count2);
		}
	     default:
	 }
//	 row_render(rp, sp->anchor_x, row_y);

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
