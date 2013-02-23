#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#define EPSILON (0.00001)

/*
 * Les couleurs en coordonnées RGB
 */
typedef struct scolor {
  unsigned char r, g, b; // traduire unsigned char par entier <= 255
} color;

/*
 * Point et vecteur sont deux objets différents mais ils sont tous
 * représentables par trois coordonnées dans l'espace
 */
typedef struct spoint {
  double x, y, z;
} point, vector;

/*
 * Structure représentant une facette
 */
typedef struct sfacet {
  point a, b, c;
  double k; // coefficient de réflexion
  color cp;
  vector n;
} facet;

/*
 * Structure représentant un rayon.
 * Le sens du vecteur donne la direction du rayon.
 */
typedef struct sray {
  point o;
  vector v;
} ray;

/*
 * Ce modèle de scène est celui utilisé par libimgsdl.h.
 * Une source de lumière est ponctuelle et possède une couleur propre.
 * width et height sont les tailles de l'image rendue.
 * nbPoints et nbFacets sont les tailles des vecteur points et facets.
 * obs est la position de l'observateur.
 * screenA et screenB aident à définir la position et l'orientation de l'écran.
 */

typedef struct ssource {
  point p;
  color cp;
} source;

typedef struct sscene {
  color back;
  int width, height, nbPoints, nbFacets;
  point obs, screenA, screenB, *points;
  facet *facets;
  source s;
} scene;

#endif // __GEOMETRY_H__

