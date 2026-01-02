class node
{
    public int data;
    public node next;
    public node prev;               // @

    // Important
    public node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;          // @
    }
}

class DoublyCL
{
    public node first;
    public node last;
    public int iCount;

    public DoublyCL()
    {
        System.out.println("Object of DoublyCL gets created");
        this.first = null;
        this.last = null;               //  #
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        // Changed code
        newn = new node(no);

        if((this.first == null) && (this.last == null))
        {
            this.first = newn;
            this.last = newn;                   // #
        }

        else
        {
            newn.next = this.first;
            this.first.prev = newn;             // @
            this.first = newn;
        }

        this.last.next = this.first;            //  #
        this.first.prev = this.last;            //  #

        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;
        node temp = null;

        // Changed code
        newn = new node(no);

        if((first == null) && (last == null))                 // if(iCount == 0)
        {
            this.first = newn;
            this.last = newn;                   // #
        }
        else
        {
            this.last.next = newn;              // #
            newn.prev = this.last;              // #
            this.last = newn;
        }

        this.last.next = this.first;
        this.first.prev = this.last;            // #

        this.iCount++;
    }

    public void DeleteFirst()
    {
        node temp = null;

        if((this.first == null) && (this.last == null))
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            temp = this.first;

            this.first = this.first.next;
            this.first.prev = this.last;                 // @
            this.last.next = this.first;
        }

        System.gc();
        this.iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;

        if((this.first == null) && (this.last == null))
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            temp = this.last;

           this.last = this.last.prev;
           this.last.next = this.first;
           this.first.prev = this.last;
        }

        System.gc();
        this.iCount--;
    }

    public void Display()
    {
        node temp = null;

        temp = this.first;

       if(this.first == null)
       {
            System.out.println("List is empty");
            return;
       }

       System.out.print(" <=> ");

       do
       {
        System.out.print("| "+temp.data+" | <=> ");
        temp = temp.next;
       }while(temp != this.first);

       System.out.println();
    }

    public int Count()
    {
        return this.iCount;
    }

    public void InsertAtPos(int no, int pos)
    {
        node temp = null;
        node newn = null;
        int iCnt = 0;

        if(pos < 1 || pos > this.iCount+1)
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            this.InsertFirst(no);
        }
        else if(pos == this.iCount+1)
        {
            this.InsertLast(no);
        }
        else
        {
            newn = new node(no);

            temp = this.first;

            for(iCnt = 1; iCnt < pos-1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next.prev = newn;                          // @

            temp.next = newn;                               // @
            newn.prev = temp;                               // @

            this.last.next = this.first;                   // #
            this.first.prev = this.last;

            this.iCount++;
        }
    }

    public void DeleteAtPos(int pos)
    {
        node temp = null;
        node target = null;

        int iCnt = 0;

        if(pos < 1 || pos > this.iCount)
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            this.DeleteFirst();
        }
        else if(pos == this.iCount)
        {
            this.DeleteLast();
        }
        else
        {
            temp = this.first;

            for(iCnt = 1; iCnt < pos-1; iCnt++)
            {
                temp = temp.next;
            }

            target = temp.next;

            temp.next = target.next;
            temp.next.prev = temp;                              // @
            
            System.gc();
            this.iCount--;
        }
    }
}

class DoublyCircularLL
{
    public static void main(String A[])
    {
        int iRet = 0;

        DoublyCL obj = null;

        obj = new DoublyCL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteFirst();

        obj.Display();

        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteLast();

        obj.Display();

        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);

        obj.InsertAtPos(105,4);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteAtPos(4);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);

        // Important for memory deallocation
        obj = null;
        System.gc();
    }
}