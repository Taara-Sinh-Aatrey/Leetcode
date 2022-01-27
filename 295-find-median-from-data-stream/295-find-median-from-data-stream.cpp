class MedianFinder {
public:
    multiset<int> small, large;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if (small.size() == large.size()) {
            small.emplace(num);
            large.emplace(*prev(small.end()));
            small.erase(prev(small.end()));
        }
        else {
            large.emplace(num);
            small.emplace(*large.begin());
            large.erase(large.begin());
        }
    }
    
    double findMedian() {
        if (large.size() > small.size())
            return *large.begin();
        
        return (*prev(small.end()) + *large.begin()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */