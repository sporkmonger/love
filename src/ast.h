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

typedef struct _expression {
  enum {
    self_type=1,
    number_type=2,
    string_literal_type=3,
    symbol_type=4,
    sequence_type=5,
    parenthetical_type=6,
    message_type=7
  } type;
} expression_t;

struct _stmt {
      enum { FunctionDef_kind=1, Return_kind=2, Yield_kind=3 } kind;
      union {
              struct {
                      identifier name;
                      arguments_ty args;
                      asdl_seq *body;
              } FunctionDef;

              struct {
                      expr_ty value;
              } Return;

              struct {
                      expr_ty value;
              } Yield;
      } v;
      int lineno;
    };
