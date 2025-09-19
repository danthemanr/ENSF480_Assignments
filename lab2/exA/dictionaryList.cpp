/*
* File Name: dictionaryList.cpp
* Assignment: Lab 2, Exercise A
* Lab Section: B01
* Completed by: Daniel Rey, Aly Farouz
* Submission Date: Sept 22, 2025
*/

#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include "dictionaryList.h"
using namespace std;

Node::Node(const int& keyA, const Datum& datumA, Node *nextA)
: keyM(keyA), datumM(datumA), nextM(nextA)
{
}

DictionaryList::DictionaryList()
: sizeM(0), headM(0), cursorM(0)
{
}

int DictionaryList::size() const
{
    return sizeM;
}

int DictionaryList::cursor_ok() const
{
    return cursorM != 0;
}

const int& DictionaryList::cursor_key() const
{
    assert(cursor_ok());
    return cursorM->keyM;
}

Datum& DictionaryList::cursor_datum() const
{
    assert(cursor_ok());
    return cursorM->datumM;
}

void DictionaryList::insert(const int& keyA, const string& datumA)
{
    // Add new node at head?
    if (headM == 0 || keyA < headM->keyM) {
        headM = new Node(keyA, datumA, headM);
        sizeM++;
    }
    
    // Overwrite datum at head?
    else if (keyA == headM->keyM)
        headM->datumM = datumA;
    
    // Have to search ...
    else {
        
        //POINT ONE
        
        // if key is found in list, just overwrite data;
        for (Node *p = headM; p !=0; p = p->nextM)
        {
            if(keyA == p->keyM)
            {
                p->datumM = datumA;
                return;
            }
        }
        
        //OK, find place to insert new node ...
        Node *p = headM ->nextM;
        Node *prev = headM;
        
        while(p !=0 && keyA >p->keyM)
        {
            prev = p;
            p = p->nextM;
        }
        
        prev->nextM = new Node(keyA, datumA, p);
        sizeM++;
    }
    cursorM = NULL;
    
}

void DictionaryList::remove(const int& keyA)
{
    if (headM == 0 || keyA < headM -> keyM)
        return;
    
    Node *doomed_node = 0;
    
    if (keyA == headM-> keyM) {
        doomed_node = headM;
        headM = headM->nextM;
        
        // POINT TWO
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->nextM;
        while(maybe_doomed != 0 && keyA > maybe_doomed-> keyM) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->nextM;
        }
        
        if (maybe_doomed != 0 && maybe_doomed->keyM == keyA) {
            doomed_node = maybe_doomed;
            before->nextM = maybe_doomed->nextM;
        }
        
        
    }
    if(doomed_node == cursorM)
        cursorM = 0;
    
    delete doomed_node;           // Does nothing if doomed_node == 0.
    sizeM--;
}

void DictionaryList::go_to_first()
{
    cursorM = headM;
}

void DictionaryList::step_fwd()
{
    assert(cursor_ok());
    cursorM = cursorM->nextM;
}

// The following functions are supposed to be completed by the stuents, as part
// of the exercise B. the given code for this fucntion are just place-holders
// in order to allow successful linking when you're esting insert and remove.
// Replace them with the definitions that work.

DictionaryList::DictionaryList(const DictionaryList& source)
  : sizeM(source.sizeM), headM(0), cursorM(source.cursorM)
{
  if (sizeM!=0)
  {
    Node *c = source.headM;
    Node *p, *prev = headM = new Node(c->keyM, c->datumM, NULL);
    for(c = c->nextM; c!=NULL; c = c->nextM)
    {
      p = new Node(c->keyM, c->datumM, NULL);
      prev = prev->nextM = p;
    }
  }
}

DictionaryList& DictionaryList::operator =(const DictionaryList& rhs)
{
  if (this != &rhs) {
    if (sizeM>=rhs.sizeM)
    {
      if (headM!=NULL)
      {
        Node *c, *p = headM;
        for(c=rhs.headM; c!=NULL; p=p->nextM)
        {
          p->keyM = c->keyM;
          p->datumM = c->datumM;
          c = c->nextM;
        }
        Node *next = p->nextM;
        p->nextM = NULL;
        while(next!=NULL)
        {
          p = next;
          next = next->nextM;
          delete p;
        }
      }
    }
    else
    {
      Node *prev, *p, *c = rhs.headM;
      if (headM==NULL)
      {
        prev = headM = new Node(c->keyM, c->datumM, NULL);
        c = c->nextM;
      }
      else
      {
        for(p=headM; p!=NULL; p=p->nextM)
        {
          p->keyM = c->keyM;
          p->datumM = c->datumM;
          c = c->nextM;
          prev = p;
        }
      }
      while(c!=NULL)
      {
        p = new Node(c->keyM, c->datumM, NULL);
        prev = prev->nextM = p;
        c = c->nextM;
      }
    }
    cursorM = rhs.cursorM;
    sizeM = rhs.sizeM;
  }
  return *this;
}

DictionaryList::~DictionaryList()
{
  for(Node *prev, *p=headM; p!=NULL;)
  {
    prev = p;
    p = p->nextM;
    delete prev;
  }
}

void DictionaryList::find(const int& keyA)
{
    for (Node *p = headM; p != 0; p=p->nextM)
        if (keyA == p->keyM)
        {
            cout << "'" << keyA <<"' was found with datum value " << p->datumM.c_str() << ".\n";
            cursorM = p;
            return;
        }
    cout << "'" << keyA <<"' was not found.\n";
    cursorM = 0;
}

void DictionaryList::make_empty()
{
  for(Node *prev, *p=headM; p!=NULL;)
  {
    prev = p;
    p = p->nextM;
    delete prev;
  }
  cursorM = headM = 0;
  sizeM = 0;
}

ostream& operator << (ostream& os, DictionaryList& dl)
{
    os << dl.cursor_datum();
    return os;
}
bool DictionaryList::operator !=(const DictionaryList& rhs)
{
   return !(this->cursor_datum() == rhs.cursor_datum());
}
bool DictionaryList::operator >(const DictionaryList& rhs)
{
   return this->cursor_datum() > rhs.cursor_datum();
}
bool DictionaryList::operator <(const DictionaryList& rhs)
{
   return this->cursor_datum() < rhs.cursor_datum();
}
bool DictionaryList::operator <=(const DictionaryList& rhs)
{
   return !(this->cursor_datum() > rhs.cursor_datum());
}
bool DictionaryList::operator >=(const DictionaryList& rhs)
{
   return !(this->cursor_datum() < rhs.cursor_datum());
}
//above few functions were implemented by Farouz
Datum DictionaryList::operator[](int i)const{ //will cause an error if i >= sizeM
    Node* p=headM;
    while(i>0){
        p=p->nextM;
        i--;
    }
    return p->datumM;
}



