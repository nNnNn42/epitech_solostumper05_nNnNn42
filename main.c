/*
** EPITECH PROJECT, 2023
** rostring
** File description:
** word rotation
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

//check si space ou tab
int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

//compte nombre de mots (ni espace ou tab)
int word_count(char *str)
{
    int count = 0;
    int in_word = 0;
    while (*str) {
        if (!is_space(*str) && !in_word) {
            in_word = 1;
            count++;
        }
        if (is_space(*str)) {
            in_word = 0;
        }
        str++;
    }
    return count;
}

//array pointeurs vers words de la string
char **word_array(char *str, int count)
{
    char **words = malloc((count + 1) * sizeof(char *));
    int i = 0;
    int in_word = 0;
    while (*str) {
        if (!is_space(*str) && !in_word) {
            in_word = 1;
            words[i++] = str;
        }
        if (is_space(*str)) {
            in_word = 0;
            *str = '\0';
        }
        str++;
    }
    words[i] = NULL;
    return words;
}

//print array de words vers terminal
void rostring(char **words)
{
    int i = 0;
    while (words[i + 1]) {
        write(1, words[i], my_strlen(words[i]));
        write(1, " ", 1);
        i++;
    }
    write(1, words[i], my_strlen(words[i]));
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        write(1, "\n", 1);
        return 0;
    }
    int count = word_count(argv[1]);
    char **words = word_array(argv[1], count);

    if (count > 1) {
        char *first_word = words[0];
        for (int i = 0; i < count - 1; i++) {
            words[i] = words[i + 1];
        }
        words[count - 1] = first_word;
    }
    rostring(words);
    free(words);
    return 0;
}
