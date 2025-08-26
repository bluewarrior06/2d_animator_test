#ifndef _SDL_EVENT_EVENT_HANDLER_H_
#define _SDL_EVENT_EVENT_HANDLER_H_

#include <SDL3/SDL.h>
#include "sdl_event_event.h"
#include "event_handler.h"

class SDLEventEventHandler : public EventHandler<SDLEventEvent, SDL_Event>
{

};

#endif