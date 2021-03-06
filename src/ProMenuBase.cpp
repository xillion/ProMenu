#include "ProMenuBase.h"

#include "ProMenuManager.h"
#include "ProMenuUtils.h"

#include <string.h>
#include <stdio.h>

namespace promenu {

MenuBase::MenuBase(char *name):
    name(name),
    prevMenu(NULL)
{

}

void MenuBase::begin(MenuManager *manager, int pos)
{
    if (manager != NULL) {
        this->prevMenu = &manager->getCurrentMenu();
        this->manager = manager;
    }
}

void MenuBase::end()
{
    this->reset();
}

bool MenuBase::exit()
{
    if (this->prevMenu != NULL) {
        this->prevMenu->begin(NULL);
        this->manager->backToMenu(*this->prevMenu);
    } else {
        this->reset();
    }
    return true;   
}

void MenuBase::reset()
{

}

const char* MenuBase::getName()
{
    return this->name;
}

MenuBase* MenuBase::getPrevMenu()
{
    return this->prevMenu;
}

MenuManager& MenuBase::getMenuManager()
{
    return *this->manager;
}

int MenuBase::getMenuTreeNameLength()
{
    MenuBase *menu = this;
    int len = 0;

    while (menu) {
        len += strlen(menu->name);
        menu = menu->prevMenu;
        if (menu)
            len ++;
    }

    return len;
}

};