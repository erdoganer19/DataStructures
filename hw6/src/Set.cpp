#include <vector>
#include <bits/stdc++.h>
#include "Set.h"

using namespace std;

void Traverse_postorder_intersect(Node* node,unordered_map<int, char> &ump){

    if(node!=NULL){
        Traverse_postorder_intersect(node->get_left(),ump);
        Traverse_postorder_intersect(node->get_right(),ump);
        ump[node->get_data()]='e';
    }

}

void set_postorderintersect(Node* node,unordered_map<int, char> &ump,vector<int> &intersections){
       if(node!=NULL){
        set_postorderintersect(node->get_left(),ump,intersections);
        set_postorderintersect(node->get_right(),ump,intersections);
        if(ump[node->get_data()]=='e'){
            intersections.push_back(node->get_data());
       }
    }
}

vector<int> Set::get_intersection(BT* bt1, BT* bt2)
{
    vector<int> intersections;
    Node *first=bt1->get_root();
    Node *second=bt2->get_root();
    unordered_map<int, char> ump;

    Traverse_postorder_intersect(first,ump);
    set_postorderintersect(second,ump,intersections);

    return intersections;
}


void set_postorderunion(Node* node,unordered_map<int, char> &ump,vector<int> &unions){
       if(node!=NULL){
        set_postorderunion(node->get_left(),ump,unions);
        set_postorderunion(node->get_right(),ump,unions);
        if(ump[node->get_data()]!='e'){
            unions.push_back(node->get_data());
       }
    }
}



void Traverse_postorder_union(Node* node,unordered_map<int, char> &ump,vector<int> &unions){

    if(node!=NULL){
        Traverse_postorder_union(node->get_left(),ump,unions);
        Traverse_postorder_union(node->get_right(),ump,unions);
        ump[node->get_data()]='e';
        unions.push_back(node->get_data());
    }

}


vector<int> Set::get_union(BT* bt1, BT* bt2)
{
    vector<int> unions;
    Node *first=bt1->get_root();
    Node *second=bt2->get_root();
    unordered_map<int, char> ump;
    Traverse_postorder_union(first,ump,unions);
    set_postorderunion(second,ump,unions);

    return unions;
}
