#include "pch.h"
#include "CppUnitTest.h"
#include "../NESEmulatorSDL/src/NESComponents.h"
#include "../NESEmulatorSDL/src/CPU.h"
#include "../NESEmulatorSDL/src/Masks.h"
#include "../NESEmulatorSDL/src/CoreHeaders.h"
#include "HelperMethods.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(MEMORY_TESTS)
	{

	public:

		uint8_t** OriginalMainMemory;
		uint8_t** OriginalPPUMemory;
	
		TEST_METHOD(PPUMemoryFoldTest)
		{
			OriginalPPUMemory = CreatePPUMemory();
			//test section 1 SETUP
			*OriginalPPUMemory[0x2000] = 11;
			*OriginalPPUMemory[0x2800] = 22;
			*OriginalPPUMemory[0x2BC0] = 33;	
			/// /////////////////////////////////////////
		
			//test section 2 SETUP
			*OriginalPPUMemory[0x3F00] = 44;
			*OriginalPPUMemory[0x3F10] = 55;
			*OriginalPPUMemory[0x3F15] = 66;
			/// /////////////////////////////////////////

			//test section 1
			Assert::AreEqual(11, (int)*OriginalPPUMemory[0x2000]);
			Assert::AreEqual(11, (int)*OriginalPPUMemory[0x3000]);

			
			Assert::AreEqual(22, (int)*OriginalPPUMemory[0x2800]);
			Assert::AreEqual(22, (int)*OriginalPPUMemory[0x3800]);

		
			Assert::AreEqual(33, (int)*OriginalPPUMemory[0x2BC0]);
			Assert::AreEqual(33, (int)*OriginalPPUMemory[0x3BC0]);
			/// /////////////////////////////////////////
			

			//test section 2
			Assert::AreEqual(44, (int)*OriginalPPUMemory[0x3F00]);
			Assert::AreEqual(44, (int)*OriginalPPUMemory[0x3F20]);
			Assert::AreEqual(44, (int)*OriginalPPUMemory[0x3F40]);
			Assert::AreEqual(44, (int)*OriginalPPUMemory[0x3F60]);

			Assert::AreEqual(55, (int)*OriginalPPUMemory[0x3F10]);
			Assert::AreEqual(55, (int)*OriginalPPUMemory[0x3F30]);
			Assert::AreEqual(55, (int)*OriginalPPUMemory[0x3F50]);
			Assert::AreEqual(55, (int)*OriginalPPUMemory[0x3F70]);

			Assert::AreEqual(66, (int)*OriginalPPUMemory[0x3F15]);
			Assert::AreEqual(66, (int)*OriginalPPUMemory[0x3F35]);
			Assert::AreEqual(66, (int)*OriginalPPUMemory[0x3F55]);
			Assert::AreEqual(66, (int)*OriginalPPUMemory[0x3F75]);
			/// /////////////////////////////////////////
		

			//test section 3
			Assert::AreEqual(11, (int)*OriginalPPUMemory[0x2000+0x4000]);
			Assert::AreEqual(11, (int)*OriginalPPUMemory[0x3000 + 0x4000]);


			Assert::AreEqual(22, (int)*OriginalPPUMemory[0x2800 + 0x4000]);
			Assert::AreEqual(22, (int)*OriginalPPUMemory[0x3800 + 0x4000]);


			Assert::AreEqual(33, (int)*OriginalPPUMemory[0x2BC0 + 0x4000]);
			Assert::AreEqual(33, (int)*OriginalPPUMemory[0x3BC0 + 0x4000]);
		
			
			Assert::AreEqual(44, (int)*OriginalPPUMemory[0x3F00 + 0x4000]);
			Assert::AreEqual(44, (int)*OriginalPPUMemory[0x3F20 + 0x4000]);
			Assert::AreEqual(44, (int)*OriginalPPUMemory[0x3F40 + 0x4000]);
			Assert::AreEqual(44, (int)*OriginalPPUMemory[0x3F60 + 0x4000]);

			Assert::AreEqual(55, (int)*OriginalPPUMemory[0x3F10 + 0x4000]);
			Assert::AreEqual(55, (int)*OriginalPPUMemory[0x3F30 + 0x4000]);
			Assert::AreEqual(55, (int)*OriginalPPUMemory[0x3F50 + 0x4000]);
			Assert::AreEqual(55, (int)*OriginalPPUMemory[0x3F70 + 0x4000]);

			Assert::AreEqual(66, (int)*OriginalPPUMemory[0x3F15 + 0x4000]);
			Assert::AreEqual(66, (int)*OriginalPPUMemory[0x3F35 + 0x4000]);
			Assert::AreEqual(66, (int)*OriginalPPUMemory[0x3F55 + 0x4000]);
			Assert::AreEqual(66, (int)*OriginalPPUMemory[0x3F75 + 0x4000]);
			/// /////////////////////////////////////////


			//test section 4
			Assert::AreEqual(11, (int)*OriginalPPUMemory[0x2000+0x8000]);
			Assert::AreEqual(11, (int)*OriginalPPUMemory[0x3000 + 0x8000]);


			Assert::AreEqual(22, (int)*OriginalPPUMemory[0x2800 + 0x8000]);
			Assert::AreEqual(22, (int)*OriginalPPUMemory[0x3800 + 0x8000]);


			Assert::AreEqual(33, (int)*OriginalPPUMemory[0x2BC0 + 0x8000]);
			Assert::AreEqual(33, (int)*OriginalPPUMemory[0x3BC0 + 0x8000]);
		
			Assert::AreEqual(44, (int)*OriginalPPUMemory[0x3F00 + 0x8000]);
			Assert::AreEqual(44, (int)*OriginalPPUMemory[0x3F20 + 0x8000]);
			Assert::AreEqual(44, (int)*OriginalPPUMemory[0x3F40 + 0x8000]);
			Assert::AreEqual(44, (int)*OriginalPPUMemory[0x3F60 + 0x8000]);

			Assert::AreEqual(55, (int)*OriginalPPUMemory[0x3F10 + 0x8000]);
			Assert::AreEqual(55, (int)*OriginalPPUMemory[0x3F30 + 0x8000]);
			Assert::AreEqual(55, (int)*OriginalPPUMemory[0x3F50 + 0x8000]);
			Assert::AreEqual(55, (int)*OriginalPPUMemory[0x3F70 + 0x8000]);

			Assert::AreEqual(66, (int)*OriginalPPUMemory[0x3F15 + 0x8000]);
			Assert::AreEqual(66, (int)*OriginalPPUMemory[0x3F35 + 0x8000]);
			Assert::AreEqual(66, (int)*OriginalPPUMemory[0x3F55 + 0x8000]);
			Assert::AreEqual(66, (int)*OriginalPPUMemory[0x3F75 + 0x8000]);
			/// /////////////////////////////////////////
		}
	
		TEST_METHOD(MainMemoryFoldTest) {
			OriginalMainMemory = CreateMainMemory();
			////////////////////////////////////////////////////////////////////////
			*OriginalMainMemory[0x0000] = 11;
			*OriginalMainMemory[0x0200] = 22;
			*OriginalMainMemory[0x0450] = 33;
			Assert::AreEqual(11, (int)*OriginalMainMemory[0x0000]);
			Assert::AreEqual(11, (int)*OriginalMainMemory[0x0000+0x800]);
			Assert::AreEqual(11, (int)*OriginalMainMemory[0x0000 + 0x800*2]);
			Assert::AreEqual(11, (int)*OriginalMainMemory[0x0000 + 0x800 * 3]);

			Assert::AreEqual(22, (int)*OriginalMainMemory[0x0200]);
			Assert::AreEqual(22, (int)*OriginalMainMemory[0x0200 + 0x800]);
			Assert::AreEqual(22, (int)*OriginalMainMemory[0x0200 + 0x800 * 2]);
			Assert::AreEqual(22, (int)*OriginalMainMemory[0x0200 + 0x800 * 3]);

			Assert::AreEqual(33, (int)*OriginalMainMemory[0x0450]);
			Assert::AreEqual(33, (int)*OriginalMainMemory[0x0450 + 0x800]);
			Assert::AreEqual(33, (int)*OriginalMainMemory[0x0450 + 0x800 * 2]);
			Assert::AreEqual(33, (int)*OriginalMainMemory[0x0450 + 0x800 * 3]);
			///////////////////////////////////////////////////////////////////////////

			///////////////////////////////////////////////////////////////////////////
			*OriginalMainMemory[0x2000] = 0;
			*OriginalMainMemory[0x2001] = 1;
			*OriginalMainMemory[0x2002] = 2;
			*OriginalMainMemory[0x2003] = 3;
			*OriginalMainMemory[0x2004] = 4;
			*OriginalMainMemory[0x2005] = 5;
			*OriginalMainMemory[0x2006] = 6;
			*OriginalMainMemory[0x2007] = 7;

			for (int i = 0x2000; i < 0x4000; i += 8) {
				Assert::AreEqual(0, (int)*OriginalMainMemory[i+0x0000]);
				Assert::AreEqual(1, (int)*OriginalMainMemory[i+0x0001]);
				Assert::AreEqual(2, (int)*OriginalMainMemory[i+0x0002]);
				Assert::AreEqual(3, (int)*OriginalMainMemory[i+0x0003]);
				Assert::AreEqual(4, (int)*OriginalMainMemory[i+0x0004]);
				Assert::AreEqual(5, (int)*OriginalMainMemory[i+0x0005]);
				Assert::AreEqual(6, (int)*OriginalMainMemory[i+0x0006]);
				Assert::AreEqual(7, (int)*OriginalMainMemory[i+0x0007]);
			}
			///////////////////////////////////////////////////////////////////////////
		}

		TEST_METHOD(MainMemoryDistinctCellsTest) {
			OriginalMainMemory = CreateMainMemory();
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
				*OriginalMainMemory[i] = RandomNumber;
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
				SumOfRandomNumbersFromMemory +=(int) *OriginalMainMemory[i];
			}
			Assert::AreEqual(ActualSumOfRandomNumbers, SumOfRandomNumbersFromMemory);
		}

		TEST_METHOD(PPUMemoryDistinctCellsTest) {
			OriginalPPUMemory = CreatePPUMemory();
			long ActualSumOfRandomNumvers = 0;
			long SumOfRandomNumbersFromMemory = 0;

			for (int i = 0x0000; i < 0x3F20; i++) {
				if (i == 0x3000) {
					//jump folds
					i = 0x3F00;
				}
				int RandomNumber = rand() % 255;
				ActualSumOfRandomNumvers += RandomNumber;
				*OriginalPPUMemory[i] = RandomNumber;
			}


			for (int i = 0x0000; i < 0x3F20; i++) {
				if (i == 0x3000) {
					//jump folds
					i = 0x3F00;
				}
				
				SumOfRandomNumbersFromMemory+= *OriginalPPUMemory[i];
			}
			Assert::AreEqual(ActualSumOfRandomNumvers, SumOfRandomNumbersFromMemory);
		}
		/*
		TEST_METHOD(ADC_IME) {
			//0x69 opcode of ADC_IME 
			//ADC_IME adds Accumulator + immediate value + carry
			OriginalMainMemory = CreateMainMemory();
		    CPU aCPU(NULL, OriginalMainMemory, NULL);

			*OriginalMainMemory[0x0000] = 0x69;
			*OriginalMainMemory[0x0001] = 0b01111000;
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
		uint8_t** OriginalMainMemory;

		TEST_METHOD(AND_IME) {
			
			CPU* aCPU;

			//TEST1
			aCPU=CreateIME_Instruction(0x29, 0b00000001, OriginalMainMemory);

			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
			

			///TEST2 false true
			aCPU = CreateIME_Instruction(0x29, 0b00000000, OriginalMainMemory);

			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);
			


			//TEST3 true false
			aCPU = CreateIME_Instruction(0x29, 0b10000001, OriginalMainMemory);
			
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
			aCPU = CreateZABS_Instruction(0x25, 0b00000001, OriginalMainMemory);

			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 false true
			 aCPU = CreateZABS_Instruction(0x25, 0b00000000, OriginalMainMemory);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3 true false
			aCPU = CreateZABS_Instruction(0x25, 0b10000001, OriginalMainMemory);
		
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
			aCPU = CreateZINX_Instruction(0x35, 0b00000001, OriginalMainMemory);

			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 false true
			 aCPU = CreateZINX_Instruction(0x35, 0b00000000, OriginalMainMemory);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3 true false
			aCPU = CreateZINX_Instruction(0x35, 0b10000001, OriginalMainMemory);
			
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
			aCPU = CreateABS_Instruction(0x2D, 0b00000001, OriginalMainMemory);

			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 false true
		    aCPU = CreateABS_Instruction(0x2D, 0b00000000, OriginalMainMemory);
		
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3 true false
			aCPU = CreateABS_Instruction(0x2D, 0b10000001, OriginalMainMemory);
			
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
			aCPU = CreateINX_X_Instruction(0x3D, 0b00000001, OriginalMainMemory);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 false true
			 aCPU = CreateINX_X_Instruction(0x3D, 0b00000000, OriginalMainMemory);
	
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3 true false
			aCPU = CreateINX_X_Instruction(0x3D, 0b10000001, OriginalMainMemory);
			
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
			aCPU = CreateINX_Y_Instruction(0x39, 0b00000001, OriginalMainMemory);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 false true
		     aCPU = CreateINX_Y_Instruction(0x39, 0b00000000, OriginalMainMemory);
		
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0003, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3 true false
			aCPU = CreateINX_Y_Instruction(0x39, 0b10000001, OriginalMainMemory);

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
			aCPU = CreatePRII_Instruction(0x21, 0b00000001, OriginalMainMemory);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 false true
			 aCPU = CreatePRII_Instruction(0x21, 0b00000000, OriginalMainMemory);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3 true false
			aCPU = CreatePRII_Instruction(0x21, 0b10000001, OriginalMainMemory);
			
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
			aCPU = CreatePOII_Instruction(0x31, 0b00000001, OriginalMainMemory);
		
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000001, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsFalse(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);


			///TEST2 false true
			 aCPU = CreatePOII_Instruction(0x31, 0b00000000, OriginalMainMemory);
			
			aCPU->A = 0b11111111;
			aCPU->PC = 0x0000;
			aCPU->ExecuteNextInstruction();

			Assert::AreEqual(0b00000000, (int)aCPU->A);
			Assert::IsFalse(aCPU->GetSign());
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0x0002, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);



			//TEST3 true false
			aCPU = CreatePOII_Instruction(0x31, 0b10000001, OriginalMainMemory);
		
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
		uint8_t** OriginalMainMemory;

		TEST_METHOD(ASL_ACC) {
			//opcoe 0x0A 1 byte long
			CPU* aCPU;
			//TEST1
			aCPU = CreateACC_Instruction(0x0A,OriginalMainMemory);

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
			aCPU = CreateACC_Instruction(0x0A, OriginalMainMemory);

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
			aCPU = CreateACC_Instruction(0x0A, OriginalMainMemory);

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
			aCPU = CreateZABS_Instruction(0x06,0b10000000,OriginalMainMemory);

			Assert::IsFalse(aCPU->GetCarry());
			aCPU->ExecuteNextInstruction();
			Assert::IsTrue(aCPU->GetCarry());
			Assert::IsFalse(aCPU->GetSignFromData(aCPU->CPUMemory[TargetDataAddress_ZABS_MODE]));
			Assert::IsTrue(aCPU->GetZero());
			Assert::AreEqual(0b00000000, (int)*aCPU->CPUMemory[TargetDataAddress_ZABS_MODE]);

			Assert::AreEqual(0x02, (int)aCPU->PC);
			Assert::IsTrue(aCPU->FinishedExecutingCurrentInsctruction);

			//TEST2
			aCPU = CreateZABS_Instruction(0x06, 0b01000000, OriginalMainMemory);

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
			aCPU = CreateZABS_Instruction(0x06, 0b01000001, OriginalMainMemory);

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
	};
	
}
