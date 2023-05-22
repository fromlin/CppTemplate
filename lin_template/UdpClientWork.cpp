//////////////////////////////////////////////////////////////////////////////////////////////////////////
// File		: UdpClientWork.cpp
// Version	: 1.0.1
// Date		: 2022.08.31
// Writer	: Kim, YeLin (MRAS)
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "UdpClientWork.h"

CUdpClientWork::CUdpClientWork(std::string name)
    :CWorkBase(name)
{
    memset(&_kuka, 0, sizeof(KuKaData_t));
    memset(&_kukaDesired, 0, sizeof(KuKaData_t));

    _memname_kuka = name + "_KuKa";                         
    CREATE_SYSTEM_MEMORY(_memname_kuka, KuKaData_t);    // ex) "UdpClientWork_KuKa"��� �̸��� system memory ����

    _isOpen = false;
}


CUdpClientWork::~CUdpClientWork() {

    DELETE_SYSTEM_MEMORY(_memname_kuka);                // ������ "UdpClientWork_KuKa" system memory ����

    Close();
}

bool CUdpClientWork::Open() {

    /* UDP Socket Connection */

    _isOpen = true;
    return _isOpen;
}


void CUdpClientWork::Close() {

    /* UDP Socket Disconnection */

    _isOpen = false;
}

void CUdpClientWork::_execute() {

    //GET_SYSTEM_MEMORY("Work_Data", _kukaDesired);       // "Work_Data"��� �̸��� system memory���� ������, _kukaDesired ������ ���

    if (_isOpen) {
        _kuka.pos[0] += 1;
		SET_SYSTEM_MEMORY(_memname_kuka, _kuka);        // "UdpClientWork_KuKa"��� �̸��� system memory�� _kuka ���� ���� ����
    }
}