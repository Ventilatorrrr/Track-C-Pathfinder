#include "pathfinder.h"

void free_matrix(t_matrix *matrix) {
    if (matrix != NULL) {
        free(matrix->matrix);
        free(matrix);
    }
}


