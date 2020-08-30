#ifndef PRO_MENU_BASE_H
#define PRO_MENU_BASE_H

#include <stddef.h>

namespace promenu {

class MenuManager;
class DisplayInterface;

class MenuBase {

public:
    MenuBase();
    
    virtual void begin(MenuManager *manager, int pos = 0);
    virtual void end();
    virtual void reset();

    virtual bool prev() = 0;
    virtual bool next() = 0;
    virtual bool exit();
    virtual bool enter() = 0;

    virtual void render(DisplayInterface &display) = 0;
    virtual void process() = 0;

    MenuManager& getMenuManager();

protected:
    MenuBase *prevMenu;
    MenuManager *manager;
};

};

#endif /* PRO_MENU_BASE_H */
