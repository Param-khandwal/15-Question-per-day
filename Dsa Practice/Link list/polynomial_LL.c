#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int power;
    struct Node* next;
};

void insertNode(struct Node** poly, int coeff, int power) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;

    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* lastNode = *poly;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

void addPolynomials(struct Node* poly1, struct Node* poly2, struct Node** result) {
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->power > poly2->power) {
            insertNode(result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        } else if (poly1->power < poly2->power) {
            insertNode(result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        } else {
            insertNode(result, poly1->coeff + poly2->coeff, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertNode(result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertNode(result, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }
}

void display(struct Node* poly) {
    while (poly != NULL) {
        printf("(%dx^%d)", poly->coeff, poly->power);
        if (poly->next != NULL) {
            printf(" + ");
        }
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    // Polynomial 1: 3x^2 + 2x^1 + 5x^0
    insertNode(&poly1, 3, 2);
    insertNode(&poly1, 2, 1);
    insertNode(&poly1, 5, 0);

    // Polynomial 2: 4x^3 + 2x^1 + 3x^0
    insertNode(&poly2, 4, 3);
    insertNode(&poly2, 2, 1);
    insertNode(&poly2, 3, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    addPolynomials(poly1, poly2, &result);

    printf("Resultant Polynomial: ");
    display(result);

    return 0;
}
