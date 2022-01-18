#include "pch.h"
#include "CppUnitTest.h"

#include "../Kod/Samochod.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace testy_Samochod
{
	TEST_CLASS(test_getterow)
	{
	public:
		TEST_METHOD(test_get_marka)
		{
			Samochod s1;
			s1.set_samochod("marka", "model", 99, "nadwozie", "xxx", -10);
			string napis = "marka";
			Assert::AreEqual(napis, s1.get_marka());
		}
		TEST_METHOD(test_get_model)
		{
			Samochod s1;
			s1.set_samochod("marka", "model", 99, "nadwozie", "xxx", -10);
			string napis = "model";
			Assert::AreEqual(napis, s1.get_model());
		}
		TEST_METHOD(test_get_ilosc_drzwi)
		{
			Samochod s1;
			s1.set_samochod("marka", "model", 99, "nadwozie", "xxx", -10);

			Assert::AreEqual(99, s1.get_ilosc_drzwi());
		}
		TEST_METHOD(test_get_rodzaj_nadwozia)
		{
			Samochod s1;
			s1.set_samochod("marka", "model", 99, "nadwozie", "xxx", -10);
			string napis = "nadwozie";
			Assert::AreEqual(napis, s1.get_rodzaj_nadwozia());
		}
		TEST_METHOD(test_get_numer_rejestracji)
		{
			Samochod s1;
			s1.set_samochod("marka", "model", 99, "nadwozie", "xxx", -10);
			string napis = "xxx";
			Assert::AreEqual(napis, s1.get_numer_rejestracji());
		}
		TEST_METHOD(test_get_cena_za_dobe)
		{
			Samochod s1;
			s1.set_samochod("marka", "model", 99, "nadwozie", "xxx", -10);
			Assert::AreEqual(-10, s1.get_cena_za_dobe());
		}
	};
}
