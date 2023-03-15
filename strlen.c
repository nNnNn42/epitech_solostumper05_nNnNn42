/*
** EPITECH PROJECT, 2023
** string length
** File description:
** len
*/

//longueur string
int my_strlen (char const *str)
{
    int i = 0;
    while (str[i] != '\0')
        i = i + 1;
    return (i);
}
