#include "pch.h"
#include "CppUnitTest.h"
#include "../lab9.2_B/Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab92AUT
{
	TEST_CLASS(Lab92AUT)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int N = 0;
			int t = 0;
			Index_sort(0, N);
			Assert::AreEqual(t, 0);
		}
	};
}
