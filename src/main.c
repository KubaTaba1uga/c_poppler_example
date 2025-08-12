#include "poppler-document.h"
#include "poppler-structure-element.h"
#include <poppler.h>
#include <stdio.h>

int main(void) {

  GFile *file = g_file_new_for_path("src/myinputfile.pdf");
  if (!file) {
    puts("Unable to file");
    return 1;
  }

  PopplerDocument *pdf =
      poppler_document_new_from_gfile(file, NULL, NULL, NULL);
  if (!pdf) {
    puts("Unable to open pdf");
    return 1;
  }

  char *title = poppler_document_get_title(POPPLER_DOCUMENT(pdf));

  printf("Title: %s\n", title);

  return 0;
}
