/**
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。
*/



double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int  n= nums1.size();
		int  m= nums2.size();		
		//排除n或m至少一个为空的情况 
        if(n==0){
            if(m%2!=0){
                return nums2[m/2]*1.0;
            }
            return (nums2[m/2]+nums2[m/2-1])/2.0;
            
        }
        else if(m==0){
             if(n%2!=0){
                return nums1[n/2]*1.0;
            }
            return (nums1[n/2]+nums1[n/2-1])/2.0;
        }
        //
        int i=0;
        int j=0;
        vector<int> ans;
        //将数据入栈输出中位数 
        while(i<n&&j<m){ 
                 if(nums1[i]>=nums2[j]){
                    // ans[i+j]=nums2[j++];
                    ans.push_back(nums2[j]);
                    
                     j++;
                 }
                else {
                    //ans[k++]=nums1[i++];
                    ans.push_back(nums1[i]);
                    
                     i++;
                }    
                }
                if(i<n){
                    for(;i<n;i++)                    
                    ans.push_back(nums1[i]);                                  
                }
                else if(j<m){
                    for(;j<m;j++)            
                    ans.push_back(nums2[j]);                    
                }
        int len = ans.size();
        if (len%2 != 0)
            return 1.0*ans[len/2];
        return (ans[len/2]+ans[len/2-1])/2.0;
    }
