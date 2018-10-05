class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t totalLen = nums1.size() + nums2.size();
        int midIdx = (totalLen - 1) / 2;
        double midium;

        int i=0, j=0;
        vector<int> a;
        for (; i < nums1.size() && j < nums2.size();) {
            int n1 = nums1.at(i);
            int n2 = nums2.at(j);
            if( n1 < n2) {
                a.push_back(n1);
                i++;
            } else {
                a.push_back(n2);
                j++;
            }
        }
        if (i < nums1.size()) {
            for (; i < nums1.size(); i++) {
                a.push_back(nums1.at(i));
            }
        } 
        if (j < nums2.size()) {
            for (; j < nums2.size(); j++) {
                a.push_back(nums2.at(j));
            }
        }
        
        if (totalLen & 1 > 0) {
            midium = (double)a.at(midIdx);
        } else {
            midium = ((double)a.at(midIdx) + (double)a.at(midIdx+1)) / 2;
        }

        return midium;
    }

    double quickFind(vector<int>& nums1, vector<int>& nums2) {
        int s1, s2; // s1 splits nums1, s2 splits
        size_t l1 = nums1.size();
        size_t l2 = nums2.size();

        
    }
}