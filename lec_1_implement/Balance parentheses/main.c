#include <stdio.h>
#include <stdbool.h>
#include "header.h"
#include "check.c"

int main(void) {
    char expr[256];
    printf("Enter expression: ");
    if (fgets(expr, sizeof(expr), stdin) == NULL) return 1;

    printf("%s\n", isBalanced(expr) ? "Balanced" : "Not balanced");
    return 0;
}