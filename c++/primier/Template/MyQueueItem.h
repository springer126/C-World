#ifndef MyQueueItem_H
#define MyQueueItem_H

template <typename Type>
class  MyQueueItem
{
public:
	MyQueueItem(const Type &t):item(t),next(0){}
	Type item;
	MyQueueItem *next;
};

#endif
