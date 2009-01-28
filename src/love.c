/**********************************************************************
# Love, Copyright (c) 2009 Bob Aman
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "error.h"

static void
usage(const char *name)
{
  /* This message really ought to be max 23 lines.
   * Removed -h because the user already knows that option. Others? */

  static const char *const usage_msg[] = {
    "-c              check syntax only",
    "-d              set debugging flags (set DEBUG to true)",
    "-e 'command'    executes a single line command",
    "-w              turn warnings on for your script",
    "-W[level]       set warning level (0=silence, 1=medium, 2=verbose)",
    "--copyright     print the copyright",
    "--version       print the version",
    NULL
  };
  const char *const *p = usage_msg;

  printf("Usage: %s [switches] [--] [programfile] [arguments]\n", name);
  while (*p) {
    printf("  %s\n", *p++);
  }
}
