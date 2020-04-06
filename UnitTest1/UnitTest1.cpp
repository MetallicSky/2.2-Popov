#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
#include "CppUnitTest.h"
#include "Map.h"
#include "List.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTestaistr1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestInsert_Find)
		{
			Map<string, int> test;
			test.insert("alpha", 23);
			test.insert("beta", 66842);
			test.insert("gamma", 46284);
			try
			{
				test.insert("alpha", 94);
			}
			catch (const std::exception & ex)
			{
				Assert::AreEqual(ex.what(), "attempt to add an existant key into map");
				Assert::AreEqual(3, test.getSize());
				Assert::AreEqual(23, test.find("alpha"));
				Assert::AreEqual(66842, test.find("beta"));
				Assert::AreEqual(46284, test.find("gamma"));
			}
			
		}
		TEST_METHOD(TestRemove)
		{

			Map<string, int> test;
			test.insert("alpha", 23);
			test.insert("beta", 66842);
			test.insert("gamma", 46284);
			test.remove("beta");
			Assert::AreEqual(NULL, test.find("beta"));
			test.remove("beta");
			Assert::AreEqual(2, test.getSize());
		}
		TEST_METHOD(TestClear)
		{
			Map<string, int> test;
			test.insert("alpha", 23);
			test.insert("beta", 66842);
			test.insert("gamma", 46284);
			test.clear();
			Assert::AreEqual(0, test.getSize());
		}
		TEST_METHOD(TestGetValues_GetKeys)
		{
			Map<string, int> test;
			test.insert("alpha", 23);
			test.insert("beta", 66842);
			test.insert("gamma", 46284);
			List<string> kys;
			test.get_keys(kys);
			List<int> vls;
			test.get_values(vls);
			Assert::AreEqual(3, kys.GetSize());
			Assert::AreEqual(3, vls.GetSize());
			string al = "alpha";
			string be = "beta";
			string ga = "gamma";
			Assert::AreEqual(al, kys[0]);
			Assert::AreEqual(be, kys[1]);
			Assert::AreEqual(ga, kys[2]);
			Assert::AreEqual(23, vls[0]);
			Assert::AreEqual(66842, vls[1]);
			Assert::AreEqual(46284, vls[2]);
		}
	};
}
