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
   (void) argc;
   (void) argv;

   auditorium_t
      *ap = auditorium_create();;

#define MIDDLE (450)

   gsave();
   font("Helvetica-Bold", 18);
   rotate(90);
   setlinewidth(1);
   text_center(MIDDLE, -30, "Southland Christian Church");
   text_center(MIDDLE, -50, "Richmond Road Campus");
   grestore();

   font("Helvetica-Bold", 14);

   setlinewidth(1);

   left_section_create  (ap);
   center_section_create(ap);
   right_section_create (ap);

   /*
    * Render the first page with the auditorium layout.
    */
   auditorium_render( ap );

   fprintf(stderr, "Auditorium chairs: %d \n", auditorium_chairs(ap) );

}
