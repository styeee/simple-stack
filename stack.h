#pragma once

 template<typename type=int>
class stack
{
    struct node
    {
        type value;
        node*prev;
    };
protected:
    node*self;
    size_t count=0;
public:
    stack(const stack&s):self(s.self),count(s.count){}
    stack(){}

    ~stack()
    {while(self)pop();}

    stack&push(const type i)
    {
        self=new node{i,self};
        count++;
        return*this;
    }

    const type pop()
    {
        if(!count)return 0;
        node*p=self->prev;
        const type v=self->value;
        delete self;
        self=p;
        count--;
        return v;
    }

    inline stack&operator+(const type i)
    {return push(i);}

    inline const type operator+()
    {return pop();}

    operator type*()
    {
        type*p=new type[count];
        while(count)p[count]=pop();
        return p;
    }

    inline const size_t size()const
    {return count;}

    inline operator size_t()const
    {return count;}
};
