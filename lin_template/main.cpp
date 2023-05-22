#include "ThreadWorker.h"
#include "SharedMemory.h"
#include "SystemMemory.h"
#include "DataType.h"

#include "UdpClientWork.h"

int main() {

	CThreadedWorker _udpClientWorker;
	_udpClientWorker.SetPeriod(UDP_TIME);
	_udpClientWorker.SetWork(CreateWork<CUdpClientWork>("UdpClientWork"));	// 생성할 Thread Work의 prefix

	KuKaData_t _kuka;

	if (((CUdpClientWork*)_udpClientWorker.GetWork())->Open()) {
		_udpClientWorker.StartWork();
		printf("UDP  Open \n");
	}
	else {
		printf("UDP  Can't Open \n");
		return -1;
	}

	while (_udpClientWorker.isRunning()) {
		GET_SYSTEM_MEMORY("UdpClientWork_KuKa", _kuka);						// UdpClientWork 생성자에서 prefix "+_KuKa"
		printf("_kuka.pos[0] = %d         \r", (int)_kuka.pos[0]);
	};

	_udpClientWorker.StopWork();
	((CUdpClientWork*)_udpClientWorker.GetWork())->Close();
	printf("UDP  Closed \n");

	return 0;
}