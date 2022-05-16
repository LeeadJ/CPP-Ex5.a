#pragma once
#include <iostream>
#include <string>
#include <vector>


namespace ariel{
    class OrgChart{
        private:
            std::vector<int> _chartNodes;
        public:
            //Constructor:
            OrgChart();

            //Class iterator:
            class iterator{
                public:
                    int _size;

                    //Constructor:
                    iterator();

                    //iterator Functions:
                    int size();
                    bool operator != (const iterator& itr_other);
                    bool operator == (iterator& itr_other);
                    iterator operator ++ ();
                    iterator* operator -> ();
                    iterator operator * ();
                    
                 
            };
            OrgChart& add_root(const std::string& root);
            OrgChart& add_sub(const std::string& parent,const std::string& child);

            iterator begin();
            iterator end();

            iterator begin_level_order() const;
            iterator end_level_order() const;

            iterator begin_reverse_order() const;
            iterator reverse_order() const;

            iterator begin_preorder() const;
            iterator end_preorder() const;

            friend std::ostream& operator << (std::ostream& out, OrgChart& chart);
            friend std::ostream& operator << (std::ostream& out, const iterator& itr);
    };
}