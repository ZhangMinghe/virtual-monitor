/*
    Virtual Monitor
    Transforms a projected computer screen into an intuitive touchscreen device.
    Copyright (C) 2018 Devin Gund (https://dgund.com)

    MouseInteractionHandler.h
    Handles mouse interactions with the virtual monitor.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MOUSEINTERACTIONHANDLER_H
#define MOUSEINTERACTIONHANDLER_H

#include "InteractionHandler.h"
#include "MouseController.h"

namespace virtualMonitor {

class MouseInteractionHandler : public InteractionHandler {
private:
    MouseController mouseController;
public:
    MouseInteractionHandler();

private:
    virtual int handleInteractionStartEvent();
    virtual int handleInteractionMoveEvent();
    virtual int handleInteractionEndEvent();
};

} /* namespace virtualMonitor */

#endif /* MOUSEINTERACTIONHANDLER_H */
