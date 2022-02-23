#pragma once

#include "../../macros.h"
#include "event.h"

// Much of the early systems developed for AlkahestEngine were developed following
// along with the Game Engine series from The Cherno (Yan Chernikov) as he built
// the Hazel game engine. A future refactor of these systems is planned to
// eventually re-work this code to adapt it more closely to the direction the
// AlkahestEngine is heading. In the meantime, however, thank you to Yan for
// providing one of the most educational channels on YT when it comes to C++
// and OpenGL development.
//
// In compliance with the Hazel license, a copy of said license is available at
// {project_root}/.licenses/Hazel.LICENSE
//
// The code within this file has been modified from the original source, and
// this notice is provided in compliance with the above license terms.

namespace Alkahest
{
    class API KeyEvent : public Event
    {
    public:
        SETUP_EVENT_FLAGS(EventCategory::Input | EventCategory::Keyboard);
    protected:
        KeyEvent() {};
        int m_Keycode;
    };

    class API KeyDownEvent : public KeyEvent
    {
    public:
        KeyDownEvent(int keycode, bool repeated): m_Repeated(repeated) { m_Keycode = keycode; };
        SETUP_EVENT_TYPE(KeyDown);
        std::string toString() const override { return "KeyDownEvent: " + std::to_string(m_Keycode); };
    private:
        bool m_Repeated = false;
    };

    class API KeyUpEvent : public KeyEvent
    {
    public:
        KeyUpEvent(int keycode) { m_Keycode = keycode; };
        SETUP_EVENT_TYPE(KeyUp);
        std::string toString() const override { return "KeyUpEvent: " + std::to_string(m_Keycode); };
    };
}