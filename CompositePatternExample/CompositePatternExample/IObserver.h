#pragma once

class IObserver
{
public:

	virtual void onNotifiedByParent(bool checkedStateChanged) = 0;
	virtual void onNotifiedByChild(bool checkedStateChanged) = 0;

};