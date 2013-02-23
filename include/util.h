#ifndef __UTIL_H__
#define __UTIL_H__

/*
 * Cette fonction calcule 1/sqrt(x) de manière optimisée, en faisant des
 * approximations dans les calculs
 */

float fastInvSqrt(float x);

/*
 * Cette fonction peut vous aider à lire un fichier. Elle découpe une chaîne de
 * caractères buf, en un tableau de chaînes de caractère, en suivant le
 * découpage induit par les espaces et les virgules.
 *
 * out doit être assigné comme tableau de pointeurs de taille size.
 */

void splitLine(char* buf, char** out, int size);

#endif // __UTIL_H__

