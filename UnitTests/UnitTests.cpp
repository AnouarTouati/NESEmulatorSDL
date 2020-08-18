#include "pch.h"
#include "CppUnitTest.h"
#include "../NESEmulatorSDL/src/Log.h"
#include "../NESEmulatorSDL/src/main.h"
#include <sstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{


	TEST_CLASS(Class1)
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
	};
	


}
