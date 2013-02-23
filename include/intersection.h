#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "geometry.h"

/*
 * Cette fonction attendue par les tests notés doit créer une facette avec les
 * trois points passés en entrée et générer le vecteur normal à la facette. Les
 * autres champs peuvent être laissés non explicites pour le moment.
 */

facet  createFacet(point a, point b, point c);

/*
 * Cette fonction prend en entrée un rayon et une facette et calcule le point
 * d'intersection entre le rayon et le plan induit par la facette.
 */

point computeIntersection(ray, facet);

/*
 * Cette fonction n'est pas explicitement appelée. Vous n'êtes pas obligés de
 * l'implémenter mais elle pourra vous être utile. Elle permet de transformer
 * les coordonnées d'un point exprimées dans le repère O,x,y,z en coordonnées
 * dans le repère (non orthogonal) de la facette.
 */

point changeCoord(point, facet);

/*
 * Cette fonction permet de tester si un point est inclus dans une facette.
 */

int   isInFacet(point, facet);

#endif // __INTERSECTION_H__

