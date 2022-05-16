#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "Node.hpp"

namespace ariel{
    class OrgChart{
        std::vector<Node*> _chartNodes;

        public:
            //Getters:
            std::vector<Node*> getChartNodes() {return this->_chartNodes;}

            //Constructors:
            OrgChart(); //initialization with no arguments

            //Destructor:
            ~OrgChart();

            //Functions:
            OrgChart& add_root(const std::string& root);
            OrgChart& add_sub(const std::string& parent, const std::string& child);
            friend std::ostream& operator << (std::ostream& out, const OrgChart& chart);

            //Iterator
            class iterator{
                int _size;

                public:
                    //Constructor
                    iterator();

                    //Functions:
                    int size() const {return this->_size;}
                    bool operator != (const iterator& other) const;
                    bool operator == (const iterator& other) const;
                    std::string* operator -> (); //returns a pointer
                    std::string* operator * (); //returns the value of the string
                    iterator& operator ++ (); 
                    iterator& operator ++ (int);
            };
            
            //Iterator Functions:
            iterator begin();
            iterator end();
            iterator begin_level_order() const;
            iterator end_level_order() const;

            iterator begin_reverse_order() const;
            iterator end_reverse_order() const;

            iterator begin_preorder() const;
            iterator end_preorder() const;

            friend std::ostream& operator << (const std::ostream& out, const iterator& itr);

    };
}