#include <stdio.h>
#include "center.h"
#include "church_layout.h"
#include "left.h"
#include "right.h"
#include "section.h"
#include "subs.h"


int
    main(int argc, char *argv[])
{
   auditorium_t
      *ap = auditorium_create();;

   (void) argc;
   (void) argv;

#define MIDDLE (450)


   font("Helvetica-Bold", 14);

   setlinewidth(1);

   left_section_create  (ap);
   center_section_create(ap);
   right_section_create (ap);

   /*
    * Render the first page with the auditorium layout.
    */
   auditorium_render( ap );

   {
      char
	 str[80];

      gsave();

      font("Helvetica-Bold", 18);
      rotate(90);
      setlinewidth(1);

      text_center(MIDDLE, 560, "Southland Christian Church");
      text_center(MIDDLE, 540, "Richmond Road Campus");

      sprintf(str, "Auditorium chairs: %d", auditorium_chairs(ap) );
      text_center(MIDDLE, 520, str);

      grestore();
   }

   showpage();

}
