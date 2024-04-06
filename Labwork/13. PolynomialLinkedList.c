/*
13. WAP to perform addition and multiplication of two polynomials by creating linked list for every polynomial.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in a polynomial
typedef struct Node {
    int coeff;  // Coefficient of the term
    int power;  // Power of the term
    struct Node* next;  // Pointer to the next term
} Node;

// Function to create a new term with given coefficient and power
Node* createTerm(int coeff, int power) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new term into the polynomial
void insertTerm(Node** poly, int coeff, int power) {
    Node* newNode = createTerm(coeff, power);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        Node* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->power > poly2->power) {
            insertTerm(&result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        } else if (poly1->power < poly2->power) {
            insertTerm(&result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        } else {
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    // Add remaining terms of poly1
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }
    // Add remaining terms of poly2
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }
    return result;
}

// Function to multiply two polynomials
Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    while (poly1 != NULL) {
        Node* tempPoly2 = poly2;
        while (tempPoly2 != NULL) {
            int coeff = poly1->coeff * tempPoly2->coeff;
            int power = poly1->power + tempPoly2->power;
            insertTerm(&result, coeff, power);
            tempPoly2 = tempPoly2->next;
        }
        poly1 = poly1->next;
    }
    return result;
}

// Function to display a polynomial
void displayPolynomial(Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->power);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to free memory allocated for a polynomial
void freePolynomial(Node* poly) {
    Node* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    // Input first polynomial
    int n, coeff, power;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficients and powers of each term of the first polynomial:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &power);
        insertTerm(&poly1, coeff, power);
    }

    // Input second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficients and powers of each term of the second polynomial:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &power);
        insertTerm(&poly2, coeff, power);
    }

    // Display first polynomial
    printf("First polynomial: ");
    displayPolynomial(poly1);

    // Display second polynomial
    printf("Second polynomial: ");
    displayPolynomial(poly2);

    // Add polynomials
    Node* sum = addPolynomials(poly1, poly2);
    printf("Sum of polynomials: ");
    displayPolynomial(sum);
    freePolynomial(sum);

    // Multiply polynomials
    Node* product = multiplyPolynomials(poly1, poly2);
    printf("Product of polynomials: ");
    displayPolynomial(product);
    freePolynomial(product);

    // Free memory allocated for polynomials
    freePolynomial(poly1);
    freePolynomial(poly2);

    return 0;
}
