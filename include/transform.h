#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__
#include <gsl/gsl_matrix.h>

gsl_matrix* orth_proj_mat(float l, float r, float t, float b, float n, float f);

#endif /* __TRANSFORM_H__ */
