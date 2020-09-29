class QuickSort {
public:

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
        
    }
    
private:
    int selectPivot(vector<int>& a, int left, int right){
        int center = (right + left)/2;
        if(a[center]<a[left]){
            swap(a[center], a[left]);
        }
        if(a[right]<a[left]){
            swap(a[right], a[left]);
        }
        if(a[right]<a[center]){
            swap(a[right], a[center]);
        }
        swap(a[center], a[right-1]);
        return a[right-1];
    }

    void insertionSort(vector<int>& nums, int left, int right){
        for(int i = left+1; i <= right; i++){
            int p;
            int tmp = nums[i];
            for(p = i; p-1>=left && tmp<nums[p-1];p--){
                nums[p] = nums[p-1];
            }
            nums[p] = tmp;
        }
    }
    
    void quickSort(vector<int>& nums, int left, int right){
        if(left + 10 <=right){
            int pivot = selectPivot(nums, left, right);
            int i=left, j=right-1;
            while(true){
                while(nums[++i]<pivot){}
                while(nums[--j]>pivot){}
                if(i<j){
                    swap(nums[i],nums[j]);
                } else {
                    break;
                }
            }
            swap(nums[i], nums[right-1]);
            
            quickSort(nums, left, i-1);
            quickSort(nums, i+1, right);
        } else {
            insertionSort(nums, left, right);
        }
    }
};