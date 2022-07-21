/**
 * @date 2022-07-21
 *
 * Find work score.
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int get_word_points(char *word);
int get_symbol_points(char symbol);
int get_symbol_index(char symbol);

int points[] = {
    1,  3, 3, 2,
    1,  4, 2, 4,
    1,  8, 5, 1,
    3,  1, 1, 3,
    10, 1, 1, 1,
    1,  4, 4, 8,
    4,  10
};

int main() {
    printf("Word:   ");
    char word[255];
    scanf("%s", word);
    printf("Points: %i\n", get_word_points(word));
    return 0;
}

int get_word_points(char *word) {
    int points_sum = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        points_sum += get_symbol_points(word[i]);
    }

    return points_sum;
}

int get_symbol_points(char symbol) {
    int symbol_index = get_symbol_index(symbol);
    return symbol_index == -1 ? 0 : points[symbol_index];
}

int CHAR_FIRST_SYMBOL_INDEX = 65;

int get_symbol_index(char symbol) {
    int unified_symbol_index = (int) toupper(symbol);
    int symbol_index = unified_symbol_index - CHAR_FIRST_SYMBOL_INDEX;
    return (symbol_index < sizeof(points) && symbol_index >= 0)
        ? symbol_index
        : -1;
}
