#pragma once

#include <stdint.h>
#include "section.h"

typedef struct {
   section_t
       *first_section,
       *last_section;
} auditorium_t;

uint32_t      auditorium_chairs     (auditorium_t *ap);
auditorium_t *auditorium_create     (void);
void          auditorium_render     (auditorium_t *ap);
void          auditorium_section_add(void *ap, section_t *sp);
