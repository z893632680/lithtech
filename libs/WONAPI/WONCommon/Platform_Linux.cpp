#include "Platform_Linux.h"
#include "CriticalSection_Linux.h"
#include "sys/poll.h"


static WONAPI::CriticalSection gInterlockedCrit;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
long InterlockedIncrement(long *addend)
{
	gInterlockedCrit.Enter();
	long aVal = ++(*addend);
	gInterlockedCrit.Leave();
	return aVal;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
long InterlockedDecrement(long *addend)
{
	gInterlockedCrit.Enter();
	long aVal = --(*addend);
	gInterlockedCrit.Leave();
	return aVal;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Sleep(DWORD dwMilliseconds)
{
	usleep(dwMilliseconds*1000);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

