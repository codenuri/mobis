// if-else if 보다 switch 가 더 잘 최적화 된다.
// godbolt.org 의 왼쪽에 넣어 보세요
void bad()
{
	int k = 0;
    int i = 8;

    if (i == 1)      { k = 10;}
    else if (i == 2) { k = 20;}
    else if (i == 3) { k = 30;}
    else if (i == 4) { k = 40;}
    else if (i == 5) { k = 50;}
    else if (i == 6) { k = 60;}
    else if (i == 7) { k = 70;}
    else if (i == 8) { k = 80;}
}

void good()
{
    int k = 0;
    int i = 8;
    switch (i)
    {
    case 1: k = 10;break;
    case 2: k = 20;break;
    case 3: k = 30;break;
    case 4: k = 40;break;
    case 5: k = 50;break;
    case 6: k = 60;break;
    case 7: k = 70;break;
    case 8: k = 80;break;
    }
}

int main()
{
    bad();
    good();
}
