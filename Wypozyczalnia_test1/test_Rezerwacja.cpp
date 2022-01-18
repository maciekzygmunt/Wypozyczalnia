#include "pch.h"
#include "CppUnitTest.h"

#include "../Kod/Rezerwacja.cpp"
#include "../Kod/Wypozyczenie.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
	TEST_CLASS(test_oblicz) {
	public:
		TEST_METHOD(test_oblicz_koszt) {
			Data d1(12, 1, 2022);
			Data d2(20, 1, 2022);
			Wypozyczenie w1;
			Rezerwacja r1(d1, d2, w1, "", "", 0);
			Assert::AreEqual(640, r1.oblicz_koszt(80));
		}
		TEST_METHOD(test_oblicz_koszt2) {
			Data d1(30, 12, 2021);
			Data d2(5, 1, 2022);
			Wypozyczenie w1;
			Rezerwacja r1(d1, d2, w1, "", "", 0);
			Assert::AreEqual(0, r1.oblicz_koszt(60));
		}
		TEST_METHOD(test_oblicz_koszt3) {
			Data d1(30, 1, 2022);
			Data d2(3, 2, 2022);
			Wypozyczenie w1;
			Rezerwacja r1(d1, d2, w1, "", "", 0);
			Assert::AreEqual(200, r1.oblicz_koszt(50));
		}
	};
}