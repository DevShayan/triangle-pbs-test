#include <main_controller.h>

MainController::MainController() {
    eventQueue = al_create_event_queue();
}


void MainController::initEventSources(ALLEGRO_DISPLAY* display) {
    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    al_register_event_source(eventQueue, al_get_display_event_source(display));
}


bool MainController::exit() {
    if (this->event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        return true;
    }
    return false;
}






