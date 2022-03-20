#pragma once

 template<typename type=int>
class stack
{
    struct node
    {
        type value;
        node*prev;
    };
    node*self=0;
public:
    void push(const type i)
    {
        self=new node{i,self};
    }

    const type pop()
    {
        if(!self)return 0;
        node*p=self->prev;
        const type v=self->value;
        delete self;
        self=p;
        return v;
    }

    inline void operator+(const type i)
    {push(i);}

    inline const type operator+()
    {pop();}
};