#include "geometry.h"
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINT_ERROR_CIRCLE printf("Error: invalid circle\n");
#define PRINT_ERROR(msg) printf("Error: unknown figure '%s'\n", msg);

char* input_figure()
{
    char* input = malloc(sizeof(char) * 40);
    printf("Input figure:\n");
    fgets(input, 40, stdin);
    return input;
}

bool isNumber(char* str)
{
    int ln = strlen(str);
    int s = 0;
    int dots = 0;
    int minus = 0;
    int plus = 0;
    int check = 0;
    if (str[0] == '.' || str[ln - 1] == '.')
        return false;
    if (str[ln] == '\n')
        str[ln] = '\0';
    for (int j = 0; j < ln; j++) {
        if (str[j] == '.')
            dots++;
    }
    for (int j = 0; j < ln; j++) {
        if (str[j] == '-')
            minus++;
    }
    for (int j = 0; j < ln; j++) {
        if (str[j] == '+')
            plus++;
    }
    if (dots > 1 || minus > 1 || plus > 1)
        return false;
    if (str[0] == '-' || str[0] == '+')
        s = 1;
    for (int i = s; i < ln; i++) {
      if(isdigit(str[i]) || str[i] == '.')
            check++;
    }
    if ((s == 0 && check == ln) || (s == 1 && check == ln - 1))
        return true;
    return false;
}

Circle create_circle(char* input_str, char* pattern)
{
    char* word;
    if (input_str[6] != '(' || input_str[strlen(input_str) - 2] != ')') {
        PRINT_ERROR_CIRCLE
    }
    Circle circle;
    word = strtok(NULL, pattern);
    if (word != NULL && isNumber(word))
        circle.center.x = atof(word);
    else {
        PRINT_ERROR_CIRCLE
    }
    word = strtok(NULL, pattern);
    if (word != NULL && isNumber(word))
        circle.center.y = atof(word);
    else {
        PRINT_ERROR_CIRCLE
    }
    word = strtok(NULL, pattern);
    if (word != NULL && isNumber(word))
        circle.radius = atof(word);
    else {
        PRINT_ERROR_CIRCLE
    }
    if (!isCircle(circle)) {
        PRINT_ERROR_CIRCLE
    }
    return circle;
}

int main()
{
    char* figure;
    char* word;
    char temp[40];
    char* delim = "() ,";
    figure = input_figure();
    strcpy(temp, figure);
    word = strtok(figure, delim);
    if (strcmp(word, "circle") == 0) {
        Circle circle = create_circle(temp, delim);
        printf("Circle. Point: %lf, %lf. Radius: %lf\n", circle.center.x, circle.center.y, circle.radius);
    } else
        PRINT_ERROR(word);
    return 0;
}