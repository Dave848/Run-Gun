#include "App.h"


int main()
{
    //Init application
    App app;

    //Game loop
    while (app.running())
    {
        //Update
        app.update();

        //Render
        app.render();
    }

    //End of app
    return 0;
}