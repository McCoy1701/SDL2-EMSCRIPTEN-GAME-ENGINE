#include "customer.h"

#define MAX_NO_OF_CUSTOMERS 42
static struct Customer objectPool[MAX_NO_OF_CUSTOMERS];
static size_t numberOfObjects = 0;

struct Customer{
    const char* name;
    Address address;
    size_t noOfOrders;
    Order order[MAX_ORDERS];
};

CustomerPtr createCustomer(const char* name, const Address* address) {
    CustomerPtr customer = NULL;
    if(numberOfObjects < MAX_NO_OF_CUSTOMERS) {
        customer = &objectPool[numberOfObjects++];
    }
    return customer;
}