#include "pch.h"
#include "CppUnitTest.h"
#include "../NESEmulatorSDL/src/NESComponents.h"
#include "../NESEmulatorSDL/src/CPU.h"

#include "../NESEmulatorSDL/src/CoreHeaders.h"
#include "HelperMethods.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(MEMORY_TESTS)
	{

	public:

		uint8_t** CPUMemory;
		uint8_t** PPUMemory;
	
		TEST_METHOD(PPUMemoryFoldTest)
		{
			PPUMemory = CreatePPUMemory();
			//test section 1 SETUP
			*PPUMemory[0x2000] = 11;
			*PPUMemory[0x2800] = 22;
			*PPUMemory[0x2BC0] = 33;	
			/// /////////////////////////////////////////
		
			//test section 2 SETUP
			*PPUMemory[0x3F00] = 44;
			*PPUMemory[0x3F10] = 55;
			*PPUMemory[0x3F15] = 66;
			/// /////////////////////////////////////////

			//test section 1
			Assert::AreEqual(11, (int)*PPUMemory[0x2000]);
			Assert::AreEqual(11, (int)*PPUMemory[0x3000]);

			
			Assert::AreEqual(22, (int)*PPUMemory[0x2800]);
			Assert::AreEqual(22, (int)*PPUMemory[0x3800]);

		
			Assert::AreEqual(33, (int)*PPUMemory[0x2BC0]);
			Assert::AreEqual(33, (int)*PPUMemory[0x3BC0]);
			/// /////////////////////////////////////////
			

			//test section 2
			Assert::AreEqual(44, (int)*PPUMemory[0x3F00]);
			Assert::AreEqual(44, (int)*PPUMemory[0x3F20]);
			Assert::AreEqual(44, (int)*PPUMemory[0x3F40]);
			Assert::AreEqual(44, (int)*PPUMemory[0x3F60]);

			Assert::AreEqual(55, (int)*PPUMemory[0x3F10]);
			Assert::AreEqual(55, (int)*PPUMemory[0x3F30]);
			Assert::AreEqual(55, (int)*PPUMemory[0x3F50]);
			Assert::AreEqual(55, (int)*PPUMemory[0x3F70]);

			Assert::AreEqual(66, (int)*PPUMemory[0x3F15]);
			Assert::AreEqual(66, (int)*PPUMemory[0x3F35]);
			Assert::AreEqual(66, (int)*PPUMemory[0x3F55]);
			Assert::AreEqual(66, (int)*PPUMemory[0x3F75]);
			/// /////////////////////////////////////////
		

			//test section 3
			Assert::AreEqual(11, (int)*PPUMemory[0x2000+0x4000]);
			Assert::AreEqual(11, (int)*PPUMemory[0x3000 + 0x4000]);


			Assert::AreEqual(22, (int)*PPUMemory[0x2800 + 0x4000]);
			Assert::AreEqual(22, (int)*PPUMemory[0x3800 + 0x4000]);


			Assert::AreEqual(33, (int)*PPUMemory[0x2BC0 + 0x4000]);
			Assert::AreEqual(33, (int)*PPUMemory[0x3BC0 + 0x4000]);
		
			
			Assert::AreEqual(44, (int)*PPUMemory[0x3F00 + 0x4000]);
			Assert::AreEqual(44, (int)*PPUMemory[0x3F20 + 0x4000]);
			Assert::AreEqual(44, (int)*PPUMemory[0x3F40 + 0x4000]);
			Assert::AreEqual(44, (int)*PPUMemory[0x3F60 + 0x4000]);

			Assert::AreEqual(55, (int)*PPUMemory[0x3F10 + 0x4000]);
			Assert::AreEqual(55, (int)*PPUMemory[0x3F30 + 0x4000]);
			Assert::AreEqual(55, (int)*PPUMemory[0x3F50 + 0x4000]);
			Assert::AreEqual(55, (int)*PPUMemory[0x3F70 + 0x4000]);

			Assert::AreEqual(66, (int)*PPUMemory[0x3F15 + 0x4000]);
			Assert::AreEqual(66, (int)*PPUMemory[0x3F35 + 0x4000]);
			Assert::AreEqual(66, (int)*PPUMemory[0x3F55 + 0x4000]);
			Assert::AreEqual(66, (int)*PPUMemory[0x3F75 + 0x4000]);
			/// /////////////////////////////////////////


			//test section 4
			Assert::AreEqual(11, (int)*PPUMemory[0x2000+0x8000]);
			Assert::AreEqual(11, (int)*PPUMemory[0x3000 + 0x8000]);


			Assert::AreEqual(22, (int)*PPUMemory[0x2800 + 0x8000]);
			Assert::AreEqual(22, (int)*PPUMemory[0x3800 + 0x8000]);


			Assert::AreEqual(33, (int)*PPUMemory[0x2BC0 + 0x8000]);
			Assert::AreEqual(33, (int)*PPUMemory[0x3BC0 + 0x8000]);
		
			Assert::AreEqual(44, (int)*PPUMemory[0x3F00 + 0x8000]);
			Assert::AreEqual(44, (int)*PPUMemory[0x3F20 + 0x8000]);
			Assert::AreEqual(44, (int)*PPUMemory[0x3F40 + 0x8000]);
			Assert::AreEqual(44, (int)*PPUMemory[0x3F60 + 0x8000]);

			Assert::AreEqual(55, (int)*PPUMemory[0x3F10 + 0x8000]);
			Assert::AreEqual(55, (int)*PPUMemory[0x3F30 + 0x8000]);
			Assert::AreEqual(55, (int)*PPUMemory[0x3F50 + 0x8000]);
			Assert::AreEqual(55, (int)*PPUMemory[0x3F70 + 0x8000]);

			Assert::AreEqual(66, (int)*PPUMemory[0x3F15 + 0x8000]);
			Assert::AreEqual(66, (int)*PPUMemory[0x3F35 + 0x8000]);
			Assert::AreEqual(66, (int)*PPUMemory[0x3F55 + 0x8000]);
			Assert::AreEqual(66, (int)*PPUMemory[0x3F75 + 0x8000]);
			/// /////////////////////////////////////////
		}
	
		TEST_METHOD(CPUMemoryFoldTest) {
			CPUMemory = CreateCPUMemory();
			////////////////////////////////////////////////////////////////////////
			*CPUMemory[0x0000] = 11;
			*CPUMemory[0x0200] = 22;
			*CPUMemory[0x0450] = 33;
			Assert::AreEqual(11, (int)*CPUMemory[0x0000]);
			Assert::AreEqual(11, (int)*CPUMemory[0x0000+0x800]);
			Assert::AreEqual(11, (int)*CPUMemory[0x0000 + 0x800*2]);
			Assert::AreEqual(11, (int)*CPUMemory[0x0000 + 0x800 * 3]);

			Assert::AreEqual(22, (int)*CPUMemory[0x0200]);
			Assert::AreEqual(22, (int)*CPUMemory[0x0200 + 0x800]);
			Assert::AreEqual(22, (int)*CPUMemory[0x0200 + 0x800 * 2]);
			Assert::AreEqual(22, (int)*CPUMemory[0x0200 + 0x800 * 3]);

			Assert::AreEqual(33, (int)*CPUMemory[0x0450]);
			Assert::AreEqual(33, (int)*CPUMemory[0x0450 + 0x800]);
			Assert::AreEqual(33, (int)*CPUMemory[0x0450 + 0x800 * 2]);
			Assert::AreEqual(33, (int)*CPUMemory[0x0450 + 0x800 * 3]);
			///////////////////////////////////////////////////////////////////////////

			///////////////////////////////////////////////////////////////////////////
			*CPUMemory[0x2000] = 0;
			*CPUMemory[0x2001] = 1;
			*CPUMemory[0x2002] = 2;
			*CPUMemory[0x2003] = 3;
			*CPUMemory[0x2004] = 4;
			*CPUMemory[0x2005] = 5;
			*CPUMemory[0x2006] = 6;
			*CPUMemory[0x2007] = 7;

			for (int i = 0x2000; i < 0x4000; i += 8) {
				Assert::AreEqual(0, (int)*CPUMemory[i+0x0000]);
				Assert::AreEqual(1, (int)*CPUMemory[i+0x0001]);
				Assert::AreEqual(2, (int)*CPUMemory[i+0x0002]);
				Assert::AreEqual(3, (int)*CPUMemory[i+0x0003]);
				Assert::AreEqual(4, (int)*CPUMemory[i+0x0004]);
				Assert::AreEqual(5, (int)*CPUMemory[i+0x0005]);
				Assert::AreEqual(6, (int)*CPUMemory[i+0x0006]);
				Assert::AreEqual(7, (int)*CPUMemory[i+0x0007]);
			}
			///////////////////////////////////////////////////////////////////////////
		}

		TEST_METHOD(CPUMemoryDistinctCellsTest) {
			CPUMemory = CreateCPUMemory();
			long ActualSumOfRandomNumbers = 0;
			long SumOfRandomNumbersFromMemory = 0;

			for (int i = 0x0000; i < 0x10000; i++) {
				if (i == 0x0800) {
					//jump the folds
					i = 0x2000;
				}
				else if (i == 0x2008) {
					//jump the folds
					i = 0x4000;
				}
				int RandomNumber = rand() % 255;
				ActualSumOfRandomNumbers += RandomNumber;
				*CPUMemory[i] = RandomNumber;
			}

			for (int i = 0x0000; i < 0x10000; i++) {
				if (i == 0x0800) {
					//jump the folds
					i = 0x2000;
				}
				else if (i == 0x2008) {
					//jump the folds
					i = 0x4000;
				}
				SumOfRandomNumbersFromMemory +=(int) *CPUMemory[i];
			}
			Assert::AreEqual(ActualSumOfRandomNumbers, SumOfRandomNumbersFromMemory);
		}

		TEST_METHOD(PPUMemoryDistinctCellsTest) {
			PPUMemory = CreatePPUMemory();
			long ActualSumOfRandomNumvers = 0;
			long SumOfRandomNumbersFromMemory = 0;

			for (int i = 0x0000; i < 0x3F20; i++) {
				if (i == 0x3000) {
					//jump folds
					i = 0x3F00;
				}
				int RandomNumber = rand() % 255;
				ActualSumOfRandomNumvers += RandomNumber;
				*PPUMemory[i] = RandomNumber;
			}


			for (int i = 0x0000; i < 0x3F20; i++) {
				if (i == 0x3000) {
					//jump folds
					i = 0x3F00;
				}
				
				SumOfRandomNumbersFromMemory+= *PPUMemory[i];
			}
			Assert::AreEqual(ActualSumOfRandomNumvers, SumOfRandomNumbersFromMemory);
		}
		/*
		TEST_METHOD(ADC_IME) {
			//0x69 opcode of ADC_IME 
			//ADC_IME adds Accumulator + immediate value + carry
			CPUMemory = CreateMainMemory();
		    CPU aCPU(NULL, CPUMemory, NULL);

			*CPUMemory[0x0000] = 0x69;
			*CPUMemory[0x0001] = 0b01111000;
			aCPU.A = 0b11111111;
			//0b1111 1111 + 0b0111 1000 = 0b1 0111 0111
			aCPU.PC = 0x0000;
			Assert::AreEqual(0b00100000, (int)aCPU.P);
			aCPU.ExecuteNextInstruction();
			
			
			Assert::IsFalse(aCPU.GetOverflow());
			Assert::IsTrue(aCPU.GetCarry());
			Assert::IsFalse(aCPU.GetZero());
			Assert::IsFalse(aCPU.GetSign());
		}
		*/
	};
	TEST_CLASS(AND_INSTRUCTIONS) {
	public :
		

		TEST_METHOD(AND_IME) {
		
			CPU* aCPU;

			//TEST1
			aCPU=CreateIME_Instruction(0x29, 0b00000001);

			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
			

			///TEST2 false true
			aCPU = CreateIME_Instruction(0x29, 0b00000000);

			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
			


			//TEST3 true false
			aCPU = CreateIME_Instruction(0x29, 0b10000001);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b10000001, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
			
			//TEST4 true true impossible

		}
		TEST_METHOD(AND_ZABS) {
			//opcode 0x25 2bytes
			
			CPU* aCPU;

			//TEST1 false false
			aCPU = CreateZABS_Instruction(0x25, 0b00000001);

			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 false true
			 aCPU = CreateZABS_Instruction(0x25, 0b00000000);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3 true false
			aCPU = CreateZABS_Instruction(0x25, 0b10000001);
		
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b10000001, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		}
		TEST_METHOD(AND_ZINX) {
			//opcode 0x35
			
			CPU* aCPU;


			//TEST1 false false
			aCPU = CreateZINX_Instruction(0x35, 0b00000001);

			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 false true
			 aCPU = CreateZINX_Instruction(0x35, 0b00000000);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3 true false
			aCPU = CreateZINX_Instruction(0x35, 0b10000001);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b10000001, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(AND_ABS) {
			//opcode 0x2D 3bytes
			
			CPU* aCPU;


			//TEST1 false false
			aCPU = CreateABS_Instruction(0x2D, 0b00000001);

			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 false true
		    aCPU = CreateABS_Instruction(0x2D, 0b00000000);
		
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3 true false
			aCPU = CreateABS_Instruction(0x2D, 0b10000001);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b10000001, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(AND_INX_X) {
			//opcode 0x3D 3bytes
		
			CPU* aCPU;

			//TEST1 false false
			aCPU = CreateINX_X_Instruction(0x3D, 0b00000001);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 false true
			 aCPU = CreateINX_X_Instruction(0x3D, 0b00000000);
	
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3 true false
			aCPU = CreateINX_X_Instruction(0x3D, 0b10000001);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b10000001, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(AND_INX_Y) {
			//opcode 0x39 3bytes
			
			CPU* aCPU;

			//TEST1 false false
			aCPU = CreateINX_Y_Instruction(0x39, 0b00000001);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 false true
		     aCPU = CreateINX_Y_Instruction(0x39, 0b00000000);
		
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3 true false
			aCPU = CreateINX_Y_Instruction(0x39, 0b10000001);

			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b10000001, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(AND_PRII) {
			//opcode 0x21 2bytes
		
			CPU* aCPU;

			//TEST1 false false
			aCPU = CreatePRII_Instruction(0x21, 0b00000001);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 false true
			 aCPU = CreatePRII_Instruction(0x21, 0b00000000);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3 true false
			aCPU = CreatePRII_Instruction(0x21, 0b10000001);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b10000001, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(AND_POII) {
			//opcode 0x31 2bytes
			
			CPU* aCPU;

			//TEST1 false false
			aCPU = CreatePOII_Instruction(0x31, 0b00000001);
		
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 false true
			 aCPU = CreatePOII_Instruction(0x31, 0b00000000);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3 true false
			aCPU = CreatePOII_Instruction(0x31, 0b10000001);
		
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b10000001, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
	};
	TEST_CLASS(ASL_INSTRUCTIONS) {
		

		TEST_METHOD(ASL_ACC) {
			//opcoe 0x0A 1 byte long
			CPU* aCPU;
			//TEST1
			aCPU = CreateACC_Instruction(0x0A);

			Assert::IsFalse(aCPU->GetCarry());
			aCPU->A = 0b10000000;
			aCPU->ExecuteNextInstruction();
			Assert::IsTrue(aCPU->GetCarry());
			Assert::IsFalse(aCPU->GetSignFromData(&aCPU->A));
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0b00000000, (int)aCPU->A);

			Assert::AreEqual(0x01, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST2
			aCPU = CreateACC_Instruction(0x0A);

			Assert::IsFalse(aCPU->GetCarry());
			aCPU->A = 0b01000000;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetCarry());
			Assert::IsTrue(aCPU->GetSignFromData(&aCPU->A));
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0b10000000, (int)aCPU->A);

			Assert::AreEqual(0x01, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST3
			aCPU = CreateACC_Instruction(0x0A);

			Assert::IsFalse(aCPU->GetCarry());
			aCPU->A = 0b01000001;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetCarry());
			Assert::IsTrue(aCPU->GetSignFromData(&aCPU->A));
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0b10000010, (int)aCPU->A);

			Assert::AreEqual(0x01, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		}
		TEST_METHOD(ASL_ZABS) {
			//opcode 0x06 2 bytes long
			CPU* aCPU;
			//TEST1
			aCPU = CreateZABS_Instruction(0x06,0b10000000);

			Assert::IsFalse(aCPU->GetCarry());
			aCPU->ExecuteNextInstruction();
			Assert::IsTrue(aCPU->GetCarry());
			Assert::IsFalse(aCPU->GetSignFromData(aCPU->CPUMemory[TargetDataAddress_ZABS_MODE]));
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0b00000000, (int)*aCPU->CPUMemory[TargetDataAddress_ZABS_MODE]);

			Assert::AreEqual(0x02, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST2
			aCPU = CreateZABS_Instruction(0x06, 0b01000000);

			Assert::IsFalse(aCPU->GetCarry());
			aCPU->A = 0b01000000;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetCarry());
			Assert::IsTrue(aCPU->GetSignFromData(aCPU->CPUMemory[TargetDataAddress_ZABS_MODE]));
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0b10000000, (int)*aCPU->CPUMemory[TargetDataAddress_ZABS_MODE]);

			Assert::AreEqual(0x02, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST3
			aCPU = CreateZABS_Instruction(0x06, 0b01000001);

			Assert::IsFalse(aCPU->GetCarry());
			aCPU->A = 0b01000001;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetCarry());
			Assert::IsTrue(aCPU->GetSignFromData(aCPU->CPUMemory[TargetDataAddress_ZABS_MODE]));
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0b10000010, (int)*aCPU->CPUMemory[TargetDataAddress_ZABS_MODE]);

			Assert::AreEqual(0x02, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		}
		TEST_METHOD(ASL_ZINX) {
			//opcode 0x16 2 bytes long
			CPU* aCPU;
			//TEST1
			aCPU = CreateZINX_Instruction(0x16, 0b10000000);

			Assert::IsFalse(aCPU->GetCarry());
			aCPU->ExecuteNextInstruction();
			Assert::IsTrue(aCPU->GetCarry());
			Assert::IsFalse(aCPU->GetSignFromData(aCPU->CPUMemory[TargetDataAddress_ZINX_MODE]));
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0b00000000, (int)*aCPU->CPUMemory[TargetDataAddress_ZINX_MODE]);

			Assert::AreEqual(0x02, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST2
			aCPU = CreateZINX_Instruction(0x16, 0b01000000);

			Assert::IsFalse(aCPU->GetCarry());
			aCPU->A = 0b01000000;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetCarry());
			Assert::IsTrue(aCPU->GetSignFromData(aCPU->CPUMemory[TargetDataAddress_ZINX_MODE]));
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0b10000000, (int)*aCPU->CPUMemory[TargetDataAddress_ZINX_MODE]);

			Assert::AreEqual(0x02, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST3
			aCPU = CreateZINX_Instruction(0x16, 0b01000001);

			Assert::IsFalse(aCPU->GetCarry());
			aCPU->A = 0b01000001;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetCarry());
			Assert::IsTrue(aCPU->GetSignFromData(aCPU->CPUMemory[TargetDataAddress_ZINX_MODE]));
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0b10000010, (int)*aCPU->CPUMemory[TargetDataAddress_ZINX_MODE]);

			Assert::AreEqual(0x02, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

}
		TEST_METHOD(ASL_ABS) {
			//opcode 0x0E 3 bytes long
			CPU* aCPU;
			//TEST1
			aCPU = CreateABS_Instruction(0x0E, 0b10000000);

			Assert::IsFalse(aCPU->GetCarry());
			aCPU->ExecuteNextInstruction();
			Assert::IsTrue(aCPU->GetCarry());
			Assert::IsFalse(aCPU->GetSignFromData(aCPU->CPUMemory[TargetDataAddress_ABS_MODE]));
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0b00000000, (int)*aCPU->CPUMemory[TargetDataAddress_ABS_MODE]);

			Assert::AreEqual(0x03, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST2
			aCPU = CreateABS_Instruction(0x0E, 0b01000000);

			Assert::IsFalse(aCPU->GetCarry());
			aCPU->A = 0b01000000;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetCarry());
			Assert::IsTrue(aCPU->GetSignFromData(aCPU->CPUMemory[TargetDataAddress_ABS_MODE]));
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0b10000000, (int)*aCPU->CPUMemory[TargetDataAddress_ABS_MODE]);

			Assert::AreEqual(0x03, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST3
			aCPU = CreateABS_Instruction(0x0E, 0b01000001);

			Assert::IsFalse(aCPU->GetCarry());
			aCPU->A = 0b01000001;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetCarry());
			Assert::IsTrue(aCPU->GetSignFromData(aCPU->CPUMemory[TargetDataAddress_ABS_MODE]));
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0b10000010, (int)*aCPU->CPUMemory[TargetDataAddress_ABS_MODE]);

			Assert::AreEqual(0x03, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(ASL_INX_X) {
			//opcode 0x1E 3 bytes long
			CPU* aCPU;
			//TEST1
			aCPU = CreateINX_X_Instruction(0x1E, 0b10000000);

			Assert::IsFalse(aCPU->GetCarry());
			aCPU->ExecuteNextInstruction();
			Assert::IsTrue(aCPU->GetCarry());
			Assert::IsFalse(aCPU->GetSignFromData(aCPU->CPUMemory[TargetDataAddress_INX_X_MODE]));
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0b00000000, (int)*aCPU->CPUMemory[TargetDataAddress_INX_X_MODE]);

			Assert::AreEqual(0x03, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST2
			aCPU = CreateINX_X_Instruction(0x1E, 0b01000000);

			Assert::IsFalse(aCPU->GetCarry());
			aCPU->A = 0b01000000;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetCarry());
			Assert::IsTrue(aCPU->GetSignFromData(aCPU->CPUMemory[TargetDataAddress_INX_X_MODE]));
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0b10000000, (int)*aCPU->CPUMemory[TargetDataAddress_INX_X_MODE]);

			Assert::AreEqual(0x03, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST3
			aCPU = CreateINX_X_Instruction(0x1E, 0b01000001);

			Assert::IsFalse(aCPU->GetCarry());
			aCPU->A = 0b01000001;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetCarry());
			Assert::IsTrue(aCPU->GetSignFromData(aCPU->CPUMemory[TargetDataAddress_INX_X_MODE]));
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0b10000010, (int)*aCPU->CPUMemory[TargetDataAddress_INX_X_MODE]);

			Assert::AreEqual(0x03, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		
	};
	TEST_CLASS(BRANCH_INSTRUCTIONS_FAMILY) {
		
		
		TEST_METHOD(BCC) {
			//opcode 0x90 2bytes
			CPU* aCPU;

			////// BACKWARD DISPLACEMENT IF ResetCarry
			//TEST1
			aCPU = CreatBRANCH_FAMILY_Instruction(0x90, 0b10000010);
			aCPU->ResetCarry();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x7FFE, (int)aCPU->PC);

			//TEST2
			aCPU = CreatBRANCH_FAMILY_Instruction(0x90, 0b10000010);
			aCPU->SetCarry();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8002, (int)aCPU->PC);

			////// FORWARD DISPLACEMENT IF ResetCarry

			//TEST3
			/// Forward Displacment should atleast be 2 to pass this instruction length
			aCPU = CreatBRANCH_FAMILY_Instruction(0x90, 0b00000100);
			aCPU->ResetCarry();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8004, (int)aCPU->PC);

			//TEST4
			aCPU = CreatBRANCH_FAMILY_Instruction(0x90, 0b10000100);
			aCPU->SetCarry();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8002, (int)aCPU->PC);
		}
		TEST_METHOD(BCS) {
			//opcode 0xB0 2bytes
			CPU* aCPU;

			////// BACKWARD DISPLACEMENT IF SetCarry
			//TEST1
			aCPU = CreatBRANCH_FAMILY_Instruction(0xB0, 0b10000010);
			aCPU->SetCarry();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x7FFE, (int)aCPU->PC);

			//TEST2
			aCPU = CreatBRANCH_FAMILY_Instruction(0xB0, 0b10000010);
			aCPU->ResetCarry();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8002, (int)aCPU->PC);

			////// FORWARD DISPLACEMENT IF SetCarry

			//TEST3
			/// Forward Displacment should atleast be 2 to pass this instruction length
			aCPU = CreatBRANCH_FAMILY_Instruction(0xB0, 0b00000100);
			aCPU->SetCarry();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8004, (int)aCPU->PC);

			//TEST4
			aCPU = CreatBRANCH_FAMILY_Instruction(0xB0, 0b10000100);
			aCPU->ResetCarry();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8002, (int)aCPU->PC);
		}
		TEST_METHOD(BEQ) {
			//opcode 0xF0 2bytes
			CPU* aCPU;

			////// BACKWARD DISPLACEMENT IF SetCarry
			//TEST1
			aCPU = CreatBRANCH_FAMILY_Instruction(0xF0, 0b10000010);
			aCPU->SetZero();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x7FFE, (int)aCPU->PC);

			//TEST2
			aCPU = CreatBRANCH_FAMILY_Instruction(0xF0, 0b10000010);
			aCPU->ResetZero();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8002, (int)aCPU->PC);

			////// FORWARD DISPLACEMENT IF SetCarry

			//TEST3
			/// Forward Displacment should atleast be 2 to pass this instruction length
			aCPU = CreatBRANCH_FAMILY_Instruction(0xF0, 0b00000100);
			aCPU->SetZero();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8004, (int)aCPU->PC);

			//TEST4
			aCPU = CreatBRANCH_FAMILY_Instruction(0xF0, 0b10000100);
			aCPU->ResetZero();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8002, (int)aCPU->PC);
		}
		TEST_METHOD(BMI) {
			//opcode 0x30 2bytes
			CPU* aCPU;

			////// BACKWARD DISPLACEMENT IF SetCarry
			//TEST1
			aCPU = CreatBRANCH_FAMILY_Instruction(0x30, 0b10000010);
			aCPU->SetSign();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x7FFE, (int)aCPU->PC);

			//TEST2
			aCPU = CreatBRANCH_FAMILY_Instruction(0x30, 0b10000010);
			aCPU->ResetSign();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8002, (int)aCPU->PC);

			////// FORWARD DISPLACEMENT IF SetCarry

			//TEST3
			/// Forward Displacment should atleast be 2 to pass this instruction length
			aCPU = CreatBRANCH_FAMILY_Instruction(0x30, 0b00000100);
			aCPU->SetSign();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8004, (int)aCPU->PC);

			//TEST4
			aCPU = CreatBRANCH_FAMILY_Instruction(0x30, 0b10000100);
			aCPU->ResetSign();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8002, (int)aCPU->PC);
		}
		TEST_METHOD(BNE) {
			//opcode 0xD0 2bytes
			uint8_t OPCode = 0xD0;
			CPU* aCPU;

			////// BACKWARD DISPLACEMENT IF SetCarry
			//TEST1
			aCPU = CreatBRANCH_FAMILY_Instruction(OPCode, 0b10000010);
			aCPU->ResetZero();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x7FFE, (int)aCPU->PC);

			//TEST2
			aCPU = CreatBRANCH_FAMILY_Instruction(OPCode, 0b10000010);
			aCPU->SetZero();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8002, (int)aCPU->PC);

			////// FORWARD DISPLACEMENT IF SetCarry

			//TEST3
			/// Forward Displacment should atleast be 2 to pass this instruction length
			aCPU = CreatBRANCH_FAMILY_Instruction(OPCode, 0b00000100);
			aCPU->ResetZero();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8004, (int)aCPU->PC);

			//TEST4
			aCPU = CreatBRANCH_FAMILY_Instruction(OPCode, 0b10000100);
			aCPU->SetZero();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8002, (int)aCPU->PC);
		}
		TEST_METHOD(BPL) {
			//opcode 0x10 2bytes
			uint8_t OPCode = 0x10;
			CPU* aCPU;

			////// BACKWARD DISPLACEMENT IF SetCarry
			//TEST1
			aCPU = CreatBRANCH_FAMILY_Instruction(OPCode, 0b10000010);
			aCPU->ResetSign();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x7FFE, (int)aCPU->PC);

			//TEST2
			aCPU = CreatBRANCH_FAMILY_Instruction(OPCode, 0b10000010);
			aCPU->SetSign();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8002, (int)aCPU->PC);

			////// FORWARD DISPLACEMENT IF SetCarry

			//TEST3
			/// Forward Displacment should atleast be 2 to pass this instruction length
			aCPU = CreatBRANCH_FAMILY_Instruction(OPCode, 0b00000100);
			aCPU->ResetSign();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8004, (int)aCPU->PC);

			//TEST4
			aCPU = CreatBRANCH_FAMILY_Instruction(OPCode, 0b10000100);
			aCPU->SetSign();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8002, (int)aCPU->PC);
		}
		TEST_METHOD(BVC) {
			//opcode 0x50 2bytes
			uint8_t OPCode = 0x50;
			CPU* aCPU;

			////// BACKWARD DISPLACEMENT IF SetCarry
			//TEST1
			aCPU = CreatBRANCH_FAMILY_Instruction(OPCode, 0b10000010);
			aCPU->ResetOverflow();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x7FFE, (int)aCPU->PC);

			//TEST2
			aCPU = CreatBRANCH_FAMILY_Instruction(OPCode, 0b10000010);
			aCPU->SetOverflow();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8002, (int)aCPU->PC);

			////// FORWARD DISPLACEMENT IF SetCarry

			//TEST3
			/// Forward Displacment should atleast be 2 to pass this instruction length
			aCPU = CreatBRANCH_FAMILY_Instruction(OPCode, 0b00000100);
			aCPU->ResetOverflow();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8004, (int)aCPU->PC);

			//TEST4
			aCPU = CreatBRANCH_FAMILY_Instruction(OPCode, 0b10000100);
			aCPU->SetOverflow();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8002, (int)aCPU->PC);
		}
		TEST_METHOD(BVS) {
			//opcode 0x70 2bytes
			uint8_t OPCode = 0x70;
			CPU* aCPU;

			////// BACKWARD DISPLACEMENT IF SetCarry
			//TEST1
			aCPU = CreatBRANCH_FAMILY_Instruction(OPCode, 0b10000010);
			aCPU->SetOverflow();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x7FFE, (int)aCPU->PC);

			//TEST2
			aCPU = CreatBRANCH_FAMILY_Instruction(OPCode, 0b10000010);
			aCPU->ResetOverflow();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8002, (int)aCPU->PC);

			////// FORWARD DISPLACEMENT IF SetCarry

			//TEST3
			/// Forward Displacment should atleast be 2 to pass this instruction length
			aCPU = CreatBRANCH_FAMILY_Instruction(OPCode, 0b00000100);
			aCPU->SetOverflow();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8004, (int)aCPU->PC);

			//TEST4
			aCPU = CreatBRANCH_FAMILY_Instruction(OPCode, 0b10000100);
			aCPU->ResetOverflow();
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x8002, (int)aCPU->PC);
		}
	};
	TEST_CLASS(BIT_INSTRUCTIONS) {
	TEST_METHOD(BIT_ABS) {
			uint8_t OPCode = 0x2C;
			uint8_t InstructionLength = 0x03;
			CPU* aCPU;

			//TEST1
			aCPU = CreateABS_Instruction(OPCode, 0b00000000);
			aCPU->A = 0b11000000;
			aCPU->ExecuteNextInstruction();
			Assert::IsTrue(aCPU->GetZero());
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetOverflow());
			Assert::AreEqual(0x0000+ InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST2
			aCPU = CreateABS_Instruction(OPCode, 0b10000000);
			aCPU->A = 0b11000000;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetZero());
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetOverflow());
			Assert::AreEqual(0x0000+ InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST3
			aCPU = CreateABS_Instruction(OPCode, 0b01000000);
			aCPU->A = 0b11000000;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetZero());
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetOverflow());
			Assert::AreEqual(0x0000+ InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST4
			aCPU = CreateABS_Instruction(OPCode, 0b11000000);
			aCPU->A = 0b11000000;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetZero());
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetOverflow());
			Assert::AreEqual(0x0000+ InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST4
			aCPU = CreateABS_Instruction(OPCode, 0b00000001);
			aCPU->A = 0b11000000;
			aCPU->ExecuteNextInstruction();
			Assert::IsTrue(aCPU->GetZero());
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetOverflow());
			Assert::AreEqual(0x0000+ InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST5
			aCPU = CreateABS_Instruction(OPCode, 0b00000001);
			aCPU->A = 0b11000001;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetZero());
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetOverflow());
			Assert::AreEqual(0x0000+ InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
	TEST_METHOD(BIT_ZABS) {
		uint8_t OPCode = 0x24;
		uint8_t InstructionLength = 0x02;
		CPU* aCPU;

		//TEST1
		aCPU = CreateZABS_Instruction(OPCode, 0b00000000);
		aCPU->A = 0b11000000;
		aCPU->ExecuteNextInstruction();
		Assert::IsTrue(aCPU->GetZero());
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsFalse(aCPU->GetOverflow());
		Assert::AreEqual(0x0000+ InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		//TEST2
		aCPU = CreateZABS_Instruction(OPCode, 0b10000000);
		aCPU->A = 0b11000000;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetZero());
		Assert::IsTrue(aCPU->GetSign());
		Assert::IsFalse(aCPU->GetOverflow());
		Assert::AreEqual(0x0000+ InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		//TEST3
		aCPU = CreateZABS_Instruction(OPCode, 0b01000000);
		aCPU->A = 0b11000000;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetZero());
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsTrue(aCPU->GetOverflow());
		Assert::AreEqual(0x0000+ InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		//TEST4
		aCPU = CreateZABS_Instruction(OPCode, 0b11000000);
		aCPU->A = 0b11000000;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetZero());
		Assert::IsTrue(aCPU->GetSign());
		Assert::IsTrue(aCPU->GetOverflow());
		Assert::AreEqual(0x0000+ InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		//TEST4
		aCPU = CreateZABS_Instruction(OPCode, 0b00000001);
		aCPU->A = 0b11000000;
		aCPU->ExecuteNextInstruction();
		Assert::IsTrue(aCPU->GetZero());
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsFalse(aCPU->GetOverflow());
		Assert::AreEqual(0x0000+ InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		//TEST5
		aCPU = CreateZABS_Instruction(OPCode, 0b00000001);
		aCPU->A = 0b11000001;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetZero());
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsFalse(aCPU->GetOverflow());
		Assert::AreEqual(0x0000+ InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
	}

	};
	TEST_CLASS(CLEAR_SET_FLAGS_INSTRUCTIONS) {
	TEST_METHOD(CLEAR_FLAGS) {

		CPU* aCPU;

		//CLEAR CARRY
		aCPU = CreatIMPLIED_Instruction(0x18);
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetCarry());
		Assert::AreEqual(0x0001, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		//CLEAR DECIMAL MODE
		aCPU = CreatIMPLIED_Instruction(0xD8);
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetDecimalMode());
		Assert::AreEqual(0x0001, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		//CLEAR INTERRUPT DISBALE
		aCPU = CreatIMPLIED_Instruction(0x58);
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetInterruptDisable());
		Assert::AreEqual(0x0001, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		//CLEAR OVERFLOW
		aCPU = CreatIMPLIED_Instruction(0xB8);
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetOverflow());
		Assert::AreEqual(0x0001, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
	}
	TEST_METHOD(SET_FLAGS) {

		CPU* aCPU;

		//SET CARRY
		aCPU = CreatIMPLIED_Instruction(0x38);
		aCPU->ExecuteNextInstruction();
		Assert::IsTrue(aCPU->GetCarry());
		Assert::AreEqual(0x0001, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		//SET DECIMAL MODE
		aCPU = CreatIMPLIED_Instruction(0xF8);
		aCPU->ExecuteNextInstruction();
		Assert::IsTrue(aCPU->GetDecimalMode());
		Assert::AreEqual(0x0001, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		//SET INTERRUPT DISBALE
		aCPU = CreatIMPLIED_Instruction(0x78);
		aCPU->ExecuteNextInstruction();
		Assert::IsTrue(aCPU->GetInterruptDisable());
		Assert::AreEqual(0x0001, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

	}
	};
	TEST_CLASS(TRANSFER_FAMILY_INSTRUCTIONS) {
		TEST_METHOD(TYA) {
			uint8_t OPCode = 0x98;
			CPU* aCPU;
			
			//TEST1
			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->Y = 0b10000000;
			aCPU->A = 0x00;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b10000000, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST2
			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->Y = 0b00000000;
			aCPU->A = 0xF0;//RANDOM AND NOT ZERO
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST3
			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->Y = 0b00001000;
			aCPU->A = 0x00;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00001000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(TXS) {
			uint8_t OPCode = 0x9A;
			CPU* aCPU;

			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->X = 0xFC;
			aCPU->SP = 0x00;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0xFC, (int)aCPU->SP);
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}

		TEST_METHOD(TXA) {
			uint8_t OPCode = 0x8A;
			CPU* aCPU;

			//TEST1
			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->X = 0b10000000;
			aCPU->A = 0x00;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b10000000, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST2
			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->X = 0b00000000;
			aCPU->A = 0xF0;//RANDOM AND NOT ZERO
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST3
			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->X = 0b00001000;
			aCPU->A = 0x00;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00001000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(TSX) {
			uint8_t OPCode = 0xBA;
			CPU* aCPU;

			//TEST1
			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->SP = 0b10000000;
			aCPU->X = 0x00;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b10000000, (int)aCPU->X);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST2
			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->SP = 0b00000000;
			aCPU->X = 0xF0;//RANDOM AND NOT ZERO
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->X);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST3
			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->SP = 0b00001000;
			aCPU->X = 0x00;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00001000, (int)aCPU->X);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(TAY) {
			uint8_t OPCode = 0xA8;
			CPU* aCPU;

			//TEST1
			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->A = 0b10000000;
			aCPU->Y = 0x00;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b10000000, (int)aCPU->Y);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST2
			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->A = 0b00000000;
			aCPU->Y = 0xF0;//RANDOM AND NOT ZERO
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->Y);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST3
			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->A = 0b00001000;
			aCPU->Y = 0x00;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00001000, (int)aCPU->Y);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(TAX) {
			uint8_t OPCode = 0xAA;
			CPU* aCPU;

			//TEST1
			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->A = 0b10000000;
			aCPU->X = 0x00;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b10000000, (int)aCPU->X);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST2
			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->A = 0b00000000;
			aCPU->X = 0xF0;//RANDOM AND NOT ZERO
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->X);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST3
			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->A = 0b00001000;
			aCPU->X = 0x00;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00001000, (int)aCPU->X);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
	};
	TEST_CLASS(STA_INSTRUCTIONS) {
		TEST_METHOD(STA_ZABS) {
			uint8_t OPCode = 0x85;
			uint8_t InstructionLength=0x02;
			CPU* aCPU;

			aCPU = CreateZABS_Instruction(OPCode, 0x12/*A Random number*/);
			aCPU->A = 0xD1;
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xD1, (int)*aCPU->CPUMemory[TargetDataAddress_ZABS_MODE]);
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(STA_ZINX) {
			uint8_t OPCode = 0x95;
			uint8_t InstructionLength = 0x02;
			CPU* aCPU;

			aCPU = CreateZINX_Instruction(OPCode, 0x12/*A Random number*/);
			aCPU->A = 0x36;
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x36, (int)*aCPU->CPUMemory[TargetDataAddress_ZINX_MODE]);
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(STA_ABS) {
			uint8_t OPCode = 0x8D;
			uint8_t InstructionLength = 0x03;
			CPU* aCPU;

			aCPU = CreateABS_Instruction(OPCode, 0x12/*A Random number*/);
			aCPU->A = 0x77;
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x77, (int)*aCPU->CPUMemory[TargetDataAddress_ABS_MODE]);
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(STA_INX_X) {
			uint8_t OPCode = 0x9D;
			uint8_t InstructionLength = 0x03;
			CPU* aCPU;

			aCPU = CreateINX_X_Instruction(OPCode, 0x12/*A Random number*/);
			aCPU->A = 0x89;
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x89, (int)*aCPU->CPUMemory[TargetDataAddress_INX_X_MODE]);
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(STA_INX_Y) {
			uint8_t OPCode = 0x99;
			uint8_t InstructionLength = 0x03;
			CPU* aCPU;

			aCPU = CreateINX_Y_Instruction(OPCode, 0x12/*A Random number*/);
			aCPU->A = 0x33;
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x33, (int)*aCPU->CPUMemory[TargetDataAddress_INX_Y_MODE]);
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(STA_PRII) {
			uint8_t OPCode = 0x81;
			uint8_t InstructionLength = 0x02;
			CPU* aCPU;

			aCPU = CreatePRII_Instruction(OPCode, 0x12/*A Random number*/);
			aCPU->A = 0xE3;
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xE3, (int)*aCPU->CPUMemory[TargetDataAddress_PRII_MODE]);
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(STA_POII) {
			uint8_t OPCode = 0x91;
			uint8_t InstructionLength = 0x02;
			CPU* aCPU;

			aCPU = CreatePOII_Instruction(OPCode, 0x12/*A Random number*/);
			aCPU->A = 0x45;
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x45, (int)*aCPU->CPUMemory[TargetDataAddress_POII_MODE]);
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
	};
	TEST_CLASS(STX_INSTRUCTIONS) {
		TEST_METHOD(STX_ZABS) {
			uint8_t OPCode = 0x86;
			uint8_t InstructionLength = 0x02;
			CPU* aCPU;

			aCPU = CreateZABS_Instruction(OPCode, 0x12/*A Random number*/);
			aCPU->X = 0x45;
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x45, (int)*aCPU->CPUMemory[TargetDataAddress_ZABS_MODE]);
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(STX_ZINY) {
			uint8_t OPCode = 0x96;
			uint8_t InstructionLength = 0x02;
			CPU* aCPU;

			aCPU = CreateZINY_Instruction(OPCode, 0x12/*A Random number*/);
			aCPU->X = 0x45;
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x45, (int)*aCPU->CPUMemory[TargetDataAddress_ZINY_MODE]);
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(STX_ABS) {
			uint8_t OPCode = 0x8E;
			uint8_t InstructionLength = 0x03;
			CPU* aCPU;

			aCPU = CreateABS_Instruction(OPCode, 0x12/*A Random number*/);
			aCPU->X = 0x45;
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x45, (int)*aCPU->CPUMemory[TargetDataAddress_ABS_MODE]);
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
	};
	TEST_CLASS(STY_INSTRUCTIONS) {
		TEST_METHOD(STY_ZABS) {
			uint8_t OPCode = 0x84;
			uint8_t InstructionLength = 0x02;
			CPU* aCPU;

			aCPU = CreateZABS_Instruction(OPCode, 0x12/*A Random number*/);
			aCPU->Y = 0x45;
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x45, (int)*aCPU->CPUMemory[TargetDataAddress_ZABS_MODE]);
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(STY_ZINX) {
			uint8_t OPCode = 0x94;
			uint8_t InstructionLength = 0x02;
			CPU* aCPU;

			aCPU = CreateZINX_Instruction(OPCode, 0x12/*A Random number*/);
			aCPU->Y = 0x45;
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x45, (int)*aCPU->CPUMemory[TargetDataAddress_ZINX_MODE]);
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(STY_ABS) {
			uint8_t OPCode = 0x8C;
			uint8_t InstructionLength = 0x03;
			CPU* aCPU;

			aCPU = CreateABS_Instruction(OPCode, 0x12/*A Random number*/);
			aCPU->Y = 0x45;
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x45, (int)*aCPU->CPUMemory[TargetDataAddress_ABS_MODE]);
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
	};
	TEST_CLASS(OPERATIONS_WITH_STACK_INSTRUCTIONS) {
	
		/// //////////////////////////////
		TEST_METHOD(RTS) {
			uint8_t OPCode = 0x60;

			CPU* aCPU;

			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->PC = 0xFFBA;
			aCPU->PushPCtoStack();
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xFFBB, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(RTI) {
			uint8_t OPCode = 0x40;

			CPU* aCPU;

			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->PC = 0xFFBA;
			aCPU->PushPCtoStack();
			aCPU->PC = 0x0000;
			aCPU->PushToStack(0x16);//0x16 is a Status Register content example

			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xFFBA, (int)aCPU->PC);
			Assert::AreEqual(0x16, (int)aCPU->P);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		//////////////////////////////////
		TEST_METHOD(PLP) {
			uint8_t OPCode = 0x28;
			CPU* aCPU;

			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->PushToStack(0x16);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x16, (int)aCPU->P);
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(PLA) {
			uint8_t OPCode = 0x68;
			CPU* aCPU;

			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->PushToStack(0x16);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x16, (int)aCPU->A);
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(PHP) {
			uint8_t OPCode = 0x08;
			CPU* aCPU;

			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->P = 0b10000000;
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0b10010000, (int)aCPU->PopStack());//bit5 of break should be set
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(PHA) {
			uint8_t OPCode = 0x48;
			CPU* aCPU;

			aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->A = 0x16;
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x16, (int)aCPU->PopStack());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		
	};
	TEST_CLASS(NOP_INSTRUCTION) {
		TEST_METHOD(NOP) {
			uint8_t OPCode = 0xEA;
			CPU* aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
	};
	TEST_CLASS(ORA_INSTRUCTIONS) {
	public:


		TEST_METHOD(ORA_IME) {
			uint8_t OPCode = 0x09;
			uint8_t InstructionLength = 2;
			CPU* aCPU;

			//TEST1
			aCPU = CreateIME_Instruction(OPCode, 0b00000001);
			aCPU->A = 0b11100000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();
			
			Assert::AreEqual(0b11100001, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 
			aCPU = CreateIME_Instruction(OPCode, 0b00000000);

			aCPU->A = 0b00000000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3
			aCPU = CreateIME_Instruction(OPCode, 0b00001001);

			aCPU->A = 0b01100000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b001101001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		}
		TEST_METHOD(ORA_ZABS) {
			uint8_t OPCode = 0x05;
			uint8_t InstructionLength = 2;
			CPU* aCPU;

			//TEST1
			aCPU = CreateZABS_Instruction(OPCode, 0b00000001);
			aCPU->A = 0b11100000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b11100001, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 
			aCPU = CreateZABS_Instruction(OPCode, 0b00000000);

			aCPU->A = 0b00000000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3
			aCPU = CreateZABS_Instruction(OPCode, 0b00001001);

			aCPU->A = 0b01100000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b001101001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		}
		TEST_METHOD(ORA_ZINX) {
			uint8_t OPCode = 0x15;
			uint8_t InstructionLength = 2;
			CPU* aCPU;

			//TEST1
			aCPU = CreateZINX_Instruction(OPCode, 0b00000001);
			aCPU->A = 0b11100000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b11100001, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 
			aCPU = CreateZINX_Instruction(OPCode, 0b00000000);

			aCPU->A = 0b00000000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3
			aCPU = CreateZINX_Instruction(OPCode, 0b00001001);

			aCPU->A = 0b01100000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b001101001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		}
		TEST_METHOD(ORA_ABS) {
			uint8_t OPCode = 0x0D;
			uint8_t InstructionLength = 3;
			CPU* aCPU;

			//TEST1
			aCPU = CreateABS_Instruction(OPCode, 0b00000001);
			aCPU->A = 0b11100000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b11100001, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 
			aCPU = CreateABS_Instruction(OPCode, 0b00000000);

			aCPU->A = 0b00000000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3
			aCPU = CreateABS_Instruction(OPCode, 0b00001001);

			aCPU->A = 0b01100000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b001101001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		}
		TEST_METHOD(ORA_INX_X) {
			uint8_t OPCode = 0x1D;
			uint8_t InstructionLength = 3;
			CPU* aCPU;

			//TEST1
			aCPU = CreateINX_X_Instruction(OPCode, 0b00000001);
			aCPU->A = 0b11100000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b11100001, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 
			aCPU = CreateINX_X_Instruction(OPCode, 0b00000000);

			aCPU->A = 0b00000000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3
			aCPU = CreateINX_X_Instruction(OPCode, 0b00001001);

			aCPU->A = 0b01100000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b001101001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		}
		TEST_METHOD(ORA_INX_Y) {
			uint8_t OPCode = 0x19;
			uint8_t InstructionLength = 3;
			CPU* aCPU;

			//TEST1
			aCPU = CreateINX_Y_Instruction(OPCode, 0b00000001);
			aCPU->A = 0b11100000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b11100001, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 
			aCPU = CreateINX_Y_Instruction(OPCode, 0b00000000);

			aCPU->A = 0b00000000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3
			aCPU = CreateINX_Y_Instruction(OPCode, 0b00001001);

			aCPU->A = 0b01100000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b001101001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		}
		TEST_METHOD(ORA_PRII) {
			uint8_t OPCode = 0x01;
			uint8_t InstructionLength = 2;
			CPU* aCPU;

			//TEST1
			aCPU = CreatePRII_Instruction(OPCode, 0b00000001);
			aCPU->A = 0b11100000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b11100001, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 
			aCPU = CreatePRII_Instruction(OPCode, 0b00000000);

			aCPU->A = 0b00000000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3
			aCPU = CreatePRII_Instruction(OPCode, 0b00001001);

			aCPU->A = 0b01100000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b001101001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		}
		TEST_METHOD(ORA_POII) {
			uint8_t OPCode = 0x11;
			uint8_t InstructionLength = 2;
			CPU* aCPU;

			//TEST1
			aCPU = CreatePOII_Instruction(OPCode, 0b00000001);
			aCPU->A = 0b11100000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b11100001, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 
			aCPU = CreatePOII_Instruction(OPCode, 0b00000000);

			aCPU->A = 0b00000000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3
			aCPU = CreatePOII_Instruction(OPCode, 0b00001001);

			aCPU->A = 0b01100000;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b001101001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		}
	};
	TEST_CLASS(LDY_INSTRUCTIONS) {
		TEST_METHOD(LDY_IME) {
			uint8_t OPCode = 0xA0;
			uint8_t InstructionLength = 2;

			CPU* aCPU = CreateIME_Instruction(OPCode, 0xBC);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xBC, (int)aCPU->Y);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(LDY_ZABS) {
			uint8_t OPCode = 0xA4;
			uint8_t InstructionLength = 2;

			CPU* aCPU = CreateZABS_Instruction(OPCode, 0xBC);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xBC, (int)aCPU->Y);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(LDY_ZINX) {
			uint8_t OPCode = 0xB4;
			uint8_t InstructionLength = 2;

			CPU* aCPU = CreateZINX_Instruction(OPCode, 0xBC);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xBC, (int)aCPU->Y);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(LDY_ABS) {
			uint8_t OPCode = 0xAC;
			uint8_t InstructionLength = 3;

			CPU* aCPU = CreateABS_Instruction(OPCode, 0xBC);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xBC, (int)aCPU->Y);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(LDY_INX_X) {
			uint8_t OPCode = 0xBC;
			uint8_t InstructionLength = 3;

			CPU* aCPU = CreateINX_X_Instruction(OPCode, 0xBC);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xBC, (int)aCPU->Y);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
	};
	TEST_CLASS(LDX_INSTRUCTIONS) {
		TEST_METHOD(LDX_IME) {
			uint8_t OPCode = 0xA2;
			uint8_t InstructionLength = 2;

			CPU* aCPU = CreateIME_Instruction(OPCode, 0xBC);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xBC, (int)aCPU->X);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(LDX_ZABS) {
			uint8_t OPCode = 0xA6;
			uint8_t InstructionLength = 2;

			CPU* aCPU = CreateZABS_Instruction(OPCode, 0xBC);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xBC, (int)aCPU->X);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(LDX_ZINY) {
			uint8_t OPCode = 0xB6;
			uint8_t InstructionLength = 2;

			CPU* aCPU = CreateZINY_Instruction(OPCode, 0xBC);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xBC, (int)aCPU->X);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(LDX_ABS) {
			uint8_t OPCode = 0xAE;
			uint8_t InstructionLength = 3;

			CPU* aCPU = CreateABS_Instruction(OPCode, 0xBC);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xBC, (int)aCPU->X);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(LDX_INX_Y) {
			uint8_t OPCode = 0xBE;
			uint8_t InstructionLength = 3;

			CPU* aCPU = CreateINX_Y_Instruction(OPCode, 0xBC);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xBC, (int)aCPU->X);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
	};
	TEST_CLASS(LDA_INSTRUCTIONS) {
		TEST_METHOD(LDA_IME) {
			uint8_t OPCode = 0xA9;
			uint8_t InstructionLength = 2;

			CPU* aCPU = CreateIME_Instruction(OPCode, 0xBC);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xBC, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(LDA_ZABS) {
			uint8_t OPCode = 0xA5;
			uint8_t InstructionLength = 2;

			CPU* aCPU = CreateZABS_Instruction(OPCode, 0xBC);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xBC, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(LDA_ZINX) {
			uint8_t OPCode = 0xB5;
			uint8_t InstructionLength = 2;

			CPU* aCPU = CreateZINX_Instruction(OPCode, 0xBC);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xBC, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(LDA_ABS) {
			uint8_t OPCode = 0xAD;
			uint8_t InstructionLength = 3;

			CPU* aCPU = CreateABS_Instruction(OPCode, 0xBC);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xBC, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(LDA_INX_X) {
			uint8_t OPCode = 0xBD;
			uint8_t InstructionLength = 3;

			CPU* aCPU = CreateINX_X_Instruction(OPCode, 0xBC);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xBC, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(LDA_INX_Y) {
			uint8_t OPCode = 0xB9;
			uint8_t InstructionLength = 3;

			CPU* aCPU = CreateINX_Y_Instruction(OPCode, 0xBC);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xBC, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(LDA_PRII) {
			uint8_t OPCode = 0xA1;
			uint8_t InstructionLength = 2;

			CPU* aCPU = CreatePRII_Instruction(OPCode, 0xBC);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xBC, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(LDA_POII) {
			uint8_t OPCode = 0xB1;
			uint8_t InstructionLength = 2;

			CPU* aCPU = CreatePOII_Instruction(OPCode, 0xBC);
			aCPU->ExecuteNextInstruction();
			Assert::AreEqual(0xBC, (int)aCPU->A);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
	};
	TEST_CLASS(JUMP_INSTRUCTIONS) {
		TEST_METHOD(JSR) {
			uint8_t OPCode = 0x20;
			CPU* aCPU;

			aCPU = new CPU(NULL,CreateCPUMemory(), NULL);

			*aCPU->CPUMemory[0xB004] = OPCode;
			*aCPU->CPUMemory[0xB005] = 0xFF;
			*aCPU->CPUMemory[0xB006] = 0xDD;
			aCPU->PC = 0xB004;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0xDDFF, (int)aCPU->PC);
			Assert::AreEqual(0xB006, (int)aCPU->PopPCfromStack());//RTS INSTRUCTION WILL ADDED ONE TO 0xB006 
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(JMP_IND) {
			uint8_t OPCode = 0x4C;
			CPU* aCPU = new CPU(NULL, CreateCPUMemory(), NULL);

			*aCPU->CPUMemory[0xB004] = OPCode;
			*aCPU->CPUMemory[0xB005] = 0xFF;
			*aCPU->CPUMemory[0xB006] = 0xDD;
			aCPU->PC = 0xB004;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0xDDFF, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		}
		TEST_METHOD(JMP_ABS) {
			uint8_t OPCode = 0x6C;
			CPU* aCPU = new CPU(NULL, CreateCPUMemory(), NULL);

			*aCPU->CPUMemory[0xB004] = OPCode;
			*aCPU->CPUMemory[0xB005] = 0xFF;
			*aCPU->CPUMemory[0xB006] = 0xDD;
			*aCPU->CPUMemory[0xDDFF] = 0x56;
			aCPU->PC = 0xB004;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0x0056, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		}
	};
	TEST_CLASS(INCREMENT_INSTRUCTIONS) {
		TEST_METHOD(INX) {
			uint8_t OPCode = 0xE8;
			CPU* aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->X = 0xF0;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0xF1, (int)aCPU->X);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(INY) {
			uint8_t OPCode = 0xC8;
			CPU* aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->Y = 0xF0;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0xF1, (int)aCPU->Y);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(INC_ZABS) {
			uint8_t OPCode = 0xE6;
			CPU* aCPU = CreateZABS_Instruction(OPCode,0xF0);
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0xF1, (int)*aCPU->CPUMemory[TargetDataAddress_ZABS_MODE]);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(INC_INX_X) {
			uint8_t OPCode = 0xFE;
			CPU* aCPU = CreateINX_X_Instruction(OPCode, 0xF0);
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0xF1, (int)*aCPU->CPUMemory[TargetDataAddress_INX_X_MODE]);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(INC_ABS) {
			uint8_t OPCode = 0xEE;
			CPU* aCPU = CreateABS_Instruction(OPCode, 0xF0);
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0xF1, (int)*aCPU->CPUMemory[TargetDataAddress_ABS_MODE]);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(INC_ZINX) {
			uint8_t OPCode = 0xF6;
			CPU* aCPU = CreateZINX_Instruction(OPCode, 0xF0);
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0xF1, (int)*aCPU->CPUMemory[TargetDataAddress_ZINX_MODE]);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}

	};
	TEST_CLASS(DECREMENT_INSTRUCTIONS) {
		TEST_METHOD(DEX) {
			uint8_t OPCode = 0xCA;
			CPU* aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->X = 0xF1;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0xF0, (int)aCPU->X);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(DEY) {
			uint8_t OPCode = 0x88;
			CPU* aCPU = CreatIMPLIED_Instruction(OPCode);
			aCPU->Y = 0xF1;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0xF0, (int)aCPU->Y);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0001, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(DEC_ZABS) {
			uint8_t OPCode = 0xC6;
			CPU* aCPU = CreateZABS_Instruction(OPCode, 0xF1);
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0xF0, (int)*aCPU->CPUMemory[TargetDataAddress_ZABS_MODE]);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(INC_INX_X) {
			uint8_t OPCode = 0xDE;
			CPU* aCPU = CreateINX_X_Instruction(OPCode, 0xF1);
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0xF0, (int)*aCPU->CPUMemory[TargetDataAddress_INX_X_MODE]);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(DEC_ABS) {
			uint8_t OPCode = 0xCE;
			CPU* aCPU = CreateABS_Instruction(OPCode, 0xF1);
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0xF0, (int)*aCPU->CPUMemory[TargetDataAddress_ABS_MODE]);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(DEX_ZINX) {
			uint8_t OPCode = 0xD6;
			CPU* aCPU = CreateZINX_Instruction(OPCode, 0xF1);
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0xF0, (int)*aCPU->CPUMemory[TargetDataAddress_ZINX_MODE]);
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
	};
	TEST_CLASS(CPY_INSTRUCTIONS) {
		TEST_METHOD(CPY_IME) {
			uint8_t OPCode = 0xC0;
			uint8_t InstructionLength = 0x02;
			CPU* aCPU;

			///Test1
			aCPU = CreateIME_Instruction(OPCode,0xFF);
			aCPU->Y = 0xFF;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetCarry());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			///Test2
			aCPU = CreateIME_Instruction(OPCode, 0xFF);
			aCPU->Y = 0x0F;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetCarry());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			///Test3
			aCPU = CreateIME_Instruction(OPCode, 0x0F);
			aCPU->Y = 0xFF;
			aCPU->ExecuteNextInstruction();
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetCarry());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(CPY_ZABS) {
			uint8_t OPCode = 0xC4;
			uint8_t InstructionLength = 0x02;
			CPU* aCPU;

			///Test1
			aCPU = CreateZABS_Instruction(OPCode, 0xFF);
			aCPU->Y = 0xFF;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetCarry());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			///Test2
			aCPU = CreateZABS_Instruction(OPCode, 0xFF);
			aCPU->Y = 0x0F;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetCarry());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			///Test3
			aCPU = CreateZABS_Instruction(OPCode, 0x0F);
			aCPU->Y = 0xFF;
			aCPU->ExecuteNextInstruction();
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetCarry());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(CPY_ABS) {
			uint8_t OPCode = 0xCC;
			uint8_t InstructionLength = 0x03;
			CPU* aCPU;

			///Test1
			aCPU = CreateABS_Instruction(OPCode, 0xFF);
			aCPU->Y = 0xFF;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetCarry());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			///Test2
			aCPU = CreateABS_Instruction(OPCode, 0xFF);
			aCPU->Y = 0x0F;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetCarry());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			///Test3
			aCPU = CreateABS_Instruction(OPCode, 0x0F);
			aCPU->Y = 0xFF;
			aCPU->ExecuteNextInstruction();
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetCarry());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
	};
	TEST_CLASS(CPX_INSTRUCTIONS) {
		TEST_METHOD(CPX_IME) {
			uint8_t OPCode = 0xE0;
			uint8_t InstructionLength = 0x02;
			CPU* aCPU;

			///Test1
			aCPU = CreateIME_Instruction(OPCode, 0xFF);
			aCPU->X = 0xFF;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetCarry());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			///Test2
			aCPU = CreateIME_Instruction(OPCode, 0xFF);
			aCPU->X = 0x0F;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetCarry());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			///Test3
			aCPU = CreateIME_Instruction(OPCode, 0x0F);
			aCPU->X = 0xFF;
			aCPU->ExecuteNextInstruction();
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetCarry());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(CPX_ZABS) {
			uint8_t OPCode = 0xE4;
			uint8_t InstructionLength = 0x02;
			CPU* aCPU;

			///Test1
			aCPU = CreateZABS_Instruction(OPCode, 0xFF);
			aCPU->X = 0xFF;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetCarry());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			///Test2
			aCPU = CreateZABS_Instruction(OPCode, 0xFF);
			aCPU->X = 0x0F;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetCarry());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			///Test3
			aCPU = CreateZABS_Instruction(OPCode, 0x0F);
			aCPU->X = 0xFF;
			aCPU->ExecuteNextInstruction();
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetCarry());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		}
		TEST_METHOD(CPX_ABS) {
			uint8_t OPCode = 0xEC;
			uint8_t InstructionLength = 0x03;
			CPU* aCPU;

			///Test1
			aCPU = CreateABS_Instruction(OPCode, 0xFF);
			aCPU->X = 0xFF;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetCarry());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			///Test2
			aCPU = CreateABS_Instruction(OPCode, 0xFF);
			aCPU->X = 0x0F;
			aCPU->ExecuteNextInstruction();
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetCarry());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			///Test3
			aCPU = CreateABS_Instruction(OPCode, 0x0F);
			aCPU->X = 0xFF;
			aCPU->ExecuteNextInstruction();
			Assert::IsTrue(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetCarry());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
		};
};
    TEST_CLASS(CPM_INSTRUCTIONS) {
	TEST_METHOD(CPM_IME) {
		uint8_t OPCode = 0xC9;
		uint8_t InstructionLength = 0x02;
		CPU* aCPU;

		///Test1
		aCPU = CreateIME_Instruction(OPCode, 0xFF);
		aCPU->A = 0xFF;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsTrue(aCPU->GetCarry());
		Assert::IsTrue(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		///Test2
		aCPU = CreateIME_Instruction(OPCode, 0xFF);
		aCPU->A = 0x0F;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsFalse(aCPU->GetCarry());
		Assert::IsFalse(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		///Test3
		aCPU = CreateIME_Instruction(OPCode, 0x0F);
		aCPU->A = 0xFF;
		aCPU->ExecuteNextInstruction();
		Assert::IsTrue(aCPU->GetSign());
		Assert::IsTrue(aCPU->GetCarry());
		Assert::IsFalse(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
	}
	TEST_METHOD(CPX_ZABS) {
		uint8_t OPCode = 0xC5;
		uint8_t InstructionLength = 0x02;
		CPU* aCPU;

		///Test1
		aCPU = CreateZABS_Instruction(OPCode, 0xFF);
		aCPU->A = 0xFF;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsTrue(aCPU->GetCarry());
		Assert::IsTrue(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		///Test2
		aCPU = CreateZABS_Instruction(OPCode, 0xFF);
		aCPU->A = 0x0F;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsFalse(aCPU->GetCarry());
		Assert::IsFalse(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		///Test3
		aCPU = CreateZABS_Instruction(OPCode, 0x0F);
		aCPU->A = 0xFF;
		aCPU->ExecuteNextInstruction();
		Assert::IsTrue(aCPU->GetSign());
		Assert::IsTrue(aCPU->GetCarry());
		Assert::IsFalse(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
	}
	TEST_METHOD(CPX_ZINX) {
		uint8_t OPCode = 0xD5;
		uint8_t InstructionLength = 0x02;
		CPU* aCPU;

		///Test1
		aCPU = CreateZINX_Instruction(OPCode, 0xFF);
		aCPU->A = 0xFF;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsTrue(aCPU->GetCarry());
		Assert::IsTrue(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		///Test2
		aCPU = CreateZINX_Instruction(OPCode, 0xFF);
		aCPU->A = 0x0F;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsFalse(aCPU->GetCarry());
		Assert::IsFalse(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		///Test3
		aCPU = CreateZINX_Instruction(OPCode, 0x0F);
		aCPU->A = 0xFF;
		aCPU->ExecuteNextInstruction();
		Assert::IsTrue(aCPU->GetSign());
		Assert::IsTrue(aCPU->GetCarry());
		Assert::IsFalse(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
	}
	TEST_METHOD(CPX_ABS) {
		uint8_t OPCode = 0xCD;
		uint8_t InstructionLength = 0x03;
		CPU* aCPU;

		///Test1
		aCPU = CreateABS_Instruction(OPCode, 0xFF);
		aCPU->A = 0xFF;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsTrue(aCPU->GetCarry());
		Assert::IsTrue(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		///Test2
		aCPU = CreateABS_Instruction(OPCode, 0xFF);
		aCPU->A = 0x0F;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsFalse(aCPU->GetCarry());
		Assert::IsFalse(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		///Test3
		aCPU = CreateABS_Instruction(OPCode, 0x0F);
		aCPU->A = 0xFF;
		aCPU->ExecuteNextInstruction();
		Assert::IsTrue(aCPU->GetSign());
		Assert::IsTrue(aCPU->GetCarry());
		Assert::IsFalse(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
	};
	TEST_METHOD(CPX_INX_X) {
		uint8_t OPCode = 0xDD;
		uint8_t InstructionLength = 0x03;
		CPU* aCPU;

		///Test1
		aCPU = CreateINX_X_Instruction(OPCode, 0xFF);
		aCPU->A = 0xFF;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsTrue(aCPU->GetCarry());
		Assert::IsTrue(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		///Test2
		aCPU = CreateINX_X_Instruction(OPCode, 0xFF);
		aCPU->A = 0x0F;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsFalse(aCPU->GetCarry());
		Assert::IsFalse(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		///Test3
		aCPU = CreateINX_X_Instruction(OPCode, 0x0F);
		aCPU->A = 0xFF;
		aCPU->ExecuteNextInstruction();
		Assert::IsTrue(aCPU->GetSign());
		Assert::IsTrue(aCPU->GetCarry());
		Assert::IsFalse(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
	};
	TEST_METHOD(CPX_INX_Y) {
		uint8_t OPCode = 0xD9;
		uint8_t InstructionLength = 0x03;
		CPU* aCPU;

		///Test1
		aCPU = CreateINX_Y_Instruction(OPCode, 0xFF);
		aCPU->A = 0xFF;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsTrue(aCPU->GetCarry());
		Assert::IsTrue(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		///Test2
		aCPU = CreateINX_Y_Instruction(OPCode, 0xFF);
		aCPU->A = 0x0F;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsFalse(aCPU->GetCarry());
		Assert::IsFalse(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		///Test3
		aCPU = CreateINX_Y_Instruction(OPCode, 0x0F);
		aCPU->A = 0xFF;
		aCPU->ExecuteNextInstruction();
		Assert::IsTrue(aCPU->GetSign());
		Assert::IsTrue(aCPU->GetCarry());
		Assert::IsFalse(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
	};


	TEST_METHOD(CPX_PRII) {
		uint8_t OPCode = 0xC1;
		uint8_t InstructionLength = 0x02;
		CPU* aCPU;

		///Test1
		aCPU = CreatePRII_Instruction(OPCode, 0xFF);
		aCPU->A = 0xFF;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsTrue(aCPU->GetCarry());
		Assert::IsTrue(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		///Test2
		aCPU = CreatePRII_Instruction(OPCode, 0xFF);
		aCPU->A = 0x0F;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsFalse(aCPU->GetCarry());
		Assert::IsFalse(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		///Test3
		aCPU = CreatePRII_Instruction(OPCode, 0x0F);
		aCPU->A = 0xFF;
		aCPU->ExecuteNextInstruction();
		Assert::IsTrue(aCPU->GetSign());
		Assert::IsTrue(aCPU->GetCarry());
		Assert::IsFalse(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
	}

	TEST_METHOD(CPX_POII) {
		uint8_t OPCode = 0xD1;
		uint8_t InstructionLength = 0x02;
		CPU* aCPU;

		///Test1
		aCPU = CreatePOII_Instruction(OPCode, 0xFF);
		aCPU->A = 0xFF;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsTrue(aCPU->GetCarry());
		Assert::IsTrue(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		///Test2
		aCPU = CreatePOII_Instruction(OPCode, 0xFF);
		aCPU->A = 0x0F;
		aCPU->ExecuteNextInstruction();
		Assert::IsFalse(aCPU->GetSign());
		Assert::IsFalse(aCPU->GetCarry());
		Assert::IsFalse(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

		///Test3
		aCPU = CreatePOII_Instruction(OPCode, 0x0F);
		aCPU->A = 0xFF;
		aCPU->ExecuteNextInstruction();
		Assert::IsTrue(aCPU->GetSign());
		Assert::IsTrue(aCPU->GetCarry());
		Assert::IsFalse(aCPU->GetZero());
		Assert::AreEqual(0x0000 + InstructionLength, (int)aCPU->PC);
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
	}
};
TEST_CLASS(BRK_INSTRUCTION) {
	TEST_METHOD(BRK) {
		uint8_t OPCode = 0x00;
		CPU* aCPU = CreatIMPLIED_Instruction(OPCode);
		
		*aCPU->CPUMemory[0xFFFE] = 0x22;
		*aCPU->CPUMemory[0xFFFF] = 0x44;
		aCPU->P = 0x00;
		aCPU->ExecuteNextInstruction();
		Assert::IsTrue(aCPU->GetBreak());
		Assert::IsTrue(aCPU->GetInterruptDisable());
		Assert::AreEqual(0x4422, (int)aCPU->PC);
		Assert::AreEqual(0b00010000, (int)aCPU->PopStack());
		Assert::AreEqual(0x02, (int)aCPU->PopPCfromStack());
		Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

	}
	};
}
