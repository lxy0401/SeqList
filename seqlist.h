#include<stdio.h>
#pragma once
#define SeqListMaxSize 100
typedef char SeqListType;

typedef struct SeqList
{
    SeqListType data[SeqListMaxSize];
    size_t size;
}SeqList;

//1.初始化顺序表
void SeqListInit(SeqList *seqlist);

//2.往顺序表尾部插入元素
void SeqListPushBack(SeqList *seqlist,SeqListType value);

//3.将顺序表尾部元素删除
void SeqListPopBack(SeqList *seqlist);

//4.往顺序表头部插入元素
void SeqListPushFront(SeqList *seqlist,SeqListType value);

//5.将顺序表头部元素删除
void SeqListPopFront(SeqList *seqlist);

//6.读取任意位置元素
void SeqListGetValue(SeqList *seqlist,size_t pos);

//7.修改任意位置元素
void SeqListSetValue(SeqList *seqlist,size_t pos,SeqListType value);

//获取指定元素的下标
size_t SeqListFind(SeqList *seqlist,SeqListType to_find);

//9.往pos位置插入元素
void SeqListInsert(SeqList *seqlist,size_t pos,SeqListType value);

//10.将pos位置元素删除
void SeqListErase(SeqList *seqlist,size_t pos);

//11.查找指定位置pos的值
int SeqListGet(SeqList *seqlist,size_t pos,SeqListType *value);

//12.删除具体值只(只删除一个)
void SeqListRemove(SeqList *seqlist,SeqListType to_move);

//13.删除所有的to_remove值
void SeqListRemoveall(SeqList *seqlist,SeqListType to_remove);

//14.冒泡排序(升序)
void SeqListBubbleSort(SeqList *seqlist);

//15.冒泡排序(降序)
void SeqListBubbleDesc(SeqList *seqlist);

//16.冒泡排序(通用版)
void SeqListBubbleSort(SeqList *seqlist);

//17.选择排序
void SeqListSelectSort(SeqList *seqlist);

