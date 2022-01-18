#include "pch.h"
#include "CppUnitTest.h"

#include "../Kod/Data.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testy_Data
{
	TEST_CLASS(test_getterow)
	{
	public:
		
		TEST_METHOD(test_get_rok)
		{
			Data  d1(12,3,2022);
			int rok = 2022;
			Assert::AreEqual(rok, d1.get_rok());
		}
		TEST_METHOD(test_get_miesiac)
		{
			Data  d1(12, 3, 2022);
			Assert::AreEqual(3, d1.get_miesiac());
		}
		TEST_METHOD(test_get_dzien)
		{
			Data  d1(12, 3, 2022);
			Assert::AreEqual(12, d1.get_dzien());
		}
	};
}
