/** @file *//********************************************************************************************************

                                                      Timer.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Time/Timer.cpp#5 $

	$NoKeywords: $

 ********************************************************************************************************************/

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include "Timer.h"

#include "Clock.h"

/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

Timer::Timer()
{
	// Start the timer immediately. This does not create a problem if it is explicitly started again later. It
	// prevents problems that would be caused by calling Stop or Resume without having called Start first.

	Start();
}



/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

Timer::~Timer()
{
}



/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

//! @return		The start time
//!
//! @note	If the timer is already running, then the timer is reset.

__int64 Timer::Start()
{
	m_StartTime = m_StopTime = Clock::Instance().GetTime();
	m_Running = true;

	return m_StartTime;
}



/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

//! @return		The elapsed time
//!
//! @note	If the timer is note running, this function does nothing.

__int64 Timer::Stop()
{
	if ( m_Running )
	{
		m_StopTime = Clock::Instance().GetTime();
		m_Running = false;
	}

	return Elapsed();
}



/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

//! This function continues timing again, but the time elapsed between the previous stop and the current time is
//! not included.
//!
//! @return		The current time
//!
//! @note	If the timer is already running, this function does nothing.

__int64 Timer::Resume()
{
	__int64 const	currentTime	= Clock::Instance().GetTime();

	if ( !m_Running )
	{
		m_StartTime += currentTime - m_StopTime;
		m_Running = true;
	}

	return currentTime;
}



/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

//! If the timer is running, the time since the timer was started is returned. Otherwise, the elapsed time between
//! Start and Stop is returned.
//!
//! @return		Elapsed time

__int64 Timer::Elapsed()
{
	__int64			elapsedTime;

	if ( m_Running )
	{
		elapsedTime = Clock::Instance().ElapsedSince( m_StartTime );
	}
	else
	{
		elapsedTime = m_StopTime - m_StartTime;
	}

	return elapsedTime;
}

