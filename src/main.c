#include "cairo.h"
#include "generate_page_image.h"
#include "higlith_word.h"
#include "poppler-document.h"
#include "poppler-page.h"
#include "poppler-structure-element.h"
#include <poppler.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s [gen|under]\n", argv[0]);
    return 1;
  }

  if (strcmp(argv[1], "gen") == 0) {
    generate_page_image();
  } else if (strcmp(argv[1], "under") == 0) {
    higlith_word();
  } else {
    printf("Unknown command: %s\n", argv[1]);
    return 1;
  }

  return 0;
}
