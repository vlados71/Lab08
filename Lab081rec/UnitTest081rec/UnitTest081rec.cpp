#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab081rec/Lab081rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab81rec
{
    TEST_CLASS(UnitTestLab81rec)
    {
    public:

        TEST_METHOD(CountTwoGroups)
        {
            Assert::AreEqual(2, Count("a,-b,-c", 0));
        }

        TEST_METHOD(CountNoGroups)
        {
            Assert::AreEqual(0, Count("abc", 0));
            Assert::AreEqual(0, Count("-,", 0));
            Assert::AreEqual(0, Count(", -", 0));
            Assert::AreEqual(0, Count("", 0));
        }

        TEST_METHOD(CountConsecutiveGroups)
        {
            Assert::AreEqual(3, Count(",-,-,-", 0));
        }

        TEST_METHOD(ChangeOneGroup)
        {
            char s[30] = "a,-b";
            char dest[30] = "";
            char* r = Change(dest, s, dest, 0);

            Assert::AreEqual("a*b", (const char*)dest);
            Assert::AreEqual("a*b", (const char*)r);
        }

        TEST_METHOD(ChangeConsecutiveGroups)
        {
            char s[30] = ",-,-,-";
            char dest[30] = "";
            char* r = Change(dest, s, dest, 0);

            Assert::AreEqual("***", (const char*)dest);
            Assert::AreEqual("***", (const char*)r);
        }

        TEST_METHOD(ChangeNoGroups)
        {
            char s[30] = "abc,d-e";
            char dest[30] = "";
            char* r = Change(dest, s, dest, 0);

            Assert::AreEqual("abc,d-e", (const char*)dest);
            Assert::AreEqual("abc,d-e", (const char*)r);
        }

        TEST_METHOD(ChangeEmptyString)
        {
            char s[10] = "";
            char dest[10] = "";
            char* r = Change(dest, s, dest, 0);

            Assert::AreEqual("", (const char*)dest);
            Assert::AreEqual("", (const char*)r);
        }
    };
}