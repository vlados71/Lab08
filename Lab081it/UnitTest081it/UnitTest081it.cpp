#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab081it/Lab081it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab81
{
    TEST_CLASS(UnitTestLab81)
    {
    public:

        TEST_METHOD(CountTwoGroups)
        {
            Assert::AreEqual(2, Count("a,-b,-c"));
        }

        TEST_METHOD(CountNoGroups)
        {
            Assert::AreEqual(0, Count("abc"));
            Assert::AreEqual(0, Count("-,"));     // зворотний порядок
            Assert::AreEqual(0, Count(", -"));    // пробіл між символами
            Assert::AreEqual(0, Count(""));
        }

        TEST_METHOD(CountSingleChars)
        {
            Assert::AreEqual(0, Count(","));
            Assert::AreEqual(0, Count("-"));
        }

        TEST_METHOD(CountConsecutiveGroups)
        {
            Assert::AreEqual(3, Count(",-,-,-"));
        }

        TEST_METHOD(ChangeOneGroup)
        {
            char s[30] = "a,-b";
            char* r = Change(s);
            Assert::AreEqual("a*b", s);   // перевірка параметра
            Assert::AreEqual("a*b", r);   // перевірка результату функції
            delete[] r;
        }

        TEST_METHOD(ChangeConsecutiveGroups)
        {
            char s[30] = ",-,-,-";
            char* r = Change(s);
            Assert::AreEqual("***", s);
            Assert::AreEqual("***", r);
            delete[] r;
        }

        TEST_METHOD(ChangeNoGroups)
        {
            char s[30] = "abc,d-e";
            char* r = Change(s);
            Assert::AreEqual("abc,d-e", s);
            Assert::AreEqual("abc,d-e", r);
            delete[] r;
        }

        TEST_METHOD(ChangeExtraCommaBefore)
        {
            char s[30] = ",,--";
            char* r = Change(s);
            Assert::AreEqual(",*-", s);   // замінюється лише пара ",-" всередині
            Assert::AreEqual(",*-", r);
            delete[] r;
        }

        TEST_METHOD(ChangeEmptyString)
        {
            char s[10] = "";
            char* r = Change(s);
            Assert::AreEqual("", s);
            Assert::AreEqual("", r);
            delete[] r;
        }
    };
}