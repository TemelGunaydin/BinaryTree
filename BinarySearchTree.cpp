
#include <iostream>
using namespace std;

class Node
{
public:
 Node *lchild;
 int data;
 Node *rchild;
 Node *root;
 Node()
 {
   root=NULL;
 }
void Insert(int key);
void Inorder(Node *p);
Node * Search(int key);
Node *RInsert(Node *p,int key);
int Height( Node *p);
Node *InPre( Node *p);
Node *Delete( Node *p,int key);
Node *InSucc( Node *p);

};

Node *Node::RInsert(Node *p,int key)
{
  Node *t = NULL;
  if(p == NULL)
  {
    t = new Node;
    t->data = key;
    t->lchild = t->rchild = NULL;
    return t;
  }
  else if(key < p->data)
  {
    p->lchild = RInsert(p->lchild,key);
  }
  else if(key > p->data)
  {
    p->rchild = RInsert(p->rchild,key);
  }
return p;
}


void Node::Insert(int key)
{
  Node *t=root;
  Node *r=NULL,*p;

 if(root==NULL)
 {
 p=new Node;
 p->data=key;
 p->lchild=p->rchild=NULL;
 root=p;
 return;
 }
 while(t!=NULL)
 {
 r=t;
 if(key<t->data)
 t=t->lchild;
 else if(key>t->data)
 t=t->rchild;
 else
 return;
 }
 p=new Node;
 p->data=key;
 p->lchild=p->rchild=NULL;

 if(key<r->data) r->lchild=p;
 else r->rchild=p;
}
void Node::Inorder( Node *p)
{
 if(p)
 {
 Inorder(p->lchild);
 cout<<" "<<p->data;
 Inorder(p->rchild);
 }
}
 Node *Node::Search(int key)
{
  Node *t=root;

 while(t!=NULL)
 {
 if(key==t->data)
 return t;
 else if(key<t->data)
 t=t->lchild;
 else
 t=t->rchild;
 }
 return NULL;
}
int Node::Height( Node *p)
{
 int x,y;
 if(p==NULL)return 0;
 x=Height(p->lchild);
 y=Height(p->rchild);
 return x>y?x+1:y+1;
}

 Node *Node::InPre( Node *p)
{
 while(p && p->rchild!=NULL)
 p=p->rchild;

 return p;
}
 Node *Node::InSucc( Node *p)
{
 while(p && p->lchild!=NULL)
 p=p->lchild;

 return p;
}

 Node *Node::Delete( Node *p,int key)
{
  Node *q;

 if(p==NULL)
 return NULL;
 if(p->lchild==NULL && p->rchild==NULL)
 {
 if(p==root)
 root=NULL;

 delete p;
 return NULL;

 }

 if(key < p->data)
 p->lchild=Delete(p->lchild,key);
 else if(key > p->data)
 p->rchild=Delete(p->rchild,key);
 else
 {
 if(Height(p->lchild)>Height(p->rchild))
 {
 q=InPre(p->lchild);
 p->data=q->data;
 p->lchild=Delete(p->lchild,q->data);
 }
 else
 {
 q=InSucc(p->rchild);
 p->data=q->data;
 p->rchild=Delete(p->rchild,q->data);
 }

 }
 return p;
}
int main()
{
 Node *temp;
 Node t;

 t.root=t.RInsert(t.root,50);
 t.RInsert(t.root,10);
 t.RInsert(t.root,40);
 t.RInsert(t.root,20);
 t.RInsert(t.root,30);

 t.Delete(t.root,50);

 t.Inorder(t.root);
 cout<<endl;
 temp=t.Search(20);

 if(temp!=NULL)
 cout<<"element "<<temp->data<<" is found\n";
 else
 cout<<"element is not found\n";

 return 0;
}
