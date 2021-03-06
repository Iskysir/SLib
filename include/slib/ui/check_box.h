/*
 *  Copyright (c) 2008-2017 SLIBIO. All Rights Reserved.
 *
 *  This file is part of the SLib.io project.
 *
 *  This Source Code Form is subject to the terms of the Mozilla Public
 *  License, v. 2.0. If a copy of the MPL was not distributed with this
 *  file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef CHECKHEADER_SLIB_UI_CHECK_BOX
#define CHECKHEADER_SLIB_UI_CHECK_BOX

#include "definition.h"

#include "button.h"

namespace slib
{

	class SLIB_EXPORT CheckBox : public Button
	{
		SLIB_DECLARE_OBJECT
		
	public:
		CheckBox();
		
		CheckBox(sl_uint32 nCategories, ButtonCategory* categories);
		
		~CheckBox();

	public:
		sl_bool isChecked();
		
		virtual void setChecked(sl_bool flag, UIUpdateMode mode = UIUpdateMode::Redraw);
		
	public:
		Ref<ViewInstance> createNativeWidget(ViewInstance* parent) override;
		
		void dispatchClick(UIEvent* ev) override;

		void dispatchClick();
		
	public:
		void _getChecked_NW();
		
		void _setChecked_NW(sl_bool flag);

	protected:
		sl_bool m_flagChecked;
		
	};

}

#endif
