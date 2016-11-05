#ifndef STRING_OPERATIONS_H
#define STRING_OPERATIONS_H
#include "wombatsay_types.h"

#include "stdio.h"
#include "stdlib.h"

/*
 * @brief Error Message if memory is exhausted
 */
static inline void no_mem()
{
  fprintf(stderr, "Error, no more memory\n");
  exit(1);
}

/*!
 * @brief Parses the cmd line arguments into one large string
 */
char *parse_argv(char **argv, int argc);

/*!
 * @brief Parses the user input into one giant string
 */
char *parse_user_input();

/*!
 * @brief If the sentence is too long divides the sentence into several lines
 */
void divide_lines(struct wombats_sentence *sentence, char *line);

/*!
 * @brief Releases Memory occupied by the line
 */
void cleanup_line(char *line);


#endif /* ifndef STRING_OPERATIONS_H */
