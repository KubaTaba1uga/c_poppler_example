#ifndef GENERATE_PAGE_IMAGE_H
#define GENERATE_PAGE_IMAGE_H
#include "cairo.h"
#include "poppler-document.h"
#include "poppler-page.h"
#include "poppler-structure-element.h"
#include <poppler.h>
#include <stdio.h>

#define IMAGE_DPI 150

void generate_page_image(void) {
  GFile *file = g_file_new_for_path("src/myinputfile.pdf");
  if (!file) {
    puts("Unable to file");
    return;
  }

  PopplerDocument *pdf =
      poppler_document_new_from_gfile(file, NULL, NULL, NULL);
  if (!pdf) {
    puts("Unable to open pdf");
    return;
  }

  char *title = poppler_document_get_title(POPPLER_DOCUMENT(pdf));

  printf("Title: %s\n", title);

  PopplerPage *page = poppler_document_get_page(POPPLER_DOCUMENT(pdf), 0);
  if (!page) {
    puts("Unable to open document's first page");
    return;
  }

  cairo_surface_t *surface;
  cairo_t *cairo;
  double width, height;
  poppler_page_get_size(page, &width, &height);

  surface = cairo_image_surface_create(
      CAIRO_FORMAT_ARGB32, IMAGE_DPI * width / 72.0, IMAGE_DPI * height / 72.0);
  cairo = cairo_create(surface);
  cairo_scale(cairo, IMAGE_DPI / 72.0, IMAGE_DPI / 72.0);
  cairo_save(cairo);
  poppler_page_render(page, cairo);
  cairo_restore(cairo);
  g_object_unref(page);

  /* Then the image is painted on top of a white "page". Instead of
   * creating a second image, painting it white, then painting the
   * PDF image over it we can use the CAIRO_OPERATOR_DEST_OVER
   * operator to achieve the same effect with the one image. */
  cairo_set_operator(cairo, CAIRO_OPERATOR_DEST_OVER);
  cairo_set_source_rgb(cairo, 1, 1, 1);
  cairo_paint(cairo);

  cairo_status_t status = cairo_status(cairo);
  if (status) {
    printf("%s\n", cairo_status_to_string(status));
  }
  cairo_destroy(cairo);

  const char *png_file = "myphoto.png";
  status = cairo_surface_write_to_png(surface, png_file);
  if (status) {
    printf("%s\n", cairo_status_to_string(status));
  }

  cairo_surface_destroy(surface);

  g_object_unref(pdf);
}

#endif
