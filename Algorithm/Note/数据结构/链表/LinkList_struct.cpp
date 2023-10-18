#include<bits/stdc++.h>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

//初始化
void InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LinkList));
    L->next = NULL;
}

//遍历操作
void PrintList(LinkList L){
    LNode *p = L->next;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

//求单链表的长度
int Length(LinkList L){
    LNode *p = L->next;
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

//头插法建立单链表
LinkList HeadInsert(LinkList &L){
    InitList(L); //初始化
    int x;
    cin>>x;
    while(x!=9999){
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        cin>>x;
    }
    return L;
}

//尾插法建立单链表
LinkList TailInsert(LinkList &L){
    InitList(L);
    LNode *s,*r=L;
    int x;
    cin>>x;
    while(x!=9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        cin>>x;
    }
    r->next = NULL;
    return L;
}

//按值查找：查找x在L中的位置
LNode *LocateElem(LinkList L, int x){
    LNode *p = L->next;
    while(p && p->data != x){
        p = p->next;
    }
    return p;
}

//按位查找：查找在单链表L中第i个位置的结点
LNode *GetElem(LinkList L, int i){
    int j=1;
    LNode *p = L->next;
    if(i==0)return L;
    if(i<1)return NULL;
    while(p && j<i){
        p = p->next;
        j++;
    }
    return p; //如果i大于表长，p=NULL,直接返回p即可
}

//将x插入到单链表L的第i个位置上
void Insert(LinkList &L, int i, int x){
    LNode *p = GetElem(L,i-1);
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = p->next;
    p->next = s;
}

//删除操作:将单链表中的第i个结点删除
void Delete(LinkList &L, int i){
    if(i<1 || i>Length(L)){
        cout<<"delete failed: index is wrong."<<endl;
        return;
    }
    LNode *p = GetElem(L,i-1);
    LNode *q = p->next;
    p->next = q->next;
    free(q);
}


int main(){
    //初始化，尾插法建立单链表
    LinkList L = TailInsert(L);
    //插入：在第二个位置插入结点，数据域为888，并遍历单链表
    Insert(L,2,888);
    cout<<"在第二个位置插入888： ";
    PrintList(L);
    //删除：删除第四个结点
    Delete(L,4);
    cout<<"删除第四个结点后：";
    PrintList(L);
    //按位查找：查找第三个结点，并输出其数据域的值
    LNode *p = GetElem(L,3);
    cout<<"第三个结点的值为："<<p->data<<endl;
    //按值查找：查找数据域为2的结点的指针
    LNode *q = LocateElem(L,2);
    cout<<"数据为2的结点的下一个结点的值为："<<q->next->data<<endl;
    //输出单链表的长度
    cout<<"单链表的长度："<<Length(L)<<endl;
    return 0;
}
