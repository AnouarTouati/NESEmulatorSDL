#pragma once
#include "../NESEmulatorSDL/src/CoreHeaders.h"
#include "../NESEmulatorSDL/src/NESComponents.h"
#include "../NESEmulatorSDL/src/CPU.h"

///Avoid working on folded regions of Memory


#define TargetDataAddress_IME_MODE  0x0001
#define TargetDataAddress_ZABS_MODE  0x00A0
#define TargetDataAddress_ZINX_MODE  0x00A1
#define TargetDataAddress_ABS_MODE  0xB0A0
#define TargetDataAddress_INX_X_MODE  0xB0A1
#define TargetDataAddress_INX_Y_MODE  0xB0A1
#define TargetDataAddress_PRII_MODE  0xF0
#define TargetDataAddress_POII_MODE  0xC0B1


CPU* CreateIME_Instruction(uint8_t InstructionOPcode, uint8_t ImmediateValue, uint8_t** OriginalMainMemory) {
	OriginalMainMemory = CreateMainMemory();
	CPU* aCPU = new CPU(NULL, OriginalMainMemory, NULL);
	*OriginalMainMemory[0x0000] = InstructionOPcode;
	*OriginalMainMemory[0x0001] = ImmediateValue;

	return aCPU;
}
CPU* CreateZABS_Instruction(uint8_t InstructionOPcode, uint8_t ValueThatWillBeRetrievedOnExecution, uint8_t** OriginalMainMemory) {
	OriginalMainMemory = CreateMainMemory();
	CPU* aCPU = new CPU(NULL, OriginalMainMemory, NULL);
	*OriginalMainMemory[0x0000] = InstructionOPcode;
	*OriginalMainMemory[0x0001] = 0xA0;
	*OriginalMainMemory[0x00A0] = ValueThatWillBeRetrievedOnExecution;
	return aCPU;
}
CPU* CreateZINX_Instruction(uint8_t InstructionOPcode, uint8_t ValueThatWillBeRetrievedOnExecution, uint8_t** OriginalMainMemory) {
	OriginalMainMemory = CreateMainMemory();
	CPU* aCPU= new CPU(NULL, OriginalMainMemory, NULL);
	*OriginalMainMemory[0x0000] = InstructionOPcode;
	*OriginalMainMemory[0x0001] = 0xA0;
	aCPU->X = 0x01;
	*OriginalMainMemory[0x00A1] = ValueThatWillBeRetrievedOnExecution;
	return aCPU;
}
CPU* CreateABS_Instruction(uint8_t InstructionOPcode, uint8_t ValueThatWillBeRetrievedOnExecution, uint8_t** OriginalMainMemory) {
	OriginalMainMemory = CreateMainMemory();
	CPU* aCPU = new CPU(NULL, OriginalMainMemory, NULL);
	*OriginalMainMemory[0x0000] = InstructionOPcode;
	*OriginalMainMemory[0x0001] = 0xA0;
	*OriginalMainMemory[0x0002] = 0xB0;
	*OriginalMainMemory[0xB0A0] = ValueThatWillBeRetrievedOnExecution;
	return aCPU;
}
CPU* CreateINX_X_Instruction(uint8_t InstructionOPcode, uint8_t ValueThatWillBeRetrievedOnExecution, uint8_t** OriginalMainMemory) {
	OriginalMainMemory = CreateMainMemory();
	CPU* aCPU = new CPU(NULL, OriginalMainMemory, NULL);
	*OriginalMainMemory[0x0000] = InstructionOPcode;
	*OriginalMainMemory[0x0001] = 0xA0;
	*OriginalMainMemory[0x0002] = 0xB0;
	aCPU->X = 0x01;
	*OriginalMainMemory[0xB0A1] = ValueThatWillBeRetrievedOnExecution;
	return aCPU;
}
CPU* CreateINX_Y_Instruction(uint8_t InstructionOPcode, uint8_t ValueThatWillBeRetrievedOnExecution, uint8_t** OriginalMainMemory) {
	OriginalMainMemory = CreateMainMemory();
	CPU* aCPU = new CPU(NULL, OriginalMainMemory, NULL);
	*OriginalMainMemory[0x0000] = InstructionOPcode;
	*OriginalMainMemory[0x0001] = 0xA0;
	*OriginalMainMemory[0x0002] = 0xB0;
	aCPU->Y = 0x01;
	*OriginalMainMemory[0xB0A1] = ValueThatWillBeRetrievedOnExecution;
	return aCPU;
}
CPU* CreatePRII_Instruction(uint8_t InstructionOPcode, uint8_t ValueThatWillBeRetrievedOnExecution, uint8_t** OriginalMainMemory) {
	OriginalMainMemory = CreateMainMemory();
	CPU* aCPU = new CPU(NULL, OriginalMainMemory, NULL);
	*OriginalMainMemory[0x0000] = InstructionOPcode;
	*OriginalMainMemory[0x0001] = 0xA0;//instruction data
	aCPU->X = 0x01;
	*OriginalMainMemory[0xA1] = 0xF0;
	*OriginalMainMemory[0xF0] = ValueThatWillBeRetrievedOnExecution;
	return aCPU;
}
CPU* CreatePOII_Instruction(uint8_t InstructionOPcode, uint8_t ValueThatWillBeRetrievedOnExecution, uint8_t** OriginalMainMemory) {
	OriginalMainMemory = CreateMainMemory();
	CPU* aCPU = new CPU(NULL, OriginalMainMemory, NULL);
	*OriginalMainMemory[0x0000] = InstructionOPcode;
	*OriginalMainMemory[0x0001] = 0xA0;

	*OriginalMainMemory[0x00A0] = 0xB0;
	*OriginalMainMemory[0x00A1] = 0xC0;
	aCPU->Y = 0x01;
	*OriginalMainMemory[0xC0B1] = ValueThatWillBeRetrievedOnExecution;
	return aCPU;
}
CPU* CreateACC_Instruction(uint8_t InstructionOPcode, uint8_t** OriginalMainMemory) {
	OriginalMainMemory = CreateMainMemory();
	CPU* aCPU = new CPU(NULL, OriginalMainMemory, NULL);
	*OriginalMainMemory[0x0000] = InstructionOPcode;
	
	return aCPU;
}