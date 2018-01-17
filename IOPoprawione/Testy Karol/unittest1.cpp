#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\IO\User.cpp"
#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestyKarol
{
	TEST_CLASS(TestyKarol)
	{
	public:

		TEST_METHOD(registerTest)
		{
			Assert::AreEqual(User::registerUser("janek", "qwerty123", "Jan", "Kowalski", "jan@kowalski.pl"), true);
			Assert::AreEqual(User::registerUser("mariuszek", "asdfgh321", "Mariusz", "Nowak", "jan@kowalski.pl"), false);//powtarza sie email
			Assert::AreEqual(User::registerUser("janek", "asdfgh321", "Mariusz", "Nowak", "mariusz@nowak.com"), false);//powtarza sie username
			Assert::AreEqual(User::registerUser("grazynka", "grazka11", "Grazyna", "Wisniewska", "grazyna@krakow.pl"), true);
		}
		TEST_METHOD(authenticateTest)
		{
			Assert::AreEqual(User::authenticateUser("janek", "qwerty123"), true);
			Assert::AreEqual(User::authenticateUser("jan@kowalski.pl", "qwerty123"), true);
			Assert::AreEqual(User::authenticateUser("janek", "zlehaslo"), false);
			Assert::AreEqual(User::authenticateUser("zlylogin", "qwerty123"), false);
		}

	};
}