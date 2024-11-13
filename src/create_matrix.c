#include "pathfinder.h"

t_matrix *create_matrix(int island_count) {
    t_matrix *matrix = malloc(sizeof(t_matrix));
    if (!matrix) return NULL;  
    matrix->matrix = malloc(island_count * island_count * sizeof(int));
    if (!matrix->matrix) {
        free(matrix);
        return NULL;
    }

    for (int i = 0; i < island_count * island_count; i++) {
        matrix->matrix[i] = INF;
    }
    return matrix;
}
