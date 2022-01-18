#include "pch.h"
#include "CppUnitTest.h"

#include "../Kod/Pracownik.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testy_Pracownik
{
	TEST_CLASS(test_getterow)
	{
	public:
		TEST_METHOD(test_get_login)
		{
			Pracownik p1("xyz", "abc");
			string login = "xyz";
			Assert::AreEqual(login, p1.get_login());
		}
		TEST_METHOD(test_get_haslo)
		{
			Pracownik p1("xyz", "abc");
			string haslo = "abc";
			Assert::AreEqual(haslo, p1.get_haslo());
		}
		
	};
}
