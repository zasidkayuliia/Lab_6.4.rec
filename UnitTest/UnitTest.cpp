#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.4.rec/Lab_6.4.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int testArray[] = { 2, 4, 6, 8, 10 };
			int size = sizeof(testArray) / sizeof(testArray[0]);
			double result = findMinAbsElement(testArray, size);

			Assert::AreEqual(2.0, result);
		}
	};
}
