// binary breakdown
// 1 ~ 100 사이에 상대방이 생각한 숫자를 맞춰야 된다면 ??
// => 1, 2, 3... 으로 맞추지 말고
// => "50" 부터 해서 "up/down" 으로 해야 효율적입니다.
void bad()
{
    int i = 8;
	
	// 8 번의 비교
    if (i == 1) {}
    else if (i == 2) {}
    else if (i == 3) {}
    else if (i == 4) {}
    else if (i == 5) {}
    else if (i == 6) {}
    else if (i == 7) {}
    else if (i == 8) {}
}

void good()
{
    int i = 0;

	// 성능은 유리 하지만, 가독성은???
	if ( i <= 4 )
	{
		if ( i <= 2)
		{
			if ( i == 1 )
			{

			}
			else 
			{

			}
		}
		else 
		{
			// 생략!!!
		}
	}
	else 
	{

	}
}

int main()
{
    bad();
    good();
}
