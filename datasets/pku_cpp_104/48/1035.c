//*********************************************
//** ??????????? **
//** ?????? 1300012722 **
//** ???2013.12.06 **
//*********************************************
int b[9][9], old[9][9];                  //????b??????????????old??????????????
void mul(int k, const int day);          //?????day????????k??????
void pam(int x, int y);                  //x?y???????????
int main()
{
	int m, n, i, j;                      //m????????????n???????
	memset(b, 0, sizeof(b));             //b????
	cin >> m >> n;                  
	b[4][4] = m;                         //????????
	mul(0, n);                           //??????n??????????????
	for(i = 0; i <= 8; i++)
	{
		for(j = 0; j < 8; j++)
			cout << b[i][j] << " ";
		cout << b[i][8] << endl;
	}                                    //?????
	return 0;
}
void mul(int k, const int day)
{
	int i, j;
	for(i = 4 - k; i <= 4 + k; i++)
		for(j = 4 - k; j <= 4 + k; j++)
		old[i][j] = b[i][j];             //??????????????
	for(i = 4 - k; i <= 4 + k; i++)
		for(j = 4 - k; j <= 4 + k; j++)
			pam(i, j);                   //????????????????
	k++;
	if(k < day)
		mul(k, day);                     //???????????????
	else
		return;
}
void pam(int x, int y)                   //?????????10????????????????????????????????????????
{
	int i, j;
	for(i = x - 1; i <= x + 1; i++)
		for(j = y - 1; j <= y + 1; j++)
			b[i][j] = b[i][j] + old[x][y];     //????????????????????
	return;
}