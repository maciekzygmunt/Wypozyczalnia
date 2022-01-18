#include "pch.h"
#include "CppUnitTest.h"

#include "../Kod/Rezerwacja.cpp"
#include "../Kod/Wypozyczenie.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// TODO: testy dla metody oblicz_koszt (nowa klasa!!!)

namespace testy_Rezerwacja
{
	TEST_CLASS(test_getterow)
	{
	public:
			TEST_METHOD(test_get_koszt)
			{
				Rezerwacja r1;
				Assert::AreEqual(0, r1.get_koszt());
			}
			TEST_METHOD(test_get_koszt2)
			{
				Data d1, d2;
				Wypozyczenie w1;
				Rezerwacja r1(d1,d2,w1,"","",1000);
				Assert::AreEqual(1000, r1.get_koszt());
			}
			 
	};
}