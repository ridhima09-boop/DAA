#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int total;
    int available;
};

int main() {
    struct Book b[100];
    int count = 0, choice, id, i;

    while (1) {
        printf("\n\n--- LIBRARY MENU ---");
        printf("\n1. Add Book");
        printf("\n2. Search Book");
        printf("\n3. Issue Book");
        printf("\n4. Return Book");
        printf("\n5. Display Unavailable Books");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Book ID: ");
            scanf("%d", &b[count].id);

            printf("Title: ");
            scanf("%s", b[count].title);

            printf("Author: ");
            scanf("%s", b[count].author);

            printf("Total copies: ");
            scanf("%d", &b[count].total);

            b[count].available = b[count].total;
            count++;

            printf("Book added successfully.");
        }

        else if (choice == 2) {
            printf("Enter Book ID: ");
            scanf("%d", &id);

            for (i = 0; i < count; i++) {
                if (b[i].id == id) {
                    printf("Title: %s\n", b[i].title);
                    printf("Author: %s\n", b[i].author);
                    printf("Available: %d\n", b[i].available);
                    break;
                }
            }
        }

        else if (choice == 3) {
            printf("Enter Book ID: ");
            scanf("%d", &id);

            for (i = 0; i < count; i++) {
                if (b[i].id == id) {
                    if (b[i].available > 0) {
                        b[i].available--;
                        printf("Book issued.");
                    } else {
                        printf("Book unavailable.");
                    }
                }
            }
        }

        else if (choice == 4) {
            printf("Enter Book ID: ");
            scanf("%d", &id);

            for (i = 0; i < count; i++) {
                if (b[i].id == id) {
                    if (b[i].available < b[i].total) {
                        b[i].available++;
                        printf("Book returned.");
                    }
                }
            }
        }

        else if (choice == 5) {
            printf("\nUnavailable Books:\n");

            for (i = 0; i < count; i++) {
                if (b[i].available == 0)
                    printf("%d - %s\n", b[i].id, b[i].title);
            }
        }

        else if (choice == 6) {
            break;
        }

        else {
            printf("Invalid choice.");
        }
    }

    return 0;
}
