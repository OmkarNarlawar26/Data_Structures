///////////////////////////////////////////////////////////////////////////////////////
//                                                                                   //
//                        GENERALISED DATA STRUCTURE LIBRARY                         //
//                                                                                   //
///////////////////////////////////////////////////////////////////////////////////////


/*
---------------------------------------------------------------------------------------
Type                    Name of class for node      Name of class for Functionality
---------------------------------------------------------------------------------------
Singly Linear            SinglyLLLnode               SinglyLLL          Done
Singly Cirular           SinglyCLLnode               SinglyCLL          Done
Doubly Linear            DoublyLLLnode               DoublyLLL          Done
Doubly Circular          DoublyCLLnode               DoublyCLL          Done
---------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//          Singly Linear LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyLLL
{
    private:        
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of SinglyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node of first position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete temp;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node of last position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)  
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Linked List
//  Description :       Used to print Linked List
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::Display()
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Integer
//  Description :       Used to count elements from Linked List
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> ::Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at given position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node from given position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////
//      Singly Circular LinkedList using Generic Approach
////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T> * next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> * first;
        SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

template<class T>
SinglyCLL<T> :: SinglyCLL()
{
    cout<<"Object of SinglyCLL gets created.\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }

    this->last->next = this->first;

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    SinglyCLLnode<T> * newn = NULL;
    SinglyCLLnode<T> * temp = NULL;

    newn = new SinglyCLLnode<T>(no);

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;

    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }
    this->last->next = this->first;

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Delete node from first position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: DeleteFirst()
{
    SinglyCLLnode<T> * temp = NULL;

    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        
        this->first = this->first-> next;
        delete temp;

        this->last->next = this->first;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Delete node from last position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: DeleteLast()
{
    SinglyCLLnode<T> * temp = NULL;

    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next != this->last)
        {
            temp = temp->next;
        }

        delete this->last;
        this->last = temp;

        this->last->next = this->first;
    }
    
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Linked List
//  Description :       Used to print Linked List
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: Display()
{
    SinglyCLLnode<T> * temp = NULL;

    temp = this->first;

    if(this->first == NULL)
    {
        cout<<"List is empty\n";
        return;
    }

    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }while(temp != this->first);

    cout<<"\n";
    
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Integer
//  Description :       Used to count elements from Linked list 
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T> :: Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at given position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * newn = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->last->next = this->first;

        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteatPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node from given position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    } 
}

///////////////////////////////////////////////////////////////////////////////
//          Doubly Linear LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked List gets created\n";

    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    
    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::InsertLast(T no) 
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;    
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at given position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;

    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }  

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node from first position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::DeleteFirst()
{
    if(this->first == NULL)                 // LL is empty
    {
        return;
    }
    else if(this->first->next == NULL)      // LL contains 1 node
    {
        delete this->first;
        this->first = NULL;
    }
    else                                    // LL contains more than 1 node
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node from last position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)                 // LL is empty
    {
        return;
    }
    else if(this->first->next == NULL)      // LL contains 1 node
    {
        delete this->first;
        this->first = NULL;
    }
    else                                    // LL contains more than 1 node
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;    
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node from given position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid position\n";
        return;
    }  

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }    
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Linked List
//  Description :       Used print Linked List
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::Display()
{
    DoublyLLLnode<T> *temp = NULL;
    
    temp = this->first;

    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Integer
//  Description :       Used to count elements from Linked List
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLLL<T> ::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////
//  Final code for Doubly Circular LinkedList using Generic Approach
////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode *next;
        DoublyCLLnode *prev;

        DoublyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T> * first;
        DoublyCLLnode<T> * last;
        int iCount;

    public:
        DoublyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

template<class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Object of DoublyCLL gets created.\n";
    this->first = NULL;
    this->last = NULL;            
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertFirst(T no)        
{
    DoublyCLLnode<T> * newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if((first == NULL) && (last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    DoublyCLLnode<T> * newn = NULL;
    DoublyCLLnode<T> * temp = NULL;

    newn = new DoublyCLLnode<T>(no);

    if((first == NULL) && (last == NULL))
    {
        this->first = newn;
        this->last = newn;

    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node from first position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteFirst()
{
    DoublyCLLnode<T> * temp = NULL;

    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        
        this->first = this->first->next;
        first->prev = this->last;
        this->last->next = this->first;
        
        delete temp;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node from last position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteLast()
{
    DoublyCLLnode<T> * temp = NULL;

    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {

        temp = this->last;

        this->last = this->last->prev;
        this->last->next = this->first;
        this->first->prev = this->last;
        
        delete temp;
    }
    
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Linked List
//  Description :       Used to print Linked List
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: Display()
{
    DoublyCLLnode<T> * temp = NULL;

    temp = this->first;

    if(this->first == NULL)
    {
        cout<<"List is empty\n";
        return;
    }

    cout<<" <=> ";

    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }while(temp != this->first);

    cout<<"\n";
    
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Integer
//  Description :       Used to count elements from Linked List
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T> :: Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at given position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyCLLnode<T> * temp = NULL;
    DoublyCLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->last->next = this->first;
        this->first->prev = this->last;

        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node from given position
//  Author :            Omkar Sachin Narlawar
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    DoublyCLLnode<T> * temp = NULL;
    DoublyCLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        target->next->prev = temp;

        delete target;

        this->iCount--;
    } 
}

//////////////////////////////// END OF LIBRARY //////////////////////////////////

int main()
{


    return 0;
}