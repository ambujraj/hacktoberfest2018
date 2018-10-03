
int count(NODE *p)
{
        	if(p==NULL)
                                                            	return 0;
        	return 1+count(p->next);
}
