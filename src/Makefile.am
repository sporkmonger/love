MAINTAINERCLEANFILES = Makefile.in

INCLUDES = -I$(top_builddir) -I$(top_builddir)/include \
  -I$(top_srcdir) -I$(top_srcdir)/include

BUILT_SOURCES = parser.h
AM_YFLAGS = -d
bin_PROGRAMS = love
love_SOURCES = main.c love.c love.h scanner.l parser.y
