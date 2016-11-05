#ifndef WOMBAT_OPERATIONS
#define WOMBAT_OPERATIONS
#include "wombatsay_types.h"

/*
 * @brief mallocs the buffer inside the wombats_sentence struct
 */

int malloc_wombats_sentences_buffer(struct wombats_sentence *sentence, int linecount);
void cleanup_sentence(struct wombats_sentence *sentence);

#endif /* ifndef WOMBAT_OPERATIONS */
