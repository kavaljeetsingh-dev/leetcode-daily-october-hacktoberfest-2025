// Language used : C++
// 3370. Smallest Number With All Set Bits
// Time complexity: O(n log n)
// Space complexity: O(1)

class Solution {
public:
    int smallestNumber(int n) {

        while (true) {
            int a = n;
            bool allOnes=true;
            while (a) {
                if ((a & 1)== 0) {
                   
                      allOnes=false;
                    break;
                }
                a = a >> 1;
            }
            if(allOnes==true){
                return n;
            }
              n++;
           
        }
        return -1;

     
    }
};