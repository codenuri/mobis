#include <stdio.h>
#include <stdlib.h>

typedef struct _bullet
{
	union
	{	
		struct 
		{
			int x;
			int y;
		}; 				
		struct _bullet* next;
	};

} bullet;


int main()
{

}
