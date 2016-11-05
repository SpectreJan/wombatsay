#include "wombat_operations.h"
#include "wombatsay_constants.h"

#include "stdio.h"
#include "stdlib.h"

/*****************************************************************************/
int
malloc_wombats_sentences_buffer(struct wombats_sentence *sentence, int linecount)
{
  sentence->linecount = linecount;

  char **lines_ptr = (char**) malloc(linecount*sizeof(char*));

  if(lines_ptr == NULL) {
    fprintf(stderr, "Error, could not allocate memory for Wombats sentence\n");
    return -1;
  };

  int i = 0;
  for (i = 0; i < linecount; ++i) {
    lines_ptr[i] = (char*) malloc(MAX_SENTENCE_LEN+1); /* +1 for trailing nullchar */
    if(lines_ptr[i] == NULL) {
      fprintf(stderr, "Error, could not allocate memory for Wombats sentence\n");
      return -1;
    }
  }

  sentence->lines = lines_ptr;


  return 0;
}

/******************************************************************************/
void
cleanup_sentence(struct wombats_sentence *sentence)
{
  for (int i = 0; i < sentence->linecount; ++i) {
    if(sentence->lines[i] != NULL) {
      free(sentence->lines[i]);
      sentence->lines[i] = NULL;
    }
  }

  if(sentence->lines != NULL) {
    free(sentence->lines);
    sentence->lines = NULL;
  }
}
