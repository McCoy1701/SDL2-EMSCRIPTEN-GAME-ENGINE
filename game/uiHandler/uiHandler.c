#include "uiHandler.h"

Ui* list;

void initUi(void) {
    list = uiConstructor();
}

void uiDeconstructor(Ui* menu) {
    while(menu->buttonHead != NULL) {
       Buttons* temp = menu->buttonHead;
       menu->buttonHead = menu->buttonHead->next;
       buttonsDeconstructor(temp);
    }
}

