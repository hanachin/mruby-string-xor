/*
** mrb_string_xor.c - String#xor
**
** Copyright (c) Seiei Miyagi 2017
**
** See Copyright Notice in LICENSE
*/

#include <mruby.h>
#include <mruby/string.h>
#include "mrb_string_xor.h"


#define DONE mrb_gc_arena_restore(mrb, 0);

static mrb_value
string_xor(mrb_state *mrb, mrb_value self)
{
  mrb_value s, str2;
  mrb_int len;
  char *p, *pend, *p2;

  len = RSTRING_LEN(self);
  mrb_get_args(mrb, "S", &str2);
  if (len != RSTRING_LEN(str2)) {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "string length does not match");
  }
  s = mrb_str_dup(mrb, self);
  p = RSTRING_PTR(s);
  p2 = RSTRING_PTR(str2);
  pend = RSTRING_END(s);
  while (p < pend) {
    *p ^= *p2;
    p++;
    p2++;
  }
  return s;
}

void
mrb_mruby_string_xor_gem_init(mrb_state* mrb)
{
  struct RClass * s = mrb->string_class;
  mrb_define_method(mrb, s, "^", string_xor, MRB_ARGS_REQ(1));
  DONE;
}

void
mrb_mruby_string_xor_gem_final(mrb_state* mrb)
{
}
