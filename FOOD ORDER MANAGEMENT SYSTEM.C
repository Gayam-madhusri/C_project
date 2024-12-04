#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 5
#define MAX_ORDERS 10

typedef struct {
    int id;
    char name[50];
    float price;
} MenuItem;

typedef struct {
    int itemId;
    int quantity;
} Order;

MenuItem menu[MAX_ITEMS] = {
    {1, "Chicken Biryani",210},
    {2, "Mutton Biryani",253},
    {3, "Egg Biryani", 154},
    {4, "Veg Biryani", 154},
    {5, "Paneer Biryani", 216}
};

Order orders[MAX_ORDERS];
int orderCount = 0;

void displayMenu() {
    printf("Menu:\n");
    printf("ID\tName\t\tPrice\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%d\t%s\t%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

void placeOrder() {
    if (orderCount >= MAX_ORDERS) {
        printf("Order limit reached. Cannot place more orders.\n");
        return;
    }

    int itemId, quantity;
    printf("Enter the item ID to order: ");
    scanf("%d", &itemId);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    
    int found = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (menu[i].id == itemId) {
            found = 1;
            break;
        }
    }

    if (found) {
        orders[orderCount].itemId = itemId;
        orders[orderCount].quantity = quantity;
        orderCount++;
        printf("Order placed successfully!\n");
    } else {
        printf("Invalid item ID.\n");
    }
}

void displayOrders() {
    if (orderCount == 0) {
        printf("No current orders.\n");
        return;
    }

    printf("Current Orders:\n");
    printf("ID\tName\t\tQuantity\tTotal Price\n");
    for (int i = 0; i < orderCount; i++) {
        int itemId = orders[i].itemId;
        int quantity = orders[i].quantity;
        printf("%d\t%s\t%d\t\t%.2f\n", itemId, menu[itemId - 1].name, quantity, menu[itemId - 1].price * quantity);
    }
}

void checkOrderStatus() {
    if (orderCount == 0) {
        printf("No current orders to check status.\n");
        return;
    }
    printf("Order status:\n");
    for (int i = 0; i < orderCount; i++) {
        printf("Order %d: Item ID %d, Quantity %d\n", i + 1, orders[i].itemId, orders[i].quantity);
    }
}

void generateBill() {
    if (orderCount == 0) {
        printf("No current orders to generate a bill.\n");
        return;
    }

    float totalBill = 0.0;
    printf("\n--- Bill ---\n");
    printf("ID\tName\t\tQuantity\tTotal Price\n");
    for (int i = 0; i < orderCount; i++) {
        int itemId = orders[i].itemId;
        int quantity = orders[i].quantity;
        float itemTotal = menu[itemId - 1].price * quantity;
        totalBill += itemTotal;
        printf("%d\t%s\t%d\t\t%.2f\n", itemId, menu[itemId - 1].name, quantity, itemTotal);
    }
    printf("Total Bill:Rs %.2f\n", totalBill);
}

int main() {
    int choice;

    do {
        printf("\n--- Paradise ---\n");
        printf("1. View Menu\n");
        printf("2. Place Order\n");
        printf("3. Display Current Orders\n");
        printf("4. Check Order Status\n");
        printf("5. Generate Bill\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu();
                break;
            case 2:
                placeOrder();
                break;
            case 3:
                displayOrders();
                break;
            case 4:
                checkOrderStatus();
                break;
            case 5:
                generateBill();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
