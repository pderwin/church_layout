#include "row.h"
#include "subs.h"

#define CHAIR_DELTA (7)

void row_render (uint32_t x, uint32_t y, uint32_t count )
{
   uint32_t
      i;

   newpath();

   x += CHAIR_DELTA;

   for (i=0; i < count; i++) {
      circle(x, y, 2);

      x += CHAIR_DELTA;
   }
}

void row_render_backwards (uint32_t x, uint32_t y, uint32_t count )
{
   uint32_t
      i;

   newpath();

   x -= CHAIR_DELTA;

   for (i=0; i < count; i++) {
      circle(x, y, 2);

      x -= CHAIR_DELTA;
   }
}
