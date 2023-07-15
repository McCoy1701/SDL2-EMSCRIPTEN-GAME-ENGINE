#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_ORDERS 42

typedef struct _address {
    int streetNumber;
    int postalCode;
    const char* town;
    const char* state;
} Address;

typedef struct _order {
    int amount;
    const char* SKU;
} Order;

/*typedef struct _customer{
    const char* name;
    Address address;
    size_t noOfOrders;
    Order order[MAX_ORDERS];
} Customer;*/

typedef struct Customer* CustomerPtr;

CustomerPtr initCustomer(const char* name, const Address* address);

void placeOrder(CustomerPtr customer, const Order* order);

void destroyCustomer(CustomerPtr customer);

#endif