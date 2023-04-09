/* @Author
Student Name: <Ertug Erdogan>
Student ID : <150190714d>
Date: <23.03.2022> */

#include "trackLinkedList.h"
#include <stdio.h>

using namespace std;


TrackLinkedList::TrackLinkedList()
{
    head=NULL;
    tail=NULL;

}

TrackLinkedList::~TrackLinkedList()
{
    if (head) {
        
        TrackNode* p = tail;

        while (p != head) {
            p->set_next(head->get_next());
            delete head;
            head = p->get_next();
        }
        if (p == head) {
            delete head;
        }
    }

}

void TrackLinkedList::print_list(bool isReverse)
{
    TrackNode* p;
    TrackNode* target;
    if (isReverse){
        p = this->tail;
        target = this->head;
    }
    else{
        p = this->head;
        target = this->tail;
    }
    
    if (p == NULL)
        return;

    int d = 0;
    while (p->step_node(isReverse) != target->step_node(isReverse)){
        cout << "----------------------" << d << "----------------------" << endl;
        p->get_node_info();
        p = p->step_node(isReverse);
        d++;
    }
    cout << "----------------------" << d << "----------------------" << endl;
    p->get_node_info();
}

TrackNode* TrackLinkedList::search(int view)
{
    TrackNode* p=head;
    TrackNode* m=head;
    int i=0;
    
    if(view>m->get_views()){
        return NULL;
    }

    while(p->get_views()>view){
        if(p->get_next()==head){
            return p;
        }
        else{
            p=p->get_next();
            i++;
        }
    }

    for(int k=0;k<(i-1);k++){
        m=m->get_next();
    }
    
    return m;

}

void TrackLinkedList::add_node(TrackNode* node)
{
    if(head==NULL){
        node->set_next(node);
        node->set_prev(node);
        head=node;
        tail=node;
    }else{
    TrackNode *previous;
    TrackNode *next;
    
        int Nviews=node->get_views();
        previous=search(Nviews);
        if(previous==NULL){
            node->set_prev(tail);
            node->set_next(head);
            tail->set_next(node);
            head->set_prev(node);
            head=node;
        }
        
        else{
            if(previous->get_next()==head){
                previous->set_next(node);
                node->set_next(head);
                node->set_prev(previous);
                head->set_prev(node);
                tail=node;

            }
            else{
                next=previous->get_next();
                previous->set_next(node);
                node->set_next(next);
                node->set_prev(previous);
                next->set_prev(node);
            }

          
        }

    }

}

void TrackLinkedList::reduce_duplicates()
{
  
    TrackNode *p,*m;
    p = head;

    while(p->get_views()>p->get_next()->get_views()){
        m=p->get_next();
        
        while(m->get_next()!=head->get_next()){
            int k=0;
            if(p->get_kwd()==m->get_kwd()){
                
                if(m==tail){
                
                    m->get_prev()->set_next(head);
                    head->set_prev(m->get_prev());
                    tail=m->get_prev();
                }else{
                    
                    m->get_prev()->set_next(m->get_next());
                    m->get_next()->set_prev(m->get_prev());
                   
                }
                    k= p->get_views()+m->get_views();
                    p->set_views(k);
                    
            }
            m=m->get_next();
            
        }
        p=p->get_next();
    }

}

KwdLinkedList::KwdLinkedList()
{
    head=NULL;
    tail=NULL;

}

KwdLinkedList::~KwdLinkedList()
{
  if(head!=NULL)
        delete head;
}

KwdNode* KwdLinkedList::search(string kwd)
{
    KwdNode* p=head;
    KwdNode *m=NULL;
        while(p!=NULL){
           
           if(p->get_keyword()==kwd){
               m=p;
               break;
           }
            p=p->get_next();    
        }
    return m;
}

void KwdLinkedList::add_node(string kwd)
{
    KwdNode *node=new KwdNode(kwd);
            
        if(head==NULL){
            head=node;
            tail=node;
        }else{
        KwdNode *previous;
        KwdNode *next;
            string searched_keyword=kwd;
            previous=search(searched_keyword);
            if(previous==NULL){
                node->set_next(head);
                head=node;

            }else{
                next=previous->get_next();
                node->set_next(next);
                previous->set_next(node);
            }

    }

    delete node;
}

bool KwdLinkedList::contains(string kwd)
{
    KwdNode* p=head;
        bool m=false;
        while(p!=NULL){
            if(p->get_keyword()==kwd){
               m=true;
            }
            p=p->get_next();    
        }
    return m;
}