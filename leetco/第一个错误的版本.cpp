bool isBadVersion(int version);

class Solution {
public:
    /*
    ����һ�����ֲ�������
    */
    int firstBadVersion(int n) {
            if(isBadVersion(1))
                return 1;
        int left=1;
        int right=n;
        while(left<right){
            int mid=(left+(right-left)/2);
            if(isBadVersion(mid)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};
