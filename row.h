#pragma once

#include <stdint.h>

typedef struct row_s row_t;

struct row_s {

   uint32_t
       count1,
       count2;

   row_t
       *next;
};

void row_render           (uint32_t x, uint32_t y, uint32_t count );
void row_render_backwards (uint32_t x, uint32_t y, uint32_t count );
