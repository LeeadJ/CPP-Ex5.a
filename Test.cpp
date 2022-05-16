#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "OrgChart.hpp"

using namespace ariel;

TEST_CASE("Testing Demo"){
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("CEO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "COO"));
    CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));
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
    // std::string lo = "CEO CTO CFO COO VP_SW VP_BI "; 
    unsigned long i=0;
    for (auto it = chart.begin_level_order(); it != chart.end_level_order(); ++it){
        
        CHECK((*it) == vec[i]);
        i++;

        // if(i==5){
        //     break;
        // }
    }


    //Testing Reverse-Order
    std::vector<std::string> vec2 = {"VP_SW", "VP_BI", "CTO", "CFO", "COO", "CEO"};
    i=0;
    for (auto it = chart.begin_reverse_order(); it != chart.reverse_order(); ++it){
        CHECK((*it) == vec2[i]);
        i++;
        // if(i==5){
        //     break;
        // }
    } // prints: VP_SW VP_BI CTO CFO COO CEO 

    //Testing Pre-Order
    std::vector<std::string> vec3 = {"CEO", "CTO", "VP_SW", "CFO", "COO", "VP_BI"};
    i=0;
    for (auto it = chart.begin_preorder(); it != chart.end_preorder(); ++it) {
        CHECK((*it) == vec3[i]);
        i++;
        // if(i==5){
        //     break;
        // }
    } // prints: CEO CTO VP_SW CFO COO VP_BI

    i=0;
    for (auto element : chart){ // this should work like level order
        CHECK(element == vec[i]);
        i++;
        // if(i==5){
        //     break;
        // }
    } // prints: CEO CTO CFO COO VP_SW VP_BI

    // demonstrate the arrow operator:
    std::vector<std::string> vec4 = {"3", "3", "3", "3", "5", "5"};
    i=0;
    for (auto it = chart.begin_level_order(); it != chart.end_level_order(); ++it){
        // CHECK(it->size() == vec4[i++]);
        CHECK_NOTHROW(it.size());
    } // prints: 3 3 3 3 5 5
}
TEST_CASE("Test No Error"){
    OrgChart chart;
    chart.add_root("CEO");
    for(int i=0;i<4;i++){
        CHECK_NOTHROW(chart.begin_level_order());
        CHECK_NOTHROW(chart.end_level_order());
        CHECK_NOTHROW(chart.begin_preorder());
        CHECK_NOTHROW(chart.end_preorder());
        CHECK_NOTHROW(chart.begin_reverse_order());
        CHECK_NOTHROW(chart.reverse_order());
        CHECK_NOTHROW(chart.add_sub("CEO", "Leead"));
    }
}