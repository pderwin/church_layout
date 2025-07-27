cmake_minimum_required(VERSION 3.22)

project(church_layout)

# set(CMAKE_VERBOSE_MAKEFILE ON)

add_compile_options(-Wall -Werror -Wextra )


add_executable(church_layout
	auditorium.c
	center.c
	church_layout.c
	left.c
	right.c
	row.c
	section.c
	subs.c
  )

include_directories( . )
