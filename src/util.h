#define REAL long double

int n;
int dim;

REAL** x;
REAL* y;
REAL* w;

REAL dot(REAL* a, REAL* b, int d);

REAL MSE(REAL** x, REAL* y, int m);

REAL CEL(REAL** x, REAL* y, int m);