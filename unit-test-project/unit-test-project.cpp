#include "pch.h"
#include "CppUnitTest.h"

#include "../dimkavvs/conference_programm.h"
#include "../dimkavvs/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	conference_programm* build_conference_programm(int start_hour, int start_minute, int finish_hour, int finish_minute)
	{
		conference_programm* lectures = new conference_programm;
		lectures->start.hour = start_hour;
		lectures->start.minute = start_minute;
		lectures->finish.hour = finish_hour;
		lectures->finish.minute = finish_minute;
		return lectures;
	}
	void delete_conference_programm(conference_programm* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}


	TEST_CLASS(unittestproject)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			conference_programm* lectures[3];
			lectures[0] = build_conference_programm(8, 30, 10, 0); // 90
			lectures[1] = build_conference_programm(10, 30, 12, 0); // 90 
			lectures[2] = build_conference_programm(9, 0, 12, 0); // 180 
			Assert::AreEqual(180, process(lectures, 3));
			delete_conference_programm(lectures, 3);
		}


		TEST_METHOD(TestMethod2)
		{
			conference_programm* lectures[3];
			lectures[0] = build_conference_programm(9, 0, 10, 0); // 60
			lectures[1] = build_conference_programm(9, 0, 10, 0); // 60
			lectures[2] = build_conference_programm(9, 0, 10, 0); // 60 
			Assert::AreEqual(60, process(lectures, 3));
			delete_conference_programm(lectures, 3);
		}


		TEST_METHOD(TestMethod3)
		{
			conference_programm* lectures[1];
			lectures[0] = build_conference_programm(8, 30, 10, 0); // 90
			Assert::AreEqual(90, process(lectures, 1));
			delete_conference_programm(lectures, 1);
		}
	};
}