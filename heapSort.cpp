class HeapSort {
public:

    vector<int> sortArray(vector<int>& nums) {
        vector<int> heap(1);
        vector<int> res;
        heap.insert(heap.end(), nums.begin(), nums.end());
        
        buildHeap(heap);

        while(heap.size()>1){
            res.push_back( heap[1]);
            deleteMin(heap);
        }
        return res;
        
    }
    
private:
    void percDown(vector<int>& heap, int hole)
    {
        int tmp = heap[hole];
        int child = 2*hole;
        while (hole * 2<heap.size()){
            if(child + 1 < heap.size()&& heap[child+1]<heap[child]){
                child++;
            }
            if(tmp>heap[child]){
                heap[hole] = heap[child];
                hole = child;
                child = 2*hole;
            } else {
                break;
            }
        }
        heap[hole] = tmp;
    }
    
    
    void delete(vector<int>& heap){
        heap[1] = heap.back();
        heap.resize(heap.size()-1);
        percDown(heap, 1);
    }
    
    void insert(vector<int>& heap, int element){
        heap.resize(heap.size() +1 );
        int hole = heap.size() -1;
        for(; hole>1&& heap[hole/2]>element;hole/=2){
            heap[hole] = heap[hole/2];
        }
        heap[hole] = element;
    }
    
    void buildHeap(vector<int>& heap)
    {
        for(int i = heap.size()/2; i>0;i--){
            percDown(heap, i);
        }
    }
};