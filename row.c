#include "row.h"
#include "subs.h"

void row_render (row_t *rp, uint32_t x, uint32_t y )
{
   uint32_t
      i;

   for (i=0; i< rp->count1 + rp->count2; i++) {
      circle(x, y, 2);

      x += 8;
   }


}
