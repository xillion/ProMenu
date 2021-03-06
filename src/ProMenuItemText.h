#ifndef PRO_MENU_ITEM_TEXT_H
#define PRO_MENU_ITEM_TEXT_H

#include "ProMenuItem.h"
#include "ProMenuItemEdit.h"

namespace promenu {

class MenuItemTextInterface: public MenuItemEditInterface {

public:
    virtual int getMaxLength(MenuItem &item) = 0;
    virtual void setChar(MenuItem &item, int p, char ch) = 0;
    virtual char getChar(MenuItem &item, int p) = 0;
};

class MenuItemText: public MenuItemEdit {

public:
    MenuItemText(int id, char *name, MenuItemTextInterface &interface, char *prefix = MenuItemText::PREFIX);
    
    virtual bool select();

    virtual bool prev();
    virtual bool next();
    virtual bool enter();

    virtual void render(DisplayInterface &display);

protected:
    virtual MenuItemEditInterface& getInterface();
    virtual void redraw();

    virtual void renderValue(DisplayInterface &display);
    virtual void renderHeaderLine(DisplayInterface &display);

private:
    MenuItemTextInterface &interface;

    int startPos;
    int cursorPos;
    bool editMode;

    static constexpr char *PREFIX = "";

    bool redrawCursor;

    void renderCursor(DisplayInterface &display);
};

};

#endif /* PRO_MENU_ITEM_TEXT_H */
