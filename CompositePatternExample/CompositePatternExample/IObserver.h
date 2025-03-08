#pragma once

#include "StateEnum.h"

class IObserver
{
public:

	virtual void onNotifiedByParent(eState checkedStateChanged) = 0;
	virtual void onNotifiedByChild(eState checkedStateChanged) = 0;

};