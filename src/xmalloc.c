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

#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include "common.h"
#include "error.h"

/* Don't use these function directly, instead use the
 * XMALLOC, XCALLOC, XREALLOC, and XFREE macros.
 */

void *
xmalloc (size_t num)
{
  void *new = malloc(num);
  if (!new)
    lv_fatal("Memory Exhausted!\n");
  return new;
}

void *
xrealloc (void *p, size_t num)
{
  void *new;

  if (!p)
    return xmalloc(num);

  new = realloc(p, num);
  if (!new)
    lv_fatal("Memory Exhausted!\n");

  return new;
}

void *
xcalloc (size_t num, size_t size)
{
  void *new = xmalloc(num * size);
  bzero(new, num * size);
  return new;
}
