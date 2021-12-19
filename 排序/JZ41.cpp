class Solution {
public:
    
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int count = 0;
    
    void Insert(int num) {
        count++;
        if(count & 1)  // 奇数，应该放入左边的大根堆
        {
            min_heap.push(num);  // 假设放入右边的小根堆中，获取最小值
            max_heap.push(min_heap.top());
            min_heap.pop();  // 恢复
        }
        else  // 偶数，应该放入右边的最小堆
        {
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }

    double GetMedian() { 
        if(count & 1)
        {
            return max_heap.top();
        }
        else
        {
            return (max_heap.top()+min_heap.top()) / 2.0;
        }
    }

};