#include "string_operations.h"
#include "wombatsay_constants.h"
#include "wombat_operations.h"

#include "string.h"
#include "ctype.h"

/******************************************************************************/
char*
parse_argv(char **argv, int argc)
{

  int i = 0;
  int total_str_size = 0;
  for (i = 1; i < argc; ++i) {
    total_str_size += strlen(argv[i]) + 1;
  }

  total_str_size -= 1;

  /*printf("Total String size: %d\n", total_str_size);*/

  char *line = (char*) malloc(total_str_size);

  if(line == NULL)
    return NULL;

  line[0] = '\0';

  for (i = 1; i < argc-1; ++i) {
    strcat(line, argv[i]);
    strcat(line, " ");
  }

  strcat(line, argv[i]);

  /*printf("Line: %s\n", line);*/

  return line;

}

/******************************************************************************/
char*
parse_user_input()
{
  char *line = NULL;

  int max = 128;

  line = (char*) malloc(max);

  if(line == NULL)
    no_mem();

  // Pos counter in the linebuffer
  int i = 0;
  // Check for leading whitespaces
  int c = 0;
  while(1) {
    c = getchar();
    if(c == EOF)
      break;
    if(!isspace(c)) {
      line[i] = c;
      i++;
      break;
    }
  }

  // Now get the real sentence
  while(1) {

    c = getchar();
    if(c == EOF || c == '\n') {
      line[i] = '\0';
      break;
    }

    line[i] = c;

    // The buffer is getting full, we need to reallocate
    if(i == max-1) {
      max += max;
      line = (char*) realloc(line, max);
      if(line == NULL)
        no_mem();
    }

    i++;
  }

  /*fprintf(stdout, "The line is %s\n", line);*/


  return line;
}

/******************************************************************************/
void
divide_lines(struct wombats_sentence *sentence, char *line)
{

  // TODO Multiline support
  // Get length of the user input sentence
/*
 *  int line_len = strlen(line);
 *
 *  fprintf(stdout, "The line is %d long\n", line_len);
 *
 *  int lines = 1;
 *
 *  if(line_len > MAX_SENTENCE_LEN) {
 *    lines = (int) (1.0*line_len/MAX_SENTENCE_LEN + 0.5);
 *  }
 *
 *  if(res != 0) {
 *    cleanup_line(line);
 *    exit(1);
 *  }
 *
 *  fprintf(stdout, "We have %d lines\n", lines);
 */
  int res = malloc_wombats_sentences_buffer(sentence, 1);
  if(res != 0) {
    cleanup_line(line);
    exit(1);
  }

  strcpy(sentence->lines[0], line);

  /*printf("The sentence is %s\n", sentence->lines[0]);*/

}

/******************************************************************************/
struct speechbubble_t*
generate_speechbubble(struct wombats_sentence *sentence)
{
  struct speechbubble_t *bubble = (struct speechbubble_t*) malloc(sizeof(struct speechbubble_t));

  bubble->speechlines = (char**) malloc(sentence->linecount*sizeof(char*));
  for (int i = 0; i < sentence->linecount; ++i) {
    bubble->speechlines[i] = (char*) malloc(strlen(sentence->lines[0])+BUBBLE_OVERHEAD);
    /*bubble->speechlines[i] = " < \0";*/
    strcpy(bubble->speechlines[i], " < ");
    strcat(bubble->speechlines[i], sentence->lines[i]);
    /*strcat(bubble->speechlines[i], sentence->lines[0]);*/
    strcat(bubble->speechlines[i], " >");
  }
  bubble->linecount = sentence->linecount;
  bubble->overline = (char*) malloc(strlen(sentence->lines[0])+BUBBLE_OVERHEAD);
  bubble->underline = (char*) malloc(strlen(sentence->lines[0])+BUBBLE_OVERHEAD);

  memset(bubble->overline, 0, strlen(sentence->lines[0])+BUBBLE_OVERHEAD);
  memset(bubble->underline, 0, strlen(sentence->lines[0])+BUBBLE_OVERHEAD);

  strcpy(bubble->overline, "  ");
  strcpy(bubble->underline, "  ");
  memset(bubble->overline+2, '_', strlen(sentence->lines[0])+2);
  memset(bubble->underline+2, '-', strlen(sentence->lines[0])+2);

  return bubble;
}

/******************************************************************************/
void
cleanup_line(char *line)
{
  if(line != NULL) {
    free(line);
    line = NULL;
  }
}

void
cleanup_speechbubble(struct speechbubble_t *speechbubble)
{
  if(speechbubble != NULL) {
    free(speechbubble->overline);
    free(speechbubble->underline);

    for (int i = 0; i < speechbubble->linecount; ++i) {
      free(speechbubble->speechlines[i]);
      speechbubble->speechlines[i] = NULL;
    }

    free(speechbubble->speechlines);
    speechbubble->speechlines = NULL;

    free(speechbubble);
    speechbubble = NULL;

  }

}
