#include "pch.h"
#include "CppUnitTest.h"

#include "../Kod/Menedzer.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testy_Menedzer
{
	TEST_CLASS(test_getterow)
	{
	public:
			TEST_METHOD(test_get_login)
			{
				Menedzer m1("xyz", "abc");
				string login = "xyz";
				Assert::AreEqual(login, m1.get_login());
			}
			TEST_METHOD(test_get_haslo)
			{
				Menedzer m1("xyz", "abc");
				string haslo = "abc";
				Assert::AreEqual(haslo, m1.get_haslo());
			}
	};
}
