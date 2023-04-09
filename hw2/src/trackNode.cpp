#include "trackNode.h"
#include <stdio.h>

using namespace std;


TrackNode::TrackNode(int views, string name, string artist_name, string kwd, string url)
{
    this->views=views;
    this->name=name;
    this->artist_name=artist_name;
    this->kwd=kwd;
    this->url=url;
    this->set_next(NULL);
    this->set_prev(NULL); 

}

TrackNode::~TrackNode()
{   
    TrackNode *p;
    p=this;
    p->get_next()->set_prev(p->get_prev());
    p->get_prev()->set_next(p->get_next());
}

void TrackNode::set_name(string s)
{
    this->name = s;
}

void TrackNode::set_views(int views)
{
    this->views = views;
}

string TrackNode::get_name()
{
    return this->name;
}

string TrackNode::get_artist_name()
{
    return this->artist_name;
}

string TrackNode::get_kwd()
{
    return this->kwd;
}

void TrackNode::set_kwd(string kwd){
    this->kwd = kwd;
}

int TrackNode::get_views()
{
    return this->views;
}

TrackNode* TrackNode::get_next()
{
    return this->next;
}

TrackNode* TrackNode::get_prev()
{
    return this->prev;
}

TrackNode* TrackNode::step_node(bool isReverse)
{
    if (isReverse)
        return this->get_prev();
    else
        return this->get_next();
}

void TrackNode::set_next(TrackNode* node)
{
    this->next = node;
}

void TrackNode::set_prev(TrackNode* node)
{
    this->prev = node;
}

void TrackNode::get_node_info()
{
    cout << this->artist_name << " - " << this->name << endl;
    cout << "Views: " << this->views << ", Keyword: " << this->kwd << endl;
    cout << "URL: " << this->url << endl;
}

KwdNode::KwdNode(string kwd)
{
    this->kwd=kwd;
    this->count=0;

}

KwdNode::~KwdNode()
{
    if(this->next != NULL)
        delete this->next;
}

string KwdNode::get_keyword()
{
    return this->kwd;
}

void KwdNode::set_keyword(string kwd)
{
    this->kwd = kwd;
}

KwdNode* KwdNode::get_next()
{
    return this->next;
}

void KwdNode::set_next(KwdNode* node)
{
    this->next = node;
}

int KwdNode::get_count()
{
    return this->count;
}

void KwdNode::update_count(int count)
{
    this->count += count;
}