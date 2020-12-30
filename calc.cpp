#include<iostream>
#include<math.h>

using namespace std;

typedef unsigned int u16;

void calc(u16 *dist, const int len, int *min)
{
	char i, j=0;
	int dif[len-1]; //存放差值（斜率）
	u16 x1, x2, x;
	
	min[0] = 1000;
	min[1] = 1000;
	
	//计算差值 
	cout << "差值" << endl; 
	for(i = 0; i < len - 1; i++)
	{
		dif[i] = dist[i + 1] - dist[i];
		cout << dif[i] << " ";
	  }  
	cout << endl;
	//获取极小值点 
	for(i = 0; i < len - 2; i++)
	{
		if(dif[i] <= 0 && dif[i + 1] > 0)
		{
			if(j < 2)
			    min[j++] = i+1;
			else
			{
			    if(dist[i+1] < dist[min[0]] && dist[min[0]] > dist[min[1]]) min[0] = i+1;
	    	    else if(dist[i+1] < dist[min[1]]) min[1] = i+1;
			}
		    cout << dist[i+1] << " "; 
		}
	}
	if(dif[0] > 0)
	{
		 
	}
	if(dif[len-2] < 0)  
	{
		
    }

	x1 = dist[min[0]];
	x2 = dist[min[1]];
	cout << min[0] << " " << min[1] << endl;
	x = sqrt(x1*x1+x2*x2-2*x1*x2*cos(3.141592 * 9*(min[0]-min[1]) / 180));
	cout << "distance：" << x << endl;
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
	    cout << (int)min[0] << ' ' << (int)min[1] << endl;
	    cout << dist[min[0]] << ' ' <<dist[min[1]] << endl;
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
 
 //添加一句话：去你大爷 
