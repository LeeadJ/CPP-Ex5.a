#include "OrgChart.hpp"
#include<string>
#include<iostream>




namespace ariel{

    //OrgChart Constructor:
    OrgChart::OrgChart(){}

    //Class iterator:
    //Constructor:
    OrgChart::iterator::iterator(){
        this->_size=0;
    }

    //Iterator Functions:
    std::string OrgChart::iterator::size(){
        std::string ans = std::to_string(this->_size);
        return ans;
    }

    //Iterator Operators:
    bool OrgChart::iterator::operator != (const OrgChart::iterator& itr_other){
        return false;
    }
    bool OrgChart::iterator::operator == (iterator& itr_other){
        return false;
    }
    std::string OrgChart::iterator::operator * (){
        return "";
    }
    OrgChart::iterator OrgChart::iterator::operator ++ (){
        return *this;
    }
    std::string* OrgChart::iterator::operator -> (){
        std::string* temp;
        return temp;
    }

    //OrgChart Functions:
    OrgChart& OrgChart::add_root(const std::string& root){
        return *this;
        }
    OrgChart& OrgChart::add_sub(const std::string& parent,const std::string& child){
        return *this;
    }

    OrgChart::iterator OrgChart::begin(){
        return OrgChart::iterator();
    }
    OrgChart::iterator OrgChart::end(){
        return OrgChart::iterator();
    }

    OrgChart::iterator OrgChart::begin_level_order() const{
        return OrgChart::iterator();
    }
    OrgChart::iterator OrgChart::end_level_order() const{
        return OrgChart::iterator();
    }

    OrgChart::iterator OrgChart::begin_reverse_order() const{
        return OrgChart::iterator();
    }
    OrgChart::iterator OrgChart::reverse_order() const{
        return OrgChart::iterator();
    }

    OrgChart::iterator OrgChart::begin_preorder() const{
        return OrgChart::iterator();
    }
    OrgChart::iterator OrgChart::end_preorder() const{
        return OrgChart::iterator();
    }

    std::ostream& operator << (std::ostream& out, OrgChart& chart){
        return out;
    }
    std::ostream& operator << (std::ostream& out, const OrgChart::iterator& itr){
        return out;
    }
    
    
    
}