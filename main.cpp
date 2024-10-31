#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {


    int n;
    cout<<"enter the number of elements: ";
    cin>>n;

    vector<int> myVector(n);
    for(int i=0 ; i<n ;++i) {
        cout<<"Enter element number"<<i+1<<": ";
        cin>> myVector[i];
    }
    int sum = 0;
    for(int i=1; i<n-1 ; ++i) {


         if(myVector[i]<myVector[i-1] && myVector[i]<myVector[i+1]) {
            int minimum=min(myVector[i-1],myVector[i+1]);
            int difference=abs(myVector[i]-minimum);
            sum=sum+1*difference;

        }
        else if(myVector[i]<myVector[i+1] && myVector[i]>=myVector[i-1]) {
            int count=0;
            int j;
            for( j=i-1 ; myVector[j]<myVector[i] && i>=1 ; --j) {
                count=count+1;

            }if (myVector[j]>myVector[i]) {
                int minimum=min(myVector[j],myVector[i+1]);
                int difference=abs(myVector[i]-minimum);

                sum=sum+difference*(1+count);

            }

        }
        else if(myVector[i]>=myVector[i+1] && myVector[i]<myVector[i-1]) {
            int count=0;
            int j;
            for(j=i+1 ;myVector[j]<=myVector[i] && j<=(n-1) ;++j) {
                count=count+1;
            }
            if(myVector[j]>myVector[i]) {
                int minimum=min(myVector[j],myVector[i-1]);
                int difference=abs(myVector[i
            ]-
                    minimum);
                sum=sum+difference*(1+count);
            }

        }
        else if(myVector[i]>=myVector[i-1] && myVector[i]>=myVector[i+1]) {
            int counterToTheLeft=0;
            int j;
            for(j=i-1;myVector[j]<=myVector[i] && j>=1; --j) {
                counterToTheLeft=counterToTheLeft+1;
            }
            int counterToTheRight=0;
            int k;
            for(k=i+1;myVector[k]<=myVector[i] && k<=(n-1);++k) {
                counterToTheRight=counterToTheRight+1;
            }
            if(myVector[j]>myVector[i] && myVector[k]>myVector[i]) {
                int minimum=min(myVector[j],myVector[k]);
                int difference=abs(myVector[i]-minimum);
                sum=sum+difference*(1+counterToTheLeft+counterToTheRight);
            }
        }else if(i==n-1) {
            sum=sum;
        }
    }
    cout<<"sum="<<sum<<endl;
    return 0;
}
