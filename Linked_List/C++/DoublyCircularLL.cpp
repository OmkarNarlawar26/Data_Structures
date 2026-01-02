#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;                  //  #
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyCL
{
    public:
        PNODE first;
        PNODE last;
        int iCount;

        DoublyCL()
        {
            cout<<"Object of DoublyCL gets created.\n";
            this->first = NULL;
            this->last = NULL;          //  #            
            this->iCount = 0;
        }

        void InsertFirst(int no)        
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;                      //  #

            if((first == NULL) && (last == NULL))
            {
                this->first = newn;
                this->last = newn;                  //  #
            }
            else
            {
                newn->next = this->first;
                this->first->prev = newn;           //  #
                this->first = newn;
            }

            this->last->next = this->first;         //  #
            this->first->prev = this->last;         //  #
    
            this->iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if((first == NULL) && (last == NULL))              // or if(this->first == NULL)
            {
                this->first = newn;
                this->last = newn;                             //  #

            }
            else
            {
                this->last->next = newn;                       //  #
                newn->prev = this->last;                       //  #
                this->last = newn;
            }
            this->last->next = this->first;
            this->first->prev = this->last;                    //  #

            this->iCount++;
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if((this->first == NULL) && (this->last == NULL))
            {
                return;
            }
            else if(this->first == this->last)        // else if(this->iCount == 0)
            {
                delete this->first;
                this->first = NULL;
                this->last = NULL;
            }
            else
            {
                temp = this->first;
                
                this->first = this->first->next;
                first->prev = this->last;                         //  #
                this->last->next = this->first;
                
                delete temp;
            }

            this->iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if((this->first == NULL) && (this->last == NULL))
            {
                return;
            }
            else if(this->first == this->last)        // else if(this->iCount == NULL)
            {
                delete this->first;
                this->first = NULL;
                this->last = NULL;
            }
            else
            {

                temp = this->last;

                this->last = this->last->prev;                      //  #
                this->last->next = this->first;
                this->first->prev = this->last;
                
                delete temp;
            }
            
            this->iCount--;
        }

        void Display()
        {
            PNODE temp = NULL;

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

        int Count()
        {
            return this->iCount;
        }

        void InsertAtPos(int no, int pos)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;
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
                newn = new NODE;

                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                temp = this->first;

                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                newn->next->prev = newn;                //  #

                temp->next = newn;
                newn->prev = temp;                      //  #

                this->last->next = this->first;         //  #
                this->first->prev = this->last;         //  #

                this->iCount++;
            }
        }

        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL;
            PNODE target = NULL;

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
                target->next->prev = temp;              //  #

                delete target;

                this->iCount--;
            } 
        }
};

int main()
{
    DoublyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertAtPos(105,4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    return 0;
}