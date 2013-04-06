
template <class T>
int compare(const T &t1,const T &t2)
{
	if(t1<t2)
	{
		return -1;
	}
	else if(t1>t2)
		return 1;
	else
		return 0;
}


