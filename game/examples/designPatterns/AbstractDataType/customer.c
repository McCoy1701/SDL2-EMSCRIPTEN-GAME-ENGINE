#include "customer.h"

struct Customer{
    const char* name;
    Address address;
    size_t noOfOrders;
    Order order[MAX_ORDERS];
};

CustomerPtr createCustom(const char* name, const Address* address) {
    CustomerPtr customer = malloc(sizeof *customer);
    if (customer) {
        customer->name = name;
        customer->address = *address;
    }
    return customer;
}

void destroyCustomer(CustomerPtr customer) {
    free(customer);
}
