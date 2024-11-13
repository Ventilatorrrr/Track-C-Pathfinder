#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) 
{
    if (s == NULL) {
        return NULL;
    }
    
    int count_words = mx_count_words(s, c);
    char **result = (char**)malloc(sizeof(char*) * (count_words + 1));
    if (result == NULL) {
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < count_words; i++) {
        int word_length = 0;
        int start = 0;

        while (s[j] && s[j] == c) {
            j++;
        }

        start = j;

        while (s[j] && s[j] != c) {
            word_length++;
            j++;
        }

        result[i] = mx_strnew(word_length);
        if (result[i] == NULL) {

            for (int k = 0; k < i; k++) {
                mx_strdel(&result[k]);
            }
            free(result);
            return NULL;
        }
        mx_strncpy(result[i], s + start, word_length);
    }
    result[count_words] = NULL;

    return result;
}

