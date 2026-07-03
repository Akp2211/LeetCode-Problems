class Solution {
public:
    int peakIdxMountain(MountainArray &mountainArr){
        int l = 0;
        int h = mountainArr.length()-1;
        while(l<h){
            int mid = l + (h-l)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)) l = mid+1;
            else h = mid;
        }
        return l;
    }

    int binarySearchLeft(int target, MountainArray &mountainArr,int low, int high){
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid)>target) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }

    int binarySearchRight(int target, MountainArray &mountainArr,int low, int high){
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid)>target) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakIdx =peakIdxMountain(mountainArr);
        int left = binarySearchLeft(target,mountainArr,0,peakIdx);
        if(left != -1) return left;
        int right = binarySearchRight(target,mountainArr,peakIdx+1,mountainArr.length()-1);
        if(right != -1) return right; 
        return -1;
    }
};