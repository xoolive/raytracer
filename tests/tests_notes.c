#include "geometry.h"
#include "intersection.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TEST(x,y,e) ((x-y)*(x-y) < 0.0001?++note:\
                     printf("obtenu: %f; attendu: %f (point %s)\n", x, y, e))

int main (int argv, char** argc)
{
  int note = 0;

  point p; p.x=0; p.y=0; p.z=0;
  vector v; v.x=1; v.y=3; v.z=2;
  vector w; w.x=-1; w.y=-3; w.z=-2;

  ray r1; r1.o = p; r1.v = v;
  ray r2; r2.o = p; r2.v = w;

  point a; a.x=-1; a.y=-1; a.z = 1;
  point b; b.x= 1; b.y=-1; b.z =-1;
  point c; c.x= 0; c.y= 1; c.z = 1;
  point d; d.x=-1; d.y= 1; d.z =-1;
  point e; e.x= 3; e.y=-2; e.z = 0;
  point f; f.x= 0; f.y= 1; f.z =-1;
  point g; g.x=-3; g.y= 2; g.z = 1;
  point h; h.x= 1; h.y=-1; h.z = 2;
  point i; i.x=-2; i.y= 3; i.z =-3;
  point j; j.x= 2; j.y= 1; j.z = 0;
  point k; k.x=-1; k.y=-2; k.z = 2;
  point l; l.x= 1; l.y= 0; l.z =-2;

  facet m = createFacet(a, b, c);
  facet n = createFacet(d, e, f);
  facet o = createFacet(g, h, i);
  facet q = createFacet(a, e, i);
  facet s = createFacet(c, e, g);
  facet t = createFacet(f, h, j);

  printf("Tests d'intersections\n");

  point x;
  x = computeIntersection(r1, m);
  TEST(x.x, 0.333, "m.x"); TEST(x.y, 1., "m.y"); TEST(x.z, 0.667, "m.z");
  x = computeIntersection(r2, n);
  TEST(x.x, -0.222, "n.x"); TEST(x.y, -0.667, "n.y"); TEST(x.z, -0.444, "n.z");
  x = computeIntersection(r1, o);
  TEST(x.x, 0.105, "o.x"); TEST(x.y, 0.316, "o.y"); TEST(x.z, 0.211, "o.z");
  x = computeIntersection(r2, q);
  TEST(x.x, -0.112, "q.x"); TEST(x.y, -0.337, "q.y"); TEST(x.z, -0.225, "q.z");
  x = computeIntersection(r1, s);
  TEST(x.x, 1.5, "s.x"); TEST(x.y, 4.5, "s.y"); TEST(x.z, 3., "s.z");
  x = computeIntersection(r1, t);
  TEST(x.x, 0.048, "t.x"); TEST(x.y, 0.143, "t.y"); TEST(x.z, 0.095, "t.z");

  printf("Tests d'appartenance à une facette\n");

  point u1; u1.x = 0; u1.y = 0; u1.z = 0;
  point u2; u2.x = 0; u2.y = 1; u2.z = 0;
  point u3; u3.x = 1; u3.y = 0; u3.z = 0;
  facet y = createFacet(u1,u2,u3);
  point z; z.x = 0.5; z.y = 0.5; z.z = 0;
  isInFacet(z,y)?++note:printf("Le point doit être dans la facette.\n");
  z.x = -0.5; z.y = -0.5;
  !isInFacet(z,y)?++note:printf("Le point ne doit pas être dans la facette.\n");

  printf ("Note finale (sur 2): %.2f\n", note/10.);

  return 0;
}

