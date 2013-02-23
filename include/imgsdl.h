#ifndef __IMGPROC_H__
#define __IMGPROC_H__

#include <SDL.h>
#include "geometry.h"

/*
 * Vous devez coder cette fonction qui prend en entrée un affichage et une
 * scène. Vous devrez alors utiliser la fonction putPixel qui place une couleur
 * au format RGB aux coordonnées x et y.
 *
 */
void traceSDLScene (SDL_Surface* display,
                    scene* s);

/*
 * Cette fonction est déjà implémentée dans libimgsdl.a.
 */
void putPixel      (SDL_Surface *g_screenSurface,
                    int x, int y, Uint8 r, Uint8 g, Uint8 b);

#endif // __IMGPROC_H__

