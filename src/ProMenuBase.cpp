#include "ProMenuBase.h"

#include "ProMenuManager.h"

#include <string.h>
#include <stdio.h>

namespace promenu {

MenuBase::MenuBase(int id, char *name):
    id(id),
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

int MenuBase::getId()
{
    return this->id;
}

const char* MenuBase::getName()
{
    return this->name;
}

MenuManager& MenuBase::getMenuManager()
{
    return *this->manager;
}

};