#include <InstrucNumTime.h>
#include <cmath>
#include <ctime>

using namespace std;

/**
 * 
 * 计算机处理指令数的时间
 * 
**/



void printInstructionTime(){
    
  


    for(jint i=1;i<=9;i++){
        

        jint number = pow(10,i);

        clock_t startTime = clock();

        jint sum = 0;

        for(jint j=0;j<number;j++){
            sum += j;
        }
   
        clock_t endTime = clock();

        cout << "10^" << i << " : " << (jdouble)(endTime-startTime)/CLOCKS_PER_SEC << "s" << endl;
      
    }

}
