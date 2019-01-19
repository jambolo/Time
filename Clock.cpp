/** @file *//********************************************************************************************************

                                                      Clock.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Time/Clock.cpp#11 $

	$NoKeywords: $

 ********************************************************************************************************************/

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include "Clock.h"

#include "Misc/Exceptions.h"

#include <windows.h>


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

//!
//! @exception	std::bad_alloc	out of memory

Clock & Clock::Instance()
{
	if ( Singleton<Clock>::Instance() == 0 )
	{
		new Clock;
	}

	return *static_cast< Clock * >( Singleton<Clock>::Instance() );
}

/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

//!
//! @exception	ConstructorFailedException	QueryPerformanceFrequency() failed

Clock::Clock()
{
	LARGE_INTEGER	frequency;
	BOOL			ok;

	ok = QueryPerformanceFrequency( &frequency );
	if ( ok == 0 )
	{
		throw ConstructorFailedException();
	}

	m_frequency = frequency.QuadPart;
	m_interval = 1.0 / double( m_frequency );
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

Clock::~Clock()
{
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

__int64 Clock::GetTime() const
{
	LARGE_INTEGER	time;

	QueryPerformanceCounter( &time );

	return time.QuadPart;
}
