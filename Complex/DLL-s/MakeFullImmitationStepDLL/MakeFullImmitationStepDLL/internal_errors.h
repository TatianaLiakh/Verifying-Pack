#pragma once

enum DllCallErroros
{
	SystemIdificationError = -1,
	NoError = 0,
	CreateProcessError,
	LoadLibError,
	GetProcAdressError
};

extern DllCallErroros lastError ;