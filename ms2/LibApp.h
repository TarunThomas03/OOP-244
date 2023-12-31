#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include <iostream>
#include "Menu.h"

namespace sdds {
    class LibApp {
    private:
        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;

        bool confirm(const char* message);

        void load();
        void save();
        void search();
        void returnPub();

        void newPublication();
        void removePublication();
        void checkOutPub();

    public:
        LibApp();

      
        void run();
    };
}

#endif



