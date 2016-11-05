#ifndef WOMBATSAY_TYPES
#define WOMBATSAY_TYPES

struct wombats_sentence {
  int linecount;
  char **lines;
};

struct speechbubble_t {
  int linecount;
  char *overline;
  char *underline;
  char **speechlines;
};
#endif /* ifndef WOMBATSAY_TYPES*/
