//////////////////////////////////////////////////////////////////////////////////////////////////////////
// File		: DataType.h
// Version	: 1.0.1
// Date		: 2022.08.31
// Writer	: Kim, YeLin (MRAS)
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#define DEG2RAD						0.0174533
#define RAD2DEG						57.2958

#define INV_LINEAR_RESOLUTION		1000./0.006 	// [mm]
#define INV_ANGULAR_RESOLUTION		1./0.09			// [deg]

#define GA							-9.80665





typedef struct _stmData {

	double fdb[3];
	
}StmData_t;

typedef struct _recvPacketData {

	unsigned char header[4];
	unsigned char size, id;
	unsigned char mode, check;
	
	int fdb[3];

}RecvPacketData_t;

typedef union _recvPacket {

	RecvPacketData_t data;
	unsigned char buffer[sizeof(RecvPacketData_t)];

}RecvPacket_t;





typedef struct _kukaData {

	double pos[3];
	double ori[3];

	double force[3];
	double torq[3];

	double jpos[7];
	double jtorq[7];

}KuKaData_t;