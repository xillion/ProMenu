#ifndef PRO_MENU_ITEM_SUBMENU_H
#define PRO_MENU_ITEM_SUBMENU_H

#include "ProMenuItem.h"

namespace promenu {

class MenuItem;

class MenuItemSubmenu: public MenuItem {

public:
    MenuItemSubmenu(int id, char *name, Menu &submenu):
        MenuItem(id, name),
        submenu(submenu) {};
    
    virtual void select(MenuManager *manager);

private:
    Menu &submenu;
};

};

#endif /* PRO_MENU_ITEM_SUBMENU_H */
