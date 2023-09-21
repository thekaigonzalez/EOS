#include "eos.h"

char
next (String *s, eoK_token *T)
{
  return T->__next;
}

char
last (String *s, eoK_token *T)
{
  return T->__previous;
}

char
move (String *s, eoK_token *T)
{
  if (T->__next_exists != -1)
    {
      T->__previous = str_at (s, T->__op);
      T->__op++;
      T->__self = str_at (s, T->__op);
      trip (s, T);
    }
  return 0;
}

void
start (String *s, eoK_token *T)
{
  if (str_length (s) > 0)
    {
      T->__self = str_at (s, 0);
      T->__op = 0;

      trip (s, T);

      // leave out next and previous
    }
}

int
trip (String *s, eoK_token *T)
{
  if ((str_length (s) > T->__op + 1))
    {
      T->__next = str_at (s, T->__op + 1);
      T->__next_exists = T->__op + 1;
    }
  return 0;
}

int
endof (String *s, eoK_token *T)
{
  if (str_at (s, T->__op) == str_at (s, str_length (s)))
    return 0;
  else
    return -1;
}

char this (String *s, eoK_token *T) { return str_at (s, T->__op); }
