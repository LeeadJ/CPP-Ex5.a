#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "sources/OrgChart.hpp"

using namespace ariel;

TEST_CASE("Testing Demo"){ //6
    OrgChart org;
    CHECK_NOTHROW(org.add_root("CEO"));
    CHECK_NOTHROW(org.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(org.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(org.add_sub("CEO", "COO"));
    CHECK_NOTHROW(org.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(org.add_sub("COO", "VP_BI"));
}
TEST_CASE("Testing Erros"){//15
    OrgChart org;
    CHECK_THROWS(org.add_sub("Grandparents", "MOMDAD"));
    CHECK_NOTHROW(org.add_root("Grandparents"));
    CHECK_NOTHROW(org.add_sub("Grandparents", "MOM&DAD"));
    CHECK_NOTHROW(org.add_root("GRANDPARENTS"));
    CHECK_THROWS(org.add_sub("Grandparents", "AMNON&NOA"));
    CHECK_NOTHROW(org.add_sub("GRANDPARENTS", "AMNON&NOA"));
    CHECK_NOTHROW(org.add_sub("MOM&DAD", "YUVAL"));
    CHECK_NOTHROW(org.add_sub("MOM&DAD", "LEEAD"));
    CHECK_NOTHROW(org.add_sub("MOM&DAD", "ELON"));
    CHECK_THROWS(org.add_sub("lEEAD", "LAVI"));
    CHECK_NOTHROW(org.add_sub("LEEAD", "LAVI"));
    CHECK_NOTHROW(org.add_sub("AMNON&NOA", "AVIGAIL"));
    CHECK_NOTHROW(org.add_sub("AMNON&NOA", "DARIA"));
    CHECK_NOTHROW(org.add_sub("AMNON&NOA", "SHIRA"));
    CHECK_NOTHROW(org.add_root("SABA&SAVTA"));

}
TEST_CASE("Testing Iterators"){
    OrgChart chart{};
    chart.add_root("CEO");
    chart.add_sub("CEO", "CTO");
    chart.add_sub("CEO", "CFO");
    chart.add_sub("CEO", "COO");
    chart.add_sub("CTO", "VP_SW");
    chart.add_sub("COO", "VP_BI");
    
    //Testing Level-Order
    std::vector<std::string> vec = {"CEO", "CTO", "CFO", "COO", "VP_SW", "VP_BI"}; 
    unsigned long i=0;
    for (auto it = chart.begin_level_order(); it != chart.end_level_order(); ++it){
        CHECK_EQ((*it), vec[i]);
        i++;
    }//prints: CEO CTO CFO COO VP_SW VP_BI 

    //Testing Reverse-Order
    std::vector<std::string> vec2 = {"VP_SW", "VP_BI", "CTO", "CFO", "COO", "CEO"};
    i=0;
    for (auto it = chart.begin_reverse_order(); it != chart.reverse_order(); ++it){
        CHECK_EQ((*it), vec2[i]);
        i++;
    } // prints: VP_SW VP_BI CTO CFO COO CEO 

    //Testing Pre-Order
    std::vector<std::string> vec3 = {"CEO", "CTO", "VP_SW", "CFO", "COO", "VP_BI"};
    i=0;
    for (auto it = chart.begin_preorder(); it != chart.end_preorder(); ++it) {
        CHECK_EQ((*it), vec3[i]);
        i++;
    } // prints: CEO CTO VP_SW CFO COO VP_BI

    i=0;
    for (auto element : chart){ // this should work like level order
        CHECK_EQ(element, vec[i]);
        i++;
    } // prints: CEO CTO CFO COO VP_SW VP_BI

    // demonstrate the arrow operator ->:
    std::vector<std::string> vec4 = {"333", "333", "333", "333", "55555", "55555"};
    i=0;
    for (auto it = chart.begin_level_order(); it != chart.end_level_order(); ++it){
        CHECK_NOTHROW(it.size());
        CHECK_EQ(it->size(), vec4.at(i++).size());
    } //: 3 3 3 3 5 5
}
TEST_CASE("Test iterator operators"){// 7
    OrgChart chart;
    CHECK_NOTHROW(chart.add_root("CEO"));
    CHECK_NOTHROW(chart.begin_level_order());
    CHECK_NOTHROW(chart.end_level_order());
    CHECK_NOTHROW(chart.begin_preorder());
    CHECK_NOTHROW(chart.end_preorder());
    CHECK_NOTHROW(chart.begin_reverse_order());
    CHECK_NOTHROW(chart.reverse_order());
}