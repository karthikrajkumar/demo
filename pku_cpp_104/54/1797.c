//********************************
//*????????   **
//*?????? 1300012957 **
//*???2013.12.10  **
//********************************
int n,k,m ;                       //n??????k???????m??????
int f(int num) ;
int main()
{
	cin >> n >> k;
	int last ;                    //last?????????????
	last = m = n + k;
	while (1)
	{
		if ( f(n - 1) ) 
			break ;               //????????????????
		else 
			m = last += n ;       //???????+n
	}
	cout << m << endl ;           //?????????
	return 0 ;
}
int f(int num)
{
	if( m % (n - 1) == 0 )        //m???n - 1????????
	{
		m = m * n / (n - 1) + k ; //??????????
	}
	else return 0 ;               //?????????0
	if( num == 1 ) 
		return 1 ;                //???????????????
	else return f(num - 1) ;      //??????
}