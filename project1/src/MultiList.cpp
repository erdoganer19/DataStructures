#include <iostream>
#include <string>
#include "../include/MultiList.h"

using namespace std;

MultiList::MultiList()
{
    head=NULL;
    tail=NULL;
}

MultiList::~MultiList()
{
    DateNode* p1 = head;
    DateNode* n1 = head;
    TSiteNode* p2 = NULL;
    TSiteNode* n2 = NULL;

    while(n1!=NULL){
        n2 = n1->get_up();
        p2 = n2->get_up();
        while(n2!=NULL)
        {
            n2 = p2->get_up();
            delete p2;
            p2 = n2;
        }
        n1=p1->get_next();
        delete p1;
        p1=n1;
    }
}


DateNode* MultiList::search(string date){
    DateNode* current=head;//we are starting from the head

    DateNode * ptr=NULL;//ptr is the pointer that we return 

    while(current!=NULL){
        if(current->get_date()>date  ){
            ptr=current->get_prev();
            break;
        }

        if(!current->get_next()){
            ptr = current;
            break;
        }
        current=current->get_next();
    }



    return ptr;
}


void MultiList::add_node(string date,string time,string site_name)
{   
    DateNode *current;//Current (temp)
    current=head;
    //current=tail;
    bool exist=false;
    while(current){
        if(current->get_date()==date){
            exist=true;
            break;
        }
        current=current->get_next();
    }
    if(!exist){
        DateNode* node= new DateNode(date);
        DateNode* prev=search(date);
        node->set_up(NULL);
        node->set_prev(prev);
        if(!prev){
            node->set_prev(NULL);
            node->set_next(head);
            head=node;
        }else{
            node->set_next(prev->get_next());
            prev->set_next(node);
            
        }
        if(prev==tail){
            tail=node;
        }else{
            node->get_next()->set_prev(node);
        }
        current=node;
    }
    if((!current->get_next()) && (!current->get_prev())){
        tail = current;
    }
    TSiteNode* TempUp;//To add upnode
    TSiteNode* prevTempUp;
    TempUp=current->get_up();
    prevTempUp=NULL;
    
    while(TempUp){

     if(TempUp->get_time()>time){

         break;
     }
    prevTempUp=TempUp;
    TempUp=TempUp->get_up();

    }

    TSiteNode* newUp= new TSiteNode(time, site_name);
   
   
    if(!prevTempUp){
        newUp->set_up(current->get_up());
        current->set_up(newUp);
    }else{
        newUp->set_up(prevTempUp->get_up());
        prevTempUp->set_up(newUp);
    }



}



void MultiList::remove_node(string date,string time)
{
    DateNode* current=head;//Current DateNode will be using as a sheld
    DateNode* tracker=head;//Tracker
    TSiteNode* currenti;
    TSiteNode* trackeri;

    bool exist=false;
    int upCounter=0;

    while(current->get_date()!=date && current->get_next()!=NULL){
        current=current->get_next();
        if(current->get_date()==date){
            exist=true;
            break;
        }
    }

    if(current->get_date()==date && current->get_next()==NULL){
            exist=true;
        }
    

    currenti=current->get_up();
    trackeri=tracker->get_up();

    if(exist==true){


        if(currenti->get_time()==time){
            current->set_up(NULL);
        }

        else{

        while(currenti->get_time()!=time && currenti->get_up()!=NULL){
            currenti=currenti->get_up();
            upCounter++;// 2 olsun
        }

        for(int i=0;upCounter>i;i++){
            trackeri=trackeri->get_up();
        }

        trackeri->set_up(trackeri->get_up()->get_up());

        }

    }
}

void MultiList::print_list()
{
    DateNode* p_hor=head;
    TSiteNode* p_ver;

    while(p_hor)
    {
        cout<<p_hor->get_date()<<":"<<endl;
        p_ver=p_hor->get_up();
        while(p_ver)
        {
            cout<<p_ver->get_time()<<"->"<<p_ver->get_site_name()<<endl;
            p_ver=p_ver->get_up();
        }
        p_hor=p_hor->get_next();
    }

}