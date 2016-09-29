
using namespace std;

#include <iostream>
#include <stdio.h>
#include <algorithm>



// this is the most basic recursive version implementation



int cut_rod(int p[] , int n) {

   int q = -999;

 if (n == 0) {
    return 0;

 }





 for (int i=0; i<n; i++){

 int res=p[i] + cut_rod(p,n - (i+1) );

 q= max(q,res);


 }
return  q;





}

// memoized version of cut_rod

int memoized_cut_rod (int p[] , int n) {


 // create an array table to store memoized values

 int temp[100]={};

 int q=-1;

 if ( n== 0) {

    return 0;

 }

 if (temp[n]>0) {

    return temp[n];

 }
else {

         for (int i=0; i<n; i++) {

             int res=p[i] + cut_rod(p,n - (i+1) );

 q= max(q,res);


 }

return q;

}


}

// cut_rod using bottom up approach

 int r[100]= {};

int bottom_cut_rod (int p[],int n) {


    r[0]=0;


   for (int j=0; j<n; j++) {

        int q=-5;

        for(int i=1; i-1<=j; i++) {
              //  cout << "i: " << i << "j : " << j << "\n";


              q=max(q,p[i - 1] + r[j - i + 1]);


               cout << q << "\n";



        }


  r[j+1]=q;
  r[1]=0;

  cout << "r : " << r[j] << "\n" ;


   }



return r[n];


}

int main() {

int arr[]={1,5,8,9,10,17,17,20,24,30,31,32,33,34,35,36,37,38};

// cout << cut_rod(arr,18) ;


 // cout << memoized_cut_rod(arr,10);

 cout << bottom_cut_rod(arr,9);

return 0;

}
