#include "drawing_operations.h"
#include "wombat_drawings.h"
#include "wombatsay_constants.h"

#include "stdio.h"

struct wombat_t wombi = { "\\",
                          " \\  /\\___/\\",
                          "   /       \\--------\\",
                          "   ()  ()            \\",
                          " / __                 \\",
                          "|  ||        >         |",
                          "<  --    __ >          |oo",
                          " < -----/|      ____   |oo",
                          "   /_____|-----/______ |"};


/*****************************************************************************/
void
draw_wombat()
{
  printf("%s\n", wombi.line0);
  printf("%s\n", wombi.line1);
  printf("%s\n", wombi.line2);
  printf("%s\n", wombi.line3);
  printf("%s\n", wombi.line4);
  printf("%s\n", wombi.line5);
  printf("%s\n", wombi.line6);
  printf("%s\n", wombi.line7);
  printf("%s\n", wombi.line8);
}

