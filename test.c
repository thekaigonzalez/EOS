#include "eos.h"

#include <assert.h>
#include <stdio.h>

int
main ()
{
  String s;
  eoK_token t;

  str_init (&s);

  str_add_char (&s, 'H');
  str_add_char (&s, 'e');
  str_add_char (&s, 'l');
  str_add_char (&s, 'l');
  str_add_char (&s, 'o');

  start (&s, &t); /* start at the beginning of the string */

  while (!(endof (&s, &t) == 0))
    {
      printf ("%c\n", this (&s, &t));
      move (&s, &t);
    }

  str_free (&s);
}
