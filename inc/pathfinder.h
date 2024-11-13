#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

#define INF 2147483647  


typedef struct s_island {
    char *name;                
    int islandID;              
    struct s_path *path;       
    struct s_island *next;     
}              t_island;

typedef struct s_path {
    int pathID;
    int pathDistance;         
    struct s_island *nextConnect;  
    struct s_path *nextPath;   
}              t_path;

typedef struct s_matrix {
    int *matrix; 
} t_matrix;

typedef struct s_visited_path {
    char *path;
    struct s_visited_path *next;
} t_visited_path;

typedef struct s_route {
    int *path; // Масив індексів островів у шляху
    int length;
    int capacity;
    int distance;  // Загальна відстань для цього шляху
    struct s_route *next; // Вказівник на наступний шлях
} t_route;


typedef struct s_sort_context {
    t_island *islands;
    int (*cmp)(const t_route *a, const t_route *b, t_island *islands);
} t_sort_context;

 typedef struct {
        int current;
        int length;
    } Frame;


void add_bridge(t_island **islands, char *island1, char *island2, int bridge_length, int *current_index);
void add_path(t_island *from, t_island *to, int distance);
void add_to_visited(t_visited_path **visited, const char *from, const char *to);
void check_arg_count(int argc);
void check_bridge_length_exceedance(t_island *islands);
void check_duplicate_bridges(t_island *islands);
void check_file_empty(const char *filename);
void check_file_existence(char *filename);
void check_file_format(char *file_content);
void clear_visited(t_visited_path **visited);
t_matrix *create_matrix(int island_count);
t_path *create_path_list(int *pathIDs, int *pathDistances, t_island **connectedIslands, int count);
void fill_matrix_with_distances(t_matrix *matrix, t_island *islands);
void find_all_paths(t_island *islands, t_matrix *matrix);
t_island *find_or_create_island(t_island **islands, char *name, int *current_index);
void free_matrix(t_matrix *matrix);
int get_island_count(t_island *islands);
int get_island_index(t_island *islands, const char *name);
char *get_island_name_by_index(t_island *islands, int index);
bool is_path_visited(t_visited_path *visited, const char *from, const char *to);
void mx_clear_list(t_list **list);
void mx_printerr(const char *s);
char *mx_read_file(const char *filename);
char *mx_strchr(const char *s, int c);
char *mx_strtok(char *str, const char *delim);
t_island *parse_input(char *file_content);
void parse_line(t_island **islands, char *line, int line_number, int *current_index);
void print_route(int *prev, int end, t_island *islands, int island_count);
void print_distance(int *path, int length, t_matrix *matrix, int island_count);
void print_shortest_path(t_island *islands, int start, int end, int *path, int length, t_matrix *matrix, int island_count);

int main(int argc, char **argv);

t_route *add_route(int *path, int length, int distance, t_route **routes);
void find_shortest_path(t_island *islands, t_matrix *matrix, int start, int end, t_route **routes);
void build_paths(t_list **prev, int start, int current, int *dist, t_route **routes);
void free_routes(t_route *routes);
void free_route(t_route *route);
void add_to_path(t_route *route, int island_id);
void print_with_separators(t_island *islands, int start, int end, t_route *routes, t_matrix *matrix, int island_count);
void add_alternative_path(int *prev, int end, int start, t_route **routes, int island_count, int *dist);
bool is_duplicate_route(t_route *routes, int *path, int length);
void add_to_list(t_list **list, int value);
void clear_list(t_list **list);
t_route *sorted_merge(t_route *a, t_route *b, t_sort_context *context);
void front_back_split(t_route *source, t_route **front_ref, t_route **back_ref);
void merge_sort_routes(t_route **head_ref, t_sort_context *context);
bool is_only_letters(const char *str);
bool is_only_digits(const char *str);
char *create_bridge_key(const char *island1, const char *island2);
bool is_bridge_duplicate(t_list *keys, const char *key);
bool bridge_exists(t_island *island1, t_island *island2);
void mx_clear_path_list(t_path **head);
t_island *create_island(char *name);
void free_island_list(t_island *islands);
void mx_clear_island_list(t_island **head);
int compare_routes(const t_route *a, const t_route *b, t_island *islands);
void free_paths(t_island *island);
void free_all_islands(t_island *islands);
void clear_paths(t_path *path);
bool is_empty_line(const char *line);
void check_empty_lines(const char *filename);
char *int_to_string(int num);

#endif // PATHFINDER_H

