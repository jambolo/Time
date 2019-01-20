#include "Clock.h"

#include "Misc/Exceptions.h"

#include <windows.h>

//!
//! @exception	std::bad_alloc	out of memory

Clock & Clock::Instance()
{
    if (Singleton<Clock>::Instance() == 0)
        new Clock;

    return *static_cast<Clock *>(Singleton<Clock>::Instance());
}

//!
//! @exception	ConstructorFailedException	QueryPerformanceFrequency() failed

Clock::Clock()
{
    LARGE_INTEGER frequency;
    BOOL          ok;

    ok = QueryPerformanceFrequency(&frequency);
    if (ok == 0)
        throw ConstructorFailedException();

    m_frequency = frequency.QuadPart;
    m_interval  = 1.0 / double(m_frequency);
}

__int64 Clock::GetTime() const
{
    LARGE_INTEGER time;
    QueryPerformanceCounter(&time);
    return time.QuadPart;
}
