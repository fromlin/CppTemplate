//////////////////////////////////////////////////////////////////////////////////////////////////////////
// File		: UdpClientWork.h
// Version	: 1.0.1
// Date		: 2022.08.31
// Writer	: Kim, YeLin (MRAS)
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef _UDPCLIENTWORK_H__
#define _UDPCLIENTWORK_H__

//include//
#include "WorkBase.h"
#include "DataType.h"
#include "SystemMemory.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define UDP_TIME			0.1		// 10[Hz]


class CUdpClientWork : public CWorkBase{

	// Define ////////////////////////////////////////////////////////
public:

protected:

private:


	// Method ////////////////////////////////////////////////////////
public:
	// CWorkBase 상속
	CUdpClientWork(std::string name);
	virtual ~CUdpClientWork();

	// ex) UDP 통신 on/off
	bool Open();
	void Close();

protected:
	virtual void _execute();		// _execute(virtual)
									// ThreadWorker.h => CThreadedWorker::_ThreadWork(CSyncSharedMemory* poMemory)



	// Member ////////////////////////////////////////////////////////
public:

protected:

private:
	std::string _memname_kuka;		// 생성할 system memory 이름

	KuKaData_t _kuka;				// 생성한 system memory에 저장할 값을 담은 변수
	KuKaData_t _kukaDesired;		// 다른 node의 데이터를 system memory에서 가져와 담을 변수

	bool _isOpen;
};

#endif