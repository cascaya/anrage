PHP_FUNCTION(strflip) 
{
    char *utf8str;
    int utf8strlen;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &utf8str, &utf8strlen) == FAILURE) {
            RETURN_NULL();
    }
    strrev_utf8(utf8str);
    
    RETURN_STRING(utf8str, utf8strlen);
}
#include <bits/types.h>
#include <stdio.h> 

#define SWP(x,y) (x^=y, y^=x, x^=y)

void strrev(char *p)
{
  char *q = p;
  while(q && *q) ++q; /* find eos */
  for(--q; p < q; ++p, --q) SWP(*p, *q);
}

void strrev_utf8(char *p)
{
  char *q = p;
  strrev(p); /* call base case */

  /* Ok, now fix bass-ackwards UTF chars. */
  while(q && *q) ++q; /* find eos */
  while(p < --q)
    switch( (*q & 0xF0) >> 4 ) {
    case 0xF: /* U+010000-U+10FFFF: four bytes. */
      SWP(*(q-0), *(q-3));
      SWP(*(q-1), *(q-2));
      q -= 3;
      break;
    case 0xE: /* U+000800-U+00FFFF: three bytes. */
      SWP(*(q-0), *(q-2));
      q -= 2;
      break;
    case 0xC: /* fall-through */
    case 0xD: /* U+000080-U+0007FF: two bytes. */
      SWP(*(q-0), *(q-1));
      q--;
      break;
    }
}
