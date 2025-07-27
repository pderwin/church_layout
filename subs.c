#include <stdint.h>
#include <stdio.h>

#include "subs.h"

void box(uint32_t x, uint32_t y, uint32_t h, uint32_t w)
{
   line(x,     y,   x, y+h);
   line(x,   y+h, x+w, y+h);
   line(x+w, y+h, x+w,   y);
   line(x,     y, x+w,   y);
}

void circle(uint32_t x, uint32_t y, uint32_t radius)
{
   printf("%d %d %d 0 360 arc closepath gsave stroke grestore \n 0 setgray fill\n", x, y, radius);
}

void font (char *font_name, uint32_t size)
{
   printf("/%s findfont\n", font_name);
   printf("%d scalefont setfont\n", size);
}

void grestore     (void)
{
   printf("grestore\n");
}

void gsave        (void)
{
   printf("gsave\n");
}

void line (uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1)
{
   move_to(x0, y0);
   line_to(x1, y1);
   stroke();
}

void line_to (uint32_t x, uint32_t y)
{
   printf("%d %d lineto\n", x, y);
}

void move_to (uint32_t x, uint32_t y)
{
   printf("%d %d moveto\n", x, y);
}

void pagesize(uint32_t w, uint32_t h)
{
   printf("<< /PageSize [%d %d] >> setpagedevice\n", w, h);
}
void rotate (uint32_t degrees)
{
   printf("%d rotate\n", degrees);
}

void scale (uint32_t x, uint32_t y)
{
   printf("%d %d scale\n", x, y);
}

void setlinewidth (uint32_t w)
{
   printf("%d setlinewidth\n", w);
}

void showpage(void)
{
   printf("showpage\n");
}

void stroke (void)
{
   printf("stroke\n");
}

void text_at (uint32_t x, uint32_t y, char *str)
{
   printf("%d %d moveto\n", x, y);
   printf("(%s) show\n", str);
}


void translate (uint32_t x, uint32_t y)
{
   printf("%d %d translate\n", x, y);
}
