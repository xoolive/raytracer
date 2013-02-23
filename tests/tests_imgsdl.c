#include "imgsdl.h"
#include "raytracer.h"

int  parse(char* fname, scene* scene) {
  /* Je ne lis pas le fichier, c'est juste un exemple */
  scene->width=400;
  scene->height=400;
  // Tout s'est bien passé
  return 0; 
}

void traceSDLScene (SDL_Surface* display, scene* s) {
  int h = s->height, w = s->width, i, j;
  for (i=0; i<w; ++i)
    for (j=0; j<h; ++j)
      putPixel(display, i, j, i*255/h, (w-j)*255/w, (i+w-j)*255/(w+h));
};



