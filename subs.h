#pragma once

#include <stdint.h>

void box          (uint32_t x, uint32_t y, uint32_t h, uint32_t w);
void circle       (uint32_t x, uint32_t y, uint32_t radius);
void font         (char *name, uint32_t size);
void grestore     (void);
void gsave        (void);
void line         (uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1);
void line_to      (uint32_t x, uint32_t y);
void move_to      (uint32_t x, uint32_t y);
void newpath      (void);
void pagesize     (uint32_t w, uint32_t h);
void rotate       (uint32_t degrees);
void scale        (uint32_t x, uint32_t y);
void setlinewidth (uint32_t w);
void showpage     (void);
void stroke       (void);
void text_at      (uint32_t x, uint32_t y, char *str);
void translate    (uint32_t x, uint32_t y);
