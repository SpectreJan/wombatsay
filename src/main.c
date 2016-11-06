#include "string_operations.h"
#include "drawing_operations.h"
#include "wombat_operations.h"
#include "wombatsay_types.h"
#include "wombatsay_constants.h"

#include "stdio.h"
#include "string.h"

int main(int argc, char *argv[])
{

  char *line = NULL;
  if(argc == 1) {
    printf("What does the wombat say?\n");
    line = parse_user_input();
  }
  else if(argc > 1) {
    line = parse_argv(argv, argc);
  }

  if(line == NULL) {
    printf("Error: Wombat cannot say that :(\n");
    return -1;
  }

  if(strlen(line) > MAX_SENTENCE_LEN) {
    fprintf(stderr, "Error: Sentence too long\n");
    fprintf(stderr, "       Our wombat is too dumb to memorize it :(\n");
    cleanup_line(line);
    exit(1);
  }

  struct wombats_sentence sentence;
  // Allocate Buffer for the sentence lines
  divide_lines(&sentence, line);
  cleanup_line(line);

  struct speechbubble_t *speechbubble = generate_speechbubble(&sentence);

  cleanup_sentence(&sentence);

  draw_speechbubble(speechbubble);
  draw_wombat();

  cleanup_speechbubble(speechbubble);

  // Windows user like to click exes, so prevent the cmdline from vanishing
#if defined (_WIN32) || defined (_WIN64)
  int c = getc(stdin);
#endif

  return 0;
}
