#include "OrgChart.hpp"

namespace ariel{
    //Constructors:
    OrgChart::OrgChart(){} //initialization with no arguments

    //Functions:
    OrgChart& OrgChart::add_root(const std::string& root){
        return *this;
    }
    OrgChart& OrgChart::add_sub(const std::string& parent, const std::string& child){
        return *this;
    }
    std::ostream& operator << (std::ostream& out, const OrgChart& chart){
        return out;
    }

    //Iterator:
    OrgChart::iterator::iterator(){};
    bool  OrgChart::iterator::operator != (const iterator& other) const{
        return true;
    }
    bool  OrgChart::iterator::operator == (const iterator& other) const{
        return true;
    }
    std::string* OrgChart::iterator::operator -> (){
        std::string* test;
        return test;
    }
    std::string* OrgChart::iterator::operator * (){
        std::string* test;
        return test;
    }
    iterator& OrgChart::iterator::operator ++ (){
        return OrgChart::iterator();
    }
    iterator& OrgChart::iterator::operator ++ (int){
        return OrgChart::iterator();
    }

    //Iterator Functions:
    iterator begin(){
        return OrgChart::iterator(); 
    }
    iterator end(){
        return OrgChart::iterator();
    }
    iterator OrgChart::begin_level_order() const{
        return OrgChart::iterator();
    }
    iterator OrgChart::end_level_order() const{
        return OrgChart::iterator();
    }

    iterator OrgChart::begin_reverse_order() const{
        return OrgChart::iterator();
    }
    iterator OrgChart::end_reverse_order() const{
        return OrgChart::iterator();
    }

    iterator OrgChart::begin_preorder() const{
        return OrgChart::iterator();
    }
    iterator OrgChart::end_preorder() const{
        return OrgChart::iterator();
    }

    std::ostream& operator << (const std::ostream& out, const iterator& itr){
        return out;
    }
}