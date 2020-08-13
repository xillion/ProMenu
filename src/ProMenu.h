#ifndef PRO_MENU_H
#define PRO_MENU_H

#include <stddef.h>

namespace promenu {

class MenuManager;
class MenuItem;
class DisplayInterface;

class Menu {

public:
    Menu(int id, char *name, MenuItem **items, int itemsNum);
    
    virtual void begin(MenuManager *manager, int pos = 0);
    virtual void end();
    virtual void reset();

    virtual bool prev();
    virtual bool next();
    virtual bool exit();
    virtual bool enter();

    virtual void render(DisplayInterface &display);

    int getId();
    const char* getName();

    MenuManager& getMenuManager();

private:
    const int id;
    const char *name;
    MenuItem* const *items;
    const int itemsNum;

    Menu *prevMenu;
    MenuManager *manager;
    int currentPos;
    int startPos;
};

};

#endif /* PRO_MENU_H */
