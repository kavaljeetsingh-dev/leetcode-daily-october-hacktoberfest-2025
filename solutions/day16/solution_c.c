// When we divide numbers by value, they leave a remainder. 
//Numbers that leave the same remainder belong to the same residue class.

int findSmallestInteger(int* nums, int numsSize, int value) {
    int* remainderCount = (int*)calloc(value, sizeof(int));
    for(int i=0;i<numsSize;i++){
        int remainder =((nums[i]%value)+value)%value;
        remainderCount[remainder]++;
    }
    int mex = 0;
    while(1){
        int remainder = mex % value;
        if(remainderCount[remainder]==0){
            break;
        }
        remainderCount[remainder]--;
        mex++;
    }
    free(remainderCount);
    return mex;
}


