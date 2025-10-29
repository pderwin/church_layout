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
