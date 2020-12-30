#include<iostream>
#include<math.h>

using namespace std;

typedef unsigned int u16;

void calc(u16 *dist, const int len, int *min)
{
	char i, j=0;
	int dif[len-1]; //存放差值（斜率）
	u16 x1, x2, x;
	
	//在此将两端值假设最小 
	min[0] = 0;
	min[1] = len - 1;
	cout << dist[min[1]] << endl;
	
	//计算差值 
	cout << "差值" << endl; 
	for(i = 0; i < len - 1; i++)
	{
		dif[i] = dist[i + 1] - dist[i];
		cout << dif[i] << " ";
	  }  
	cout << endl;
	//获取极小值点 
	cout << "极小值" << endl;
	for(i = 0; i < len - 2; i++)
	{
		if(dif[i] <= 0 && dif[i + 1] > 0)
		{
			if(dist[i+1] < dist[min[0]] || dist[i+1] < dist[min[1]])
			{
				if(dist[min[0]] < dist[min[1]])
					min[1] = i+1;
				else
					min[0] = i+1;
			 }
		}
		cout << dist[i+1] << " "; 
	}
	cout << endl;
	cout << "最小两位极小值" << endl;
	cout << dist[min[0]] << ' ' << dist[min[1]] << endl; 
}

main()
{
	u16 dist[11];
    char i;
	int min[2];
    
    while(1)
    {
        for(i = 0; i < 11; i++)
        {
    	    cin >> dist[i];
	    }
	    calc(dist, 11, min);
	    cout << endl;
     }
 } 
 
 //100 1000 1000 1000 1000 1000 1000 1000 1000 1000 100
 //0   9
 //100 100
 
 //400 700 345 234 123 234 345 698 432 211 345 
 //4   9
 //123 211
 
 //300 440 550 229 112 44 234 456 1333 1346 122
 //5  10
 //44 122
 
 //500 400 500 500 500 600 300 700 200 800 100
