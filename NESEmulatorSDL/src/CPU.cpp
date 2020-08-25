#include "CPU.h"

	void  CPU::ExecuteNextInstruction() {
		FinishedExecutingCurrentInsctruction = false;
		//LOG_INFO("Executing Instructions ...");
		uint8_t OPCode = *CPUMemory[PC];
		//IME Immediate
		//ABS Absolute
		//ZABS Zeropage Absolute
		//IMP implied
		//ACC Accumulator
		//INX Indexed
		//ZINX Zero Page Indexed X register only
		//ZINY Zero Page Indexed Y
		//IND Indirect applies only to Jump instruction
		//PRII Pre Indexed Indirect
		//POII Post Indexed Indirect
		//REL Relative // signed number added to PC
	
		switch (OPCode) {
			
		case 0x00:  BRK(); break;
		case 0x01:  ORA_PRII(); break;
		//
	    case 0x05:  ORA_ZABS(); break;
		case 0x06:  ASL_ZABS(); break;
		//
		case 0x08:  PHP(); break;
		case 0x09:  ORA_IME(); break;
		case 0x0A:  ASL_ACC(); break;
		//
		case 0x0D:  ORA_ABS(); break;
		case 0x0E:  ASL_ABS(); break;
		//
		case 0x10:  BPL(); break;
		case 0x11:  ORA_POII(); break;
		
		case 0x15: ORA_ZINX (); break;
		case 0x16: ASL_ZINX (); break;
		//
		case 0x18:  CLC(); break;
		case 0x19:  ORA_INX_Y(); break;
		//
		case 0x1D:  ORA_INX_X(); break;
		case 0x1E:  ASL_INX_X(); break;
		//
		case 0x20:  JSR(); break;
		case 0x21:  AND_PRII(); break;
		//
		case 0x24:  BIT_ZABS(); break;
		case 0x25:  AND_ZABS(); break;
		case 0x26:  ROL_ZABS(); break;
		//
		case 0x28:  PLP(); break;
		case 0x29:  AND_IME(); break;
		case 0x2A:  ROL_ACC(); break;
		//
		case 0x2C:  BIT_ABS(); break;
		case 0x2D:  AND_ABS(); break;
		case 0x2E:  ROL_ABS(); break;
		//
		case 0x30:  BMI(); break;
		case 0x31:  AND_POII(); break;
		//
		case 0x35:  AND_ZINX(); break;
		case 0x36:  ROL_ZINX(); break;
		//
		case 0x38:  SEC(); break;
		case 0x39:  AND_INX_Y(); break;
		//
		case 0x3D:  AND_INX_X(); break;
		case 0x3E:  ROL_INX_X(); break;
		case 0x40:  RTI(); break;
		case 0x41:  EOR_PRII(); break;
		case 0x45:  EOR_ZABS(); break;
		//case 0x46:  LSR_ZABS(); break;
		case 0x48:  PHA(); break;
		case 0x49:  EOR_IME(); break;
		//case 0x4A:  LSR_ACC(); break;
		case 0x4C:  JMP_ABS(); break;
		case 0x4D:  EOR_ABS(); break;
		//case 0x4E:  LSR_ABS(); break;
		case 0x50:  BVC(); break;
		case 0x51:  EOR_POII(); break;
		case 0x55:  EOR_ZINX(); break;
		//case 0x56:  LSR_ZINX(); break;
		case 0x58:  CLI(); break;
		case 0x59:  EOR_INX_Y(); break;
		case 0x5D:  EOR_INX_X(); break;
		//case 0x5E:  LSR_INX_X(); break;
		case 0x60:  RTS(); break;
		case 0x61:  ADC_PRII(); break;
		case 0x65:  ADC_ZABS(); break;
		case 0x66:  ROR_ZABS(); break;
		case 0x68:  PLA(); break;
		//
		//
		case 0x69:  ADC_IME(); break;
		//
		//
		//
		case 0x6A:  ROR_ACC(); break;
		case 0x6C:  JMP_IND(); break;
		case 0x6D:  ADC_ABS(); break;
		case 0x6E:  ROR_ABS(); break;
		case 0x70:  BVS(); break;
		case 0x71:  ADC_POII(); break;
		case 0x75:  ADC_ZINX(); break;
		case 0x76:  ROR_ZINX(); break;
		case 0x78:  SEI(); break;
		case 0x79:  ADC_INX_Y(); break;
		case 0x7D:  ADC_INX_X(); break;
		case 0x7E:  ROR_INX_X(); break;
		case 0x81:  STA_PRII(); break;
		case 0x84:  STY_ZABS(); break;
		case 0x85:  STA_ZABS(); break;
		case 0x86:  STX_ZABS(); break;
		case 0x88:  DEY(); break;
		case 0x8A:  TXA(); break;
		case 0x8C:  STY_ABS(); break;
		case 0x8D:  STA_ABS(); break;
		case 0x8E:  STX_ABS(); break;
		case 0x90:  BCC(); break;
		case 0x91:  STA_POII(); break;
		case 0x94:  STY_ZINX(); break;
		case 0x95:  STA_ZINX(); break;
		case 0x96:  STX_ZINY(); break;
		case 0x98:  TYA(); break;
		case 0x99:  STA_INX_Y(); break;
		case 0x9A:  TXS(); break;
		case 0x9D:  STA_INX_X(); break;
		case 0xA0:  LDY_IME(); break;
		case 0xA1:  LDA_PRII(); break;
	    case 0xA2:  LDX_IME(); break;
		case 0xA4:  LDY_ZABS(); break;
		case 0xA5:  LDA_ZABS(); break;
		case 0xA6:  LDX_ZABS(); break;
		case 0xA8:  TAY(); break;
		case 0xA9:  LDA_IME(); break;
		case 0xAA:  TAX(); break;
		case 0xAC:  LDY_ABS(); break;
		case 0xAD:  LDA_ABS(); break;
		case 0xAE:  LDX_ABS(); break;
		case 0xB0:  BCS(); break;
		case 0xB1:  LDA_POII(); break;
		case 0xB4:  LDY_ZINX(); break;
		case 0xB5:  LDA_ZINX(); break;
		case 0xB6:  LDX_ZINY(); break;
		case 0xB8:  CLV(); break;
		case 0xB9:  LDA_INX_Y(); break;
		case 0xBA:  TSX(); break;
		case 0xBC:  LDY_INX_X(); break;
		case 0xBD:  LDA_INX_X(); break;
		case 0xBE:  LDX_INX_Y(); break;
		case 0xC0:  CPY_IME(); break;
		case 0xC1:  CMP_PRII(); break;
		case 0xC4:  CPY_ZABS(); break;
		case 0xC5:  CMP_ZABS(); break;
		case 0xC6:  DEC_ZABS(); break;
		case 0xC8:  INY(); break;
		case 0xC9:  CMP_IME(); break;
		case 0xCA:  DEX(); break;
	    case 0xCC:  CPY_ABS(); break;
		case 0xCD:  CMP_ABS(); break;
		case 0xCE:  DEC_ABS(); break;
		case 0xD0:  BNE(); break;
		case 0xD1:  CMP_POII(); break;
		case 0xD5:  CMP_ZINX(); break;
		case 0xD6:  DEC_ZINX(); break;
		case 0xD8:  CLD(); break;
		case 0xD9:  CMP_INX_Y(); break;
		case 0xDD:  CMP_INX_X(); break;
		case 0xDE:  DEC_INX_X(); break;
		case 0xE0:  CPX_IME(); break;
		//case 0xE1:  SBC_PRII(); break;
		case 0xE4:  CPX_ZABS(); break;
		//case 0xE5:  SBC_ZABS(); break;
		case 0xE6:  INC_ZABS(); break;
		case 0xE8:  INX(); break;
		//case 0xE9:  SBC_IME(); break;
		case 0xEA:  NOP(); break;
		case 0xEC:  CPX_ABS(); break;
		//case 0xED:  SBC_ABS(); break;
		case 0xEE:  INC_ABS(); break;
		case 0xF0:  BEQ(); break;
		//case 0xF1:  SBC_POII(); break;
		//case 0xF5:  SBC_ZINX(); break;
		case 0xF6:  INC_ZINX(); break;
		case 0xF8:  SED(); break;
		//case 0xF9:  SBC_INX_Y(); break;
		//case 0xFD:  SBC_INX_X(); break;
		case 0xFE:  INC_INX_X(); break;
		//default:LOG_WARN("OPCode not supported"); break;
		}
		
	}

	void CPU::BaseROR(uint8_t InstructionLength, uint8_t* DataThaWillBeAltered) {
		bool CarryWas = GetCarry();
		if (*DataThaWillBeAltered & 0x01) {
			SetCarry();
		}
		else { ResetCarry(); }
		*DataThaWillBeAltered = *DataThaWillBeAltered >> 1;
		if (CarryWas == true) {
			*DataThaWillBeAltered = *DataThaWillBeAltered | 0x80;
		}
		BaseSZCheck(InstructionLength, *DataThaWillBeAltered);
	}
	/////////   ROR_INSTRUCTION
	void CPU::ROR_ACC() {
		//opcode 0x6A 1 byte long
		BaseROR(1, &A);
	}
	void CPU::ROR_ZABS() {
		//opcode 0x66 2 byte long
		BaseROR(2, GetPointerToDataInCPUMemoryUsing_ZABS_MODE());
	}
	void CPU::ROR_ZINX() {
		//opcode 0x76 2 byte long
		BaseROR(2, GetPointerToDataInCPUMemoryUsing_ZINX_MODE());
	}
	void CPU::ROR_ABS() {
		//opcode 0x6E 3 byte long
		BaseROR(3, GetPointerToDataInCPUMemoryUsing_ABS_MODE());
	}
	void CPU::ROR_INX_X() {
		//opcode 0x7E 3 byte long
		BaseROR(3, GetPointerToDataInCPUMemoryUsing_INX_X_MODE());
	}
	////////////////  END    ///////////////



	void CPU::BaseROL(uint8_t InstructionLength, uint8_t* DataThaWillBeAltered) {
		bool CarryWas = GetCarry();
		if (GetSignFromData(DataThaWillBeAltered)) {
			SetCarry();
		}
		else { ResetCarry(); }
		*DataThaWillBeAltered = *DataThaWillBeAltered << 1;
		if (CarryWas==true) {
			*DataThaWillBeAltered = *DataThaWillBeAltered | 0x01;
		}
		BaseSZCheck(InstructionLength, *DataThaWillBeAltered);
	}
	/////////   ROL_INSTRUCTION
	void CPU::ROL_ACC() {
		//opcode 0x2A 1 byte long
		BaseROL(1, &A);
	}
	void CPU::ROL_ZABS() {
		//opcode 0x26 2 byte long
		BaseROL(2, GetPointerToDataInCPUMemoryUsing_ZABS_MODE());
	}
	void CPU::ROL_ZINX() {
		//opcode 0x36 2 byte long
		BaseROL(2, GetPointerToDataInCPUMemoryUsing_ZINX_MODE());
	}
	void CPU::ROL_ABS() {
		//opcode 0x2E 3 byte long
		BaseROL(3, GetPointerToDataInCPUMemoryUsing_ABS_MODE());
	}
	void CPU::ROL_INX_X() {
		//opcode 0x3E 3 byte long
		BaseROL(3, GetPointerToDataInCPUMemoryUsing_INX_X_MODE());
	}
	////////////////  END    ///////////////

	/////////   EOR_INSTRUCTION
	void CPU::EOR_IME() {
		//OPCOE 0x49 2BYTES LONG
		A = A ^ *GetPointerToDataInCPUMemoryUsing_IME_MODE();
		BaseSZCheck(2, A);
	}
	void CPU::EOR_ZABS() {
		//opcode 0x45 2bytes long
		A = A ^ *GetPointerToDataInCPUMemoryUsing_ZABS_MODE();
		BaseSZCheck(2, A);
	}
	void CPU::EOR_ZINX() {
		//opcode 0x55 2bytes long
		A = A ^ *GetPointerToDataInCPUMemoryUsing_ZINX_MODE();
		BaseSZCheck(2, A);
	}
	void CPU::EOR_ABS() {
		//opcode 4D 3bytes long

		A = A ^ *GetPointerToDataInCPUMemoryUsing_ABS_MODE();
		BaseSZCheck(3, A);
	}
	void CPU::EOR_INX_X() {
		//opcode 5D 3bytes long
		A = A ^ *GetPointerToDataInCPUMemoryUsing_INX_X_MODE();
		BaseSZCheck(3, A);
	}
	void CPU::EOR_INX_Y() {
		//opcode 59 3bytes long
		A = A ^ *GetPointerToDataInCPUMemoryUsing_INX_Y_MODE();
		BaseSZCheck(3, A);
	}
	void CPU::EOR_PRII() {
		//opcode 41  2bytes long

		A = A ^ *GetPointerToDataInCPUMemoryUsing_PRII_MODE();
		BaseSZCheck(2, A);
	}
	void CPU::EOR_POII() {
		//opcode 51  2bytes long
		A = A ^ *GetPointerToDataInCPUMemoryUsing_POII_MODE();
		BaseSZCheck(2, A);
	}
	////////////////  END    ///////////////



	void CPU::BaseCOMPARE(uint8_t InstructionLength, uint8_t RegisterValue, uint8_t MemoryValue) {
		if (RegisterValue >= MemoryValue) {
			//we dont need a borrow thus SetCarry
			SetCarry();
		}
		else {
			ResetCarry();
		}
		if (RegisterValue == MemoryValue) {
			SetZero();
		}
		else {
			ResetZero();
		}
		uint8_t data = RegisterValue - MemoryValue;
		if (GetSignFromData(&data)) { SetSign(); }
		else { ResetSign(); }

		PC = PC + InstructionLength;
		FinishedExecutingCurrentInsctruction = true;
	}

	//////////// BRK INSTRUCTION
	void CPU::BRK() {
		//OPCODE 0x00 1 byte long
		PC = PC + 2;
		PushPCtoStack();
		SetBreak();
		PushToStack(P);
		SetInterruptDisbale();
		PC = Get16BitAddressFromMemoryLocation(0xFFFE);
		FinishedExecutingCurrentInsctruction = true;
	}
    ////////////    END ////////////

	///////////CMP_INSTRUCTIONS
	void CPU::CMP_IME() {
		//OPCODE 0xC9
		BaseCOMPARE(2, A, *GetPointerToDataInCPUMemoryUsing_IME_MODE());
	}
	void CPU::CMP_ZABS() {
		//opcode 0xC5
		BaseCOMPARE(2, A, *GetPointerToDataInCPUMemoryUsing_ZABS_MODE());
	}
	void CPU::CMP_ZINX() {
		//opcode 0xD5
		BaseCOMPARE(2, A, *GetPointerToDataInCPUMemoryUsing_ZINX_MODE());
	}
	void CPU::CMP_ABS() {
		//opcode 0xCD
		BaseCOMPARE(3, A, *GetPointerToDataInCPUMemoryUsing_ABS_MODE());
	}
	void CPU::CMP_INX_X() {
		//opcode 0xDD
		BaseCOMPARE(3, A, *GetPointerToDataInCPUMemoryUsing_INX_X_MODE());
	}
	void CPU::CMP_INX_Y() {
		//opcode 0xD9
		BaseCOMPARE(3, A, *GetPointerToDataInCPUMemoryUsing_INX_Y_MODE());
	}
	void CPU::CMP_PRII() {
		//opcode 0xC1
		BaseCOMPARE(2, A, *GetPointerToDataInCPUMemoryUsing_PRII_MODE());
	}
	void CPU::CMP_POII() {
		//opcode 0xD1
		BaseCOMPARE(2, A, *GetPointerToDataInCPUMemoryUsing_POII_MODE());
	}
	////////////    END //////////// 

	///////////CPX_INSTRUCTIONS
	void CPU::CPX_IME() {
		//OPCODE 0xE0
		BaseCOMPARE(2, X, *GetPointerToDataInCPUMemoryUsing_IME_MODE());
	}
	void CPU::CPX_ZABS() {
		//opcode 0xE4
		BaseCOMPARE(2, X, *GetPointerToDataInCPUMemoryUsing_ZABS_MODE());
	}
	void CPU::CPX_ABS() {
		//opcode 0xEC
		BaseCOMPARE(3, X, *GetPointerToDataInCPUMemoryUsing_ABS_MODE());
	}
	////////////    END //////////// 


	///////////CPY_INSTRUCTIONS
	void CPU::CPY_IME() {
		//OPCODE 0xC0
		BaseCOMPARE(2,Y,*GetPointerToDataInCPUMemoryUsing_IME_MODE());
	}
	void CPU::CPY_ZABS() {
		//opcode 0xC4
		BaseCOMPARE(2, Y, *GetPointerToDataInCPUMemoryUsing_ZABS_MODE());
	}
	void CPU::CPY_ABS() {
		//opcode 0xCC
		BaseCOMPARE(3, Y, *GetPointerToDataInCPUMemoryUsing_ABS_MODE());
	}
	////////////    END //////////// 


	///////// DECREMENT INSTRUCTIONS
	void CPU::DEC_ZABS() {
		//OPCODE 0xC6
		*GetPointerToDataInCPUMemoryUsing_ZABS_MODE() -= 1;
		BaseSZCheck(2, *GetPointerToDataInCPUMemoryUsing_ZABS_MODE());
	}
	void CPU::DEC_INX_X() {
		//OPCODE 0xDE
		*GetPointerToDataInCPUMemoryUsing_INX_X_MODE() -= 1;
		BaseSZCheck(3, *GetPointerToDataInCPUMemoryUsing_INX_X_MODE());
	}
	void CPU::DEC_ZINX() {
		//OPCODE 0xD6
		*GetPointerToDataInCPUMemoryUsing_ZINX_MODE() -= 1;
		BaseSZCheck(2, *GetPointerToDataInCPUMemoryUsing_ZINX_MODE());
	}
	void CPU::DEC_ABS() {
		//OPCODE 0xCE
		*GetPointerToDataInCPUMemoryUsing_ABS_MODE() -= 1;
		BaseSZCheck(3, *GetPointerToDataInCPUMemoryUsing_ABS_MODE());
	}

	///////////////////////////////////
	void CPU::DEX() {
		//0xCA
		X = X - 1;
		BaseSZCheck(1, X);

	}
	void CPU::DEY() {
		//0x88
		Y = Y - 1;
		BaseSZCheck(1, Y);
	}
	////////////    END //////////// 



	///////// INCREMENT INSTRUCTIONS
	void CPU::INC_ZABS() {
		//OPCODE 0xE6
		*GetPointerToDataInCPUMemoryUsing_ZABS_MODE() += 1;
		BaseSZCheck(2, *GetPointerToDataInCPUMemoryUsing_ZABS_MODE());
	}
	void CPU::INC_INX_X() {
		//OPCODE 0xFE
		*GetPointerToDataInCPUMemoryUsing_INX_X_MODE() += 1;
		BaseSZCheck(3, *GetPointerToDataInCPUMemoryUsing_INX_X_MODE());
	}
	void CPU::INC_ZINX() {
		//OPCODE 0xF6
		*GetPointerToDataInCPUMemoryUsing_ZINX_MODE() += 1;
		BaseSZCheck(2, *GetPointerToDataInCPUMemoryUsing_ZINX_MODE());
	}
	void CPU::INC_ABS() {
		//OPCODE 0xEE
		*GetPointerToDataInCPUMemoryUsing_ABS_MODE() += 1;
		BaseSZCheck(3, *GetPointerToDataInCPUMemoryUsing_ABS_MODE());
	}
	
	///////////////////////////////////
	void CPU::INX() {
		//0xE8
		X = X + 1;
		BaseSZCheck(1, X);
	
	}
	void CPU::INY() {
		//0xC8
		Y = Y + 1;
		BaseSZCheck(1, Y);
	}
	////////////    END //////////// 

	///////// JUMP INSTRUCTIONS
	void CPU::JSR() {
		//opcode 0x20 
		uint16_t address = Get16BitAddressFromMemoryLocation(PC + 1);

		PC = PC + 2;
		PushPCtoStack();

		PC = address;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::JMP_ABS() {
	   //OPCODE 0x4C
		PC = Get16BitAddressFromMemoryLocation(PC+1);
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::JMP_IND() {
		//opcode 0x6C
		PC =*CPUMemory[Get16BitAddressFromMemoryLocation(PC+1)];
		FinishedExecutingCurrentInsctruction = true;
	}
	////////////    END //////////// 

	/////////   LDA INSTRUCTIONS 
	void CPU::LDA_IME() {
		//opcode 0xA9 2 bytes long
		A = *GetPointerToDataInCPUMemoryUsing_IME_MODE();
		BaseSZCheck(2, A);
	}
	void CPU::LDA_ZABS() {
		//opcode 0xA5 2 bytes long
		A = *GetPointerToDataInCPUMemoryUsing_ZABS_MODE();
		BaseSZCheck(2, A);
	}
	void CPU::LDA_ZINX() {
		//opcode 0xB5 2 bytes long
		A = *GetPointerToDataInCPUMemoryUsing_ZINX_MODE();
		BaseSZCheck(2, A);
	}
	void CPU::LDA_ABS() {
		//opcode 0xAD 3 bytes long
		A = *GetPointerToDataInCPUMemoryUsing_ABS_MODE();
		BaseSZCheck(3, A);
	}
	void CPU::LDA_INX_X() {
		//opcode 0xBD 3 bytes long
		A = *GetPointerToDataInCPUMemoryUsing_INX_X_MODE();
		BaseSZCheck(3, A);
	}
	void CPU::LDA_INX_Y() {
		//opcode 0xB9 3 bytes long
		A = *GetPointerToDataInCPUMemoryUsing_INX_Y_MODE();
		BaseSZCheck(3, A);
	}
	void CPU::LDA_PRII() {
		//opcode 0xA1 2 bytes long
		 A= *GetPointerToDataInCPUMemoryUsing_PRII_MODE();
		BaseSZCheck(2, A);
	}
	void CPU::LDA_POII() {
		//opcode 0xB1 2 bytes long
		A = *GetPointerToDataInCPUMemoryUsing_POII_MODE();
		BaseSZCheck(2, A);
	}
	////////////////  END    /////////////// 

	int8_t CPU::InterruptRequestReset() {
		if (FinishedExecutingCurrentInsctruction) {
			PC = *CPUMemory[0xFFFD];
			PC = PC << 8;
			PC = PC | *CPUMemory[0xFFFC];
			return 0;
		}
		else {
			//LOG_ERROR("Calling Interrupt Methods Should only be called after Execute Method is Called");
			return -1;
		}
	}

	int8_t CPU::InterruptRequestMaskable() {
		if (FinishedExecutingCurrentInsctruction) {
			if ((P & 0b00000100) == 0) {
				ResetBreak();
				*CPUMemory[0x0100 + SP] = PC & 0x0F;
				SP--;
				*CPUMemory[0x0100 + SP] = (PC & 0xF0) >> 8;
				SP--;
				*CPUMemory[0x0100 + SP] = P;
				SP--;
				P = P | 0b00000100;//set I Flag
				PC = *CPUMemory[0xFFFF];
				PC = PC << 8;
				PC = PC | *CPUMemory[0xFFFE];
			}
			else {
				//I flag set ignore the interrupt
			}
			

			return 0;
		}
		else {
			//LOG_ERROR("Calling Interrupt Methods Should only be called after Execute Method is Called");
			return -1;
		}
	}

	int8_t CPU::InterruptRequestNonMaskable() {
		if (FinishedExecutingCurrentInsctruction) {
			//only maskbale by PPU control register 1 if bit 7 is reset
			if ((*PPUControlRegister1 & 0b10000000) != 0) {
				ResetBreak();
				*CPUMemory[0x0100 + SP] = PC & 0x0F;
				SP--;
				*CPUMemory[0x0100 + SP] = (PC & 0xF0) >> 8;
				SP--;
				*CPUMemory[0x0100 + SP] = P;
				SP--;
				P = P | 0b00000100;//set I Flag
				PC = *CPUMemory[0xFFFB];
				PC = PC << 8;
				PC = PC | *CPUMemory[0xFFFA];
			}
			else {
				//bit 7 of PPU Control register is reset ignore the interrupt
			}

			return 0;
		}
		else {
			//LOG_ERROR("Calling Interrupt Methods Should only be called after Execute Method is Called");
			return -1;
		}
	}
	
	//Check the sign and whether data is zero and Set/Reset flags appropriatly
	void CPU::BaseSZCheck(uint8_t InstructionLength, uint8_t DataToCheck) {
		if (DataToCheck == 0) { SetZero(); }
		else { ResetZero(); }

		if (GetSignFromData(&DataToCheck)) { SetSign(); }
		else { ResetSign(); }

		PC = PC + InstructionLength;
		FinishedExecutingCurrentInsctruction = true;
	}
	
	void CPU::BaseOverflowCheckOnAddition(uint8_t Value1, uint8_t Value2) {
	
		if (GetSignFromData(&Value1) != GetSignFromData(&Value2)) {
			//no overflow
			ResetOverflow();
		}
		else {
			//overflow is a possibility
			uint8_t sum = Value1 + Value2;
		
			if (GetSignFromData(&sum) != GetSignFromData(&Value2)) {
				//overflow happened
				SetOverflow();
			}
			else {
				ResetOverflow();
			}
		}

	}
    void CPU::ADC_IME() {
		//2 bytes instruction
		uint8_t Carry = 0;
		BaseOverflowCheckOnAddition(A, *GetPointerToDataInCPUMemoryUsing_IME_MODE());
		if (GetCarry()) {
			Carry = 1;
			uint8_t ByteSum = A + *GetPointerToDataInCPUMemoryUsing_IME_MODE();
			BaseOverflowCheckOnAddition(ByteSum, Carry);
		}
		uint16_t sum = A + *GetPointerToDataInCPUMemoryUsing_IME_MODE() + Carry;
		  /*if (!((A | *GetPointerToDataInCPUMemoryUsing_IME_MODE()) & 0x80) && ((A | sum) & 0x80)) {
			  SetOverflow();
		  }
		  else {
			  ResetOverflow();
		  }*/
		  if (sum & 0x0100) { SetCarry(); }
		  else { ResetCarry(); }
		  A = sum;//truncated
		  BaseSZCheck(2, A);
	}
	void CPU::ADC_ZABS() {
		//opcode 0X65 2 bytes instruction
		uint8_t Carry = 0;
		BaseOverflowCheckOnAddition(A, *GetPointerToDataInCPUMemoryUsing_ZABS_MODE());
		if (GetCarry()) {
			Carry = 1;
			uint8_t ByteSum = A + *GetPointerToDataInCPUMemoryUsing_ZABS_MODE();
			BaseOverflowCheckOnAddition(ByteSum, Carry);
		}
		uint16_t sum = A + *GetPointerToDataInCPUMemoryUsing_ZABS_MODE() + Carry;
	
		if (sum & 0x0100) { SetCarry(); }
		else { ResetCarry(); }
		A = sum;//truncated
		BaseSZCheck(2, A);
	}
	void CPU::ADC_ZINX() {
		//opcode 0x75 2 bytes instruction
		uint8_t Carry = 0;
		BaseOverflowCheckOnAddition(A, *GetPointerToDataInCPUMemoryUsing_ZINX_MODE());
		if (GetCarry()) {
			Carry = 1;
			uint8_t ByteSum = A + *GetPointerToDataInCPUMemoryUsing_ZINX_MODE();
			BaseOverflowCheckOnAddition(ByteSum, Carry);
		}
		uint16_t sum = A + *GetPointerToDataInCPUMemoryUsing_ZINX_MODE() + Carry;
		
		if (sum & 0x0100) { SetCarry(); }
		else { ResetCarry(); }
		A = sum;//truncated
		BaseSZCheck(2, A);
	}
	void CPU::ADC_ABS() {
		//opcode 0x6D 3 bytes instruction
		uint8_t Carry = 0;
		BaseOverflowCheckOnAddition(A, *GetPointerToDataInCPUMemoryUsing_ABS_MODE());
		if (GetCarry()) {
			Carry = 1;
			uint8_t ByteSum = A + *GetPointerToDataInCPUMemoryUsing_ABS_MODE();
			BaseOverflowCheckOnAddition(ByteSum, Carry);
		}
		uint16_t sum = A + *GetPointerToDataInCPUMemoryUsing_ABS_MODE() + Carry;
		
		if (sum & 0x0100) { SetCarry(); }
		else { ResetCarry(); }
		A = sum;//truncated
		BaseSZCheck(3, A);
	}
	void CPU::ADC_INX_X() {
		//opcode 0x7D 3 bytes instruction
		uint8_t Carry = 0;
		BaseOverflowCheckOnAddition(A, *GetPointerToDataInCPUMemoryUsing_INX_X_MODE());
		if (GetCarry()) {
			Carry = 1;
			uint8_t ByteSum = A + *GetPointerToDataInCPUMemoryUsing_INX_X_MODE();
			BaseOverflowCheckOnAddition(ByteSum, Carry);
		}
		uint16_t sum = A + *GetPointerToDataInCPUMemoryUsing_INX_X_MODE() + Carry;
		
		if (sum & 0x0100) { SetCarry(); }
		else { ResetCarry(); }
		A = sum;//truncated
		BaseSZCheck(3, A);
	}
	void CPU::ADC_INX_Y() {
		//opcode 0x79 3 bytes instruction
		uint8_t Carry = 0;
		BaseOverflowCheckOnAddition(A, *GetPointerToDataInCPUMemoryUsing_INX_Y_MODE());
		if (GetCarry()) {
			Carry = 1;
			uint8_t ByteSum = A + *GetPointerToDataInCPUMemoryUsing_INX_Y_MODE();
			BaseOverflowCheckOnAddition(ByteSum, Carry);
		}
		uint16_t sum = A + *GetPointerToDataInCPUMemoryUsing_INX_Y_MODE() + Carry;
		
		if (sum & 0x0100) { SetCarry(); }
		else { ResetCarry(); }
		A = sum;//truncated
		BaseSZCheck(3, A);
	}
	void CPU::ADC_PRII() {
		//opcdoe 0x61 2 bytes instruction
		uint8_t Carry = 0;
		BaseOverflowCheckOnAddition(A, *GetPointerToDataInCPUMemoryUsing_PRII_MODE());
		if (GetCarry()) {
			Carry = 1;
			uint8_t ByteSum = A + *GetPointerToDataInCPUMemoryUsing_PRII_MODE();
			BaseOverflowCheckOnAddition(ByteSum, Carry);
		}
		uint16_t sum = A + *GetPointerToDataInCPUMemoryUsing_PRII_MODE() + Carry;
		if (sum & 0x0100) { SetCarry(); }
		else { ResetCarry(); }
		A = sum;//truncated
		BaseSZCheck(2, A);
	}
	void CPU::ADC_POII() {
		//OPCODE 0X71 2 bytes instruction
		uint8_t Carry = 0;
		BaseOverflowCheckOnAddition(A, *GetPointerToDataInCPUMemoryUsing_POII_MODE());
		if (GetCarry()) {
			Carry = 1;
			uint8_t ByteSum = A + *GetPointerToDataInCPUMemoryUsing_POII_MODE();
			BaseOverflowCheckOnAddition(ByteSum, Carry);
		}
		uint16_t sum = A + *GetPointerToDataInCPUMemoryUsing_POII_MODE() + Carry;
		
		if (sum & 0x0100) { SetCarry(); }
		else { ResetCarry(); }
		A = sum;//truncated
		BaseSZCheck(2, A);
	}
	/////////   AND_INSTRUCTIONS
	void CPU::AND_IME() {
		//OPCOE 0x29 2BYTES LONG
		A = A & *GetPointerToDataInCPUMemoryUsing_IME_MODE();
		BaseSZCheck(2,A);
	}
	void CPU::AND_ZABS() {
		//opcode 0x25 2bytes long
		A = A & *GetPointerToDataInCPUMemoryUsing_ZABS_MODE();
		BaseSZCheck(2,A);
	}    
	void CPU::AND_ZINX() {
		//opcode 0x35 2bytes long
		A = A & *GetPointerToDataInCPUMemoryUsing_ZINX_MODE();
		BaseSZCheck(2,A);
   }
	void CPU::AND_ABS() {
		//opcode 2D 3bytes long
		
		A = A & *GetPointerToDataInCPUMemoryUsing_ABS_MODE();
		BaseSZCheck(3,A);
	}
	void CPU::AND_INX_X() {
		//opcode 3D 3bytes long
		A = A & *GetPointerToDataInCPUMemoryUsing_INX_X_MODE();
		BaseSZCheck(3,A);
	}
	void CPU::AND_INX_Y() {
		//opcode 39 3bytes long
		A = A & *GetPointerToDataInCPUMemoryUsing_INX_Y_MODE();
		BaseSZCheck(3,A);
	}
	void CPU::AND_PRII() {
		//opcode 21  2bytes long
		
		A = A & *GetPointerToDataInCPUMemoryUsing_PRII_MODE();
		BaseSZCheck(2,A);
	}
	void CPU::AND_POII() {
		//opcode 31  2bytes long
		
		A = A & *GetPointerToDataInCPUMemoryUsing_POII_MODE();
		BaseSZCheck(2,A);
	}
	////////////////  END    ///////////////

	/////////   ASL_INSTRUCTIONS
	void CPU::BaseASL(uint8_t InstructionLength,uint8_t* DataThaWillBeAltered) {
		if (GetSignFromData(DataThaWillBeAltered)) { SetCarry(); }
		else { ResetCarry(); }

		*DataThaWillBeAltered = *DataThaWillBeAltered << 1;

		if (*DataThaWillBeAltered == 0) { SetZero(); }
		else { ResetZero(); }
		if (GetSignFromData(DataThaWillBeAltered)) { SetSign(); }
		else { ResetSign(); }

		PC = PC + InstructionLength;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::ASL_ACC() {
		//opcode 0x0A 1byte long
		BaseASL(1, &A);
	}
	void CPU::ASL_ZABS() {
		//opcode 0x06 2bytes long
		BaseASL(2, GetPointerToDataInCPUMemoryUsing_ZABS_MODE());
	}
	void CPU::ASL_ZINX() {
		//opcode 0x16 2 bytes long
		BaseASL(2, GetPointerToDataInCPUMemoryUsing_ZINX_MODE());
	}
	void CPU::ASL_ABS() {
		//opcode 0x0E 3 bytes long
		BaseASL(3, GetPointerToDataInCPUMemoryUsing_ABS_MODE());
	}
	void CPU::ASL_INX_X() {
		//opcode 0x1E 3 bytes long
		BaseASL(3, GetPointerToDataInCPUMemoryUsing_INX_X_MODE());
	}
	////////////////  END    ///////////////

	/////////   BRANCH FAMILY INSTRUCTIONS 
	CPU::BaseBranchReturnType CPU::BaseBranch() {
		uint8_t SignedOperand = *GetPointerToDataInCPUMemoryUsing_IME_MODE(); //this jump value is signed
		bool Sign = GetSignFromData(&SignedOperand);
		uint8_t UnSignedOperand = SignedOperand & 0b01111111;//we mask the 7th bit to get the decimal value without a sign
		return { Sign , UnSignedOperand };
	}
	void CPU::BCC() {
		//opcode 0x90 2bytes
		//THE DOC FOR RELATIVE ADDRESSING IS CONTRADICTING THE DOC FOR PROGRAM COUNTER
		//IN THAT PC POINTS TO CURRENT INSTRUCTION BEING EXECUTED(which is used now) AND POINTING TO NEXT INSTRUCTION TO BE
		//EXECUTED
		CPU::BaseBranchReturnType BranchData = BaseBranch();
		
		if (GetCarry() == false)
		{
			if (BranchData.Sign) { PC = PC - BranchData.UnSignedOperand; }
			else { PC = PC + BranchData.UnSignedOperand; }
		}

		else { PC = PC + 2; }

		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::BCS() {
		//opcode 0xB0 2 BYTES LONG
		CPU::BaseBranchReturnType BranchData = BaseBranch();

		if (GetCarry() == true)
		{
			if (BranchData.Sign) { PC = PC - BranchData.UnSignedOperand; }
			else { PC = PC + BranchData.UnSignedOperand; }
		}

		else { PC = PC + 2; }

		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::BEQ() {
		//opcode 0xF0 2 BYTES LONG
		CPU::BaseBranchReturnType BranchData = BaseBranch();

		if (GetZero() == true)
		{
			if (BranchData.Sign) { PC = PC - BranchData.UnSignedOperand; }
			else { PC = PC + BranchData.UnSignedOperand; }
		}

		else { PC = PC + 2; }

		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::BMI() {
		//opcode 0x30 2 BYTES LONG
		CPU::BaseBranchReturnType BranchData = BaseBranch();

		if (GetSign() == true)
		{
			if (BranchData.Sign) { PC = PC - BranchData.UnSignedOperand; }
			else { PC = PC + BranchData.UnSignedOperand; }
		}

		else { PC = PC + 2; }

		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::BNE() {
		//opcode 0xD0 2 BYTES LONG
		CPU::BaseBranchReturnType BranchData = BaseBranch();

		if (GetZero() == false)
		{
			if (BranchData.Sign) { PC = PC - BranchData.UnSignedOperand; }
			else { PC = PC + BranchData.UnSignedOperand; }
		}

		else { PC = PC + 2; }

		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::BPL() {
		//opcode 0x10 2 BYTES LONG
		CPU::BaseBranchReturnType BranchData = BaseBranch();

		if (GetSign() == false)
		{
			if (BranchData.Sign) { PC = PC - BranchData.UnSignedOperand; }
			else { PC = PC + BranchData.UnSignedOperand; }
		}

		else { PC = PC + 2; }

		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::BVC() {
		//opcode 0x50 2 BYTES LONG
		CPU::BaseBranchReturnType BranchData = BaseBranch();

		if (GetOverflow() == false)
		{
			if (BranchData.Sign) { PC = PC - BranchData.UnSignedOperand; }
			else { PC = PC + BranchData.UnSignedOperand; }
		}

		else { PC = PC + 2; }

		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::BVS() {
		//opcode 0x70 2 BYTES LONG
		CPU::BaseBranchReturnType BranchData = BaseBranch();

		if (GetOverflow() == true)
		{
			if (BranchData.Sign) { PC = PC - BranchData.UnSignedOperand; }
			else { PC = PC + BranchData.UnSignedOperand; }
		}

		else { PC = PC + 2; }

		FinishedExecutingCurrentInsctruction = true;
	}
	////////////////  END    ///////////////

	/////////   BIT_INSTRUCTIONS
	void CPU::BIT_ABS() {
		//opcode 0x2C 3 byte long
		uint8_t AndResult = A & *GetPointerToDataInCPUMemoryUsing_ABS_MODE();
		bool IsBit7Set = AndResult & 0b10000000;//bit7 aka M7 in docs
		bool IsBit6Set = AndResult & 0b01000000;//bit6 aka M6 in docs

		if (IsBit7Set) { SetSign();}
		else { ResetSign(); }

		if (IsBit6Set) { SetOverflow(); }
		else { ResetOverflow(); }

		if (AndResult == 0) { SetZero(); }
		else { ResetZero(); }
		PC = PC + 3;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::BIT_ZABS() {
		//opcode 0x24 2 byte long
		uint8_t AndResult = A & *GetPointerToDataInCPUMemoryUsing_ZABS_MODE();
		bool IsBit7Set = AndResult & 0b10000000;//bit7 aka M7 in docs
		bool IsBit6Set = AndResult & 0b01000000;//bit6 aka M6 in docs

		if (IsBit7Set) { SetSign(); }
		else { ResetSign(); }

		if (IsBit6Set) { SetOverflow(); }
		else { ResetOverflow(); }

		if (AndResult == 0) { SetZero(); }
		else { ResetZero(); }
		PC = PC + 2;
		FinishedExecutingCurrentInsctruction = true;
	}
	////////////////  END    /////////////// 

	/////////   OperationsOnFlags_INSTRUCTIONS
	void CPU::CLC() {
		//opcode 0x18 1 byte long
		ResetCarry();
		PC = PC + 1;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::CLD() {
		//opcode 0xD8 1 byte long
		ResetDecimalMode();
		PC = PC + 1;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::CLI() {
		//opcode 0x58 1 byte long
		ResetInterruptDisable();
		PC = PC + 1;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::CLV() {
		//opcode 0xB8 1 byte long
		ResetOverflow();
		PC = PC + 1;
		FinishedExecutingCurrentInsctruction = true;
	}

	void CPU::SEC() {
		//opcode 0x38 1 byte long
		SetCarry();
		PC = PC + 1;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::SED() {
		//opcode 0xF8 1 byte long
		SetDecimalMode();
		PC = PC + 1;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::SEI() {
		//opcode 0x78 1 byte long
		SetInterruptDisbale();
		PC = PC + 1;
		FinishedExecutingCurrentInsctruction = true;
	}
	////////////////  END    /////////////// 
	
	/////////   TRANSFER FAMILY INSTRUCTIONS 
	void CPU::TYA() {
		//opcode 0x98 1 byte long
		A = Y;
		if (GetSignFromData(&A)) {SetSign();}
		else { ResetSign(); }
		if (A == 0) { SetZero(); }
		else { ResetZero(); }

		PC = PC + 1;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::TXS() {
		//OPCODE 0x9A 1 byte long
		SP = X;
		PC = PC + 1;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::TXA() {
		//opcode 0x8A 1 byte long
		A = X;
		if (GetSignFromData(&A)) { SetSign(); }
		else { ResetSign(); }
		if (A == 0) { SetZero(); }
		else { ResetZero(); }

		PC = PC + 1;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::TSX() {
		//opcode 0xBA 1 byte long
		X = SP;
		if (GetSignFromData(&X)) { SetSign(); }
		else { ResetSign(); }
		if (X == 0) { SetZero(); }
		else { ResetZero(); }

		PC = PC + 1;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::TAY() {
		//opcode 0xA8 1 byte long
		Y = A;
		if (GetSignFromData(&Y)) { SetSign(); }
		else { ResetSign(); }
		if (Y == 0) { SetZero(); }
		else { ResetZero(); }

		PC = PC + 1;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::TAX() {
		//opcode 0xAA 1 byte long
		X = A;
		if (GetSignFromData(&X)) { SetSign(); }
		else { ResetSign(); }
		if (X == 0) { SetZero(); }
		else { ResetZero(); }

		PC = PC + 1;
		FinishedExecutingCurrentInsctruction = true;
	}
	////////////////  END    /////////////// 

	/////////   STA INSTRUCTIONS 
	void CPU::STA_ZABS() {
		//opcode 0x85 2 bytes long
		*GetPointerToDataInCPUMemoryUsing_ZABS_MODE() = A;
		PC = PC + 2;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::STA_ZINX() {
		//opcode 0x95 2 bytes long
		*GetPointerToDataInCPUMemoryUsing_ZINX_MODE() = A;
		PC = PC + 2;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::STA_ABS() {
		//opcode 0x8D 3 bytes long
		*GetPointerToDataInCPUMemoryUsing_ABS_MODE() = A;
		PC = PC + 3;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::STA_INX_X() {
		//opcode 0x9D 3 bytes long
		*GetPointerToDataInCPUMemoryUsing_INX_X_MODE() = A;
		PC = PC + 3;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::STA_INX_Y() {
		//opcode 0x99 3 bytes long
		*GetPointerToDataInCPUMemoryUsing_INX_Y_MODE() = A;
		PC = PC + 3;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::STA_PRII() {
		//opcode 0x81 2 bytes long
		*GetPointerToDataInCPUMemoryUsing_PRII_MODE() = A;
		PC = PC + 2;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::STA_POII() {
		//opcode 0x91 2 bytes long
		*GetPointerToDataInCPUMemoryUsing_POII_MODE() = A;
		PC = PC + 2;
		FinishedExecutingCurrentInsctruction = true;
	}
	////////////////  END    /////////////// 

	/////////   STX INSTRUCTIONS 
	void CPU::STX_ZABS() {
		//opcode 0x86 2 bytes long
		*GetPointerToDataInCPUMemoryUsing_ZABS_MODE() = X;
		PC = PC + 2;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::STX_ZINY() {
		//opcode 0x96 2 bytes long
		*GetPointerToDataInCPUMemoryUsing_ZINY_MODE() = X;
		PC = PC + 2;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::STX_ABS() {
		//opcode 0x8E 3 bytes long
		*GetPointerToDataInCPUMemoryUsing_ABS_MODE() = X;
		PC = PC + 3;
		FinishedExecutingCurrentInsctruction = true;
	}
	////////////////  END    /////////////// 

	/////////   STY INSTRUCTIONS 
	void CPU::STY_ZABS() {
		//opcode 0x84 2 bytes long
		*GetPointerToDataInCPUMemoryUsing_ZABS_MODE() = Y;
		PC = PC + 2;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::STY_ZINX() {
		//opcode 0x94 2 bytes long
		*GetPointerToDataInCPUMemoryUsing_ZINX_MODE() = Y;
		PC = PC + 2;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::STY_ABS() {
		//opcode 0x8C 3 bytes long
		*GetPointerToDataInCPUMemoryUsing_ABS_MODE() = Y;
		PC = PC + 3;
		FinishedExecutingCurrentInsctruction = true;
	}
	////////////////  END    /////////////// 

	/////////   OPERATIONS WITH STACK INSTRUCTIONS 
	   //NOTE: JSR of JUMP_INSTRUCTIONS also uses the stack
	/// ////////////////////////////
	void CPU::RTS() {
		//opcode 0x60 1 byte long
		PC = PopPCfromStack() + 0x01;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::RTI() {
		//opcode 0x40 1 byte long
		P = PopStack();
		PC = PopPCfromStack();
		FinishedExecutingCurrentInsctruction = true;
	}
	///////////////////////////////
	void CPU::PLP() {
		//opcode 0x28 1 BYTE LONG
		P = PopStack();
		PC = PC + 1;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::PLA() {
		//opcode 0x68 1 BYTELONG
		A = PopStack();
		PC = PC + 1;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::PHP() {
		//opcode 0x08 1 BYTELONG
		SetBreak();
		PushToStack(P);
		PC = PC + 1;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::PHA() {
		//opcode 0x48 1 BYTELONG
		PushToStack(A);
		PC = PC + 1;
		FinishedExecutingCurrentInsctruction = true;
	}

	////////////////  END    /////////////// 

	/////////   NOP INSTRUCTION 
	void CPU::NOP() {
		//opcode 0xEA 1 byte long
		PC = PC + 1;
		FinishedExecutingCurrentInsctruction = true;
	}
	////////////////  END    ///////////////

	/////////   ORA_INSTRUCTION
	void CPU::ORA_IME() {
		//OPCOE 0x09 2BYTES LONG
		A = A | *GetPointerToDataInCPUMemoryUsing_IME_MODE();
		BaseSZCheck(2,A);
	}
	void CPU::ORA_ZABS() {
		//opcode 0x05 2bytes long
		A = A | *GetPointerToDataInCPUMemoryUsing_ZABS_MODE();
		BaseSZCheck(2,A);
	}
	void CPU::ORA_ZINX() {
		//opcode 0x15 2bytes long
		A = A | *GetPointerToDataInCPUMemoryUsing_ZINX_MODE();
		BaseSZCheck(2,A);
	}
	void CPU::ORA_ABS() {
		//opcode 0D 3bytes long

		A = A | *GetPointerToDataInCPUMemoryUsing_ABS_MODE();
		BaseSZCheck(3,A);
	}
	void CPU::ORA_INX_X() {
		//opcode 1D 3bytes long
		A = A | *GetPointerToDataInCPUMemoryUsing_INX_X_MODE();
		BaseSZCheck(3,A);
	}
	void CPU::ORA_INX_Y() {
		//opcode 19 3bytes long
		A = A | *GetPointerToDataInCPUMemoryUsing_INX_Y_MODE();
		BaseSZCheck(3,A);
	}
	void CPU::ORA_PRII() {
		//opcode 01  2bytes long

		A = A | *GetPointerToDataInCPUMemoryUsing_PRII_MODE();
		BaseSZCheck(2,A);
	}
	void CPU::ORA_POII() {
		//opcode 11  2bytes long
		A = A | *GetPointerToDataInCPUMemoryUsing_POII_MODE();
		BaseSZCheck(2,A);
	}
	////////////////  END    ///////////////

	/////////   LDY INSTRUCTIONS 
	void CPU::LDY_IME() {
		//opcode 0xA0 2 bytes long
		Y=*GetPointerToDataInCPUMemoryUsing_IME_MODE();
		BaseSZCheck(2, Y);
	}
	void CPU::LDY_ZABS() {
		//opcode 0xA4 2 bytes long
		Y=*GetPointerToDataInCPUMemoryUsing_ZABS_MODE();
		BaseSZCheck(2, Y);
	}
	void CPU::LDY_ZINX() {
		//opcode 0xB4 2 bytes long
		Y=*GetPointerToDataInCPUMemoryUsing_ZINX_MODE();
		BaseSZCheck(2, Y);
	}
	void CPU::LDY_ABS() {
		//opcode 0xAC 3 bytes long
		Y=*GetPointerToDataInCPUMemoryUsing_ABS_MODE();
		BaseSZCheck(3, Y);
	}
	void CPU::LDY_INX_X() {
		//opcode 0xBC 3 bytes long
		Y=*GetPointerToDataInCPUMemoryUsing_INX_X_MODE();
		BaseSZCheck(3, Y);
	}
	////////////////  END    /////////////// 

	/////////   LDX INSTRUCTIONS 
	void CPU::LDX_IME() {
		//opcode 0xA2 2 bytes long
		X = *GetPointerToDataInCPUMemoryUsing_IME_MODE();
		BaseSZCheck(2, X);
	}
	void CPU::LDX_ZABS() {
		//opcode 0xA6 2 bytes long
		 X= *GetPointerToDataInCPUMemoryUsing_ZABS_MODE();
		BaseSZCheck(2, X);
	}
	void CPU::LDX_ZINY() {
		//opcode 0xB6 2 bytes long
		X = *GetPointerToDataInCPUMemoryUsing_ZINY_MODE();
		BaseSZCheck(2, X);
	}
	void CPU::LDX_ABS() {
		//opcode 0xAE 3 bytes long
		X = *GetPointerToDataInCPUMemoryUsing_ABS_MODE();
		BaseSZCheck(3, X);
	}
	void CPU::LDX_INX_Y() {
		//opcode 0xBE 3 bytes long
		X = *GetPointerToDataInCPUMemoryUsing_INX_Y_MODE();
		BaseSZCheck(3, X);
	}
	////////////////  END    /////////////// 