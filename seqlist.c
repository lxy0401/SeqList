#include<stdio.h>
#include "seqlist.h"
#include<stdint.h>
//初始化顺序表
void SeqListInit(SeqList *seqlist)
{
    if(seqlist == NULL)
	{
	    return ;
	}
    seqlist->size=0;
}

//尾插
void SeqListPushBack(SeqList *seqlist,SeqListType value)
{
    if(seqlist == NULL)
    {
	//非法输入
	return ;
    }
    if(seqlist->size>=SeqListMaxSize)
    {
	//顺序表满了
	return ;
    }
    seqlist->data[seqlist->size]=value;
    ++seqlist->size;
    return ;
}

//尾删
void SeqListPopBack(SeqList *seqlist)
{
    if(seqlist == NULL)
    {
	//非法输入
	return ;
    }
    if(seqlist->size==0)
    {
	//空顺序表
	return ;
    }
    --seqlist->size;
    return ;
}

//头插
void SeqListPushFront(SeqList *seqlist,SeqListType value)
{
    if(seqlist == NULL)
    {
	//非法输入
	return ;
    }
    if(seqlist->size>=SeqListMaxSize)
    {
	//顺序表满了
	return ;
    }
    ++seqlist->size;
    size_t i=seqlist->size-1;
    for(;i>0;--i)
    {
	seqlist->data[i]=seqlist->data[i-1];
    }
    seqlist->data[0]=value;
    return ;
}

//头删
void SeqListPopFront(SeqList *seqlist)
{
    if(seqlist == NULL)
    {
        //非法输入
        return ;
    }
    if(seqlist->size==0)
    {
	//空顺序表
	return ;
    }
    size_t i=0;
    for(;i<seqlist->size-1;++i)
    {
	seqlist->data[i]=seqlist->data[i+1];
    }
    --seqlist->size;
    return ;
}

//读取pos位置的元素
void SeqListGetValue(SeqList *seqlist,size_t pos)
{
    if(seqlist == NULL)
    {
	//非法输入
	return ;
    }
    if(pos>seqlist->size)
    {
	//越界查找
	return ;
    }
    printf("查找位置的元素为%c\n",seqlist->data[pos]);
    return ;
}

//获取指定元素的下标
size_t SeqListFind(SeqList *seqlist,SeqListType to_find)
{
    size_t i=0;
    for(;i<seqlist->size;i++)
    {
	if(seqlist->data[i]==to_find)
	{
	    //找到了
	    return i;
	}
    }
    return -1;
//    if(seqlist == NULL)
//    {
//	//非法输入
//	return ;
//    }
//    size_t i=0;
//    for(;i<SeqListMaxSize;++i)
//    {
//	if(seqlist->data[i]==value)
//	{
//	    printf("查找元素的下标为%d\n",i);
//	}
//    }
//    return ;
}

//修改pos位置的元素
void SeqListSetValue(SeqList *seqlist,size_t pos,SeqListType value)
{
    if(seqlist == NULL)
    {
	//非法输入
	return ;
    }
    if(pos>seqlist->size)
    {
	//越界访问
	return ;
    }
    seqlist->data[pos]=value;
    return ;
}

//在任意位置插入元素
void SeqListInsert(SeqList *seqlist,size_t pos,SeqListType value)
{
    if(seqlist == NULL)
    {
	//非法输入
	return ;
    }
    if(pos>seqlist->size)
    {
	//越界访问
	return ;
    }
    if(seqlist->size>=SeqListMaxSize)
    {
	//顺序表满了
	return ;
    }
    if(pos==0)
    {
	SeqListPushFront(seqlist,value);
	return ;
    }
    ++seqlist->size;
    size_t i=seqlist->size-1;
    for(;i-1>=pos;--i)
    {
	seqlist->data[i]=seqlist->data[i-1];
    }
    seqlist->data[pos]=value;
}

//删除指定位置的元素
void SeqListErase(SeqList *seqlist,size_t pos)
{
    if(seqlist == NULL)
    {
	//非法输入
	return ;
    }
    if(seqlist->size == 0)
    {
	//空顺序表
	return ;
    }
    if(pos>=seqlist->size)
    {
	//越界访问
	return ;
    }
    size_t i=pos;
    for(;i<seqlist->size-1;++i)
    {
	seqlist->data[i]=seqlist->data[i+1];
    }
    --seqlist->size;
    return ;
}

//11.查找指定位置pos的值
int SeqListGet(SeqList *seqlist,size_t pos,SeqListType *value)
{
    if(seqlist ==NULL)
    {
	//非法输入
	return 0;
    }
    if(pos>=seqlist->size)
    {
	//越界访问
	return 0;
    }
    *value=seqlist->data[pos];
    return 1;
}

//12.删除具体值(只删除一个)
void SeqListRemove(SeqList *seqlist,SeqListType to_move)
{
    if(seqlist ==NULL)
    {
	//非法输入
	return ;
    }
    size_t pos =SeqListFind(seqlist,to_move);
    if(pos==(size_t)-1)
    {
	return ;
    }
    SeqListErase(seqlist,pos);
    return ;
}

//13.删除所有的to_remove值
void SeqListRemoveall(SeqList *seqlist,SeqListType to_remove)
{
    if(seqlist == NULL)
    {
	//非法输入
	return ;
    }
    while(1)
    {
	size_t pos=SeqListFind(seqlist,to_remove);
	if(pos==(size_t)-1)
	{
	    break;
	}
	SeqListErase(seqlist,pos);
    }
}


void Swap(SeqListType *a,SeqListType *b)
{
    SeqListType tmp=*a;
    *a=*b;
    *b=tmp;
}

//14.冒泡排序(升序)
void SeqListBubbleSort(SeqList *seqlist)
{
    if(seqlist == NULL)
    {
	//非法输入
	return ;
    }
    //count为冒泡的次数
    size_t count =0;
    for(;count<seqlist->size;++count)
    {
	size_t cur =0;
	for(;cur<seqlist->size-count-1;++cur)
	{
	    if(seqlist->data[cur]>seqlist->data[cur+1])
	    {
		Swap(&seqlist->data[cur],&seqlist->data[cur+1]);
	    }
	}
    }
    return ;
}


//15.冒泡排序(降序)
void SeqListBubbleDesc(SeqList *seqlist)
{
    if(seqlist == NULL)
    {
	//非法输入
	return ;
    }
    //count为冒泡的次数
    size_t count =0;
    for(;count<seqlist->size;++count)
    {
	size_t cur =0;
	for(;cur<seqlist->size-count-1;++cur)
	{
	    if(seqlist->data[cur]<seqlist->data[cur+1])
	    {
		Swap(&seqlist->data[cur],&seqlist->data[cur+1]);
	    }
	}
    }
    return ;
}


//15.冒泡排序(通用版)
typedef int(*cmp)(SeqListType a,SeqListType b);
void SeqListBubbleSortEx(SeqList *seqlist,cmp cmp)
{
    if(seqlist == NULL)
    {
	//非法输入
	return ;
    }
    //count为冒泡的次数
    size_t count =0;
    for(;count<seqlist->size;++count)
    {
	size_t cur =0;
	for(;cur<seqlist->size-count-1;++cur)
	{
	    if(cmp(seqlist->data[cur],seqlist->data[cur+1]))
	    {
		Swap(&seqlist->data[cur],&seqlist->data[cur+1]);
	    }
	}
    }
    return ;
}

//选择排序
void SeqListSelectSort(SeqList *seqlist)
{
    if(seqlist == NULL)
    {
	//非法输入
	return ;
    }
    if(seqlist->size<=1)
    {
	//不需要排序
	return ;
    }
    //[0,bound)表示有序区间[bound,size)表示待排序区间
    size_t bound=0;
    for(;bound<seqlist->size-1;++bound)
    {
	size_t cur=bound+1;
	for(;cur<seqlist->size;++cur)
	{
	    if(seqlist->data[cur]<seqlist->data[bound])
	    {
		Swap(&seqlist->data[cur],&seqlist->data[bound]);
	    }
	}
    }
    return ;
}



//以下为测试代码
#include<stdio.h>
#define TEST_HEADER printf("\n========%s===========\n",__FUNCTION__)

void SeqListPrintChar(SeqList *seqlist,const char *msg)
{
    if(seqlist == NULL)
    {
	printf("非法输入\n");
	return ;
    }
    printf("[%s]\n",msg);
    size_t i=0;
    for(;i<seqlist->size;++i)
    {
	printf("[%c]",seqlist->data[i]);
    }
    printf("\n");
}
void TestInit()
{
    TEST_HEADER;
    SeqList seqlist;
    SeqListInit(&seqlist);
    printf("seqlist.size expect 0,actual %lu\n",seqlist.size);
}

void TestPushBack()
{
    TEST_HEADER;
    SeqList seqlist;
    SeqListInit(&seqlist);
    SeqListPushBack(&seqlist,'a');
    SeqListPushBack(&seqlist,'b');
    SeqListPushBack(&seqlist,'c');
    SeqListPushBack(&seqlist,'d');
    SeqListPrintChar(&seqlist,"尾部插入四个元素");
}
void TestPopBack()
{
    TEST_HEADER;
    SeqList seqlist;
    SeqListInit(&seqlist);
    SeqListPopBack(&seqlist);
    SeqListPushBack(&seqlist,'a');
    SeqListPushBack(&seqlist,'b');
    SeqListPushBack(&seqlist,'c');
    SeqListPushBack(&seqlist,'d');
    SeqListPrintChar(&seqlist,"对顺序表进行尾删");
    SeqListPopBack(&seqlist);
    SeqListPopBack(&seqlist);
    SeqListPrintChar(&seqlist,"尾部删除两个元素");
}

void TestPushFront()
{
    TEST_HEADER;
    SeqList seqlist;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist,'a');
    SeqListPushFront(&seqlist,'b');
    SeqListPushFront(&seqlist,'c');
    SeqListPushFront(&seqlist,'d');
    SeqListPrintChar(&seqlist,"头部插入四个元素");
}

void TestPopFront()
{
    
    TEST_HEADER;
    SeqList seqlist;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist,'a');
    SeqListPushFront(&seqlist,'b');
    SeqListPushFront(&seqlist,'c');
    SeqListPushFront(&seqlist,'d');
    SeqListPrintChar(&seqlist,"对顺序表进行尾删");
    SeqListPopFront(&seqlist);
    SeqListPopFront(&seqlist);
    SeqListPrintChar(&seqlist,"头部删除两个元素");
}

void TestGetValue()
{ 
    TEST_HEADER;
    SeqList seqlist;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist,'a');
    SeqListPushFront(&seqlist,'b');
    SeqListPushFront(&seqlist,'c');
    SeqListPushFront(&seqlist,'d');
    SeqListPrintChar(&seqlist,"查找pose位置的元素");
    SeqListGetValue(&seqlist,3);
}

void TestFind()
{
    TEST_HEADER;
    SeqList seqlist;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist,'a');
    SeqListPushFront(&seqlist,'b');
    SeqListPushFront(&seqlist,'c');
    SeqListPushFront(&seqlist,'d');
    size_t pos = SeqListFind(&seqlist,'c');
    printf("pos expect 1,actual %ld\n",(int64_t)pos);
    pos = SeqListFind(&seqlist,'x');
    printf("pos expect -1,actual %ld\n",(int64_t)pos);


}

void TestSetValue()
{
    TEST_HEADER;
    SeqList seqlist;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist,'a');
    SeqListPushFront(&seqlist,'b');
    SeqListPushFront(&seqlist,'c');
    SeqListPushFront(&seqlist,'d');
    SeqListPrintChar(&seqlist,"修改指定位置的元素");
    SeqListSetValue(&seqlist,3,'Y');
    SeqListPrintChar(&seqlist,"修改后为");
}

void TestInsert()
{
    TEST_HEADER;
    SeqList seqlist;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist,'a');
    SeqListPushFront(&seqlist,'b');
    SeqListPushFront(&seqlist,'c');
    SeqListPushFront(&seqlist,'d');
    SeqListPrintChar(&seqlist,"在任意位置插入元素");
    SeqListInsert(&seqlist,3,'Y');
    SeqListPrintChar(&seqlist,"插入后后为");
}

void TestErase()
{
    TEST_HEADER;
    SeqList seqlist;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist,'a');
    SeqListPushFront(&seqlist,'b');
    SeqListPushFront(&seqlist,'c');
    SeqListPushFront(&seqlist,'d');
    SeqListPrintChar(&seqlist,"删除指定位置的元素");
    SeqListErase(&seqlist,3);
    SeqListPrintChar(&seqlist,"删除后为");
    
}

void TestGet()
{
    TEST_HEADER;
    SeqList seqlist;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist,'a');
    SeqListPushFront(&seqlist,'b');
    SeqListPushFront(&seqlist,'c');
    SeqListPushFront(&seqlist,'d');
    SeqListType value;
    int ret=SeqListGet(&seqlist,0,&value);
    printf("value expect d,actual %c\n",value);
    printf("ret expect 1,actual %d\n",ret);
} 

void TestRemove()
{
    TEST_HEADER;
    SeqList seqlist;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist,'a');
    SeqListPushFront(&seqlist,'b');
    SeqListPushFront(&seqlist,'c');
    SeqListPushFront(&seqlist,'d');
    SeqListPrintChar(&seqlist,"删除指定的值");
    SeqListRemove(&seqlist,'a');
    SeqListPrintChar(&seqlist,"删除后为");
 
}

void TestRemoveall()
{
    TEST_HEADER;
    SeqList seqlist;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist,'a');
    SeqListPushFront(&seqlist,'b');
    SeqListPushFront(&seqlist,'a');
    SeqListPushFront(&seqlist,'c');
    SeqListPushFront(&seqlist,'a');
    SeqListPushFront(&seqlist,'d');
    SeqListPrintChar(&seqlist,"删除所有指定的值");
    SeqListRemoveall(&seqlist,'a');
    SeqListPrintChar(&seqlist,"删除后为");
 
}

void TestBubbleSort()
{
    TEST_HEADER;
    SeqList seqlist;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist,'a');
    SeqListPushFront(&seqlist,'b');
    SeqListPushFront(&seqlist,'e');
    SeqListPushFront(&seqlist,'c');
    SeqListPushFront(&seqlist,'m');
    SeqListPushFront(&seqlist,'d');
    SeqListBubbleSort(&seqlist);
    SeqListPrintChar(&seqlist,"冒泡排序");
 
}

void TestBubbleDesc()
{
    TEST_HEADER;
    SeqList seqlist;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist,'a');
    SeqListPushFront(&seqlist,'b');
    SeqListPushFront(&seqlist,'e');
    SeqListPushFront(&seqlist,'c');
    SeqListPushFront(&seqlist,'m');
    SeqListPushFront(&seqlist,'d');
    SeqListBubbleDesc(&seqlist);
    SeqListPrintChar(&seqlist,"冒泡排序");
 
}

int Greater(SeqListType a,SeqListType b)
{
    return a>b?1:0;
}

int Less(SeqListType a,SeqListType b)
{
    return a<b?1:0;
}

//struct Student
//{
//    char *name;
//    int score;
//};

//int StudentGreater(Student a,Student b)
//{
//    return a.score>b.score?1:0;
//}

void TestBubbleSortEx()
{
   TEST_HEADER;
   SeqList seqlist;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist,'a');
    SeqListPushFront(&seqlist,'b');
    SeqListPushFront(&seqlist,'e');
    SeqListPushFront(&seqlist,'c');
    SeqListPushFront(&seqlist,'m');
    SeqListPushFront(&seqlist,'d');
    SeqListBubbleSortEx(&seqlist,Greater);
    SeqListPrintChar(&seqlist,"升序冒泡排序");
}

void TestSelect()
{
    TEST_HEADER;
    SeqList seqlist;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist,'a');
    SeqListPushFront(&seqlist,'b');
    SeqListPushFront(&seqlist,'e');
    SeqListPushFront(&seqlist,'c');
    SeqListPushFront(&seqlist,'m');
    SeqListPushFront(&seqlist,'d');
    SeqListSelectSort(&seqlist); 
    SeqListPrintChar(&seqlist,"选择排序");
}

int main()
{
    TestInit();
    TestPushBack();
    TestPopBack();
    TestPushFront();
    TestPopFront();
    TestGetValue();
    TestFind();
    TestSetValue();
    TestInsert();
    TestErase();
    TestGet();
    TestRemove();
    TestRemoveall();
    TestBubbleSort();
    TestBubbleDesc();
    TestBubbleSortEx();
    TestSelect();
    return 0;
}
