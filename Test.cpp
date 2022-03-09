// This is my first try in writing Test in cpp
//
// Created by gilivex on 8.3.2022.
//


#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>

using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}

TEST_CASE("Good input"){
        CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                        "@-------@\n"
                                                        "@-@@@@@-@\n"
                                                        "@-@---@-@\n"
                                                        "@-@@@@@-@\n"
                                                        "@-------@\n"
                                                        "@@@@@@@@@"));

        CHECK(nospaces(mat(3,5,'-','@')) == nospaces("---\n"
                                                     "-@-\n"
                                                     "-@-\n"
                                                     "-@-\n"
                                                     "---\n"));

        CHECK(nospaces(mat(3,3,'@','-')) == nospaces("---\n"
                                                     "-@-\n"
                                                     "-@-\n"
                                                     "-@-\n"
                                                     "---\n"));

        CHECK(nospaces(mat(3,3,'@','-')) == nospaces("@@@\n"
                      "@-@\n"
                      "@@@\n"));

        CHECK(nospaces(mat(3,3,'-','@')) == nospaces("---\n"
                      "-@-\n"
                      "---\n"));

        CHECK(nospaces(mat(1,1,'-','@')) == nospaces("-\n"));
        CHECK(nospaces(mat(1,1,'@','-')) == nospaces("@\n"));

        CHECK(nospaces(mat(3,1,'@','-')) == nospaces("@\n"
                                                     "@\n"
                                                     "@\n"));
        CHECK(nospaces(mat(1,3,'@','-')) == nospaces("@@@\n"));


}

TEST_CASE("bud input from user") {
        CHECK_THROWS(mat(3, 5, 9, '%'));
        CHECK_THROWS(mat(7, 5, '$', 7));
        CHECK_THROWS(mat(7, 9, '$', 'A'));
}

TEST_CASE("Not All Odd") {
        CHECK_THROWS(mat(10, 6, '$', '%'));
        CHECK_THROWS(mat(10, 5, '$', '%'));
        CHECK_THROWS(mat(5, 10, '$', '%'));

}

TEST_CASE("Zero") {
        CHECK_THROWS(mat(0, 0, '$', '%'));
        CHECK_THROWS(mat(0, 5, '$', '%'));
        CHECK_THROWS(mat(3, 0, '$', '%'));
}

TEST_CASE("Negatives") {

        CHECK_THROWS(mat(-1, 5, '$', '%'));
        CHECK_THROWS(mat(5, -1, '$', '%'));
        CHECK_THROWS(mat(-5, -3, '$', '%'));

}

