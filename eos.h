// Copyright 2020-2023 Kai D. Gonzalez

#include "string.h"

#define EOS_CHAR '\0'

typedef struct __eostoken
{
  char __self;     /* the current character */
  char __next;     /* the next character */
  char __previous; /* the previous character*/

  int __next_exists; /* does the next character exist?*/
  int __op;          /* dont worry about this value for now*/
} eoK_token;

char next (String *s, eoK_token *T); /* returns the next character   */
char last (String *s, eoK_token *T); /* returns the last character   */
char move (String *s, eoK_token *T); /* moves to the next character, handling
                                        self, next and previous      */
char this (String *s, eoK_token *T); /* returns the current character*/

void start (String *s, eoK_token *T);

int trip (String *s, eoK_token *T); /* set __next to the next        character -> set
                                       __next_exists too*/
int endof (String *s,
           eoK_token *T); /* returns 0 if we've hit the end of       the string -
                             need to fix - this way checks if        the character is
                             the last in the entire string*/
