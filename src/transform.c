#include "transform.h"

gsl_matrix* orth_proj_mat(float l, float r, float t, float b, float n, float f) {
	float rml = (r - l);
	float rpl = (r + l);
	float tmb = (t - b);
	float tpb = (t + b);
	float fmn = (f - n);
	float fpn = (f + n);

	gsl_matrix* proj = gsl_matrix_calloc(4, 4);
	gsl_matrix_set(proj, 0, 0, 2.0f / rml);
	gsl_matrix_set(proj, 1, 1, 2.0f / tmb);
	gsl_matrix_set(proj, 2, 2, -2.0f / fmn);
	gsl_matrix_set(proj, 3, 3, 1.0f);
	gsl_matrix_set(proj, 3, 0, -rpl / rml);
	gsl_matrix_set(proj, 3, 1, -tpb / tmb);
	gsl_matrix_set(proj, 3, 2, -fpn / fmn);

	return proj;
}
