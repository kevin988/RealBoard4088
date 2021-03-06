/*
 * YAFFS: Yet Another Flash File System. A NAND-flash specific file system.
 *
 * Copyright (C) 2002-2010 Aleph One Ltd.
 *   for Toby Churchill Ltd and Brightstar Engineering
 *
 * Created by Charles Manning <charles@aleph1.co.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

/*
 * yaffscfg2k.c  The configuration for the "direct" use of yaffs.
 *
 * This file is intended to be modified to your requirements.
 * There is no need to redistribute this file.
 */

#include "yaffscfg.h"
#include "yaffsfs.h"
#include "yaffs_trace.h"
#include "ynandsim.h"

unsigned yaffs_traceMask = 

	YAFFS_TRACE_SCAN |  
	YAFFS_TRACE_GC |
	YAFFS_TRACE_ERASE | 
	YAFFS_TRACE_ERROR | 
	YAFFS_TRACE_TRACING | 
	YAFFS_TRACE_ALLOCATE | 
	YAFFS_TRACE_BAD_BLOCKS |
	YAFFS_TRACE_VERIFY | 
	
	0;
        

static int yaffsfs_lastError;

void yaffsfs_SetError(int err)
{
	//Do whatever to set error
	yaffsfs_lastError = err;
}


int yaffsfs_GetLastError(void)
{
	return yaffsfs_lastError;
}

void yaffsfs_Lock(void)
{
}

void yaffsfs_Unlock(void)
{
}

__u32 yaffsfs_CurrentTime(void)
{
	return 0;
}



void *yaffs_malloc(size_t size)
{
	return malloc(size);
}

void yaffs_free(void *ptr)
{
	free(ptr);
}

void yaffsfs_LocalInitialisation(void)
{
	// Define locking semaphore.
}

// Configuration


int yaffs_StartUp(void)
{   
	// Stuff to configure YAFFS
	// Stuff to initialise anything special (eg lock semaphore).
	yaffsfs_LocalInitialisation();
	ynandsim_CreateRamSim("p0",0,127,1,0);
	ynandsim_CreateRamSim("p1",1,7936,128,0);
	
	return 0;
}



