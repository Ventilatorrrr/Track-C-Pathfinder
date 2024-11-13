#include "pathfinder.h"

int main(int argc, char **argv) 
{

    t_route *routes = NULL;
    t_visited_path *visited_paths = NULL;
    
    check_arg_count(argc);
    
    check_file_existence(argv[1]);
    
    check_file_empty(argv[1]);
    
     
    char *file_content = mx_read_file(argv[1]);
    check_file_format(file_content);
    check_empty_lines(argv[1]);
    
    t_island *islands = parse_input(file_content);
    
    check_duplicate_bridges(islands);
    
    check_bridge_length_exceedance(islands);
    
    int island_count = get_island_count(islands);
    t_matrix *matrix = create_matrix(island_count);
    
    fill_matrix_with_distances(matrix, islands);
    
    find_all_paths(islands, matrix);
    
    free_all_islands(islands);
    free_matrix(matrix);
    free(file_content);
    clear_visited(&visited_paths);
    free_routes(routes);
    
    return 0;
}

