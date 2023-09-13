#include "ui.h"


Ui* uiConstructor(void) {
    Ui* newUi = (Ui*)malloc(sizeof(Ui));
    return newUi;
}
