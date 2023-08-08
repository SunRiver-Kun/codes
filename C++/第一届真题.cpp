/*²Ö¿â²¼¾Ö
#include<iostream>
using namespace std;
size_t GetNum(int n, int m)
{
if (n <= 0 || m <= 0) { return 0; }
int num_c = 5 * (m / 6) + m % 6;
int num_r = 2 * (n / 3);
if (n % 3 == 2)
num_r++;
return num_r * num_c;
}
int main()
{
int n, m;
cin >> n >> m;
cout << GetNum(n, m) << endl;
}   
*/

/*ÍøÂçÀ©ÕÅ
#include<iostream>
using namespace std;

int *arr;
//330 is time over
unsigned long GetInviteNum(const int day_join, const int day_now)
{
if (day_now - day_join < 7) { return 0; }
unsigned long num = 0;

// day_in + 7 + 3k <= day_now
int k = (day_now - day_join - 7) / 3;
for (int i = day_join + 7 + 3 * k; i >= day_join + 7; i -= 3)
{
if (arr[i - 1] <= 0)
{
arr[i - 1] = GetInviteNum(i, day_now);
}
num += 1 + arr[i - 1];
}
return num;
}

// 130 is time over
unsigned long GetInviteNum2(const int day_join, const int day_now)
{
if (day_now - day_join < 7) { return 0; }
unsigned long num = 0;
for (int i = day_join + 7; i <= day_now; i += 3)
num += 1 + GetInviteNum2(i, day_now);
return num;
}

int main()
{
int day;
cin >> day;
if (day <= 0)
{
return 0;
}
arr = new int[day]();
cout << 1 + GetInviteNum(1, day) << endl;
}
*/