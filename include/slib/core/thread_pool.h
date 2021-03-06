/*
 *  Copyright (c) 2008-2017 SLIBIO. All Rights Reserved.
 *
 *  This file is part of the SLib.io project.
 *
 *  This Source Code Form is subject to the terms of the Mozilla Public
 *  License, v. 2.0. If a copy of the MPL was not distributed with this
 *  file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef CHECKHEADER_SLIB_CORE_THREAD_POOL
#define CHECKHEADER_SLIB_CORE_THREAD_POOL

#include "definition.h"

#include "queue.h"
#include "thread.h"
#include "dispatch.h"

namespace slib
{
	
	class SLIB_EXPORT ThreadPool : public Dispatcher
	{
		SLIB_DECLARE_OBJECT

	private:
		ThreadPool();

		~ThreadPool();

	public:
		static Ref<ThreadPool> create(sl_uint32 minThreads = 0, sl_uint32 maxThreads = 30);
	
	public:
		void release();

		sl_bool isRunning();

		sl_uint32 getThreadsCount();
	
		sl_bool addTask(const Function<void()>& task);

		sl_bool dispatch(const Function<void()>& callback, sl_uint64 delay_ms = 0) override;
	
	public:
		SLIB_PROPERTY(sl_uint32, MinimumThreadsCount)
		SLIB_PROPERTY(sl_uint32, MaximumThreadsCount)
		SLIB_PROPERTY(sl_uint32, ThreadStackSize)
	
	protected:
		void onRunWorker();
	
	protected:
		CList< Ref<Thread> > m_threadWorkers;
		LinkedQueue< Function<void()> > m_tasks;
	
		sl_bool m_flagRunning;

	};

}

#endif
