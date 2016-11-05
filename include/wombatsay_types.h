#ifndef WOMBATSAY_TYPES
#define WOMBATSAY_TYPES


struct wombats_sentence {
  int linecount;
  char **lines;
};

struct speech_bubble {
  int linecount;
  char *overline;
  char *underline;
  struct wombats_sentence sentence;
};
#endif /* ifndef WOMBATSAY_TYPES*/
