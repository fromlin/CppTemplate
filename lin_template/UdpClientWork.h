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
	// CWorkBase ���
	CUdpClientWork(std::string name);
	virtual ~CUdpClientWork();

	// ex) UDP ��� on/off
	bool Open();
	void Close();

protected:
	virtual void _execute();		// _execute(virtual)
									// ThreadWorker.h => CThreadedWorker::_ThreadWork(CSyncSharedMemory* poMemory)



	// Member ////////////////////////////////////////////////////////
public:

protected:

private:
	std::string _memname_kuka;		// ������ system memory �̸�

	KuKaData_t _kuka;				// ������ system memory�� ������ ���� ���� ����
	KuKaData_t _kukaDesired;		// �ٸ� node�� �����͸� system memory���� ������ ���� ����

	bool _isOpen;
};

#endif